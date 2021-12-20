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
#include <cmath>

using namespace std;
using namespace cardinal;

unsigned Map::size() const {
    return map_.size();
}

Navigator Map::getNavigator(pair<int, int> position) {
    return Navigator(map_[position].get());
}

Room& Map::operator[](pair<int, int> position) {
    return map_[position]->room_;
}

void Map::erase(pair<int, int> position) {
    for (pair<int, int> adjPos : getAdjacentPositions(position)) {
        Direction direction = computeDirection(adjPos, position);
        map_[adjPos]->unlink(direction);
        map_[adjPos]->setAdjacency(nullptr, direction);
    }
    map_.erase(position);
}

void Map::insert( pair<int, int> position, const Room& room) {
    if (map_[position] != nullptr)
        throw InvalidCoordinates("Position occupied");

    map_[position] = make_unique<Tile>(Tile{room});

    Tile* newTile = map_[position].get();
    for (pair<int, int> adjPos : getAdjacentPositions(position)) {
        auto adjTile = map_[adjPos].get();
        if (adjTile != nullptr) {
            Direction newToAdj = computeDirection(position, adjPos);
            Direction adjToNew = computeDirection(adjPos, position);
            newTile->setAdjacency(adjTile, newToAdj);
            adjTile->setAdjacency(newTile, adjToNew);
        }
    }
}

void Map::insert(pair<int, int> position, const string& roomName, const string& roomDescription) {
    insert(position, Room(roomName, roomDescription));
}

void Map::link(pair<int, int> position1, pair<int, int> position2) {
    if (computeDistance(position1, position2) != 1.0) {
        throw InvalidCoordinates("Positions must me adjacent to be linked");
    }

    Tile* tile1 = map_[position1].get();
    Tile* tile2 = map_[position2].get();
    Direction direction12 = tile1->getDirection(tile2);
    tile1->link(direction12);
}

double Map::computeDistance(pair<int, int> position1, pair<int, int> position2) {
    int deltaX = position2.first  - position1.first;
    int deltaY = position2.second - position1.second;
    return hypot(deltaX, deltaY);
}

vector<std::pair<int, int>> Map::getAdjacentPositions(pair<int, int> position) {
    vector<pair<int, int>>  adjacentPositions;
    adjacentPositions.push_back({position.first    , position.second - 1});
    adjacentPositions.push_back({position.first    , position.second + 1});
    adjacentPositions.push_back({position.first - 1, position.second    });
    adjacentPositions.push_back({position.first + 1, position.second    });
    return adjacentPositions;
}