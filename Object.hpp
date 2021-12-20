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

#include "iostream"

class Object : public Lookable, public Interactible {
public:
    Object(const std::string&);

    virtual void interact(Navigator&, std::ostream&) const override;
    virtual void show(std::ostream&) const override;
};
