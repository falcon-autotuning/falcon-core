#include <falcon_core/communications/messages/BaseMessage.hpp>

#include "cereal/types/polymorphic.hpp"

namespace falcon_core::communications::messages {

BaseMessage::BaseMessage() = default;
BaseMessage::BaseMessage(const std::string &message) : _message(message) {}

const std::string &BaseMessage::message() const { return _message; }

}  // namespace falcon_core::communications::messages

CEREAL_REGISTER_TYPE(falcon_core::communications::messages::BaseMessage)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::communications::messages::BaseMessage)
