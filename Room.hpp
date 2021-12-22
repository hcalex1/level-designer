/**
* This file contains the declarations and prototypes for the Room class.
* \file   Room.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include "Interactive.hpp"
#include "Component.hpp"

#include <string>
#include <iostream>
#include <unordered_map>
#include <memory>

class Room : public Component {
public:
    Room() = default;
    Room(const std::string &name, const std::string &description="");
    Room(const Room&);


    Interactive& getInteractive(const std::string&);
    void addInteractive(std::unique_ptr<Interactive>);
    void removeInteractive(const std::string&);
    void show(std::ostream&) const;

private:
    std::unordered_map<std::string, std::unique_ptr<Interactive>> interactives_;
};
