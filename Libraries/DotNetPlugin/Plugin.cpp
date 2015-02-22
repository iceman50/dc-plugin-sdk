
#include "stdafx.h"
#include "Plugin.h"

#include "PluginHelper.h"
#include "AssemblyLoader.h"
#include "AssemblyResolver.h"
#include "Marshalling.h"
#include "MetaDataParser.h"

#include "dcapi\Core.hpp"
#include "dcapi\Logger.hpp"
#include "dcapi\Util.hpp"

#include <iostream>
#include <windows.h>

dcapi::CPluginInformation* _pPluginInformation = NULL;

gcroot<dcapi::CAssemblyResolver^> _pAssemblyResolver;

Plugin::Plugin() : m_pPlugin( NULL ), m_pPluginAssemblyManager( NULL ) {
}

Plugin::~Plugin() {
	
}



DCIMP Bool DCAPI Plugin::main(PluginState state, DCCorePtr core, dcptr_t) {
	static Plugin* instance;

	switch(state) {
	case ON_INSTALL:
	case ON_LOAD:
	case ON_LOAD_RUNTIME:
		{
			instance = new Plugin();

            instance->Initialize();
			return instance->onLoad(core, state == ON_INSTALL, state == ON_INSTALL || state == ON_LOAD_RUNTIME) ? True : False;
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

            _pAssemblyResolver->Uninitialize();

			return True;
		}

	default:
		{
			return False;
		}
	}
}

DCIMP void Plugin::Initialize()
{
    // Create the search paths.
	// Add the application's directory and the executable's location.
    System::Collections::Generic::List<System::String^>^ searchPaths = gcnew System::Collections::Generic::List<System::String^>();
    searchPaths->Add(System::IO::Directory::GetCurrentDirectory());
    searchPaths->Add(System::IO::Path::GetDirectoryName(System::Reflection::Assembly::GetExecutingAssembly()->Location));

    std::string cppAssemblyName = GetPluginInformation()->GetSetting("AssemblyName").GetStringValue();
    std::string cppClassName = GetPluginInformation()->GetSetting("ClassName").GetStringValue();

    System::String^ assemblyName = gcnew System::String(cppAssemblyName.c_str());
    System::String^ className = gcnew System::String(cppClassName.c_str());
    bool bAppDomain = GetPluginInformation()->GetSetting("AppDomain").GetByteValue() == 1 ? true : false;

    m_pPluginAssemblyManager = new dcapi::CAssemblyManager(searchPaths, assemblyName, className, bAppDomain);
    m_pPluginAssemblyManager->Initialize();
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

    // Parse the settings file.
    System::String^ fileName = "MetaData.xml";

    System::String^ currentDirfilePath = System::IO::Path::Combine( System::IO::Directory::GetCurrentDirectory(), fileName );
    System::String^ exeAssemblyfilePath = System::IO::Path::Combine( System::IO::Path::GetDirectoryName(System::Reflection::Assembly::GetExecutingAssembly()->Location), fileName );
    
    if(System::IO::File::Exists(fileName))
    {
        dcapi::CMetaDataParser::ParseFile(fileName, pluginInfo);
    }
    else if(System::IO::File::Exists(currentDirfilePath))
    {
        dcapi::CMetaDataParser::ParseFile(currentDirfilePath, pluginInfo);
    }
    else if(System::IO::File::Exists(exeAssemblyfilePath))
    {
        dcapi::CMetaDataParser::ParseFile(exeAssemblyfilePath, pluginInfo);
    }
}

DCIMP void Plugin::UpdateEnvironment()
{
    // Set up the environment to make sure that assemblies are properly resolved etc.
    System::Collections::Generic::List<System::String^>^ searchPaths = gcnew System::Collections::Generic::List<System::String^>();
    searchPaths->Add(System::IO::Directory::GetCurrentDirectory());
    searchPaths->Add(System::IO::Path::GetDirectoryName(System::Reflection::Assembly::GetExecutingAssembly()->Location));

    _pAssemblyResolver = gcnew dcapi::CAssemblyResolver(searchPaths);
    _pAssemblyResolver->Initialize();
}

DCIMP bool Plugin::onLoad(DCCorePtr core, bool install, bool runtime) 
{
    DCPlugin::DataTypes::PluginInformation^ pluginInfo = dcapi::CMarshalling::MarshalData(_pPluginInformation);

    // Load assembly
    DCPlugin::DataTypes::INETPlugin^ netPlugin = nullptr;
    m_pPluginAssemblyManager->LoadAssembly(pluginInfo, netPlugin);

    if(netPlugin == nullptr)
    {
        return false;
    }

    // Create the plugin
    dcapi::CPluginBase* pPlugin = new dcapi::CPluginHelper(netPlugin);

    // Initialize the plugin
	bool initialized = pPlugin->Initialize(_pPluginInformation, core, install, runtime);
	if( initialized )
	{
        {
            std::string message;
            dcapi::CMarshalling::MarshalString("[" + pluginInfo->Name + "] Plugin is loaded.", message);

		    dcapi::Logger::log(message);
        }

		m_pPlugin = pPlugin;

		return true;
	}

	// Validate that at least the logger is initialized
	if( dcapi::Logger::handle() != NULL )
	{
        {
            std::string message;
            dcapi::CMarshalling::MarshalString("[" + pluginInfo->Name + "] could not load.", message);
		    dcapi::Logger::log(message);
        }
	}

    return false;
}

void Plugin::Uninitialize()
{
    {
        DCPlugin::DataTypes::PluginInformation^ pluginInfo = dcapi::CMarshalling::MarshalData(_pPluginInformation);

        std::string message;
        dcapi::CMarshalling::MarshalString("[" + pluginInfo->Name + "] Unloading.", message);
		dcapi::Logger::log(message);
    }

    // Uninitialize the plugin
    if( m_pPlugin != NULL )
    {
        m_pPlugin->Uninitialize();
    }

    // Delete the plugin
    delete m_pPlugin;
    m_pPlugin = NULL;

    // Uninitialize the plugin assembly manager
    if( m_pPluginAssemblyManager != NULL )
    {
        m_pPluginAssemblyManager->Destroy();
    }

    // Destroy the plugin assembly manager
    delete m_pPluginAssemblyManager;
    m_pPluginAssemblyManager = NULL;
}