#pragma once
#include <string>
#include <vector>

using namespace std;

class Graph {

public:
  Graph(const string& file);
  int get_nodes();

private:
  // Adjacency matrix
  vector<vector<bool>> adj_matrix;

  /**
   * \brief Get the graph size for a given file (in adjlist format)
   *
   * Pre-parse the given graph file (in the adjlist format) and return the
   * size of the encoded graph.
   */
  int get_file_size(const string& file);

  /**
   * \brief Split a string into a vector of ints. "1 2 3" -> vec{1,2,3}
   *
   * Utility function used for parsing the graph files.
   */
  vector<int> split_line(const string& line);
};