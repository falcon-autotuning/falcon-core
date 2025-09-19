#include "falcon_core/instrument_interfaces/names/ExecutionClock.hpp"

namespace falcon_core::instrument_interfaces::names {

ExecutionClock::ExecutionClock()
    : Meter(falcon_core::INSTRUMENT_TYPES::CLOCK,  // default_name
            nullptr,                               // pseudo_name
            falcon_core::INSTRUMENT_TYPES::CLOCK,  // instrument_type
            physics::units::SymbolUnit::Second(),
            "Clock used to show time traces after execution") {}

}  // namespace falcon_core::instrument_interfaces::names

CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::ExecutionClock)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::names::ExecutionClock)
