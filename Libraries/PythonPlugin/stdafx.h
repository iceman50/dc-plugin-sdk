
#ifndef PLUGIN_STDAFX_H
#define PLUGIN_STDAFX_H

#ifdef _WIN32

#include <windows.h>
#include <tchar.h>

#else

#include <unistd.h>

#endif

#include <cstdio>
#include <cstdint>
#include <string>

#include "dcapi/PluginDefs.h"

#include "version.h"

#ifdef _UNICODE
typedef std::wstring tstring;
#else
typedef std::string tstring;
#endif

#endif
