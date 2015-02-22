
#include "stdafx.h"

#include "Marshalling.h"

#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

void dcapi::CMarshalling::MarshalString(System::String ^ s, std::string& os)
{
    if(s == nullptr)
    {
        s = gcnew System::String("");
    }

	os = msclr::interop::marshal_as<std::string>(s);
}

void dcapi::CMarshalling::MarshalString(System::String ^ s, std::wstring& os)
{
    if(s == nullptr)
    {
        s = gcnew System::String("");
    }

    os = msclr::interop::marshal_as<std::wstring>(s);
}

DCPlugin::DataTypes::QueueData^ dcapi::CMarshalling::MarshalData(QueueDataPtr data)
{
    if(data == NULL)
    {
        return nullptr;
    }

    System::String^ target = gcnew System::String(data->target);
    System::String^ location = gcnew System::String(data->location);
    System::String^ hash = gcnew System::String(data->hash);
    System::UInt64 size = data->size;
    bool isFileList = MarshalData(data->isFileList);

    System::IntPtr internalPointer(data);

    return gcnew DCPlugin::DataTypes::QueueData(target, location, hash, size, isFileList, internalPointer);
}

QueueDataPtr dcapi::CMarshalling::MarshalData(DCPlugin::DataTypes::QueueData^ data)
{
    if(data == nullptr)
    {
        return NULL;
    }

    return reinterpret_cast<QueueDataPtr>(data->InternalPointer.ToPointer());
}

DCPlugin::DataTypes::HubData^ dcapi::CMarshalling::MarshalData(HubDataPtr data)
{
    if(data == NULL)
    {
        return nullptr;
    }

    System::String^ url = gcnew System::String(data->url);
    System::String^ ip = gcnew System::String(data->ip);
    System::UInt16 port = data->port;
    DCPlugin::DataTypes::ProtocolType protocol = MarshalData(data->protocol);
    bool isOp = MarshalData(data->isOp);
    bool isEncrypted = MarshalData(data->isSecure);
    System::IntPtr internalPointer(data);

    return gcnew DCPlugin::DataTypes::HubData(url, ip, port, protocol, isOp, isEncrypted, internalPointer);
}
 
HubDataPtr dcapi::CMarshalling::MarshalData(DCPlugin::DataTypes::HubData^ data)
{
    if(data == nullptr)
    {
        return NULL;
    }

    return reinterpret_cast<HubDataPtr>(data->InternalPointer.ToPointer());
}

DCPlugin::DataTypes::UserData^ dcapi::CMarshalling::MarshalData(UserDataPtr data)
{
    if(data == NULL)
    {
        return nullptr;
    }

    System::String^ nick = gcnew System::String(data->nick);
    System::String^ hubUrl = gcnew System::String(data->hubHint);
    System::String^ cid = gcnew System::String(data->cid);
    System::UInt32 sid = data->sid;
    DCPlugin::DataTypes::ProtocolType protocol = MarshalData(data->protocol);
    bool isOp = MarshalData(data->isOp);
    System::IntPtr internalPointer(data);

    return gcnew DCPlugin::DataTypes::UserData(nick, hubUrl, cid, sid, protocol, isOp, internalPointer);
}

UserDataPtr dcapi::CMarshalling::MarshalData(DCPlugin::DataTypes::UserData^ data)
{
    if(data == nullptr)
    {
        return NULL;
    }

    return reinterpret_cast<UserDataPtr>(data->InternalPointer.ToPointer());
}

DCPlugin::DataTypes::ConnectionData^ dcapi::CMarshalling::MarshalData(ConnectionDataPtr data)
{
    if(data == NULL)
    {
        return nullptr;
    }

	System::String^ ip = gcnew System::String(data->ip);
	System::UInt16 port = data->port;
    DCPlugin::DataTypes::ProtocolType protocol = MarshalData(data->protocol);
	bool isOp = MarshalData(data->isOp);
	bool isEncrypted = MarshalData(data->isSecure);
    System::IntPtr internalPointer(data);

    return gcnew DCPlugin::DataTypes::ConnectionData(ip, port, protocol, isOp, isEncrypted, internalPointer);
}

ConnectionDataPtr dcapi::CMarshalling::MarshalData(DCPlugin::DataTypes::ConnectionData^ data)
{
    if(data == nullptr)
    {
        return NULL;
    }

    return reinterpret_cast<ConnectionDataPtr>(data->InternalPointer.ToPointer());
}

DCPlugin::DataTypes::TagData^ dcapi::CMarshalling::MarshalData(TagDataPtr data)
{
    if(data == NULL)
    {
        return nullptr;
    }

    System::IntPtr internalPointer(data);

	return gcnew DCPlugin::DataTypes::TagData(internalPointer);
}

TagDataPtr dcapi::CMarshalling::MarshalData(DCPlugin::DataTypes::TagData^ data)
{
    if(data == nullptr)
    {
        return NULL;
    }

    return reinterpret_cast<TagDataPtr>(data->InternalPointer.ToPointer());
}

DCPlugin::DataTypes::UDPData^ dcapi::CMarshalling::MarshalData(UDPDataPtr data)
{
    if(data == NULL)
    {
        return nullptr;
    }

    System::String^ ipAddress = gcnew System::String(data->ip);
    System::UInt16 port = data->port;
    System::IntPtr internalPointer(data);

    return gcnew DCPlugin::DataTypes::UDPData(ipAddress, port, internalPointer);
}

UDPDataPtr dcapi::CMarshalling::MarshalData(DCPlugin::DataTypes::UDPData^ data)
{
    if(data == nullptr)
    {
        return NULL;
    }

    return reinterpret_cast<UDPDataPtr>(data->InternalPointer.ToPointer());
}

DCPlugin::DataTypes::StringData^ dcapi::CMarshalling::MarshalData(StringDataPtr data)
{
    if(data == NULL)
    {
        return nullptr;
    }

	System::String^ input = gcnew System::String(data->in);
	System::IntPtr internalPointer(data);

    return gcnew DCPlugin::DataTypes::StringData(input, internalPointer);
}

StringDataPtr dcapi::CMarshalling::MarshalData(DCPlugin::DataTypes::StringData^ data)
{
    if(data == nullptr)
    {
        return NULL;
    }

    StringDataPtr ptr = reinterpret_cast<StringDataPtr>(data->InternalPointer.ToPointer());

	std::string strOutput;
	MarshalString(data->Output, strOutput);

	ptr->out = const_cast<char*>(strOutput.c_str());

	return ptr;
}

DCPlugin::DataTypes::CommandData^ dcapi::CMarshalling::MarshalData(CommandDataPtr data)
{
    if(data == NULL)
    {
        return nullptr;
    }

	System::String^ command = gcnew System::String(data->command);
	System::String^ parameters = gcnew System::String(data->params);
	System::IntPtr internalPointer(data);

    return gcnew DCPlugin::DataTypes::CommandData(command, parameters, internalPointer);
}

CommandDataPtr dcapi::CMarshalling::MarshalData(DCPlugin::DataTypes::CommandData^ data)
{
    return reinterpret_cast<CommandDataPtr>(data->InternalPointer.ToPointer());
}

bool dcapi::CMarshalling::MarshalData(dcBool boolValue)
{
    return boolValue == dcTrue ? true : false;
}
dcBool dcapi::CMarshalling::MarshalData(bool boolValue)
{
    return boolValue ? dcTrue : dcFalse;
}

DCPlugin::DataTypes::ProtocolType dcapi::CMarshalling::MarshalData(ProtocolType protocol)
{
    switch(protocol)
    {
        case PROTOCOL_NMDC:
            return DCPlugin::DataTypes::ProtocolType::NMDC;

        case PROTOCOL_DHT:
            return DCPlugin::DataTypes::ProtocolType::DHT;

        case PROTOCOL_ADC:
        default:
            return DCPlugin::DataTypes::ProtocolType::ADC;
    }
}

ProtocolType dcapi::CMarshalling::MarshalData(DCPlugin::DataTypes::ProtocolType protocol)
{
    switch(protocol)
    {
        case DCPlugin::DataTypes::ProtocolType::NMDC:
            return PROTOCOL_NMDC;

        case DCPlugin::DataTypes::ProtocolType::DHT:
            return PROTOCOL_DHT;

        case DCPlugin::DataTypes::ProtocolType::ADC:
        default:
            return PROTOCOL_ADC;
    }
}

DCPlugin::DataTypes::QueuePriority dcapi::CMarshalling::MarshalData(QueuePrio priority)
{
	switch(priority)
    {
        case PRIO_LOWEST:
            return DCPlugin::DataTypes::QueuePriority::Lowest;

        case PRIO_LOW:
            return DCPlugin::DataTypes::QueuePriority::Low;

        case PRIO_NORMAL:
            return DCPlugin::DataTypes::QueuePriority::Normal;

        case PRIO_HIGH:
            return DCPlugin::DataTypes::QueuePriority::High;

        case PRIO_HIGHEST:
            return DCPlugin::DataTypes::QueuePriority::Highest;

        case PRIO_DEFAULT:
        default:
            return DCPlugin::DataTypes::QueuePriority::Default;
    }
}

QueuePrio dcapi::CMarshalling::MarshalData(DCPlugin::DataTypes::QueuePriority priority)
{
	switch(priority)
    {
        case DCPlugin::DataTypes::QueuePriority::Lowest:
            return PRIO_LOWEST;

        case DCPlugin::DataTypes::QueuePriority::Low:
            return PRIO_LOW;

        case DCPlugin::DataTypes::QueuePriority::Normal:
            return PRIO_NORMAL;

        case DCPlugin::DataTypes::QueuePriority::High:
            return PRIO_HIGH;

        case DCPlugin::DataTypes::QueuePriority::Highest:
            return PRIO_HIGHEST;

        case DCPlugin::DataTypes::QueuePriority::Default:
        default:
            return PRIO_DEFAULT;
    }
}

DCPlugin::DataTypes::TagPathType dcapi::CMarshalling::MarshalData(PathType tagPathType)
{
	switch(tagPathType)
    {
        case PATH_USER_CONFIG:
            return DCPlugin::DataTypes::TagPathType::UserConfig;

        case PATH_USER_LOCAL:
            return DCPlugin::DataTypes::TagPathType::UserLocal;

        case PATH_RESOURCES:
            return DCPlugin::DataTypes::TagPathType::Resources;

        case PATH_LOCALE:
            return DCPlugin::DataTypes::TagPathType::Locale;

        case PATH_GLOBAL_CONFIG:
        default:
            return DCPlugin::DataTypes::TagPathType::GlobalConfig;
    }
}

PathType dcapi::CMarshalling::MarshalData(DCPlugin::DataTypes::TagPathType tagPathType)
{
	switch(tagPathType)
    {
        case DCPlugin::DataTypes::TagPathType::UserConfig:
            return PATH_USER_CONFIG;

        case DCPlugin::DataTypes::TagPathType::UserLocal:
            return PATH_USER_LOCAL;

        case DCPlugin::DataTypes::TagPathType::Resources:
            return PATH_RESOURCES;

        case DCPlugin::DataTypes::TagPathType::Locale:
            return PATH_LOCALE;

        case DCPlugin::DataTypes::TagPathType::GlobalConfig:
        default:
            return PATH_GLOBAL_CONFIG;
    }
}

DCPlugin::DataTypes::MessageType dcapi::CMarshalling::MarshalData(MsgType messageType)
{
	switch(messageType)
    {
        case MSG_STATUS:
            return DCPlugin::DataTypes::MessageType::Status;

        case MSG_SYSTEM:
            return DCPlugin::DataTypes::MessageType::System;
            
        case MSG_CLIENT:
        default:
            return DCPlugin::DataTypes::MessageType::Client;
    }
}

MsgType dcapi::CMarshalling::MarshalData(DCPlugin::DataTypes::MessageType messageType)
{
	switch(messageType)
    {
        case DCPlugin::DataTypes::MessageType::Status:
            return MSG_STATUS;

        case DCPlugin::DataTypes::MessageType::System:
            return MSG_SYSTEM;

        case DCPlugin::DataTypes::MessageType::Client:
        default:
            return MSG_CLIENT;
    }
}

DCPlugin::DataTypes::PluginInformation^ dcapi::CMarshalling::MarshalData(dcapi::CPluginInformation* data)
{
    DCPlugin::DataTypes::PluginInformation^ pluginInfo = gcnew DCPlugin::DataTypes::PluginInformation();

    pluginInfo->Name = gcnew System::String(data->_name.c_str());
    pluginInfo->UUID = gcnew System::String(data->_guid.c_str());
    pluginInfo->Author = gcnew System::String(data->_author.c_str());
    pluginInfo->Description = gcnew System::String(data->_description.c_str());
    pluginInfo->Web = gcnew System::String(data->_web.c_str());
    pluginInfo->Version = data->_version;
    pluginInfo->APIVersion = (System::UInt32)data->_apiversion;

    for( std::map<std::string, CPluginSettingContainer>::const_iterator itSetting = data->_settings.begin();
         itSetting != data->_settings.end();
         ++itSetting )
    {
        DCPlugin::DataTypes::PluginSetting^ setting = MarshalData(itSetting->second);
        pluginInfo->Settings->Add(setting->Name, setting);
    }

    return pluginInfo;
}

dcapi::CPluginInformation dcapi::CMarshalling::MarshalData(DCPlugin::DataTypes::PluginInformation^ data)
{
    CPluginInformation pluginInfo;

    MarshalString(data->Name, pluginInfo._name);
    MarshalString(data->UUID, pluginInfo._guid);
    MarshalString(data->Author, pluginInfo._author);
    MarshalString(data->Description, pluginInfo._description);
    MarshalString(data->Web, pluginInfo._web);

    pluginInfo._version = data->Version;
    pluginInfo._apiversion = data->APIVersion;

    for each( DCPlugin::DataTypes::PluginSetting^ setting in data->Settings->Values)
    {
        dcapi::CPluginSettingContainer cppSetting = MarshalData(setting);

        pluginInfo._settings[cppSetting.GetName()] = cppSetting;
    }

    return pluginInfo;
}

DCPlugin::DataTypes::PluginSetting^ dcapi::CMarshalling::MarshalData(dcapi::CPluginSettingContainer data)
{
    DCPlugin::DataTypes::PluginSetting^ setting = gcnew DCPlugin::DataTypes::PluginSetting();

    switch(data._datatype)
    {
        case SettingDataTypeByte:
            setting->Name = gcnew System::String(data._byteSetting._name.c_str());
            setting->Description = gcnew System::String(data._byteSetting._description.c_str());
            setting->Value = (System::Object^)(System::Byte)data._byteSetting._value;
            setting->DefaultValue = (System::Object^)(System::Byte)data._byteSetting._defaultValue;
            setting->DataType = DCPlugin::DataTypes::DataType::Byte;
            setting->ValidValues = gcnew System::String(data._byteSetting._validvalues.c_str());

            break;

        case SettingDataTypeShort:
            setting->Name = gcnew System::String(data._shortSetting._name.c_str());
            setting->Description = gcnew System::String(data._shortSetting._description.c_str());
            setting->Value = (System::Object^)(System::UInt16)data._shortSetting._value;
            setting->DefaultValue = (System::Object^)(System::UInt16)data._shortSetting._defaultValue;
            setting->DataType = DCPlugin::DataTypes::DataType::Short;
            setting->ValidValues = gcnew System::String(data._shortSetting._validvalues.c_str());

            break;

        case SettingDataTypeInt:
            setting->Name = gcnew System::String(data._intSetting._name.c_str());
            setting->Description = gcnew System::String(data._intSetting._description.c_str());
            setting->Value = (System::Object^)(System::UInt32)data._intSetting._value;
            setting->DefaultValue = (System::Object^)(System::UInt32)data._intSetting._defaultValue;
            setting->DataType = DCPlugin::DataTypes::DataType::Int;
            setting->ValidValues = gcnew System::String(data._intSetting._validvalues.c_str());

            break;

        case SettingDataTypeLong:
            setting->Name = gcnew System::String(data._longSetting._name.c_str());
            setting->Description = gcnew System::String(data._longSetting._description.c_str());
            setting->Value = (System::Object^)(System::UInt64)data._longSetting._value;
            setting->DefaultValue = (System::Object^)(System::UInt64)data._longSetting._defaultValue;
            setting->DataType = DCPlugin::DataTypes::DataType::Long;
            setting->ValidValues = gcnew System::String(data._longSetting._validvalues.c_str());

            break;

        case SettingDataTypeString:
        case SettingDataTypeUnknown:
        default:
            setting->Name = gcnew System::String(data._stringSetting._name.c_str());
            setting->Description = gcnew System::String(data._stringSetting._description.c_str());
            setting->Value = (System::Object^)gcnew System::String(data._stringSetting._value.c_str());
            setting->DefaultValue = (System::Object^)gcnew System::String(data._stringSetting._defaultValue.c_str());
            setting->DataType = DCPlugin::DataTypes::DataType::String;
            setting->ValidValues = gcnew System::String(data._stringSetting._validvalues.c_str());

            break;
    }

    return setting;
}

dcapi::CPluginSettingContainer dcapi::CMarshalling::MarshalData(DCPlugin::DataTypes::PluginSetting^ data)
{
    dcapi::CPluginSettingContainer container;

    switch(data->DataType)
    {
    case DCPlugin::DataTypes::DataType::Byte:
            {
                dcapi::CPluginSetting<uint8_t> setting;

                MarshalString(data->Name, setting._name);
                MarshalString(data->Description, setting._description);
                setting._datatype = SettingDataTypeByte;
                setting._value = (uint8_t)(System::Byte)(data->Value);
                setting._defaultValue = (uint8_t)(System::Byte)(data->DefaultValue);
                MarshalString(data->ValidValues, setting._validvalues);

                container = dcapi::CPluginSettingContainer::GetContainer(setting);
            }
            break;

        case DCPlugin::DataTypes::DataType::Short:
            {
                dcapi::CPluginSetting<uint16_t> setting;

                MarshalString(data->Name, setting._name);
                MarshalString(data->Description, setting._description);
                setting._datatype = SettingDataTypeShort;
                setting._value = (uint16_t)(System::UInt16)(data->Value);
                setting._defaultValue = (uint16_t)(System::UInt16)(data->DefaultValue);
                MarshalString(data->ValidValues, setting._validvalues);

                container = dcapi::CPluginSettingContainer::GetContainer(setting);
            }
            break;

        case DCPlugin::DataTypes::DataType::Int:
            {
                dcapi::CPluginSetting<uint32_t> setting;

                MarshalString(data->Name, setting._name);
                MarshalString(data->Description, setting._description);
                setting._datatype = SettingDataTypeInt;
                setting._value = (uint32_t)(System::UInt32)(data->Value);
                setting._defaultValue = (uint32_t)(System::UInt32)(data->DefaultValue);
                MarshalString(data->ValidValues, setting._validvalues);

                container = dcapi::CPluginSettingContainer::GetContainer(setting);
            }
            break;

        case DCPlugin::DataTypes::DataType::Long:
            {
                dcapi::CPluginSetting<uint64_t> setting;

                MarshalString(data->Name, setting._name);
                MarshalString(data->Description, setting._description);
                setting._datatype = SettingDataTypeLong;
                setting._value = (uint64_t)(System::UInt64)(data->Value);
                setting._defaultValue = (uint64_t)(System::UInt64)(data->DefaultValue);
                MarshalString(data->ValidValues, setting._validvalues);

                container = dcapi::CPluginSettingContainer::GetContainer(setting);
            }
            break;

        case DCPlugin::DataTypes::DataType::String:
        default:
            {
                dcapi::CPluginSetting<std::string> setting;

                MarshalString(data->Name, setting._name);
                MarshalString(data->Description, setting._description);
                setting._datatype = SettingDataTypeString;
                MarshalString((System::String^)data->Value, setting._value);
                MarshalString((System::String^)data->DefaultValue, setting._defaultValue);
                MarshalString(data->ValidValues, setting._validvalues);

                container = dcapi::CPluginSettingContainer::GetContainer(setting);
            }
            break;
    }

    return container;
}
