
#include "stdafx.h"

#include "CommandReferrer.h"
#include "Marshalling.h"

#include "dcapi\UI.hpp"

#include <functional>

void dcapi::CCommandReferrer::Initialize(std::string name, std::string icon, DCPlugin::DataTypes::Delegates::CommandDelegate^ del)
{
    this->_name = name;
    this->_delegate = del;

    auto cmd = [this] { dcapi::CCommandReferrer::Callback(); };
    dcapi::UI::addCommand(name, cmd, icon);
}

void dcapi::CCommandReferrer::Callback()
{
    _delegate->Invoke();
}