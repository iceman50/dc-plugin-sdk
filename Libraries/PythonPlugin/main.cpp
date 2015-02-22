
#include "stdafx.h"
#include "Plugin.h"

extern "C" {

// Plugin loader
DCIMP DCMAIN pluginInit(MetaDataPtr info) {
    Plugin::ReadSettings();

    auto pluginInfo = Plugin::GetPluginInformation();

	info->name = pluginInfo->_name.c_str();
	info->author = pluginInfo->_author.c_str();
	info->description = pluginInfo->_description.c_str();
	info->web = pluginInfo->_web.c_str();
	info->version = pluginInfo->_version;
	info->apiVersion = pluginInfo->_apiversion;
	info->guid = pluginInfo->_guid.c_str();

	return &Plugin::main;
}

#ifdef _WIN32
BOOL APIENTRY DllMain(HINSTANCE /*hinstDLL*/, DWORD /*fdwReason*/, LPVOID /*lpvReserved*/) {
	return TRUE;
}
#endif
}

int
main(int argc, char *argv[])
{
    Plugin::ReadSettings();

	Plugin::main(PluginState::ON_INSTALL, NULL, NULL);

	return 0;

}
