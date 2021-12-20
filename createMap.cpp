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
#include "Object.hpp"
#include "Navigator.hpp"
#include "cardinal.hpp"

#include <memory>
#include <string>

using namespace std;

Map createMap() {
    
    pair<int, int> frontYard  = { 0, 0 };
    pair<int, int> garage     = { 1, 0 };
    pair<int, int> foyer      = { 0, 1 };
    pair<int, int> livingRoom = { 1, 1 };
    pair<int, int> guestHouse = { -1, 0 };
    pair<int, int> diningRoom = { -1, 1 };
    pair<int, int> secretRoom = { 2, 1 };

    Map map;
  
    map.insert(frontYard,  "Front Yard",  "There is a circular driveway and a fountain.");
    map.insert(garage,     "Garage",      "There are four parking spaces.");
    map.insert(foyer,      "Foyer",       "There is a round table and a chandelier.");
    map.insert(livingRoom, "Living Room", "There are two large couches and a coffee table.");
    map.insert(guestHouse, "Guest House", "There is a bed and a kitchen.");
    map.insert(diningRoom, "Dining Room", "There is a long rectangular table with 8 chairs.");
    map.insert(secretRoom, "Secret Room", "It is a dark windowless room with a round table.");

    map.link(frontYard, garage);
    map.link(frontYard, foyer);
    map.link(frontYard, guestHouse);
    map.link(foyer,     livingRoom);
    map.link(garage,    livingRoom);
    map.link(foyer,     diningRoom);

    Object bookShelf = createBookShelf();
    map[livingRoom].addObject(bookShelf);

    Object banana = createBanana();
    map[diningRoom].addObject(banana);

    return map;
}

Object createBookShelf() {
    Object object{"book shelf", "This a woodden book shelf filled with encyclopedias.",
                       "You pull on a book and the book shelf slides to the side."};
    object.setInteract( [] (Navigator& n) { n.link(cardinal::EAST); });
    return object;
}

Object createBanana() {
    Object object{"banana", "This is a large ripe tropical banana.",
                       "You peel the banana and eat it."};
    object.setInteract( [] (Navigator& n)
                       { (*n).addObject(Object{"banana peel", "A slippery banana peel."});
                         (*n).removeObject("banana"); });
    return object;
}