using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DCPlugin.DataTypes
{
    /// <summary>
    /// Command container.
    /// </summary>
    public class CommandData
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="command">Command name.</param>
        /// <param name="parameters">Command parameters.</param>
        /// <param name="internalPointer">See InternalPointer documentation</param>
        public CommandData(string command, string parameters, System.IntPtr internalPointer)
        {
            this.Command = command;
            this.Parameters = parameters;
            this.InternalPointer = internalPointer;
        }

        /// <summary>
        /// Command name.
        /// </summary>
        public string Command
        {
            get;
            private set;
        }

        /// <summary>
        /// Command parameters.
        /// </summary>
        public string Parameters
        {
            get;
            private set;
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
