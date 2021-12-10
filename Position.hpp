#pragma once
#include <memory>

template<typename T> class Map;
template<typename T> class Navigator;
template<typename T>
class Position
{
	public:
		Position(const T& tile = {}) : tile_(tile) {
            adjacents_['N'] = none_;
            adjacents_['E'] = none_;
            adjacents_['S'] = none_;
            adjacents_['W'] = none_;
        }
	private:
		// adjacents_ is a map of adjacent Position. Teh bool indicates if the other Position is linked.
        std::map<char, std::pair<bool, std::shared_ptr<Position<T>>>> adjacents_;
		T tile_;

	inline static constexpr std::pair<bool, Position<T>*> none_ = {False, nullptr};
	friend class Map<T>;
	friend class Navigator<T>;
};
