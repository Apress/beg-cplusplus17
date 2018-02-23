// Exercise 11-8
// Remove Boxes from a Truckload without searching a second time
/*****************************************************************************\
  The key to the solution is that the Iterator object already contains
  a pointer to the Package that needs to be removed.
  Of course, external code cannot use a Package, but it can use the Iterator.
  To exploit the knowledge contained in the Iterator, we add an overload 
  of the removeBox() function with an Iterator parameter instead of a Box.
  Note that the same technique is used by all Standard Library containers!
  
  Once we have this, all we need to do is return an Iterator instead of a
  SharedBox from the two find functions, and add a getCurrentBox() to Iterator.

  Important to notice, moreover, is that our model solution reworked the
  original removeBox() function to use Iterators, and to call the new one
  for the actual removal. This considerably reduces its complexity, 
  and reduces the amount of code that is duplicated in two places!
\*****************************************************************************/
#include <cstdlib>                     // For random number generation
#include <ctime>                       // For the std::time() function
#include "Truckload.h"

SharedBox findLargestBox(const Truckload& truckload);
SharedBox findSmallestBox(const Truckload& truckload);
void addRandomBoxes(Truckload& truckload, size_t num);
void addRandomBoxes(std::vector<SharedBox>& vector, size_t num);

int main()  
{
  std::srand((unsigned)std::time(0));  // Initialize the random number generator

  Truckload load1;                     // Create an empty list
  addRandomBoxes(load1, 12);

  std::cout << "The first list:\n";
  load1.listBoxes();
  std::cout << "In reversed order, this becomes:\n";
  load1.listBoxesReversed();

  // Find the largest Box in the list
  auto largestBox{findLargestBox(load1)};

  std::cout << "\nThe largest box in the first list is ";
  largestBox->listBox();
  std::cout << std::endl;
  load1.removeBox(largestBox);
  std::cout << "\nAfter deleting the largest box, the list contains:\n";
  load1.listBoxes();

  std::vector<SharedBox> boxes;        // Array of Box objects
  addRandomBoxes(boxes, 20);

  Truckload load2{boxes};
  std::cout << "\nThe second list:\n";
  load2.listBoxes();

  std::cout << "\nThe smallest box in the second list is ";
  findSmallestBox(load2)->listBox();
  std::cout << std::endl;
}

SharedBox findLargestBox(const Truckload& truckload)
{
  auto iterator = truckload.getIterator();        // type of iterator is Truckload::Iterator
  SharedBox largestBox{ iterator.getFirstBox() };

  SharedBox nextBox{ iterator.getNextBox() };
  while (nextBox)
  {
    if (nextBox->compare(*largestBox) > 0)
      largestBox = nextBox;
    nextBox = iterator.getNextBox();
  }

  return largestBox;
}

SharedBox findSmallestBox(const Truckload& truckload)
{
  auto iterator = truckload.getIterator();        // type of iterator is Truckload::Iterator
  SharedBox smallestBox{ iterator.getLastBox() };

  SharedBox previousBox{ iterator.getPreviousBox() };
  while (previousBox)
  {
    if (previousBox->compare(*smallestBox) < 0)
      smallestBox = previousBox;
    previousBox = iterator.getPreviousBox();
  }

  return smallestBox;
}

// Function to generate a random integer 1 to count
inline double random(size_t count)
{
  return 1.0 + rand() / (RAND_MAX / count + 1);
}
// Function to generate a Box with random dimensions
inline SharedBox randomBox()
{
  const size_t dimLimit {99};          // Upper limit on Box dimensions
  return std::make_shared<Box>(random(dimLimit), random(dimLimit), random(dimLimit));
}

void addRandomBoxes(Truckload& truckload, size_t boxCount)
{
  for (size_t i {} ; i < boxCount ; ++i)
    truckload.addBox(randomBox());
}

void addRandomBoxes(std::vector<SharedBox>& boxes, size_t nBoxes)
{
  for (size_t i {} ; i < nBoxes ; ++i)
    boxes.push_back(randomBox());
}