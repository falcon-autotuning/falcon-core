#include "falcon_core/instrument_interfaces/names/Knob.hpp"

#include "falcon_core/physics/device_structures/Connection.hpp"

namespace falcon_core::instrument_interfaces::names {

Knob::Knob() = default;

Knob::Knob(std::string                              default_name,
           physics::device_structures::ConnectionSP pseudo_name,
           Instrument                               instrument_type,
           physics::units::SymbolUnitSP             units,
           std::string                              description)
    : InstrumentPort(std::move(default_name),
                     std::move(pseudo_name),
                     std::move(instrument_type),
                     std::move(units),
                     std::move(description)) {}

}  // namespace falcon_core::instrument_interfaces::names

CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::Knob)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::instrument_interfaces::names::Knob)
