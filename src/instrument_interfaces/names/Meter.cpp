#include "falcon_core/instrument_interfaces/names/Meter.hpp"

namespace falcon_core::instrument_interfaces::names {

Meter::Meter() = default;

Meter::Meter(std::string                              default_name,
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

CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::Meter)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::names::Meter)
