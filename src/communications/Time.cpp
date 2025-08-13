#include "falcon_core/communications/Time.hpp"

#include "falcon_core/constants.hpp"

using namespace falcon_core;
using communications::Time;

Time::Time()
    : generic::Song<Time>("SymbolUnit"),
      _now(std::chrono::system_clock::now()) {}

long long Time::time() const {
  return std::chrono::duration_cast<std::chrono::seconds>(
             _now.time_since_epoch())
      .count();
}
