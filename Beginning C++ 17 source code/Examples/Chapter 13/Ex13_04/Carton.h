// Carton.h - defines the Carton class with the Box class as base
#ifndef CARTON_H
#define CARTON_H
#include <string>
#include <string_view>
#include "Box.h"

class Carton : public Box
{
using Box::Box;                               // Inherit Box class constructors

private:
  std::string material {"Cardboard"};

public:
  Carton(double lv, double wv, double hv, std::string_view mat) 
     : Box {lv, wv, hv}, material {mat}
     { std::cout << "Carton(double,double,double,string_view) called.\n"; } 
	 
//  Carton() = default;                   // Uncomment if you want a default constructor for Carton 
};

#endif
