// Exercise 4-05
// Using the conditional operator to select output.
#include  <iostream>

int main()
{
  int mice {};               // Count of all mice
  int brown {};              // Count of brown mice
  int white {};              // Count of white  mice

  std::cout << "How many brown mice do you have? ";
  std::cin >> brown;
  std::cout << "How many white mice do you have? ";
  std::cin >> white;
  
  if (brown < 0 || white < 0) {
    std::cout << "One cannot have a negative amount of mice. At least not in this program..." << std::endl;
	return 1;
  }

  mice = brown + white;

  std::cout << "You have " << mice
            << (mice == 1? " mouse" : " mice")
            << " in total." << std::endl;

  if (mice == 1)
  {
    std::cout << "It is a " << (brown? "brown" : "white") << " mouse." << std::endl;
  }
  else
  {
    std::cout << "Of these mice, " << brown << ' ' << (brown == 1? "is a" : "are") 
              << " brown " << (brown == 1? "mouse" : "mice") << '.' << std::endl;
  }
}
