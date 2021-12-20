/**
* This file consists of the Object abstract class. 
* \file   Interactible.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include "Lookable.hpp"
#include "Interactible.hpp"

#include <iostream>
#include <string>
#include <functional>

class Object : public Lookable, public Interactible {
public:
    Object(const std::string&, const std::string&);
    
    const std::string& getName() const;
    const std::string& getDescription() const ;

    void setInteract(const std::function<void(Navigator&, Object&)> interactFunction, 
                    std::string interactText = "Nothing to do");

    virtual void interact(Navigator&, std::ostream&) const override;
    virtual void show(std::ostream&) const override;

private:
    std::string name_;
    std::string description;
    std::string interactText_;
};
