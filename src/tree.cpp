#include <tree.hpp>

huffman::HuffmanNode::HuffmanNode(char ch, unsigned long long freq)
    : character(ch), frequency(freq), left(nullptr), right(nullptr) {}

bool huffman::HuffmanNode::operator>(const HuffmanNode &other) const {
  return frequency > other.frequency;
}

bool huffman::CompareNode::operator()(HuffmanNode *lhs,
                                      HuffmanNode *rhs) const {
  return lhs->frequency > rhs->frequency;
}
