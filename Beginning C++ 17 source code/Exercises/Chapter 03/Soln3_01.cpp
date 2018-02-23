// Exercise 3-1. Output integer and its 1's complement in decimal and hexadecimal.

// This tests how well you remember the stream manipulators as well as bitwise ~.
// You also need to be creative with the manipulators.
// The setw() manipulator only applies to the next output value so you must use it preceding each output value. 
// std::internal causes the fill character, '0', to be used internal to the hexadecimal values.
// The field width has to be set appropriately to get the correct number of hex digits including the leading zeros.

// Because the program computes the complement of signed integers, 
// the output of this program is strictly speaking undefined.
// That is: it depends on which binary representation of negative integers your computer uses.
// Nearly all computers employ the two's complement encoding though,
// which means that flipping all bits and adding one should negate your number.

#include <iostream>
#include <iomanip>

int main()
{
  int value {};
  std::cout << "Enter any integer: ";
  std::cin >> value;
  int inverted_value {~value};

  unsigned int hex_digits {2 * sizeof(int)};          // Hex digits in value
  unsigned int hex_value_width {hex_digits + 2};      // Add 2 for 0x prefix
  unsigned int column_width {hex_value_width + 4};    // Output column width (add 4 for padding)

  // Output column headings
  std::cout << std::right << std::setw(column_width) << "value"
    << std::setw(column_width) << "~value"
    << std::setw(column_width) << "~value+1" << std::endl;

  // Output hexadecimal values
  std::cout << std::hex << std::showbase << std::internal << std::setfill('0')
    << "    " << std::setw(hex_value_width) << value
    << "    " << std::setw(hex_value_width) << inverted_value
    << "    " << std::setw(hex_value_width) << inverted_value + 1 << std::endl;

  // Output decimal values
  std::cout << std::dec << std::right << std::setfill(' ')
    << std::setw(column_width) << value
    << std::setw(column_width) << inverted_value
    << std::setw(column_width) << inverted_value + 1 << std::endl;
}