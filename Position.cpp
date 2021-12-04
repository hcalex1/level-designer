#include "Position.hpp"

#define _USE_MATH_DEFINES

#include "gsl/gsl"
#include <cmath>
#include <stdexcept>

using namespace std;

Position::Position(int x, int y) : x_(x), y_ (y) {}

int Position::getX() const { return x_; }
int Position::getY() const { return y_; }

double Position::computeDistance(Position target) const {
    double deltaX = target.x_ - x_;
    double deltaY = target.y_ - y_;
    return hypot(deltaX, deltaY);
}

char Position::getCardinalDirection(Position target) const {
    double deltaX = target.x_ - x_;
    double deltaY = target.y_ - y_;

    switch (gsl::narrow_cast<int>(atan2(deltaX, deltaY) * 180.0 / M_PI))
    {
    case   0: return 'E';
    case  90: return 'N';
    case 180: return 'W';
    case 270: return 'S';
    default:
        throw domain_error("Target is not in a cardinal direction");
    }
}

bool operator<(const Position& position1, const Position& position2) {
    if (position1.getX() != position2.getY())
        return position1.getX() < position2.getY();
    else
        return position1.getY() < position2.getY();
}