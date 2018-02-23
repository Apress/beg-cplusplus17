// Contents.h - Dry contents
#ifndef CONTENTS_H
#define CONTENTS_H
#include <iostream>
#include <string>
#include <string_view>

class Contents
{
protected:
  std::string name {"cereal"};           // Contents type
  double volume {};                      // Cubic inches
  double density {0.03};                 // Pounds per cubic inch

public:
  Contents(std::string_view name, double dens, double vol) 
    : name {name}, density {dens}, volume {vol} 
  { 
    std::cout << "Contents(string_view,double,double) called.\n";
  }

  explicit Contents(std::string_view name) 
    : name {name}
  {
    std::cout << "Contents(string_view) called.\n";
  }

  Contents()  { std::cout << "Contents() called.\n";  }

  // Destructor
  ~Contents()
  {
    std::cout << "Contents destructor" << std::endl;
  }

  // "Get contents weight" function
  double getWeight() const
  {
    return volume * density;
  }
};
#endif
