/**
* This file consists of definitions for the Map class. It is used to manage Tiles
* with the assumptions laid out in the README.md file.
* \file   main.cpp
* \author Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#include "Map.hpp"
#include "cardinal.hpp"
#include "Exceptions/InvalidCoordinates.hpp"

#include <memory>
#include <stdexcept>
#include <cmath>
#include "cppitertools/range.hpp"

using namespace std;
using namespace cardinal;

Map::~Map() {
    // All tiles must be deleted due to circular references
    for (auto [position, tilePtr] : map_) {
        delete tilePtr.get();
    }
}

unsigned Map::size() const {
    return map_.size();
}

shared_ptr<Tile> Map::getTile(pair<int, int> position) {
    return map_[position];
}

void Map::erase(pair<int, int> position) {
    map_.erase(position);
}

void Map::insert(const Tile& tile, pair<int, int> position) {
    if (map_[position] != nullptr)
        throw InvalidCoordinates("Position occupied");

    pair<int, int> adjacent[4];
    adjacent[0] = {position.first    , position.second - 1};
    adjacent[1] = {position.first    , position.second + 1};
    adjacent[2] = {position.first - 1, position.second    };
    adjacent[3] = {position.first + 1, position.second    };

    auto newTile = make_shared<Tile>(tile);
    for (int i : iter::range(4)) {
        if (map_[adjacent[i]] != nullptr) {
            Direction toAdjacent = computeDirection(position, adjacent[i]);
            Direction toNew      = computeDirection(adjacent[i], position);
            newTile->adjacentTiles_[toAdjacent] = map_[adjacent[i]];
            map_[adjacent[i]]->adjacentTiles_[toNew] = newTile;
        }
    }
    map_[position] = newTile;
}