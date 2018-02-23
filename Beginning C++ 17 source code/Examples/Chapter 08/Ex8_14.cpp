// Working with std::opional
#include <iostream>
#include <optional>
#include <string_view>
using std::optional;
using std::string_view;

optional<size_t> find_last(string_view string, char to_find, 
                                                optional<size_t> start_index = std::nullopt);
int main()
{
  const auto string = "Growing old is mandatory; growing up is optional.";
  
  const optional<size_t> found_a{ find_last(string, 'a') };
  if (found_a)
    std::cout << "Found the last a at index " << *found_a << std::endl;

  const auto found_b{ find_last(string, 'b') };
  if (found_b.has_value())
    std::cout << "Found the last b at index " << found_b.value() << std::endl;

  // const size_t found_c{ find_last(string, 'c') };     /* error: cannot convert to size_t */

  const auto found_early_i{ find_last(string, 'i', 10) };
  if (found_early_i != std::nullopt)
    std::cout << "Found an early i at index " << *found_early_i << std::endl;
}

optional<size_t> find_last(string_view string, char to_find, optional<size_t> start_index)
{
  // code below will not work for empty strings  
  if (string.empty())             
    return std::nullopt;         // or: ‘  return optional<size_t>{};’ 
                                 // or: ‘  return {};’
  
  // determine the starting index for the loop that follows:
  size_t index = start_index.value_or(string.size() - 1);

  while (true)                   // never use while (index >= 0) here, as size_t is always >= 0!
  {
    if (string[index] == to_find) return index;
    if (index == 0) return std::nullopt;
    --index;
  }
}
