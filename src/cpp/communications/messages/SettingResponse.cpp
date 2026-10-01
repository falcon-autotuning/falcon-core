#include <falcon-core/communications/messages/SettingResponse.hpp>

#include <stdexcept>

namespace falcon_core {
namespace communications {
namespace messages {

SettingResponse::SettingResponse(const SettingResponse &other)
    : BaseMessage(other) {
  std::unique_lock<std::shared_timed_mutex> lock_getters(_mu_getters);

  if (!other.getters()) {
    throw std::invalid_argument(
        "SettingResponse copy constructor: Other SettingResponse "
        "contains null shared pointers.");
  }

  _getters = std::make_shared<generic::Map<
      instrument_interfaces::names::InstrumentPort, math::Quantity>>(
      *other.getters());
}

SettingResponse &SettingResponse::operator=(const SettingResponse &other) {
  if (this != &other) {
    BaseMessage::operator=(other);

    std::unique_lock<std::shared_timed_mutex> lock_getters(_mu_getters);

    if (!other.getters()) {
      throw std::invalid_argument(
          "SettingResponse assignment operator: Other SettingResponse "
          "contains null shared pointers.");
    }

    _getters = std::make_shared<generic::Map<
        instrument_interfaces::names::InstrumentPort, math::Quantity>>(
        *other.getters());
  }

  return *this;
}

SettingResponse::SettingResponse() = default;

SettingResponse::SettingResponse(
    const std::string &message,
    const generic::MapSP<instrument_interfaces::names::InstrumentPort,
                         math::Quantity> &getters)
    : BaseMessage(message), _getters(getters) {
  if (!getters) {
    throw std::invalid_argument(
        "SettingResponse: The getters map must not be null.");
  }
}

const generic::MapSP<instrument_interfaces::names::InstrumentPort,
                     math::Quantity> &
SettingResponse::getters() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_getters);
  return _getters;
}

bool SettingResponse::operator==(const SettingResponse &other) const {
  if (this == &other) {
    return true;
  }

  return (*getters() == *other.getters()) && BaseMessage::operator==(other);
}

bool SettingResponse::operator!=(const SettingResponse &other) const {
  return !(*this == other);
}

} // namespace messages
} // namespace communications
} // namespace falcon_core
