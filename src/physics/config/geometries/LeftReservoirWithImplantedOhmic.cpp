#include "falcon_core/physics/config/geometries/LeftReservoirWithImplantedOhmic.hpp"

#include "falcon_core/physics/device_structures/ReservoirGate.hpp"

namespace falcon_core::physics::config::geometries {
LeftReservoirWithImplantedOhmic::LeftReservoirWithImplantedOhmic() = default;
LeftReservoirWithImplantedOhmic::LeftReservoirWithImplantedOhmic(
    std::string                      name,
    device_structures::BarrierGateSP right_neighbor,
    device_structures::OhmicSP       ohmic)
    : ReservoirGate(name),
      HasRightNeighbor(right_neighbor),
      HasImplantedOhmic(ohmic) {}
}  // namespace falcon_core::physics::config::geometries
