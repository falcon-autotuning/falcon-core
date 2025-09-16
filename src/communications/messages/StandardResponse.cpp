#include <falcon_core/communications/messages/StandardResponse.hpp>

namespace falcon_core::communications::messages {

StandardResponse::StandardResponse() : BaseMessage() {}
StandardResponse::StandardResponse(const std::string& message)
    : BaseMessage(message) {}

}  // namespace falcon_core::communications::messages

CEREAL_REGISTER_TYPE(falcon_core::communications::messages::StandardResponse)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::communications::messages::BaseMessage,
    falcon_core::communications::messages::StandardResponse)
