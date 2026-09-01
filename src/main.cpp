#include "../graphlib/graph.hpp"
#include "../lightning-diffusion/utils/rng.hpp"
#include "../lightning-diffusion/utils/timer.hpp"
#include "cli/argument_parser.hpp"

int main(int argc, char* argv[]) {
  auto parser = ArgumentParser(argc, argv);

  auto graph = Graph(parser.get_graph());
}