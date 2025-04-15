#include <chrono>

namespace ld {
namespace utils {

class Timer {
public:
  Timer();
  void start();
  double stop();

private:
  std::chrono::high_resolution_clock::time_point begining;
};

}; // namespace utils

} // namespace ld