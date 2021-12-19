/**
* This file contains the definition for the createMap function.
* It creates and returns a map.
* \file   createMap.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#include "createMap.hpp"
#include "Map.hpp"
#include "Room.hpp"

#include <memory>
#include <string>

Map createMap() {
    Map map;

    map.insert({ 0, 0}, "Front Yard",  "There is a circular driveway and a fountain.");
    map.insert({ 1, 0}, "Garage",      "There are four parking spaces.");
    map.insert({ 0, 1}, "Foyer",       "There is a round table and a chandelier.");
    map.insert({ 1, 1}, "Living Room", "There are two large couches and a coffee table.");
    map.insert({-1, 0}, "Guest House", "There is a bed and a kitchen.");
    map.insert({-1, 1}, "Dining Room", "There is a long rectangular table with 8 chairs.");

    map.link({0, 0}, { 1, 0});
    map.link({0, 0}, { 0, 1});
    map.link({0, 0}, {-1, 0});
    map.link({0, 1}, { 1, 1});
    map.link({1, 0}, { 1, 1});
    map.link({0, 1}, {-1, 1});

    return map;
}
