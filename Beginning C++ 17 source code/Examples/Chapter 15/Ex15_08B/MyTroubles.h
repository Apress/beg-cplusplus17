// MyTroubles.h Exception classes
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
  virtual ~Trouble() = default;    // Base classes must always have a virtual destructor!
  
  virtual std::string_view what() const noexcept { return message; }
};

// Derived exception class
class MoreTrouble : public Trouble 
{
public:
  MoreTrouble(std::string_view str = "There's more trouble...") : Trouble {str} {}
};

// Derived exception class
class BigTrouble : public MoreTrouble 
{
public:
  BigTrouble(std::string_view str = "Really big trouble...") : MoreTrouble {str} {}
};

#endif