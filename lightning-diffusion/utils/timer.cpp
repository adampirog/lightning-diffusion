#include "timer.hpp"

ld::utils::Timer::Timer() {
  begining = std::chrono::high_resolution_clock::now();
}

void ld::utils::Timer::start() {
  begining = std::chrono::high_resolution_clock::now();
}

double ld::utils::Timer::stop() {
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> result = end - begining;

  return result.count();
}
