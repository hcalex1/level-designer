#pragma once
#include "Navigator.hpp"
#include "Position.hpp"

#include <memory>

template<typename T> class Navigator;
template<typename T>
class Map
{
public:
    Map();
    ~Map();

    unsigned size() const; 
    std::pair<int, int> getStartPosition() const;

    void insert(Navigator<T> navigator, const T& item);
    void erase(Navigator<T> navigator);

private:
    std::shared_ptr<Position<T>> startPosition_;
    // std::map<std::pair<int, int>, std::shared_ptr<Position>> positions_;
    friend class Navigator<T>;
};
