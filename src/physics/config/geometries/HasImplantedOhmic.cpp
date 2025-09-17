#include "falcon_core/physics/config/geometries/HasImplantedOhmic.hpp"

#include "falcon_core/physics/device_structures/Ohmic.hpp"
using OhmicSP = falcon_core::physics::device_structures::OhmicSP;

namespace falcon_core::physics::config::geometries {
HasImplantedOhmic::HasImplantedOhmic() = default;
HasImplantedOhmic::HasImplantedOhmic(OhmicSP ohmic) : _ohmic(ohmic) {}
OhmicSP HasImplantedOhmic::ohmic() const { return _ohmic; }
}  // namespace falcon_core::physics::config::geometries

CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::HasImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::geometries::HasImplantedOhmic)
