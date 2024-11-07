#include <queue>
#include <tree.hpp>

huffman::HuffmanNode *huffman::build_huffman_tree(
    const std::vector<std::pair<char, unsigned long long>> &frequencies) {
  std::priority_queue<huffman::HuffmanNode *,
                      std::vector<huffman::HuffmanNode *>, huffman::CompareNode>
      min_heap;

  for (const auto &pair : frequencies) {
    min_heap.push(new huffman::HuffmanNode(pair.first, pair.second));
  }

  while (min_heap.size() > 1) {
    huffman::HuffmanNode *left = min_heap.top();
    min_heap.pop();
    huffman::HuffmanNode *right = min_heap.top();
    min_heap.pop();

    huffman::HuffmanNode *merged_node =
        new huffman::HuffmanNode('\0', left->frequency + right->frequency);
    merged_node->left = left;
    merged_node->right = right;

    min_heap.push(merged_node);
  }

  return min_heap.top();
}
