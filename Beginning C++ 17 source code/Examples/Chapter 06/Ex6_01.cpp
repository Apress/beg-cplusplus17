// The size of pointers
#include <iostream>

int main()
{
  // Print out the size (in number of bytes) of some arbitrary data types 
  // and the corresponding pointer types:
  std::cout << sizeof(double)  << " > "  << sizeof(char)  << std::endl;
  std::cout << sizeof(double*) << " == " << sizeof(char*) << std::endl;
}
