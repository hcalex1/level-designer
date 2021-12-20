/**
* This file consists of declarations for the Object class. 
* \file   Object.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include "Lookable.hpp"

#include <iostream>
#include <string>
#include <functional>

class Navigator;
class Object : public Lookable {
public:
    Object() = default;
    Object(const std::string&, const std::string&);
    
    const std::string& getName() const;
    const std::string& getDescription() const ;

    void setInteract(const std::function<void(Navigator&)> interactFunction, 
                    std::string interactText = "");

    void interact(Navigator&, std::ostream&);
    virtual void show(std::ostream&) const override;

private:
    std::string name_;
    std::string description_;
    std::string interactText_;
    std::function<void(Navigator&)> interactFunction_;

    static std::function<void(Navigator&)> noInteract_;
};
