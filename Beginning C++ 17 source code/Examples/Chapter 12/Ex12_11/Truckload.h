#ifndef TRUCKLOAD_H
#define TRUCKLOAD_H

#include <vector>
#include <memory>          // For std::shared_ptr<>
#include "Box.h"

using SharedBox = std::shared_ptr<Box>;

class Truckload 
{
private:
  static SharedBox nullBox;                        // Pointer to nullptr
  
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
  
public:
  Truckload() = default;                           // No-arg constructor - empty truckload

  Truckload(SharedBox pBox)                        // Constructor - one Box
  {  pHead = pTail = new Package{pBox}; }

  Truckload(const std::vector<SharedBox>& boxes);  // Constructor - vector of Boxes

  Truckload(const Truckload& src);                 // Copy constructor
  
  ~Truckload() { delete pHead; }                   // Destructor: clean up the list

  class Iterator
  {
  private:
    Package* pHead;                     // The head of the linked list (needed for getFirstBox())
    Package* pCurrent;                  // The package whose Box was last retrieved

    friend class Truckload;             // Only a Truckload can create an Iterator
    explicit Iterator(Package* head) : pHead{head}, pCurrent{nullptr} {}

  public:
    SharedBox getFirstBox();            // Get the first Box
    SharedBox getNextBox();             // Get the next Box
  };
  
  Iterator getIterator() const { return Iterator{pHead}; }

  void addBox(SharedBox pBox);          // Add a new Box
  bool removeBox(SharedBox pBox);       // Remove a Box from the Truckload
  
  SharedBox& operator[](size_t index);  // Overloaded subscript operator
};

// Stream output operator to replace listBoxes() member
std::ostream& operator<<(std::ostream& stream, const Truckload& load);

#endif

