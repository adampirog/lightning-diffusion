#include "argument_parser.hpp"

void ArgumentParser::addArguments(argparse::ArgumentParser& parser) {
  parser.add_argument("graph").help("Path to a graph file.");
  parser.add_argument("output_path")
      .help("Output path to store the simulation results.");
}

ArgumentParser::ArgumentParser(int argc, char* argv[]) {
  auto parser = argparse::ArgumentParser(
      "Simulating diffusion processes in complex networks", "0.1.0");

  this->addArguments(parser);
  parser.parse_args(argc, argv);

  this->graph = parser.get<std::string>("graph");
  this->output_path = parser.get<std::string>("output_path");
};

std::string ArgumentParser::get_graph() { return this->graph; }
std::string ArgumentParser::get_output_path() { return this->output_path; }
