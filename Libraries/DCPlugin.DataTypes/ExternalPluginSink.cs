using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.CompilerServices;

namespace DCPlugin.DataTypes
{
    /// <summary>
    /// Sink for external use (e.g. Mono)
    /// </summary>
    public class ExternalPluginSink : INETPluginSink
    {
        #region Members

        private byte _instanceId;

        #endregion

        #region Constructors

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="instanceId">Instance id to pass to the external interface.</param>
        public ExternalPluginSink(byte instanceId)
        {
            _instanceId = instanceId;
        }

        #endregion

        #region INETPluginSink

        #region Core

        /// <inheritdoc />
        public virtual string GetApplicationName()
        {
            return ExternalGetApplicationName(_instanceId);
        }

        /// <inheritdoc />
        public virtual void SetApplicationName(string name)
        {
            ExternalSetApplicationName(name, _instanceId);
        }

        #endregion

        #region Log

        /// <inheritdoc />
        public virtual void LogMessage(string message)
        {
            ExternalLogMessage(message, _instanceId);
        }

        #endregion

        #region Config

        /// <inheritdoc />
        public virtual string GetInstallPath()
        {
            return ExternalGetInstallPath(_instanceId);
        }

        /// <inheritdoc />
        public virtual string GetPath(TagPathType pathType)
        {
            return ExternalGetPath(pathType, _instanceId);
        }

        /// <inheritdoc />
        public virtual string GetConfig(string name)
        {
            return ExternalGetConfig(name, _instanceId);
        }

        /// <inheritdoc />
        public virtual void SetConfig(string name, string value)
        {
            ExternalSetConfig(name, value, _instanceId);
        }

        /// <inheritdoc />
        public virtual bool GetBoolConfig(string name)
        {
            return ExternalGetBoolConfig(name, _instanceId);
        }

        /// <inheritdoc />
        public virtual void SetConfig(string name, bool value)
        {
            ExternalSetBoolConfig(name, value, _instanceId);
        }

        /// <inheritdoc />
        public virtual System.Int32 GetIntConfig(string name)
        {
            return ExternalGetIntConfig(name, _instanceId);
        }

        /// <inheritdoc />
        public virtual void SetConfig(string name, System.Int32 value)
        {
            ExternalSetIntConfig(name, value, _instanceId);
        }

        /// <inheritdoc />
        public virtual System.Int64 GetLongConfig(string name)
        {
            return ExternalGetLongConfig(name, _instanceId);
        }

        /// <inheritdoc />
        public virtual void SetConfig(string name, System.Int64 value)
        {
            ExternalSetLongConfig(name, value, _instanceId);
        }

        /// <inheritdoc />
        public virtual string GetLanguage()
        {
            return ExternalGetLanguage(_instanceId);
        }

        #endregion

        #region Connection

        /// <inheritdoc />
        public virtual void SendUdpData(string ipAddress, System.UInt32 port, string data, System.UInt64 amount)
        {
            ExternalSendUdpData(ipAddress, port, data, amount, _instanceId);
        }

        /// <inheritdoc />
        public virtual void SendProtocolCommand(ConnectionData connectionData, string command)
        {
            ExternalSendProtocolCommandConnection(connectionData, command, _instanceId);
        }

        /// <inheritdoc />
        public virtual void TerminateConnection(ConnectionData connectionData, bool graceless)
        {
            ExternalTerminateConnection(connectionData, graceless, _instanceId);
        }

        /// <inheritdoc />
        public virtual UserData GetConnectionUser(ConnectionData connectionData)
        {
            return ExternalGetConnectionUser(connectionData, _instanceId);
        }

        #endregion

        #region Hub

        /// <inheritdoc />
        public virtual HubData AddHub(string url, string nick, string password)
        {
            return ExternalAddHub(url, nick, password, _instanceId);
        }

        /// <inheritdoc />
        public virtual HubData FindHub(string url)
        {
            return ExternalFindHub(url, _instanceId);
        }

        /// <inheritdoc />
        public virtual void RemoveHub(HubData hubData)
        {
            ExternalRemoveHub(hubData, _instanceId);
        }

        /// <inheritdoc />
        public virtual void EmulateProtocolCommand(HubData hubData, string command)
        {
            ExternalEmulateProtocolCommand(hubData, command, _instanceId);
        }

        /// <inheritdoc />
        public virtual void SendProtocolCommand(HubData hubData, string command)
        {
            ExternalSendProtocolCommandHub(hubData, command, _instanceId);
        }

        /// <inheritdoc />
        public virtual void SendMessage(HubData hubData, string message, bool thirdPerson)
        {
            ExternalSendMessage(hubData, message, thirdPerson, _instanceId);
        }

        /// <inheritdoc />
        public virtual void LocalMessage(HubData hubData, string message, MessageType messageType)
        {
            ExternalLocalMessage(hubData, message, messageType, _instanceId);
        }

        /// <inheritdoc />
        public virtual void SendPrivateMessage(UserData userData, string message, bool thirdPerson)
        {
            ExternalSendPrivateMessage(userData, message, thirdPerson, _instanceId);
        }

        /// <inheritdoc />
        public virtual UserData FindUser(string cid, string hubURL)
        {
            return ExternalFindUser(cid, hubURL, _instanceId);
        }

        #endregion

        #region Queue

        /// <inheritdoc />
        public virtual QueueData AddList(UserData userData, bool silent)
        {
            return ExternalAddList(userData, silent, _instanceId);
        }

        /// <inheritdoc />
        public virtual QueueData AddDownload(string hash, System.UInt64 size, string target)
        {
            return ExternalAddDownload(hash, size, target, _instanceId);
        }

        /// <inheritdoc />
        public virtual QueueData FindDownload(string target)
        {
            return ExternalFindDownload(target, _instanceId);
        }

        /// <inheritdoc />
        public virtual void RemoveDownload(QueueData queueData)
        {
            ExternalRemoveDownload(queueData, _instanceId);
        }

        /// <inheritdoc />
        public virtual void SetPriority(QueueData queueData, QueuePriority priority)
        {
            ExternalSetPriority(queueData, priority, _instanceId);
        }

        /// <inheritdoc />
        public virtual bool Pause(QueueData queueData)
        {
            return ExternalPause(queueData, _instanceId);
        }

        #endregion

        #region Tagger

        /// <inheritdoc />
        public virtual string GetText(TagData tagData)
        {
            return ExternalGetText(tagData, _instanceId);
        }

        /// <inheritdoc />
        public virtual void AddTag(TagData tagData, System.UInt64 startPlace, System.UInt64 endPlace, string id, string attributes)
        {
            ExternalAddTag(tagData, startPlace, endPlace, id, attributes, _instanceId);
        }

        /// <inheritdoc />
        public virtual void ReplaceTagText(TagData tagData, System.UInt64 startPlace, System.UInt64 endPlace, string replacement)
        {
            ExternalReplaceTagText(tagData, startPlace, endPlace, replacement, _instanceId);
        }

        #endregion

        #region UI

        /// <inheritdoc />
        public virtual void AddCommand(string name, Delegates.CommandDelegate command, string icon)
        {
            ExternalAddCommand(name, command, icon, _instanceId);
        }

        /// <inheritdoc />
        public virtual void RemoveCommand(string name)
        {
            ExternalRemoveCommand(name, _instanceId);
        }

        /// <inheritdoc />
        public virtual void PlaySoundInUI(string path)
        {
            ExternalPlaySoundInUI(path, _instanceId);
        }

        /// <inheritdoc />
        public virtual void Notify(string title, string message)
        {
            ExternalNotify(title, message, _instanceId);
        }

        #endregion

        #endregion

        #region External InternalCall management

        #region Core

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern string ExternalGetApplicationName(byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalSetApplicationName(string name, byte instanceId);

        #endregion

        #region Log

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalLogMessage(string message, byte instanceId);

        #endregion

        #region Config

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern string ExternalGetInstallPath(byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern string ExternalGetPath(TagPathType pathType, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern string ExternalGetConfig(string name, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalSetConfig(string name, string value, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern bool ExternalGetBoolConfig(string name, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalSetBoolConfig(string name, bool value, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern System.Int32 ExternalGetIntConfig(string name, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalSetIntConfig(string name, System.Int32 value, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern System.Int64 ExternalGetLongConfig(string name, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalSetLongConfig(string name, System.Int64 value, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern string ExternalGetLanguage(byte instanceId);

        #endregion

        #region Connection

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalSendUdpData(string ipAddress, System.UInt32 port, string data, System.UInt64 amount, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalSendProtocolCommandConnection(ConnectionData connectionData, string command, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalTerminateConnection(ConnectionData connectionData, bool graceless, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern UserData ExternalGetConnectionUser(ConnectionData connectionData, byte instanceId);

        #endregion

        #region Hub

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern HubData ExternalAddHub(string url, string nick, string password, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern HubData ExternalFindHub(string url, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalRemoveHub(HubData hubData, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalEmulateProtocolCommand(HubData hubData, string command, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalSendProtocolCommandHub(HubData hubData, string command, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalSendMessage(HubData hubData, string message, bool thirdPerson, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalLocalMessage(HubData hubData, string message, MessageType messageType, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalSendPrivateMessage(UserData userData, string message, bool thirdPerson, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern UserData ExternalFindUser(string cid, string hubURL, byte instanceId);

        #endregion

        #region Queue

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern QueueData ExternalAddList(UserData userData, bool silent, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern QueueData ExternalAddDownload(string hash, System.UInt64 size, string target, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern QueueData ExternalFindDownload(string target, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalRemoveDownload(QueueData queueData, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalSetPriority(QueueData queueData, QueuePriority priority, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern bool ExternalPause(QueueData queueData, byte instanceId);

        #endregion

        #region Tagger

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern string ExternalGetText(TagData tagData, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalAddTag(TagData tagData, System.UInt64 startPlace, System.UInt64 endPlace, string id, string attributes, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalReplaceTagText(TagData tagData, System.UInt64 startPlace, System.UInt64 endPlace, string replacement, byte instanceId);

        #endregion

        #region UI

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalAddCommand(string name, Delegates.CommandDelegate command, string icon, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalRemoveCommand(string name, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalPlaySoundInUI(string path, byte instanceId);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void ExternalNotify(string title, string message, byte instanceId);

        #endregion

        #endregion
    }
}
