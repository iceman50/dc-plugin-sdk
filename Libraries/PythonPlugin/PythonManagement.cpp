
#include "PythonManagement.h"

#include "DCPluginSink.h"
#include "PythonCallbacks.h"
#include "Marshalling.h"

#include "Python.h"

static PyMethodDef StaticPythonMethods[] = {

	// Core
	{"GetApplicationName",  CPythonCallbacks::GetApplicationNameCallbackFunc, METH_VARARGS, ""},
	{"SetApplicationName",  CPythonCallbacks::SetApplicationNameCallbackFunc, METH_VARARGS, ""},

	// Log
	{"LogMessage",  CPythonCallbacks::LogMessageCallbackFunc, METH_VARARGS, ""},

	// Config
	{"GetInstallPath",  CPythonCallbacks::GetInstallPathCallbackFunc, METH_VARARGS, ""},
	{"GetPath",  CPythonCallbacks::GetPathCallbackFunc, METH_VARARGS, ""},
	{"GetStringConfig",  CPythonCallbacks::GetStringConfigCallbackFunc, METH_VARARGS, ""},
	{"SetStringConfig",  CPythonCallbacks::SetStringConfigCallbackFunc, METH_VARARGS, ""},
	{"GetBoolConfig",  CPythonCallbacks::GetBoolConfigCallbackFunc, METH_VARARGS, ""},
	{"SetBoolConfig",  CPythonCallbacks::SetBoolConfigCallbackFunc, METH_VARARGS, ""},
	{"GetInt32Config",  CPythonCallbacks::GetInt32ConfigCallbackFunc, METH_VARARGS, ""},
	{"SetInt32Config",  CPythonCallbacks::SetInt32ConfigCallbackFunc, METH_VARARGS, ""},
	{"GetInt64Config",  CPythonCallbacks::GetInt64ConfigCallbackFunc, METH_VARARGS, ""},
	{"SetInt64Config",  CPythonCallbacks::SetInt64ConfigCallbackFunc, METH_VARARGS, ""},
	{"GetLanguage",  CPythonCallbacks::GetLanguageCallbackFunc, METH_VARARGS, ""},

	// Connection
	{"SendUDPData",  CPythonCallbacks::SendUDPDataCallbackFunc, METH_VARARGS, ""},
	{"SendProtocolCommandConnection",  CPythonCallbacks::SendProtocolCommandConnectionCallbackFunc, METH_VARARGS, ""},
	{"TerminateConnection",  CPythonCallbacks::TerminateConnectionCallbackFunc, METH_VARARGS, ""},
	{"GetConnectionUser",  CPythonCallbacks::GetConnectionUserCallbackFunc, METH_VARARGS, ""},

	// Hub
	{"AddHub",  CPythonCallbacks::AddHubCallbackFunc, METH_VARARGS, ""},
	{"FindHub",  CPythonCallbacks::FindHubCallbackFunc, METH_VARARGS, ""},
	{"RemoveHub",  CPythonCallbacks::RemoveHubCallbackFunc, METH_VARARGS, ""},
	{"EmulateProtocolCommand",  CPythonCallbacks::EmulateProtocolCommandCallbackFunc, METH_VARARGS, ""},
	{"SendProtocolCommandHub",  CPythonCallbacks::SendProtocolCommandHubCallbackFunc, METH_VARARGS, ""},
	{"SendMessage",  CPythonCallbacks::SendMessageCallbackFunc, METH_VARARGS, ""},
	{"LocalMessage",  CPythonCallbacks::LocalMessageCallbackFunc, METH_VARARGS, ""},
	{"SendPrivateMessage",  CPythonCallbacks::SendPrivateMessageCallbackFunc, METH_VARARGS, ""},
	{"FindUser",  CPythonCallbacks::FindUserCallbackFunc, METH_VARARGS, ""},

	// Queue
	{"AddList",  CPythonCallbacks::AddListCallbackFunc, METH_VARARGS, ""},
	{"AddDownload",  CPythonCallbacks::AddDownloadCallbackFunc, METH_VARARGS, ""},
	{"FindDownload",  CPythonCallbacks::FindDownloadCallbackFunc, METH_VARARGS, ""},
	{"RemoveDownload",  CPythonCallbacks::RemoveDownloadCallbackFunc, METH_VARARGS, ""},
	{"SetPriority",  CPythonCallbacks::SetPriorityCallbackFunc, METH_VARARGS, ""},
	{"Pause",  CPythonCallbacks::PauseCallbackFunc, METH_VARARGS, ""},

	// Tagger
	{"GetText",  CPythonCallbacks::GetTextCallbackFunc, METH_VARARGS, ""},
	{"AddTag",  CPythonCallbacks::AddTagCallbackFunc, METH_VARARGS, ""},
	{"ReplaceTagText",  CPythonCallbacks::ReplaceTagTextCallbackFunc, METH_VARARGS, ""},

	// UI
	{"AddCommand",  CPythonCallbacks::AddCommandCallbackFunc, METH_VARARGS, ""},
	{"RemoveCommand",  CPythonCallbacks::RemoveCommandCallbackFunc, METH_VARARGS, ""},
	{"ClearCommands",  CPythonCallbacks::ClearCommandsCallbackFunc, METH_VARARGS, ""},
	{"PlaySoundInUI",  CPythonCallbacks::PlaySoundInUICallbackFunc, METH_VARARGS, ""},
	{"Notify",  CPythonCallbacks::NotifyCallbackFunc, METH_VARARGS, ""},

	{NULL, NULL, 0, NULL}        /* Sentinel */
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef StaticPythonModule = 
{
	PyModuleDef_HEAD_INIT,
	"DCPluginSink",
	NULL,
	-1,
	StaticPythonMethods
};

PyMODINIT_FUNC PyInit_PythonPlugin()
{
	return PyModule_Create(&StaticPythonModule);
}
#endif

void CPythonManagement::InitializePython()
{
#if PY_MAJOR_VERSION >= 3
	PyImport_AppendInittab("DCPluginSink", PyInit_PythonPlugin);

	Py_Initialize();
#else
	Py_Initialize();

	Py_InitModule("DCPluginSink", CPythonManagement::GetStaticMethods());
#endif
}

void CPythonManagement::UninitalizePython()
{
	Py_Finalize();
}

PyObject* CPythonManagement::GetObjectInstance(const std::string& strModuleName, const std::string& strObjectType, PyObject* pArgs )
{
	// todo: Add error checking
	PyObject* pModuleName = CMarshalling::GetStringValue(strModuleName);

	PyObject* pModule = PyImport_Import(pModuleName);
	if (!pModule) {
		printf("Could not load the Python module %s\n", strModuleName.c_str());
		// todo: throw
		return nullptr;
	}

	PyObject* pDict = PyModule_GetDict(pModule);

	PyObject* pClass = PyDict_GetItemString(pDict, strObjectType.c_str());

	PyObject* pInstance = PyObject_CallObject(pClass, pArgs);

	// todo: Clean up resources

	return pInstance;
}

PyObject* CPythonManagement::GetObjectInstance(const std::string& strModuleName, const std::string& strObjectType)
{
	return GetObjectInstance(strModuleName, strObjectType, NULL);
}

PyObject* CPythonManagement::GetPluginBaseObject(const std::string& strModuleName, const std::string& strClassName, CPluginSink* pluginSink)
{
	// todo: Add error checking

	// Get object with arguments
	PyObject* pObjectInstance = GetObjectInstance(strModuleName, strClassName, NULL);

	PyObject_CallMethod( pObjectInstance, "SetSink", "i", (int)pluginSink);

	return pObjectInstance;
}

PyMethodDef* CPythonManagement::GetStaticMethods()
{
	return StaticPythonMethods;
}