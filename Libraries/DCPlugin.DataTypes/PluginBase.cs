using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DCPlugin.DataTypes
{
    /// <summary>
    /// Class implementing the INETPlugin interface.
    /// </summary>
    public abstract class PluginBase : INETPlugin
    {
        #region Properties

        #endregion

        #region Constructors

        /// <summary>
        /// Constructor
        /// </summary>
        public PluginBase()
        {
            this.Info = new PluginInformation();
            this.Sink = null;
        }

        #endregion

        #region INETPlugin

        #region Properties

        /// <summary>
        /// Information about the plugin.
        /// </summary>
        public PluginInformation Info
        {
            get;
            set;
        }

        /// <summary>
        /// Callback sink.
        /// </summary>
        public INETPluginSink Sink
        {
            get;
            set;
        }

        #endregion

        #region Methods

        /// <inheritdoc />
        public virtual bool Initialize(bool install, bool runtime)
        {
            if (install)
            {
                // This only executes when the plugin has been installed for the first time.
            }

            if (runtime)
            {
                // If the plugin doesn't support being enabled at runtime, cancel its loading here.
            }

            return true;
        }

        /// <inheritdoc />
        public virtual void Uninitialize()
        {
        }

        #region Hooks

        #region Chat

        /// <inheritdoc />
        public virtual bool OnChatIncoming(HubData hubData, string data, ref bool bBreak)
        {
            return false;
        }

        /// <inheritdoc />
        public virtual bool OnChatOutgoing(HubData hubData, string data, ref bool bBreak)
        {
            return false;
        }

        /// <inheritdoc />
        public virtual bool OnChatIncomingPM(UserData userData, string data, ref bool bBreak)
        {
            return false;
        }

        /// <inheritdoc />
        public virtual bool OnChatOutgoingPM(UserData userData, string data, ref bool bBreak)
        {
            return false;
        }

        #endregion

        #region Timer

        /// <inheritdoc />
        public virtual bool OnTimerSecond(UInt64 data, ref bool bBreak)
        {
            return false;
        }

        /// <inheritdoc />
        public virtual bool OnTimerMinute(UInt64 data, ref bool bBreak)
        {
            return false;
        }

        #endregion

        #region Hubs

        /// <inheritdoc />
        public virtual bool OnHubOnline(HubData hubData, ref bool bBreak)
        {
            return false;
        }

        /// <inheritdoc />
        public virtual bool OnHubOffline(HubData hubData, ref bool bBreak)
        {
            return false;
        }

        #endregion

        #region Users

        /// <inheritdoc />
        public virtual bool OnUserOnline(UserData userData, ref bool bBreak)
        {
            return false;
        }

        /// <inheritdoc />
        public virtual bool OnUserOffline(UserData userData, ref bool bBreak)
        {
            return false;
        }

        #endregion

        #region Network

        /// <inheritdoc />
        public virtual bool OnNetworkHubDataIn(HubData hubData, string data, ref bool bBreak)
        {
            return false;
        }

        /// <inheritdoc />
        public virtual bool OnNetworkHubDataOut(HubData hubData, string data, ref bool bBreak)
        {
            return false;
        }

        /// <inheritdoc />
        public virtual bool OnNetworkClientDataIn(ConnectionData connectionData, string data, ref bool bBreak)
        {
            return false;
        }

        /// <inheritdoc />
        public virtual bool OnNetworkClientDataOut(ConnectionData connectionData, string data, ref bool bBreak)
        {
            return false;
        }

        /// <inheritdoc />
        public virtual bool OnNetworkUDPDataIn(UDPData udpData, string data, ref bool bBreak)
        {
            return false;
        }

        /// <inheritdoc />
        public virtual bool OnNetworkUDPDataOut(UDPData udpData, string data, ref bool bBreak)
        {
            return false;
        }

        #endregion

        #region Queue

        /// <inheritdoc />
        public virtual bool OnQueueAdded(QueueData queueData, ref bool bBreak)
        {
            return false;
        }

        /// <inheritdoc />
        public virtual bool OnQueueMoved(QueueData queueData, ref bool bBreak)
        {
            return false;
        }

        /// <inheritdoc />
        public virtual bool OnQueueRemoved(QueueData queueData, ref bool bBreak)
        {
            return false;
        }

        /// <inheritdoc />
        public virtual bool OnQueueFinished(QueueData queueData, ref bool bBreak)
        {
            return false;
        }

        #endregion

        #region UI

        /// <inheritdoc />
        public virtual bool OnUICreated(IntPtr data, ref bool bBreak)
        {
            return false;
        }

        /// <inheritdoc />
        public virtual bool OnUIChatTags(UserData userData, TagData tagData, ref bool bBreak)
        {
            return false;
        }

        /// <inheritdoc />
        public virtual bool OnUIChatDisplay(UserData userData, StringData stringData, ref bool bBreak)
        {
            return false;
        }

        /// <inheritdoc />
        public virtual bool OnUIChatCommand(HubData hubData, CommandData data, ref bool bBreak)
        {
            return false;
        }

        /// <inheritdoc />
        public virtual bool OnUIChatCommandPM(UserData userData, CommandData data, ref bool bBreak)
        {
            return false;
        }

        #endregion

        #endregion

        #endregion

        #endregion

        #region Methods

        /// <summary>
        /// Helper for logging an error that is an exceptional occurance.
        /// Note that messages will be prepended with the plugin name, an [ERROR] tag and the exception information.
        /// Ex: [MyPlugin] [ERROR] An unknown exception occured: text
        /// </summary>
        /// <param name="exceptionMessage">The exception</param>
        public void LogException(string exceptionMessage)
        {
            LogError("An unknown exception occured: " + exceptionMessage);
        }

        /// <summary>
        /// Helper for logging an exception and its stacktrace.
        /// Calls LogException with a 'logStacktrace' set to true.
        /// </summary>
        /// <param name="exception">The exception.</param>
        public void LogException(Exception exception)
        {
            LogException(exception, true);
        }

        /// <summary>
        /// Helper for logging an exception and its stacktrace.
        /// Implementatons can decide whether the stacktrace shall be logged as well or not.
        /// Note that messages will be prepended with the plugin name, an [ERROR] tag and the exception information.
        /// Ex: [MyPlugin] [ERROR] An exception occured: Null reference exception
        /// Ex: [MyPlugin] [ERROR] Stacktrace: ...
        /// </summary>
        /// <param name="exception">The exception.</param>
        /// <param name="logStacktrace">true if the stacktrace shall be logged, otherwise false.</param>
        public void LogException(Exception exception, bool logStacktrace)
        {
            LogError("An exception occured: " + exception.Message);

            if (logStacktrace)
            {
                LogError("Stacktrace: " + exception.StackTrace);
            }
        }

        /// <summary>
        /// Helper for logging an error.
        /// Note that messages will be prepended with the plugin name and an [ERROR] tag.
        /// Ex: [MyPlugin] [ERROR] message
        /// </summary>
        /// <param name="message">The message.</param>
        public void LogError(string message)
        {
            LogMessage("[ERROR] " + message);
        }

        /// <summary>
        /// Helper for logging a warning.
        /// Note that messages will be prepended with the plugin name and a [WARNING] tag.
        /// Ex: [MyPlugin] [WARNING] message
        /// </summary>
        /// <param name="message">The message.</param>
        public void LogWarning(string message)
        {
            LogMessage("[WARNING] " + message);
        }

        /// <summary>
        /// Helper for logging a message.
        /// Note that messages will be prepended with the plugin name.
        /// Ex: [MyPlugin] message
        /// </summary>
        /// <param name="message">The message.</param>
        public void LogMessage(string message)
        {
            this.Sink.LogMessage("[" + this.Info.Name + "] " + message);
        }

        #endregion
    }
}
