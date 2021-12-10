/**
* This file constains the declarations and prototypes for the Tile class.
* \file   main.cpp
* \author Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include "Lookable.hpp"
#include "cardinalDirection.hpp"

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
    bool isLinked(cardinalDirection direction);

    void link(cardinalDirection direction);

    void unlink(cardinalDirection direction);

    virtual void show(std::ostream&) const override;

private:
    std::string name_;
    std::string description_;
    std::uint8_t linkState_;
};
