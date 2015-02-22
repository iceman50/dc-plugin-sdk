
#pragma once

#include <dcapi\PluginDefs.h>

#include "DataTypes.h"

#include <string>

class CPluginSink
{
public:

	///
	/// Core
	///

	std::string GetApplicationName();

	void SetApplicationName( const std::string& pApplicationName );

	///
	/// Log
	///

	void LogMessage( const std::string& strMessage );

	///
	/// Config
	///

	std::string GetInstallPath();

	std::string GetPath( const PathType& ePathType );

	std::string GetStringConfig( const std::string& strName );
	void SetStringConfig( const std::string& strName, const std::string& strValue );

	bool GetBoolConfig( const std::string& strName);
	void SetBoolConfig( const std::string& strName, const bool& bValue );

	long GetInt32Config( const std::string& strName);
	void SetInt32Config( const std::string& strName, const long& nValue );

	long long GetInt64Config( const std::string& strName );
	void SetInt64Config( const std::string& strName, const long long& nValue );

	std::string GetLanguage();

	///
	/// Connection
	///

	void SendUDPData( const std::string& strIPAddress, const long& nPort, const std::string& strData, const long long& nAmount );

	void SendProtocolCommand( const ConnectionDataExt& connectionData, const std::string& strCommand);

	void TerminateConnection( const ConnectionDataExt& connectionData, const bool& bGraceless);

	UserDataExt GetConnectionUser( const ConnectionDataExt& connectionData );


	///
	/// Hub
	///

	HubDataExt AddHub( const std::string& strURL, const std::string& strNick, const std::string& strPassword );

	HubDataExt FindHub( const std::string& strURL );

	void RemoveHub( const HubDataExt& hubData );

	void EmulateProtocolCommand( const HubDataExt& hubData, const std::string& strCommand );

	void SendProtocolCommand( const HubDataExt& hubData, const std::string& strCommand );

	void SendMessage( const HubDataExt& hubData, const std::string& strMessage, const bool& bThirdPerson );

	void Localmessage( const HubDataExt& hubData, const std::string& strMessage, const MsgType& eMsgType );

	bool SendPrivateMessage( const UserDataExt& userDataExt, const std::string& strMessage, const bool& bThirdPerson );

	UserDataExt FindUser( const std::string& strCID, const std::string& strHubURL );

	///
	/// Queue
	///

	QueueDataExt AddList( const UserDataExt& userData, const bool& bSilent );

	QueueDataExt AddDownload( const std::string& strHash, const long long& nSize, const std::string& strTarget );

	QueueDataExt FindDownload( const std::string& strTarget );

	void RemoveDownload( const QueueDataExt& queueData );

	void SetPriority( const QueueDataExt& queueData, const QueuePrio& eQueuePriority );

	bool Pause( const QueueDataExt& queueData );

	///
	/// Tagger
	///

	std::string GetText( const TagDataExt& tagData );

	void AddTag( const TagDataExt& tagData, const long long& nStartPlace, const long long& nEndPlace, const std::string& strId, const std::string& strAttributes );

	void ReplaceText( const TagDataExt& tagData, const long long& nStartPlace, const long long& nEndPlace, const std::string& strReplacement );

	///
	/// UI
	///

	void AddCommand( const std::string& strName, const std::string& strIcon );

	void RemoveCommand( const std::string& strName );

	void ClearCommands();

	void PlaySoundInUI( const std::string& strPath );

	void Notify( const std::string& strTitle, const std::string& strMessage );

private:


};
