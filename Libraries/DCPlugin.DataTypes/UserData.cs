using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DCPlugin.DataTypes
{
    /// <summary>
    /// User container.
    /// </summary>
    public class UserData
    {
        #region Constructors

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="nick">See Nick documentation.</param>
        /// <param name="hubUrl">See HubURL documentation.</param>
        /// <param name="cid">See CID documentation.</param>
        /// <param name="sid">See SID documentation.</param>
        /// <param name="protocol">See Protocol documentation.</param>
        /// <param name="isOp">See IsOperator documentation.</param>
        /// <param name="internalPointer">See InternalPointer documentation.</param>
        public UserData(string nick, string hubUrl, string cid, System.UInt32 sid, ProtocolType protocol, bool isOp, System.IntPtr internalPointer)
        {
            this.Nick = nick;
            this.HubURL = hubUrl;
            this.CID = cid;
            this.SID = sid;
            this.Protocol = protocol;
            this.IsOperator = isOp;
            this.InternalPointer = internalPointer;
        }

        #endregion

        #region Properties

        /// <summary>
        /// Users nick (only quaranteed to not be empty in NMDC environment)
        /// </summary>
        public string Nick
        {
            get;
            set;
        }
        
        /// <summary>
        /// Contains hub url to find the user from
        /// </summary>
        public string HubURL
        {
            get;
            set;
        }
        
        /// <summary>
        /// User CID
        /// </summary>
        public string CID
        {
            get;
            set;
        }
        
        /// <summary>
        /// User's SID in HubURL hub (only valid in ADC environment)
        /// </summary>
        public System.UInt32 SID
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
