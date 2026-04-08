#include <falcon-core/communications/messages/StandardRequest.hpp>

namespace falcon_core {
namespace communications {
namespace messages {

StandardRequest::StandardRequest() : BaseMessage() {}
StandardRequest::StandardRequest(const std::string& message)
    : BaseMessage(message) {}

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core
