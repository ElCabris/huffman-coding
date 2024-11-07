#include <files.hpp>
#include <tree.hpp>

int main() {
  auto frequencies = huffman::get_character_frequencies("text.txt");

  auto root = huffman::build_huffman_tree(frequencies);

  huffman::print_huffman_tree(root);

  huffman::write_huffman_tree_to_json(root, "tree.json");

  huffman::encode_file("text.txt", "encode.txt", root);

  huffman::delete_huffman_tree(root);

  return 0;
}
