
#include "Plugin.h"

#include "PluginHelper.h"

#include "PythonManagement.h"
#include "Marshalling.h"
#include "Utilities.h"

#include <dcapi\PluginDefs.h>
#include "dcapi\Core.hpp"
#include "dcapi\Logger.hpp"
#include "dcapi\Util.hpp"

#include <iostream>
#include <Windows.h>

dcapi::CPluginInformation* _pPluginInformation = NULL;

Plugin::Plugin() : m_pPlugin( NULL ) {
}

Plugin::~Plugin() {
	Uninitialize();
}

DCIMP Bool DCAPI Plugin::main(PluginState state, DCCorePtr core, dcptr_t) {
	static Plugin* instance;

	switch(state) {
	case ON_INSTALL:
	case ON_LOAD:
	case ON_LOAD_RUNTIME:
		{
			instance = new Plugin();

			std::wstring strCWD = instance->UpdateEnvironment();

			instance->Initialize();

			auto onLoadValue = instance->onLoad(core, state == ON_INSTALL, state == ON_INSTALL || state == ON_LOAD_RUNTIME) ? True : False;

			instance->ResetEnvironment(strCWD);

			return onLoadValue;
		}

	case ON_UNINSTALL:
	case ON_UNLOAD:
		{
            if( instance != NULL )
            {
                instance->Uninitialize();
            }

			delete instance;
			instance = 0;

			return True;
		}

	default:
		{
			return False;
		}
	}
}

DCIMP bool Plugin::onLoad(DCCorePtr core, bool install, bool runtime) 
{
	CPluginSink* pSink = new CPluginSink();

	runtime = false;

	PyObject* pBaseClassPlugin = CPythonManagement::GetPluginBaseObject(m_strBinaryName, m_strClassName, pSink);

	dcapi::CPluginBase* pPlugin = new dcapi::CPluginHelper(pBaseClassPlugin, pSink);

	// Initialize the plugin
	bool initialized = pPlugin->Initialize(GetPluginInformation(), core, install, runtime);
	if( initialized )
	{
        {
            std::string message = "[" + GetPluginInformation()->_name + "] Plugin is loaded.";
		    dcapi::Logger::log(message);
        }

		m_pPlugin = pPlugin;

		return true;
	}

	// Validate that at least the logger is initialized
	if( dcapi::Logger::handle() != NULL )
	{
        {
			std::string message = "[" + GetPluginInformation()->_name + "] Plugin could not be loaded.";
		    dcapi::Logger::log(message);
        }
	}
	
    return false;
}

DCIMP void Plugin::Initialize()
{
	CPythonManagement::InitializePython();

	m_strBinaryName = GetPluginInformation()->GetSetting("AssemblyName").GetStringValue();
	m_strClassName = GetPluginInformation()->GetSetting("ClassName").GetStringValue();
}

DCIMP void Plugin::Uninitialize()
{
	if( m_pPlugin != NULL )
	{
		m_pPlugin->Uninitialize();
	}

	delete m_pPlugin;
	m_pPlugin = NULL;

	CPythonManagement::UninitalizePython();
} 

DCIMP dcapi::CPluginInformation* Plugin::GetPluginInformation()
{
    if( _pPluginInformation == NULL )
    {
        _pPluginInformation = new dcapi::CPluginInformation();
    }

    return _pPluginInformation;
}

DCIMP void Plugin::ReadSettings()
{
	dcapi::CPluginInformation* pluginInfo = GetPluginInformation();

	// todo: Read from a settings file
	// In the meantime, you must edit these values
	{
		std::string strBinaryName = "MyPlugin";
		auto container = dcapi::CPluginSettingContainer::GetContainer("AssemblyName", "Name of assembly", dcapi::SettingDataTypeString, "", "", strBinaryName);
		pluginInfo->_settings[container.GetName()] = container;
	}
	{
		std::string strClassName = "MyPlugin";
		auto container = dcapi::CPluginSettingContainer::GetContainer("ClassName", "Name of class", dcapi::SettingDataTypeString, "", "", strClassName);
		pluginInfo->_settings[container.GetName()] = container;
	}

	pluginInfo->_name = PLUGIN_NAME;
	pluginInfo->_guid = PLUGIN_GUID;
	pluginInfo->_version = PLUGIN_VERSION;
	pluginInfo->_author = PLUGIN_AUTHOR;
	pluginInfo->_description = PLUGIN_AUTHOR;
	pluginInfo->_web = PLUGIN_WEB;
}

DCIMP std::wstring Plugin::UpdateEnvironment()
{
	std::wstring strCurrentDir = CUtilities::GetWorkingDirectory();

	std::wstring strCurrentDirNew = strCurrentDir + L"\\Plugins\\" + CUtilities::ToWString(GetPluginInformation()->_guid) + L"\\";
	::SetCurrentDirectory(strCurrentDirNew.c_str());

	return strCurrentDir;
}

DCIMP void Plugin::ResetEnvironment(const std::wstring& strPath)
{
	::SetCurrentDirectory(strPath.c_str());
}
