#ifndef TREE_HPP
#define TREE_HPP

#include <nlohmann/json.hpp>
#include <vector>

namespace huffman {
struct HuffmanNode {
  char character;
  unsigned long long frequency;
  HuffmanNode *left, *right;

  HuffmanNode(char ch, unsigned long long freq);
  bool operator>(const HuffmanNode &other) const;
};

struct CompareNode {
  bool operator()(HuffmanNode *lhs, HuffmanNode *rhs) const;
};

HuffmanNode *build_huffman_tree(
    const std::vector<std::pair<char, unsigned long long>> &frequencies);

void delete_huffman_tree(huffman::HuffmanNode *node);

void write_huffman_tree_to_json(HuffmanNode *root, const std::string &filename);

void encode_file(const std::string &input_filename,
                 const std::string &output_filename, HuffmanNode *root);

void print_huffman_tree(HuffmanNode *node, const std::string &prefix = "",
                        bool is_left = true);

HuffmanNode *load_huffman_tree_from_json(const std::string &filename);

void decode_file(const std::string &input_filename,
                 const std::string &output_filename, HuffmanNode *root);

} // namespace huffman

#endif
