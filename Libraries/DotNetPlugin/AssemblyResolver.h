
#pragma once

namespace dcapi {

ref class CAssemblyResolver : System::MarshalByRefObject
{
public:

    CAssemblyResolver( System::Collections::Generic::List<System::String^>^ searchPaths );

public:

    void Initialize();

    void Uninitialize();

    System::Reflection::Assembly^ Resolver( System::Object^ sender, System::ResolveEventArgs^ args );

private:

    System::Collections::Generic::List<System::String^>^ _searchPaths;

};

}