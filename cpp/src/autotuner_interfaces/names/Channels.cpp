#include "falcon_core/autotuner_interfaces/names/Channels.hpp"

namespace falcon_core {
namespace autotuner_interfaces {
namespace names {

Channels::Channels() = default;
Channels::Channels(const std::vector<std::shared_ptr<Channel>>& vec)
    : falcon_core::generic::List<Channel>(vec) {}

bool Channels::operator==(const Channels& other) const {
  return generic::List<Channel>::operator==(other);
}

bool Channels::operator!=(const Channels& other) const {
  return !(*this == other);
}

}  // namespace names
}  // namespace autotuner_interfaces
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(falcon_core::autotuner_interfaces::names::Channels)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::names::Channels)
