
#include "Utilities.h"

#include <stdio.h>  /* defines FILENAME_MAX */

#ifdef WIN32
    #include <direct.h>
    #define GetCurrentWorkingDirectory GetCurrentDirectory
#else
    #include <unistd.h>
    #define GetCurrentWorkingDirectory getcwd
 #endif

#include <Windows.h>

std::wstring CUtilities::GetWorkingDirectory()
{
	wchar_t cCurrentPath[FILENAME_MAX];
	GetCurrentDirectory(FILENAME_MAX, cCurrentPath);

	return cCurrentPath;
}

std::wstring CUtilities::ToWString(const std::string& str)
{
	std::wstring wsTmp(str.begin(), str.end());
	return wsTmp;
}