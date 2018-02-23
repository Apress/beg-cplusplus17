// Pair.h
#ifndef PAIR_H
#define PAIR_H

#include <ostream>

template <typename First, typename Second>
class Pair
{
public:
  First first;
  Second second;

  Pair();
  Pair(const First& f, const Second& s);
  
  bool operator==(const Pair& other) const;
  bool operator<(const Pair& other) const;
};

// Default constructor
template <typename First, typename Second>
Pair<First, Second>::Pair() : first{}, second{}
{}

// Constructor
template <typename First, typename Second>
Pair<First, Second>::Pair(const First& f, const Second& s)
  : first{f}, second{s}
{}

// Comparison operators
template <typename First, typename Second>
bool Pair<First, Second>::operator==(const Pair& other) const
{
  return first == other.first
      && second == other.second;
}

template <typename First, typename Second>
bool Pair<First, Second>::operator<(const Pair& other) const
{
  return first < other.first
      || (first == other.first && second < other.second);
}

template <typename First, typename Second>
std::ostream& operator<< (std::ostream& stream, const Pair<First, Second>& pair)
{
  return stream << '(' << pair.first << ", " << pair.second << ')';
}

#endif