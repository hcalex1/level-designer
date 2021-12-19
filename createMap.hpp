/**
* This file contains the dec for the createMap function.
* It creates and returns a map.
* \file   createMap.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include "Map.hpp"
#include "Room.hpp"

#include <memory>
#include <string>

Map createMap() {
    Map map;
    Room frontYard  = Room{"Front Yard",  "There is a circular driveway and a fountain."};
    Room garage     = Room{"Garage",      "There are four parking spaces."};
    Room foyer      = Room{"Foyer",       "There is a round table and a chandelier."};
    Room livingRoom = Room{"Living Room", "There are two large couches and a coffee table."};
    Room guestHouse = Room{"Guest House", "There is a bed and a kitchen."};
    Room diningRoom = Room{"Dining Room", "There is a long rectangular table with 8 chairs."};

    map.insert(frontYard,  { 0, 0});
    map.insert(garage,     { 1, 0});
    map.insert(foyer,      { 0, 1});
    map.insert(livingRoom, { 1, 1});
    map.insert(guestHouse, {-1, 0});
    map.insert(diningRoom, {-1, 1});

    map.link({0, 0}, { 1, 0});
    map.link({0, 0}, { 0, 1});
    map.link({0, 0}, {-1, 0});
    map.link({0, 1}, { 1, 1});
    map.link({1, 0}, { 1, 1});
    map.link({0, 1}, {-1, 1});

    return map;
}
