
#include "stdafx.h"

#include "AssemblyManager.h"


dcapi::CAssemblyManager::CAssemblyManager(System::Collections::Generic::List<System::String^>^ searchPaths,
                     System::String^ assemblyName,
                     System::String^ className,
                     bool bAppDomain) :
    _searchPaths( searchPaths ),
    _assemblyName( assemblyName ),
    _className( className ),
    _bAppDomain( bAppDomain ),
    _domain( nullptr )
{
}

dcapi::CAssemblyManager::CAssemblyManager(System::Collections::Generic::List<System::String^>^ searchPaths,
                     System::String^ assemblyName,
                     bool bAppDomain) :
    _searchPaths( searchPaths ),
    _assemblyName( assemblyName ),
    _className( "" ),
    _bAppDomain( bAppDomain ),
    _domain( nullptr )
{
}

void dcapi::CAssemblyManager::Initialize()
{
    if( _bAppDomain )
    {
		// Create an appdomain where we keep the binary in.
		
		// The appdomain's name is irrelevant, it will simply be discarded later on anyway.
        System::String^ domainName = System::Guid::NewGuid().ToString();

		// Must store the domain so we can destroy it later on.
        _domain = System::AppDomain::CreateDomain( domainName );

        cli::array<System::Object^>^ args = gcnew cli::array<System::Object^>(1)
        { 
            _searchPaths
        };

        _resolver = (dcapi::CAssemblyResolver^)_domain->CreateInstanceAndUnwrap( 
            System::Reflection::Assembly::GetExecutingAssembly()->FullName, 
            gcnew System::String( L"dcapi.CAssemblyResolver" ), 
            false,
            System::Reflection::BindingFlags::Default,
            nullptr,
            args,
            nullptr,
            nullptr );

        _resolver->Initialize();

        _loader = (dcapi::CAssemblyLoader^)_domain->CreateInstanceAndUnwrap( 
            System::Reflection::Assembly::GetExecutingAssembly()->FullName, 
            gcnew System::String( L"dcapi.CAssemblyLoader" ), 
            false,
            System::Reflection::BindingFlags::Default,
            nullptr,
            args,
            nullptr,
            nullptr );
    }
    else
    {
        _resolver = gcnew dcapi::CAssemblyResolver(_searchPaths);
        _resolver->Initialize();
    }
}

void dcapi::CAssemblyManager::LoadAssembly(System::Object^% instance)
{
    _loader->LoadAssembly(_assemblyName, _className, instance );
}

void dcapi::CAssemblyManager::LoadAssembly(DCPlugin::DataTypes::PluginInformation^ pluginInfo, DCPlugin::DataTypes::INETPlugin^% dcPlugin)
{
    _loader->LoadAssembly(_assemblyName, _className, pluginInfo, dcPlugin );
}

void dcapi::CAssemblyManager::Destroy()
{
    if( _bAppDomain )
    {
        System::AppDomain::Unload( _domain );
        _domain = nullptr;
    }

    _resolver->Uninitialize();
    _resolver = nullptr;

    _loader = nullptr;
}