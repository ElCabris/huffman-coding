#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <tree.hpp>

nlohmann::json huffman_tree_to_json(huffman::HuffmanNode *node) {
  if (!node)
    return nullptr;

  nlohmann::json j;
  j["frequency"] = node->frequency;

  if (node->character != '\0')
    j["character"] = std::string(1, node->character);

  j["left"] = huffman_tree_to_json(node->left);
  j["right"] = huffman_tree_to_json(node->right);

  return j;
}

void huffman::write_huffman_tree_to_json(huffman::HuffmanNode *root,
                                         const std::string &filename) {
  nlohmann::json j = huffman_tree_to_json(root);

  std::ofstream out_file(filename);

  if (!out_file.is_open()) {
    std::cerr << "Error opening file for writing: " << filename << std::endl;
    return;
  }

  out_file << j.dump(4);
  out_file.close();
}
