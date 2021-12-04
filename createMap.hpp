#include "Map.hpp"
#include "Tile.hpp"

#include <memory>
#include <string>

std::shared_ptr<Tile> createMap() {
    Map map;
    auto courtyard = std::make_shared<Tile>(Tile("Courtyard", 
        "This the courtyard."));
    auto garage = std::make_shared<Tile>(Tile("Garage", 
        "This the garage."));
    auto foyer = std::make_shared<Tile>(Tile("Foyer", 
        "This the foyer."));
    auto livingRoom = std::make_shared<Tile>(Tile("Living Room", 
        "This the living room."));
    auto guestHouse = std::make_shared<Tile>(Tile("Guest House", 
        "This the guess house."));

    map.setTile(courtyard,  Position( 0, 0));
    map.setTile(garage,     Position( 1, 0));
    map.setTile(foyer,      Position( 0, 1));
    map.setTile(livingRoom, Position( 1, 1));
    map.setTile(guestHouse, Position(-1, 0));

    // map.linkTiles(Position(0,0), Position( 1,0));
    // map.linkTiles(Position(0,0), Position( 0,1));
    // map.linkTiles(Position(0,0), Position(-1,0));
    // map.linkTiles(Position(0,1), Position( 1,1));
    // map.linkTiles(Position(1,1), Position( 1,0));

    return map.getTile(Position(0,0));
}