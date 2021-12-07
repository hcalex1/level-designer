/**
* This file constains the declarations and prototypes for the Game class.
* \file   main.cpp
* \author Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#include "Tile.hpp"
#include "Lookable.hpp"

#include <memory>
#include <string>

class Game {
public:
    Game (const std::shared_ptr<Tile>& startTile);

    void look(const Lookable& lookable = defaultLookable_) const;
    void move(char direction);
    void executeCommand(const std::string& proword, const std::string& argument="");
    void start();

    static std::pair<std::string, std::string> parseCommand(const std::string& command);

private:
    std::shared_ptr<Tile> currentTile_;

    inline static const Lookable& defaultLookable_ = Tile{};
};