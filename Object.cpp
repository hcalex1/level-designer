/**
* This file consists of definitions for the Object class. 
* \file   Object.cpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#include "Object.hpp"
#include "Lookable.hpp"

#include <iostream>
#include <string>
#include <functional>

using namespace std;

Object::Object(const string& name, const string& description) : name_(name),
    description_(description), useCount_(0), interactFunction_(noInteract_) {}


const string& Object::getName() const {
    return name_;
}

const string& Object::getDescription() const {
    return description_;
}

void Object::setInteract(const function<void(Game&, unsigned, ostream&)> interactFunction) { 
    interactFunction_ = interactFunction;
}

void Object::interact(Game& game, ostream& os) {
    interactFunction_(game, useCount_, os);
    useCount_++;
}

void Object::show(ostream& os) const {
    os << description_ << endl;
}

function<void(Game&, unsigned, ostream&)> Object::noInteract_ = 
    [] (Game&, unsigned, ostream&) {};