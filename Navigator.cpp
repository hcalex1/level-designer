/**
* This file consists of definitions for the Navigator class. 
* It is used to move through the tiles while respecting the travel rules.
* \file   Navigator.cpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#include "Navigator.hpp"
#include "Tile.hpp"
#include "Room.hpp"
#include "cardinal.hpp"
#include "Exceptions/EmptyDirection.hpp"

#include <memory>

using namespace std;

Navigator::Navigator(Tile* tile) : tile_(tile) {}

void Navigator::link(cardinal::Direction direction) {
    tile_->link(direction);
}

void Navigator::unlink(cardinal::Direction direction) {
    tile_->unlink(direction);
}

Room& Navigator::operator*() {
    return tile_->room_;
}

const Room& Navigator::operator*() const {
    return tile_->room_;
}

void Navigator::move(cardinal::Direction direction) {
    if (!tile_->isLinkedTo(direction))
        throw EmptyDirection("No tile in this direction");

    tile_ = tile_->adjacentTiles_[direction];
}

void Navigator::show(std::ostream& os) const {
    os << endl;
    for (auto [direction, tile] : tile_->adjacentTiles_) {
        if (tile_->isLinkedTo(direction)) {
            os << tile->room_.getName() << " is to the " << directionToString(direction)
                << " (" << static_cast<char>(direction) << ")\n";
        }
    }
}