// MyTroubles.h Exception class definition
#ifndef MYTROUBLES_H
#define MYTROUBLES_H
#include <string>
#include <string_view>

class Trouble
{
private:
  std::string message;
public:
  Trouble(std::string_view str = "There's a problem") : message {str} {}
  
  std::string_view what() const { return message; }
};

#endif
