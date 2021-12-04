#pragma once

#include <iostream>

class Observable {
public:
    virtual ~Observable() = default;
    virtual void show(std::ostream&) const = 0;
};