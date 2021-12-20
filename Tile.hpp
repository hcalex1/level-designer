/**
* This file contains the declarations and prototypes for the Tile class.
* \file   Tile.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include "Room.hpp"
#include "cardinal.hpp"

#include <string>
#include <iostream>
#include <map>

class Map;
class Navigator;
class Tile {
public:
    Tile(const Room&);

    cardinal::Direction getDirection(Tile*) const;
    bool isLinkedTo(cardinal::Direction direction) const;

    void link(cardinal::Direction direction);
    void unlink(cardinal::Direction direction);
    
private:
    Room room_;
    std::map<cardinal::Direction, Tile*> adjacentTiles_;

    std::uint8_t linkState_; // This is a bitmap for the links to the other Tiles

    void setAdjacency(Tile*, cardinal::Direction);

    static const std::map<cardinal::Direction, uint8_t> directionToBit;

    friend Map;
    friend Navigator;
};
