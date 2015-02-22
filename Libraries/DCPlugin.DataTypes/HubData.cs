using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DCPlugin.DataTypes
{
    /// <summary>
    /// Hub container.
    /// </summary>
    public class HubData
    {
        #region Constructors

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="url">See URL documentation.</param>
        /// <param name="ip">See IP documentation.</param>
        /// <param name="port">See Port documentation.</param>
        /// <param name="protocol">See Protocol documentation.</param>
        /// <param name="isOperator">See IsOperator documentation.</param>
        /// <param name="isEncrypted">See IsEncrypted documentation.</param>
        /// <param name="internalPointer">See InternalPointer documentation.</param>
        public HubData(string url, string ip, System.UInt16 port, ProtocolType protocol, bool isOperator, bool isEncrypted, System.IntPtr internalPointer)
        {
            this.Url = url;
            this.IP = ip;
            this.Port = port;
            this.Protocol = protocol;
            this.IsOperator = isOperator;
            this.IsEncrypted = isEncrypted;
            this.InternalPointer = internalPointer;
        }

        #endregion

        #region Properties

        /// <summary>
        /// Hub URL address.
        /// </summary>
        public string Url
        {
            get;
            set;
        }

        /// <summary>
        /// Hub ip address.
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
        /// Whether we are operator on this hub or not.
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
