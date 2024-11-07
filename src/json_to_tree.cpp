#include <fstream>
#include <iostream>
#include <tree.hpp>

huffman::HuffmanNode *huffman_tree_from_json(const nlohmann::json &j) {
  if (j.is_null())
    return nullptr;

  char character = '\0';
  if (j.contains("character"))
    character = j["character"].get<std::string>()[0];
  unsigned long long frequency = j["frequency"].get<unsigned long long>();

  huffman::HuffmanNode *node = new huffman::HuffmanNode(character, frequency);

  node->left = huffman_tree_from_json(j["left"]);
  node->right = huffman_tree_from_json(j["right"]);

  return node;
}

huffman::HuffmanNode *
huffman::load_huffman_tree_from_json(const std::string &filename) {
  std::ifstream in_file(filename);

  if (!in_file.is_open()) {
    std::cerr << "Eror opening file for reading: " << filename << std::endl;
    return nullptr;
  }

  nlohmann::json j;
  in_file >> j;
  in_file.close();

  return huffman_tree_from_json(j);
}
