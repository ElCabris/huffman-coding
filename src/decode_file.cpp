#include <fstream>
#include <iostream>
#include <tree.hpp>

void huffman::decode_file(const std::string &input_filename,
                          const std::string &output_filename,
                          HuffmanNode *root) {
  std::ifstream input_file(input_filename);

  if (!input_file.is_open()) {
    std::cerr << "Error opening input file: " << input_filename << std::endl;
    return;
  }

  std::ofstream output_file(output_filename);
  if (!output_file.is_open()) {
    std::cerr << "Error opening output file: " << output_filename << std::endl;
    input_file.close();
    return;
  }

  HuffmanNode *current_node = root;
  char bit_char;

  while (input_file.get(bit_char)) {
    if (bit_char == '0')
      current_node = current_node->left;
    else if (bit_char == '1')
      current_node = current_node->right;
    else {
      std::cerr
          << "Error: Invalid character in input file (expected '0' or '1')"
          << std::endl;
      input_file.close();
      output_file.close();
      return;
    }

    if (current_node->left == nullptr && current_node->right == nullptr) {
      output_file << current_node->character;
      current_node = root;
    }
  }

  input_file.close();
  output_file.close();
}
