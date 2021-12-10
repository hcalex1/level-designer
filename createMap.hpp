/**
* This file constains the definition for the createMap function.
* It creates a map and returns the start Tile.
* \file   main.cpp
* \author Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#include "Map.hpp"
#include "Tile.hpp"

#include <memory>
#include <string>

Map createMap() {
    Map map;
    Tile frontYard  = Tile{"Front Yard",  "There is circular driveway and a fountain"};
    Tile garage     = Tile{"Garage",      "There are four parking spaces."};
    Tile foyer      = Tile{"Foyer",       "There is a round table and a chandelier."};
    Tile livingRoom = Tile{"Living Room", "There are two large couches and a coffee table."};
    Tile guestHouse = Tile{"Guest House", "There is a bed and a kitchen."};

    map.insert(frontYard,  { 0, 0});
    map.insert(garage,     { 1, 0});
    map.insert(foyer,      { 0, 1});
    map.insert(livingRoom, { 1, 1});
    map.insert(guestHouse, {-1, 0});

    Tile::link(map.getTile({0, 0}), map.getTile({ 1, 0}));
    Tile::link(map.getTile({0, 0}), map.getTile({ 0, 1}));
    Tile::link(map.getTile({0, 0}), map.getTile({-1, 0}));
    Tile::link(map.getTile({0, 1}), map.getTile({ 1, 1}));
    Tile::link(map.getTile({1, 0}), map.getTile({ 1, 1}));

    return map;
}
