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

Object::Object(const std::string& name, const std::string& description) : name_(name),
    description_(description), interactText_("Nothing happens"), interactFunction_(noInteract_) {}


const std::string& Object::getName() const {
    return name_;
}

const std::string& Object::getDescription() const {
    return description_;
}

void Object::setInteract(const std::function<void(Navigator&)> interactFunction, 
                std::string interactText) {
    interactText_ = interactText;
    interactFunction_ = interactFunction;
}

void Object::interact(Navigator& navigator, std::ostream& os) {
    interactFunction_(navigator);
    os << interactText_ << endl;
}

void Object::show(std::ostream& os) const {
    os << description_ << endl;
}

std::function<void(Navigator&)> Object::noInteract_ = [] (Navigator&) {};