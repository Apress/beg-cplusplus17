// Creating and working with Standard iterators
#include <vector>
#include <iostream>

int main()
{
  std::vector<char> letters{ 'a', 'b', 'c', 'd', 'e' };
  auto my_iter{ letters.begin() };

  std::cout << *my_iter << std::endl;       // a

  *my_iter = 'x';
  std::cout << letters[0] << std::endl;     // x

  ++my_iter;                                // Move my_iter to the next element
  std::cout << *my_iter << std::endl;       // b

  my_iter += 2;
  std::cout << *my_iter-- << std::endl;     // d
  std::cout << *my_iter << std::endl;       // c  (my_iter was altered using the post-decrement
											//     operator in the previous statement)
  auto copy{ my_iter };
  my_iter += 2;
  std::cout << *copy << std::endl;           // c
  std::cout << *my_iter << std::endl;        // e
  std::cout << my_iter - copy << std::endl;  // 2
}
