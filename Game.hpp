/**
* This file contains the declarations and prototypes for the Game class.
* \file   Game.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include "Room.hpp"
#include "Navigator.hpp"

#include <string>
#include <functional>

class Game {
public:
    Game (const Navigator&);

    Navigator& getNavigator();

    void executeCommand(const std::string& proword, const std::string& argument="");
    void start();

    static std::pair<std::string, std::string> parseCommand(const std::string& command);

    void look(const std::string&);

private:
    bool running_ = true;
    Navigator navigator_;

    static std::unordered_map<std::string, std::function<void(Game&, const std::string&)>> commands_;
};