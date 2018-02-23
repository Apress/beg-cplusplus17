// Exercise 16-2
// Create a basic Pair template
#include "Pair.h"
#include <iostream>
#include <string>

int main()
{
  auto my_pair = Pair<int, std::string>(122, "abc");
  ++my_pair.first;
  std::cout << "my_pair equals (" << my_pair.first 
            << ", " << my_pair.second << ')' << std::endl;

  auto pair1 = Pair<int, std::string>(  0, "def");
  auto pair2 = Pair<int, std::string>(123, "abc");
  auto pair3 = Pair<int, std::string>(123, "def");

  std::cout << (pair1 < pair2 && pair2 < pair3? "operator< seems to be working" : "oops") << std::endl;
  std::cout << (pair1 == pair2? "oops" : "operator== works as well") << std::endl;
}