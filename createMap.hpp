/**
* This file constains the definition for the createMap function.
* It creates a map and returns the start Tile.
* \file   main.cpp
* \author Alex Hoang-Cao
* \date   13 December 2021
* Created 13 December 2021
*/

#include "Map.hpp"
#include "Tile.hpp"

#include <string>

Tile& createMap() {
    Map map;
    auto frontYard = std::make_shared<Tile>(Tile("Front Yard", 
        "There is circular driveway and a fountain"));
    auto garage = std::make_shared<Tile>(Tile("Garage", 
        "There are four parking spaces."));
    auto foyer = std::make_shared<Tile>(Tile("Foyer", 
        "There is a round table and a chandelier."));
    auto livingRoom = std::make_shared<Tile>(Tile("Living Room", 
        "There are two large couches and a coffee table."));
    auto guestHouse = std::make_shared<Tile>(Tile("Guest House", 
        "There is a bed and a kitchen."));

    map.setTile(frontYard,  std::pair( 0, 0));
    map.setTile(garage,     std::pair( 1, 0));
    map.setTile(foyer,      std::pair( 0, 1));
    map.setTile(livingRoom, std::pair( 1, 1));
    map.setTile(guestHouse, std::pair(-1, 0));

    map.linkTiles(std::pair(0,0), std::pair( 1,0));
    map.linkTiles(std::pair(0,0), std::pair( 0,1));
    map.linkTiles(std::pair(0,0), std::pair(-1,0));
    map.linkTiles(std::pair(0,1), std::pair( 1,1));
    map.linkTiles(std::pair(1,0), std::pair( 1,1));

    return *map.getTile(std::pair(0,0));
}