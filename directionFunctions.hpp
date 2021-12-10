#pragma once
#include "Exceptions/InvalidDirection.hpp"
#include <pair>

std::pair<char, char> getOrthogonals(char direction) {
    if      (direction == ('N' || 'S'))
        return { 'E', 'W' };
    else if (direction == ('E' || 'W'))
        return { 'N', 'S' };
    else
        throw InvalidDirection("Direction must be cardinal");
}