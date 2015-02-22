
#include "stdafx.h"

#include "MetaDataParser.h"
#include "Marshalling.h"

void dcapi::CMetaDataParser::ParseFile(System::String^ fileName, dcapi::CPluginInformation* pluginInfo)
{
    DCPlugin::DataTypes::MetaData^ metaData = DCPlugin::DataTypes::MetaData::Parse(fileName);

    auto convertedPluginInfo = DCPlugin::DataTypes::MetaData::GetPluginInformation(metaData);
    *pluginInfo = dcapi::CMarshalling::MarshalData(convertedPluginInfo);
}

