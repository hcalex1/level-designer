/**
* This file consists of the Lookable abstract class. All classes that 
* can be observed by the player will be derived from this class.
* \file   Lookable.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include <iostream>

class Lookable {
public:
    virtual ~Lookable() = default;

    virtual void show(std::ostream&) const = 0;

    bool operator==(const Lookable& other) const {
        return this == &other;
    }
};
