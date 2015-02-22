using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using DCPlugin.DataTypes;

namespace DCPlugin.SamplePlugin
{
    /// <summary>
    /// Sample plugin
    /// </summary>
    public class SamplePlugin : PluginBase
    {
        /// <inheritdoc />
        public override bool OnChatIncoming(HubData hubData, string data, ref bool bBreak)
        {
            base.LogMessage("OnChatIncoming: " + data);
            
            return base.OnChatIncoming(hubData, data, ref bBreak);
        }
    }
}
