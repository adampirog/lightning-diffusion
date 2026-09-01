#include <random>
#include <vector>

namespace ld {
namespace utils {

class RandomNumberGenerator {
public:
  RandomNumberGenerator();
  RandomNumberGenerator(float seed);
  float generate();
  std::vector<float> generate_batch(int n);

private:
  std::minstd_rand random_engine;
  std::uniform_real_distribution<float> distribution;
};
} // namespace utils

} // namespace ld