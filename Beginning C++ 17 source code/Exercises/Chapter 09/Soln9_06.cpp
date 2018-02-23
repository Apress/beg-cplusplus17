// Exercise 9-6 A Quicksort funtion template

// The top level sort() template with one parameter calls the sort() template with three parameters
// The sort() function template uses the swap() function template
// The list() template outputs all elements in a vector.

#include <iostream>
#include <iomanip>
#include <vector>

// Swap two vector elements
template<typename T>
inline void swap(std::vector<T>& data, size_t first, size_t second)
{
  T temp{ data[first] };
  data[first] = data[second];
  data[second] = temp;
}

// Sort a range of vector elements
template<typename T>
void sort(std::vector<T>& data, size_t start, size_t end)
{
  // Start index must be less than end index for 2 or more elements
  if (!(start < end))
    return;

  // Choose middle value to partition set
  swap(data, start, (start + end) / 2);         // Swap middle value with start

  // Check data against chosen value
  size_t current{ start };                      // The index of the last element less than the chosen element (after partitioning)
  for (size_t i{ start + 1 }; i <= end; ++i)
  {
    if (data[i] < data[start])                  // Is value less than chosen element?
      swap(data, ++current, i);                 // Yes, so swap to the left
  }

  swap(data, start, current);                   // Swap the chosen value with last in

  if (current) sort(data, start, current - 1);  // Sort left subset if exists
  sort(data, current + 1, end);                 // Sort right subset if exists
}

// Sort all vector elements
template<typename T>
inline void sort(std::vector<T>& values)
{
  if (!values.empty())
    sort(values, 0, values.size() - 1);
}

// Output vector elements
template<typename T>
void list(const std::vector<T>& values, size_t width = 5)
{
  for (auto value : values)
    std::cout << std::setw(width) << value;
  std::cout << std::endl;
}

int main()
{
  std::vector<int> numbers{ -2, 4, -5, 6, 10, -40, 56, 4, 67, 45 };
  list(numbers);
  sort(numbers);
  std::cout << "\nSorted integers:\n";
  list(numbers);

  std::cout << "\nCharacters to be sorted:\n";
  std::vector<char> letters{ 'C', 'd', 'a', 'z', 't', 'S', 'p', 'm', 'D', 'f' };
  list(letters, 2);
  sort(letters);
  std::cout << "\nSorted characters:\n";
  list(letters, 2);

  std::cout << "\nFloating-point values to be sorted:\n";
  std::vector<double> values{ -2.5, 1.4, -2.55, 6.3, 10.1, -40.5, 56.0, 4.7, 67.3, 45.0 };
  list(values, 10);
  sort(values);
  std::cout << "\nSorted floaating-point values:\n";
  list(values, 10);
}