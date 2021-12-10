/**
* This file consists of definitions for the Map class. It is used to manage Tiles
* with the assumptions laid out in the README.md file.
* \file   main.cpp
* \author Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#include "Map.hpp"
#include "trigonometry.hpp"
#include "cardinalDirection.hpp"

#include <memory>
#include <stdexcept>
#include <cmath>

using namespace std;

Map::Map(pair<int, int> startPosition) : startPosition_(startPosition) {}

unsigned Map::size() const {
    return map_.size();
}

Tile& Map::getTile(pair<int, int> position) {
    return map_[position];
}

std::pair<int, int> Map::getStartPosition() const{
    return startPosition_;
}

void Map::insert(Tile& tile, pair<int, int> position) {
    if (map_.find(position) == map_.end())
        map_[position] = tile;
    else
        throw domain_error("Position occupied");
}

void Map::linkTiles(pair<int, int> position1, pair<int, int> position2) {
    if (computeDistance(position1, position2) != 1.0)
        throw domain_error("Tiles are not adjacent");
    
    Tile& tile1 = map_[position1];
    Tile& tile2 = map_[position2];
    cardinalDirection direction12 = computeCardinalDirection(position1, position2);
    cardinalDirection direction21 = computeCardinalDirection(position2, position1);
    tile1.link(direction12);
    tile2.link(direction21);
}
