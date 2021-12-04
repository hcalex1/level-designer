#include "Game.hpp"
#include "Tile.hpp"

#include <memory>
#include <stdexcept>
#include <iostream>

using namespace std;

Game::Game(shared_ptr<Tile> startTile) : characterLocation_(startTile) {}

void Game::moveCharacter(char direction) {
    if (characterLocation_->getAdjacentTile(direction) == Tile::noTile)
        throw domain_error("No tile in that direction");

    characterLocation_ = characterLocation_->getAdjacentTile(direction);
    cout << "Going " << direction << endl;
    characterLocation_->print();
}

void Game::start() {
    cout << "\
        ╔╦═╦═════╦╦╦══╦══╦══════════╗\n\
        ║║║╚╦═╦═╦╝║╠╦╗║░░╠═╦═╦══╦══╗║\n\
        ║║║╔╣╩╬╝║║║║║║║╔╗╣║║║║║║╠╗╚╣║\n\
        ║╚═╝╚═╩═╩═╩╬╗║╚╝╚╩═╩═╩╩╩╩══╝║\n\
        ╚══════════╩═╩══════════════╝\n\
            by Alex Hoang-Cao\n" << endl;

    while (true) {
        characterLocation_->print();
        cout << "\n>";

        try {
            char input;
            cin >> input;
            moveCharacter(input);
        } catch (domain_error& e) {
            cout << "domain_error: " << e.what() << endl;
        } catch (invalid_argument& e) {
            cout << "invalid_argument: " << e.what() << endl;
        } catch (exception& e) {
            cout << "Other exception: " << e.what() <<endl;
        }
    }
}