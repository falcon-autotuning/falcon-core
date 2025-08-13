#pragma once

#include <chrono>

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace communications {

class Time : public generic::Song<Time> {
 public:
  Time();

  // Returns seconds since epoch
  long long time() const;

 private:
  std::chrono::system_clock::time_point _now;
};
}  // namespace communications
}  // namespace falcon_core
