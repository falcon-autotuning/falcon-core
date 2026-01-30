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
