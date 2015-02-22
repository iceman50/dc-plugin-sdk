
#pragma once

#include <vcclr.h>

#include <string>

namespace dcapi {

public class CCommandReferrer
{
public:

    void Initialize(std::string name, std::string icon, DCPlugin::DataTypes::Delegates::CommandDelegate^ del);

private:

    void Callback();

private:

    std::string _name;
    gcroot<DCPlugin::DataTypes::Delegates::CommandDelegate^> _delegate;
};

}