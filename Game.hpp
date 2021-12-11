/**
* This file contains the declarations and prototypes for the Game class.
* \file   Game.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include "Lookable.hpp"
#include "Tile.hpp"
#include "Navigator.hpp"

#include <memory>
#include <string>

class Game {
public:
    Game (const std::shared_ptr<Tile>& startTile);

    void look(const Lookable& lookable = defaultLookable_) const;
    void executeCommand(const std::string& proword, const std::string& argument="");
    void start();

    static std::pair<std::string, std::string> parseCommand(const std::string& command);

private:
    bool running_ = true;
    Navigator navigator_;
    inline static const Lookable& defaultLookable_ = Tile{};
};