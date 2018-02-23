// Generating multiplication tables using nested loops
// In this version an indefinite for loop is used, in combination with break statements.
#include <iostream>
#include <iomanip>
#include <cctype>		// for std::tolower()

int main()
{
  size_t table{};               // Table size
  const size_t table_min{ 2 };  // Minimum table size - at least up to the 2-times
  const size_t table_max{ 12 }; // Maximum table size
  const size_t max_tries {3};   // Maximum number of times user is allowed to try entering a table size
  char reply{};                 // Response to prompt

  do
  {
    for (size_t count {1}; ; ++count)  // Indefinite loop
    {
      std::cout << "What size table would you like ("
                << table_min << " to " << table_max << ")? ";
      std::cin >> table; // Get the table size
 
      // Make sure table size is within the limits
      if (table >= table_min && table <= table_max)
      {
        break;                                        // Exit the input loop
      }
      else if (count < max_tries)
      {
        std::cout << "Invalid input - try again.\n";
      }
      else
      {
        std::cout << "Invalid table size entered - yet again! \nSorry, only "
                  << max_tries << " allowed - program terminated." << std::endl;
        return 1;
      }
    }

    // Make sure table size is within the limits
    if (table < table_min || table > table_max)
    {
      std::cout << "Invalid table size entered. Program terminated." << std::endl;
      return 1;
    }

    // Create the top line of the table
    std::cout << std::setw(6) << " |";
    for (size_t i{ 1 }; i <= table; ++i)
    {
      std::cout << " " << std::setw(3) << i << " |";
    }
    std::cout << std::endl;

    // Create the separator row
    for (size_t i{}; i <= table; ++i)
    {
      std::cout << "------";
    }
    std::cout << std::endl;

    for (size_t i {1}; i <= table; ++i)
    {    // Iterate over rows
      std::cout << " " << std::setw(3) << i << " |"; // Start the row

      // Output the values in a row
      for (size_t j{1}; j <= table; ++j)
      {
        std::cout << " " << std::setw(3) << i*j << " |";  // For each col.
      }
      std::cout << std::endl;                        // End the row
    }

    // Check if another table is required
    std::cout << "\nDo you want another table (y or n)? ";
    std::cin >> reply;
  } while (std::tolower(reply) == 'y');
}
