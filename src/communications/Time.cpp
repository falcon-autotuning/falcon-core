#include "falcon_core/communications/Time.hpp"

using namespace falcon_core;
using communications::Time;

Time::Time() : _now(std::chrono::system_clock::now()) {}

long long Time::time() const {
  return std::chrono::duration_cast<std::chrono::seconds>(
             _now.time_since_epoch())
      .count();
}
CEREAL_REGISTER_TYPE(Time)
CEREAL_REGISTER_POLYMORPHIC_RELATION(generic::Song, Time)
