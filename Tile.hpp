#pragma once

#include <string>
#include <iostream>
#include <map>
#include <memory>

class Tile {
public:
    Tile();
    Tile(const std::string &name, const std::string &description="");

    const std::string getName() const;
    const std::string getDescription() const;
    std::shared_ptr<Tile> getAdjacentTile(char);

    void print(std::ostream&) const;
    void setAdjacentTile(std::shared_ptr<Tile> tile, char direction);
    
    inline static std::shared_ptr<Tile> noTile = std::make_shared<Tile>();

private:
    std::string name_;
    std::string description_;
    std::map<char, std::shared_ptr<Tile>> adjacentTiles_;
};