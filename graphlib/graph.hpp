#pragma once
#include <string>

class Graph {
private:
  std::string name;

public:
  Graph(std::string name);
  std::string get_name();
};