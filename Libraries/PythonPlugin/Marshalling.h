
#pragma once

#include "DataTypes.h"
#include "PluginInformation.h"

#include "Python.h"

#include <string>

class CAPIMarshaling
{

public:

	//
	// dcapi type conversion
	//
	
	static HubDataExt GetHubData(HubData* hubData);
	static HubData GetHubData(const HubDataExt& hubData);

	static UserDataExt GetUserData(UserData* userData);
	static UserData GetUserData(const UserDataExt& userData);

	static ConnectionDataExt GetConnectionData(ConnectionData* connectionData);
	static ConnectionData GetConnectionData(const ConnectionDataExt& connectionData);

	static CommandDataExt GetCommandData(CommandData* commandData);
	static CommandData GetCommandData(const CommandDataExt& commandData);

	static UDPDataExt GetUDPData(UDPData* udpData);
	static UDPData GetUDPData(const UDPDataExt& udpData);

	static QueueDataExt GetQueueData(QueueData* queueData);
	static QueueData GetQueueData(const QueueDataExt& queueData);

	static TagDataExt GetTagData(TagData* tagData);
	static TagData GetTagData(const TagDataExt& tagData);

	//static StringDataExt GetStringData(const StringData& stringData);
	//static StringData GetStringData(const StringDataExt& stringData);

	static bool GetBool(const dcBool& b);
	static dcBool GetBool(const bool& b);

};

class CMarshalling
{
public:

	//
	// Python (basic) type conversion
	//

	static double GetDoubleValue(PyObject* pObj);
	static PyObject* GetDoubleValue(const double& dValue);

	static PyObject* GetNoneValue();

	static std::string GetStringValue(PyObject* pObj);
	static PyObject* GetStringValue(const std::string& strValue);

	static PyObject* GetBoolValue(const bool& bValue);
	static bool GetBoolValue(PyObject* pObj);
	static short GetInt16Value(PyObject* pObj);

	static long GetInt32Value(PyObject* pObj);
	static PyObject* GetInt32Value(const long& nValue);

	static long long GetInt64Value(PyObject* pObj);
	static PyObject* GetInt64Value(const long long& nValue);

	//
	// Python (complex) type conversion
	//

	static PyObject* GetHubData(const HubDataExt& hubData);
	static HubDataExt GetHubData(PyObject* pHubData);

	static PyObject* GetUserData(const UserDataExt& userData);
	static UserDataExt GetUserData(PyObject* pUserData);

	static PyObject* GetQueueData(const QueueDataExt& queueData);
	static QueueDataExt GetQueueData(PyObject* pQueueData);

	static PyObject* GetTagData(const TagDataExt& tagData);
	static TagDataExt GetTagData(PyObject* pTagData);

	static PyObject* GetConnectionData(const ConnectionDataExt& connectionData);
	static ConnectionDataExt GetConnectionData(PyObject* pConnectionData);

	static PyObject* GetUDPData(const UDPDataExt& udpData);
	static UDPDataExt GetUDPData(PyObject* pUDPData);

	static PyObject* GetCommandData(const CommandDataExt& commandData);
	static CommandDataExt GetCommandData(PyObject* pCommandData);

	static PyObject* GetPluginSetting(const dcapi::CPluginSettingContainer& pluginSetting);
	static dcapi::CPluginSettingContainer GetPluginSetting(PyObject* pPluginSetting);

	static PyObject* GetPluginInformation(const dcapi::CPluginInformation& pluginInformation);
	static dcapi::CPluginInformation GetPluginInformation(PyObject* pPluginInformation);

	
	// 
	// Python helpers
	//

	static PyObject* GetAttribute(PyObject* pObject, const std::string& strAttribute);
	static std::string GetStringAttribute(PyObject* pObject, const std::string& strAttribute);
	static bool GetBoolAttribute(PyObject* pObject, const std::string& strAttribute);
	static short GetInt16Attribute(PyObject* pObject, const std::string& strAttribute);
	static long GetInt32Attribute(PyObject* pObject, const std::string& strAttribute);
	static long long GetInt64Attribute(PyObject* pObject, const std::string& strAttribute);
	static double GetDoubleAttribute(PyObject* pObject, const std::string& strAttribute);

};
