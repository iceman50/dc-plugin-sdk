
#include "stdafx.h"

#include "PluginBase.h"

#include <dcapi/Config.hpp>
#include <dcapi/Connections.hpp>
#include <dcapi/Core.hpp>
#include <dcapi/Hooks.hpp>
#include <dcapi/Hubs.hpp>
#include <dcapi/Logger.hpp>
#include <dcapi/Queue.hpp>
#include <dcapi/Tagger.hpp>
#include <dcapi/UI.hpp>
#include <dcapi/Util.hpp>

bool dcapi::CPluginBase::Initialize(dcapi::CPluginInformation* pPluginInformation, DCCorePtr core, bool, bool)
{
    m_pPluginInformation = pPluginInformation;

	// Core is always initialized first...
	dcapi::Core::init(core);
	
	if(!InitializeHooks())
	{
		return false;
	}

    if(!SetupHooks())
    {
        return false;
    }

    // Add additional initialization here if need be.

    return true;
}

void dcapi::CPluginBase::Uninitialize()
{
    Hooks::clear();
}

bool dcapi::CPluginBase::InitializeHooks()
{
	if(!dcapi::Logger::init())
	{
		// Can't do anything here, really...

		return false;
	}

	if(!dcapi::Config::init(PLUGIN_GUID))
	{
		dcapi::Logger::log("Config initialization failed.");

		return false;
	}

	if(!dcapi::Connections::init())
	{
		dcapi::Logger::log("Connections initialization failed.");

		return false;
	}

	if(!dcapi::Hooks::init())
	{
		dcapi::Logger::log("Hooks initialization failed.");

		return false;
	}

	if(!dcapi::Hubs::init())
	{
		dcapi::Logger::log("Hubs initialization failed.");

		return false;
	}

	if(!dcapi::Queue::init())
	{
		dcapi::Logger::log("Queue initialization failed.");

		return false;
	}

	if(!dcapi::Tagger::init())
	{
		dcapi::Logger::log("Tagger initialization failed.");

		return false;
	}

	if(!dcapi::UI::init(PLUGIN_GUID))
	{
		dcapi::Logger::log("UI initialization failed.");

		return false;
	}

	if(!dcapi::Util::init()) 
	{
		dcapi::Logger::log("Util initialization failed.");

		return false;
	}

	return true;
}

bool dcapi::CPluginBase::SetupHooks() 
{ 
    // Chat
    Hooks::Chat::onIncomingChat([this](HubDataPtr hHub, char* message, bool& bBreak) { return OnChatIncoming(hHub, message, bBreak); });
    Hooks::Chat::onOutgoingChat([this](HubDataPtr hHub, char* message, bool& bBreak) { return OnChatOutgoing(hHub, message, bBreak); });
    Hooks::Chat::onIncomingPM([this](UserDataPtr hUser, char* message, bool& bBreak) { return OnChatIncomingPM(hUser, message, bBreak); });
    Hooks::Chat::onOutgoingPM([this](UserDataPtr hUser, char* message, bool& bBreak) { return OnChatOutgoingPM(hUser, message, bBreak); });

    // Timer
    Hooks::Timer::onSecond([this](uint64_t data, bool& bBreak) { return OnTimerSecond(data, bBreak); });
    Hooks::Timer::onMinute([this](uint64_t data, bool& bBreak) { return OnTimerMinute(data, bBreak); });

    // Hubs
    Hooks::Hubs::onOnline([this](HubDataPtr hHub, bool& bBreak) { return OnHubsOnline(hHub, bBreak); });
    Hooks::Hubs::onOffline([this](HubDataPtr hHub, bool& bBreak) { return OnHubsOffline(hHub, bBreak); });
    
    // Users
    Hooks::Users::onOnline([this](UserDataPtr hUser, bool& bBreak) { return OnUserOnline(hUser, bBreak); });
    Hooks::Users::onOffline([this](UserDataPtr hUser, bool& bBreak) { return OnUserOffline(hUser, bBreak); });

    // Network
    Hooks::Network::onHubDataIn([this](HubDataPtr hHub, char* message, bool& bBreak) { return OnNetworkHubDataIn(hHub, message, bBreak); });
    Hooks::Network::onHubDataOut([this](HubDataPtr hHub, char* message, bool& bBreak) { return OnNetworkHubDataOut(hHub, message, bBreak); });
    Hooks::Network::onClientDataIn([this](ConnectionDataPtr hConnection, char* message, bool& bBreak) { return OnNetworkClientDataIn(hConnection, message, bBreak); });
    Hooks::Network::onClientDataOut([this](ConnectionDataPtr hConnection, char* message, bool& bBreak) { return OnNetworkClientDataOut(hConnection, message, bBreak); });
    Hooks::Network::onUDPDataIn([this](UDPDataPtr hUDP, char* message, bool& bBreak) { return OnNetworkUDPDataIn(hUDP, message, bBreak); });
    Hooks::Network::onUDPDataOut([this](UDPDataPtr hUDP, char* message, bool& bBreak) { return OnNetworkUDPDataOut(hUDP, message, bBreak); });

    // Queue
    Hooks::Queue::onAdded([this](QueueDataPtr data, bool& bBreak) { return OnQueueAdded(data, bBreak); });
    Hooks::Queue::onMoved([this](QueueDataPtr data, bool& bBreak) { return OnQueueMoved(data, bBreak); });
    Hooks::Queue::onRemoved([this](QueueDataPtr data, bool& bBreak) { return OnQueueRemoved(data, bBreak); });
    Hooks::Queue::onFinished([this](QueueDataPtr data, bool& bBreak) { return OnQueueFinished(data, bBreak); });

    // UI
    Hooks::UI::onCreated([this](dcptr_t hPtr, bool& bBreak) { return OnUICreated(hPtr, bBreak); });
    Hooks::UI::onChatTags([this](UserDataPtr hUser, TagDataPtr hTag, bool& bBreak) { return OnUIChatTags(hUser, hTag, bBreak); });
    Hooks::UI::onChatDisplay([this](UserDataPtr hUser, StringDataPtr hString, bool& bBreak) { return OnUIChatDisplay(hUser, hString, bBreak); });
    Hooks::UI::onChatCommand([this](HubDataPtr hHub, CommandDataPtr hCommand, bool& bBreak) { return OnUIChatCommand(hHub, hCommand, bBreak); });
    Hooks::UI::onChatCommandPM([this](UserDataPtr hUser, CommandDataPtr hCommand, bool& bBreak) { return OnUIChatCommandPM(hUser, hCommand, bBreak); });

    return true;
}

#pragma region Hooks

#pragma region Chat

bool dcapi::CPluginBase::OnChatIncoming(HubDataPtr, char*, bool&)
{
    return false;
}

bool dcapi::CPluginBase::OnChatOutgoing(HubDataPtr, char*, bool&)
{
    return false;
}

bool dcapi::CPluginBase::OnChatIncomingPM(UserDataPtr, char*, bool&)
{
    return false;
}

bool dcapi::CPluginBase::OnChatOutgoingPM(UserDataPtr, char*, bool&)
{
    return false;
}

#pragma endregion

#pragma region Timer

bool dcapi::CPluginBase::OnTimerSecond(uint64_t, bool&)
{
    return false;
}

bool dcapi::CPluginBase::OnTimerMinute(uint64_t, bool&)
{
    return false;
}

#pragma endregion

#pragma region Hubs

bool dcapi::CPluginBase::OnHubsOnline(HubDataPtr, bool&)
{
    return false;
}

bool dcapi::CPluginBase::OnHubsOffline(HubDataPtr, bool&)
{
    return false;
}

#pragma endregion

#pragma region Users

bool dcapi::CPluginBase::OnUserOnline(UserDataPtr, bool&)
{
    return false;
}

bool dcapi::CPluginBase::OnUserOffline(UserDataPtr, bool&)
{
    return false;
}

#pragma endregion

#pragma region Network

bool dcapi::CPluginBase::OnNetworkHubDataIn(HubDataPtr, char*, bool&)
{
    return false;
}

bool dcapi::CPluginBase::OnNetworkHubDataOut(HubDataPtr, char*, bool&)
{
    return false;
}

bool dcapi::CPluginBase::OnNetworkClientDataIn(ConnectionDataPtr, char*, bool&)
{
    return false;
}

bool dcapi::CPluginBase::OnNetworkClientDataOut(ConnectionDataPtr, char*, bool&)
{
    return false;
}

bool dcapi::CPluginBase::OnNetworkUDPDataIn(UDPDataPtr, char*, bool&)
{
    return false;
}

bool dcapi::CPluginBase::OnNetworkUDPDataOut(UDPDataPtr, char*, bool&)
{
    return false;
}

#pragma endregion

#pragma region Queue
bool dcapi::CPluginBase::OnQueueAdded(QueueDataPtr, bool&)
{
    return false;
}

bool dcapi::CPluginBase::OnQueueMoved(QueueDataPtr, bool&)
{
    return false;
}

bool dcapi::CPluginBase::OnQueueRemoved(QueueDataPtr, bool&)
{
    return false;
}

bool dcapi::CPluginBase::OnQueueFinished(QueueDataPtr, bool&)
{
    return false;
}

#pragma endregion

#pragma region UI

bool dcapi::CPluginBase::OnUICreated(dcptr_t, bool&)
{
    return false;
}

bool dcapi::CPluginBase::OnUIChatTags(UserDataPtr, TagDataPtr, bool&)
{
    return false;
}

bool dcapi::CPluginBase::OnUIChatDisplay(UserDataPtr, StringDataPtr, bool&)
{
    return false;
}

bool dcapi::CPluginBase::OnUIChatCommand(HubDataPtr, CommandDataPtr, bool&)
{
    return false;
}

bool dcapi::CPluginBase::OnUIChatCommandPM(UserDataPtr, CommandDataPtr, bool&)
{
    return false;
}

#pragma endregion

#pragma endregion
