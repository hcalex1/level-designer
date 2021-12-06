/**
* This file constains the declarations and prototypes for the Game class.
* \file   main.cpp
* \author Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#include "Tile.hpp"
#include "Observable.hpp"

#include <memory>

class Game {
public:
    Game (const std::shared_ptr<Tile>& startTile);

    void moveCharacter(char direction);
    void readInput();
    void start();

private:
    std::shared_ptr<Tile> currentTile_;
};
