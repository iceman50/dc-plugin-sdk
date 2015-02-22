
#include "stdafx.h"

#include "PluginHelper.h"
#include "Marshalling.h"

#include "AssemblyLoader.h"
#include "NETPluginSink.h"

#include "dcapi\PluginDefs.h"
#include "dcapi\Logger.hpp"

bool dcapi::CPluginHelper::Initialize(CPluginInformation* pPluginInformation, DCCorePtr core, bool install, bool runtime)
{
    m_pPluginInformation = pPluginInformation;

    try
    {
        if( !m_pPlugin->Initialize(install, runtime) )
        {
            return false;
        }
    }
    catch(System::Exception^ exp)
    {
        LogException("Initialize", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("Initialize", cppExp);
    }
    catch( ... )
    {
        LogException("Initialize");
    }

	// Call base class
    return dcapi::CPluginBase::Initialize(pPluginInformation, core, install, runtime);
}

#pragma region Hooks

#pragma region Chat

bool dcapi::CPluginHelper::OnChatIncoming(HubDataPtr cppHubData, char* cppData, bool& bBreak)
{
    try
    {
        if(cppHubData == NULL)
        {
            LogWarning("OnChatIncoming", "Parameter 'cppHubData' is null.");
        }

        auto hubData = CMarshalling::MarshalData(cppHubData);
        System::String^ data = gcnew System::String(cppData);

        return m_pPlugin->OnChatIncoming(hubData, data, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnChatIncoming", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnChatIncoming", cppExp);
    }
    catch( ... )
    {
        LogException("OnChatIncoming");
    }

    return dcapi::CPluginBase::OnChatIncoming(cppHubData, cppData, bBreak);
}

bool dcapi::CPluginHelper::OnChatOutgoing(HubDataPtr cppHubData, char* cppData, bool& bBreak)
{
    try
    {
        if(cppHubData == NULL)
        {
            LogWarning("OnChatOutgoing", "Parameter 'cppHubData' is null.");
        }

        auto hubData = CMarshalling::MarshalData(cppHubData);
        System::String^ data = gcnew System::String(cppData);

        return m_pPlugin->OnChatOutgoing(hubData, data, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnChatOutgoing", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnChatOutgoing", cppExp);
    }
    catch( ... )
    {
        LogException("OnChatOutgoing");
    }

    return dcapi::CPluginBase::OnChatOutgoing(cppHubData, cppData, bBreak);
}

bool dcapi::CPluginHelper::OnChatIncomingPM(UserDataPtr cppUserData, char* cppData, bool& bBreak)
{
    try
    {
        if(cppUserData == NULL)
        {
            LogWarning("OnChatIncomingPM", "Parameter 'cppUserData' is null.");
        }

        auto userData = CMarshalling::MarshalData(cppUserData);
        System::String^ data = gcnew System::String(cppData);

        return m_pPlugin->OnChatIncomingPM(userData, data, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnChatIncomingPM", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnChatIncomingPM", cppExp);
    }
    catch( ... )
    {
        LogException("OnChatIncomingPM");
    }

    return dcapi::CPluginBase::OnChatIncomingPM(cppUserData, cppData, bBreak);
}

bool dcapi::CPluginHelper::OnChatOutgoingPM(UserDataPtr cppUserData, char* cppData, bool& bBreak)
{
    try
    {
        if(cppUserData == NULL)
        {
            LogWarning("OnChatIncomingPM", "Parameter 'cppUserData' is null.");
        }

        auto userData = CMarshalling::MarshalData(cppUserData);
        System::String^ data = gcnew System::String(cppData);

        return m_pPlugin->OnChatOutgoingPM(userData, data, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnChatOutgoingPM", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnChatOutgoingPM", cppExp);
    }
    catch( ... )
    {
        LogException("OnChatOutgoingPM");
    }

    return dcapi::CPluginBase::OnChatOutgoingPM(cppUserData, cppData, bBreak);
}

#pragma endregion

#pragma region Timer

bool dcapi::CPluginHelper::OnTimerSecond(uint64_t data, bool& bBreak)
{
    try
    {
        return m_pPlugin->OnTimerSecond((System::UInt64)data, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnTimerSecond", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnTimerSecond", cppExp);
    }
    catch( ... )
    {
        LogException("OnTimerSecond");
    }

    return dcapi::CPluginBase::OnTimerSecond(data, bBreak);
}

bool dcapi::CPluginHelper::OnTimerMinute(uint64_t data, bool& bBreak)
{
    try
    {
        return m_pPlugin->OnTimerMinute((System::UInt64)data, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnTimerMinute", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnTimerMinute", cppExp);
    }
    catch( ... )
    {
        LogException("OnTimerMinute");
    }

    return dcapi::CPluginBase::OnTimerSecond(data, bBreak);
}

#pragma endregion

#pragma region Hubs

bool dcapi::CPluginHelper::OnHubsOnline(HubDataPtr data, bool& bBreak)
{
    try
    {
        if(data == NULL)
        {
            LogWarning("OnHubsOnline", "Parameter 'data' is null.");
        }

        auto hubData = CMarshalling::MarshalData(data);
        return m_pPlugin->OnHubOnline(hubData, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnHubsOnline", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnHubsOnline", cppExp);
    }
    catch( ... )
    {
        LogException("OnHubsOnline");
    }

    return dcapi::CPluginBase::OnHubsOnline(data, bBreak);
}

bool dcapi::CPluginHelper::OnHubsOffline(HubDataPtr data, bool& bBreak)
{
    try
    {
        if(data == NULL)
        {
            LogWarning("OnHubsOffline", "Parameter 'data' is null.");
        }

        auto hubData = CMarshalling::MarshalData(data);
        return m_pPlugin->OnHubOffline(hubData, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnHubsOffline", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnHubsOffline", cppExp);
    }
    catch( ... )
    {
        LogException("OnHubsOffline");
    }

    return dcapi::CPluginBase::OnHubsOffline(data, bBreak);
}

#pragma endregion

#pragma region Users

bool dcapi::CPluginHelper::OnUserOnline(UserDataPtr cppData, bool& bBreak)
{
    try
    {
        if(cppData == NULL)
        {
            LogWarning("OnUserOnline", "Parameter 'cppData' is null.");
        }

        auto data = CMarshalling::MarshalData(cppData);
        return m_pPlugin->OnUserOnline(data, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnUserOnline", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnUserOnline", cppExp);
    }
    catch( ... )
    {
        LogException("OnUserOnline");
    }

    return dcapi::CPluginBase::OnUserOnline(cppData, bBreak);
}
bool dcapi::CPluginHelper::OnUserOffline(UserDataPtr cppData, bool& bBreak)
{
    try
    {
        if(cppData == NULL)
        {
            LogWarning("OnUserOffline", "Parameter 'cppData' is null.");
        }

        auto data = CMarshalling::MarshalData(cppData);
        return m_pPlugin->OnUserOffline(data, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnUserOffline", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnUserOffline", cppExp);
    }
    catch( ... )
    {
        LogException("OnUserOffline");
    }

    return dcapi::CPluginBase::OnUserOffline(cppData, bBreak);
}

#pragma endregion

#pragma region Network

bool dcapi::CPluginHelper::OnNetworkHubDataIn(HubDataPtr cppHubData, char* cppData, bool& bBreak)
{
    try
    {
        if(cppHubData == NULL)
        {
            LogWarning("OnNetworkHubDataIn", "Parameter 'cppHubData' is null.");
        }

        auto hubData = CMarshalling::MarshalData(cppHubData);
        System::String^ data = gcnew System::String(cppData);

        return m_pPlugin->OnNetworkHubDataIn(hubData, data, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnNetworkHubDataIn", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnNetworkHubDataIn", cppExp);
    }
    catch( ... )
    {
        LogException("OnNetworkHubDataIn");
    }

    return dcapi::CPluginBase::OnNetworkHubDataIn(cppHubData, cppData, bBreak);
}

bool dcapi::CPluginHelper::OnNetworkHubDataOut(HubDataPtr cppHubData, char* cppData, bool& bBreak)
{
    try
    {
        if(cppHubData == NULL)
        {
            LogWarning("OnNetworkHubDataOut", "Parameter 'cppHubData' is null.");
        }

        auto hubData = CMarshalling::MarshalData(cppHubData);
        System::String^ data = gcnew System::String(cppData);

        return m_pPlugin->OnNetworkHubDataOut(hubData, data, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnNetworkHubDataOut", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnNetworkHubDataOut", cppExp);
    }
    catch( ... )
    {
        LogException("OnNetworkHubDataOut");
    }

    return dcapi::CPluginBase::OnNetworkHubDataOut(cppHubData, cppData, bBreak);
}

bool dcapi::CPluginHelper::OnNetworkClientDataIn(ConnectionDataPtr cppClientData, char* cppData, bool& bBreak)
{
    try
    {
        if(cppClientData == NULL)
        {
            LogWarning("OnNetworkClientDataIn", "Parameter 'cppClientData' is null.");
        }

        auto clientData = CMarshalling::MarshalData(cppClientData);
        System::String^ data = gcnew System::String(cppData);

        return m_pPlugin->OnNetworkClientDataIn(clientData, data, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnNetworkClientDataIn", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnNetworkClientDataIn", cppExp);
    }
    catch( ... )
    {
        LogException("OnNetworkClientDataIn");
    }

    return dcapi::CPluginBase::OnNetworkClientDataIn(cppClientData, cppData, bBreak);
}

bool dcapi::CPluginHelper::OnNetworkClientDataOut(ConnectionDataPtr cppClientData, char* cppData, bool& bBreak)
{
    try
    {
        if(cppClientData == NULL)
        {
            LogWarning("OnNetworkClientDataOut", "Parameter 'cppClientData' is null.");
        }

        auto clientData = CMarshalling::MarshalData(cppClientData);
        System::String^ data = gcnew System::String(cppData);

        return m_pPlugin->OnNetworkClientDataOut(clientData, data, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnNetworkClientDataOut", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnNetworkClientDataOut", cppExp);
    }
    catch( ... )
    {
        LogException("OnNetworkClientDataOut");
    }

    return dcapi::CPluginBase::OnNetworkClientDataOut(cppClientData, cppData, bBreak);
}

bool dcapi::CPluginHelper::OnNetworkUDPDataIn(UDPDataPtr cppUdpData, char* cppData, bool& bBreak)
{
    try
    {
        if(cppUdpData == NULL)
        {
            LogWarning("OnNetworkUDPDataIn", "Parameter 'cppUdpData' is null.");
        }

        auto udpData = CMarshalling::MarshalData(cppUdpData);
        System::String^ data = gcnew System::String(cppData);

        return m_pPlugin->OnNetworkUDPDataIn(udpData, data, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnNetworkUDPDataIn", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnNetworkUDPDataIn", cppExp);
    }
    catch( ... )
    {
        LogException("OnNetworkUDPDataIn");
    }

    return dcapi::CPluginBase::OnNetworkUDPDataIn(cppUdpData, cppData, bBreak);
}

bool dcapi::CPluginHelper::OnNetworkUDPDataOut(UDPDataPtr cppUdpData, char* cppData, bool& bBreak)
{
    try
    {
        if(cppUdpData == NULL)
        {
            LogWarning("OnNetworkUDPDataOut", "Parameter 'cppUdpData' is null.");
        }

        auto udpData = CMarshalling::MarshalData(cppUdpData);
        System::String^ data = gcnew System::String(cppData);

        return m_pPlugin->OnNetworkUDPDataOut(udpData, data, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnNetworkUDPDataOut", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnNetworkUDPDataOut", cppExp);
    }
    catch( ... )
    {
        LogException("OnNetworkUDPDataOut");
    }

    return dcapi::CPluginBase::OnNetworkUDPDataOut(cppUdpData, cppData, bBreak);
}

#pragma endregion

#pragma region Queue
bool dcapi::CPluginHelper::OnQueueAdded(QueueDataPtr cppData, bool& bBreak)
{
    try
    {
        if(cppData == NULL)
        {
            LogWarning("OnQueueAdded", "Parameter 'cppData' is null.");
        }

        auto data = CMarshalling::MarshalData(cppData);

        return m_pPlugin->OnQueueAdded(data, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnQueueAdded", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnQueueAdded", cppExp);
    }
    catch( ... )
    {
        LogException("OnQueueAdded");
    }

    return dcapi::CPluginBase::OnQueueAdded(cppData, bBreak);
}

bool dcapi::CPluginHelper::OnQueueMoved(QueueDataPtr cppData, bool& bBreak)
{
    try
    {
        if(cppData == NULL)
        {
            LogWarning("OnQueueMoved", "Parameter 'cppData' is null.");
        }

        auto data = CMarshalling::MarshalData(cppData);

        return m_pPlugin->OnQueueMoved(data, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnQueueMoved", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnQueueMoved", cppExp);
    }
    catch( ... )
    {
        LogException("OnQueueMoved");
    }

    return dcapi::CPluginBase::OnQueueMoved(cppData, bBreak);
}

bool dcapi::CPluginHelper::OnQueueRemoved(QueueDataPtr cppData, bool& bBreak)
{
    try
    {
        if(cppData == NULL)
        {
            LogWarning("OnQueueRemoved", "Parameter 'cppData' is null.");
        }

        auto data = CMarshalling::MarshalData(cppData);

        return m_pPlugin->OnQueueRemoved(data, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnQueueRemoved", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnQueueRemoved", cppExp);
    }
    catch( ... )
    {
        LogException("OnQueueRemoved");
    }

    return dcapi::CPluginBase::OnQueueRemoved(cppData, bBreak);
}

bool dcapi::CPluginHelper::OnQueueFinished(QueueDataPtr cppData, bool& bBreak)
{
    try
    {
        if(cppData == NULL)
        {
            LogWarning("OnQueueFinished", "Parameter 'cppData' is null.");
        }

        auto data = CMarshalling::MarshalData(cppData);

        return m_pPlugin->OnQueueFinished(data, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnQueueFinished", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnQueueFinished", cppExp);
    }
    catch( ... )
    {
        LogException("OnQueueFinished");
    }

    return dcapi::CPluginBase::OnQueueFinished(cppData, bBreak);
}

#pragma endregion

#pragma region UI

bool dcapi::CPluginHelper::OnUICreated(dcptr_t cppObject, bool& bBreak)
{
    try
    {
        if(cppObject == NULL)
        {
            LogWarning("OnUICreated", "Parameter 'cppObject' is null.");
        }

        System::IntPtr ptr(cppObject);

		return m_pPlugin->OnUICreated(ptr, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnUICreated", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnUICreated", cppExp);
    }
    catch( ... )
    {
        LogException("OnUICreated");
    }

    return dcapi::CPluginBase::OnUICreated(cppObject, bBreak);
}

bool dcapi::CPluginHelper::OnUIChatTags(UserDataPtr cppUserData, TagDataPtr cppTagData, bool& bBreak)
{
    try
    {
        // The cppUserData variable may be null and that's OK. Don't warn about it.
        //if(cppUserData == NULL)
        //{
        //    LogWarning("OnUIChatTags", "Parameter 'cppUserData' is null.");
        //}

        if(cppTagData == NULL)
        {
            LogWarning("OnUIChatTags", "Parameter 'cppTagData' is null.");
        }

        auto userData = CMarshalling::MarshalData(cppUserData);
        auto tagData = CMarshalling::MarshalData(cppTagData);

        return m_pPlugin->OnUIChatTags(userData, tagData, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnUIChatTags", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnUIChatTags", cppExp);
    }
    catch( ... )
    {
        LogException("OnUIChatTags");
    }

    return dcapi::CPluginBase::OnUIChatTags(cppUserData, cppTagData, bBreak);
}

bool dcapi::CPluginHelper::OnUIChatDisplay(UserDataPtr cppUserData, StringDataPtr cppStringData, bool& bBreak)
{
    try
    {
        // The cppUserData variable may be null and that's OK. Don't warn about it.
        //if(cppUserData == NULL)
        //{
        //    LogWarning("OnUIChatDisplay", "Parameter 'cppUserData' is null.");
        //}

        if(cppStringData == NULL)
        {
            LogWarning("OnUIChatDisplay", "Parameter 'cppStringData' is null.");
        }

        auto userData = CMarshalling::MarshalData(cppUserData);
        auto stringData = CMarshalling::MarshalData(cppStringData);

        return m_pPlugin->OnUIChatDisplay(userData, stringData, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnUIChatDisplay", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnUIChatDisplay", cppExp);
    }
    catch( ... )
    {
        LogException("OnUIChatDisplay");
    }

    return dcapi::CPluginBase::OnUIChatDisplay(cppUserData, cppStringData, bBreak);
}

bool dcapi::CPluginHelper::OnUIChatCommand(HubDataPtr cppHubData, CommandDataPtr cppCommandData, bool& bBreak)
{
    try
    {
        if(cppHubData == NULL)
        {
            LogWarning("OnUIChatCommand", "Parameter 'cppHubData' is null.");
        }

        if(cppCommandData == NULL)
        {
            LogWarning("OnUIChatCommand", "Parameter 'cppCommandData' is null.");
        }

        auto hubData = CMarshalling::MarshalData(cppHubData);
        auto commandData = CMarshalling::MarshalData(cppCommandData);

        return m_pPlugin->OnUIChatCommand(hubData, commandData, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnUIChatCommand", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnUIChatCommand", cppExp);
    }
    catch( ... )
    {
        LogException("OnUIChatCommand");
    }

    return dcapi::CPluginBase::OnUIChatCommand(cppHubData, cppCommandData, bBreak);
}

bool dcapi::CPluginHelper::OnUIChatCommandPM(UserDataPtr cppUserData, CommandDataPtr cppCommandData, bool& bBreak)
{
    try
    {
        if(cppUserData == NULL)
        {
            LogWarning("OnUIChatCommandPM", "Parameter 'cppUserData' is null.");
        }

        if(cppCommandData == NULL)
        {
            LogWarning("OnUIChatCommandPM", "Parameter 'cppCommandData' is null.");
        }

        auto userData = CMarshalling::MarshalData(cppUserData);
        auto commandData = CMarshalling::MarshalData(cppCommandData);

        return m_pPlugin->OnUIChatCommandPM(userData, commandData, bBreak);
    }
    catch(System::Exception^ exp)
    {
        LogException("OnUIChatCommandPM", exp);
    }
    catch(std::exception& cppExp)
    {
        LogException("OnUIChatCommandPM", cppExp);
    }
    catch( ... )
    {
        LogException("OnUIChatCommandPM");
    }

    return dcapi::CPluginBase::OnUIChatCommandPM(cppUserData, cppCommandData, bBreak);
}

#pragma endregion

#pragma endregion

void dcapi::CPluginHelper::LogException(System::String^ source, System::Exception^ exp)
{
	LogError("An exception occured: '" + source + "': " + exp->Message);
    LogError("Stacktrace: '" + source + "': " + exp->StackTrace);
}

void dcapi::CPluginHelper::LogException(System::String^ source, const std::exception& exp)
{
    LogError("An exception occured in '" + source + "': " + gcnew System::String(exp.what()));
}

void dcapi::CPluginHelper::LogException(System::String^ source)
{
    LogError("An unknown exception occured in '" + source + "' (no additional information)");
}

void dcapi::CPluginHelper::LogError(System::String^ source, System::String^ message)
{
    LogMessage("[ERROR] " + source + ": " + message);
}

void dcapi::CPluginHelper::LogError(System::String^ message)
{
    LogMessage("[ERROR] " + message);
}

void dcapi::CPluginHelper::LogWarning(System::String^ source, System::String^ message)
{
    LogMessage("[WARNING] " + source + ": " + message);
}

void dcapi::CPluginHelper::LogWarning(System::String^ message)
{
    LogMessage("[WARNING] " + message);
}

void dcapi::CPluginHelper::LogMessage(System::String^ message)
{
    std::string cppMessage;
    dcapi::CMarshalling::MarshalString("[" + gcnew System::String(m_pPluginInformation->_name.c_str()) + "] " + message, cppMessage);

    dcapi::Logger::log(cppMessage);
}