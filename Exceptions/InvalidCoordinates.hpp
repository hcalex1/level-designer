#pragma once

#include <stdexcept>

class  InvalidCoordinates : public std::domain_error {
public:
     using std::domain_error::domain_error;
};