/**
* This file contains the Cardinal library.
* \file   main.cpp
* \author Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include "Exceptions/InvalidDirection.hpp"

#include <cmath>

namespace cardinal {
    enum Direction { NORTH = 0x01, EAST  = 0x02, SOUTH = 0x04, WEST  = 0x08 };

    constexpr Direction charToDirection(char c) {
        switch (c) {
        case 'N': return NORTH;
        case 'E': return EAST;
        case 'S': return SOUTH;
        case 'W': return WEST;
        default : throw InvalidDirection("No such cardinal direction");
        }
    }

    constexpr char directionToChar(Direction direction) {
        switch (direction) {
        case NORTH: return 'N';
        case EAST : return 'E';
        case SOUTH: return 'S';
        case WEST : return 'W';
        default   : throw InvalidDirection("No such cardinal direction");
        }
    }

    constexpr const char* directionToString(Direction direction) {
        switch (direction) {
        case NORTH: return "North";
        case EAST : return "East";
        case SOUTH: return "South";
        case WEST : return "West";
        default   : throw InvalidDirection("No such cardinal direction");
        }
    }

    constexpr Direction computeDirection(std::pair<int, int> start, std::pair<int, int> end) {
        double deltaX = end.first - start.first;
        double deltaY = end.second - start.second;
        const double rad = atan2(deltaX, deltaY);

        if      (rad ==  0.0)    return NORTH;
        else if (rad ==  M_PI_2) return EAST;
        else if (rad ==  M_PI)   return SOUTH;
        else if (rad == -M_PI_2) return WEST;
        else throw std::domain_error("Target is not in a cardinal direction");
    }
}