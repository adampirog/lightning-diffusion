#include "argparse.hpp"
#include <string>

class ArgumentParser {
public:
  std::string get_graph();
  std::string get_output_path();

  ArgumentParser(int argc, char* argv[]);

private:
  std::string graph;
  std::string output_path;

  void addArguments(argparse::ArgumentParser& parser);
};
