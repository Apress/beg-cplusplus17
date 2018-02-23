// Using overloaded function templates
#include <iostream>
#include <vector>
#include <string>

template <typename T> T larger(T a, T b);    // Function  template  prototype
template <typename T> T larger(const T data[], size_t count);
template <typename T> T larger(const std::vector<T>& data);
template <typename T> T* larger(T*, T*);

int main()
{
  int big_int {17011983}, small_int {10};
  std::cout << "Larger of " << big_int << " and " << small_int << " is "
            << larger(big_int, small_int) << std::endl;
  std::cout << "Larger of " << big_int << " and " << small_int << " is "
            << *larger(&big_int, &small_int) << std::endl;

  const char text[] {"A nod is as good as a wink to a blind horse."};
  std::cout << "Largest character in \"" << text << "\" is '" 
            << larger(text, std::size(text)) << "'" << std::endl;

  std::vector<std::string> words {"The", "higher", "the", "fewer"};
  std::cout << "The largest word in words is \"" << larger(words) 
            << '"' << std::endl;

  std::vector<double> data {-1.4, 7.3, -100.0, 54.1, 16.3};
  std::cout << "The largest value in data is " << larger(data) << std::endl;
}

// Template for functions to return the larger of two values
template <typename T>
T larger(T a, T b)
{
  return a > b ? a : b;
}

// Function template overload to return the largest 
// of two values pointed to by pointers
template<typename T>
T* larger(T* a, T* b) 
{
  return *a > *b ? a : b;
}

// Function template to return largest value in an array
template <typename T>
T larger(const T data[], size_t count)
{
  T result{data[0]};
  for (size_t i{1}; i < count; ++i)
    if (data[i] > result) result = data[i];

  return result;
}

// Function template to return largest value in a vector
template <typename T>
T larger(const std::vector<T>& data)
{
  T result{data[0]};
  for (auto& value : data)
    if (value > result) result = value;

  return result;
}
