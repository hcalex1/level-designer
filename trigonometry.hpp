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

    switch (gsl::narrow_cast<int>(atan2(deltaX, deltaY))) {
    case 0                              : return 'N';
    case gsl::narrow_cast<int>(M_PI_2)  : return 'E';
    case gsl::narrow_cast<int>(M_PI)    : return 'S';
    case gsl::narrow_cast<int>(-M_PI_2) : return 'W';
    default:
        throw std::domain_error("Target is not in a cardinal direction");
    }
}