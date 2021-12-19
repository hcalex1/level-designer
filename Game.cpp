/**
* This file consists of definitions for the Game class. It has methods to 
* start the game loop, read user input and show information to the user.
* \file   Game.cpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#include "Game.hpp"
#include "Lookable.hpp"
#include "cardinal.hpp"
#include "Exceptions/InvalidCommand.hpp"
#include "Exceptions/InvalidDirection.hpp"
#include "Exceptions/EmptyDirection.hpp"

#include <memory>
#include <stdexcept>
#include <iostream>
#include <sstream>

using namespace std;
using namespace cardinal;


Game::Game(const Navigator& navigator) : navigator_(navigator) {}

void Game::look(const Lookable& lookable) const {
    if (lookable == defaultLookable_) {
        Room &room  = *navigator_;
        room.show(cout);
        navigator_.show(cout);
    }
    else {
        lookable.show(cout);
    }
}

void Game::executeCommand(const string& proword, const string& argument) {
    if (proword.size() == 1) {
        Direction direction = static_cast<Direction>(proword[0]);
        navigator_.move(direction);
        cout << "Going " << cardinal::directionToString(direction) << "...\n\n";
        look();
    }
    else if (proword == "look" && argument == "") {
        cout << "Taking another look... \n\n";
        look();
    }
    else if (proword == "exit" && argument == "") {
        cout << "Exiting...\n\nThanks for playing!\n";
        running_ = false;
    }
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

    while (running_) {
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
    size_t split = command.find(" ");
    if (split != string::npos) {
        string proword  = command.substr(0, split - 1);
        string argument = command.substr(split);
        return { proword, argument };
    }
    else {
        return { command, "" };
    }
}