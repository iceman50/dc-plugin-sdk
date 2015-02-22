using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DCPlugin.DataTypes
{
    /// <summary>
    /// Meta data helpers
    /// </summary>
    public partial class MetaData
    {
        /// <summary>
        /// Parse a file to a MetaData struct.
        /// </summary>
        /// <param name="file">Path to a file.</param>
        /// <returns>The MetaData container.</returns>
        public static MetaData Parse(string file)
        {
            System.Xml.Serialization.XmlSerializer serializer = new System.Xml.Serialization.XmlSerializer(typeof(MetaData));
            MetaData resultingObject = (MetaData)serializer.Deserialize(System.Xml.XmlReader.Create(file));

            return resultingObject;
        }

        /// <summary>
        /// Get plugin information from meta data.
        /// </summary>
        /// <param name="data">The meta data.</param>
        /// <returns>PluginInformation container.</returns>
        public static PluginInformation GetPluginInformation(MetaData data)
        {
            PluginInformation pluginInfo = new PluginInformation();

            var metaDataPluginInformation = (MetaDataPluginInformation)data.Items[0];
            var metaDataSettings = (MetaDataSettings)data.Items[1];

            pluginInfo.Name = metaDataPluginInformation.Name;
            pluginInfo.Description = metaDataPluginInformation.Description;
            pluginInfo.Version = Convert.ToDouble(metaDataPluginInformation.Version);
            pluginInfo.UUID = metaDataPluginInformation.UUID;
            pluginInfo.Author = metaDataPluginInformation.Author;
            pluginInfo.APIVersion = Convert.ToUInt32(metaDataPluginInformation.ApiVersion);
            pluginInfo.Web = metaDataPluginInformation.Website;

            foreach (var setting in metaDataSettings.Setting)
            {
                var convertedSetting = GetPluginSetting(setting);
                pluginInfo.Settings.Add(convertedSetting.Name, convertedSetting);
            }

            return pluginInfo;
        }

        /// <summary>
        /// Get a plugin setting from the meta data struct.
        /// </summary>
        /// <param name="data">MetaDataSetting struct.</param>
        /// <returns>PluginSetting container.</returns>
        public static PluginSetting GetPluginSetting(MetaDataSettingsSetting data)
        {
            PluginSetting setting = new PluginSetting();

            setting.Name = data.Name;
            setting.Description = data.Description;
            setting.DataType = (DataType)Enum.Parse(typeof(DataType), data.DataType);

            switch (setting.DataType)
            {
                case DataType.Byte:
                    setting.Value = Convert.ToByte(data.Value);
                    setting.DefaultValue = Convert.ToByte(data.DefaultValue);
                    break;

                case DataType.Short:
                    setting.Value = Convert.ToUInt16(data.Value);
                    setting.DefaultValue = Convert.ToUInt16(data.DefaultValue);
                    break;

                case DataType.Int:
                    setting.Value = Convert.ToUInt32(data.Value);
                    setting.DefaultValue = Convert.ToUInt32(data.DefaultValue);
                    break;

                case DataType.Long:
                    setting.Value = Convert.ToUInt64(data.Value);
                    setting.DefaultValue = Convert.ToUInt64(data.DefaultValue);
                    break;

                case DataType.String:
                default:
                    setting.Value = data.Value;
                    setting.DefaultValue = data.DefaultValue;
                    break;
            }

            setting.ValidValues = data.ValidValues;

            if (setting.ValidValues == null)
            {
                setting.ValidValues = "";
            }

            return setting;
        }
    }
}
