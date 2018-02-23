// Exercise 18-1. A lambda expression returning the number of vector elements that begin with a given letter.

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

int main()
{
  std::vector<std::string> words{"apple", "pear", "plum", "orange", "peach", "grape", "greengage"};
  std::cout << "Words are:\n";
  for (const auto& word : words)
    std::cout << std::setw(10) << word;
  std::cout << std::endl;

  auto count = [&words](char letter)
  {
    size_t n {};
    for (auto& word : words)
      if (letter == word[0]) ++n;
    return n;
  };
  
  char ch {'p'};
  std::cout << "There are " << count(ch) << " words beginning with " << ch << '.' << std::endl;
  ch = 'g';
  std::cout << "There are " << count(ch) << " words beginning with " << ch << '.' << std::endl;
}