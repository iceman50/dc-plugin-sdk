import dcplugin


class MyPlugin(dcplugin.DCPluginBase):

    def __init__(self):
        """This initializer is important, even if it doesn't do anything! Its
        absence leads to crashes...
        """
        pass

    def OnChatIncoming(self, hubData, paramData):
        if paramData == "test":
            self.LogMessage("Test? Here's a test for you. In Python!")
            self.sink.SendMessage(
                hubData,
                "Python Test? Here's a test for you. In Python!",
                False
            )

        # Note: "super" doesn't work here.
        return dcplugin.DCPluginBase.OnChatIncoming(self,hubData, paramData)
