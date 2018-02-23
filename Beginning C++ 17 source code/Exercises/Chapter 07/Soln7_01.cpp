// Exercise 7-1 Storing student names and grades. 
// This uses a vector of string objects to store the names.
#include <iostream>
#include <iomanip>
#include <cctype>
#include <vector>
#include <string>

int main()
{
  std::vector<std::string> names;
  std::vector<double> grades;
  
  size_t max_length {};                     // Longest name length
  double average_grade {};                  // First accumulates the sum of the grades, 
                                            // to diveded by the number of grades later
  // Data entry loop. 
  // This loop reads the name and grade for each student.
  while (true)
  {
    std::cout << "Enter a student's name: ";
	std::string name;                       // Stores a student name
	std::getline(std::cin, name);

    names.push_back(name);
	
    if (max_length < name.length()) 
		max_length = name.length();

    std::cout << "Enter " << name << "\'s grade: ";
    double grade {};                        // Stores a student grade
	std::cin >> grade;
    grades.push_back(grade);

    average_grade += grade;

    std::cout << "Do you wish to enter another student's details (y/n): ";
	char answer {};
    std::cin >> answer;
    if (std::toupper(answer) == 'N') break;
  } 

  // Calculating the class average.
  average_grade /= grades.size();

  // Displaying the class average.
  std::cout << "\nThe class average for " << names.size() << " students is "
            << std::fixed << std::setprecision(2) << average_grade << std::endl;

  // Displaying the students' names and grades.
  const size_t perline {3};
  for (size_t i {}; i < names.size(); ++i)
  {
    std::cout << "  " << std::left << std::setw(max_length) << names[i] 
              << std::right << std::setw(6) << std::setprecision(2) << grades[i];
    if ((i + 1) % perline) continue;
    std::cout << std::endl;
  }
  std::cout << std::endl;
}