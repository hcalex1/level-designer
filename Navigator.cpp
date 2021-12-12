/**
* This file consists of definitions for the Navigator class. 
It is used to move through the tiles while respecting the travel rules.
* \file   Navigator.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#include "Navigator.hpp"
#include "Tile.hpp"
#include "Room.hpp"
#include "Lookable.hpp"
#include "cardinal.hpp"
#include "Exceptions/EmptyDirection.hpp"

#include <memory>

using namespace std;

Navigator::Navigator(std::shared_ptr<Tile> tile) : tile_(tile) {}

void Navigator::linkTo(cardinal::Direction direction) {
    tile_->linkTo(direction);
}

void Navigator::unlink(cardinal::Direction direction) {
    tile_->unlink(direction);
}

Room& Navigator::operator*() {
    return tile_->room_;
}

Room& Navigator::operator*() const {
    return tile_->room_;
}

void Navigator::move(cardinal::Direction direction) {
    if (not tile_->isLinkedTo(direction))
        throw EmptyDirection("No tile in this direction");

    tile_ = tile_->adjacentTiles_[direction].lock();
}

void Navigator::show(std::ostream& os) const {
    for (auto [direction, tile] : tile_->adjacentTiles_) {
        if (!tile.expired() && tile_->isLinkedTo(direction)) {
            os << tile.lock()->room_.getName() << " is to the " << directionToString(direction)
                << " (" << directionToChar(direction) << ")" << endl;
        }
    }
}