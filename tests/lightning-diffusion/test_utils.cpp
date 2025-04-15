
#include "../../lightning-diffusion/utils/timer.hpp"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <thread>

TEST_CASE("Testing a timer", "[timer]") {
  ld::utils::Timer timer;

  double target = 0.235;
  std::chrono::milliseconds timespan(int(target * 1000));

  timer.start();
  std::this_thread::sleep_for(timespan);
  auto result = timer.stop();

  REQUIRE_THAT(target, Catch::Matchers::WithinAbs(result, 0.001));
}