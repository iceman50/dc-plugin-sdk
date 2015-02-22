
#pragma once

#include "PluginBase.h"
#include "DCPluginSink.h"

#include "Python.h"

namespace dcapi {

class CPluginHelper : public CPluginBase
{
public:

    CPluginHelper(PyObject* pPlugin, CPluginSink* pSink);
    virtual ~CPluginHelper();

public:

    ///
    /// CPluginBase
    ///

    virtual bool Initialize(CPluginInformation* pPluginInformation, DCCorePtr core, bool install, bool runtime);
	virtual void Uninitialize();

    #pragma region Hooks

    #pragma region Chat
    virtual bool OnChatIncoming(HubDataPtr hubData, char* data, bool& bBreak);
    virtual bool OnChatOutgoing(HubDataPtr hubData, char* data, bool& bBreak);
    virtual bool OnChatIncomingPM(UserDataPtr userData, char* data, bool& bBreak);
    virtual bool OnChatOutgoingPM(UserDataPtr userData, char* data, bool& bBreak);
    #pragma endregion

    #pragma region Timer
    virtual bool OnTimerSecond(uint64_t data, bool& bBreak);
    virtual bool OnTimerMinute(uint64_t data, bool& bBreak);
    #pragma endregion

    #pragma region Hubs
    virtual bool OnHubsOnline(HubDataPtr data, bool& bBreak);
    virtual bool OnHubsOffline(HubDataPtr data, bool& bBreak);
    #pragma endregion

    #pragma region Users
    virtual bool OnUserOnline(UserDataPtr data, bool& bBreak);
    virtual bool OnUserOffline(UserDataPtr data, bool& bBreak);
    #pragma endregion

    #pragma region Network
    virtual bool OnNetworkHubDataIn(HubDataPtr hubData, char* data, bool& bBreak);
    virtual bool OnNetworkHubDataOut(HubDataPtr hubData, char* data, bool& bBreak);
    virtual bool OnNetworkClientDataIn(ConnectionDataPtr clientData, char* data, bool& bBreak);
    virtual bool OnNetworkClientDataOut(ConnectionDataPtr clientData, char* data, bool& bBreak);
    virtual bool OnNetworkUDPDataIn(UDPDataPtr udpData, char* data, bool& bBreak);
    virtual bool OnNetworkUDPDataOut(UDPDataPtr udpData, char* data, bool& bBreak);
    #pragma endregion

    #pragma region Queue
    virtual bool OnQueueAdded(QueueDataPtr data, bool& bBreak);
    virtual bool OnQueueMoved(QueueDataPtr data, bool& bBreak);
    virtual bool OnQueueRemoved(QueueDataPtr data, bool& bBreak);
    virtual bool OnQueueFinished(QueueDataPtr data, bool& bBreak);
    #pragma endregion

    #pragma region UI
    virtual bool OnUICreated(dcptr_t, bool& bBreak);
    virtual bool OnUIChatTags(UserDataPtr userData, TagDataPtr tagData, bool& bBreak);
    virtual bool OnUIChatDisplay(UserDataPtr userData, StringDataPtr stringData, bool& bBreak);
    virtual bool OnUIChatCommand(HubDataPtr hubData, CommandDataPtr commandData, bool& bBreak);
    virtual bool OnUIChatCommandPM(UserDataPtr, CommandDataPtr dommandData, bool& bBreak);
    #pragma endregion

    #pragma endregion


private:

	bool CheckReturnValue(PyObject* value, bool& bBreak);

private:

    /*void LogException(System::String^ source, System::Exception^ exp);
    void LogException(System::String^ source, const std::exception& exp);
    void LogException(System::String^ source);
    void LogError(System::String^ source, System::String^ message);
    void LogError(System::String^ message);
    void LogWarning(System::String^ source, System::String^ message);
    void LogWarning(System::String^ message);
	void LogMessage(System::String^ message);
*/
private:

    PyObject* m_pPlugin;
	CPluginSink* m_pSink;
};

}