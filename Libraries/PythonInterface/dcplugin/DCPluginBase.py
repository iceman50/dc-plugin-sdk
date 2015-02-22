
from .Enumerations import *
from .DataTypes import *
from .DCPluginSinkProxy import *
from .IDCPlugin import *
from .IDCPluginSink import *


class DCPluginBase(IDCPlugin):

    def __init__(self):
        self.info = PluginInformation()
        self.sink = None

    """ Methods """
    def Initialize(self, install, runtime):
        """ if install: """
        """ This only executes when the plugin has been installed for the first time. """

        """ if runtime: """
        """ If the plugin doesn't support being enabled at runtime, cancel its loading here. """

        return True

    def Uninitialize(self):
        return True

    def SetSink(self, paramSink):
        self.sink = DCPluginProxySink(paramSink)

    def SetPluginInfo(self, paramInfo):
        self.info = paramInfo

    """ Hooks """

    """ Chat """
    def OnChatIncoming(self, hubData, data):
        return False, False

    def OnChatOutgoing(self, hubData, data):
        return False, False

    def OnChatIncomingPM(self, userData, data):
        return False, False

    """ Timer """
    def OnTimerSecond(self, data):
        return False, False

    def OnTimerMinute(self, data):
        return False, False

    """ Hubs """
    def OnHubOnline(self, hubData):
        return False, False

    def OnHubOffline(self, hubData):
        return False, False

    """ Users """
    def OnUserOnline(self, userData):
        return False, False

    def OnUserOffline(self, userData):
        return False, False

    """ Network """
    def OnNetworkHubDataIn(self, hubData, data):
        return False, False

    def OnNetworkHubDataOut(self, hubData, data):
        return False, False

    def OnNetworkClientDataIn(self, connectionData, data):
        return False, False

    def OnNetworkClientDataOut(self, connectionData, data):
        return False, False

    def OnNetworkUDPDataIn(self, udpData, data):
        return False, False

    def OnNetworkUDPDataOut(self, udpData, data):
        return False, False

    """ Queue """
    def OnQueueAdded(self, queueData):
        return False, False

    def OnQueueMoved(self, queueData):
        return False, False

    def OnQueueRemoved(self, queueData):
        return False, False

    def OnQueueFinished(self, queueData):
        return False, False

    """ UI """
    def OnUICreated(self, data):
        return False, False

    def OnUIChatTags(self, userData, tagData):
        return False, False

    def OnUIChatDisplay(self, userData, stringData):
        return False, False

    def OnUIChatCommand(self, hubData, data):
        return False, False

    def OnUIChatCommandPM(self, userData, data):
        return False, False

    """ Methods """

    def LogException(self, exception, logStacktrace=True):
        if logStacktrace:
            self.LogError(
                "An exception occurred with stacktrace: " +
                exception.format_exc()
            )
        else:
            self.LogError(
                "An exception occurred: " +
                exception.format_exc()
            )

    def LogError(self, message):
        self.LogMessage("[ERROR] " + message)

    def LogWarning(self, message):
        self.LogMessage("[WARNING] " + message)

    def LogMessage(self, message):
        self.sink.LogMessage("[" + self.info.name + "] " + message)
