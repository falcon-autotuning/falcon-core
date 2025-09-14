#include "falcon_core/instrument_interfaces/names/Timer.hpp"

#include "falcon_core/physics/units/CommonUnits.hpp"

namespace falcon_core::instrument_interfaces::names {

Timer::Timer()
    : Knob(falcon_core::INSTRUMENT_TYPES::CLOCK,  // default_name
           nullptr,                               // pseudo_name
           falcon_core::INSTRUMENT_TYPES::CLOCK,  // instrument_type
           std::make_shared<physics::units::SymbolUnit>(
               physics::units::CommonUnits::Second),
           "Clock") {}

}  // namespace falcon_core::instrument_interfaces::names

CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::Timer)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::names::Timer)
