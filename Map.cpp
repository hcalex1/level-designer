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
#include "cppitertools/range.hpp"

using namespace std;
using namespace cardinal;

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

    auto adjacentPositions = getAdjacentPositions(position);
    auto newTile = make_shared<Tile>(tile);
    for (int i : iter::range(4)) {
        auto adjTile = map_[adjacentPositions[i]];
        if (adjTile != nullptr) {
            Direction newToAdj = computeDirection(position, adjacentPositions[i]);
            Direction adjToNew = computeDirection(adjacentPositions[i], position);
            newTile->adjacentTiles_[newToAdj] = adjTile;
            adjTile->adjacentTiles_[adjToNew] = newTile;
        }
    }
    map_[position] = newTile;
}

pair<int, int>* Map::getAdjacentPositions(pair<int, int> referencePosition) {
    pair<int, int> positions[4];
    positions[0] = {referencePosition.first    , referencePosition.second - 1};
    positions[1] = {referencePosition.first    , referencePosition.second + 1};
    positions[2] = {referencePosition.first - 1, referencePosition.second    };
    positions[3] = {referencePosition.first + 1, referencePosition.second    };
    return positions;
}