
#ifndef CNETPLUGIN_SINK
#define CNETPLUGIN_SINK

#using <mscorlib.dll>

#include "CommandReferrer.h"

#include <map>
#include <string>

namespace dcapi {

public ref class CNETPluginSink : DCPlugin::DataTypes::INETPluginSink
{
    #pragma region Constructors

public:

    CNETPluginSink();

    #pragma endregion

    #pragma region INETPluginSink

public:

    #pragma region Core

    virtual System::String^ GetApplicationName();

    virtual void SetApplicationName(System::String^ name);

    #pragma endregion

    #pragma region Log

    virtual void LogMessage(System::String^ message);

    #pragma endregion

    #pragma region Config

    virtual System::String^ GetInstallPath();

    virtual System::String^ GetPath(DCPlugin::DataTypes::TagPathType pathType);

    virtual System::String^ GetConfig(System::String^ name);

    virtual bool GetBoolConfig(System::String^ name);

    virtual System::Int32 GetIntConfig(System::String^ name);

    virtual System::Int64 GetLongConfig(System::String^ name);

    virtual void SetConfig(System::String^ name, System::String^ value);

    virtual void SetConfig(System::String^ name, bool value);

    virtual void SetConfig(System::String^ name, System::Int32 value);

    virtual void SetConfig(System::String^ name, System::Int64 value);

    virtual System::String^ GetLanguage();

    #pragma endregion

    #pragma region Connection

    virtual void SendUdpData(System::String^ ipAddress, System::UInt32 port, System::String^ data, System::UInt64 amount);

    virtual void SendProtocolCommand(DCPlugin::DataTypes::ConnectionData^ connectionData, System::String^ command);

    virtual void TerminateConnection(DCPlugin::DataTypes::ConnectionData^ connectionData, bool graceless);

    virtual DCPlugin::DataTypes::UserData^ GetConnectionUser(DCPlugin::DataTypes::ConnectionData^ connectionData);

    #pragma endregion

    #pragma region Hub

    virtual DCPlugin::DataTypes::HubData^ AddHub(System::String^ url, System::String^ nick, System::String^ password);

    virtual DCPlugin::DataTypes::HubData^ FindHub(System::String^ url);

    virtual void RemoveHub(DCPlugin::DataTypes::HubData^ hubData);

    virtual void EmulateProtocolCommand(DCPlugin::DataTypes::HubData^ hubData, System::String^ command);

    virtual void SendProtocolCommand(DCPlugin::DataTypes::HubData^ hubData, System::String^ command);

    virtual void SendMessage(DCPlugin::DataTypes::HubData^ hubData, System::String^ message, bool thirdPerson);

    virtual void LocalMessage(DCPlugin::DataTypes::HubData^ hubData, System::String^ message, DCPlugin::DataTypes::MessageType messageType);

    virtual void SendPrivateMessage(DCPlugin::DataTypes::UserData^ userData, System::String^ message, bool thirdPerson);

    virtual DCPlugin::DataTypes::UserData^ FindUser(System::String^ cid, System::String^ hubURL);

    #pragma endregion

    #pragma region Queue

    virtual DCPlugin::DataTypes::QueueData^ AddList(DCPlugin::DataTypes::UserData^ userData, bool silent);

    virtual DCPlugin::DataTypes::QueueData^ AddDownload(System::String^ hash, System::UInt64 size, System::String^ target);

    virtual DCPlugin::DataTypes::QueueData^ FindDownload(System::String^ target);

    virtual void RemoveDownload(DCPlugin::DataTypes::QueueData^ queueData);

    virtual void SetPriority(DCPlugin::DataTypes::QueueData^ queueData, DCPlugin::DataTypes::QueuePriority priority);

    virtual bool Pause(DCPlugin::DataTypes::QueueData^ queueData);

    #pragma endregion

    #pragma region Tagger

    virtual System::String^ GetText(DCPlugin::DataTypes::TagData^ tagData);

    virtual void AddTag(DCPlugin::DataTypes::TagData^ tagData, System::UInt64 startPlace, System::UInt64 endPlace, System::String^ id, System::String^ attributes);

    virtual void ReplaceTagText(DCPlugin::DataTypes::TagData^ tagData, System::UInt64 startPlace, System::UInt64 endPlace, System::String^ replacement);

    #pragma endregion

    #pragma region UI

    virtual void AddCommand(System::String^ name, DCPlugin::DataTypes::Delegates::CommandDelegate^ command, System::String^ icon);

    virtual void RemoveCommand(System::String^ name);

    virtual void PlaySoundInUI(System::String^ path);

    virtual void Notify(System::String^ title, System::String^ message);

    #pragma endregion

    #pragma endregion

private:

    System::Collections::Generic::Dictionary<System::String^, System::IntPtr>^ _commands;

};

}    

#endif // CNETPLUGIN_SINK
