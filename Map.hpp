/**
* This file constains the declarations and prototypes for the Map class. This class is 
used to manage Tiles with the assumptions laid out in the README.md file. It is intended
to be used to link Tiles avoiding conflicts.
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
    Map(std::pair<int, int> startPosition={0,0});
    unsigned size() const; 
    Tile& getTile(std::pair<int, int>);
    std::pair<int, int> getStartPosition() const;

    void insert(Tile&, std::pair<int, int>);
    void linkTiles(std::pair<int, int>, std::pair<int, int>);

private:
    std::map<std::pair<int, int>, Tile&> map_;
    std::pair<int, int> startPosition_;
};
