// Working with maps
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <string_view>
#include <vector>

// Type aliases
using Words = std::vector<std::string_view>;
using WordCounts = std::map<std::string, size_t>;

// Function prototypes
Words extract_words(std::string_view text, std::string_view separators = " ,.!?\"\n");
WordCounts count_words(const Words& words);
void show_word_counts(const WordCounts& wordCounts);
size_t max_word_length(const WordCounts& wordCounts);

int main()
{
  std::string text;                                         // The string to count words in

  // Read a string from the keyboard
  std::cout << "Enter a string terminated by *:" << std::endl;
  getline(std::cin, text, '*');

  Words words = extract_words(text);
  if (words.empty())
  {
    std::cout << "No words in text." << std::endl;
    return 0;
  }

  WordCounts wordCounts = count_words(words);
  show_word_counts(wordCounts);
}

Words extract_words(std::string_view text, std::string_view separators)
{
  Words words;
  size_t start{ text.find_first_not_of(separators) };                // Start 1st word
  size_t end{};                                                      // Index for the end of a word

  while (start != std::string_view::npos)
  {
    end = text.find_first_of(separators, start + 1);                 // Find end separator
    if (end == std::string_view::npos)                               // End of text?
      end = text.length();                                           // Yes, so set to last+1
    words.push_back(text.substr(start, end - start));
    start = text.find_first_not_of(separators, end + 1);             // Find next word
  }

  return words;
}

WordCounts count_words(const Words& words)
{
  WordCounts result;
  for (auto& word : words)
    ++result[std::string(word)];
  return result;
}

void show_word_counts(const WordCounts& wordCounts)
{
  const size_t field_width{ max_word_length(wordCounts) + 1 };
  const size_t words_per_line{ 5 };

  size_t words_in_line{};      // Number of words in the current line
  char previous_initial{};
  for (auto&[word, count] : wordCounts)
  {
    if (count < 2) continue;      // Skip words that appear only once

                    // Output newline when initial letter changes or after 5 per line
    if (previous_initial &&
      (word[0] != previous_initial || ++words_in_line == words_per_line))
    {
      words_in_line = 0;
      std::cout << std::endl;
    }
    std::cout << std::setw(field_width) << word;          // Output a word
    std::cout << " (" << std::setw(2) << count << ')';    // Output count
    previous_initial = word[0];
  }
  std::cout << std::endl;
}

size_t max_word_length(const WordCounts& wordCounts)
{
  size_t max{};
  for (const auto& [word, count] : wordCounts)
    if (count >= 2 && max < word.length()) max = word.length();
  return max;
}
