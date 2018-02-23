// Dereferencing pointers
// Calculates the purchase price for a given quantity of items
#include  <iostream>
#include  <iomanip>

int main()
{
  int unit_price{ 295 };                // Item unit price in cents
  int count{};                          // Number of items ordered
  int discount_threshold{ 25 };         // Quantity threshold for discount
  double discount{ 0.07 };              // Discount for quantities over discount_threshold

  int* pcount{ &count };                // Pointer to count
  std::cout << "Enter the number of items you want: ";
  std::cin >> *pcount;
  std::cout << "The unit price is " << std::fixed << std::setprecision(2)
            << "$" << unit_price/100.0 << std::endl;

  // Calculate gross price
  int*  punit_price{ &unit_price };     // Pointer to unit_price
  int price{ *pcount * *punit_price };  // Gross price via pointers
  auto* pprice {&price};                // Pointer to gross price

  // Calculate net price in US$
  double net_price{};
  double* pnet_price{ nullptr };
  pnet_price = &net_price;
  if (*pcount > discount_threshold)
  {
    std::cout << "You qualify for a discount of "
              << static_cast<int>(discount * 100.0) << " percent.\n";
    *pnet_price = price*(1.0 - discount) / 100.0;
  }
  else
  {
    net_price = *pprice / 100.0;
  }
  std::cout << "The net price for " << *pcount 
            << " items is $" << net_price << std::endl;

}
