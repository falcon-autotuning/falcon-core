#include "falcon_core/instrument_interfaces/names/Knobs.hpp"

namespace falcon_core::instrument_interfaces::names {

Knobs::Knobs() = default;
Knobs::Knobs(const std::vector<KnobSP>& knobs) : Ports<Knob>(knobs) {}

}  // namespace falcon_core::instrument_interfaces::names

CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::Knobs)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::names::Knobs)
