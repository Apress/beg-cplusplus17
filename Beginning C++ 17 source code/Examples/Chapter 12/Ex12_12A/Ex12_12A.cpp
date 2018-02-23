// Defining both a copy assignment operator and a copy contructor
#include "Message.h"
#include <iostream>

int main()
{
  Message beware {"Careful"};
  Message warning;

  warning = beware;                       // Call assignment operator
  Message otherWarning{warning};          // Calls the copy constructor

  std::cout << "After assignment beware is: " << beware.getText() << std::endl;
  std::cout << "After assignment warning is: " << warning.getText() << std::endl;
  std::cout << "The copy-constructed otherWarning is: " << otherWarning.getText() << std::endl;
}