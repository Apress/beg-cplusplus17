// Vessel.h  Abstract class defining a vessel
#ifndef VESSEL_H
#define VESSEL_H

class Vessel
{
public:
  virtual ~Vessel() = default;
  virtual double volume() const = 0;
};
#endif
