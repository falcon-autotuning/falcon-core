#pragma once

#include <falcon_core/communications/messages/BaseMessage.hpp>

#include "falcon_core/export.h"

namespace falcon_core {
namespace communications {
namespace messages {

class FALCON_CORE_CPP_API StandardRequest : public BaseMessage {
 public:
  StandardRequest(const std::string& message);

 protected:
  friend class cereal::access;
  StandardRequest();
  template <class Archive>
  inline void serialize(Archive& ar) {
    ar(cereal::base_class<BaseMessage>(this));
  }
};
using StandardRequestSP = std::shared_ptr<StandardRequest>;
}  // namespace messages
}  // namespace communications
}  // namespace falcon_core
