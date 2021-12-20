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
    
    std::pair<int, int> frontYard  = { 0, 0 };
    std::pair<int, int> garage     = { 1, 0 };
    std::pair<int, int> foyer      = { 0, 1 };
    std::pair<int, int> livingRoom = { 1, 1 };
    std::pair<int, int> guestHouse = { -1, 0 };
    std::pair<int, int> diningRoom = { -1, 1 };

    Map map;
  
    map.insert(frontYard,  "Front Yard",  "There is a circular driveway and a fountain.");
    map.insert(garage,     "Garage",      "There are four parking spaces.");
    map.insert(foyer,      "Foyer",       "There is a round table and a chandelier.");
    map.insert(livingRoom, "Living Room", "There are two large couches and a coffee table.");
    map.insert(guestHouse, "Guest House", "There is a bed and a kitchen.");
    map.insert(diningRoom, "Dining Room", "There is a long rectangular table with 8 chairs.");

    map.link(frontYard, garage);
    map.link(frontYard, foyer);
    map.link(frontYard, guestHouse);
    map.link(foyer,     livingRoom);
    map.link(garage,    livingRoom);
    map.link(foyer,     diningRoom);

    // map.link("Front Yard" , "Garage");
    // map.link("Front Yard" , "Guest House");
    // map.link("Front Yard" , "Foyer");
    // map.link("Foyer"      , "Dining Room");
    // map.link("Foyer"      , "Living Room");
    // map.link("Living Room", "Garage");

    return map;
}
