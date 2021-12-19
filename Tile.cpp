/**
* This file consists of definitions for the Tile class.
* \file   Tile.cpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#include "Tile.hpp"
#include "cardinal.hpp"
#include "Exceptions/InvalidDirection.hpp"
#include "Exceptions/InvalidCoordinates.hpp"
#include "Exceptions/EmptyDirection.hpp"

#include <string>
#include <memory>
#include <iostream>

using namespace std;
using namespace cardinal;

static const map<Direction, uint8_t> directionToBit = { { NORTH, 0x01 },
                                                        { EAST , 0x02 },
                                                        { SOUTH, 0x04 },
                                                        { WEST , 0x08 } };

Tile::Tile(const Room & room) : room_(room), linkState_(0x00) {}

Direction Tile::getDirection(shared_ptr<Tile> other) const {
    for (auto [direction, tile] : adjacentTiles_) {
        if (tile.lock() == other)
            return direction; 
    }
    throw InvalidCoordinates("Tiles are not adjacent");
}

bool Tile::isLinkedTo(Direction direction) const{
    try {
        if (adjacentTiles_.at(direction).expired())
            return false;
        else
            return linkState_ & directionToBit.at(direction);
    }
    catch (out_of_range& e) {
        return false;
    }
}

void Tile::link(Direction direction) {
    auto other = adjacentTiles_[direction].lock();
    Direction rDirection = reverseDirection(direction);
    linkState_        = linkState_        | directionToBit.at(direction);
    other->linkState_ = other->linkState_ | directionToBit.at(rDirection);
}

void Tile::unlink(Direction direction) {
    auto other = adjacentTiles_[direction].lock();
    Direction rDirection = reverseDirection(direction);
    linkState_        = linkState_        ^ directionToBit.at(direction);
    other->linkState_ = other->linkState_ ^ directionToBit.at(rDirection);
}

void Tile::setAdjacency(shared_ptr<Tile> other, Direction direction) {
    adjacentTiles_[direction] = other;
}