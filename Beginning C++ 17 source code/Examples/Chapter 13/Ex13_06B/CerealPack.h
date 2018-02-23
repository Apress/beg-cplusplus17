// Cerealpack.h - Class defining a carton of cereal
#ifndef CEREALPACK_H
#define CEREALPACK_H
#include <iostream>
#include "Carton.h"
#include "Contents.h"

class CerealPack : public Carton, public Contents
{
public:
  CerealPack(double length, double width, double height, std::string_view cerealType)
    : Carton {length, width, height, "cardboard"}, Contents {cerealType} 
  {
    std::cout << "CerealPack constructor" << std::endl;
    Contents::volume = 0.9 * Carton::volume();                 // Set contents volume
  }

  // Destructor
  ~CerealPack()
  {
    std::cout << "CerealPack destructor" << std::endl;
  }
  
  using Carton::volume;
  using Contents::getWeight;
};
#endif
