#include "Map.hpp"

#include <memory>
#include <stdexcept>
#include <cassert>
#include <cmath>

using namespace std;

unsigned Map::size() const {
    return map_.size();
}

shared_ptr<Tile> Map::getTile(Position position) {
    return map_[position];
}

Position Map::getStartPosition() const {
    return startPosition_;
}

void Map::setStartPosition(Position position) {
    startPosition_ = position;
}

void Map::setTile(std::shared_ptr<Tile> tile, Position position) {
    // if (map_.find(position) == map_.end())
        map_[position] = tile;
    // else
    //     throw domain_error("Position occupied");
}

void Map::linkTiles(Position position1, Position position2) {
    if (position1.computeDistance(position2) != 1.0)
        throw domain_error("Tiles are not adjacent");
    
    auto tile1 = map_[position1];
    auto tile2 = map_[position2];
    char direction12 = position1.getCardinalDirection(position2);
    char direction21 = position2.getCardinalDirection(position2);

    tile1->setAdjacentTile(tile2, direction12);
    tile2->setAdjacentTile(tile1, direction21);
}
