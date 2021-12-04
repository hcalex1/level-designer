/**
* This file consists of definitions for the Tile class.
* \file   main.cpp
* \author Alex Hoang-Cao
* \date   13 December 2021
* Created 13 December 2021
*/

#include "Tile.hpp"
#include"CARDINAL_DIRECTIONS.h"

#include <string>
#include <memory>
#include <iostream>

using namespace std;

Tile::Tile() {
    adjacentTiles_['N'] = noTile;
    adjacentTiles_['E'] = noTile;
    adjacentTiles_['S'] = noTile;
    adjacentTiles_['W'] = noTile;
}

Tile::Tile(const string &name, const string &description) : Tile() {
    name_ = name;
    description_ = description;
}

const string& Tile::getName()        const { return name_; }
const string& Tile::getDescription() const { return description_; }
shared_ptr<Tile> Tile::getAdjacentTile(char direction) {
    return adjacentTiles_[direction];
}

void Tile::show(ostream& os) const {
    os << "-- " << name_ << " --" << endl;
    os << description_ << endl;
    for (auto [direction, tile] : adjacentTiles_){
        if (tile != noTile) {
            os << tile->name_ << " is to the " << CARIDINAL_DIRECTIONS.at(direction)
                    << " (" << direction << ")" << endl;
        }
    }
}

void Tile::setAdjacentTile(std::shared_ptr<Tile> newTile, char direction) {
    adjacentTiles_[direction] = newTile;
}