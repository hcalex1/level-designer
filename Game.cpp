/**
* This file consists of definitions for the Game class. It has methods to 
* start the game loop, read user input and show information to the user.
* \file   main.cpp
* \author Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#include "Game.hpp"
#include "Tile.hpp"
#include "Lookable.hpp"
#include "cardinalDirection.hpp"
#include "Exceptions/EmptyDirection.hpp"
#include "Exceptions/InvalidCommand.hpp"
#include "Exceptions/InvalidDirection.hpp"

#include <stdexcept>
#include <iostream>
#include <sstream>

using namespace std;


Game::Game(Map& map) : 
    map_(map), coordinates_(map.getStartPosition()) {}

void Game::look(const Lookable& lookable) const {
    if (lookable == defaultLookable_)
        map_.getTile(coordinates_).show(cout);
        // TODO look at surrounding Tiles
    else
        lookable.show(cout);
}

void Game::move(cardinalDirection direction) {
    if (map_.getTile(coordinates_).isLinked(direction)) {
        pair<int, int> directionVector = cardinalToVector.at(direction);
        coordinates_.first += directionVector.first;
        coordinates_.second += directionVector.second;
    }
    else
        throw EmptyDirection("No tile in this direction");

    cout << "Going " << cardinalToString.at(direction) << "...\n\n";
    look();
}

void Game::executeCommand(const string& proword, const string& argument) {
    if (proword.size() == 1)
        move(charToCardinal.at(proword[0]));
    else if (proword == "look" && argument == "")
        look();
    else
        throw InvalidCommand("Unknown command");
}

void Game::start() {
    cout << "\
        ╔╦═╦═════╦╦╦══╦══╦══════════╗\n\
        ║║║╚╦═╦═╦╝║╠╦╗║░░╠═╦═╦══╦══╗║\n\
        ║║║╔╣╩╬╝║║║║║║║╔╗╣║║║║║║╠╗╚╣║\n\
        ║╚═╝╚═╩═╩═╩╬╗║╚╝╚╩═╩═╩╩╩╩══╝║\n\
        ╚══════════╩═╩══════════════╝\n\
            by Alex Hoang-Cao & Emile Watier\n\n";
    look();

    while (true) {
        cout << "\n> ";

        try { 
            string playerInput;
            getline(cin, playerInput);

            auto&& [proword, argument] = parseCommand(playerInput);
            executeCommand(proword, argument);
        }
        catch (EmptyDirection& e)   { cout << "You can't go there."     << endl; }
        catch (InvalidCommand& e)   { cout << "I do not know that one." << endl; }
        catch (InvalidDirection& e) { cout << "I do not know that one." << endl; }
    }
}

pair<string, string> Game::parseCommand(const string& command) {
    int split = command.find(" ");
    if (split != string::npos) {
        string proword  = command.substr(0, split - 1);
        string argument = command.substr(split);
        return { proword, argument };
    }
    else {
        return { command, "" };
    }
}