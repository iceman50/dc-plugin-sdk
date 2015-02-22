using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DCPlugin.DataTypes
{
    /// <summary>
    /// Tag path.
    /// </summary>
    public enum TagPathType
    {
        /// <summary>
        /// Global configuration
        /// </summary>
        GlobalConfig = 0,

        /// <summary>
        /// Per-user configuration (queue, favorites, ...)
        /// </summary>
        UserConfig,

        /// <summary>
        /// Per-user local data (cache, temp files, ...)
        /// </summary>
        UserLocal,

        /// <summary>
        /// Various resources (help files etc)
        /// </summary>
        Resources,

        /// <summary>
        /// Translations
        /// </summary>
        Locale
    }

    /// <summary>
    /// Indicates the protocol used.
    /// </summary>
    public enum ProtocolType
    {
        /// <summary>
        /// ADC
        /// </summary>
        ADC = 0,

        /// <summary>
        /// NMDC
        /// </summary>
        NMDC,

        /// <summary>
        /// DHT node (not used, reserved)
        /// </summary>
        DHT
    }

    /// <summary>
    /// The message type that will be used.
    /// </summary>
    public enum MessageType
    {
        /// <summary>
        /// General text style
        /// </summary>
	    Client = 0,

        /// <summary>
        /// Message in status bar
        /// </summary>
	    Status,

        /// <summary>
        /// Message with system message format
        /// </summary>
	    System
    }

    /// <summary>
    /// Queue priority.
    /// </summary>
    public enum QueuePriority
    {
        /// <summary>
        /// Default value (no priority).
        /// </summary>
        Default = -1,

        /// <summary>
        /// Lowest possible priority.
        /// </summary>
        Lowest = 1,

        /// <summary>
        /// Low priority.
        /// </summary>
        Low,

        /// <summary>
        /// Normal priority.
        /// </summary>
        Normal,

        /// <summary>
        /// High priority.
        /// </summary>
	    High,

        /// <summary>
        /// Highest priority.
        /// </summary>
	    Highest
    }

    /// <summary>
    /// Data type
    /// </summary>
    public enum DataType
    {
        /// <summary>
        /// Data type is unknown.
        /// </summary>
        Unknown = 0,

        /// <summary>
        /// String.
        /// </summary>
        String = 1,

        /// <summary>
        /// 8-bit integer.
        /// </summary>
        Byte = 2,

        /// <summary>
        /// 16-bit integer.
        /// </summary>
        Short = 3,

        /// <summary>
        /// 32-bit integer.
        /// </summary>
        Int = 4,

        /// <summary>
        /// 64-bit integer.
        /// </summary>
        Long = 5,

    }
}
