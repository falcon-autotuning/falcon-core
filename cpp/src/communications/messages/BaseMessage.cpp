#include <falcon_core/communications/messages/BaseMessage.hpp>
#include <mutex>

namespace falcon_core {
namespace communications {
namespace messages {
BaseMessage::BaseMessage(const BaseMessage& other) {
  std::unique_lock<std::shared_timed_mutex> lock_m(_mu_message);
  _message = other.message();
}
BaseMessage& BaseMessage::operator=(const BaseMessage& other) {
  if (this != &other) {
    std::unique_lock<std::shared_timed_mutex> lock_m(_mu_message);
    _message = other.message();
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
  if (this == &other) return true;
  return (message() == other.message());
}
bool BaseMessage::operator!=(const BaseMessage& other) const {
  return !(*this == other);
}

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core
