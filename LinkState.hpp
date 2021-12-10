#pragma once

#include "cardinalDirection.h"

#include <cstdint>

class LinkState {
public:
    LinkState() : state_(0) {}

    enum cardinalDirection {
        NORTH = 0x01,
        EAST  = 0x02,
        SOUTH = 0x04,
        WEST  = 0x08,
    };

    bool isLinked(cardinalDirection direction) {
        return state_ & direction;
    }

    void link(cardinalDirection direction) {
        return state_ += direction;
    }

    void unlink(cardinalDirection direction) {
        return state_ -= direction;
    }

private:
    std::uint8_t state_;
};