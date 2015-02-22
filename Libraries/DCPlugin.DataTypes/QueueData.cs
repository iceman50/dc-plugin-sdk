using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DCPlugin.DataTypes
{
    /// <summary>
    /// Queue data container.
    /// </summary>
    public class QueueData
    {
        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="target">See Target documentation.</param>
        /// <param name="location">See Location documentation.</param>
        /// <param name="hash">See Hash documentation.</param>
        /// <param name="fileSize">See FileSize documentation</param>
        /// <param name="isFileList">See IsFileList documentation</param>
        /// <param name="internalPointer">See InternalPointer documentation</param>
        public QueueData(string target, string location, string hash, System.UInt64 fileSize, bool isFileList, System.IntPtr internalPointer)
        {
            this.Target = target;
            this.Location = location;
            this.Hash = hash;
            this.FileSize = fileSize;
            this.IsFileList = isFileList;
            this.InternalPointer = internalPointer;
        }

        /// <summary>
        /// The final location of the file.
        /// </summary>
        public string Target
        {
            get;
            private set;
        }

        /// <summary>
        /// The current location of the file (may be the same as target).
        /// </summary>
        public string Location
        {
            get;
            private set;
        }

        /// <summary>
        /// The hash of the file.
        /// </summary>
        public string Hash
        {
            get;
            private set;
        }

        /// <summary>
        /// The file size in bytes.
        /// </summary>
        public System.UInt64 FileSize
        {
            get;
            private set;
        }

        /// <summary>
        /// Whether this is a file list download or not.
        /// </summary>
        public bool IsFileList
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
