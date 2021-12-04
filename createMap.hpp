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

#include <memory>
#include <string>

std::shared_ptr<Tile> createMap() {
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

    map.setTile(frontYard,  { 0, 0});
    map.setTile(garage,     { 1, 0});
    map.setTile(foyer,      { 0, 1});
    map.setTile(livingRoom, { 1, 1});
    map.setTile(guestHouse, {-1, 0});

    map.linkTiles({0,0}, { 1,0});
    map.linkTiles({0,0}, { 0,1});
    map.linkTiles({0,0}, {-1,0});
    map.linkTiles({0,1}, { 1,1});
    map.linkTiles({1,0}, { 1,1});

    return map.getTile(std::pair(0,0));
}