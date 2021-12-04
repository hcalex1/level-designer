#pragma once

#include "Observable.hpp"

#include <iostream>

class Interactive : public Observable
{
public:
    virtual void show(std::ostream&) const override { }
};