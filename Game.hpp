#include "Tile.hpp"

#include <memory>

class Game {
public:
    Game(std::shared_ptr<Tile> startTile);

    void moveCharacter(char direction);
    void start();

private:
    std::shared_ptr<Tile> characterLocation_;
};