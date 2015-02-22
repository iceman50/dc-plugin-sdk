
#include "stdafx.h"

#include "NETPluginSink.h"
#include "Marshalling.h"

#include <dcapi\Config.hpp>
#include <dcapi\Core.hpp>
#include <dcapi\Logger.hpp>
#include <dcapi\Queue.hpp>
#include <dcapi\UI.hpp>
#include <dcapi\Connections.hpp>
#include <dcapi\Tagger.hpp>
#include <dcapi\Hubs.hpp>

dcapi::CNETPluginSink::CNETPluginSink()
{
    _commands = gcnew System::Collections::Generic::Dictionary<System::String^, System::IntPtr>();
}

#pragma region INETPluginSink

#pragma region Core

System::String^ dcapi::CNETPluginSink::GetApplicationName()
{
    std::string strAppName = Core::appName;
    return gcnew System::String(strAppName.c_str());
}

void dcapi::CNETPluginSink::SetApplicationName(System::String^ name)
{
    if( name == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("SetApplicationName: 'name' is null."));
    }

    std::string cppName;
    CMarshalling::MarshalString( name, cppName );

    Core::appName = cppName;
}

#pragma endregion

#pragma region Log

void dcapi::CNETPluginSink::LogMessage(System::String^ message)
{
    if( message == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("LogMessage: 'message' is null."));
    }

    std::string cppMessage;
    CMarshalling::MarshalString( message, cppMessage );

    Logger::log(cppMessage);
}

#pragma endregion

#pragma region Config

System::String^ dcapi::CNETPluginSink::GetInstallPath()
{
    std::string strInstallPath = Config::getInstallPath();
    return gcnew System::String(strInstallPath.c_str());
}

System::String^ dcapi::CNETPluginSink::GetPath(DCPlugin::DataTypes::TagPathType tagPathType)
{
    PathType pathType = CMarshalling::MarshalData(tagPathType);

    std::string strPath = Config::getPath(pathType);
    return gcnew System::String(strPath.c_str());
}

System::String^ dcapi::CNETPluginSink::GetConfig(System::String^ name)
{
    if( name == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("GetConfig: 'name' is null."));
    }

    std::string cppName;
    CMarshalling::MarshalString( name, cppName );

    std::string value = Config::getConfig( cppName.c_str() );
    return gcnew System::String( value.c_str() );
}

bool dcapi::CNETPluginSink::GetBoolConfig(System::String^ name)
{
    if( name == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("GetBoolConfig: 'name' is null."));
    }

    std::string cppName;
    CMarshalling::MarshalString( name, cppName );

    return Config::getBoolConfig( cppName.c_str() );
}

System::Int32 dcapi::CNETPluginSink::GetIntConfig(System::String^ name)
{
    if( name == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("GetIntConfig: 'name' is null."));
    }

    std::string cppName;
    CMarshalling::MarshalString( name, cppName );

    return Config::getIntConfig( cppName.c_str() );
}

System::Int64 dcapi::CNETPluginSink::GetLongConfig(System::String^ name)
{
    if( name == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("GetLongConfig: 'name' is null."));
    }

    std::string cppName;
    CMarshalling::MarshalString( name, cppName );

    return Config::getInt64Config( cppName.c_str() );
}

void dcapi::CNETPluginSink::SetConfig(System::String^ name, System::String^ value)
{
    if( name == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("SetConfig: 'name' is null."));
    }

    if( value == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("SetConfig: 'value' is null."));
    }

    std::string cppName;
    CMarshalling::MarshalString( name, cppName );

    std::string cppValue;
    CMarshalling::MarshalString( value, cppValue );

    Config::setConfig( cppName.c_str(), cppValue.c_str() );
}

void dcapi::CNETPluginSink::SetConfig(System::String^ name, bool value)
{
    if( name == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("SetConfig: 'name' is null."));
    }

    std::string cppName;
    CMarshalling::MarshalString( name, cppName );

    Config::setConfig( cppName.c_str(), static_cast<bool>(value) );
}

void dcapi::CNETPluginSink::SetConfig(System::String^ name, System::Int32 value)
{
    if( name == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("SetConfig: 'name' is null."));
    }

    std::string cppName;
    CMarshalling::MarshalString( name, cppName );

    Config::setConfig( cppName.c_str(), static_cast<int>(value) );
}

void dcapi::CNETPluginSink::SetConfig(System::String^ name, System::Int64 value)
{
    if( name == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("SetConfig: 'name' is null."));
    }

    std::string cppName;
    CMarshalling::MarshalString( name, cppName );

    Config::setConfig( cppName.c_str(), static_cast<long>(value) );
}

System::String^ dcapi::CNETPluginSink::GetLanguage()
{
    auto language = Config::handle()->get_language();
    return gcnew System::String(language->value);
}

#pragma endregion

#pragma region Connection

void dcapi::CNETPluginSink::SendUdpData(System::String^ ipAddress, System::UInt32 port, System::String^ data, System::UInt64 amount)
{
    if( ipAddress == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("SendUdpData: 'ipAddress' is null."));
    }

	if( data == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("SendUdpData: 'data' is null."));
    }

    std::string cppIPAddress;
    CMarshalling::MarshalString( ipAddress, cppIPAddress );

    std::string cppData;
    CMarshalling::MarshalString( data, cppData );

    Connections::handle()->send_udp_data(cppIPAddress.c_str(), static_cast<uint32_t>(port), (dcptr_t)cppData.c_str(), static_cast<size_t>(amount));
}

void dcapi::CNETPluginSink::SendProtocolCommand(DCPlugin::DataTypes::ConnectionData^ connectionData, System::String^ command)
{
    if( connectionData == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("SendProtocolCommand: 'connectionData' is null."));
    }

    if( command == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("SendProtocolCommand: 'command' is null."));
    }

    auto cppConnectionData = CMarshalling::MarshalData(connectionData);

    std::string cppCommand;
    CMarshalling::MarshalString( command, cppCommand );

    Connections::handle()->send_protocol_cmd(cppConnectionData, cppCommand.c_str());
}

void dcapi::CNETPluginSink::TerminateConnection(DCPlugin::DataTypes::ConnectionData^ connectionData, bool graceless)
{
    if( connectionData == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("TerminateConnection: 'connectionData' is null."));
    }

    auto cppConnectionData = CMarshalling::MarshalData(connectionData);
    Connections::handle()->terminate_conn(cppConnectionData, CMarshalling::MarshalData(graceless));
}

DCPlugin::DataTypes::UserData^ dcapi::CNETPluginSink::GetConnectionUser(DCPlugin::DataTypes::ConnectionData^ connectionData)
{
    if( connectionData == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("GetConnectionUser: 'connectionData' is null."));
    }

    auto cppConnectionData = CMarshalling::MarshalData(connectionData);

    UserDataPtr userData = Connections::handle()->get_user(cppConnectionData);
    return CMarshalling::MarshalData(userData);
}

#pragma endregion

#pragma region Hub

DCPlugin::DataTypes::HubData^ dcapi::CNETPluginSink::AddHub(System::String^ url, System::String^ nick, System::String^ password)
{
    if( url == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("AddHub: 'url' is null."));
    }

    if( nick == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("AddHub: 'nick' is null."));
    }

    if( password == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("AddHub: 'password' is null."));
    }

    std::string cppUrl;
    CMarshalling::MarshalString( url, cppUrl );

    std::string cppNick;
    CMarshalling::MarshalString( nick, cppNick );

    std::string cppPassword;
    CMarshalling::MarshalString( password, cppPassword );

    HubDataPtr cppHubData = Hubs::handle()->add_hub(cppUrl.c_str(), cppNick.c_str(), cppPassword.c_str());
    return CMarshalling::MarshalData(cppHubData);
}

DCPlugin::DataTypes::HubData^ dcapi::CNETPluginSink::FindHub(System::String^ url)
{
    if( url == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("FindHub: 'url' is null."));
    }

    std::string cppUrl;
    CMarshalling::MarshalString( url, cppUrl );

    HubDataPtr cppHubData = Hubs::handle()->find_hub(cppUrl.c_str());
    return CMarshalling::MarshalData(cppHubData);
}

void dcapi::CNETPluginSink::RemoveHub(DCPlugin::DataTypes::HubData^ hubData)
{
    auto cppHubData = CMarshalling::MarshalData(hubData);
    Hubs::handle()->remove_hub(cppHubData);
}

void dcapi::CNETPluginSink::EmulateProtocolCommand(DCPlugin::DataTypes::HubData^ hubData, System::String^ command)
{
    if( hubData == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("EmulateProtocolCommand: 'hubData' is null."));
    }

    if( command == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("EmulateProtocolCommand: 'command' is null."));
    }

    auto cppHubData = CMarshalling::MarshalData(hubData);

    std::string cppCommand;
    CMarshalling::MarshalString( command, cppCommand );

    Hubs::handle()->emulate_protocol_cmd(cppHubData, cppCommand.c_str());
}

void dcapi::CNETPluginSink::SendProtocolCommand(DCPlugin::DataTypes::HubData^ hubData, System::String^ command)
{
    if( hubData == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("SendProtocolCommand: 'hubData' is null."));
    }

    if( command == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("SendProtocolCommand: 'command' is null."));
    }

    auto cppHubData = CMarshalling::MarshalData(hubData);

    std::string cppCommand;
    CMarshalling::MarshalString( command, cppCommand );

    Hubs::handle()->send_protocol_cmd(cppHubData, cppCommand.c_str());
}

void dcapi::CNETPluginSink::SendMessage(DCPlugin::DataTypes::HubData^ hubData, System::String^ message, bool thirdPerson)
{
    if( hubData == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("SendMessage: 'hubData' is null."));
    }

    if( message == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("SendMessage: 'message' is null."));
    }

    auto cppHubData = CMarshalling::MarshalData(hubData);

    std::string cppMessage;
    CMarshalling::MarshalString( message, cppMessage );

    Hubs::handle()->send_message(cppHubData, cppMessage.c_str(), CMarshalling::MarshalData(thirdPerson));
}

void dcapi::CNETPluginSink::LocalMessage(DCPlugin::DataTypes::HubData^ hubData, System::String^ message, DCPlugin::DataTypes::MessageType messageType)
{
    if( hubData == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("LocalMessage: 'hubData' is null."));
    }

    if( message == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("LocalMessage: 'message' is null."));
    }

    auto cppHubData = CMarshalling::MarshalData(hubData);

    std::string cppMessage;
    CMarshalling::MarshalString( message, cppMessage );

    MsgType msgType = CMarshalling::MarshalData(messageType);

    Hubs::handle()->local_message(cppHubData, cppMessage.c_str(), msgType);
}

void dcapi::CNETPluginSink::SendPrivateMessage(DCPlugin::DataTypes::UserData^ userData, System::String^ message, bool thirdPerson)
{
    if( userData == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("SendPrivateMessage: 'userData' is null."));
    }

    if( message == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("SendPrivateMessage: 'message' is null."));
    }

    auto cppUserData = CMarshalling::MarshalData(userData);

    std::string cppMessage;
    CMarshalling::MarshalString( message, cppMessage );

    Hubs::handle()->send_private_message(cppUserData, cppMessage.c_str(), CMarshalling::MarshalData(thirdPerson));
}

DCPlugin::DataTypes::UserData^ dcapi::CNETPluginSink::FindUser(System::String^ cid, System::String^ hubURL)
{
    if( cid == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("FindUser: 'cid' is null."));
    }

    if( hubURL == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("FindUser: 'hubURL' is null."));
    }

    std::string cppCid;
    CMarshalling::MarshalString( cid, cppCid );

    std::string cppHubURL;
    CMarshalling::MarshalString( hubURL, cppHubURL );

    UserDataPtr cppUserData = Hubs::handle()->find_user( cppCid.c_str(), cppHubURL.c_str() );

    return CMarshalling::MarshalData(cppUserData);
}

#pragma endregion

#pragma region Queue

DCPlugin::DataTypes::QueueData^ dcapi::CNETPluginSink::AddList(DCPlugin::DataTypes::UserData^ userData, bool silent)
{
    if( userData == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("AddList: 'userData' is null."));
    }

    auto cppUserData = CMarshalling::MarshalData(userData);
    QueueDataPtr cppQueueData = Queue::handle()->add_list(cppUserData, CMarshalling::MarshalData(silent));

    return CMarshalling::MarshalData(cppQueueData);
}

DCPlugin::DataTypes::QueueData^ dcapi::CNETPluginSink::AddDownload(System::String^ hash, System::UInt64 size, System::String^ target)
{
    if( hash == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("AddDownload: 'hash' is null."));
    }

    if( target == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("AddDownload: 'target' is null."));
    }

    std::string cppHash;
    CMarshalling::MarshalString( hash, cppHash );

    std::string cppTarget;
    CMarshalling::MarshalString( target, cppTarget );

    QueueDataPtr cppQueueData = Queue::handle()->add_download(cppHash.c_str(), static_cast<uint64_t>(size), cppTarget.c_str());

    DCPlugin::DataTypes::QueueData^ queueData = CMarshalling::MarshalData(cppQueueData);
    return queueData;
}

DCPlugin::DataTypes::QueueData^ dcapi::CNETPluginSink::FindDownload(System::String^ target)
{
    if( target == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("FindDownload: 'target' is null."));
    }

    std::string cppTarget;
    CMarshalling::MarshalString( target, cppTarget );

    QueueDataPtr cppQueueData = Queue::handle()->find_download(cppTarget.c_str());

    DCPlugin::DataTypes::QueueData^ queueData = CMarshalling::MarshalData(cppQueueData);
    return queueData;
}

void dcapi::CNETPluginSink::RemoveDownload(DCPlugin::DataTypes::QueueData^ queueData)
{
    if( queueData == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("RemoveDownload: 'queueData' is null."));
    }

    QueueDataPtr cppQueueData = CMarshalling::MarshalData(queueData);
    Queue::handle()->remove_download(cppQueueData);
}

void dcapi::CNETPluginSink::SetPriority(DCPlugin::DataTypes::QueueData^ queueData, DCPlugin::DataTypes::QueuePriority priority)
{
    if( queueData == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("SetPriority: 'queueData' is null."));
    }

    QueueDataPtr cppQueueData = CMarshalling::MarshalData(queueData);

    QueuePrio cppPriority = CMarshalling::MarshalData(priority);

    Queue::handle()->set_priority(cppQueueData, cppPriority);
}

bool dcapi::CNETPluginSink::Pause(DCPlugin::DataTypes::QueueData^ queueData)
{
    if( queueData == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("Pause: 'queueData' is null."));
    }

    QueueDataPtr cppQueueData = CMarshalling::MarshalData(queueData);

    bool returnValue = CMarshalling::MarshalData(Queue::handle()->pause(cppQueueData));

    return returnValue;
}

#pragma endregion

#pragma region Tagger

System::String^ dcapi::CNETPluginSink::GetText(DCPlugin::DataTypes::TagData^ tagData)
{
    if( tagData == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("GetText: 'tagData' is null."));
    }

    auto cppTagData = CMarshalling::MarshalData(tagData);
    
    const char* text = Tagger::handle()->get_text(cppTagData);
    return gcnew System::String(text);
}

void dcapi::CNETPluginSink::AddTag(DCPlugin::DataTypes::TagData^ tagData, System::UInt64 startPlace, System::UInt64 endPlace, System::String^ id, System::String^ attributes)
{
    if( tagData == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("AddTag: 'tagData' is null."));
    }

    if( id == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("AddTag: 'id' is null."));
    }

    if( attributes == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("AddTag: 'attributes' is null."));
    }

    std::string cppId;
    CMarshalling::MarshalString( id, cppId );

    std::string cppAttributes;
    CMarshalling::MarshalString( attributes, cppAttributes );

    auto cppTagData = CMarshalling::MarshalData(tagData);

    Tagger::handle()->add_tag(cppTagData, static_cast<size_t>(startPlace), static_cast<size_t>(endPlace), cppId.c_str(), cppAttributes.c_str());
}

void dcapi::CNETPluginSink::ReplaceTagText(DCPlugin::DataTypes::TagData^ tagData, System::UInt64 startPlace, System::UInt64 endPlace, System::String^ replacement)
{
    if( tagData == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("ReplaceTagText: 'tagData' is null."));
    }

    if( replacement == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("ReplaceTagText: 'replacement' is null."));
    }

    std::string cppReplacement;
    CMarshalling::MarshalString( replacement, cppReplacement );

    auto cppTagData = CMarshalling::MarshalData(tagData);

    Tagger::handle()->replace_text(cppTagData, static_cast<size_t>(startPlace), static_cast<size_t>(endPlace), cppReplacement.c_str());
}

#pragma endregion

#pragma region UI

void dcapi::CNETPluginSink::AddCommand(System::String^ name, DCPlugin::DataTypes::Delegates::CommandDelegate^ command, System::String^ icon)
{
    if( name == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("AddCommand: 'name' is null."));
    }

    // Do not validate whether icon is valid.
    // It is allowed to pass an invalid icon.

    std::string cppName;
    CMarshalling::MarshalString( name, cppName );

    std::string cppIcon;
    CMarshalling::MarshalString( icon, cppIcon );

    if( !_commands->ContainsKey(name) )
    {
        dcapi::CCommandReferrer* ptr = new dcapi::CCommandReferrer();
        ptr->Initialize(cppName, cppIcon, command);

        System::IntPtr data(ptr);

        _commands->Add(name, data);
    }
}

void dcapi::CNETPluginSink::RemoveCommand(System::String^ name)
{
    if( name == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("RemoveCommand: 'name' is null."));
    }

    std::string cppName;
    CMarshalling::MarshalString( name, cppName );

    UI::removeCommand(cppName.c_str());

    // Remove from internal list
    if(_commands->ContainsKey(name))
    {
        System::IntPtr data;
        _commands->TryGetValue(name, data);

        dcapi::CCommandReferrer* ptr = reinterpret_cast<dcapi::CCommandReferrer*>(data.ToPointer());

        delete ptr;
        ptr = NULL;

        _commands->Remove(name);
    }
}

void dcapi::CNETPluginSink::PlaySoundInUI(System::String^ path)
{
    if( path == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("PlaySoundInUI: 'path' is null."));
    }

    std::string cppPath;
    CMarshalling::MarshalString( path, cppPath );

    UI::handle()->play_sound( cppPath.c_str() );
}

void dcapi::CNETPluginSink::Notify(System::String^ title, System::String^ message)
{
    if( title == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("Notify: 'title' is null."));
    }

    if( message == nullptr )
    {
        throw gcnew System::NullReferenceException(gcnew System::String("Notify: 'message' is null."));
    }

    std::string cppTitle;
    CMarshalling::MarshalString( title, cppTitle );

    std::string cppMessage;
    CMarshalling::MarshalString( message, cppMessage );

    UI::handle()->notify( cppTitle.c_str(), cppMessage.c_str() );
}

#pragma endregion

#pragma endregion