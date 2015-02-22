
#include "stdafx.h"

#include "AssemblyLoader.h"
#include "NETPluginSink.h"

namespace dcapi {

void CAssemblyLoader::LoadAssembly( 
                       System::String^ assemblyName,
                       System::String^ className,
                       DCPlugin::DataTypes::PluginInformation^ pluginInfo,
                       DCPlugin::DataTypes::INETPlugin^% dcPlugin )
{
    System::Reflection::Assembly^ assembly = nullptr;

    try
    {
        assembly = System::Reflection::Assembly::Load( assemblyName );
    }
    catch( System::IO::FileNotFoundException^ )
    {
		return;
    }

    try
    {
        System::Object^ instance = nullptr;

        if( !System::String::IsNullOrEmpty( className ) )
        {
            try
            {
                instance = assembly->CreateInstance( className );
            }
            catch( System::TypeLoadException^ )
            {
                // Continue on anyway...
            }
        }

        if( instance == nullptr )
        {
            for each( System::Type^ type in assembly->GetExportedTypes() )
            {
                if( DCPlugin::DataTypes::INETPlugin::typeid->IsAssignableFrom( type ) )
                {
                    try
                    {
                        instance = assembly->CreateInstance( type->FullName );
                    }
                    catch( ... )
                    {

                    }
                }
            }
        }

        if( instance != nullptr )
        {
            if( DCPlugin::DataTypes::INETPlugin::typeid->IsAssignableFrom( instance->GetType() ) )
            {
                try
                {
                    dcPlugin = dynamic_cast< DCPlugin::DataTypes::INETPlugin^ >( instance );
                }
                catch( ... )
                {

                }
            }
        }
    }
    catch( System::Exception^)
    {
        return;
    }

    // Set up the sink and info
    if( dcPlugin != nullptr )
    {
        dcPlugin->Sink = gcnew CNETPluginSink();
        dcPlugin->Info = pluginInfo;
    }
}

void CAssemblyLoader::LoadAssembly( System::String^ assemblyName, System::String^ className, System::Object^% instance ) 
{
    System::Reflection::Assembly^ assembly = nullptr;

    try
    {
        assembly = System::Reflection::Assembly::Load( assemblyName );
    }
    catch( System::IO::FileNotFoundException^ )
    {
        return;
    }

    try
    {
        instance = nullptr;

        if( !System::String::IsNullOrEmpty( className ) )
        {
            try
            {
                instance = assembly->CreateInstance( className );
            }
            catch( System::TypeLoadException^ )
            {
                // Continue on anyway...
            }
        }
    }
    catch( System::Exception^)
    {
        return;
    }
}

}