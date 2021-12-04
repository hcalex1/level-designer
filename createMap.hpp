#include "Map.hpp"
#include "Tile.hpp"

#include <memory>
#include <string>

std::shared_ptr<Tile> createMap() {
    Map map;
    auto frontYard = std::make_shared<Tile>(Tile("Front Yard", 
        "This the front yard."));
    auto garage = std::make_shared<Tile>(Tile("Garage", 
        "This the garage."));
    auto foyer = std::make_shared<Tile>(Tile("Foyer", 
        "This the foyer."));
    auto livingRoom = std::make_shared<Tile>(Tile("Living Room", 
        "This the living room."));
    auto guestHouse = std::make_shared<Tile>(Tile("Guest House", 
        "This the guess house."));

    map.setTile(frontYard,  std::pair( 0, 0));
    map.setTile(garage,     std::pair( 1, 0));
    map.setTile(foyer,      std::pair( 0, 1));
    map.setTile(livingRoom, std::pair( 1, 1));
    map.setTile(guestHouse, std::pair(-1, 0));

    map.linkTiles(std::pair(0,0), std::pair( 1,0));
    map.linkTiles(std::pair(0,0), std::pair( 0,1));
    map.linkTiles(std::pair(0,0), std::pair(-1,0));
    map.linkTiles(std::pair(0,1), std::pair( 1,1));
    map.linkTiles(std::pair(1,1), std::pair( 1,0));

    return map.getTile(std::pair(0,0));
}