#ifndef TRUCKLOAD_H
#define TRUCKLOAD_H

#include "Box.h"
#include <vector>
#include <memory>          // For std::shared_ptr<>

using SharedBox = std::shared_ptr<Box>;

class Truckload 
{
private:
  class Package
  {
  public:
    SharedBox pBox;             // Pointer to the Box object contained in this Package
    Package* pNext;             // Pointer to the next Package in the list

    Package(SharedBox pb) : pBox{pb}, pNext{nullptr} {}     // Constructor
    ~Package() { delete pNext; }                            // Destructor
  };

  Package* pHead {};                               // First in the list
  Package* pTail {};                               // Last in the list
  Package* pCurrent {};                            // Last retrieved from the list

public:
  Truckload() = default;                           // Default constructor - empty truckload

  Truckload(SharedBox pBox)                        // Constructor - one Box
  {  pHead = pTail = new Package{pBox}; }

  Truckload(const std::vector<SharedBox>& boxes);  // Constructor - vector of Boxes

  Truckload(const Truckload& src);                 // Copy constructor
  
  ~Truckload() { delete pHead; }                   // Destructor: clean up the list
  
  SharedBox getFirstBox();                         // Get the first Box
  SharedBox getNextBox();                          // Get the next Box
  void addBox(SharedBox pBox);                     // Add a new Box
  bool removeBox(SharedBox pBox);                  // Remove a Box from the Truckload
  void listBoxes() const;                          // Output the Boxes
};

#endif

