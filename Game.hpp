/**
* This file constains the declarations and prototypes for the Game class.
* \file   main.cpp
* \author Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#include "Lookable.hpp"
#include "Room.hpp"
#include "Navigator.hpp"

#include <memory>
#include <string>

class Game {
public:
    Game (const Navigator&);

    void look(const Lookable& lookable = defaultLookable_) const;
    void executeCommand(const std::string& proword, const std::string& argument="");
    void start();

    static std::pair<std::string, std::string> parseCommand(const std::string& command);

private:
    Navigator navigator_;
    inline static const Lookable& defaultLookable_ = Room{};
};