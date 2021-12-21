/**
* This file consists of declarations for the Object class. 
* \file   Object.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include <iostream>
#include <string>
#include <functional>

class Game;
class Object {
public:
    Object() = default;
    Object(const std::string&, const std::string&); 
    
    const std::string& getName() const;
    const std::string& getDescription() const ;

    void setInteract(const std::function<void(Game&, unsigned, std::ostream&)> interactFunction); 

    void interact(Game&, std::ostream&);
    void show(std::ostream&) const;

private:
    std::string name_;
    std::string description_;
    unsigned useCount_;
    std::function<void(Game&, unsigned, std::ostream&)> interactFunction_;

    static std::function<void(Game&, unsigned, std::ostream&)> noInteract_;
};
