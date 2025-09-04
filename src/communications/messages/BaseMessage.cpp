#include <falcon_core/communications/messages/BaseMessage.hpp>

namespace falcon_core {
namespace communications {
namespace messages {

BaseMessage::BaseMessage() = default;
BaseMessage::BaseMessage(const std::string& message) : _message(message) {}

const std::string& BaseMessage::message() const { return _message; }

template <class Archive>
void BaseMessage::serialize(Archive& ar) {
  ar(cereal::base_class<generic::Song>(this), _message);
}

template void BaseMessage::serialize<cereal::JSONOutputArchive>(cereal::JSONOutputArchive& ar);
template void BaseMessage::serialize<cereal::JSONInputArchive>(cereal::JSONInputArchive& ar);

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::communications::messages::BaseMessage)
