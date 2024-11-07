#include <fstream>
#include <iostream>
#include <tree.hpp>

void generate_codes(huffman::HuffmanNode *node, const std::string &code,
                    std::map<char, std::string> &codes) {
  if (!node)
    return;

  if (node->left == nullptr && node->right == nullptr &&
      node->character != '\0')
    codes[node->character] = code;

  generate_codes(node->left, code + "0", codes);

  generate_codes(node->right, code + "1", codes);
}

void huffman::encode_file(const std::string &input_filename,
                          const std::string &output_filename,
                          HuffmanNode *root) {
  std::map<char, std::string> codes;
  generate_codes(root, "", codes);

  std::ifstream input_file(input_filename);

  if (!input_file.is_open()) {
    std::cerr << "Error opening input file: " << input_filename << std::endl;
    return;
  }

  std::string encoded_text;
  char ch;
  while (input_file.get(ch))
    encoded_text += codes[ch];

  input_file.close();

  std::ofstream output_file(output_filename);

  if (!output_file.is_open()) {
    std::cerr << "Error opening output file: " << output_filename << std::endl;
    return;
  }

  output_file << encoded_text;

  output_file.close();

  std::cout << "size encoded text: " << encoded_text.size() << std::endl;
}
