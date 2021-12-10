/**
* This file contains a map of char to string  for cardinal directions.
* \file   main.cpp
* \author Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#include <map>
#include <string>

enum cardinalDirection {
    NORTH = 0x01,
    EAST  = 0x02,
    SOUTH = 0x04,
    WEST  = 0x08,
};

const std::map<char, cardinalDirection> charToCardinal = {{'N', NORTH},
                                                           {'E', EAST},
                                                           {'S', SOUTH},
                                                           {'W', WEST}};

const std::map<cardinalDirection, std::string> cardinalToString = {{NORTH, "North"},
                                                                   {EAST,  "East"},
                                                                   {SOUTH, "South"},
                                                                   {WEST,  "West"}};

const std::map<cardinalDirection, char> cardinalToChar = {{NORTH, 'N'},
                                                           {EAST, 'E'},
                                                           {SOUTH, 'S'},
                                                           {WEST, 'W'}};