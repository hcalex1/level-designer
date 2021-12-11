/**
* This file contains the declarations and prototypes for the Map class. This class is 
* used to manage Tiles with the assumptions laid out in the README.md file. 
* It is intended to be used to link Tiles and avoid conflicts.
* \file   Map.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include "Tile.hpp"

#include <utility>
#include <memory>

class Map
{
public:
    unsigned size() const; 
    std::shared_ptr<Tile> getTile(std::pair<int, int>);
    std::pair<int, int> getStartPosition() const;

    void insert(const Tile&, std::pair<int, int>);
    void erase(std::pair<int, int>);

    static double computeDistance(std::pair<int, int> position1, std::pair<int, int> position2);
    static pair<int, int>* Map::getAdjacentPositions(pair<int, int> position);

private:
    std::map<std::pair<int, int>, std::shared_ptr<Tile>> map_;
};
