#pragma once

#include <string>

class Component {
public:
	Component() = default;
	Component(const std::string& name, const std::string& description) {
		name_ = name, description_ = description; };

	virtual ~Component() = default;

	const std::string& getName()        const { return name_; };
	const std::string& getDescription() const { return description_; };


	virtual void show(std::ostream& os) const = 0;

protected:
	std::string name_;
	std::string description_;
};