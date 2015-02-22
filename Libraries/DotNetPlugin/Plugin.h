
#ifndef PLUGIN_PLUGIN_H
#define PLUGIN_PLUGIN_H

#include "PluginBase.h"
#include "AssemblyManager.h"
#include "PluginInformation.h"

class Plugin
{
public:
	static DCIMP Bool DCAPI main(PluginState state, DCCorePtr core, dcptr_t);

    static DCIMP dcapi::CPluginInformation* GetPluginInformation();
    static DCIMP void ReadSettings();

    static DCIMP void UpdateEnvironment();

private:
	Plugin();
	~Plugin();

	DCIMP bool onLoad(DCCorePtr core, bool install, bool runtime);

    DCIMP void Initialize();
    DCIMP void Uninitialize();

private:

    dcapi::CPluginBase* m_pPlugin;

    dcapi::CAssemblyManager* m_pPluginAssemblyManager;

};

#endif
