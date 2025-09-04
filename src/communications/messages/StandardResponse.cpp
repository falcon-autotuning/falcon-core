#include <falcon_core/communications/messages/StandardResponse.hpp>

namespace falcon_core {
namespace communications {
namespace messages {

StandardResponse::StandardResponse() : BaseMessage() {}
StandardResponse::StandardResponse(const std::string& message) : BaseMessage(message) {}

template <class Archive>
void StandardResponse::serialize(Archive& ar) {
  ar(cereal::base_class<BaseMessage>(this));
}

template void StandardResponse::serialize<cereal::JSONOutputArchive>(cereal::JSONOutputArchive& ar);
template void StandardResponse::serialize<cereal::JSONInputArchive>(cereal::JSONInputArchive& ar);

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::communications::messages::StandardResponse)
