#include "Tile.hpp"
#include "Interactive.hpp"

#include <memory>

class Game {
public:
    Game(const std::shared_ptr<Tile>& startTile);

    void show(const std::shared_ptr<Interactive>&) const;
    void moveCharacter(char direction);
    void start();

private:
    std::shared_ptr<Tile> currentTile_;
};