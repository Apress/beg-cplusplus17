#include "Truckload.h"

// Constructor
Truckload::Truckload(const std::vector<SharedBox>& boxes)
{
  for (auto pBox : boxes)
  {
    addBox(pBox);
  }
}

// Output all Box objects in the list
void Truckload::listBoxes() const
{
  const size_t boxesPerLine = 5;
  size_t count {};  
  for (Package* package{pHead}; package; package = package->pNext)
  {
    package->pBox->listBox();
    if (! (++count % boxesPerLine)) std::cout << std::endl;
  }
  if (count % boxesPerLine) std::cout << std::endl;
}

// Output all Box objects in the list in reversed order
void Truckload::listBoxesReversed() const
{
  const size_t boxesPerLine = 5;
  size_t count {};  
  for (Package* package{pTail}; package; package = package->pPrevious)
  {
    package->pBox->listBox();
    if (! (++count % boxesPerLine)) std::cout << std::endl;
  }
  if (count % boxesPerLine) std::cout << std::endl;
}

// Get the first Box
SharedBox Truckload::Iterator::getFirstBox()
{
  // Return pHead's box (or nullptr if the list is empty)
  return pHead ? pHead->pBox : nullptr;
}

// Get the last box
SharedBox Truckload::Iterator::getLastBox()
{
	// Return pTail's box (or nullptr if the list is empty)
	return pTail ? pTail->pBox : nullptr;
}

// Get the next Box
SharedBox Truckload::Iterator::getNextBox()    
{
  if (!pCurrent)                                   // If there's no current...
    return getFirstBox();                          // ...return the 1st Box

  pCurrent = pCurrent->pNext;                      // Move to the next package
  
  return pCurrent? pCurrent->pBox : nullptr;       // Return its box (or nullptr...).
}

// Get the previous Box
SharedBox Truckload::Iterator::getPreviousBox()    
{
  if (!pCurrent)                                   // If there's no current...
    return getLastBox();                           // ...return the last Box

  pCurrent = pCurrent->pPrevious;                  // Move to the previous package
  
  return pCurrent? pCurrent->pBox : nullptr;       // Return its box (or nullptr...).
}

// Add a Box to the list
void Truckload::addBox(SharedBox pBox)
{
  auto pPackage = new Package{pBox, pTail};  // Create a new Package (previous is always the tail)

  if (pTail)                               // Check list is not empty
    pTail->pNext = pPackage;               // Add the  new  object to the tail
  else                                     // List is empty
    pHead = pPackage;                      // so new object is the head

  pTail = pPackage;                        // Store its address as tail
}

// Find the Package containing pBox and delete it from the list
bool Truckload::removeBox(SharedBox boxToRemove)
{	
  // initialize current to the head of the list
  for (Package* current {pHead}; current; current = current->pNext)
  {
    if (current->pBox == boxToRemove)          // We found the Box!
    {
      if (current->pPrevious)                  // If there is a previous Package...
      {
        current->pPrevious->pNext = current->pNext;  // ... make it point to the next one (if any) 
      }
      else
      {                                        // If there is no previous, we are removing the 
        pHead = current->pNext;                // first Package in the list, so update pHead
      }
	  
	  if (current->pNext)                      // If there is a next Package...
	  {
		current->pNext->pPrevious = current->pPrevious;   // ... make it point the previous one (if any)
	    current->pNext = nullptr;              // Set pNext to null to prevent use during deletion
	  }
      
      delete current;                          // delete it
      return true;                             // Return true: we found and removed the box
    }
  }

  return false;                                // Return false: boxToRemove was not found
}
