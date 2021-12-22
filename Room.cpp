/**
* This file contains the definitions for the Room class.
* \file   Room.cpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/
#include "Room.hpp"
#include "Exceptions/InvalidInteractive.hpp"

#include <string>
#include <sstream>
#include <memory>

using namespace std;

Room::Room(const string &name, const string &description) : 
    name_(name) , description_(description) {}

Room::Room(const Room& other) : 
    name_(other.name_) , description_(other.description_) {
        for (auto&& [name, interactive] : interactives_) {
            interactives_[name_] = make_unique<Interactive>(*interactive);
        }
    }

const string& Room::getName() const {
    return name_;
}

const string& Room::getDescription() const {
    return description_;
}

Interactive& Room::getInteractive(const std::string& lookupValue) {
    for (auto&& [name, Interactive] : interactives_) {
        stringstream ss(name);
        string keyword;
        while (ss >> keyword) {
            if (lookupValue.find(keyword) != string::npos)
                return *Interactive;
        }
    }
    throw InvalidInteractive("Interactive not found");
}

void Room::addInteractive(unique_ptr<Interactive> newInteractive) {
    interactives_[newInteractive->getName()] = move(newInteractive);
}

void Room::removeInteractive(const std::string& InteractiveName) {
    interactives_.erase(InteractiveName);
}

void Room::show(ostream& os) const {
    os << "\n-- " << name_ << " --" << endl
       << description_ << endl;
    if (interactives_.size() > 0) {
        os << "You notice:" << endl;
        for (auto&& [name, Interactive] : interactives_) {
            os << "    A " << name << endl;
        }
    }
}