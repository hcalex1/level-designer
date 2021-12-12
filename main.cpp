/**
* This program consists of the first deliverable of the Deadly Rooms game.
* \file   main.cpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#include "createMap.hpp"
#include "Game.hpp"


using namespace std;

int main() {
    Map map = createMap();
    Game game{map.getNavigator({0,0})};
    game.start();
}
