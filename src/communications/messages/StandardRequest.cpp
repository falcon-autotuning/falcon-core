#include <falcon_core/communications/messages/StandardRequest.hpp>

namespace falcon_core::communications::messages {

StandardRequest::StandardRequest() : BaseMessage() {}
StandardRequest::StandardRequest(const std::string& message)
    : BaseMessage(message) {}

template <class Archive>
void StandardRequest::serialize(Archive& ar) {
  ar(cereal::base_class<BaseMessage>(this));
}

template void StandardRequest::serialize<cereal::JSONOutputArchive>(
    cereal::JSONOutputArchive& ar);
template void StandardRequest::serialize<cereal::JSONInputArchive>(
    cereal::JSONInputArchive& ar);

}  // namespace falcon_core::communications::messages

CEREAL_REGISTER_TYPE(falcon_core::communications::messages::StandardRequest)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::communications::messages::BaseMessage,
    falcon_core::communications::messages::StandardRequest)
