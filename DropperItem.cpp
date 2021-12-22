/**
* This file consists of definitions for the DropperItem class. 
* \file   Interactive.cpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#include "DropperItem.hpp"
#include "Interactive.hpp"
#include "cardinal.hpp"
#include "Game.hpp"
#include "Navigator.hpp"

#include <iostream>
#include <string>
#include <memory>

using namespace std;
using namespace cardinal;

DropperItem::DropperItem(const string &name, const string &description, 
    const string &dropText, const string &useText, unique_ptr<Interactive> dropedItem)
     : Interactive{name, description}, dropText_(dropText), useText_(useText) {
    dropedItem_ = move(dropedItem);
} 

DropperItem::DropperItem(const DropperItem& other)
    : DropperItem(other.name_, other.description_, other.dropText_, other.useText_, 
    make_unique<Interactive>(*other.dropedItem_)) {}
    
void DropperItem::interact(Game &game, ostream &os) {
    if (Interactive::useCount_ == 0) {
        (*game.getNavigator()).addInteractive(move(dropedItem_));
        os << useText_ << " " << dropText_ << endl;
    }
    else {
        os << useText_ << endl;
    }
    Interactive::useCount_++;
}