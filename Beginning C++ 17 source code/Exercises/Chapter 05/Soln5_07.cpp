// Exercise 5-7. Outputting product records & cost
// Getting the alignment right is tricky.
// You have to adjust the field widths until it looks OK.
#include <iostream>
#include <iomanip>
#include <cctype>
#include <vector>
using std::setw;

int main()
{
  std::vector<size_t> product_id;
  std::vector<size_t> quantity;
  std::vector<double> unit_cost;

  // Read the records
  while (true)
  {
    std::cout << "Enter a record - product number, quantity, unit cost separated by spaces: ";
	size_t id {};
    size_t n {};
    double cost {};
    std::cin >> id >> n >> cost;

    product_id.push_back(id);
    quantity.push_back(n);
    unit_cost.push_back(cost);
    
	std::cout << "Do you want to enter another record (Y or N): ";
	char answer {};
    std::cin >> answer;
    if (std::toupper(answer) == 'N') break;
  }
  
  // Column headings
  std::cout << setw(10) << "Product" << setw(10) << "Quantity" << setw(12) << "Unit Price" << setw(14) << "Cost\n";
  double total_cost {};
  for (size_t i {}; i < product_id.size(); ++i)
  {
    std::cout << std::setw(8) << product_id[i]
      << std::setw(8) << quantity[i]
      << std::setw(9) << "$" << std::fixed << std::setprecision(2) << setw(5) << unit_cost[i];
    auto cost = quantity[i] * unit_cost[i];
    total_cost += cost;
    std::cout << std::setw(10) << "$" << std::fixed << std::setprecision(2) << setw(5) << cost << std::endl;
  }
  std::cout << std::setw(40) << "$" << std::fixed << std::setprecision(2) << setw(5) << total_cost << std::endl;
}