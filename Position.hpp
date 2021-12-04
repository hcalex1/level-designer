#pragma once

#include <cmath>
#include <stdexcept>

class Position {
public:
    Position(int x, int y);
    
    int getX() const;
    int getY() const;

    double computeDistance(Position target) const;
    char getCardinalDirection(Position target)const;

private:
    int x_;
    int y_;
};

bool operator<(const Position&, const Position&);