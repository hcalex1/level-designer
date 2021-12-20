/**
* This file consists of the Interactible abstract class. All classes that 
* can be used by the player will be derived from this class.
* \file   Interactible.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include "Navigator.hpp"

#include <iostream>

class Interactible {
public:
    virtual ~Interactible() = default;

    virtual void interact(Navigator&, std::ostream&) const = 0;
};
