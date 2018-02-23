// Exercise 19-3 Replacing custom container types with standard ones
/*
	The following replacements were made compared to Soln16_06.cpp:
		- LinkedList<T> --> std::vector<T> (not std::list<>, because vector<> should
			be your go-to container; there's rarely a good reason to use linked lists)
		- SparseArray<T> --> std::map<char, T> (no need to use a size_t as the key!)
	
	Soln19_03A contains an alternative solution based on std::multimap<>
*/
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <cctype>
#include <utility>

int main()
{
  std::string text;                                 // Stores input prose or poem
  std::cout << "Enter a poem or prose over one or more lines.\n"
            << "Terminate the input with #:\n";
  getline(std::cin, text, '#');

  std::map<char, std::vector<std::string>> lists;

  // Extract words and store in the appropriate list
  // A list in the map<> is selected by the index in letters of the first letter in a word.
  const std::string separators {" \n\t,.\"?!;:"};   // Separators between words
  size_t start {};                                  // Start of a word
  size_t end {};                                    // separator position after a word
  while (std::string::npos != (start = text.find_first_not_of(separators, start)))
  {
    end = text.find_first_of(separators, start+1);
    const auto word = text.substr(start, end - start);
    const auto letter = static_cast<char>(std::toupper(word[0]));
    lists[letter].push_back(word);
    start = end;
  }

  // List the words in order 5 to a line
  const size_t perline {5};
  
  for (const auto& [beginLetter, words] : lists)
  {
	size_t count {};                               // Word counter
    for (const auto& word : words)
    {
      std::cout << word << ' ';
      if (!(++count % perline))
        std::cout << std::endl;
    }
    std::cout << std::endl;
  }
  std::cout << std::endl; 
}

