#include "Game.hpp"
#include "Tile.hpp"
#include "Interactive.hpp"
#include "CARDINAL_DIRECTIONS.h"

#include <memory>
#include <stdexcept>
#include <iostream>

using namespace std;

Game::Game(const shared_ptr<Tile> &startTile) : currentTile_(startTile) {}

void Game::show(const shared_ptr<Interactive> &object = nullptr) const {
    if (object == nullptr)
        currentTile_->print(cout);
    object->print(cout);
}

void Game::moveCharacter(char direction) {
    if (currentTile_->getAdjacentTile(direction) == nullptr)
        throw invalid_argument("Direction does not exist");
    if (currentTile_->getAdjacentTile(direction) == currentTile_->noTile)
        throw domain_error("No tile in this direction");

    currentTile_ = currentTile_->getAdjacentTile(direction);
    cout << "Going " << CARIDINAL_DIRECTIONS.at(direction) << "...\n\n";
    show();
}

void Game::start() {
    cout << "\
        ╔╦═╦═════╦╦╦══╦══╦══════════╗\n\
        ║║║╚╦═╦═╦╝║╠╦╗║░░╠═╦═╦══╦══╗║\n\
        ║║║╔╣╩╬╝║║║║║║║╔╗╣║║║║║║╠╗╚╣║\n\
        ║╚═╝╚═╩═╩═╩╬╗║╚╝╚╩═╩═╩╩╩╩══╝║\n\
        ╚══════════╩═╩══════════════╝\n\
            by Alex Hoang-Cao\n\n";

    show();

    while (true) {
        cout << "\n> ";

        try {
            string input;
            getline(cin, input);

            if (input.size() == 1) {
                moveCharacter(input[0]);
            }
            else if (input == "look") {
                show();
            }
            else{
                invalid_argument("Command does not exist");
            }
        } catch (domain_error& e) {
            cout <<  "You can't go there." << endl;
        } catch (invalid_argument& e) {
            cout << "I do not know that one." << endl;
        } catch (exception& e) {
            cout << "Exception: " << e.what() << endl;
        }
    }
}