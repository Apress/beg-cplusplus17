// Exercise 15-4 
/* Somewhat artificial example to practice lists of different, 
 * related exception types (mind the order + catch-by-reference!)
 * and rethrowing (catch-by-reference + "throw;" !)
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "CurveBall.h"
#include "DomainExceptions.h"


size_t random(size_t count);  // Function to generate a random integer 0 to count-1
void sometimes();             // Throw a CurveBall exception 25% of the time
void askEvenNumber();         // Ask the user to provide an even number
int readEvenNumber();         // Helper used by askEvenNumber(); reads an even number 
                              // from std::cin and verifies the input (throws upon failure)

int main()
{
  try
  {
    askEvenNumber();
  }
  catch (CurveBall& caught)
  {
	std::cerr << "...hit it out of the park!" << std::endl;
  }
}

// Function to generate a random integer 0 to count-1
size_t random(size_t count)
{
  return static_cast<size_t>(rand() / (RAND_MAX / count + 1));
}

// Throw a CurveBall exception 25% of the time
void sometimes()
{
  if (random(100) < 25)
    throw CurveBall{};
}

// Option 1: use recursion
void askEvenNumber()
{
  try
  {
    std::cout << "Please enter an even number: ";
	readEvenNumber();
  }
  catch (NotANumber& nan)
  {
	std::cerr << nan.what() << std::endl;
	return;
  }
  catch (std::domain_error& domainException)
  {
	std::cerr << domainException.what() << std::endl;
	askEvenNumber();	// Recursive call
  }
  catch (std::exception& exception)
  {
    std::cerr << exception.what() << std::endl;
    throw;
  }
}

/*
// Option 2: use a loop
void askEvenNumber()
{
  bool repeat = false;
  do
  {
    try
    {
      std::cout << "Please enter an even number: ";
    }
    catch (NotANumber& nan)
    {
      std::cerr << nan.what() << std::endl;
      return;
    }
    catch (std::out_of_range& range)
    {
      std::cerr << range.what() << std::endl;
      repeat = true;
    }
    catch (std::exception& exception)
    {
      std::cerr << exception.what() << std::endl;
      throw;
    }
  }
  while (repeat);
}
*/

int readEvenNumber()
{
  int number;
  std::cin >> number;
  if (std::cin.fail())  // Check whether the user has effectively entered a number
  {
    std::cin.clear();	// Reset the stream's failure state
    std::string line;	// Read the erroneous input and discard it
    std::getline(std::cin, line);
    throw NotANumber{line};
  }
  
  sometimes();
  
  if (number < 0)
    throw NegativeNumber{number};
  if (number % 2)
	throw OddNumber{number};

  return number;
}
