#pragma once

#include <falcon_core/communications/messages/BaseMessage.hpp>

#include "falcon_core/export.h"

namespace falcon_core {
namespace communications {
namespace messages {

class FALCON_CORE_CPP_API StandardResponse : public BaseMessage {
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
