/**
* This file contains the declarations and prototypes for the Room class.
* \file   Room.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include "Object.hpp"

#include <string>
#include <iostream>
#include <unordered_map>
#include <memory>

class Room {
public:
    Room() = default;
    Room(const std::string &name, const std::string &description="");
    Room(const Room&);

    const std::string& getName() const;
    const std::string& getDescription() const;
    Object& getObject(const std::string&);
    void addObject(const Object&);
    void removeObject(const std::string&);
    void show(std::ostream&) const;

private:
    std::string name_;
    std::string description_;
    std::unordered_map<std::string, std::unique_ptr<Object>> objects_;
};
