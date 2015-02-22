
#pragma once

namespace dcapi {

ref class CAssemblyLoader : System::MarshalByRefObject
{

public:

    void LoadAssembly( System::String^ assemblyName,
                       System::String^ className,
                       DCPlugin::DataTypes::PluginInformation^ pluginInfo,
                       DCPlugin::DataTypes::INETPlugin^% dcPlugin );

    void LoadAssembly( System::String^ assemblyName,
                       System::String^ className,
                       System::Object^% instance );

};

}