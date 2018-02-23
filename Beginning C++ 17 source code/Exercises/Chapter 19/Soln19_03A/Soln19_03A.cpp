// Exercise 19-3 Replacing custom container types with standard ones
/*
	The following replacements were made compared to Soln16_06.cpp:
		- SparseArray<LinkedList<T>> --> std::multimap<size_t, T>
	
	This means that compared to Soln19_03, we replaced std::map<Key, std::vector<Value>>
	with the more std::multimap<Key, Value>. This data structure was less discussed 
	in the main text (as it is less used in practice), but is more appropriate here.
*/
#include <map>       // for std::multimap<>
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

  std::multimap<char, std::string> multimap;
  const std::string letters {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

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
    multimap.insert(std::make_pair(letter, word));
    start = end;
  }

  // List the words in order 5 to a line
  const size_t perline {5};
  
  char previousBeginLetter {};
  size_t count{};                                   // Word counter
  for (const auto& [beginLetter, word] : multimap)
  {
    std::cout << word << ' ';
    if (!(++count % perline) || (previousBeginLetter && beginLetter != previousBeginLetter))
    {
      std::cout << std::endl;
      count = 0;
    }
	previousBeginLetter = beginLetter;
  }
  std::cout << std::endl; 
}