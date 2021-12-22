/**
* This file consists of declarations for the Interactive class. 
* \file   Interactive.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include <iostream>
#include <string>

class Game;
class Interactive {
public:
    Interactive(const std::string &name, const std::string &description) : 
        useCount_(0), name_(name), description_(description) {}
    virtual ~Interactive() = default;
    
    const std::string& getName()        const { return name_; } ;
    const std::string& getDescription() const { return description_; };

    virtual void interact(Game&, std::ostream &os) { os << "Nothing happens."; }
    virtual void show(std::ostream &os) const      { os << description_; }

protected:
    unsigned useCount_;
    std::string name_;
    std::string description_;
};