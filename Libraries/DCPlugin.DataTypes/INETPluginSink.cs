using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DCPlugin.DataTypes
{
    /// <summary>
    /// Sink interface for .NET plugins.
    /// </summary>
    public interface INETPluginSink
    {
        #region Core

        /// <summary>
        /// Retrieve the application's name.
        /// </summary>
        /// <returns>Application name.</returns>
        string GetApplicationName();

        /// <summary>
        /// Set application name.
        /// </summary>
        /// <param name="name">New name.</param>
        void SetApplicationName(string name);

        #endregion

        #region Log

        /// <summary>
        /// Log a message.
        /// </summary>
        /// <param name="message">The message.</param>
        void LogMessage(string message);

        #endregion

        #region Config

        /// <summary>
        /// Get the path where the plugin is installed.
        /// </summary>
        /// <returns>The path where the plugin is.</returns>
        string GetInstallPath();

        /// <summary>
        /// Get path of the appropriate type.
        /// </summary>
        /// <param name="pathType">The type of path desired.</param>
        /// <returns>The path where the aformentioned type is.</returns>
        string GetPath(TagPathType pathType);

        /// <summary>
        /// Get configuration setting.
        /// </summary>
        /// <param name="name">Setting name.</param>
        /// <returns>Setting value.</returns>
        string GetConfig(string name);

        /// <summary>
        /// Set configuration setting.
        /// </summary>
        /// <param name="name">Setting name.</param>
        /// <param name="value">Setting value.</param>
        void SetConfig(string name, string value);

        /// <summary>
        /// Get configuration setting.
        /// </summary>
        /// <param name="name">Setting name.</param>
        /// <returns>Setting value.</returns>
        bool GetBoolConfig(string name);

        /// <summary>
        /// Set configuration setting.
        /// </summary>
        /// <param name="name">Setting name.</param>
        /// <param name="value">Setting value.</param>
        void SetConfig(string name, bool value);

        /// <summary>
        /// Get configuration setting.
        /// </summary>
        /// <param name="name">Setting name.</param>
        /// <returns>Setting value.</returns>
        System.Int32 GetIntConfig(string name);

        /// <summary>
        /// Set configuration setting.
        /// </summary>
        /// <param name="name">Setting name.</param>
        /// <param name="value">Setting value.</param>
        void SetConfig(string name, System.Int32 value);

        /// <summary>
        /// Get configuration setting.
        /// </summary>
        /// <param name="name">Setting name.</param>
        /// <returns>Setting value.</returns>
        System.Int64 GetLongConfig(string name);

        /// <summary>
        /// Set configuration setting.
        /// </summary>
        /// <param name="name">Setting name.</param>
        /// <param name="value">Setting value.</param>
        void SetConfig(string name, System.Int64 value);

        /// <summary>
        /// Return the language used by the host as an IETF language tag.
        /// </summary>
        /// <returns>The language tag.</returns>
        string GetLanguage();

        #endregion

        #region Connection

        /// <summary>
        /// Send raw UDP data on a specified port. 
        /// </summary>
        /// <param name="ipAddress">Address to send to.</param>
        /// <param name="port">Port to send to.</param>
        /// <param name="data">The data.</param>
        /// <param name="amount">Amount of data to send.</param>
        void SendUdpData(string ipAddress, System.UInt32 port, string data, System.UInt64 amount);

        /// <summary>
        /// Send a raw protocol command to a connection.
        /// </summary>
        /// <param name="connectionData">Connection identifier.</param>
        /// <param name="command">The command.</param>
        void SendProtocolCommand(ConnectionData connectionData, string command);

        /// <summary>
        /// Terminate a connection.
        /// </summary>
        /// <param name="connectionData">Connection identifier.</param>
        /// <param name="graceless">true if the connection should be terminated gracefully, otherwise false.</param>
        void TerminateConnection(ConnectionData connectionData, bool graceless);

        /// <summary>
        /// Get the user associated with the connection identifier.
        /// </summary>
        /// <param name="connectionData">Connection identifier.</param>
        /// <returns>The user associated.</returns>
        UserData GetConnectionUser(ConnectionData connectionData);

        #endregion

        #region Hub

        /// <summary>
        /// Connect to a hub.
        /// </summary>
        /// <param name="url">The URL of the hub.</param>
        /// <param name="nick">The nick name to use.</param>
        /// <param name="password">The password to use.</param>
        /// <returns>The resulting hub identifier data.</returns>
        HubData AddHub(string url, string nick, string password);

        /// <summary>
        /// Search for a hub based on an URL.
        /// </summary>
        /// <param name="url">The URL of the hub.</param>
        /// <returns>The resulting hub identifier data.</returns>
        HubData FindHub(string url);

        /// <summary>
        /// Disconnect from a hub (closing the tab etc for those hosts that have that).
        /// </summary>
        /// <param name="hubData">Hub identifier</param>
        void RemoveHub(HubData hubData);

        /// <summary>
        /// Emulate a raw protocol command to a hub.
        /// No actual data is sent to the hub, but the plugin will get a notification as if it was.
        /// </summary>
        /// <param name="hubData">Hub identifier.</param>
        /// <param name="command">The command to send.</param>
        void EmulateProtocolCommand(HubData hubData, string command);

        /// <summary>
        /// Send a raw protocol command to a hub.
        /// </summary>
        /// <param name="hubData">Hub identifier.</param>
        /// <param name="command">The command to send.</param>
        void SendProtocolCommand(HubData hubData, string command);

        /// <summary>
        /// Send a message to a hub.
        /// </summary>
        /// <param name="hubData">The hub to send to.</param>
        /// <param name="message">The message.</param>
        /// <param name="thirdPerson">true if the message should be sent in "third person", otherwise false.</param>
        void SendMessage(HubData hubData, string message, bool thirdPerson);

        /// <summary>
        /// Send a message to a hub, set a status message or as a system message.
        /// </summary>
        /// <param name="hubData">Hub identifier.</param>
        /// <param name="message">The message.</param>
        /// <param name="messageType">The message type.</param>
        void LocalMessage(HubData hubData, string message, MessageType messageType);

        /// <summary>
        /// Send a private message (PM) to a user.
        /// </summary>
        /// <param name="userData">The user to send to.</param>
        /// <param name="message">The message.</param>
        /// <param name="thirdPerson">true if the message should be sent in "third person", otherwise false.</param>
        void SendPrivateMessage(UserData userData, string message, bool thirdPerson);

        /// <summary>
        /// Search for a user based on the CID and the hub's URL.
        /// </summary>
        /// <param name="cid">The CID of the user.</param>
        /// <param name="hubURL">The URL of the hub.</param>
        /// <returns>The user.</returns>
        UserData FindUser(string cid, string hubURL);

        #endregion

        #region Queue

        /// <summary>
        /// Queue the file list for a user.
        /// </summary>
        /// <param name="userData">User identifier.</param>
        /// <param name="silent">true if the hosting application should not indicate that the file list is being downloaded and opened, otherwise false.</param>
        /// <returns>The queued file list item.</returns>
        QueueData AddList(UserData userData, bool silent);

        /// <summary>
        /// Queue a file.
        /// </summary>
        /// <param name="hash">The hash of the file.</param>
        /// <param name="size">The size of the file.</param>
        /// <param name="target">The path to the target.</param>
        /// <returns>The queued item.</returns>
        QueueData AddDownload(string hash, System.UInt64 size, string target);

        /// <summary>
        /// Search for a queued item based on the target path.
        /// </summary>
        /// <param name="target">The path of the queued item.</param>
        /// <returns>The queued item.</returns>
        QueueData FindDownload(string target);

        /// <summary>
        /// Remove an item from the queue.
        /// </summary>
        /// <param name="queueData">The queued item.</param>
        void RemoveDownload(QueueData queueData);

        /// <summary>
        /// Set a queued item's priority.
        /// </summary>
        /// <param name="queueData">The queued item.</param>
        /// <param name="priority">The new priority.</param>
        /// <returns>true if the operation succeeded, otherwise false.</returns>
        void SetPriority(QueueData queueData, QueuePriority priority);

        /// <summary>
        /// Set a queued item's status to Paused.
        /// </summary>
        /// <param name="queueData">The queued item.</param>
        /// <returns>true if the operation succeeded, otherwise false.</returns>
        bool Pause(QueueData queueData);

        #endregion

        #region Tagger

        /// <summary>
        /// Get text value from a tag identifier.
        /// </summary>
        /// <param name="tagData">Tag identifier.</param>
        /// <returns>Text value.</returns>
        string GetText(TagData tagData);

        /// <summary>
        /// Add a tag to the XML tagger.
        /// </summary>
        /// <param name="tagData">Tag data.</param>
        /// <param name="startPlace">Start location (index).</param>
        /// <param name="endPlace">Stop location (index)</param>
        /// <param name="id">Name of tag.</param>
        /// <param name="attributes">Attributes.</param>
        void AddTag(TagData tagData, System.UInt64 startPlace, System.UInt64 endPlace, string id, string attributes);

        /// <summary>
        /// Replace the value in a tag.
        /// </summary>
        /// <param name="tagData">Tag identifier.</param>
        /// <param name="startPlace">Start location (index).</param>
        /// <param name="endPlace">Stop location (index)</param>
        /// <param name="replacement">Replacement data.</param>
        void ReplaceTagText(TagData tagData, System.UInt64 startPlace, System.UInt64 endPlace, string replacement);

        #endregion

        #region UI

        /// <summary>
        /// Add a command with a callback function (delegate). The icon is optional and may be null.
        /// </summary>
        /// <param name="name"></param>
        /// <param name="command"></param>
        /// <param name="icon"></param>
        void AddCommand(string name, Delegates.CommandDelegate command, string icon);

        /// <summary>
        /// Remove a previously added command.
        /// </summary>
        /// <param name="name">Command name.</param>
        void RemoveCommand(string name);

        /// <summary>
        /// Play a sound in the UI.
        /// </summary>
        /// <param name="path">Path to a sound file.</param>
        void PlaySoundInUI(string path);

        /// <summary>
        /// Notify the user about something.
        /// </summary>
        /// <param name="title">Title of message.</param>
        /// <param name="message">The message.</param>
        void Notify(string title, string message);

        #endregion

    }
}
