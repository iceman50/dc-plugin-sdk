
#include "stdafx.h"
#include "Plugin.h"

#include <iostream>

extern "C" {

// Plugin loader
DCIMP DCMAIN pluginInit(MetaDataPtr info) {

    Plugin::UpdateEnvironment();

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
#pragma unmanaged
BOOL APIENTRY DllMain(HINSTANCE /*hinstDLL*/, DWORD /*fdwReason*/, LPVOID /*lpvReserved*/) {
	return TRUE;
}
#endif


}
