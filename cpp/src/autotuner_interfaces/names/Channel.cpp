#include "falcon_core/autotuner_interfaces/names/Channel.hpp"

#include <mutex>

namespace falcon_core {
namespace autotuner_interfaces {
namespace names {
Channel::Channel(const Channel& other) {
  std::unique_lock<std::shared_timed_mutex> lock_name(_mu_name);
  _name = other.name();
}
Channel& Channel::operator=(const Channel& other) {
  if (this != &other) {
    std::unique_lock<std::shared_timed_mutex> lock_name(_mu_name);
    _name = other.name();
  }
  return *this;
}
Channel::Channel(const std::string& name) : _name(name) {};
std::string Channel::name() const {
  std::shared_lock<std::shared_timed_mutex> lock(_mu_name);
  return _name;
}

Channel::Channel() : _name("") {};
bool Channel::operator==(const Channel& other) const {
  return name() == other.name();
}
bool Channel::operator!=(const Channel& other) const {
  return !(*this == other);
}
}  // namespace names
}  // namespace autotuner_interfaces
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::autotuner_interfaces::names::Channel)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::names::Channel)
