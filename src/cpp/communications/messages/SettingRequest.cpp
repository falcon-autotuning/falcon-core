#include <falcon-core/communications/messages/SettingRequest.hpp>

#include <stdexcept>

namespace falcon_core {
namespace communications {
namespace messages {

SettingRequest::SettingRequest(const SettingRequest &other)
    : BaseMessage(other) {
  std::unique_lock<std::shared_timed_mutex> lock_getters(_mu_getters,
                                                         std::defer_lock);
  std::unique_lock<std::shared_timed_mutex> lock_setters(_mu_setters,
                                                         std::defer_lock);

  std::lock(lock_getters, lock_setters);

  if (!other.getters() || !other.setters()) {
    throw std::invalid_argument(
        "SettingRequest copy constructor: Other SettingRequest "
        "contains null shared pointers.");
  }

  _getters =
      std::make_shared<instrument_interfaces::names::Ports>(*other.getters());

  _setters = std::make_shared<generic::Map<
      instrument_interfaces::names::InstrumentPort, math::Quantity>>(
      *other.setters());
}

SettingRequest &SettingRequest::operator=(const SettingRequest &other) {
  if (this != &other) {
    BaseMessage::operator=(other);

    std::unique_lock<std::shared_timed_mutex> lock_getters(_mu_getters,
                                                           std::defer_lock);
    std::unique_lock<std::shared_timed_mutex> lock_setters(_mu_setters,
                                                           std::defer_lock);

    std::lock(lock_getters, lock_setters);

    if (!other.getters() || !other.setters()) {
      throw std::invalid_argument(
          "SettingRequest assignment operator: Other SettingRequest "
          "contains null shared pointers.");
    }

    _getters =
        std::make_shared<instrument_interfaces::names::Ports>(*other.getters());

    _setters = std::make_shared<generic::Map<
        instrument_interfaces::names::InstrumentPort, math::Quantity>>(
        *other.setters());
  }

  return *this;
}

SettingRequest::SettingRequest() = default;

SettingRequest::SettingRequest(
    const std::string &message,
    const instrument_interfaces::names::PortsSP &getters,
    const generic::MapSP<instrument_interfaces::names::InstrumentPort,
                         math::Quantity> &setters)
    : BaseMessage(message), _getters(getters), _setters(setters) {
  if (!getters || !setters) {
    throw std::invalid_argument(
        "SettingRequest: The getters and setters must not be null.");
  }
}

const instrument_interfaces::names::PortsSP &SettingRequest::getters() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_getters);
  return _getters;
}

const generic::MapSP<instrument_interfaces::names::InstrumentPort,
                     math::Quantity> &
SettingRequest::setters() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_setters);
  return _setters;
}

bool SettingRequest::operator==(const SettingRequest &other) const {
  if (this == &other) {
    return true;
  }

  return (*getters() == *other.getters()) && (*setters() == *other.setters()) &&
         BaseMessage::operator==(other);
}

bool SettingRequest::operator!=(const SettingRequest &other) const {
  return !(*this == other);
}

} // namespace messages
} // namespace communications
} // namespace falcon_core
