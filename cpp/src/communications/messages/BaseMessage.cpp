#include <falcon_core/communications/messages/BaseMessage.hpp>
#include <mutex>

#include "cereal/types/polymorphic.hpp"

namespace falcon_core {
namespace communications {
namespace messages {
BaseMessage::BaseMessage(const BaseMessage& other) {
  std::shared_lock<std::shared_timed_mutex> lock_m(_mu_message);
  _message = other._message;
}
BaseMessage BaseMessage::operator=(const BaseMessage& other) {
  if (this != &other) {
    std::shared_lock<std::shared_timed_mutex> lock_m(_mu_message,
                                                     std::defer_lock);
    std::shared_lock<std::shared_timed_mutex> lock_o(other._mu_message,
                                                     std::defer_lock);
    std::lock(lock_m, lock_o);
    _message = other._message;
  }
  return *this;
}
BaseMessage::BaseMessage() = default;
BaseMessage::BaseMessage(const std::string& message) : _message(message) {}

const std::string& BaseMessage::message() const {
  std::shared_lock<std::shared_timed_mutex> lock_m(_mu_message);
  return _message;
}
bool BaseMessage::operator==(const BaseMessage& other) const {
  return (message() == other.message());
}
bool BaseMessage::operator!=(const BaseMessage& other) const {
  return !(*this == other);
}

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::communications::messages::BaseMessage)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::communications::messages::BaseMessage)
