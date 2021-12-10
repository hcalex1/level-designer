/**
* This program consists of the first deliverable of the Deadly Rooms game.
* \file   main.cpp
* \author Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#include "createMap.hpp"
#include "Game.hpp"

#include <memory>

using namespace std;

int main() {
    auto  map = createMap();
    Game game{map};

    game.start();
}
