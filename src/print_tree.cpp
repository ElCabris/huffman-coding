#include <iostream>
#include <tree.hpp>

// Función recursiva para imprimir el árbol con indentación
void huffman::print_huffman_tree(huffman::HuffmanNode *node,
                                 const std::string &prefix, bool is_left) {
  if (node == nullptr) {
    return;
  }

  std::cout << prefix;

  // Mostrar rama (izquierda o derecha)
  std::cout << (is_left ? "├── " : "└── ");

  // Mostrar información del nodo
  if (node->character == '\0') {
    std::cout << "[Freq: " << node->frequency << "]" << std::endl;
  } else {
    std::cout << "[Char: " << node->character << ", Freq: " << node->frequency
              << "]" << std::endl;
  }

  // Recursión para hijos izquierdo y derecho
  print_huffman_tree(node->left, prefix + (is_left ? "│   " : "    "), true);
  print_huffman_tree(node->right, prefix + (is_left ? "│   " : "    "), false);
}
