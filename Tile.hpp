/**
* This file constains the declarations and prototypes for the Tile class.
* \file   main.cpp
* \author Alex Hoang-Cao and Emile Watier
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

    void linkTo(cardinal::Direction direction);
    void unlink(cardinal::Direction direction);
    
private:
    Room room_;
    std::map<cardinal::Direction, std::weak_ptr<Tile>> adjacentTiles_;
    std::uint8_t linkState_;

    void setAdjacency(std::shared_ptr<Tile>, cardinal::Direction);

    friend Map;
    friend Navigator;
};
