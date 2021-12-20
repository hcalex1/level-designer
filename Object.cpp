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

Object::Object(const string& name, const string& description, const string interactText) : name_(name),
    description_(description), interactText_(interactText), interactFunction_(noInteract_) {}


const string& Object::getName() const {
    return name_;
}

const string& Object::getDescription() const {
    return description_;
}

void Object::setInteract(const function<void(Navigator&)> interactFunction) { 
    interactFunction_ = interactFunction;
}

void Object::interact(Navigator& navigator, ostream& os) {
    interactFunction_(navigator);
    os << interactText_ << endl;
}

void Object::show(ostream& os) const {
    os << description_ << endl;
}

function<void(Navigator&)> Object::noInteract_ = [] (Navigator&) {};