#include <files.hpp>
#include <iostream>
#include <tree.hpp>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "invalid arguments" << std::endl;
    return -1;
  }
  auto frequencies = huffman::get_character_frequencies(argv[1]);

  auto root = huffman::build_huffman_tree(frequencies);

  huffman::encode_file(argv[1], argv[2], root);

  huffman::write_huffman_tree_to_json(root, "tree.json");

  huffman::print_huffman_tree(root);

  huffman::delete_huffman_tree(root);

  return 0;
}
