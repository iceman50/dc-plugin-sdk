using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DCPlugin.DataTypes
{
    /// <summary>
    /// String data container
    /// </summary>
    public class StringData
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="input">See Input documentation.</param>
        /// <param name="internalPointer">See InternalPointer documentation.</param>
        public StringData(string input, System.IntPtr internalPointer)
        {
            this.Input = input;
            this.Output = input;
            this.InternalPointer = internalPointer;
        }

        /// <summary>
        /// Input string.
        /// </summary>
        public string Input
        {
            get;
            private set;
        }

        /// <summary>
        /// Output (modified) string.
        /// </summary>
        public string Output
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
