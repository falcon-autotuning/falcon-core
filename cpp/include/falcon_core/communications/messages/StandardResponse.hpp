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
