

# File Time.hpp

[**File List**](files.md) **>** [**communications**](dir_b94a6b29f2c7b9c121097afc928ed71e.md) **>** [**Time.hpp**](Time_8hpp.md)

[Go to the documentation of this file](Time_8hpp.md)


```C++
#pragma once

#include <shared_mutex>

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace communications {
class Time : public generic::Song {
  long long                       _micro_seconds_since_epoch;
  mutable std::shared_timed_mutex _mu_time;

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _micro_seconds_since_epoch);
  }

 public:
  Time(const Time& other);
  Time& operator=(const Time& other);
  Time();

  Time(long long micro_seconds_since_epoch);

  const long long micro_seconds_since_epoch() const;
  const long long time() const;

  const std::string to_string() const;
  bool              operator==(const Time& other);
  bool              operator!=(const Time& other);
};
using TimeSP = std::shared_ptr<Time>;
}  // namespace communications
}  // namespace falcon_core
```


