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
#include <memory>

class Map;
class Navigator;
class Tile {
public:
    Tile(const Room&);

    cardinal::Direction getDirection(std::shared_ptr<Tile>) const;
    bool isLinkedTo(cardinal::Direction direction) const;

    void link(cardinal::Direction direction);
    void unlink(cardinal::Direction direction);
    
private:
    Room room_;

    // Adjacent tiles must be refenced using weak_ptrs to avoid circular referencing
    // (adjacent tiles will inevitable be referencing each other).Tile ownership must
    // be shared with the Map class which manages the creation and destruction. 
    std::map<cardinal::Direction, std::weak_ptr<Tile>> adjacentTiles_;

    std::uint8_t linkState_; // This is a bitmap for the links to the other Tiles

    void setAdjacency(std::shared_ptr<Tile>, cardinal::Direction);

    static const std::map<cardinal::Direction, uint8_t> directionToBit;

    friend Map;
    friend Navigator;
};
