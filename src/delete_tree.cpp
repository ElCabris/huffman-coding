#include <tree.hpp>

void huffman::delete_huffman_tree(huffman::HuffmanNode *node) {
  if (!node)
    return;
  delete_huffman_tree(node->left);
  delete_huffman_tree(node->right);
  delete node;
}
