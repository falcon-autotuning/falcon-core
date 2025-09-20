#include "falcon_core/physics/config/geometries/LeftReservoirWithImplantedOhmic.hpp"

#include <stdexcept>

#include "falcon_core/physics/device_structures/Connection.hpp"

namespace falcon_core::physics::config::geometries {
LeftReservoirWithImplantedOhmic::LeftReservoirWithImplantedOhmic() = default;
LeftReservoirWithImplantedOhmic::LeftReservoirWithImplantedOhmic(
    std::string                     name,
    device_structures::ConnectionSP right_neighbor,
    device_structures::ConnectionSP ohmic)
    : Connection(name, device_structures::DeviceFeature::ReservoirGate),
      HasRightNeighbor(right_neighbor),
      HasImplantedOhmic(ohmic) {
  if (!ohmic->is_ohmic()) {
    throw std::runtime_error(
        "Expected only type ohmic for the implanted ohmic but got " +
        ohmic->type());
  }
  if (!right_neighbor->is_barrier_gate()) {
    throw std::runtime_error(
        "Expected only type barriergate for the right neighbor but got " +
        right_neighbor->type());
  }
}
}  // namespace falcon_core::physics::config::geometries
CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::LeftReservoirWithImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::Connection,
    falcon_core::physics::config::geometries::LeftReservoirWithImplantedOhmic)
