#include <iostream>
#include <tree.hpp>

int main() {
  auto root = huffman::load_huffman_tree_from_json("tree.json");
  huffman::print_huffman_tree(root);

  std::cout << std::endl;

  huffman::decode_file("encode.txt", "decoded.txt", root);

  huffman::delete_huffman_tree(root);
}
