// Using multiple default parameter values
#include <iostream>
#include <iomanip>
#include <string_view>

// The function prototype including defaults for parameters
void show_data(const int data[], size_t count = 1, std::string_view title = "Data Values", 
                                                   size_t width = 10, size_t perLine = 5);

int main()
{
  int samples[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

  int dataItem{-99};
  show_data(&dataItem);

  dataItem = 13;
  show_data(&dataItem, 1, "Unlucky for some!");

  show_data(samples, sizeof (samples) / sizeof (samples[0]));
  show_data(samples, sizeof (samples) / sizeof (samples[0]), "Samples");
  show_data(samples, sizeof (samples) / sizeof (samples[0]), "Samples", 6);
  show_data(samples, sizeof (samples) / sizeof (samples[0]), "Samples", 8, 4);
}

void show_data(const int data[], size_t count, std::string_view title, size_t width, size_t perLine)
{
  std::cout << title << std::endl;                      // Display the title

  // Output the data values
  for (size_t i {}; i < count ; ++i)
  {
    std::cout << std::setw(width) << data[i];           // Display a data item
    if ((i + 1) % perLine == 0)                         // Newline after perLine values
      std::cout << '\n';
  }
  std::cout << std::endl;
}
