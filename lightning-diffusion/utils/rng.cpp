#include "rng.hpp"
#include <algorithm>

ld::utils::RandomNumberGenerator::RandomNumberGenerator() {
  distribution = std::uniform_real_distribution<float>(0.0, 1.0);

  std::random_device rd;
  random_engine = std::minstd_rand(rd());
};

ld::utils::RandomNumberGenerator::RandomNumberGenerator(float seed) {
  distribution = std::uniform_real_distribution<float>(0.0, 1.0);
  random_engine = std::minstd_rand(seed);
};

float ld::utils::RandomNumberGenerator::generate() {
  return distribution(random_engine);
};

std::vector<float> ld::utils::RandomNumberGenerator::generate_batch(int n) {
  std::vector<float> result(n);
  std::generate(result.begin(), result.end(),
                [&]() { return this->generate(); });

  return result;
};