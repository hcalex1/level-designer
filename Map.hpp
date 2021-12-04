#pragma once

#include "Tile.hpp"
#include "Position.hpp"

#include <utility>
#include <memory>

class Map
{
public:

    unsigned size() const; 
    std::shared_ptr<Tile> getTile(Position);
    Position getStartPosition() const;

    void setStartPosition(Position);
    void setTile(std::shared_ptr<Tile>, Position);
    void linkTiles(Position, Position);

private:
    Position startPosition_ = Position(0, 0);
    std::map<Position, std::shared_ptr<Tile>> map_;
};