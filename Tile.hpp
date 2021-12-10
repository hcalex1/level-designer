/**
* This file constains the declarations and prototypes for the Tile class.
* \file   main.cpp
* \author Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include "Lookable.hpp"
#include "cardinal.hpp"

#include <string>
#include <iostream>
#include <map>
#include <memory>

class Map;
class Tile : public Lookable {
public:
    Tile() = default;
    Tile(const std::string &name, const std::string &description="");

    const std::string& getName() const;
    const std::string& getDescription() const;
    std::shared_ptr<Tile> getAdjacentTile(cardinal::Direction) const;
    cardinal::Direction getDirection(std::shared_ptr<Tile>) const;
    bool isLinkedTo(cardinal::Direction direction);

    void linkTo(cardinal::Direction direction);
    void unlink(cardinal::Direction direction);
    virtual void show(std::ostream&) const override;

    static void link(std::shared_ptr<Tile>, std::shared_ptr<Tile>);
    
private:
    void setAdjacency(std::shared_ptr<Tile>, cardinal::Direction);

    std::string name_;
    std::string description_;
    std::map<cardinal::Direction, std::shared_ptr<Tile>> adjacentTiles_;
    std::uint8_t linkState_;

    friend Map;
};
