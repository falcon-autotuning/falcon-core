

# File Channels.hpp

[**File List**](files.md) **>** [**autotuner\_interfaces**](dir_f103c4a8c56717e1b25b9ff095326f77.md) **>** [**names**](dir_8292229a53142724ca7ed55be1de9aba.md) **>** [**Channels.hpp**](Channels_8hpp.md)

[Go to the documentation of this file](Channels_8hpp.md)


```C++
#pragma once

#include "falcon_core/autotuner_interfaces/names/Channel.hpp"
#include "falcon_core/generic/List.hpp"
namespace falcon_core {
namespace autotuner_interfaces {
namespace names {

class Channels : public generic::List<Channel> {
 public:
  Channels();
  Channels(const std::vector<std::shared_ptr<Channel>>& vec);

  bool operator==(const Channels& other) const;
  bool operator!=(const Channels& other) const;
};
using ChannelsSP = std::shared_ptr<Channels>;
}  // namespace names
}  // namespace autotuner_interfaces
}  // namespace falcon_core
```


