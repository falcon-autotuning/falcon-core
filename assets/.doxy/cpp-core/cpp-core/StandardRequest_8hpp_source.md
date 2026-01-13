

# File StandardRequest.hpp

[**File List**](files.md) **>** [**communications**](dir_b94a6b29f2c7b9c121097afc928ed71e.md) **>** [**messages**](dir_f6911bd59d3e24442984bf7e05e945fa.md) **>** [**StandardRequest.hpp**](StandardRequest_8hpp.md)

[Go to the documentation of this file](StandardRequest_8hpp.md)


```C++
#pragma once

#include <falcon_core/communications/messages/BaseMessage.hpp>

namespace falcon_core {
namespace communications {
namespace messages {

class StandardRequest : public BaseMessage {
 public:
  StandardRequest(const std::string& message);

 protected:
  friend class cereal::access;
  StandardRequest();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseMessage>(this));
  }
};
using StandardRequestSP = std::shared_ptr<StandardRequest>;
}  // namespace messages
}  // namespace communications
}  // namespace falcon_core
```


