#include "falcon_core/instrument_interfaces/names/Timer.hpp"

#include "falcon_core/physics/units/SymbolUnit.hpp"

namespace falcon_core::instrument_interfaces::names {

Timer::Timer()
    : Knob(INSTRUMENT_TYPES::CLOCK,  // default_name
           nullptr,                  // pseudo_name
           INSTRUMENT_TYPES::CLOCK,  // instrument_type
           physics::units::SymbolUnit::Second(),
           "A time clock used for measurement aquisition and synchronization") {
}

}  // namespace falcon_core::instrument_interfaces::names

CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::Timer)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::names::Timer)
