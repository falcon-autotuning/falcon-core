#include "falcon_core/instrument_interfaces/names/Meters.hpp"

namespace falcon_core::instrument_interfaces::names {

Meters::Meters() = default;
Meters::Meters(const std::vector<MeterSP>& knobs) : Ports<Meter>(knobs) {}

}  // namespace falcon_core::instrument_interfaces::names

CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::Meters)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::names::Meters)
