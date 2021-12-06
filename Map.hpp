/**
* This file constains the declarations and prototypes for the Map class.
* \file   main.cpp
* \author Alex Hoang-Cao and Emile Watier
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

    void setTile(const std::shared_ptr<Tile>&, std::pair<int, int>);
    void linkTiles(std::pair<int, int>, std::pair<int, int>);

private:
    std::map<std::pair<int, int>, std::shared_ptr<Tile>> map_;
};
