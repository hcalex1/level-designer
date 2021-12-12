/**
* This file contains the declarations and prototypes for the Tile class.
* \file   Tile.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include "Lookable.hpp"

#include <string>
#include <iostream>
#include <map>
#include <memory>

class Room : public Lookable {
public:
    Room() = default;
    Room(const std::string &name, const std::string &description="");

    const std::string& getName() const;
    const std::string& getDescription() const;
    virtual void show(std::ostream&) const override;

private:
    std::string name_;
    std::string description_;
};
