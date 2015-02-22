
#include "PluginHelper.h"

#include "Marshalling.h"

#include "dcapi\Logger.hpp"

#include <iostream>

dcapi::CPluginHelper::CPluginHelper(PyObject* pPlugin, CPluginSink* pSink) : 
	m_pPlugin( pPlugin ), 
	m_pSink(pSink) 
{
}

dcapi::CPluginHelper::~CPluginHelper()
{

}

bool dcapi::CPluginHelper::Initialize(CPluginInformation* pPluginInformation, DCCorePtr core, bool install, bool runtime)
{
	bool baseInitialize = dcapi::CPluginBase::Initialize(pPluginInformation, core, install, runtime);
	if(!baseInitialize)
	{
		return false;
	}

	PyObject* pyPluginInfo = CMarshalling::GetPluginInformation(*pPluginInformation);
	PyObject_CallMethod(m_pPlugin, "SetPluginInfo", "O", pyPluginInfo);

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "Initialize", "ii", (install ? 1 : 0), (runtime ? 1 : 0));
	
	bool bValue = CMarshalling::GetBoolValue(pMethodReturnValue);
	if(!bValue)
	{
		return false;
	}
	
	return true;
}

void dcapi::CPluginHelper::Uninitialize()
{
	dcapi::CPluginBase::Uninitialize();

	delete m_pSink;
	m_pSink = NULL;

	PyObject_Free(m_pPlugin);
	m_pPlugin = NULL;	
}

#pragma region Hooks

#pragma region Chat

bool dcapi::CPluginHelper::OnChatIncoming(HubDataPtr hubData, char* data, bool& bBreak)
{
	PyObject* pHubData = CMarshalling::GetHubData(CAPIMarshaling::GetHubData(hubData));

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnChatIncoming", "Os", pHubData, data);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnChatIncoming(hubData, data, bBreak);
}

bool dcapi::CPluginHelper::OnChatOutgoing(HubDataPtr hubData, char* data, bool& bBreak)
{
	PyObject* pHubData = CMarshalling::GetHubData(CAPIMarshaling::GetHubData(hubData));

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnChatOutgoing", "Os", pHubData, data);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnChatOutgoing(hubData, data, bBreak);
}

bool dcapi::CPluginHelper::OnChatIncomingPM(UserDataPtr userData, char* data, bool& bBreak)
{
	PyObject* pUserData = CMarshalling::GetUserData(CAPIMarshaling::GetUserData(userData));

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnChatIncomingPM", "Os", pUserData, data);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnChatIncomingPM(userData, data, bBreak);
}

bool dcapi::CPluginHelper::OnChatOutgoingPM(UserDataPtr userData, char* data, bool& bBreak)
{
	PyObject* pUserData = CMarshalling::GetUserData(CAPIMarshaling::GetUserData(userData));

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnChatOutgoingPM", "Os", pUserData, data);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnChatOutgoingPM(userData, data, bBreak);
}

#pragma endregion

#pragma region Timer

bool dcapi::CPluginHelper::OnTimerSecond(uint64_t data, bool& bBreak)
{
	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnTimerSecond", "L", data);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnTimerSecond(data, bBreak);
}

bool dcapi::CPluginHelper::OnTimerMinute(uint64_t data, bool& bBreak)
{
	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnTimerMinute", "L", data);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnTimerMinute(data, bBreak);
}

#pragma endregion

#pragma region Hubs

bool dcapi::CPluginHelper::OnHubsOnline(HubDataPtr hubData, bool& bBreak)
{
	PyObject* pHubData = CMarshalling::GetHubData(CAPIMarshaling::GetHubData(hubData));

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnHubOnline", "O", pHubData);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnHubsOnline(hubData, bBreak);
}

bool dcapi::CPluginHelper::OnHubsOffline(HubDataPtr hubData, bool& bBreak)
{
	PyObject* pHubData = CMarshalling::GetHubData(CAPIMarshaling::GetHubData(hubData));

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnHubOffline", "O", pHubData);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnHubsOffline(hubData, bBreak);
}

#pragma endregion

#pragma region Users

bool dcapi::CPluginHelper::OnUserOnline(UserDataPtr data, bool& bBreak)
{
	PyObject* pUserData = CMarshalling::GetUserData(CAPIMarshaling::GetUserData(data));

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnUserOnline", "O", pUserData);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnUserOnline(data, bBreak);
}

bool dcapi::CPluginHelper::OnUserOffline(UserDataPtr data, bool& bBreak)
{
	PyObject* pUserData = CMarshalling::GetUserData(CAPIMarshaling::GetUserData(data));

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnUserOffline", "O", pUserData);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnUserOffline(data, bBreak);
}

#pragma endregion

#pragma region Network

bool dcapi::CPluginHelper::OnNetworkHubDataIn(HubDataPtr hubData, char* data, bool& bBreak)
{
	PyObject* pHubData = CMarshalling::GetHubData(CAPIMarshaling::GetHubData(hubData));

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnNetworkHubDataIn", "Os", pHubData, data);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnNetworkHubDataIn(hubData, data, bBreak);
}

bool dcapi::CPluginHelper::OnNetworkHubDataOut(HubDataPtr hubData, char* data, bool& bBreak)
{
	PyObject* pHubData = CMarshalling::GetHubData(CAPIMarshaling::GetHubData(hubData));

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnNetworkHubDataOut", "Os", pHubData, data);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnNetworkHubDataOut(hubData, data, bBreak);
}

bool dcapi::CPluginHelper::OnNetworkClientDataIn(ConnectionDataPtr clientData, char* data, bool& bBreak)
{
	PyObject* pClientData = CMarshalling::GetConnectionData(CAPIMarshaling::GetConnectionData(clientData));

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnNetworkClientDataIn", "Os", pClientData, data);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnNetworkClientDataIn(clientData, data, bBreak);
}

bool dcapi::CPluginHelper::OnNetworkClientDataOut(ConnectionDataPtr clientData, char* data, bool& bBreak)
{
	PyObject* pClientData = CMarshalling::GetConnectionData(CAPIMarshaling::GetConnectionData(clientData));

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnNetworkClientDataOut", "Os", pClientData, data);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnNetworkClientDataOut(clientData, data, bBreak);
}

bool dcapi::CPluginHelper::OnNetworkUDPDataIn(UDPDataPtr udpData, char* data, bool& bBreak)
{
	PyObject* pUDPData = CMarshalling::GetUDPData(CAPIMarshaling::GetUDPData(udpData));

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnNetworkUDPDataIn", "Os", pUDPData, data);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnNetworkUDPDataIn(udpData, data, bBreak);
}

bool dcapi::CPluginHelper::OnNetworkUDPDataOut(UDPDataPtr udpData, char* data, bool& bBreak)
{
	PyObject* pUDPData = CMarshalling::GetUDPData(CAPIMarshaling::GetUDPData(udpData));

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnNetworkUDPDataOut", "Os", pUDPData, data);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnNetworkUDPDataOut(udpData, data, bBreak);
}

#pragma endregion

#pragma region Queue

bool dcapi::CPluginHelper::OnQueueAdded(QueueDataPtr data, bool& bBreak)
{
	PyObject* pQueueData = CMarshalling::GetQueueData(CAPIMarshaling::GetQueueData(data));

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnQueueAdded", "O", pQueueData);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnQueueAdded(data, bBreak);
}

bool dcapi::CPluginHelper::OnQueueMoved(QueueDataPtr data, bool& bBreak)
{
	PyObject* pQueueData = CMarshalling::GetQueueData(CAPIMarshaling::GetQueueData(data));

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnQueueMoved", "O", pQueueData);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnQueueMoved(data, bBreak);
}

bool dcapi::CPluginHelper::OnQueueRemoved(QueueDataPtr data, bool& bBreak)
{
	PyObject* pQueueData = CMarshalling::GetQueueData(CAPIMarshaling::GetQueueData(data));

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnQueueRemoved", "O", pQueueData);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnQueueRemoved(data, bBreak);
}

bool dcapi::CPluginHelper::OnQueueFinished(QueueDataPtr data, bool& bBreak)
{
	PyObject* pQueueData = CMarshalling::GetQueueData(CAPIMarshaling::GetQueueData(data));

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnQueueFinished", "O", pQueueData);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnQueueFinished(data, bBreak);
}

#pragma endregion

#pragma region UI

bool dcapi::CPluginHelper::OnUICreated(dcptr_t data, bool& bBreak)
{
	return dcapi::CPluginBase::OnUICreated(data, bBreak);
}

bool dcapi::CPluginHelper::OnUIChatTags(UserDataPtr userData, TagDataPtr tagData, bool& bBreak)
{
	PyObject* pUserData = CMarshalling::GetUserData(CAPIMarshaling::GetUserData(userData));
	PyObject* pTagData = CMarshalling::GetTagData(CAPIMarshaling::GetTagData(tagData));

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnUIChatTags", "OO", pUserData, pTagData);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnUIChatTags(userData, tagData, bBreak);
}

bool dcapi::CPluginHelper::OnUIChatDisplay(UserDataPtr userData, StringDataPtr stringData, bool& bBreak)
{
	/*PyObject* pUserData = CMarshalling::GetUserData(CAPIMarshaling::GetUserData(userData));
	PyObject* pStringData = CMarshalling::GetStringData(CAPIMarshaling::GetStringData(stringData));

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnUIChatDisplay", "OO", pUserData, pStringData);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}*/

	return dcapi::CPluginBase::OnUIChatDisplay(userData, stringData, bBreak);
}

bool dcapi::CPluginHelper::OnUIChatCommand(HubDataPtr hubData, CommandDataPtr commandData, bool& bBreak)
{
	PyObject* pHubData = CMarshalling::GetHubData(CAPIMarshaling::GetHubData(hubData));
	PyObject* pCommandData = CMarshalling::GetCommandData(CAPIMarshaling::GetCommandData(commandData));

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnUIChatCommand", "OO", pHubData, pCommandData);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnUIChatCommand(hubData, commandData, bBreak);
}

bool dcapi::CPluginHelper::OnUIChatCommandPM(UserDataPtr userData, CommandDataPtr commandData, bool& bBreak)
{
	PyObject* pUserData = CMarshalling::GetUserData(CAPIMarshaling::GetUserData(userData));
	PyObject* pCommandData = CMarshalling::GetCommandData(CAPIMarshaling::GetCommandData(commandData));

	PyObject* pMethodReturnValue = PyObject_CallMethod(m_pPlugin, "OnUIChatCommandPM", "OO", pUserData, pCommandData);
	if(!CheckReturnValue(pMethodReturnValue, bBreak))
	{
		return false;
	}

	return dcapi::CPluginBase::OnUIChatCommandPM(userData, commandData, bBreak);
}

#pragma endregion

#pragma endregion

bool dcapi::CPluginHelper::CheckReturnValue(PyObject* value, bool& bBreak)
{
	Py_ssize_t nTupleItems = PyTuple_Size(value);

	// First value is always whether the call succeeded
	if(nTupleItems >= 1)
	{
		PyObject* tupleItem = PyTuple_GetItem(value, 0);
		bool bValue = CMarshalling::GetBoolValue(value);
		if(!bValue)
		{
			return false;
		}

		// Second value is whether the plugin requests that no further chained calls shall be done
		if(nTupleItems >= 2)
		{
			tupleItem = PyTuple_GetItem(value, 1);
			bBreak = CMarshalling::GetBoolValue(value);
		}
	}

	return true;
}
