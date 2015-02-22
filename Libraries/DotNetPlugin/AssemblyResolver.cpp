
#include "stdafx.h"

#include "AssemblyResolver.h"

namespace dcapi {

CAssemblyResolver::CAssemblyResolver(System::Collections::Generic::List<System::String^>^ searchPaths)
{
    _searchPaths = searchPaths;
}

void CAssemblyResolver::Initialize()
{
    System::AppDomain::CurrentDomain->AssemblyResolve += gcnew System::ResolveEventHandler( this, &CAssemblyResolver::Resolver );
}

void CAssemblyResolver::Uninitialize()
{
    System::AppDomain::CurrentDomain->AssemblyResolve -= gcnew System::ResolveEventHandler( this, &CAssemblyResolver::Resolver );
}

System::Reflection::Assembly^ CAssemblyResolver::Resolver( System::Object^ /*sender*/, System::ResolveEventArgs^ args )
{
    System::String^ assemblyName = args->Name;

    // Strip irrelevant information, such as assembly, version etc.
    // Example: "DCPlugin.DataTypes, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null"
    if( assemblyName->Contains(",") ) 
    {
        assemblyName = assemblyName->Substring(0, assemblyName->IndexOf(","));
    }

	// Make sure the binary name ends in ".dll"
    if( !assemblyName->ToLower()->EndsWith( ".dll" ) )
    {
        assemblyName += gcnew System::String( ".dll" );
    }

    for each( System::String^ path in _searchPaths )
    {
        System::String^ assemblyPath = System::IO::Path::Combine( path, assemblyName );
        if( System::IO::File::Exists( assemblyPath ) )
        {
            return System::Reflection::Assembly::LoadFrom( assemblyPath );
        }
    }

    return nullptr;
}

}