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

#include <memory>
#include <stdexcept>
#include <cmath>

using namespace std;

unsigned Map::size() const {
    return map_.size();
}

shared_ptr<Tile> Map::getTile(pair<int, int> position) {
    return map_[position];
}

void Map::setTile(const std::shared_ptr<Tile>& tile, pair<int, int> position) {
    if (map_.find(position) == map_.end())
        map_[position] = tile;
    else
        throw domain_error("Position occupied");
}

void Map::linkTiles(pair<int, int> position1, pair<int, int> position2) {
    if (computeDistance(position1, position2) != 1.0)
        throw domain_error("Tiles are not adjacent");
    
    auto tile1 = map_[position1];
    auto tile2 = map_[position2];
    char direction12 = computeCardinalDirection(position1, position2);
    char direction21 = computeCardinalDirection(position2, position1);

    tile1->setAdjacentTile(tile2, direction12);
    tile2->setAdjacentTile(tile1, direction21);
}
