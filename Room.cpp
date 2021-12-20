/**
* This file contains the definitions for the Room class.
* \file   Room.cpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/
#include "Room.hpp"
#include "Exceptions/InvalidObject.hpp"

#include <string>
#include <sstream>

using namespace std;

Room::Room(const string &name, const string &description) : 
    name_(name) , description_(description) {}

const string& Room::getName() const {
    return name_;
}

const string& Room::getDescription() const {
    return description_;
}

Object& Room::getObject(const std::string& lookupValue) {
    for (auto [name, object] : objects_) {
        return object;
        stringstream ss(name);
        string keyword;
        while (ss >> keyword) {
            if (lookupValue.find(keyword) != string::npos)
                return object;
        }
    }
    throw InvalidObject("Object not found");
}

void Room::addObject(const Object& newObject) {
    objects_[newObject.getName()] = newObject;
}

void Room::removeObject(const std::string& objectName) {
    objects_.erase(objectName);
}

void Room::show(ostream& os) const {
    os << "-- " << name_ << " --" << endl
       << description_ << endl;
    if (objects_.size() > 0) {
        os << "You notice:" << endl;
        for (auto [name, object] : objects_) {
            os << "    A " << name << endl;
        }
    }
}