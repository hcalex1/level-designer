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

class Map
{
public:
    unsigned size() const; 
    Navigator getNavigator(std::pair<int, int> position);
    // std::pair<int, int> getPosition(const std::string& roomName) const;
    // Room& getRoom(std::pair<int, int> position);
    // Room& getRoom(const std::string& roomName);

    void insert(std::pair<int, int> position, const Room& room);
    void insert(std::pair<int, int> position, const std::string& roomName, const std::string& roomDescription);
    void erase(std::pair<int, int>);
    void link(std::pair<int, int>, std::pair<int, int>);
    // void link(const std::string& roomName1, const std::string& roomName2);

    static double computeDistance(std::pair<int, int> position1, std::pair<int, int> position2);

private:
    std::map<std::pair<int, int>, std::shared_ptr<Tile>> map_;
};
