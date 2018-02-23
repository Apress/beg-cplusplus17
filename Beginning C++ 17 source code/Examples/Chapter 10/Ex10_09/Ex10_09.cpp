// Demonstrating assertions
#include <iostream>
#include <cassert>
int main()
{
  int y{5};

  for (int x{}; x < 20; ++x)
  {
    std::cout << "x = " << x << " y = " << y << std::endl;
    assert(x < y);
  }
}
