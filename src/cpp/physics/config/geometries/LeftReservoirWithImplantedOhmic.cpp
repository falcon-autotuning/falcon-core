#include "falcon-core/physics/config/geometries/LeftReservoirWithImplantedOhmic.hpp"

#include <stdexcept>

#include "falcon-core/physics/device_structures/Connection.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
LeftReservoirWithImplantedOhmic::LeftReservoirWithImplantedOhmic() = default;
LeftReservoirWithImplantedOhmic::LeftReservoirWithImplantedOhmic(
    std::string                     name,
    device_structures::ConnectionSP right_neighbor,
    device_structures::ConnectionSP ohmic)
    : Connection(name, device_structures::DeviceFeature::ReservoirGate),
      HasImplantedOhmic(ohmic),
      HasRightNeighbor(right_neighbor) {
  if (!right_neighbor->is_barrier_gate()) {
    throw std::runtime_error(
        "LeftReservoirWithImplantedOhmic: Expected only type barriergate for "
        "the right neighbor but got " +
        right_neighbor->type());
  }
}
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
