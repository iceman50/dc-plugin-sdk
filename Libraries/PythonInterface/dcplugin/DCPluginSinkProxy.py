
import DCPluginSink

from .Enumerations import *
from .DataTypes import *


class DCPluginProxySink(object):
    def __init__(self, paramSink):
        self._sink = paramSink

    """ Core """
    def GetApplicationName(self):
        return DCPluginSink.GetApplicationName(self._sink)

    def SetApplicationName(self, name):
        DCPluginSink.SetApplicationName(self._sink, name)

    """ Log """
    def LogMessage(self, message):
        DCPluginSink.LogMessage(self._sink, message)

    """ Config """
    def GetInstallPath(self):
        return DCPluginSink.GetInstallPath(self._sink)

    def GetPath(self, pathType):
        return DCPluginSink.GetPath(self._sink, pathType)

    def GetStringConfig(self, name):
        return DCPluginSink.GetStringConfig(self._sink, name)
    def SetStringConfig(self, name, value):
        DCPluginSink.SetStringConfig(self._sink, name, value)

    def GetBoolConfig(self, name):
        return DCPluginSink.GetBoolConfig(self._sink, name)
    def SetBoolConfig(self, name, value):
        DCPluginSink.SetStringConfig(self._sink, name, value)

    def GetInt32Config(self, name):
        return DCPluginSink.GetInt32Config(self._sink, name)
    def SetInt32Config(self, name, value):
        DCPluginSink.SetStringConfig(self._sink, name, value)

    def GetInt64Config(self, name):
        return DCPluginSink.GetInt64Config(self._sink, name)
    def SetInt64Config(self, name, value):
        DCPluginSink.SetStringConfig(self._sink, name, value)

    def GetLanguage(self):
        return DCPluginSink.GetLanguage(self._sink);

    """ Connection """
    def SendUDPData(self, ipAddress, port, data, amount):
        DCPluginSink.SendUDPData(self._sink, ipAddress, port, data, amount)

    def SendProtocolCommandConnection(self, connectionData, command):
        DCPluginSink.SendProtocolCommandConnection(
            self._sink, connectionData, command
        )

    def TerminateConnection(self, connectionData, graceLess):
        DCPluginSink.TerminateConnection(self._sink, connectionData, graceLess)

    def GetConnectionUser(self, connectionData):
        return DCPluginSink.GetConnectionUser(self._sink, connectionData)

    """ Hub """
    def AddHub(self, url, nick, password):
        return DCPluginSink.AddHub(self._sink, url, nick, password)

    def FindHub(self, url):
        return DCPluginSink.FindHub(self._sink, url)

    def RemoveHub(self, hubData):
        DCPluginSink.RemoveHub(self._sink, hubData)

    def EmulateProtocolCommand(self, hubData, command):
        DCPluginSink.EmualteProtocolCommand(self._sink, hubData, command)

    def SendProtocolCommandHub(self, hubData, command):
        DCPluginSink.SendProtocolCommandHub(self._sink, hubData, command)

    def SendMessage(self, hubData, message, thirdPerson):
        DCPluginSink.SendMessage(self._sink, hubData, message, thirdPerson)

    def LocalMessage(self, hubData, message, messageType):
        DCPluginSink.LocalMessage(self._sink, hubData, message, messageType)

    def SendPrivateMessage(self, userData, message, thirdPerson):
        DCPluginSink.SendPrivateMessage(
            self._sink, userData, message, thirdPerson
        )

    def FindUser(self, cid, hubURL):
        return DCPluginSink.FindUser(self._sink, cid, hubURL)

    """ Queue """
    def AddList(self, userData, silent):
        return DCPluginSink.AddList(self._sink, userData, silent)

    def AddDownload(self, hashData, size, target):
        return DCPluginSink.AddDownload(self._sink, hashData, size, target)

    def FindDownload(self, target):
        return DCPluginSink.FindDownload(self._sink, target)

    def RemoveDownload(self, queueData):
        DCPluginSink.RemoveDownload(self._sink, queueData)

    def SetPriority(self, queueData, priority):
        DCPluginSink.SetPriority(self._sink, queueData, priority)

    def Pause(self, queueData):
        return DCPluginSink.Pause(self._sink, queueData)

    """ Tagger """
    def GetText(self, tagData):
        return DCPluginSink.GetText(self._sink, tagData)

    def AddTag(self, tagData, startPlace, endPlace, tagId, attributes):
        DCPluginSink.AddTag(
            self._sink, tagData, startPlace, endPlace, tagId, attributes
        )

    def ReplaceTagText(self, tagData, startPlace, endPlace, replacement):
        DCPluginSink.ReplaceTagText(
            self._sink, tagData, startPlace, endPlace, replacement
        )

    """ UI """
    def AddCommand(self, name):
        DCPluginSink.AddCommand(self._sink, name)

    def RemoveCommand(self, name):
        DCPluginSink.RemoveCommand(self._sink, name)

    def PlaySoundInUI(self, path):
        DCPluginSink.PlaySoundInUI(self._sink, path)

    def Notify(self, title, message):
        DCPluginSink.Notify(self._sink, title, message)
