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
#include "cardinal.hpp"

class Navigator {
public:
    Navigator(Tile* tile);

    Room& getRoom(cardinal::Direction);

    void link(cardinal::Direction);
    void unlink(cardinal::Direction);
    void move(cardinal::Direction);
    void show(std::ostream&) const;

    Room& operator*();
    const Room& operator*() const;


private:
    Tile* tile_;
};