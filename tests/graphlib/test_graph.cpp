#include "../../graphlib/graph.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Factorials are computed", "[graph]") {

  Graph graph = Graph("First graph.");
  REQUIRE(graph.get_name() == "First graph.");
}