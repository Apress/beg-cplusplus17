// Using a static assertion
#include <vector>
#include <iostream>
#include <string>
#include "average.h"

int main()
{
   std::vector<double> vectorData {1.5, 2.5, 3.5, 4.5};
   std::cout << "The average of vectorData is " << average(vectorData) << std::endl;

// Uncomment the next lines for compiler errors...
//   std::vector<std::string> words {"this", "that", "them", "those"};
//   std::cout << "The average of words values is " << average(words) << std::endl;

   std::vector<float> emptyVector;
   average(emptyVector);		// Will trigger a runtime assertion!
}
