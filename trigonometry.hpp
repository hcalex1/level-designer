/**
* This file contains functions to compute the direction and distance between two position pairs.
* \file   main.cpp
* \author Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#define _USE_MATH_DEFINES

#include "gsl/gsl"
#include <cmath>
#include <stdexcept>

double computeDistance(std::pair<int, int> position1, std::pair<int, int> position2) {
    double deltaX = position1.first - position2.first;
    double deltaY = position1.second - position2.second;
    return hypot(deltaX, deltaY);
}

char computeCardinalDirection(std::pair<int, int> start, std::pair<int, int> end) {
    double deltaX = end.first - start.first;
    double deltaY = end.second - start.second;
    const double rad = atan2(deltaX, deltaY);

    if      (rad ==  0.0)    return 'N';
    else if (rad ==  M_PI_2) return 'E';
    else if (rad ==  M_PI)   return 'S';
    else if (rad == -M_PI_2) return 'W';
    else throw std::domain_error("Target is not in a cardinal direction");
}
