#include "falcon_core/instrument_interfaces/names/ExecutionClock.hpp"

#include "falcon_core/physics/units/CommonUnits.hpp"
namespace falcon_core {
namespace instrument_interfaces {
namespace names {

ExecutionClock::ExecutionClock()
    : Meter(falcon_core::INSTRUMENT_TYPES::CLOCK,  // default_name
            nullptr,                               // pseudo_name
            falcon_core::INSTRUMENT_TYPES::CLOCK,  // instrument_type
            std::make_shared<physics::units::SymbolUnit>(
                physics::units::CommonUnits::Second),
            "Execution clock") {}

template <class Archive>
void ExecutionClock::serialize(Archive& ar) {
  ar(cereal::base_class<Meter>(this));
}

}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::ExecutionClock)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::names::ExecutionClock)
