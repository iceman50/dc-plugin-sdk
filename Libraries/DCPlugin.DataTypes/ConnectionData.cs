using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DCPlugin.DataTypes
{
    /// <summary>
    /// Connection data.
    /// </summary>
    public class ConnectionData
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="ip">See IP documentation.</param>
        /// <param name="port">See Port documentation.</param>
        /// <param name="protocol">See Protocol documentation.</param>
        /// <param name="isOp">See IsOperator documentation.</param>
        /// <param name="isEncrypted">See IsEncrypted documentation.</param>
        /// <param name="internalPointer">See InternalPointer documentation.</param>
        public ConnectionData(string ip, System.UInt16 port, ProtocolType protocol, bool isOp, bool isEncrypted, System.IntPtr internalPointer)
        {
            this.IP = ip;
            this.Port = port;
            this.Protocol = protocol;
            this.IsOperator = isOp;
            this.IsEncrypted = isEncrypted;
            this.InternalPointer = internalPointer;
        }

        #region Properties

        /// <summary>
        /// Remote IP address.
        /// </summary>
        public string IP
        {
            get;
            set;
        }

        /// <summary>
        /// Hub port.
        /// </summary>
        public System.UInt16 Port
        {
            get;
            set;
        }

        /// <summary>
        /// The protocol used.
        /// </summary>
        public ProtocolType Protocol
        {
            get;
            set;
        }

        /// <summary>
        /// Whether the user is operator in the hub or not.
        /// </summary>
        public bool IsOperator
        {
            get;
            set;
        }

        /// <summary>
        /// Whether this is a TLS encrypted connection.
        /// </summary>
        public bool IsEncrypted
        {
            get;
            set;
        }

        /// <summary>
        /// Internal pointer value. Do not modify.
        /// </summary>
        public System.IntPtr InternalPointer
        {
            get;
            private set;
        }

        #endregion
    }
}
