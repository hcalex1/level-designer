/**
* This file consists of definitions for the Tile class.
* \file   main.cpp
* \author Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#include "Tile.hpp"
#include "cardinal.hpp"
#include "Exceptions/InvalidDirection.hpp"
#include "Exceptions/InvalidCoordinates.hpp"

#include <string>
#include <memory>
#include <iostream>

using namespace std;
using namespace cardinal;

Tile::Tile(const string &name, const string &description) : 
    name_(name) , description_(description) , linkState_(0x00) {}

const string& Tile::getName() const {
    return name_;
}

const string& Tile::getDescription() const {
    return description_;
}

shared_ptr<Tile> Tile::getAdjacentTile(Direction direction) const {
    try {
        return adjacentTiles_.at(direction);
    }
    catch (out_of_range& e) {
        throw InvalidDirection("Direction does not exist");
    }
}

Direction Tile::getDirection(shared_ptr<Tile> other) const {
    for (auto [direction, tile] : adjacentTiles_) {
        if (tile == other)
            return direction; 
    }
    throw InvalidCoordinates("Tiles are not adjacent");
}

bool Tile::isLinkedTo(Direction direction) const{
    return linkState_ & direction;
}

void Tile::linkTo(Direction direction) {
    linkState_ += direction;
}

void Tile::unlink(Direction direction) {
    linkState_ -= direction;
}

void Tile::show(ostream& os) const {
    os << "-- " << name_ << " --" << endl;
    os << description_ << endl;
    for (auto [direction, tile] : adjacentTiles_) {
        if (isLinkedTo(direction)) {
            os << tile->name_ << " is to the " << directionToString(direction)
                << " (" << directionToChar(direction) << ")" << endl;
        }
    }
}

void Tile::link(std::shared_ptr<Tile> tile1, std::shared_ptr<Tile> tile2) {
    Direction direction12 = tile1->getDirection(tile2);
    tile1->linkTo(direction12);
    Direction direction21 = tile2->getDirection(tile1);
    tile2->linkTo(direction21);
}

void Tile::setAdjacency(shared_ptr<Tile> other, Direction direction) {
    adjacentTiles_[direction] = other;
}