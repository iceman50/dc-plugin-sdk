
#pragma once

#include "Python.h"
#include "DCPluginSink.h"

class CPythonCallbacks
{

public:


public:

	//
	// Core
	//

	static PyObject* GetApplicationNameCallbackFunc(PyObject* self, PyObject* args);
	static PyObject* SetApplicationNameCallbackFunc(PyObject* self, PyObject* args);

	//
	// Log
	//

	static PyObject* LogMessageCallbackFunc(PyObject *self, PyObject *args);
	
	//
	// Config
	//

	static PyObject* GetInstallPathCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* GetPathCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* GetStringConfigCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* SetStringConfigCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* GetBoolConfigCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* SetBoolConfigCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* GetInt32ConfigCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* SetInt32ConfigCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* GetInt64ConfigCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* SetInt64ConfigCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* GetLanguageCallbackFunc(PyObject *self, PyObject *args);
	
	//
	// Connection
	//

	static PyObject* SendUDPDataCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* SendProtocolCommandConnectionCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* TerminateConnectionCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* GetConnectionUserCallbackFunc(PyObject *self, PyObject *args);
	
	//
	// Hub
	//
	static PyObject* AddHubCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* FindHubCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* RemoveHubCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* EmulateProtocolCommandCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* SendProtocolCommandHubCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* SendMessageCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* LocalMessageCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* SendPrivateMessageCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* FindUserCallbackFunc(PyObject *self, PyObject *args);
	
	//
	// Queue
	//
	static PyObject* AddListCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* AddDownloadCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* FindDownloadCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* RemoveDownloadCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* SetPriorityCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* PauseCallbackFunc(PyObject *self, PyObject *args);
	
	//
	// Tagger
	//
	static PyObject* GetTextCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* AddTagCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* ReplaceTagTextCallbackFunc(PyObject *self, PyObject *args);
	
	//
	// UI
	//

	static PyObject* AddCommandCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* RemoveCommandCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* ClearCommandsCallbackFunc(PyObject *self, PyObject *args);
	static PyObject* PlaySoundInUICallbackFunc(PyObject *self, PyObject *args);
	static PyObject* NotifyCallbackFunc(PyObject *self, PyObject *args);

private:

	typedef CPluginSink CPythonPluginSink;

};