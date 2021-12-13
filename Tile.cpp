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

Tile::Tile(const Room & room) : room_(room), linkState_(0x00) {}

Direction Tile::getDirection(shared_ptr<Tile> other) const {
    for (auto [direction, tile] : adjacentTiles_) {
        if (tile.lock() == other)
            return direction; 
    }
    throw InvalidCoordinates("Tiles are not adjacent");
}

bool Tile::isLinkedTo(Direction direction) const{
    if (adjacentTiles_.find(direction) != adjacentTiles_.end() &&
        adjacentTiles_.at(direction).expired())
        return false;
    else
        return linkState_ & direction;
}

void Tile::linkTo(Direction direction) {
    auto other = adjacentTiles_[direction].lock();
    Direction rDirection = reverseDirection(direction);
    if (!isLinkedTo(direction))
        linkState_ += direction;
    if (!other->isLinkedTo(rDirection))
        other->linkState_ += rDirection;
}

void Tile::unlink(Direction direction) {
    auto other = adjacentTiles_[direction].lock();
    Direction rDirection = reverseDirection(direction);
    if (isLinkedTo(direction))
        linkState_ -= direction;
    if (other->isLinkedTo(rDirection))
        other->linkState_ -= rDirection;
}

void Tile::setAdjacency(shared_ptr<Tile> other, Direction direction) {
    adjacentTiles_[direction] = other;
}