
#pragma once

#include <vcclr.h>

#include "AssemblyLoader.h"
#include "AssemblyResolver.h"

namespace dcapi {

class CAssemblyManager
{
public:

    CAssemblyManager(System::Collections::Generic::List<System::String^>^ searchPaths,
                     System::String^ assemblyName,
                     System::String^ className,
                     bool bAppDomain);

    CAssemblyManager(System::Collections::Generic::List<System::String^>^ searchPaths,
                     System::String^ assemblyName,
                     bool bAppDomain);

public:

    void Initialize();
    void LoadAssembly(DCPlugin::DataTypes::PluginInformation^ pluginInfo, DCPlugin::DataTypes::INETPlugin^% dcPlugin);
    void LoadAssembly(System::Object^% instance);
    void Destroy();

private:

    gcroot<System::Collections::Generic::List<System::String^>^> _searchPaths;
    gcroot<System::String^> _assemblyName;
    gcroot<System::String^> _className;
    bool _bAppDomain;

    gcroot<System::AppDomain^> _domain;
    
    gcroot<dcapi::CAssemblyResolver^> _resolver;
    gcroot<dcapi::CAssemblyLoader^> _loader; // Don't need to initialize...

};

}