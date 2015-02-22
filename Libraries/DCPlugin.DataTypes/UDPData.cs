using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DCPlugin.DataTypes
{
    /// <summary>
    /// UDP data container.
    /// </summary>
    public class UDPData
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="remoteAddress">See RemoteAddress documentation.</param>
        /// <param name="port">See Port documentation.</param>
        /// <param name="internalPointer">See InternalPointer documentation.</param>
        public UDPData(string remoteAddress, System.UInt16 port, System.IntPtr internalPointer)
        {
            this.RemoteAddress = remoteAddress;
            this.Port = port;
            this.InternalPointer = internalPointer;
        }

        /// <summary>
        /// The (remote) IP address of the connection.
        /// </summary>
        public string RemoteAddress
        {
            get;
            set;
        }

        /// <summary>
        /// The port.
        /// </summary>
        public System.UInt16 Port
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
    }
}
