
#include "PythonCallbacks.h"

#include "DCPluginSink.h"
#include "Marshalling.h"

#include "Python.h"

#include <dcapi\Logger.hpp>

#include <iostream>

#pragma region Core

PyObject* CPythonCallbacks::GetApplicationNameCallbackFunc(PyObject* self, PyObject* args)
{
	int nCppSink = 0;

	if(!PyArg_ParseTuple(args, "i", &nCppSink))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	std::string strApplicationName = pSink->GetApplicationName();

	PyObject* returnValue = CMarshalling::GetStringValue(strApplicationName);
	return returnValue;
}

PyObject* CPythonCallbacks::SetApplicationNameCallbackFunc(PyObject* self, PyObject* args)
{
	int nCppSink = 0;

	char* cppApplicationName;

	if(!PyArg_ParseTuple(args, "is", &nCppSink, &cppApplicationName))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	pSink->SetApplicationName(cppApplicationName);

	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

#pragma endregion

#pragma region Log

PyObject* CPythonCallbacks::LogMessageCallbackFunc(PyObject *self, PyObject *args)
{
	int pointerValue = 0;

    char *strMessage;

    if (!PyArg_ParseTuple(args, "is", &pointerValue, &strMessage))
        return NULL;

	CPythonPluginSink* myPointer = (CPythonPluginSink*)pointerValue;
	myPointer->LogMessage(strMessage);

    PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

#pragma endregion

#pragma region Config

PyObject* CPythonCallbacks::GetInstallPathCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	if(!PyArg_ParseTuple(args, "i", &nCppSink))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	std::string strInstallPath = pSink->GetInstallPath();

	PyObject* returnValue = CMarshalling::GetStringValue(strInstallPath);
	return returnValue;
}

PyObject* CPythonCallbacks::GetPathCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	long nPathType;

	if(!PyArg_ParseTuple(args, "ii", &nCppSink, &nPathType))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	std::string strPath = pSink->GetPath((PathType)nPathType);

	PyObject* returnValue = CMarshalling::GetStringValue(strPath);
	return returnValue;
}

PyObject* CPythonCallbacks::GetStringConfigCallbackFunc(PyObject *self, PyObject *args)	
{
	int nCppSink = 0;

	const char* pName;

	if(!PyArg_ParseTuple(args, "is", &nCppSink, &pName))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	std::string strValue = pSink->GetStringConfig(pName);

	PyObject* returnValue = CMarshalling::GetStringValue(strValue);
	return returnValue;
}

PyObject* CPythonCallbacks::SetStringConfigCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	const char* pName;
	const char* pValue;

	if(!PyArg_ParseTuple(args, "iss", &nCppSink, &pName, &pValue))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	pSink->SetStringConfig(pName, pValue);

	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

PyObject* CPythonCallbacks::GetBoolConfigCallbackFunc(PyObject *self, PyObject *args)	
{
	int nCppSink = 0;

	const char* pName;

	if(!PyArg_ParseTuple(args, "is", &nCppSink, &pName))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	bool bValue = pSink->GetBoolConfig(pName);

	PyObject* returnValue = CMarshalling::GetBoolValue(bValue);
	return returnValue;
}

PyObject* CPythonCallbacks::SetBoolConfigCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	const char* pName;
	bool bValue;

	if(!PyArg_ParseTuple(args, "isi", &nCppSink, &pName, &bValue))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	pSink->SetBoolConfig(pName, bValue);

	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

PyObject* CPythonCallbacks::GetInt32ConfigCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	const char* pName;

	if(!PyArg_ParseTuple(args, "is", &nCppSink, &pName))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	long lValue = pSink->GetInt32Config(pName);

	PyObject* returnValue = CMarshalling::GetInt32Value(lValue);
	return returnValue;
}

PyObject* CPythonCallbacks::SetInt32ConfigCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	const char* pName;
	long nValue;

	if(!PyArg_ParseTuple(args, "isi", &nCppSink, &pName, &nValue))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	pSink->SetInt32Config(pName, nValue);

	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

PyObject* CPythonCallbacks::GetInt64ConfigCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	const char* pName;

	if(!PyArg_ParseTuple(args, "is", &nCppSink, &pName))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	long long lValue = pSink->GetInt64Config(pName);

	PyObject* returnValue = CMarshalling::GetInt64Value(lValue);
	return returnValue;
}

PyObject* CPythonCallbacks::SetInt64ConfigCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	const char* pName;
	long long nValue;

	if(!PyArg_ParseTuple(args, "isL", &nCppSink, &pName, &nValue))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	pSink->SetInt64Config(pName, nValue);

	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

PyObject* CPythonCallbacks::GetLanguageCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	if(!PyArg_ParseTuple(args, "is", &nCppSink))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	std::string strLangauge = pSink->GetLanguage();

	PyObject* returnValue = CMarshalling::GetStringValue(strLangauge);
	return returnValue;
}

#pragma endregion

#pragma region Connection

PyObject* CPythonCallbacks::SendUDPDataCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	const char* pIpAddress;
	long nPort;
	const char* pData;
	long long nAmount;

	if(!PyArg_ParseTuple(args, "islsL", &nCppSink, &pIpAddress, &nPort, &pData, &nAmount))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	pSink->SendUDPData( pIpAddress, nPort, pData, nAmount );

	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

PyObject* CPythonCallbacks::SendProtocolCommandConnectionCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	PyObject* pConnectionData;
	const char* pCommand;

	if(!PyArg_ParseTuple(args, "iOs", &nCppSink, &pConnectionData, &pCommand))
		return NULL;

	ConnectionDataExt connectionData = CMarshalling::GetConnectionData(pConnectionData);

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	pSink->SendProtocolCommand( connectionData, pCommand );

	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

PyObject* CPythonCallbacks::TerminateConnectionCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	PyObject* pConnectionData;
	bool bGraceless;

	if(!PyArg_ParseTuple(args, "iOi", &nCppSink, &pConnectionData, &bGraceless))
		return NULL;

	ConnectionDataExt connectionData = CMarshalling::GetConnectionData(pConnectionData);

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	pSink->TerminateConnection( connectionData, bGraceless );

	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

PyObject* CPythonCallbacks::GetConnectionUserCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	PyObject* pConnectionData;

	if(!PyArg_ParseTuple(args, "iO", &nCppSink, &pConnectionData))
		return NULL;

	ConnectionDataExt connectionData = CMarshalling::GetConnectionData(pConnectionData);

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	UserDataExt userData = pSink->GetConnectionUser( connectionData );

	PyObject* returnValue = CMarshalling::GetUserData(userData);
	return returnValue;
}

#pragma endregion

#pragma region Hub

PyObject* CPythonCallbacks::AddHubCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	const char* pURL;
	const char* pNick;
	const char* pPassword;

	if(!PyArg_ParseTuple(args, "isss", &nCppSink, &pURL, &pNick, &pPassword))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	HubDataExt hubData = pSink->AddHub( pURL, pNick, pPassword );

	PyObject* returnValue = CMarshalling::GetHubData(hubData);
	return returnValue;
}
PyObject* CPythonCallbacks::FindHubCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	const char* pURL;

	if(!PyArg_ParseTuple(args, "isss", &nCppSink, &pURL))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	HubDataExt hubData = pSink->FindHub( pURL );

	PyObject* returnValue = CMarshalling::GetHubData(hubData);
	return returnValue;
}

PyObject* CPythonCallbacks::RemoveHubCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	PyObject* pHubData;

	if(!PyArg_ParseTuple(args, "iO", &nCppSink, &pHubData))
		return NULL;

	HubDataExt hubData = CMarshalling::GetHubData(pHubData);

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	pSink->RemoveHub( hubData );

	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

PyObject* CPythonCallbacks::EmulateProtocolCommandCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	PyObject* pHubData;
	const char* pCommand;

	if(!PyArg_ParseTuple(args, "iOs", &nCppSink, &pHubData, &pCommand))
		return NULL;

	HubDataExt hubData = CMarshalling::GetHubData(pHubData);

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	pSink->EmulateProtocolCommand( hubData, pCommand );

	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

PyObject* CPythonCallbacks::SendProtocolCommandHubCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	PyObject* pHubData;
	const char* pCommand;

	if(!PyArg_ParseTuple(args, "iOs", &nCppSink, &pHubData, &pCommand))
		return NULL;

	HubDataExt hubData = CMarshalling::GetHubData(pHubData);

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	pSink->SendProtocolCommand( hubData, pCommand );

	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

PyObject* CPythonCallbacks::SendMessageCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	PyObject* pHubData;
	const char* pMessage;
	bool bThirdPerson;

	if(!PyArg_ParseTuple(args, "iOsi", &nCppSink, &pHubData, &pMessage, &bThirdPerson))
		return NULL;

	HubDataExt hubData = CMarshalling::GetHubData(pHubData);

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	pSink->SendMessage( hubData, pMessage, bThirdPerson );

	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

PyObject* CPythonCallbacks::LocalMessageCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	PyObject* pHubData;
	const char* pMessage;
	int nMessageType;

	if(!PyArg_ParseTuple(args, "iOsi", &nCppSink, &pHubData, &pMessage, &nMessageType))
		return NULL;

	HubDataExt hubData = CMarshalling::GetHubData(pHubData);

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	pSink->Localmessage( hubData, pMessage, (MsgType)nMessageType );

	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

PyObject* CPythonCallbacks::SendPrivateMessageCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	PyObject* pUserData;
	const char* pMessage;
	bool bThirdPerson;

	if(!PyArg_ParseTuple(args, "iOsi", &nCppSink, &pUserData, &pMessage, &bThirdPerson))
		return NULL;

	UserDataExt userData = CMarshalling::GetUserData(pUserData);

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	pSink->SendPrivateMessage( userData, pMessage, bThirdPerson );

	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

PyObject* CPythonCallbacks::FindUserCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	const char* pCid;
	const char* pHubUrl;

	if(!PyArg_ParseTuple(args, "iss", &nCppSink, &pCid, &pHubUrl))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	UserDataExt userData = pSink->FindUser( pCid, pHubUrl );

	PyObject* returnValue = CMarshalling::GetUserData(userData);
	return returnValue;
}

#pragma endregion

#pragma region Queue

PyObject* CPythonCallbacks::AddListCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	PyObject* pUserData;
	bool bSilent;

	if(!PyArg_ParseTuple(args, "iOi", &nCppSink, &pUserData, &bSilent))
		return NULL;

	UserDataExt userData = CMarshalling::GetUserData(pUserData);

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	QueueDataExt queueData = pSink->AddList( userData, bSilent );

	PyObject* returnValue = CMarshalling::GetQueueData(queueData);
	return returnValue;
}

PyObject* CPythonCallbacks::AddDownloadCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	const char* pHash;
	long long nSize;
	const char* pTarget;

	if(!PyArg_ParseTuple(args, "isLs", &nCppSink, &pHash, &nSize, &pTarget))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	QueueDataExt queueData = pSink->AddDownload( pHash, nSize, pTarget );

	PyObject* returnValue = CMarshalling::GetQueueData(queueData);
	return returnValue;
}

PyObject* CPythonCallbacks::FindDownloadCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	const char* pTarget;

	if(!PyArg_ParseTuple(args, "is", &nCppSink, &pTarget))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	QueueDataExt queueData = pSink->FindDownload( pTarget );

	PyObject* returnValue = CMarshalling::GetQueueData(queueData);
	return returnValue;
}

PyObject* CPythonCallbacks::RemoveDownloadCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	PyObject* pQueueData;

	if(!PyArg_ParseTuple(args, "iO", &nCppSink, &pQueueData))
		return NULL;

	QueueDataExt queueData = CMarshalling::GetQueueData( pQueueData );

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	pSink->RemoveDownload( queueData );

	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

PyObject* CPythonCallbacks::SetPriorityCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	PyObject* pQueueData;
	long nQueuePriority;

	if(!PyArg_ParseTuple(args, "iOi", &nCppSink, &pQueueData, &nQueuePriority))
		return NULL;

	QueueDataExt queueData = CMarshalling::GetQueueData( pQueueData );

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	pSink->SetPriority( queueData, (QueuePrio)nQueuePriority );

	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

PyObject* CPythonCallbacks::PauseCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	PyObject* pQueueData;

	if(!PyArg_ParseTuple(args, "iO", &nCppSink, &pQueueData))
		return NULL;

	QueueDataExt queueData = CMarshalling::GetQueueData( pQueueData );

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	bool bPaused = pSink->Pause( queueData );

	PyObject* returnValue = CMarshalling::GetBoolValue(bPaused);
	return returnValue;
}


#pragma endregion

#pragma region Tagger

PyObject* CPythonCallbacks::GetTextCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	PyObject* pTagData;

	if(!PyArg_ParseTuple(args, "iO", &nCppSink, &pTagData))
		return NULL;

	TagDataExt tagData = CMarshalling::GetTagData( pTagData );

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	std::string strText = pSink->GetText( tagData );

	PyObject* returnValue = CMarshalling::GetStringValue(strText);
	return returnValue;
}

PyObject* CPythonCallbacks::AddTagCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	PyObject* pTagData;
	long long nStartPlace;
	long long nEndPlace;
	const char* pId;
	const char* pAttributes;

	if(!PyArg_ParseTuple(args, "iOLLss", &nCppSink, &pTagData, &nStartPlace, &nEndPlace, &pId, &pAttributes))
		return NULL;

	TagDataExt tagData = CMarshalling::GetTagData( pTagData );

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	pSink->AddTag( tagData, nStartPlace, nEndPlace, pId, pAttributes );

	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

PyObject* CPythonCallbacks::ReplaceTagTextCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	PyObject* pTagData;
	long long nStartPlace;
	long long nEndPlace;
	const char* pReplacement;

	if(!PyArg_ParseTuple(args, "iOLLs", &nCppSink, &pTagData, &nStartPlace, &nEndPlace, &pReplacement))
		return NULL;

	TagDataExt tagData = CMarshalling::GetTagData( pTagData );

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	pSink->ReplaceText( tagData, nStartPlace, nEndPlace, pReplacement );

	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}


#pragma endregion

#pragma region UI

PyObject* CPythonCallbacks::AddCommandCallbackFunc(PyObject *self, PyObject *args)
{
	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

PyObject* CPythonCallbacks::RemoveCommandCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	const char* pName;

	if(!PyArg_ParseTuple(args, "is", &nCppSink, &pName))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	pSink->RemoveCommand( pName );

	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

PyObject* CPythonCallbacks::ClearCommandsCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	if(!PyArg_ParseTuple(args, "i", &nCppSink))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	pSink->ClearCommands();

	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

PyObject* CPythonCallbacks::PlaySoundInUICallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	const char* pPath;

	if(!PyArg_ParseTuple(args, "is", &nCppSink, &pPath))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	pSink->PlaySoundInUI( pPath );

	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

PyObject* CPythonCallbacks::NotifyCallbackFunc(PyObject *self, PyObject *args)
{
	int nCppSink = 0;

	const char* pTitle;
	const char* pMessage;

	if(!PyArg_ParseTuple(args, "iss", &nCppSink, &pTitle, &pMessage))
		return NULL;

	CPythonPluginSink* pSink = (CPythonPluginSink*)nCppSink;
	pSink->Notify( pTitle, pMessage );

	PyObject* returnValue = CMarshalling::GetNoneValue();
	return returnValue;
}

#pragma endregion