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
#include "Room.hpp"

#include <utility>
#include <memory>
#include <string>
#include <vector>

class Map
{
public:
    unsigned size() const; 
    Navigator getNavigator(std::pair<int, int> position);
    Room& operator[](std::pair<int, int> position);

    void insert(std::pair<int, int> position, const Room& room);
    void insert(std::pair<int, int> position, const std::string& roomName, const std::string& roomDescription);
    void erase(std::pair<int, int>);
    void link(std::pair<int, int>, std::pair<int, int>);

    static double computeDistance(std::pair<int, int> position1, std::pair<int, int> position2);

private:
    std::map<std::pair<int, int>, std::unique_ptr<Tile>> map_;

    static std::vector<std::pair<int, int>> getAdjacentPositions(std::pair<int, int>);
};
