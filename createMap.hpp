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

Map& createMap() {
    auto map = std::make_shared<Map>();
    auto frontYard = std::make_shared<Tile>(Tile{"Front Yard", 
        "There is circular driveway and a fountain"});
    auto garage = std::make_shared<Tile>(Tile{"Garage", 
        "There are four parking spaces."});
    auto foyer = std::make_shared<Tile>(Tile{"Foyer", 
        "There is a round table and a chandelier."});
    auto livingRoom = std::make_shared<Tile>(Tile{"Living Room", 
        "There are two large couches and a coffee table."});
    auto guestHouse = std::make_shared<Tile>(Tile{"Guest House", 
        "There is a bed and a kitchen."});

    map->insert(*frontYard,  { 0, 0});
    map->insert(*garage,     { 1, 0});
    map->insert(*foyer,      { 0, 1});
    map->insert(*livingRoom, { 1, 1});
    map->insert(*guestHouse, {-1, 0});

    map->linkTiles({0,0}, { 1,0});
    map->linkTiles({0,0}, { 0,1});
    map->linkTiles({0,0}, {-1,0});
    map->linkTiles({0,1}, { 1,1});
    map->linkTiles({1,0}, { 1,1});

    return *map;
}
