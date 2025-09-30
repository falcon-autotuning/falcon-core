#include "falcon_core/autotuner_interfaces/names/Channel.hpp"

namespace falcon_core::autotuner_interfaces::names {
Channel::Channel(const std::string& name) : _name(name) {};
std::string Channel::name() const { return _name; }

Channel::Channel() : _name("") {};
bool Channel::operator==(const Channel& other) const {
  return name() == other.name();
}
bool Channel::operator!=(const Channel& other) const {
  return !(*this == other);
}
}  // namespace falcon_core::autotuner_interfaces::names
CEREAL_REGISTER_TYPE(falcon_core::autotuner_interfaces::names::Channel)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::names::Channel)
