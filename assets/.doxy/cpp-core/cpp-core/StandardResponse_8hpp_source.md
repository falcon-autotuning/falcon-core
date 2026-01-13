

# File StandardResponse.hpp

[**File List**](files.md) **>** [**communications**](dir_b94a6b29f2c7b9c121097afc928ed71e.md) **>** [**messages**](dir_f6911bd59d3e24442984bf7e05e945fa.md) **>** [**StandardResponse.hpp**](StandardResponse_8hpp.md)

[Go to the documentation of this file](StandardResponse_8hpp.md)


```C++
#pragma once

#include <falcon_core/communications/messages/BaseMessage.hpp>

namespace falcon_core {
namespace communications {
namespace messages {

class StandardResponse : public BaseMessage {
 public:
  StandardResponse(const std::string& message);

 protected:
  friend class cereal::access;
  StandardResponse();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseMessage>(this));
  }
};
using StandardResponseSP = std::shared_ptr<StandardResponse>;

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core
```


