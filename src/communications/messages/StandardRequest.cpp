#include <falcon_core/communications/messages/StandardRequest.hpp>

namespace falcon_core {
namespace communications {
namespace messages {

StandardRequest::StandardRequest() : BaseMessage() {}
StandardRequest::StandardRequest(const std::string& message) : BaseMessage(message) {}

template <class Archive>
void StandardRequest::serialize(Archive& ar) {
  ar(cereal::base_class<BaseMessage>(this));
}

template void StandardRequest::serialize<cereal::JSONOutputArchive>(cereal::JSONOutputArchive& ar);
template void StandardRequest::serialize<cereal::JSONInputArchive>(cereal::JSONInputArchive& ar);

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::communications::messages::StandardRequest)
