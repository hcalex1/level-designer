/**
* This file consists of declarations for the DropperItem class. 
* \file   Interactive.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include "Interactive.hpp"

#include <iostream>
#include <string>
#include <memory>

class Game;
class DropperItem : public Interactive {
public:
    DropperItem(const std::string& name, const std::string& description, const std::string& dropText,
        const std::string& dropedText, const std::string& useText, std::unique_ptr<Interactive> dropedItem);
    DropperItem(const DropperItem&);
    virtual ~DropperItem() override = default;
    
    virtual void interact(Game&, std::ostream&) override;

private:
    std::string dropText_;
    std::string dropedText_;
    std::unique_ptr<Interactive> dropedItem_;
};