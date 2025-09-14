#include "falcon_core/instrument_interfaces/names/Meter.hpp"

namespace falcon_core::instrument_interfaces::names {

Meter::Meter() = default;

Meter::Meter(std::string                                        default_name,
             std::shared_ptr<physics::device_structures::Ohmic> pseudo_name,
             Instrument                                         instrument_type,
             std::shared_ptr<physics::units::SymbolUnit>        units,
             std::string                                        description)
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
