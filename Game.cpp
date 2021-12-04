/**
* This file consists of definitions for the Game class. It has methods to 
* start the game loop, read user input and show information to the user.
* \file   main.cpp
* \author Alex Hoang-Cao
* \date   13 December 2021
* Created 13 December 2021
*/

#include "Game.hpp"
#include "Tile.hpp"
#include "Observable.hpp"
#include "CARDINAL_DIRECTIONS.h"

#include <memory>
#include <stdexcept>
#include <iostream>
#include <sstream>

using namespace std;

Game::Game(const shared_ptr<Tile>& startTile) : currentTile_(startTile) {}

void Game::moveCharacter(char direction) {
    if (currentTile_->getAdjacentTile(direction) == nullptr)
        throw invalid_argument("Direction does not exist");
    if (currentTile_->getAdjacentTile(direction) == Tile::noTile)
        throw domain_error("No tile in this direction");

    cout << "Going " << CARIDINAL_DIRECTIONS.at(direction) << "...\n\n";
    currentTile_ = currentTile_->getAdjacentTile(direction);
    currentTile_->show(cout);
}

void Game::readInput() {
    string input;
    getline(cin, input);

    if (input.size() == 1) {
        moveCharacter(input[0]);
    }
    else {
        stringstream ss(input);
        string command;
        ss >> command;
        if (command == "look")
            currentTile_->show(cout);
        else
            throw invalid_argument("Command does not exist");
    }
}

void Game::start() {
    cout << "\
        ╔╦═╦═════╦╦╦══╦══╦══════════╗\n\
        ║║║╚╦═╦═╦╝║╠╦╗║░░╠═╦═╦══╦══╗║\n\
        ║║║╔╣╩╬╝║║║║║║║╔╗╣║║║║║║╠╗╚╣║\n\
        ║╚═╝╚═╩═╩═╩╬╗║╚╝╚╩═╩═╩╩╩╩══╝║\n\
        ╚══════════╩═╩══════════════╝\n\
            by Alex Hoang-Cao\n\n";

    currentTile_->show(cout);

    while (true) {
        cout << "\n> ";

        try { readInput(); }
        catch (domain_error& e)     { cout << "You can't go there."     << endl; }
        catch (invalid_argument& e) { cout << "I do not know that one." << endl; }
        catch (exception& e)        { cout << "Exception: " << e.what() << endl; }
    }
}