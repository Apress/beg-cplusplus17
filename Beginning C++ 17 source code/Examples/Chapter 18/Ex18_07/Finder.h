// Finder.h - A small class to illustrate the use of lambda expression in member functions
#ifndef FINDER_H
#define FINDER_H

#include <vector>
#include <optional>

class Finder
{
public:
  int getNumberToSearchFor() const;
  void setNumberToSearchFor(int n);

  std::optional<int> findNearest(const std::vector<int>& values) const;
private:
  int number_to_search_for {};
};

#endif