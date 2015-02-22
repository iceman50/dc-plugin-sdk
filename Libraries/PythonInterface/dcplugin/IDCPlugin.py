
from .DataTypes import *
from .IDCPluginSink import *


class IDCPlugin(object):

    """ Methods """
    def Initialize(self, install, runtime):
        """ Initialization of the plugin.
            install is True only when the plugin is installed for the first time. """
        raise NotImplementedError

    def Uninitialize(self):
        """ Uninitialization of the plugin.
            Clean up any resources here.
            No further calls to the sink etc are allowed. """
        raise NotImplementedError

    def SetSink(self, sink):
        """ For the Python marshalling plugin. Do not implement."""
        raise NotImplementedError
    def SetPluginInfo(self, paramInfo):
        """ For the Python marshalling plugin. Do not implement."""
        raise NotImplementedError

    """ Hooks """

    """ Chat """
    def OnChatIncoming(self, hubData, data):
        """ Callback for incoming chat.
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError
    def OnChatOutgoing(self, hubData, data):
        """ Callback for outgoing chat.
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError
    def OnChatIncomingPM(self, userData, data):
        """ Callback for incoming chat in a Private Message (PM).
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError
    def OnChatOutgoingPM(self, userData, data):
        """ Callback for outgoing chat in a Private Message (PM).
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError

    """ Timer """
    def OnTimerSecond(self, data):
        """ Callback for a timer that runs every second.
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError
    def OnTimerMinute(self, data):
        """ Callback for a timer that runs every minute.
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError

    """ Hubs """
    def OnHubOnline(self, hubData):
        """ Callback for when a hub goes online.
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError
    def OnHubOffline(self, hubData):
        """ Callback for when a hub goes offline.
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError

    """ Users """
    def OnUserOnline(self, userData):
        """ Callback for when a user goes online.
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError
    def OnUserOffline(self, userData):
        """ Callback for when a user goes offline.
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError

    """ Network """
    def OnNetworkHubDataIn(self, hubData, data):
        """ Callback for network data from a hub.
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError
    def OnNetworkHubDataOut(self, hubData, data):
        """ Callback for network data to a hub.
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError
    def OnNetworkClientDataIn(self, connectionData, data):
        """ Callback for network data from a client.
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError
    def OnNetworkClientDataOut(self, connectionData, data):
        """ Callback for network data to a client.
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError
    def OnNetworkUDPDataIn(self, udpData, data):
        """ Callback for network data from a UDP packet.
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError
    def OnNetworkUDPDataOut(self, udpData, data):
        """ Callback for network data from a UDP packet.
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError

    """ Queue """
    def OnQueueAdded(self, queueData):
        """ Callback for a item that has been added to the queue.
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError
    def OnQueueMoved(self, queueData):
        """ Callback for a item that has been moved in the queue.
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError
    def OnQueueRemoved(self, queueData):
        """ Callback for a item that has been removed from the queue.
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError
    def OnQueueFinished(self, queueData):
        """ Callback for a item that has been finished.
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError

    """ UI """
    def OnUICreated(self, data):
        raise NotImplementedError
    def OnUIChatTags(self, userData, tagData):
        """ Callback for chat message tags before tag merging.
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError
    def OnUIChatDisplay(self, userData, stringData):
        """ Callback for chat messages before they are displayed in the chat.
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError
    def OnUIChatCommand(self, hubData, data):
        """ Callback for client side commands in a hub chat.
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError
    def OnUIChatCommandPM(self, userData, data):
        """ Callback for client side commands in a private message (PM) chat.
            Return value should be a tuple of two bools:
            first denoting if the call was successfull and
            the second if further processing shall be blocked for other plugins. """
        raise NotImplementedError
