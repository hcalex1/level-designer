#pragma once

#include <stdexcept>

class  InvalidDirection : public std::invalid_argument {
public:
     using std::invalid_argument::invalid_argument;
};