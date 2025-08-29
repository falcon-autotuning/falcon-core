#include "falcon_core/instrument_interfaces/names/Knobs.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

Knobs::Knobs() = default;

template <class Archive>
void Knobs::serialize(Archive& ar) {
  ar(cereal::base_class<Ports<Knob>>(this));
}

}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::Knobs)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::names::Knobs)
