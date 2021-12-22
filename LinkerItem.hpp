/**
* This file consists of declarations for the LinkerItem class. 
* \file   Interactive.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include "Interactive.hpp"
#include "cardinal.hpp"

#include <iostream>
#include <string>

class Game;
class LinkerItem : public Interactive {
public:
    LinkerItem(const std::string&, const std::string&, cardinal::Direction); 
    virtual ~LinkerItem() override = default;
    
    virtual void interact(Game&, std::ostream&) override;

private:
    cardinal::Direction linkDirection_;
};