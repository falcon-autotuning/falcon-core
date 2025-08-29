#include "falcon_core/instrument_interfaces/names/Meters.hpp"

namespace falcon_core {
namespace instrument_interfaces {
namespace names {

Meters::Meters() = default;

template <class Archive>
void Meters::serialize(Archive& ar) {
  ar(cereal::base_class<Ports<Meter>>(this));
}

}  // namespace names
}  // namespace instrument_interfaces
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::instrument_interfaces::names::Meters)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::instrument_interfaces::names::Meters)
