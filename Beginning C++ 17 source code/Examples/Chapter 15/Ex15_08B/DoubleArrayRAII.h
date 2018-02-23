// A custom RAII class to manage a dynamic double[] array resource
#ifndef DOUBLE_ARRAY_RAII_H
#define DOUBLE_ARRAY_RAII_H

#include <iostream>

class DoubleArrayRAII final
{
private:
  double* resource;
public:
  DoubleArrayRAII(size_t size) : resource{ new double[size] } {}
  ~DoubleArrayRAII()
  {
    std::cout << "Freeing memory..." << std::endl;
    delete[] resource;
  }

  // Delete copy constructor and assignment operator
  DoubleArrayRAII(const DoubleArrayRAII&) = delete;
  DoubleArrayRAII& operator=(const DoubleArrayRAII&) = delete;
  
  // Array subscript operator
  double& operator[](size_t index) noexcept { return resource[index]; }
  const double& operator[](size_t index) const noexcept { return resource[index]; }
  
  // Function to access the encapsulated resource
  double* get() const noexcept { return resource; }

  // Function to instruct the RAII object to longer release the resource 
  // upon destruction anymore. Returns the resource in the process.
  double* release() noexcept
  {
    double* result = resource;
    resource = nullptr;
    return result;
  }
};

#endif