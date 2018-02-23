// Exercise 5-2 Summing integers and calculating the average
#include <iostream>
#include <iomanip>
#include <cctype>

int main()
{
  unsigned int count {};
  long long total {};
  
  while (true)
  {
    std::cout << "Enter an integer: ";
    int n;
    std::cin >> n;
    total += n;
    ++count;

    char yesno {};
    std::cout << "Do you want to enter another (y/n)?";
    std::cin >> yesno;
	
    if (std::tolower(yesno) == 'n')
      break;
  }
  
  std::cout << "The total is " << total << std::endl
    << "The average is " << std::setw(10) << std::setprecision(2)
    << std::fixed << (static_cast<double>(total) / count) << std::endl;
}