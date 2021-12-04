#pragma once

#include "Tile.hpp"

#include <utility>
#include <memory>

class Map
{
public:

    unsigned size() const; 
    std::shared_ptr<Tile> getTile(std::pair<int, int>);
    std::pair<int, int> getStartPosition() const;

    void setTile(const std::shared_ptr<Tile>&, std::pair<int, int>);
    void linkTiles(std::pair<int, int>, std::pair<int, int>);

private:
    std::map<std::pair<int, int>, std::shared_ptr<Tile>> map_;
};