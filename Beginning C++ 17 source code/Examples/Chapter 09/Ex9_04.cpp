// Using decltype() inside a function template
#include <iostream>
#include <vector>
#include <algorithm>	// for std::min()

// Template that computes a so-called "inner product" of two vectors.
// Both vectors are supposed to be equally long, 
// but the function will cope if they aren't.
template<typename T1, typename T2>
auto vector_product(const std::vector<T1>& data1, const std::vector<T2>& data2)
{
  // safeguard against vectors of different sizes
  const auto count = std::min(data1.size(), data2.size());  
  
  decltype(data1[0]*data2[0]) sum {};
  for (size_t i {}; i < count; ++i) 
    sum += data1[i] * data2[i];

  return sum;
}

int main()
{
  // Take the product of vectors with different types. Deduced return type: double
  std::vector<int> integers { 1, 2, 3 };
  std::vector<double> doubles { 1.1, 1.1, 1.1 };
  std::cout << vector_product(integers, doubles) << std::endl;
  
  // decltype() does not evaluate the expression, so this will work
  std::vector<bool> empty;
  std::cout << vector_product(empty, empty) << std::endl;
}