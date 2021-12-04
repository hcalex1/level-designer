#define _USE_MATH_DEFINES

#include "gsl/gsl"
#include <cmath>
#include <stdexcept>

double computeDistance(std::pair<int, int> position1, std::pair<int, int> position2) {
    double deltaX = position1.first - position2.first;
    double deltaY = position1.second - position2.second;
    return hypot(deltaX, deltaY);
}

char getCardinalDirection(std::pair<int, int> start, std::pair<int, int> end) {
    double deltaX = end.first - start.first;
    double deltaY = end.second - start.second;

    switch (gsl::narrow_cast<int>(atan2(deltaX, deltaY) * 180.0 / M_PI))
    {
    case   0: return 'E';
    case  90: return 'N';
    case 180: return 'W';
    case 270: return 'S';
    default:
        throw std::domain_error("Target is not in a cardinal direction");
    }
}