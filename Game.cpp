#include "Game.hpp"
#include "Tile.hpp"
#include "Observable.hpp"
#include "CARDINAL_DIRECTIONS.h"

#include <memory>
#include <stdexcept>
#include <iostream>
#include <sstream>

using namespace std;

Game::Game(Tile &startTile) : currentTile_(startTile) {}

void Game::show(const Observable &observable) const {
    observable.show(cout);
}

void Game::moveCharacter(char direction) {
    if (currentTile_.getAdjacentTile(direction) == nullptr)
        throw invalid_argument("Direction does not exist");
    if (currentTile_.getAdjacentTile(direction) == Tile::noTile)
        throw domain_error("No tile in this direction");

    currentTile_ = *currentTile_.getAdjacentTile(direction);
    cout << "Going " << CARIDINAL_DIRECTIONS.at(direction) << "...\n\n";
    show(currentTile_);
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
            show(currentTile_);
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

    show(currentTile_);

    while (true) {
        cout << "\n> ";

        try { readInput(); }
        catch (domain_error& e)     { cout << "You can't go there."     << endl; }
        catch (invalid_argument& e) { cout << "I do not know that one." << endl; }
        catch (exception& e)        { cout << "Exception: " << e.what() << endl; }
    }
}