/**
* This file consists of definitions for the Object class. 
* \file   Object.cpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#include "Object.hpp"
#include "Lookable.hpp"
#include "Interactible.hpp"

#include <iostream>
#include <string>
#include <functional>

using namespace std;

Object::Object(const std::string& name, const std::string& description) :
    name_(name), description_(description), interactText_("Nothing happens") {}


const std::string& Object::getName() const {
    return name_;
}

const std::string& Object::getDescription() const {
    return description_;
}

void Object::setInteract(const std::function<void(Navigator&, Object&)> interactFunction, 
                std::string interactText) {
    interactText_ = interactText_;
    interactFunction_ = interactFunction;
}

void Object::interact(Navigator& navigator, std::ostream& os) {
    if (&interactFunction_ != nullptr)
        interactFunction_(navigator, *this);
    os << interactText_ << endl;
}

void Object::show(std::ostream& os) const {
    os << description_ << endl;
}