
from .DataTypes import *


class IDCPluginSink(object):

    """ Core """
    def GetApplicationName(self): raise NotImplementedError

    def SetApplicationName(self, name): raise NotImplementedError

    """ Log """
    def LogMessage(self, message): raise NotImplementedError

    """ Config """
    def GetInstallPath(self): raise NotImplementedError

    def GetPath(self, pathType): raise NotImplementedError

    def GetStringConfig(self, name): raise NotImplementedError
    def SetStringConfig(self, name, value): raise NotImplementedError

    def GetBoolConfig(self, name): raise NotImplementedError
    def SetBoolConfig(self, name, value): raise NotImplementedError

    def GetInt32Config(self, name): raise NotImplementedError
    def SetInt32Config(self, name, value): raise NotImplementedError

    def GetInt64Config(self, name): raise NotImplementedError
    def SetInt64Config(self, name, value): raise NotImplementedError

    def GetLanguage(self): raise NotImplementedError

    """ Connection """
    def SendUDPData(self, ipAddress, port, data, amount): raise NotImplementedError
    def SendProtocolCommandConnection(self, connectionData, command): raise NotImplementedError
    def TerminateConnection(self, connectionData, graceLess): raise NotImplementedError
    def GetConnectionUser(self, connectionData): raise NotImplementedError

    """ Hub """
    def AddHub(self, url, nick, password): raise NotImplementedError
    def FindHub(self, url): raise NotImplementedError
    def RemoveHub(self, hubData): raise NotImplementedError
    def EmulateProtocolCommandHub(self, hubData, command): raise NotImplementedError
    def SendProtocolCommand(self, hubData, command): raise NotImplementedError
    def SendMessage(self, hubData, message, thirdPerson): raise NotImplementedError
    def LocalMessage(self, hubData, message, messageType): raise NotImplementedError
    def SendPrivateMessage(self, userData, message, thirdPerson): raise NotImplementedError
    def FindUser(self, cid, hubURL): raise NotImplementedError

    """ Queue """
    def AddList(self, userData, silent): raise NotImplementedError
    def AddDownload(self, hashData, size, target): raise NotImplementedError
    def FindDownload(self, target): raise NotImplementedError
    def RemoveDownload(self, queueData): raise NotImplementedError
    def SetPriority(self, queueData, priority): raise NotImplementedError
    def Pause(self, queueData): raise NotImplementedError

    """ Tagger """
    def GetText(self, tagData): raise NotImplementedError
    def AddTag(self, tagData, startPlace, endPlace, tagId, attributes): raise NotImplementedError
    def ReplaceTagText(self, tagData, startPlace, endPlace, replacement): raise NotImplementedError

    """ UI """
    def AddCommand(self, name): raise NotImplementedError
    def RemoveCommand(self, name): raise NotImplementedError
    def PlaySoundInUI(self, path): raise NotImplementedError
    def Notify(self, title, message): raise NotImplementedError
