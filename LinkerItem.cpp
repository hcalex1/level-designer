/**
* This file consists of definitions for the LinkerItem class. 
* \file   Interactive.cpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#include "LinkerItem.hpp"
#include "Interactive.hpp"
#include "cardinal.hpp"
#include "Game.hpp"
#include "Navigator.hpp"

#include <iostream>
#include <string>

using namespace std;
using namespace cardinal;

LinkerItem::LinkerItem(const string &name, const string &description, Direction linkDirection)
    : Interactive{name, description}, linkDirection_(linkDirection) {} 
    
void LinkerItem::interact(Game &game, ostream &os) {
    if (Interactive::useCount_ == 0) {
        Navigator navigator = game.getNavigator();
        game.getNavigator().link(linkDirection_); 
        os << (*navigator).getName() << " is now connected to " 
            << navigator.getRoom(linkDirection_).getName() << endl;
    }
    else {
        os << "Nothing happens...\n";
    }
    Interactive::useCount_++;
}