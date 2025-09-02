#include "falcon_core/instrument_interfaces/names/Knob.hpp"

#include "falcon_core/physics/device_structures/BaseConnection.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

Knob::Knob() = default;

Knob::Knob(
    std::string                                                 default_name,
    std::shared_ptr<physics::device_structures::BaseConnection> pseudo_name,
    Instrument                                                  instrument_type,
    std::shared_ptr<physics::units::SymbolUnit>                 units,
    std::string                                                 description)
    : InstrumentPort<physics::device_structures::BaseConnection>(
          std::move(default_name),
          std::move(pseudo_name),
          std::move(instrument_type),
          std::move(units),
          std::move(description)) {}

template <class Archive>
void Knob::serialize(Archive& ar) {
  ar(cereal::base_class<
      InstrumentPort<physics::device_structures::BaseConnection>>(this));
}

}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::Knob)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, falcon_core::instrument_interfaces::names::Knob)
