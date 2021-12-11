/**
* This file consists of declaratiosn and definitions for the Navigator class. 
It is used to move through the tiles while respecting the travel rules.
* \file   Navigator.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include "Tile.hpp"
#include "cardinal.hpp"
#include "Exceptions/EmptyDirection.hpp"

#include <memory>

class Navigator {
public:
    Navigator(std::shared_ptr<Tile> tile) : currentTile_(tile) {}

    std::shared_ptr<Tile> operator*() {
        return currentTile_;
    }

    std::shared_ptr<Tile> operator*() const {
        return currentTile_;
    }

    void move(cardinal::Direction direction) {
        if (not currentTile_->isLinkedTo(direction))
            throw EmptyDirection("No tile in this direction");

        currentTile_ = currentTile_->getAdjacentTile(direction);
    }

private:
    std::shared_ptr<Tile> currentTile_;
};