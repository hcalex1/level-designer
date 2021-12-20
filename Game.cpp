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
#include "Exceptions/InvalidObject.hpp"

#include <memory>
#include <stdexcept>
#include <iostream>
#include <sstream>

using namespace std;
using namespace cardinal;


Game::Game(const Navigator& navigator) : navigator_(navigator) {}

void Game::executeCommand(const string& proword, const string& argument) {
    if (proword.size() == 1) {
        Direction direction = static_cast<Direction>(proword[0]);
        navigator_.move(direction);
        cout << "Going " << directionToString(direction) << "...\n\n";
        commands_["look"](*this, "");
    }
    else {
        try {
            auto command = commands_[proword];
            command(*this, argument);
        }
        catch (bad_function_call& e) {
            throw InvalidCommand("Unknown command");
        }
    }
}

void Game::start() {
    cout << "\
        ╔╦═╦═════╦╦╦══╦══╦══════════╗\n\
        ║║║╚╦═╦═╦╝║╠╦╗║░░╠═╦═╦══╦══╗║\n\
        ║║║╔╣╩╬╝║║║║║║║╔╗╣║║║║║║╠╗╚╣║\n\
        ║╚═╝╚═╩═╩═╩╬╗║╚╝╚╩═╩═╩╩╩╩══╝║\n\
        ╚══════════╩═╩══════════════╝\n\
            by Alex Hoang-Cao & Emile Watier\n\n";
    commands_["look"](*this, "");

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
        catch (InvalidObject& e)    { cout << "That is not an object."  << endl; }
    }
}

pair<string, string> Game::parseCommand(const string& command) {
    size_t split = command.find(" ");
    if (split != string::npos) {
        string proword  = command.substr(0, split);
        string argument = command.substr(split + 1);
        return { proword, argument };
    }
    else {
        return { command, "" };
    }
}

map<string, std::function<void(Game&, const string&)>> Game::commands_ = {
    { "look",
      [] (Game& g, const string& arg) { 
          Navigator &n = g.navigator_;
          if (arg == "")  {
              (*n).show(cout);
              n.show(cout);
          }
          else {
              (*n).getObject(arg).show(cout);
          }
       }
    },
    { "use",
      [] (Game& g, const string& arg) {
          if (arg == "") {
              cout << "The use command requires object name or keyword as argument." << endl;
          }
          else {
              Navigator &n = g.navigator_;
              (*n).getObject(arg).interact(n, cout);
          }
      } 
    },
    { "exit",
      [] ([[maybe_unused]] Game& g,[[maybe_unused]] const string& arg) {
          cout << "Exiting...\n\nThanks for playing!\n";
          g.running_ = false;
      }
    }
};