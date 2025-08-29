#include "falcon_core/instrument_interfaces/names/Timer.hpp"
#include <memory>

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

Timer::Timer()
    : Knob(falcon_core::INSTRUMENT_TYPES::CLOCK,  // default_name
           nullptr,                               // pseudo_name
           falcon_core::INSTRUMENT_TYPES::CLOCK,  // instrument_type
           std::make_shared<physics::units::SymbolUnit>(
               physics::units::CommonUnits::Second),
           "Clock") {}

template <class Archive>
void Timer::serialize(Archive& ar) {
  ar(cereal::base_class<Knob>(this));
}

}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::Timer)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::names::Timer)
