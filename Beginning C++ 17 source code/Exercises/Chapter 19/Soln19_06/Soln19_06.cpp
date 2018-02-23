// Removing all elements that satisfy a certain condition 
// while iterating over a container
#include <vector>
#include <string_view>
#include <iostream>
#include <algorithm>   // for std::remove_if()
#include <numeric>     // for std::iota()

std::vector<int> fillVector_1_to_N(size_t N);       // Fill a vector with 1, 2, ..., N
void printVector(std::string_view message, const std::vector<int>& numbers);

template <typename NumberContainer>
void removeEvenNumbers(NumberContainer& numbers)
{
  auto first_to_erase = 
    std::remove_if(begin(numbers), end(numbers), [](auto num) { return num % 2 == 0; });
  
  numbers.erase(first_to_erase, end(numbers));
}

int main()
{
  const size_t num_numbers{20};
  
  auto numbers{ fillVector_1_to_N(num_numbers) };

  printVector("The original set of numbers", numbers);

  removeEvenNumbers(numbers);

  printVector("The numbers that were kept", numbers);
}

std::vector<int> fillVector_1_to_N(size_t N)   // Fill a vector with 1, 2, ..., N
{
  std::vector<int> numbers(N);
  std::iota(begin(numbers), end(numbers), 1);
  return numbers;
}

void printVector(std::string_view message, const std::vector<int>& numbers)
{
  std::cout << message << ": ";
  for (int number : numbers) std::cout << number << ' ';
  std::cout << std::endl;
}
