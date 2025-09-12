#include <cereal/archives/binary.hpp>
#include <falcon_core/communications/messages/BaseMessage.hpp>

namespace falcon_core {
namespace communications {
namespace messages {

BaseMessage::BaseMessage() = default;
BaseMessage::BaseMessage(const std::string &message) : _message(message) {}

const std::string &BaseMessage::message() const { return _message; }

template <class Archive>
void BaseMessage::serialize(Archive &ar) {
  ar(cereal::base_class<generic::Song>(this), _message);
}

// Explicit instantiations for Cereal archives
template void BaseMessage::serialize<cereal::BinaryInputArchive>(
    cereal::BinaryInputArchive &);
template void BaseMessage::serialize<cereal::BinaryOutputArchive>(
    cereal::BinaryOutputArchive &);
template void BaseMessage::serialize<cereal::JSONInputArchive>(
    cereal::JSONInputArchive &);
template void BaseMessage::serialize<cereal::JSONOutputArchive>(
    cereal::JSONOutputArchive &);
}  // namespace messages
}  // namespace communications
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::communications::messages::BaseMessage)
