/**
* This file constains the declarations and prototypes for the Tile class.
* \file   main.cpp
* \author Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include "Lookable.hpp"

#include <string>
#include <iostream>
#include <map>
#include <memory>

class Tile : public Lookable {
public:
    Tile();
    Tile(const std::string &name, const std::string &description="");

    const std::string& getName() const;
    const std::string& getDescription() const;
    std::shared_ptr<Tile> getAdjacentTile(char);

    virtual void show(std::ostream&) const override;
    void setAdjacentTile(std::shared_ptr<Tile> tile, char direction);
    
    inline static const std::shared_ptr<Tile> noTile = std::make_shared<Tile>();

private:
    std::string name_;
    std::string description_;
    std::map<char, std::shared_ptr<Tile>> adjacentTiles_;
};
