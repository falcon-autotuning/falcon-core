#include <falcon_core/communications/messages/StandardRequest.hpp>

namespace falcon_core {
namespace communications {
namespace messages {

StandardRequest::StandardRequest() : BaseMessage() {}
StandardRequest::StandardRequest(const std::string& message)
    : BaseMessage(message) {}

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::communications::messages::StandardRequest)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::communications::messages::BaseMessage,
    falcon_core::communications::messages::StandardRequest)
