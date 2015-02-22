
#pragma once

#include "DCPluginSink.h"
#include "Python.h"

#include <string>

class CPythonManagement
{
public:

	static void InitializePython();
	static void UninitalizePython();

	static PyObject* GetObjectInstance(const std::string& strModuleName, const std::string& strObjectType, PyObject* pArgs );

	static PyObject* GetObjectInstance(const std::string& strModuleName, const std::string& strObjectType);

	static PyObject* GetPluginBaseObject(const std::string& strModuleName, const std::string& strClassName, CPluginSink* pluginSink);

	static PyMethodDef* GetStaticMethods();

};