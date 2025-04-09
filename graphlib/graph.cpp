#include "graph.hpp"

Graph::Graph(std::string name) { this->name = name; }

std::string Graph::get_name() { return this->name; }