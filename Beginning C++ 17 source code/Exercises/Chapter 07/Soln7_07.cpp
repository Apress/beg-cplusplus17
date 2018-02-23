// Exercise 7-7 
// Relatively easy exercise to practice using string streams to parse given strings

#include <iostream>
#include <sstream>
#include <string> 

int main()
{
  std::string numbers;
  std::cout << "Enter a sequence of numbers terminated by #:\n";
  std::getline(std::cin, numbers, '#');
  
  long sum {};
  
  std::stringstream ss{ numbers };
  while (ss)                            // true as long as the stream is non-empty
  {
    int i {};                           // Extract a number and add it to the sum
	ss >> i;
	sum += i;
  }
  
  std::cout << "The sum of the numbers you entered is: " << sum << std::endl;
}
