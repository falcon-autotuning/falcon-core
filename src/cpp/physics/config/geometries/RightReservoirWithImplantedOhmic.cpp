#include "falcon-core/physics/config/geometries/RightReservoirWithImplantedOhmic.hpp"

#include <stdexcept>

#include "falcon-core/physics/config/geometries/HasLeftNeighbor.hpp"
#include "falcon-core/physics/device_structures/Connection.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
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
  HasLeftNeighbor::operator=(HasLeftNeighbor(left_neighbor));
  HasImplantedOhmic::operator=(HasImplantedOhmic(ohmic));
}
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
