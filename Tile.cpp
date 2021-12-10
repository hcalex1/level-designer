/**
* This file consists of definitions for the Tile class.
* \file   main.cpp
* \author Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#include "Tile.hpp"
#include "cardinalDirection.hpp"
#include "Exceptions/InvalidDirection.hpp"

#include <string>
#include <memory>
#include <iostream>

using namespace std;

Tile::Tile() : linkState_(0) {}

Tile::Tile(const string &name, const string &description) : 
    name_(name), description_(description), linkState_(0) {}

const string& Tile::getName() const {
    return name_;
}

const string& Tile::getDescription() const {
    return description_;
}

bool Tile::isLinked(cardinalDirection direction) {
    return linkState_ & direction;
}

void Tile::link(cardinalDirection direction) {
    linkState_ += direction;
}

void Tile::unlink(cardinalDirection direction) {
    linkState_ -= direction;
}

void Tile::show(ostream& os) const {
    os << "-- " << name_ << " --" << endl;
    os << description_ << endl;
}