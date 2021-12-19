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
#include <cmath>

using namespace std;
using namespace cardinal;

unsigned Map::size() const {
    return map_.size();
}

Navigator Map::getNavigator(pair<int, int> position) {
    return Navigator(map_[position]);
}

// pair<int, int> Map::getPosition(const string& roomName) const {
//     for (auto [position, tile] : map_) {
//         if (tile->room_.getName() == roomName)
//             return position;
//     }
//     throw domain_error("No such room");
// }

// Room& Map::getRoom(pair<int, int> position) {
//     return map_[position]->room_;
// }

// Room& Map::getRoom(const string& roomName) {
//     return getRoom(getPosition(roomName));
// }

void Map::erase(pair<int, int> position) {
    map_.erase(position);
}

void Map::insert( pair<int, int> position, const Room& room) {
    if (map_[position] != nullptr)
        throw InvalidCoordinates("Position occupied");

    Tile tile{room};
    pair<int, int> adjacentPositions[4];
    adjacentPositions[0] = {position.first    , position.second - 1};
    adjacentPositions[1] = {position.first    , position.second + 1};
    adjacentPositions[2] = {position.first - 1, position.second    };
    adjacentPositions[3] = {position.first + 1, position.second    };
    auto newTile = make_shared<Tile>(tile);
    for (int i : iter::range(static_cast<int>(Direction::count))) {
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

void Map::insert(pair<int, int> position, const string& roomName, const string& roomDescription) {
    insert(position, Room(roomName, roomDescription));
}

void Map::link(pair<int, int> position1, pair<int, int> position2) {
    if (computeDistance(position1, position2) != 1.0) {
        throw InvalidCoordinates("Positions must me adjacent to be linked");
    }

    auto tile1 = map_[position1];
    auto tile2 = map_[position2];
    Direction direction12 = tile1->getDirection(tile2);
    tile1->link(direction12);
}

// void Map::link(const string& roomName1, const string& roomName2) {
//     link(getPosition(roomName1), getPosition(roomName2));
// }

double Map::computeDistance(pair<int, int> position1, pair<int, int> position2) {
    int deltaX = position2.first  - position1.first;
    int deltaY = position2.second - position1.second;
    return hypot(deltaX, deltaY);
}