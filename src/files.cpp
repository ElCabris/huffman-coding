#include <files.hpp>
#include <fstream>
#include <iostream>
#include <unordered_map>

std::vector<std::pair<char, unsigned long long>>
huffman::get_character_frequencies(const std::string &filename) {
  std::unordered_map<char, unsigned long long> frequency_map;

  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "error opening file" << std::endl;
    return {};
  }

  char ch;
  while (file.get(ch)) {
    frequency_map[ch]++;
  }

  file.close();

  std::vector<std::pair<char, unsigned long long>> frequencies(
      frequency_map.begin(), frequency_map.end());

  return frequencies;
}
