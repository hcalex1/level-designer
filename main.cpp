/**
* This program consists of the first deliverable 
* of the Deadly Rooms game.
* \file   main.cpp
* \author Alex Hoang-Cao
* \date   13 December 2021
* Created 13 December 2021
*/

#include "createMap.hpp"
#include "Game.hpp"

#include <memory>

using namespace std;

int main() {
    Tile&  startTile = createMap();
    Game game(startTile);

    game.start();
}