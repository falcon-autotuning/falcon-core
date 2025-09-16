#include "falcon_core/autotuner_interfaces/names/Channels.hpp"

namespace falcon_core::autotuner_interfaces::names {

Channels::Channels() = default;
Channels::Channels(const std::vector<std::shared_ptr<Channel>>& vec)
    : falcon_core::generic::List<Channel>(vec) {}

}  // namespace falcon_core::autotuner_interfaces::names
CEREAL_REGISTER_TYPE(falcon_core::autotuner_interfaces::names::Channels)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::autotuner_interfaces::names::Channels)
