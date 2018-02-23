#ifndef AVERAGE_H
#define AVERAGE_H

#include <type_traits>
#include <vector>
#include <cassert>

template<typename T>
T average(const std::vector<T>& values)
{
  static_assert(std::is_arithmetic_v<T>,
                "Type parameter for average() must be arithmetic.");  
  assert(!values.empty());    // Not possible using static_assert()!

  T sum {};
  for (auto& value : values) 
    sum += value;
  return sum / values.size();
}
#endif
