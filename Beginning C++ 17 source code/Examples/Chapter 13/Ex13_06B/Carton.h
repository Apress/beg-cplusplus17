// Carton.h - defines the Carton class with the Box class as base
#ifndef CARTON_H
#define CARTON_H
#include <string>
#include <string_view>
#include "Box.h"

class Carton : public Box
{
protected:
  std::string material {"Cardboard"};
  double thickness {0.125};                 // Material thickness inches
  double density {0.2};                     // Material density in pounds/cubic inch

public:
  // Constructors
  Carton(double lv, double wv, double hv, std::string_view mat)
    : Box {lv, wv, hv}, material {mat}
  {
    std::cout << "Carton(double,double,double,string_view) called.\n";
  }  

  explicit Carton(std::string_view mat) 
    : material {mat}
  {
    std::cout << "Carton(string_view) called.\n";
  } 
  
  Carton(double side, std::string_view mat)
    : Box {side}, material {mat}
  {
    std::cout << "Carton(double,string_view) called.\n";
  }

  Carton()
  {
    std::cout << "Carton() called.\n";
  }

  Carton(double lv, double wv, double hv, std::string_view mat, double dense, double thick)
    : Carton {lv, wv, hv, mat}
  {
    density = dense;
    thickness = thick;
    std::cout << "Carton(double,double,double,string_view,double,double) called.\n";
  }

  // Copy constructor
  Carton(const Carton& carton)
    : Box {carton}, material {carton.material}
  {
    std::cout << "Carton copy constructor" << std::endl;
  }

  // Destructor
  ~Carton()
  {
    std::cout << "Carton destructor. Material = " << material << std::endl;
  }

  // "Get carton weight" function
  double getWeight() const
  {
    return 2.0*(length*width + width*height + height*length)*thickness*density;
  }
};
#endif
