#include "falcon_core/communications/Time.hpp"

#include <chrono>
#include <mutex>
namespace falcon_core {
namespace communications {
Time::Time(const Time& other) {
  std::unique_lock<std::shared_timed_mutex> lock(_mu_time);
  _micro_seconds_since_epoch = other.micro_seconds_since_epoch();
}
Time& Time::operator=(const Time& other) {
  if (this != &other) {
    std::unique_lock<std::shared_timed_mutex> lock(_mu_time);
    _micro_seconds_since_epoch = other.micro_seconds_since_epoch();
  }
  return *this;
}
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
  std::shared_lock<std::shared_timed_mutex> lock_t(_mu_time);
  return _micro_seconds_since_epoch;
}

const long long Time::time() const { return micro_seconds_since_epoch(); }

const std::string Time::to_string() const {
  std::time_t sec = micro_seconds_since_epoch() / 1000000;
  std::tm     tm;
#ifdef _WIN32
  localtime_s(&tm, &sec);  // Windows safe version
#else
  tm = *std::localtime(&sec);  // POSIX version
#endif
  char buf[20];
  std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tm);
  return std::string(buf);
}
bool Time::operator==(const Time& other) {
  if (this == &other) return true;
  return micro_seconds_since_epoch() == other.micro_seconds_since_epoch();
}
bool Time::operator!=(const Time& other) { return !(*this == other); }
}  // namespace communications
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::communications::Time)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::communications::Time)
