using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DCPlugin.DataTypes
{
    /// <summary>
    /// Interface for the .NET plugin
    /// </summary>
    public interface INETPlugin
    {
        #region Properties

        /// <summary>
        /// Information about the plugin.
        /// </summary>
        PluginInformation Info 
        { 
            get; 
            set; 
        }

        /// <summary>
        /// Callback sink.
        /// </summary>
        INETPluginSink Sink 
        { 
            get; 
            set; 
        }

        #endregion

        #region Methods

        /// <summary>
        /// Initialization of the plugin. 
        /// This is the first function called.
        /// </summary>
        /// <param name="install">Will be true when the plugin is installed (i.e. only first time use).</param>
        /// <param name="runtime">Will be true when the plugin is enabled at runtime.</param>
        /// <returns>true to continue loading the plugin, otherwise false..</returns>
        bool Initialize(bool install, bool runtime);

        /// <summary>
        /// Uninitialization of the plugin. 
        /// This is the last function called.
        /// </summary>
        void Uninitialize();

        #region Hooks

        #region Chat

        /// <summary>
        /// Callback for incoming chat.
        /// </summary>
        /// <param name="hubData">Hub identifier</param>
        /// <param name="data">The data</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnChatIncoming(HubData hubData, string data, ref bool bBreak);

        /// <summary>
        /// Callback for outgoing chat.
        /// </summary>
        /// <param name="hubData">Hub identifier</param>
        /// <param name="data">The data</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnChatOutgoing(HubData hubData, string data, ref bool bBreak);

        /// <summary>
        /// Callback for incoming chat in a Private Message (PM).
        /// </summary>
        /// <param name="userData">User identifier</param>
        /// <param name="data">The data</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnChatIncomingPM(UserData userData, string data, ref bool bBreak);

        /// <summary>
        /// Callback for outgoing chat in a Private Message (PM).
        /// </summary>
        /// <param name="userData">User identifier</param>
        /// <param name="data">The data</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnChatOutgoingPM(UserData userData, string data, ref bool bBreak);

        #endregion

        #region Timer

        /// <summary>
        /// Callback for a timer that runs every second.
        /// </summary>
        /// <param name="data">The time in seconds since the UNIX epoch.</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnTimerSecond(UInt64 data, ref bool bBreak);

        /// <summary>
        /// Callback for a timer that runs every minute.
        /// </summary>
        /// <param name="data">The time in seconds since the UNIX epoch.</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnTimerMinute(UInt64 data, ref bool bBreak);

        #endregion

        #region Hubs

        /// <summary>
        /// Callback for when a hub goes online.
        /// </summary>
        /// <param name="hubData">Hub identifier</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnHubOnline(HubData hubData, ref bool bBreak);

        /// <summary>
        /// Callback for when a hub goes offline.
        /// </summary>
        /// <param name="hubData">Hub identifier</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnHubOffline(HubData hubData, ref bool bBreak);

        #endregion

        #region Users

        /// <summary>
        /// Callback for when a user goes online.
        /// </summary>
        /// <param name="userData">User identifier</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnUserOnline(UserData userData, ref bool bBreak);

        /// <summary>
        /// Callback for when a user goes offline.
        /// </summary>
        /// <param name="userData">User identifier</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnUserOffline(UserData userData, ref bool bBreak);

        #endregion

        #region Network

        /// <summary>
        /// Callback for network data from a hub.
        /// </summary>
        /// <param name="hubData">Hub identifier.</param>
        /// <param name="data">Data.</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnNetworkHubDataIn(HubData hubData, string data, ref bool bBreak);

        /// <summary>
        /// Callback for network data to a hub.
        /// </summary>
        /// <param name="hubData">Hub identifier.</param>
        /// <param name="data">Data.</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnNetworkHubDataOut(HubData hubData, string data, ref bool bBreak);

        /// <summary>
        /// Callback for network data from a client.
        /// </summary>
        /// <param name="connectionData">Client identifier.</param>
        /// <param name="data">Data.</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnNetworkClientDataIn(ConnectionData connectionData, string data, ref bool bBreak);

        /// <summary>
        /// Callback for network data to a client.
        /// </summary>
        /// <param name="connectionData">Client identifier.</param>
        /// <param name="data">Data.</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnNetworkClientDataOut(ConnectionData connectionData, string data, ref bool bBreak);

        /// <summary>
        /// Callback for network data from a UDP packet.
        /// </summary>
        /// <param name="udpData">Packet identifier.</param>
        /// <param name="data">Data.</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnNetworkUDPDataIn(UDPData udpData, string data, ref bool bBreak);

        /// <summary>
        /// Callback for network data from a UDP packet.
        /// </summary>
        /// <param name="udpData">Packet identifier.</param>
        /// <param name="data">Data.</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnNetworkUDPDataOut(UDPData udpData, string data, ref bool bBreak);

        #endregion

        #region Queue

        /// <summary>
        /// Callback for a item that has been added to the queue.
        /// </summary>
        /// <param name="queueData">The queued item.</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnQueueAdded(QueueData queueData, ref bool bBreak);

        /// <summary>
        /// Callback for a item that has been moved in the queue.
        /// </summary>
        /// <param name="queueData">The queued item.</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnQueueMoved(QueueData queueData, ref bool bBreak);

        /// <summary>
        /// Callback for a item that has been removed from the queue.
        /// </summary>
        /// <param name="queueData">The queued item.</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnQueueRemoved(QueueData queueData, ref bool bBreak);

        /// <summary>
        /// Callback for a item that has been finished.
        /// </summary>
        /// <param name="queueData">The queued item.</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnQueueFinished(QueueData queueData, ref bool bBreak);

        #endregion

        #region UI

        /// <summary>
        /// Callback for notification when a window has been created.
        /// The 'data' is a pointer to a HWND in C++. This pointer can be used by implemetators in conjunction with
        /// System.Windows.Forms.Control.FromHandle() in the System.Windows.Forms assembly.
        /// The 'data' parameter can be passed to the function and a System.Windows.Forms.Control will be the result.
        /// This Control can then subsequently be used.
        /// </summary>
        /// <param name="data">A pointer to a HWND.</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnUICreated(IntPtr data, ref bool bBreak);

        /// <summary>
        /// Callback for chat message tags before tag merging.
        /// </summary>
        /// <param name="userData">User identifier. Note that this may be null.</param>
        /// <param name="tagData">Tag data identifier.</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnUIChatTags(UserData userData, TagData tagData, ref bool bBreak);

        /// <summary>
        /// Callback for chat messages before they are displayed in the chat.
        /// </summary>
        /// <param name="userData">User identifier. Note that this may be null.</param>
        /// <param name="stringData">The data to potentially modify.</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnUIChatDisplay(UserData userData, StringData stringData, ref bool bBreak);

        /// <summary>
        /// Callback for client side commands in a hub chat.
        /// </summary>
        /// <param name="hubData">Hub identifier.</param>
        /// <param name="data">The command data.</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnUIChatCommand(HubData hubData, CommandData data, ref bool bBreak);

        /// <summary>
        /// Callback for client side commands in a private message (PM) chat 
        /// </summary>
        /// <param name="userData">User identifier.</param>
        /// <param name="data">The command data.</param>
        /// <param name="bBreak"></param>
        /// <returns>true if any further processing shall be blocked for other plugins (and the host application), otherwise false.</returns>
        bool OnUIChatCommandPM(UserData userData, CommandData data, ref bool bBreak);

        #endregion

        #endregion

        #endregion
    }
}
