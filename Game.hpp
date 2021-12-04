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