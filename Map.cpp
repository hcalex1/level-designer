/**
* This file consists of definitions for the Map class. It is used to manage Tiles
* with the assumptions laid out in the README.md file.
* \file   Map.cpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#include "Map.hpp"
#include "Navigator.hpp"
#include "cardinal.hpp"
#include "Exceptions/InvalidCoordinates.hpp"

#include <memory>
#include "cppitertools/range.hpp"

using namespace std;
using namespace cardinal;

unsigned Map::size() const {
    return map_.size();
}

Navigator Map::getNavigator(pair<int, int> position) {
    return Navigator(map_[position]);
}

void Map::erase(pair<int, int> position) {
    map_.erase(position);
}

void Map::insert(const Room& room, pair<int, int> position) {
    if (map_[position] != nullptr)
        throw InvalidCoordinates("Position occupied");

    Tile tile{room};
    pair<int, int> adjacentPositions[4];
    adjacentPositions[0] = {position.first    , position.second - 1};
    adjacentPositions[1] = {position.first    , position.second + 1};
    adjacentPositions[2] = {position.first - 1, position.second    };
    adjacentPositions[3] = {position.first + 1, position.second    };
    auto newTile = make_shared<Tile>(tile);
    for (int i : iter::range(4)) {
        auto adjTile = map_[adjacentPositions[i]];
        if (adjTile != nullptr) {
            Direction newToAdj = computeDirection(position, adjacentPositions[i]);
            Direction adjToNew = computeDirection(adjacentPositions[i], position);
            newTile->setAdjacency(adjTile, newToAdj);
            adjTile->setAdjacency(newTile, adjToNew);
        }
    }
    map_[position] = newTile;
}

void Map::link(std::pair<int, int> position1, std::pair<int, int> position2) {
    auto tile1 = map_[position1];
    auto tile2 = map_[position2];
    Direction direction12 = tile1->getDirection(tile2);
    tile1->link(direction12);
}