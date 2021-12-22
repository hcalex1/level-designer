/**
* This file consists of the Lookable abstract class. All classes that 
* can be observed by the player will be derived from this class.
* \file   Lookable.hpp
* \authors Alex Hoang-Cao and Emile Watier
* \date   13 December 2021
* Created 13 December 2021
*/

#pragma once

#include <string>

class Lookable {
public:
	Lookable() = default;
	Lookable(const std::string& name, const std::string& description) {
		name_ = name, description_ = description; };

	virtual ~Lookable() = default;

	const std::string& getName()        const { return name_; };
	const std::string& getDescription() const { return description_; };


	virtual void show(std::ostream& os) const = 0;

protected:
	std::string name_;
	std::string description_;
};