#pragma once

#include <falcon_core/communications/messages/BaseMessage.hpp>

namespace falcon_core {
namespace communications {
namespace messages {

class StandardResponse : public BaseMessage {
 public:
  StandardResponse();
  explicit StandardResponse(const std::string& message);

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core
