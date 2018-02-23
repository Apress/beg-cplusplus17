#ifndef PACKAGE_H
#define PACKAGE_H
#include <memory>
#include "Box.h"

using SharedBox = std::shared_ptr<Box>;

class Package
{
private:
  SharedBox pBox;             // Pointer to the Box object contained in this Package
  Package* pNext;             // Pointer to the next Package in the list

public:
  Package(SharedBox pb) : pBox{pb}, pNext{nullptr} {}     // Constructor
  ~Package() { delete pNext; }                            // Destructor

  // Retrieve the Box pointer
  SharedBox getBox() const { return pBox; } 
  
  // Retrieve or update the pointer to the next Package 
  Package* getNext() { return pNext; }
  void setNext(Package* pPackage) { pNext = pPackage; }
};
#endif
