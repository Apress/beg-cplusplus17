// Truckload.h
#ifndef TRUCKLOAD_H
#define TRUCKLOAD_H

#include "Box.h"
#include <vector>
#include <memory>          // For std::shared_ptr<>

using SharedBox = std::shared_ptr<Box>;

class Truckload 
{
private:
  std::vector<SharedBox> boxes;                    // Last in the list
  
public:
  Truckload() = default;                           // No-arg constructor - empty truckload
  Truckload(SharedBox pBox);                       // Constructor - one Box
  Truckload(std::vector<SharedBox> boxes);         // Constructor - vector of Boxes (by value!)
  
  void swap(Truckload& other) noexcept;            // Swap function (noexcept!)
  
  class Iterator
  {
  private:
	std::vector<SharedBox>::const_iterator iter;
	const std::vector<SharedBox>& boxes;

    friend class Truckload;             // Only a Truckload can create an Iterator
    explicit Iterator(const std::vector<SharedBox>& theBoxes)
	  : iter{ theBoxes.end() }
      , boxes{ theBoxes }
    {}

  public:
    SharedBox getFirstBox();            // Get the first Box
    SharedBox getNextBox();             // Get the next Box
  };
  
  Iterator getIterator() const { return Iterator{boxes}; }

  void addBox(SharedBox pBox);          // Add a new Box
  bool removeBox(SharedBox pBox);       // Remove a Box from the Truckload
  
  SharedBox& operator[](size_t index);  // Overloaded subscript operator
  size_t getSize() const;
};

// Stream output operator to replace listBoxes() member
std::ostream& operator<<(std::ostream& stream, const Truckload& load);

#endif

