/**
* This file contains a map of char to string  for cardinal directions.
* \file   main.cpp
* \author Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/
#pragma once

#include "Exceptions/InvalidDirection.hpp"

#include <map>
#include <string>

enum cardinalDirection { NORTH = 0x01, EAST  = 0x02, SOUTH = 0x04, WEST  = 0x08 };

cardinalDirection getCardinalFromChar(char c) {
    switch (c) {
    case 'N' : return NORTH;
    case 'E' : return EAST;
    case 'S' : return SOUTH;
    case 'W' : return WEST;
    default  : throw InvalidDirection("Direction must be chars 'N' 'E' 'S' or 'W'");
    }
}

const std::map<char, cardinalDirection> charToCardinal = {{'N', NORTH},
                                                          {'E', EAST},
                                                          {'S', SOUTH},
                                                          {'W', WEST}};

const std::map<cardinalDirection, std::string> cardinalToString = {{NORTH, "North"},
                                                                   {EAST,  "East"},
                                                                   {SOUTH, "South"},
                                                                   {WEST,  "West"}};

const std::map<cardinalDirection, char> cardinalToChar = {{NORTH, 'N'},
                                                          {EAST,  'E'},
                                                          {SOUTH, 'S'},
                                                          {WEST,  'W'}};


const std::map<cardinalDirection, std::pair<int, int>> cardinalToVector = {{NORTH, { 0, 1}},
                                                                           {EAST,  { 1, 0}},
                                                                           {SOUTH, { 0,-1}},
                                                                           {WEST,  {-1, 0}}};