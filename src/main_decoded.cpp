#include <iostream>
#include <tree.hpp>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "invalid arguments" << std::endl;
    return -1;
  }
  auto root = huffman::load_huffman_tree_from_json("tree.json");
  huffman::print_huffman_tree(root);

  std::cout << std::endl;

  huffman::decode_file(argv[1], argv[2], root);

  huffman::delete_huffman_tree(root);
}
