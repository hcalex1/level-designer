/**
* This file consists of declarations for the Interactive class. 
* \file   Interactive.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include "Component.hpp"

#include <iostream>
#include <string>

class Game;
class Interactive : public Component {
public:
    Interactive(const std::string &name, const std::string &description) : 
        used_(false), Component(name, description) {}
    
    virtual void interact(Game&, std::ostream &os)     { os << "Nothing happens."; }
    virtual void show(std::ostream &os) const override { os << description_; }

protected:
    bool used_;
};