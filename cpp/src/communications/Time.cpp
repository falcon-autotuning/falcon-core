#include "falcon_core/communications/Time.hpp"
#include <ctime>
#include <chrono>
namespace falcon_core {
namespace communications {
Time::Time() {
  auto now = std::chrono::system_clock::now();
  auto us  = std::chrono::duration_cast<std::chrono::microseconds>(
                now.time_since_epoch())
                .count();
  _micro_seconds_since_epoch = us;
}

Time::Time(long long micro_seconds_since_epoch)
    : _micro_seconds_since_epoch(micro_seconds_since_epoch) {}

const long long Time::micro_seconds_since_epoch() const {
  return _micro_seconds_since_epoch;
}

const long long Time::time() const { return _micro_seconds_since_epoch; }

const std::string Time::to_string() const {
  std::time_t sec = _micro_seconds_since_epoch / 1000000;

  // std::tm     tm  = *std::localtime(&sec);
  #ifdef _WIN32
    localtime_s(&tm, &sec);   // secure Windows version, no warnings
  #else
    // Temporarily keep the original behavior everywhere else
    tm = *std::localtime(&sec);
  #endif

  char        buf[20];
  std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tm);
  return std::string(buf);
}
}  // namespace communications
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::communications::Time)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::communications::Time)
