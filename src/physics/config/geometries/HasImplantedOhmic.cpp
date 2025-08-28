#include "falcon_core/physics/config/geometries/HasImplantedOhmic.hpp"

#include "falcon_core/physics/device_structures/Ohmic.hpp"
using OhmicSP = falcon_core::physics::device_structures::OhmicSP;

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
HasImplantedOhmic::HasImplantedOhmic() = default;
HasImplantedOhmic::HasImplantedOhmic(OhmicSP ohmic) : _ohmic(ohmic) {}
OhmicSP HasImplantedOhmic::ohmic() const { return _ohmic; }
template <class Archive>
void HasImplantedOhmic::serialize(Archive& ar) {
  ar(cereal::base_class<HasImplantedOhmic>(this), _ohmic);
}
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::HasImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::geometries::HasImplantedOhmic)
