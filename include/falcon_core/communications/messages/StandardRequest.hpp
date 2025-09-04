#pragma once

#include <falcon_core/communications/messages/BaseMessage.hpp>
#include <string>

namespace falcon_core {
namespace communications {
namespace messages {

class StandardRequest : public BaseMessage {
 public:
  StandardRequest();
  explicit StandardRequest(const std::string& message);

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core
