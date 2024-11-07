#ifndef FILES_HPP
#define FILES_HPP
#include <string>
#include <vector>

namespace huffman {

std::vector<std::pair<char, unsigned long long>>
get_character_frequencies(const std::string &filename);

}
#endif
