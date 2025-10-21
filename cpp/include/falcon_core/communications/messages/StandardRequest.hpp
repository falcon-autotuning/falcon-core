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
