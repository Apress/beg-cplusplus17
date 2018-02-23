// Truckload.h
#ifndef TRUCKLOAD_H
#define TRUCKLOAD_H

#include <vector>
#include <memory>          // For std::shared_ptr<>
#include "Box.h"

using SharedBox = std::shared_ptr<Box>;

class Truckload 
{
private:
  class Package
  {
  public:
    SharedBox pBox;             // Pointer to the Box object contained in this Package
    Package* pNext;             // Pointer to the next Package in the list
	Package* pPrevious;         // Pointer to the previous Package in the list

    Package(SharedBox pb, Package* previous = nullptr)      // Constructor
	  : pBox{pb}, pNext{nullptr}, pPrevious{previous} {}
    ~Package() { delete pNext; }                            // Destructor
  };

  Package* pHead {};                               // First in the list
  Package* pTail {};                               // Last in the list
  
public:
  Truckload() = default;                           // No-arg constructor - empty truckload

  Truckload(SharedBox pBox)                        // Constructor - one Box
  {  pHead = pTail = new Package{pBox}; }

  Truckload(const std::vector<SharedBox>& boxes);  // Constructor - vector of Boxes
  
  ~Truckload() { delete pHead; }                   // Destructor: clean up the list

  class Iterator
  {
  private:
    Package* pHead;               // The head of the linked list (needed for getFirstBox())
	Package* pTail;               // The tail of the linked list (needed for getLastBox())
    Package* pCurrent;            // The package whose Box was last retrieved

    friend class Truckload;       // Only a Truckload can create an Iterator
    explicit Iterator(const Truckload* load) 
	  : pHead{load->pHead}, pTail{load->pTail}, pCurrent{nullptr} {}

  public:
    SharedBox getFirstBox();      // Get the first Box
    SharedBox getNextBox();       // Get the next Box
	SharedBox getCurrentBox();    // Get the current Box
	SharedBox getLastBox();       // Get the last Box
	SharedBox getPreviousBox();   // Get the previous Box
  };
  
  Iterator getIterator() const { return Iterator{this}; }

  void addBox(SharedBox pBox);                     // Add a new Box
  bool removeBox(SharedBox pBox);                  // Remove a Box from the Truckload
  bool removeBox(Iterator iterator);               // Remove the Box that was last returned by the given Iterator
  void listBoxes() const;                          // Output the Boxes
  void listBoxesReversed() const;                  // Output the Boxes in reversed order
};

#endif

