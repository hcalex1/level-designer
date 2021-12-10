#pragma once
#include "Position.hpp"
#include "Exceptions/InvalidDirection.hpp"

template<typename T>
class Navigator {
public:
    Navigator(Position<T>* tile) 

    void move(char direction) {
        if (position_ != none_) {
            if (position_->adjacent_[direction] == none_) {
                position_->adjacent_[direction] = std::make_shared<Position>();
                for (char orthogonal in )
            }
        }
    }

    T& operator*(){
        return position_->tile_;
    }
private:
    Position<T>* = position_;
    friend class Map<T>;
};