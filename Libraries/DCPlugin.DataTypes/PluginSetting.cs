using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DCPlugin.DataTypes
{
    /// <summary>
    /// A plugin setting.
    /// </summary>
    public class PluginSetting
    {
        /// <summary>
        /// Name of the setting.
        /// </summary>
        public string Name
        {
            get;
            set;
        }

        /// <summary>
        /// Value of the setting.
        /// </summary>
        public object Value
        {
            get;
            set;
        }

        /// <summary>
        /// Default value of the setting.
        /// </summary>
        public object DefaultValue
        {
            get;
            set;
        }

        /// <summary>
        /// The data type of the value.
        /// </summary>
        public DataType DataType
        {
            get;
            set;
        }

        /// <summary>
        /// Description of the setting.
        /// </summary>
        public string Description
        {
            get;
            set;
        }

        /// <summary>
        /// Valid values for the setting.
        /// </summary>
        public string ValidValues
        {
            get;
            set;
        }
    }
}
