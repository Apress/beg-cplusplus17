// Using return to exit a stitch statement (and the program)
// (This is just to show it is possible: don't code like this!)
#include <iostream>
#include <cctype>

int main()
{
  char letter {};
  std::cout << "Enter a letter: ";
  std::cin >> letter;

  if (std::isalpha(letter))
  {
    switch (std::tolower(letter))
    {
    case 'a': case 'e': case 'i': case 'o': case 'u':
      std::cout << "You entered a vowel." << std::endl;
      return 0;
    }
	
	std::cout << "You entered a consonant." << std::endl;
  }
  else
  {
    std::cout << "You did not enter a letter." << std::endl;
  }
}
