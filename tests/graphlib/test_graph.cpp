#include "../../graphlib/graph.hpp"
#include <catch2/catch_test_macros.hpp>
#include <string>

const std::string RESOURCE_PATH = "../tests/graphlib/resources/";

TEST_CASE("Creating a graph", "[graph]") {

  Graph graph = Graph(RESOURCE_PATH + "test_graph.adjlist");
  REQUIRE(graph.get_nodes() == 5);
}