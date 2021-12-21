/**
* This file consists of declarations for the Navigator class. 
* It is used to move through the tiles while respecting the travel rules.
* \file   Navigator.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include "Tile.hpp"
#include "Room.hpp"
#include "Lookable.hpp"
#include "cardinal.hpp"

class Navigator : public Lookable {
public:
    Navigator(Tile* tile);
    virtual ~Navigator() override = default;

    void link(cardinal::Direction direction);

    void unlink(cardinal::Direction direction);

    Room& operator*();

    const Room& operator*() const;

    void move(cardinal::Direction direction);

    virtual void show(std::ostream&) const override;

private:
    Tile* tile_;
};