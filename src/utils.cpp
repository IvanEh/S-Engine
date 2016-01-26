#include "utils.hpp"

int timems() {
  auto timeSinceEpoch = std::chrono::system_clock::now().time_since_epoch();
  auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(timeSinceEpoch);
  return ms.count();
}

