
#include "Marshalling.h"
#include "PythonManagement.h"

#include "Python.h"

#include <iostream>

const std::string DATATYPES_BINARY = "dcplugin.DataTypes";

PyObject* CMarshalling::GetStringValue(const std::string& strValue)
{
#if PY_MAJOR_VERSION >= 3
	return PyUnicode_FromString(strValue.c_str());
#else
	return PyString_FromString(strValue.c_str());
#endif
}

std::string CMarshalling::GetStringValue(PyObject* pObj)
{
#if PY_MAJOR_VERSION >= 3
	return PyUnicode_AsUTF8(pObj);
#else
	return PyString_AsString(pObj);
#endif
}

short CMarshalling::GetInt16Value(PyObject* pObj)
{
	return static_cast<short>(PyLong_AsLong(pObj));
}

PyObject* CMarshalling::GetInt32Value(const long& nValue)
{
#if PY_MAJOR_VERSION >= 3
	return PyLong_FromLong(nValue);
#else
	return PyInt_FromLong(nValue);
#endif
}

long CMarshalling::GetInt32Value(PyObject* pObj)
{
	return PyLong_AsLong(pObj);
}

PyObject* CMarshalling::GetInt64Value(const long long& nValue)
{
	return PyLong_FromLongLong(nValue);
}

long long CMarshalling::GetInt64Value(PyObject* pObj)
{
	return PyLong_AsLongLong(pObj);
}

PyObject* CMarshalling::GetDoubleValue(const double& dValue)
{
	return PyFloat_FromDouble(dValue);
}

double CMarshalling::GetDoubleValue(PyObject* pObj)
{
	return PyFloat_AsDouble(pObj);
}

PyObject* CMarshalling::GetNoneValue()
{
	Py_INCREF(Py_None);
	PyObject* returnValue = Py_None;
	return returnValue;
}

PyObject* CMarshalling::GetBoolValue(const bool& bValue)
{
	return PyBool_FromLong(static_cast<long>(bValue));
}

bool CMarshalling::GetBoolValue(PyObject* pObj)
{
	return GetInt32Value(pObj) == 1 ? true : false;
}

PyObject* CMarshalling::GetHubData(const HubDataExt& hubData)
{
	PyObject* pArgs = PyTuple_New(6);
	PyTuple_SetItem(pArgs, 0, CMarshalling::GetStringValue(hubData.url));
	PyTuple_SetItem(pArgs, 1, CMarshalling::GetStringValue(hubData.ip));
	PyTuple_SetItem(pArgs, 2, CMarshalling::GetInt32Value((long)hubData.port));
	PyTuple_SetItem(pArgs, 3, CMarshalling::GetInt32Value((long)hubData.protocol));
	PyTuple_SetItem(pArgs, 4, CMarshalling::GetBoolValue(hubData.isOp));
	PyTuple_SetItem(pArgs, 5, CMarshalling::GetBoolValue(hubData.isSecure));

	PyObject* pInstance = CPythonManagement::GetObjectInstance(DATATYPES_BINARY, "HubData", pArgs);

	return pInstance;
}

HubDataExt CMarshalling::GetHubData(PyObject* pHubData)
{
	HubDataExt hubData;

	hubData.ip = GetStringAttribute(pHubData, "ip");
	hubData.url = GetStringAttribute(pHubData, "url");
	hubData.protocol = (ProtocolType)GetInt32Attribute(pHubData, "protocolType");
	hubData.port = GetInt16Attribute(pHubData, "port");
	hubData.isOp = GetBoolAttribute(pHubData, "isOp");
	hubData.isSecure = GetBoolAttribute(pHubData, "isSecure");

	return hubData;
}

PyObject* CMarshalling::GetUserData(const UserDataExt& userData)
{
	PyObject* pArgs = PyTuple_New(6);
	PyTuple_SetItem(pArgs, 0, CMarshalling::GetStringValue(userData.cid));
	PyTuple_SetItem(pArgs, 1, CMarshalling::GetStringValue(userData.hubHint));
	PyTuple_SetItem(pArgs, 2, CMarshalling::GetBoolValue(userData.isOp));
	PyTuple_SetItem(pArgs, 3, CMarshalling::GetStringValue(userData.nick));
	PyTuple_SetItem(pArgs, 4, CMarshalling::GetInt32Value((long)userData.protocol));
	PyTuple_SetItem(pArgs, 5, CMarshalling::GetInt32Value((long)userData.sid));

	PyObject* pInstance = CPythonManagement::GetObjectInstance(DATATYPES_BINARY, "UserData", pArgs);

	return pInstance;
}

UserDataExt CMarshalling::GetUserData(PyObject* pUserData)
{
	UserDataExt userData;

	userData.cid = GetStringAttribute(pUserData, "cid");
	userData.hubHint = GetStringAttribute(pUserData, "hubHint");
	userData.isOp = GetBoolAttribute(pUserData, "isOp");
	userData.nick = GetStringAttribute(pUserData, "nick");
	userData.protocol = (ProtocolType)GetInt32Attribute(pUserData, "protocol");
	userData.sid = GetInt32Attribute(pUserData, "sid");

	return userData;
}

PyObject* CMarshalling::GetQueueData(const QueueDataExt& queueData)
{
	PyObject* pArgs = PyTuple_New(5);
	PyTuple_SetItem(pArgs, 0, CMarshalling::GetStringValue(queueData.hash));
	PyTuple_SetItem(pArgs, 1, CMarshalling::GetBoolValue(queueData.isFileList));
	PyTuple_SetItem(pArgs, 2, CMarshalling::GetStringValue(queueData.location));
	PyTuple_SetItem(pArgs, 3, CMarshalling::GetInt64Value((long long)queueData.size));
	PyTuple_SetItem(pArgs, 4, CMarshalling::GetStringValue(queueData.target));

	PyObject* pInstance = CPythonManagement::GetObjectInstance(DATATYPES_BINARY, "QueueData", pArgs);

	return pInstance;
}

QueueDataExt CMarshalling::GetQueueData(PyObject* pQueueData)
{
	QueueDataExt queueData;

	queueData.hash = GetStringAttribute(pQueueData, "hash");
	queueData.isFileList = GetBoolAttribute(pQueueData, "isFilelist");
	queueData.location = GetStringAttribute(pQueueData, "location");
	queueData.size = GetInt64Attribute(pQueueData, "size");
	queueData.target = GetStringAttribute(pQueueData, "target");

	return queueData;
}

PyObject* CMarshalling::GetTagData(const TagDataExt& tagData)
{
	PyObject* pArgs = NULL;//PyTuple_New(0);

	PyObject* pInstance = CPythonManagement::GetObjectInstance(DATATYPES_BINARY, "TagData", pArgs);

	return pInstance;
}

TagDataExt CMarshalling::GetTagData(PyObject* pTagData)
{
	TagDataExt tagData;

	tagData.object = NULL;

	return tagData;
}

PyObject* CMarshalling::GetConnectionData(const ConnectionDataExt& connectionData)
{
	PyObject* pArgs = PyTuple_New(5);
	PyTuple_SetItem(pArgs, 0, CMarshalling::GetStringValue(connectionData.ip));
	PyTuple_SetItem(pArgs, 1, CMarshalling::GetBoolValue(connectionData.isOp));
	PyTuple_SetItem(pArgs, 2, CMarshalling::GetBoolValue(connectionData.isSecure));
	PyTuple_SetItem(pArgs, 3, CMarshalling::GetInt32Value((long)connectionData.port));
	PyTuple_SetItem(pArgs, 4, CMarshalling::GetInt32Value((long)connectionData.protocol));

	PyObject* pInstance = CPythonManagement::GetObjectInstance(DATATYPES_BINARY, "ConnectionData", pArgs);

	return pInstance;
}

ConnectionDataExt CMarshalling::GetConnectionData(PyObject* pConnectionData)
{
	ConnectionDataExt connectionData;

	connectionData.ip = GetStringAttribute(pConnectionData, "ip");
	connectionData.isOp = GetBoolAttribute(pConnectionData, "isOp");
	connectionData.isSecure = GetBoolAttribute(pConnectionData, "isSecure");
	connectionData.port = GetInt16Attribute(pConnectionData, "port");
	connectionData.protocol = (ProtocolType)GetInt32Attribute(pConnectionData, "protocol");

	return connectionData;
}

PyObject* CMarshalling::GetUDPData(const UDPDataExt& udpData)
{
	PyObject* pArgs = PyTuple_New(2);
	PyTuple_SetItem(pArgs, 0, CMarshalling::GetStringValue(udpData.ip));
	PyTuple_SetItem(pArgs, 1, CMarshalling::GetInt32Value((long)udpData.port));

	PyObject* pInstance = CPythonManagement::GetObjectInstance(DATATYPES_BINARY, "UDPData", pArgs);

	return pInstance;
}

UDPDataExt CMarshalling::GetUDPData(PyObject* pUDPData)
{
	UDPDataExt udpData;

	udpData.ip = GetStringAttribute(pUDPData, "ip");
	udpData.port = GetInt16Attribute(pUDPData, "port");

	return udpData;
}

PyObject* CMarshalling::GetCommandData(const CommandDataExt& commandData)
{
	PyObject* pArgs = PyTuple_New(2);
	PyTuple_SetItem(pArgs, 0, CMarshalling::GetStringValue(commandData.command));
	PyTuple_SetItem(pArgs, 1, CMarshalling::GetStringValue(commandData.parameters));

	PyObject* pInstance = CPythonManagement::GetObjectInstance(DATATYPES_BINARY, "CommandData", pArgs);

	return pInstance;
}

CommandDataExt CMarshalling::GetCommandData(PyObject* pCommandData)
{
	CommandDataExt commandData;

	commandData.command = GetStringAttribute(pCommandData, "command");
	commandData.parameters = GetStringAttribute(pCommandData, "parameters");

	return commandData;
}

PyObject* CMarshalling::GetPluginSetting(const dcapi::CPluginSettingContainer& pluginSetting)
{
	PyObject* pArgs = PyTuple_New(6);

	switch((dcapi::SettingDataType)pluginSetting._datatype)
	{
		case dcapi::SettingDataTypeByte:
			{
				PyTuple_SetItem(pArgs, 0, CMarshalling::GetStringValue(pluginSetting._byteSetting._name));
				PyTuple_SetItem(pArgs, 1, CMarshalling::GetInt32Value(pluginSetting._byteSetting._value));
				PyTuple_SetItem(pArgs, 2, CMarshalling::GetInt32Value(pluginSetting._byteSetting._defaultValue));
				PyTuple_SetItem(pArgs, 3, CMarshalling::GetInt32Value(pluginSetting._byteSetting._datatype));
				PyTuple_SetItem(pArgs, 4, CMarshalling::GetStringValue(pluginSetting._byteSetting._description));
				PyTuple_SetItem(pArgs, 5, CMarshalling::GetStringValue(pluginSetting._byteSetting._validvalues));
			}
			break;

		case dcapi::SettingDataTypeShort:
			{
				PyTuple_SetItem(pArgs, 0, CMarshalling::GetStringValue(pluginSetting._shortSetting._name));
				PyTuple_SetItem(pArgs, 1, CMarshalling::GetInt32Value(pluginSetting._shortSetting._value));
				PyTuple_SetItem(pArgs, 2, CMarshalling::GetInt32Value(pluginSetting._shortSetting._defaultValue));
				PyTuple_SetItem(pArgs, 3, CMarshalling::GetInt32Value(pluginSetting._shortSetting._datatype));
				PyTuple_SetItem(pArgs, 4, CMarshalling::GetStringValue(pluginSetting._shortSetting._description));
				PyTuple_SetItem(pArgs, 5, CMarshalling::GetStringValue(pluginSetting._shortSetting._validvalues));
			}
			break;

		case dcapi::SettingDataTypeInt:
			{
				PyTuple_SetItem(pArgs, 0, CMarshalling::GetStringValue(pluginSetting._intSetting._name));
				PyTuple_SetItem(pArgs, 1, CMarshalling::GetInt32Value(pluginSetting._intSetting._value));
				PyTuple_SetItem(pArgs, 2, CMarshalling::GetInt32Value(pluginSetting._intSetting._defaultValue));
				PyTuple_SetItem(pArgs, 3, CMarshalling::GetInt32Value(pluginSetting._intSetting._datatype));
				PyTuple_SetItem(pArgs, 4, CMarshalling::GetStringValue(pluginSetting._intSetting._description));
				PyTuple_SetItem(pArgs, 5, CMarshalling::GetStringValue(pluginSetting._intSetting._validvalues));
			}
			break;

		case dcapi::SettingDataTypeLong:
			{
				PyTuple_SetItem(pArgs, 0, CMarshalling::GetStringValue(pluginSetting._longSetting._name));
				PyTuple_SetItem(pArgs, 1, CMarshalling::GetInt64Value(pluginSetting._longSetting._value));
				PyTuple_SetItem(pArgs, 2, CMarshalling::GetInt64Value(pluginSetting._longSetting._defaultValue));
				PyTuple_SetItem(pArgs, 3, CMarshalling::GetInt32Value(pluginSetting._longSetting._datatype));
				PyTuple_SetItem(pArgs, 4, CMarshalling::GetStringValue(pluginSetting._longSetting._description));
				PyTuple_SetItem(pArgs, 5, CMarshalling::GetStringValue(pluginSetting._longSetting._validvalues));
			}
			break;

		case dcapi::SettingDataTypeString:
		case dcapi::SettingDataTypeUnknown:
		default:
			{
				PyTuple_SetItem(pArgs, 0, CMarshalling::GetStringValue(pluginSetting._stringSetting._name));
				PyTuple_SetItem(pArgs, 1, CMarshalling::GetStringValue(pluginSetting._stringSetting._value));
				PyTuple_SetItem(pArgs, 2, CMarshalling::GetStringValue(pluginSetting._stringSetting._defaultValue));
				PyTuple_SetItem(pArgs, 3, CMarshalling::GetInt32Value(pluginSetting._stringSetting._datatype));
				PyTuple_SetItem(pArgs, 4, CMarshalling::GetStringValue(pluginSetting._stringSetting._description));
				PyTuple_SetItem(pArgs, 5, CMarshalling::GetStringValue(pluginSetting._stringSetting._validvalues));
			}
			break;
	}
	
	PyObject* pInstance = CPythonManagement::GetObjectInstance(DATATYPES_BINARY, "PluginSetting", pArgs);

	return pInstance;
}

dcapi::CPluginSettingContainer CMarshalling::GetPluginSetting(PyObject* pPluginSetting)
{
	dcapi::CPluginSettingContainer pluginSetting;

	std::string strName = GetStringAttribute(pPluginSetting, "name");
	std::string strDescription = GetStringAttribute(pPluginSetting, "description");
	std::string strValidValues = GetStringAttribute(pPluginSetting, "validvalues");

	long nDataType = GetInt32Attribute(pPluginSetting, "datatype");
	switch((dcapi::SettingDataType)nDataType)
	{
		case dcapi::SettingDataTypeByte:
			{
				long defaultValue = GetInt32Attribute(pPluginSetting, "defaultvalue");
				long value = GetInt32Attribute(pPluginSetting, "value");

				pluginSetting = dcapi::CPluginSettingContainer::GetContainer(
					strName, strDescription, (dcapi::SettingDataType)nDataType, strValidValues, 
					(uint8_t)defaultValue, (uint8_t)value);
			}
			break;

		case dcapi::SettingDataTypeShort:
			{
				long defaultValue = GetInt32Attribute(pPluginSetting, "defaultvalue");
				long value = GetInt32Attribute(pPluginSetting, "value");

				pluginSetting = dcapi::CPluginSettingContainer::GetContainer(
					strName, strDescription, (dcapi::SettingDataType)nDataType, strValidValues, 
					(uint16_t)defaultValue, (uint16_t)value);
			}
			break;

		case dcapi::SettingDataTypeInt:
			{
				long defaultValue = GetInt32Attribute(pPluginSetting, "defaultvalue");
				long value = GetInt32Attribute(pPluginSetting, "value");

				pluginSetting = dcapi::CPluginSettingContainer::GetContainer(
					strName, strDescription, (dcapi::SettingDataType)nDataType, strValidValues, 
					(uint32_t)defaultValue, (uint32_t)value);
			}
			break;

		case dcapi::SettingDataTypeLong:
			{
				long long defaultValue = GetInt64Attribute(pPluginSetting, "defaultvalue");
				long long value = GetInt64Attribute(pPluginSetting, "value");

				pluginSetting = dcapi::CPluginSettingContainer::GetContainer(
					strName, strDescription, (dcapi::SettingDataType)nDataType, strValidValues, (uint64_t)defaultValue, (uint64_t)value);
			}
			break;

		case dcapi::SettingDataTypeString:
		case dcapi::SettingDataTypeUnknown:
			{
				std::string defaultValue = GetStringAttribute(pPluginSetting, "defaultvalue");
				std::string value = GetStringAttribute(pPluginSetting, "value");

				pluginSetting = dcapi::CPluginSettingContainer::GetContainer(
					strName, strDescription, (dcapi::SettingDataType)nDataType, strValidValues, (std::string)defaultValue, (std::string)value);
			}
			break;
	}

	return pluginSetting;
}

PyObject* CMarshalling::GetPluginInformation(const dcapi::CPluginInformation& pluginInformation)
{
	PyObject* pArgs = PyTuple_New(7); // todo: 8
	PyTuple_SetItem(pArgs, 0, CMarshalling::GetStringValue(pluginInformation._name));
	PyTuple_SetItem(pArgs, 1, CMarshalling::GetStringValue(pluginInformation._description));
	PyTuple_SetItem(pArgs, 2, CMarshalling::GetStringValue(pluginInformation._author));
	PyTuple_SetItem(pArgs, 3, CMarshalling::GetStringValue(pluginInformation._web));
	PyTuple_SetItem(pArgs, 4, CMarshalling::GetDoubleValue(pluginInformation._version));
	PyTuple_SetItem(pArgs, 5, CMarshalling::GetDoubleValue(pluginInformation._apiversion));
	PyTuple_SetItem(pArgs, 6, CMarshalling::GetStringValue(pluginInformation._guid));
	//PyTuple_SetItem(pArgs, 7, CMarshalling::GetSettingListValue(pluginInformation._settings));

	PyObject* pInstance = CPythonManagement::GetObjectInstance(DATATYPES_BINARY, "PluginInformation", pArgs);

	return pInstance;
}

dcapi::CPluginInformation CMarshalling::GetPluginInformation(PyObject* pPluginInformation)
{
	dcapi::CPluginInformation pluginInformation;

	pluginInformation._name = GetStringAttribute(pPluginInformation, "name");
	pluginInformation._description = GetStringAttribute(pPluginInformation, "description");
	pluginInformation._author = GetStringAttribute(pPluginInformation, "author");
	pluginInformation._web = GetStringAttribute(pPluginInformation, "web");
	pluginInformation._version = GetDoubleAttribute(pPluginInformation, "version");
	pluginInformation._apiversion = GetInt32Attribute(pPluginInformation, "apiversion");
	pluginInformation._guid = GetStringAttribute(pPluginInformation, "uuid");
	//pluginInformation._settings = GetSettingListAttribute(pPluginInformation, "settings"); // todo

	return pluginInformation;
}

PyObject* CMarshalling::GetAttribute(PyObject* pObject, const std::string& strAttribute)
{
	PyObject* pAttribute = PyObject_GetAttrString( pObject, strAttribute.c_str() );
	return pAttribute;
}

std::string CMarshalling::GetStringAttribute(PyObject* pObject, const std::string& strAttribute)
{
	PyObject* pAttribute = GetAttribute( pObject, strAttribute );
	return GetStringValue( pAttribute );
}

bool CMarshalling::GetBoolAttribute(PyObject* pObject, const std::string& strAttribute)
{
	PyObject* pAttribute = GetAttribute( pObject, strAttribute );
	return GetBoolValue( pAttribute );
}

short CMarshalling::GetInt16Attribute(PyObject* pObject, const std::string& strAttribute)
{
	PyObject* pAttribute = GetAttribute( pObject, strAttribute );
	return GetInt16Value( pAttribute );
}

long CMarshalling::GetInt32Attribute(PyObject* pObject, const std::string& strAttribute)
{
	PyObject* pAttribute = GetAttribute( pObject, strAttribute );
	return GetInt32Value( pAttribute );
}

long long CMarshalling::GetInt64Attribute(PyObject* pObject, const std::string& strAttribute)
{
	PyObject* pAttribute = GetAttribute( pObject, strAttribute );
	return GetInt64Value( pAttribute );
}

double CMarshalling::GetDoubleAttribute(PyObject* pObject, const std::string& strAttribute)
{
	PyObject* pAttribute = GetAttribute( pObject, strAttribute );
	return GetDoubleValue( pAttribute );
}


HubDataExt CAPIMarshaling::GetHubData(HubData* hubData)
{
	HubDataExt hubDataExt;

	if(hubData == NULL)
	{
		return hubDataExt;
	}

	hubDataExt.ip = hubData->ip;
	hubDataExt.isOp = GetBool( hubData->isOp );
	hubDataExt.isSecure = GetBool( hubData->isSecure );
	hubDataExt.object = hubData->object;
	hubDataExt.port = hubData->port;
	hubDataExt.protocol = hubData->protocol;
	hubDataExt.url = hubData->url;

	return hubDataExt;
}

HubData CAPIMarshaling::GetHubData(const HubDataExt& hubDataExt)
{
	HubData hubData;

	hubData.ip = hubDataExt.ip.c_str();
	hubData.isOp = GetBool( hubDataExt.isOp );
	hubData.isSecure = GetBool( hubDataExt.isSecure );
	hubData.object = hubDataExt.object;
	hubData.port = hubDataExt.port;
	hubData.protocol = hubDataExt.protocol;
	hubData.url = hubDataExt.url.c_str();

	return hubData;
}

UserDataExt CAPIMarshaling::GetUserData(UserData* userData)
{
	UserDataExt userDataExt;

	if(userData == NULL)
	{
		return userDataExt;
	}

	userDataExt.cid = userData->cid;
	userDataExt.hubHint = userData->hubHint;
	userDataExt.isOp = GetBool( userData->isOp );
	userDataExt.nick = userData->nick;
	userDataExt.object = userData->object;
	userDataExt.protocol = userData->protocol;
	userDataExt.sid = userData->sid;

	return userDataExt;
}

UserData CAPIMarshaling::GetUserData(const UserDataExt& userDataExt)
{
	UserData userData;

	userData.cid = userDataExt.cid.c_str();
	userData.hubHint = userDataExt.hubHint.c_str();
	userData.isOp = GetBool( userDataExt.isOp );
	userData.nick = userDataExt.nick.c_str();
	userData.object = userDataExt.object;
	userData.protocol = userDataExt.protocol;
	userData.sid = userDataExt.sid;

	return userData;
}

ConnectionDataExt CAPIMarshaling::GetConnectionData(ConnectionData* connectionData)
{
	ConnectionDataExt connectionDataExt;

	if(connectionData == NULL)
	{
		return connectionDataExt;
	}

	connectionDataExt.ip = connectionData->ip;
	connectionDataExt.isOp = GetBool( connectionData->isOp );
	connectionDataExt.isSecure = GetBool( connectionData->isSecure );
	connectionDataExt.object = connectionData->object;
	connectionDataExt.port = connectionData->port;
	connectionDataExt.protocol = connectionData->protocol;

	return connectionDataExt;
}

ConnectionData CAPIMarshaling::GetConnectionData(const ConnectionDataExt& connectionDataExt)
{
	ConnectionData connectionData;

	connectionData.ip = connectionDataExt.ip.c_str();
	connectionData.isOp = GetBool( connectionDataExt.isOp );
	connectionData.isSecure = GetBool( connectionDataExt.isSecure );
	connectionData.object = connectionDataExt.object;
	connectionData.port = connectionDataExt.port;
	connectionData.protocol = connectionDataExt.protocol;

	return connectionData;
}

CommandDataExt CAPIMarshaling::GetCommandData(CommandData* commandData)
{
	CommandDataExt commandDataExt;

	if(commandData == NULL)
	{
		return commandDataExt;
	}

	commandDataExt.command = commandData->command;
	commandDataExt.parameters = commandData->params;

	return commandDataExt;
}

CommandData CAPIMarshaling::GetCommandData(const CommandDataExt& commandDataExt)
{
	CommandData commandData;

	commandData.command = commandDataExt.command.c_str();
	commandData.params = commandDataExt.parameters.c_str();

	return commandData;
}
UDPDataExt CAPIMarshaling::GetUDPData(UDPData* udpData)
{
	UDPDataExt udpDataExt;

	if(udpData == NULL)
	{
		return udpDataExt;
	}

	udpDataExt.ip = udpData->ip;
	udpDataExt.port = udpData->port;

	return udpDataExt;
}

UDPData CAPIMarshaling::GetUDPData(const UDPDataExt& udpDataExt)
{
	UDPData udpData;

	udpData.ip = udpDataExt.ip.c_str();
	udpData.port = udpDataExt.port;

	return udpData;
}


QueueDataExt CAPIMarshaling::GetQueueData(QueueData* queueData)
{
	QueueDataExt queueDataExt;

	if(queueData == NULL)
	{
		return queueDataExt;
	}

	queueDataExt.hash = queueData->hash;
	queueDataExt.isFileList = GetBool( queueData->isFileList );
	queueDataExt.location = queueData->location;
	queueDataExt.object = queueData->object;
	queueDataExt.size = queueData->size;
	queueDataExt.target = queueData->target;

	return queueDataExt;
}
QueueData CAPIMarshaling::GetQueueData(const QueueDataExt& queueDataExt)
{
	QueueData queueData;

	queueData.hash = queueDataExt.hash.c_str();
	queueData.isFileList = GetBool( queueDataExt.isFileList );
	queueData.location = queueDataExt.location.c_str();
	queueData.object = queueDataExt.object;
	queueData.size = queueDataExt.size;
	queueData.target = queueDataExt.target.c_str();

	return queueData;
}

TagDataExt CAPIMarshaling::GetTagData(TagData* tagData)
{
	TagDataExt tagDataExt;

	tagDataExt.object = NULL;
	//tagDataExt.object = tagData.object;

	return tagDataExt;
}

TagData CAPIMarshaling::GetTagData(const TagDataExt& tagDataExt)
{
	TagData tagData;

	tagData.isManaged = dcTrue;
	//tagData.object = tagDataExt.object;

	return tagData;
}

bool CAPIMarshaling::GetBool(const dcBool& b)
{
	return b == dcTrue ? true : false;
}

dcBool CAPIMarshaling::GetBool(const bool& b)
{
	return b == true ? dcTrue : dcFalse;
}
