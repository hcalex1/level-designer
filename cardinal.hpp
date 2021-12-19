/**
* This file contains the Cardinal library.
* \file   cardinal.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include "Exceptions/InvalidDirection.hpp"

namespace cardinal {
    enum Direction { NORTH = 'N', EAST  = 'E', SOUTH = 'S', WEST  = 'W' };

    constexpr const char* directionToString(Direction direction) {
        switch (direction) {
            case NORTH: return "North";
            case EAST : return "East";
            case SOUTH: return "South";
            case WEST : return "West";
            default   : throw InvalidDirection("No such cardinal direction");
        }
    }

    constexpr Direction reverseDirection(Direction direction) {
        switch (direction) {
            case NORTH: return SOUTH;
            case EAST : return WEST;
            case SOUTH: return NORTH;
            case WEST : return EAST;
            default   : throw InvalidDirection("No such cardinal direction");
        }
    }

    constexpr Direction computeDirection(std::pair<int, int> start, std::pair<int, int> end) {
        int deltaX = end.first - start.first;
        int deltaY = end.second - start.second;

        if (deltaX == 0){
            if (deltaY > 0)
                return NORTH;
            else if (deltaY < 0)
                return SOUTH;
        } else if (deltaY == 0){
            if (deltaX > 0)
                return EAST;
            else if (deltaX < 0)
                return WEST;
        }
        throw InvalidDirection("Target is not in a cardinal direction");
    }
}