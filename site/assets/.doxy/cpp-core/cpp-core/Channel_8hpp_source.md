

# File Channel.hpp

[**File List**](files.md) **>** [**autotuner\_interfaces**](dir_f103c4a8c56717e1b25b9ff095326f77.md) **>** [**names**](dir_8292229a53142724ca7ed55be1de9aba.md) **>** [**Channel.hpp**](Channel_8hpp.md)

[Go to the documentation of this file](Channel_8hpp.md)


```C++
#pragma once

#include <shared_mutex>

#include "falcon_core/generic/Song.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace names {
class Channel : public generic::Song {
  std::string                     _name;
  mutable std::shared_timed_mutex _mu_name;
 public:
  Channel(const Channel& other);
  Channel& operator=(const Channel& other);
  Channel(const std::string& name);
  std::string name() const;
  bool        operator==(const Channel& other) const;
  bool        operator!=(const Channel& other) const;

 protected:
  Channel();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_name(_mu_name);
    ar(cereal::base_class<generic::Song>(this), _name);
  }
};
using ChannelSP = std::shared_ptr<Channel>;
}  // namespace names
}  // namespace autotuner_interfaces
}  // namespace falcon_core
```


