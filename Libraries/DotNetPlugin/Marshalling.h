
#pragma once

#include "dcapi\PluginDefs.h"

#include "PluginInformation.h"

#include <string>

namespace dcapi {


class CMarshalling
{
public:

    static void MarshalString(System::String ^ s, std::string& os);
    static void MarshalString(System::String ^ s, std::wstring& os);

    static DCPlugin::DataTypes::QueueData^ MarshalData(QueueDataPtr data);
    static QueueDataPtr MarshalData(DCPlugin::DataTypes::QueueData^ data);

    static DCPlugin::DataTypes::HubData^ MarshalData(HubDataPtr data);
    static HubDataPtr MarshalData(DCPlugin::DataTypes::HubData^ data);

    static DCPlugin::DataTypes::UserData^ MarshalData(UserDataPtr data);
    static UserDataPtr MarshalData(DCPlugin::DataTypes::UserData^ data);

    static DCPlugin::DataTypes::ConnectionData^ MarshalData(ConnectionDataPtr data);
    static ConnectionDataPtr MarshalData(DCPlugin::DataTypes::ConnectionData^ data);

    static DCPlugin::DataTypes::TagData^ MarshalData(TagDataPtr data);
    static TagDataPtr MarshalData(DCPlugin::DataTypes::TagData^ data);

    static DCPlugin::DataTypes::UDPData^ MarshalData(UDPDataPtr data);
    static UDPDataPtr MarshalData(DCPlugin::DataTypes::UDPData^ data);

    static DCPlugin::DataTypes::StringData^ MarshalData(StringDataPtr data);
    static StringDataPtr MarshalData(DCPlugin::DataTypes::StringData^ data);

    static DCPlugin::DataTypes::CommandData^ MarshalData(CommandDataPtr data);
    static CommandDataPtr MarshalData(DCPlugin::DataTypes::CommandData^ data);

    static bool MarshalData(dcBool boolValue);
    static dcBool MarshalData(bool boolValue);

    static DCPlugin::DataTypes::ProtocolType MarshalData(ProtocolType protocol);
    static ProtocolType MarshalData(DCPlugin::DataTypes::ProtocolType protocol);

	static DCPlugin::DataTypes::QueuePriority MarshalData(QueuePrio priority);
    static QueuePrio MarshalData(DCPlugin::DataTypes::QueuePriority priority);

	static DCPlugin::DataTypes::TagPathType MarshalData(PathType tagPathType);
    static PathType MarshalData(DCPlugin::DataTypes::TagPathType tagPathType);

	static DCPlugin::DataTypes::MessageType MarshalData(MsgType msgType);
    static MsgType MarshalData(DCPlugin::DataTypes::MessageType msgType);

    static DCPlugin::DataTypes::PluginInformation^ MarshalData(dcapi::CPluginInformation* data);
    static dcapi::CPluginInformation MarshalData(DCPlugin::DataTypes::PluginInformation^ data);

    static DCPlugin::DataTypes::PluginSetting^ MarshalData(dcapi::CPluginSettingContainer data);
    static dcapi::CPluginSettingContainer MarshalData(DCPlugin::DataTypes::PluginSetting^ data);

};

}