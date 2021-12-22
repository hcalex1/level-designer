/**
* This file consists of declarations for the Interactive class. 
* \file   Interactive.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include "Lookable.hpp"

#include <iostream>
#include <string>

class Game;
class Interactive : public Lookable {
public:
    Interactive(const std::string &name, const std::string &description, 
        const std::string &useText = "Nothing happens.") :
        Lookable(name, description), useText_(useText), used_(false) {}
    
    virtual void interact(Game&, std::ostream &os)     { os << useText_ << std::endl; }
    virtual void show(std::ostream &os) const override { os << description_; }

protected:
    std::string useText_;
    bool used_;
};