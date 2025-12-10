#include <falcon_core/communications/messages/StandardResponse.hpp>

namespace falcon_core {
namespace communications {
namespace messages {

StandardResponse::StandardResponse() : BaseMessage() {}
StandardResponse::StandardResponse(const std::string& message)
    : BaseMessage(message) {}

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::communications::messages::StandardResponse)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::communications::messages::BaseMessage,
    falcon_core::communications::messages::StandardResponse)
