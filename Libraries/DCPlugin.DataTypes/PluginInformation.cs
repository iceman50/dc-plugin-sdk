using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DCPlugin.DataTypes
{
    /// <summary>
    /// Plugin information.
    /// </summary>
    public class PluginInformation
    {
        /// <summary>
        /// Constructor
        /// </summary>
        public PluginInformation()
        {
            Settings = new Dictionary<string, PluginSetting>();
        }

        /// <summary>
        /// Plugin name.
        /// </summary>
        public string Name 
        { 
            get; 
            set; 
        }

        /// <summary>
        /// Description of the plugin.
        /// </summary>
        public string Description
        {
            get;
            set;
        }

        /// <summary>
        /// Author of the plugin.
        /// </summary>
        public string Author
        {
            get;
            set;
        }

        /// <summary>
        /// Web page of the plugin.
        /// </summary>
        public string Web
        {
            get;
            set;
        }

        /// <summary>
        /// Version of the plugin.
        /// </summary>
        public double Version
        {
            get;
            set;
        }

        /// <summary>
        /// Version of the API used for the plugin.
        /// </summary>
        public System.UInt32 APIVersion
        {
            get;
            set;
        }

        /// <summary>
        /// UUID of plugin.
        /// </summary>
        public string UUID 
        { 
            get; 
            set; 
        }

        /// <summary>
        /// List of settings associated.
        /// </summary>
        public Dictionary<string, PluginSetting> Settings
        {
            get;
            set;
        }
    }
}
