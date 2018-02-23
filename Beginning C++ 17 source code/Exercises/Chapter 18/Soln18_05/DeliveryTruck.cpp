#include "DeliveryTruck.h"

// Constructor  
DeliveryTruck::DeliveryTruck(Truckload aTruckload)
  : truckload{ std::move(aTruckload) }   // Do not copy!
{}

void DeliveryTruck::deliverBox(SharedBox box)
{
  truckload.removeBox(box);
  
  // Notify all interested parties (aka "observers") that the Box was delivered
  for (auto& callback : callbacks)
    callback(box);
}

void DeliveryTruck::registerOnDelivered(Callback callback)
{
  callbacks.push_back(std::move(callback));   // Do not copy!
}