
#include "DCPluginSink.h"

#include <dcapi\PluginDefs.h>
#include <dcapi\Config.hpp>
#include <dcapi\Core.hpp>
#include <dcapi\Logger.hpp>
#include <dcapi\Queue.hpp>
#include <dcapi\UI.hpp>
#include <dcapi\Connections.hpp>
#include <dcapi\Tagger.hpp>
#include <dcapi\Hubs.hpp>

#include "Marshalling.h"

#include <iostream>

#pragma region Core

std::string CPluginSink::GetApplicationName()
{
	std::string strApplicationName = "";

	strApplicationName = dcapi::Core::appName;

	return strApplicationName;
}

void CPluginSink::SetApplicationName(const std::string& strApplicationName)
{
	dcapi::Core::appName = strApplicationName;
}

#pragma endregion

#pragma region Log

void CPluginSink::LogMessage(const std::string& strMessage)
{
	dcapi::Logger::log( strMessage );
}

#pragma endregion

#pragma region Config

std::string CPluginSink::GetInstallPath()
{
	std::string strInstallPath = "";

	strInstallPath = dcapi::Config::getInstallPath();

	return strInstallPath;
}

std::string CPluginSink::GetPath( const PathType& ePathType )
{
	std::string strPath = "";

	strPath = dcapi::Config::getPath( ePathType );

	return strPath;
}

std::string CPluginSink::GetStringConfig(const std::string& strName)
{
	std::string value = "";

	value = dcapi::Config::getConfig( strName.c_str() );

	return value;
}

void CPluginSink::SetStringConfig(const std::string& strName, const std::string& strValue)
{
	dcapi::Config::setConfig( strName.c_str(), strValue.c_str() );
}

bool CPluginSink::GetBoolConfig(const std::string& strName)
{
	bool value = false;

	value = dcapi::Config::getBoolConfig( strName.c_str() );

	return value;
}

void CPluginSink::SetBoolConfig(const std::string& strName, const bool& bValue)
{
	dcapi::Config::setConfig( strName.c_str(), bValue );
}

long CPluginSink::GetInt32Config(const std::string& strName)
{
	long value = 0;

	value = dcapi::Config::getIntConfig( strName.c_str() );

	return value;
}

void CPluginSink::SetInt32Config(const std::string& strName, const long& nValue)
{
	dcapi::Config::setConfig( strName.c_str(), nValue );
}

long long CPluginSink::GetInt64Config(const std::string& strName)
{
	long long value = 0;

	value = dcapi::Config::getInt64Config( strName.c_str() );

	return value;
}

void CPluginSink::SetInt64Config(const std::string& strName, const long long& nValue)
{
	dcapi::Config::setConfig( strName.c_str(), nValue );
}

std::string CPluginSink::GetLanguage()
{
	std::string strLanguage = "";

	ConfigStrPtr pLanguage = dcapi::Config::handle()->get_language();
	strLanguage = pLanguage->value;

	return strLanguage;
}

#pragma endregion

#pragma region Connection

void CPluginSink::SendUDPData( const std::string& strIPAddress, const long& nPort, const std::string& strData, const long long& nAmount )
{
	dcapi::Connections::handle()->send_udp_data( strIPAddress.c_str(), nPort, (dcptr_t)strData.c_str(), static_cast<size_t>(nAmount) );
}

void CPluginSink::SendProtocolCommand( const ConnectionDataExt& connectionDataExt, const std::string& strCommand)
{
	ConnectionData connectionData = CAPIMarshaling::GetConnectionData(connectionDataExt);
	
	dcapi::Connections::handle()->send_protocol_cmd( &connectionData, strCommand.c_str() );
}

void CPluginSink::TerminateConnection( const ConnectionDataExt& connectionDataExt, const bool& bGraceless)
{
	ConnectionData connectionData = CAPIMarshaling::GetConnectionData(connectionDataExt);
	
	dcapi::Connections::handle()->terminate_conn( &connectionData, (dcBool)bGraceless );
}

UserDataExt CPluginSink::GetConnectionUser( const ConnectionDataExt& connectionDataExt )
{
	ConnectionData connectionData = CAPIMarshaling::GetConnectionData(connectionDataExt);

	UserDataPtr userDataPtr = dcapi::Connections::handle()->get_user( &connectionData );

	UserDataExt userData = CAPIMarshaling::GetUserData(userDataPtr);

	dcapi::Hubs::handle()->release_user(userDataPtr);

	return userData;
}

#pragma endregion

#pragma region Hub

HubDataExt CPluginSink::AddHub( const std::string& strURL, const std::string& strNick, const std::string& strPassword )
{
	HubDataPtr pHub = dcapi::Hubs::handle()->add_hub( strURL.c_str(), strNick.c_str(), strPassword.c_str() );

	HubDataExt hubData = CAPIMarshaling::GetHubData(pHub);

	dcapi::Hubs::handle()->release(pHub);

	return hubData;
}

HubDataExt CPluginSink::FindHub( const std::string& strURL )
{
	HubDataPtr pHub = dcapi::Hubs::handle()->find_hub( strURL.c_str() );

	HubDataExt hubData = CAPIMarshaling::GetHubData(pHub);

	dcapi::Hubs::handle()->release(pHub);

	return hubData;
}

void CPluginSink::RemoveHub( const HubDataExt& hubDataExt )
{
	HubDataPtr pHub = dcapi::Hubs::handle()->find_hub(hubDataExt.url.c_str());

	dcapi::Hubs::handle()->remove_hub( pHub );

	dcapi::Hubs::handle()->release(pHub);
}

void CPluginSink::EmulateProtocolCommand( const HubDataExt& hubDataExt, const std::string& strCommand )
{
	HubDataPtr pHub = dcapi::Hubs::handle()->find_hub(hubDataExt.url.c_str());

	dcapi::Hubs::handle()->emulate_protocol_cmd( pHub, strCommand.c_str() );
	
	dcapi::Hubs::handle()->release(pHub);
}

void CPluginSink::SendProtocolCommand( const HubDataExt& hubDataExt, const std::string& strCommand )
{
	HubDataPtr pHub = dcapi::Hubs::handle()->find_hub(hubDataExt.url.c_str());

	dcapi::Hubs::handle()->send_protocol_cmd( pHub, strCommand.c_str() );

	dcapi::Hubs::handle()->release(pHub);
}

void CPluginSink::SendMessage( const HubDataExt& hubDataExt, const std::string& strMessage, const bool& bThirdPerson )
{
	HubDataPtr pHub = dcapi::Hubs::handle()->find_hub(hubDataExt.url.c_str());

	dcapi::Hubs::handle()->send_message( pHub, strMessage.c_str(), CAPIMarshaling::GetBool(bThirdPerson) );

	dcapi::Hubs::handle()->release(pHub);
}

void CPluginSink::Localmessage( const HubDataExt& hubDataExt, const std::string& strMessage, const MsgType& eMsgType )
{
	HubDataPtr pHub = dcapi::Hubs::handle()->find_hub(hubDataExt.url.c_str());

	dcapi::Hubs::handle()->local_message( pHub, strMessage.c_str(), eMsgType );

	dcapi::Hubs::handle()->release(pHub);
}

bool CPluginSink::SendPrivateMessage( const UserDataExt& userDataExt, const std::string& strMessage, const bool& bThirdPerson )
{
	UserDataPtr pUser = dcapi::Hubs::handle()->find_user(userDataExt.cid.c_str(), userDataExt.hubHint.c_str());

	dcBool bValue = dcapi::Hubs::handle()->send_private_message( pUser, strMessage.c_str(), CAPIMarshaling::GetBool(bThirdPerson) );

	dcapi::Hubs::handle()->release_user(pUser);

	return CAPIMarshaling::GetBool( bValue );
}

UserDataExt CPluginSink::FindUser( const std::string& strCID, const std::string& strHubURL )
{
	UserDataPtr userDataPtr = dcapi::Hubs::handle()->find_user( strCID.c_str(), strHubURL.c_str() );

	UserDataExt userData = CAPIMarshaling::GetUserData( userDataPtr );

	dcapi::Hubs::handle()->release_user(userDataPtr);

	return userData;
}

#pragma endregion

#pragma region Queue

QueueDataExt CPluginSink::AddList( const UserDataExt& userDataExt, const bool& bSilent )
{
	UserDataPtr pUser = dcapi::Hubs::handle()->find_user(userDataExt.cid.c_str(), userDataExt.hubHint.c_str());

	QueueDataPtr queueDataPtr = dcapi::Queue::handle()->add_list( pUser, CAPIMarshaling::GetBool(bSilent) );

	QueueDataExt queueDataExt = CAPIMarshaling::GetQueueData( queueDataPtr );

	dcapi::Hubs::handle()->release_user(pUser);

	dcapi::Queue::handle()->release( queueDataPtr );

	return queueDataExt;
}

QueueDataExt CPluginSink::AddDownload( const std::string& strHash, const long long& nSize, const std::string& strTarget )
{
	QueueDataPtr queueDataPtr = dcapi::Queue::handle()->add_download( strHash.c_str(), nSize, strTarget.c_str() );

	QueueDataExt queueDataExt = CAPIMarshaling::GetQueueData( queueDataPtr );

	dcapi::Queue::handle()->release( queueDataPtr );

	return queueDataExt;
}

QueueDataExt CPluginSink::FindDownload( const std::string& strTarget )
{
	QueueDataPtr queueDataPtr = dcapi::Queue::handle()->find_download( strTarget.c_str() );

	QueueDataExt queueDataExt = CAPIMarshaling::GetQueueData( queueDataPtr );

	dcapi::Queue::handle()->release( queueDataPtr );

	return queueDataExt;
}

void CPluginSink::RemoveDownload( const QueueDataExt& queueDataExt )
{
	QueueDataPtr pQueueData = dcapi::Queue::handle()->find_download(queueDataExt.target.c_str());

	dcapi::Queue::handle()->remove_download( pQueueData );

	dcapi::Queue::handle()->release( pQueueData );
}

void CPluginSink::SetPriority( const QueueDataExt& queueDataExt, const QueuePrio& eQueuePriority )
{
	QueueDataPtr pQueueData = dcapi::Queue::handle()->find_download(queueDataExt.target.c_str());

	dcapi::Queue::handle()->set_priority( pQueueData, eQueuePriority );

	dcapi::Queue::handle()->release(pQueueData);
}

bool CPluginSink::Pause( const QueueDataExt& queueDataExt )
{
	QueueDataPtr pQueueData = dcapi::Queue::handle()->find_download(queueDataExt.target.c_str());

	dcBool dcbPaused = dcapi::Queue::handle()->pause( pQueueData );

	dcapi::Queue::handle()->release(pQueueData);

	bool bPaused = CAPIMarshaling::GetBool( dcbPaused );

	return bPaused;
}

#pragma endregion

#pragma region Tagger

std::string CPluginSink::GetText( const TagDataExt& tagDataExt )
{
	TagData tagData = CAPIMarshaling::GetTagData( tagDataExt );

	const char* pText = dcapi::Tagger::handle()->get_text( &tagData );

	std::string strText = pText;

	// todo: Release pText?

	return strText;
}

void CPluginSink::AddTag( const TagDataExt& tagDataExt, const long long& nStartPlace, const long long& nEndPlace, const std::string& strId, const std::string& strAttributes )
{
	TagData tagData = CAPIMarshaling::GetTagData( tagDataExt );

	dcapi::Tagger::handle()->add_tag( &tagData, static_cast<size_t>(nStartPlace), static_cast<size_t>(nEndPlace), strId.c_str(), strAttributes.c_str() );
}

void CPluginSink::ReplaceText( const TagDataExt& tagDataExt, const long long& nStartPlace, const long long& nEndPlace, const std::string& strReplacement )
{
	TagData tagData = CAPIMarshaling::GetTagData( tagDataExt );

	dcapi::Tagger::handle()->replace_text( &tagData, static_cast<size_t>(nStartPlace), static_cast<size_t>(nEndPlace), strReplacement.c_str() );
}

#pragma endregion

#pragma region UI

void CPluginSink::AddCommand( const std::string& strName, const std::string& strIcon )
{
	// todo
}

void CPluginSink::RemoveCommand( const std::string& strName )
{
	dcapi::UI::removeCommand( strName.c_str() );
}

void CPluginSink::ClearCommands()
{
	dcapi::UI::clearCommands();
}

void CPluginSink::PlaySoundInUI( const std::string& strPath )
{
	dcapi::UI::handle()->play_sound( strPath.c_str() );
}

void CPluginSink::Notify( const std::string& strTitle, const std::string& strMessage )
{
	dcapi::UI::handle()->notify( strTitle.c_str(), strMessage.c_str() );
}

#pragma endregion
