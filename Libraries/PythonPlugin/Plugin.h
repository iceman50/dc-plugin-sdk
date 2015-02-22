
#ifndef PLUGIN_PLUGIN_H
#define PLUGIN_PLUGIN_H

#include "PluginBase.h"
#include "PluginInformation.h"

class Plugin
{
public:
	static DCIMP Bool DCAPI main(PluginState state, DCCorePtr core, dcptr_t);

    static DCIMP dcapi::CPluginInformation* GetPluginInformation();
    static DCIMP void ReadSettings();

    static DCIMP std::wstring UpdateEnvironment();
	static DCIMP void ResetEnvironment(const std::wstring& strPath);

private:
	Plugin();
	~Plugin();

	DCIMP bool onLoad(DCCorePtr core, bool install, bool runtime);

    DCIMP void Initialize();
    DCIMP void Uninitialize();

private:

    dcapi::CPluginBase* m_pPlugin;

	std::string m_strBinaryName;
	std::string m_strClassName;

};

#endif
