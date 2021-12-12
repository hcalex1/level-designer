#include "Room.hpp"

#include <string>

using namespace std;

Room::Room(const string &name, const string &description) : 
    name_(name) , description_(description) {}

const string& Room::getName() const {
    return name_;
}

const string& Room::getDescription() const {
    return description_;
}

void Room::show(ostream& os) const {
    os << "-- " << name_ << " --" << endl;
    os << description_ << endl;
}