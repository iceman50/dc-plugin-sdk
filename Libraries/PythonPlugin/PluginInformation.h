
#pragma once

#include "version.h"

#include <dcapi/PluginDefs.h>

#include <string>
#include <map>

#ifdef __cplusplus
#include <cstdint>
#include <cstddef>
#else
#include <stdint.h>
#include <stddef.h>
#endif

namespace dcapi {

enum SettingDataType
{
    SettingDataTypeUnknown = 0,
    SettingDataTypeString = 1,
    SettingDataTypeByte = 2,
    SettingDataTypeShort = 3,
    SettingDataTypeInt = 4,
    SettingDataTypeLong = 5
};


template<typename T>
class CPluginSetting
{
public:

    std::string _name;
    std::string _description;
    std::string _validvalues;

    T _value;
    T _defaultValue;

    SettingDataType _datatype;
};

class CPluginSettingContainer
{
public:

    static CPluginSettingContainer GetContainer(CPluginSetting<std::string> setting)
    {
        CPluginSettingContainer container;
        container._stringSetting = setting;
        container._datatype = SettingDataTypeString;

        return container;
    }

    static CPluginSettingContainer GetContainer(CPluginSetting<uint8_t> setting)
    {
        CPluginSettingContainer container;
        container._byteSetting = setting;
        container._datatype = SettingDataTypeByte;

        return container;
    }

    static CPluginSettingContainer GetContainer(CPluginSetting<uint16_t> setting)
    {
        CPluginSettingContainer container;
        container._shortSetting = setting;
        container._datatype = SettingDataTypeShort;

        return container;
    }

    static CPluginSettingContainer GetContainer(CPluginSetting<uint32_t> setting)
    {
        CPluginSettingContainer container;
        container._intSetting = setting;
        container._datatype = SettingDataTypeInt;

        return container;
    }

    static CPluginSettingContainer GetContainer(CPluginSetting<uint64_t> setting)
    {
        CPluginSettingContainer container;
        container._longSetting = setting;
        container._datatype = SettingDataTypeLong;

        return container;
    }

	static CPluginSettingContainer GetContainer(const std::string& strName, const std::string& strDescription, 
												const SettingDataType& datatype, const std::string& strValidValues,
												const uint64_t& defaultValue, const uint64_t& value)
	{
		CPluginSettingContainer container;

		CPluginSetting<uint64_t> setting;
		setting._name = strName;
		setting._description = strDescription;
		setting._datatype = datatype;
		setting._validvalues = strValidValues;
		setting._defaultValue = defaultValue;
		setting._value = value;
		
		container._longSetting = setting;
		container._datatype = datatype;

		return container;
	}

	static CPluginSettingContainer GetContainer(const std::string& strName, const std::string& strDescription, 
												const SettingDataType& datatype, const std::string& strValidValues,
												const uint32_t& defaultValue, const uint32_t& value)
	{
		CPluginSettingContainer container;

		CPluginSetting<uint32_t> setting;
		setting._name = strName;
		setting._description = strDescription;
		setting._datatype = datatype;
		setting._validvalues = strValidValues;
		setting._defaultValue = defaultValue;
		setting._value = value;
		
		container._intSetting = setting;
		container._datatype = datatype;

		return container;
	}

	static CPluginSettingContainer GetContainer(const std::string& strName, const std::string& strDescription, 
												const SettingDataType& datatype, const std::string& strValidValues,
												const uint16_t& defaultValue, const uint16_t& value)
	{
		CPluginSettingContainer container;

		CPluginSetting<uint16_t> setting;
		setting._name = strName;
		setting._description = strDescription;
		setting._datatype = datatype;
		setting._validvalues = strValidValues;
		setting._defaultValue = defaultValue;
		setting._value = value;
		
		container._shortSetting = setting;
		container._datatype = datatype;

		return container;
	}

	static CPluginSettingContainer GetContainer(const std::string& strName, const std::string& strDescription, 
												const SettingDataType& datatype, const std::string& strValidValues,
												const uint8_t& defaultValue, const uint8_t& value)
	{
		CPluginSettingContainer container;

		CPluginSetting<uint16_t> setting;
		setting._name = strName;
		setting._description = strDescription;
		setting._datatype = datatype;
		setting._validvalues = strValidValues;
		setting._defaultValue = defaultValue;
		setting._value = value;
		
		container._shortSetting = setting;
		container._datatype = datatype;

		return container;
	}

	static CPluginSettingContainer GetContainer(const std::string& strName, const std::string& strDescription, 
												const SettingDataType& datatype, const std::string& strValidValues,
												const std::string& defaultValue, const std::string& value)
	{
		CPluginSettingContainer container;

		CPluginSetting<std::string> setting;
		setting._name = strName;
		setting._description = strDescription;
		setting._datatype = datatype;
		setting._validvalues = strValidValues;
		setting._defaultValue = defaultValue;
		setting._value = value;
		
		container._stringSetting = setting;
		container._datatype = datatype;

		return container;
	}

	std::string GetName()
    {
        switch(_datatype)
        {
            case SettingDataTypeByte:
                return _byteSetting._name;

            case SettingDataTypeShort:
                return _shortSetting._name;

            case SettingDataTypeInt:
                return _intSetting._name;

            case SettingDataTypeLong:
                return _longSetting._name;

            case SettingDataTypeString:
            case SettingDataTypeUnknown:
            default:
                return _stringSetting._name;
        }
    }

	void SetName(const std::string& strName)
	{
		switch(_datatype)
        {
            case SettingDataTypeByte:
                _byteSetting._name = strName;
				break;

            case SettingDataTypeShort:
                _shortSetting._name = strName;
				break;

            case SettingDataTypeInt:
                _intSetting._name = strName;
				break;

            case SettingDataTypeLong:
                _longSetting._name = strName;
				break;

            case SettingDataTypeString:
            case SettingDataTypeUnknown:
            default:
                _stringSetting._name = strName;
				break;
        }
	}

    std::string GetDescription()
    {
        switch(_datatype)
        {
            case SettingDataTypeByte:
                return _byteSetting._description;

            case SettingDataTypeShort:
                return _shortSetting._description;

            case SettingDataTypeInt:
                return _intSetting._description;

            case SettingDataTypeLong:
                return _longSetting._description;

            case SettingDataTypeString:
            case SettingDataTypeUnknown:
            default:
                return _stringSetting._description;
        }
    }

	void SetDescription(const std::string& description)
	{
		switch(_datatype)
        {
            case SettingDataTypeByte:
                _byteSetting._description = description;
				break;

            case SettingDataTypeShort:
                _shortSetting._description = description;
				break;

            case SettingDataTypeInt:
                _intSetting._description = description;
				break;

            case SettingDataTypeLong:
                _longSetting._description = description;
				break;

            case SettingDataTypeString:
            case SettingDataTypeUnknown:
            default:
                _stringSetting._description = description;
				break;
        }
	}

    std::string GetStringValue()
    {
        return _stringSetting._value;
    }

    uint8_t GetByteValue()
    {
        return _byteSetting._value;
    }

    CPluginSetting<std::string> _stringSetting;
    CPluginSetting<uint8_t> _byteSetting;
    CPluginSetting<uint16_t> _shortSetting;
    CPluginSetting<uint32_t> _intSetting;
    CPluginSetting<uint64_t> _longSetting;
	
    SettingDataType _datatype;
};


class CPluginInformation
{
public:

    CPluginInformation()
    {
        _name = PLUGIN_NAME;
        _author = PLUGIN_AUTHOR;
        _description = PLUGIN_DESC;
        _web = PLUGIN_WEB;
        _guid = PLUGIN_WEB;
        _apiversion = DCAPI_CORE_VER;
        _version = PLUGIN_VERSION;
    }

    CPluginSettingContainer GetSetting(const std::string& name)
    {
        return _settings[name];
    }

    std::string _name;
    std::string _author;
    std::string _description;
    std::string _web;
    std::string _guid;
    uint32_t _apiversion;
    double _version;

    std::map<std::string, CPluginSettingContainer> _settings;

};

}