using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DCPlugin.DataTypes
{
    /// <summary>
    /// Tag data container.
    /// </summary>
    public class TagData
    {
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="internalPointer">See InternalPointer documentation.</param>
        public TagData(System.IntPtr internalPointer)
        {
            this.InternalPointer = internalPointer;
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
