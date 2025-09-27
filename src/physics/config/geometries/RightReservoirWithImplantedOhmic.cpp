#include "falcon_core/physics/config/geometries/RightReservoirWithImplantedOhmic.hpp"

#include <stdexcept>

#include "falcon_core/physics/config/geometries/HasLeftNeighbor.hpp"
#include "falcon_core/physics/device_structures/Connection.hpp"

namespace falcon_core::physics::config::geometries {
RightReservoirWithImplantedOhmic::RightReservoirWithImplantedOhmic() = default;
RightReservoirWithImplantedOhmic::RightReservoirWithImplantedOhmic(
    std::string                     name,
    device_structures::ConnectionSP left_neighbor,
    device_structures::ConnectionSP ohmic)
    : Connection(name, device_structures::DeviceFeature::ReservoirGate) {
  if (!left_neighbor) {
    throw std::invalid_argument(
        "RightReservoirWithImplantedOhmic: The left neighbor must not be "
        "null.");
  }
  if (!ohmic) {
    throw std::invalid_argument(
        "RightReservoirWithImplantedOhmic: The ohmic must not be null.");
  }
  if (!ohmic->is_ohmic()) {
    throw std::invalid_argument(
        "RightReservoirWithImplantedOhmic: Expected only type ohmic for the "
        "implanted ohmic but got " +
        ohmic->type());
  }
  if (!left_neighbor->is_barrier_gate()) {
    throw std::invalid_argument(
        "RightReservoirWithImplantedOhmic: Expected only type barriergate for "
        "the right neighbor but got " +
        left_neighbor->type());
  }
  HasLeftNeighbor::  operator=(HasLeftNeighbor(left_neighbor));
  HasImplantedOhmic::operator=(HasImplantedOhmic(ohmic));
}
}  // namespace falcon_core::physics::config::geometries

CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::RightReservoirWithImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::Connection,
    falcon_core::physics::config::geometries::RightReservoirWithImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::config::geometries::HasImplantedOhmic,
    falcon_core::physics::config::geometries::RightReservoirWithImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::config::geometries::HasLeftNeighbor,
    falcon_core::physics::config::geometries::RightReservoirWithImplantedOhmic)
