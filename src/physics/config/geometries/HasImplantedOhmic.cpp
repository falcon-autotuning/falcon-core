#include "falcon_core/physics/config/geometries/HasImplantedOhmic.hpp"

#include <stdexcept>

#include "falcon_core/physics/device_structures/Connection.hpp"

namespace falcon_core::physics::config::geometries {
HasImplantedOhmic::HasImplantedOhmic() = default;
HasImplantedOhmic::HasImplantedOhmic(device_structures::ConnectionSP ohmic)
    : _ohmic(ohmic) {
  if (!ohmic->is_ohmic()) {
    throw std::runtime_error("This needs to be an ohmic, not a " +
                             ohmic->type());
  }
}
device_structures::ConnectionSP HasImplantedOhmic::ohmic() const {
  return _ohmic;
}
}  // namespace falcon_core::physics::config::geometries

CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::HasImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::geometries::HasImplantedOhmic)
