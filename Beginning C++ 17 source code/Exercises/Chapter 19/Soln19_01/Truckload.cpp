#include "Truckload.h"

#include <stdexcept>
#include <string>
#include <algorithm>    // for std::remove()

// Constructor - one Box
Truckload::Truckload(SharedBox box)
  : boxes{ 1, box }
{
}

// Constructor - vector of Boxes
Truckload::Truckload(std::vector<SharedBox> theBoxes)
  : boxes{ std::move(theBoxes) }
{
}

void Truckload::swap(Truckload& other) noexcept
{
  boxes.swap(other.boxes);
}

// Get the first Box
SharedBox Truckload::Iterator::getFirstBox()
{
  // Return the first box (or nullptr if the vector is empty)
  iter = boxes.begin();
  return iter == boxes.end()? nullptr : *iter;
}

// Get the next Box
SharedBox Truckload::Iterator::getNextBox()    
{
  if (iter == boxes.end())                         // If we're at the end (as when first constructed)...
    return getFirstBox();                          // ...return the 1st Box

  ++iter;                                          // Move to the next box
  
  return iter == boxes.end() ? nullptr : *iter;    // Return its box (or nullptr...).
}

// Add a Box to the list
void Truckload::addBox(SharedBox pBox)
{
  boxes.push_back(pBox);
}

// Find the Package containing pBox and delete it from the list
bool Truckload::removeBox(SharedBox boxToRemove)
{
  // Use the remove-erase idiom:
  // First we obtain an iterator to the first removed element
  auto removed = std::remove(begin(boxes), end(boxes), boxToRemove);
  
  // Keep track whether something was found to remove (do this before erasing!)
  const bool result = removed != end(boxes);
  
  // Erase all removed elements (if any) from the vector<> container.
  boxes.erase(removed, end(boxes));

  return result;
}

// Overloaded subscript operator
SharedBox& Truckload::operator[](size_t index)
{
  return boxes[index];
}

size_t Truckload::getSize() const
{
  return boxes.size();
}

// Stream output operator to replace listBoxes() member
std::ostream& operator<<(std::ostream& stream, const Truckload& load)
{
  size_t count {};
  auto iterator = load.getIterator();
  for (auto box = iterator.getFirstBox(); box; box = iterator.getNextBox())
  {
    std::cout << *box;
    if (!(++count % 5)) std::cout << std::endl;
  }
  if (count % 5) std::cout << std::endl;
  return stream;
}

void swap(Truckload& one, Truckload& other) noexcept
{
  one.swap(other);  // Simply forward to member function
}

