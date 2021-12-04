/**
* This file constains the declarations and prototypes for the Game class.
* \file   main.cpp
* \author Alex Hoang-Cao
* \date   13 December 2021
* Created 13 December 2021
*/

#include "Tile.hpp"
#include "Observable.hpp"

#include <memory>

class Game {
public:
    Game (Tile& startTile);

    void show(const Observable&) const;
    void moveCharacter(char direction);
    void readInput();
    void start();

private:
    Tile &currentTile_;
    Observable &test = static_cast<Observable&>(currentTile_);
};