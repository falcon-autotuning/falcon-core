#pragma once

#include "Jsonable.hpp"
#include <chrono>

namespace falcon_core {

class Time : public Jsonable {
public:
  Time();

  // Returns seconds since epoch
  long long time() const;
  nlohmann::json to_json() const override;
  size_t hash() const override;

private:
  std::chrono::system_clock::time_point _now;
};

} // namespace falcon_core
