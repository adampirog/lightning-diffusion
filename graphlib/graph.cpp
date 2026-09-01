#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "graph.hpp"

Graph::Graph(const string& file) {

  ifstream handle(file);
  if (!handle)
    throw invalid_argument("Graph file does not exist.");

  int size = this->get_file_size(file);
  adj_matrix = vector<vector<bool>>(size, vector<bool>(size, false));

  string line;
  string node;
  while (getline(handle, line)) {
    if (line[0] == '#')
      continue;

    auto nodes = this->split_line(line);

    // get the first node
    int from = nodes[0];
    nodes.erase(nodes.begin());

    for (const int& to : nodes) {
      adj_matrix[from][to] = true;
      adj_matrix[to][from] = true;
    }
  }
}

int Graph::get_nodes() { return adj_matrix.size(); }

int Graph::get_file_size(const string& file) {
  ifstream handle(file);
  string line;
  int result = 0;
  while (getline(handle, line)) { // read line by line
    if (line[0] != '#')
      result++;
  }

  return result;
}

vector<int> Graph::split_line(const string& line) {
  vector<int> result;

  string node;
  istringstream line_stream(line);
  while (getline(line_stream, node, ' ')) {
    result.push_back(stoi(node));
  }

  return result;
}
