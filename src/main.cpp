#include <iostream>

#include "../graphlib/graph.hpp"

int main() {

  std::cout << "Hello World!\n";
  Graph graph = Graph("First graph.");
  std::cout << "Graph created: " << graph.get_name() << "\n";
}