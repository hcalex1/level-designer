/**
* This file consists of the Observable abstract class
* all classes that can be observed by the player will
* be derrived from this class..
* \file   main.cpp
* \author Alex Hoang-Cao
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include <iostream>

class Observable {
public:
    virtual ~Observable() = default;
    virtual void show(std::ostream&) const = 0;
};