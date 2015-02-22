
#pragma once

#include "PluginInformation.h"

namespace dcapi { 

class CMetaDataParser
{

public:

    static void ParseFile(System::String^ fileName, dcapi::CPluginInformation* pluginInfo);
};

}