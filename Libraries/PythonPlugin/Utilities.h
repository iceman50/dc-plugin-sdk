
#pragma once

#include <string>

class CUtilities
{
public:

	static std::wstring GetWorkingDirectory();

	static std::wstring ToWString(const std::string& str);

};