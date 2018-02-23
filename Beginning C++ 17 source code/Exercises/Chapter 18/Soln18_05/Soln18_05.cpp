// Exercise 18-5. 
// Using callback functions to implement the so-called observer pattern,
// where a callback function is called whenever a certain event occurs (in this case: when a Box is delivered)

#include <iostream>
#include "DeliveryTruck.h"

void logDelivary(SharedBox box)
{
  std::cout << "The box " << *box << " was delivered. On time, as always!" << std::endl;
}

// Function to generate integral random box dimensions from 1 to max_size
inline double random(double max_size)
{
  return 1 + rand() / (RAND_MAX / max_size + 1);
}

int main()
{
  const double dimLimit {99.0};             // Upper limit on Box dimensions
  std::srand((unsigned) std::time(0));      // Initialize the random number generator
  Truckload load;
  const size_t boxCount {20};               // Number of Box object to be created

  // Create boxCount Box objects
  for (size_t i {}; i < boxCount; ++i)
    load.addBox(std::make_shared<Box>(random(dimLimit), random(dimLimit), random(dimLimit)));

  DeliveryTruck truck{ load };  // Copy the load, because we still need it below. 
                                // Note that all Boxes are shared, so the they themselves are not copied.
  
  // Register two callback functions:
  truck.registerOnDelivered(logDelivary);
  
  unsigned count {};
  truck.registerOnDelivered([&count](SharedBox) { ++count; });
  
  // Deliver some boxes:
  for (size_t i : { 5u, 8u, 11u })
    truck.deliverBox(load[i]);

  std::cout << count << " boxes were delivered. On time, as always!" << std::endl;
}