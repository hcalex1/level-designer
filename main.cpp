#include "createMap.hpp"
#include "Game.hpp"

#include <memory>

using namespace std;

int main() {
    Tile&  startTile = createMap();
    Game game(startTile);

    game.start();
}