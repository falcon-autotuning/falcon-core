#include "falcon_core/physics/config/geometries/LeftReservoirWithImplantedOhmic.hpp"

#include "falcon_core/physics/device_structures/ReservoirGate.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
LeftReservoirWithImplantedOhmic::LeftReservoirWithImplantedOhmic() = default;
LeftReservoirWithImplantedOhmic::LeftReservoirWithImplantedOhmic(
    std::string                      name,
    device_structures::BarrierGateSP right_neighbor,
    device_structures::OhmicSP       ohmic)
    : ReservoirGate(name),
      HasRightNeighbor(right_neighbor),
      HasImplantedOhmic(ohmic) {}
template <class Archive>
void LeftReservoirWithImplantedOhmic::serialize(Archive& ar) {
  ar(cereal::base_class<ReservoirGate>(this),
     cereal::base_class<HasImplantedOhmic>(this),
     cereal::base_class<HasRightNeighbor>(this));
}
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(LeftReservoirWithImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::ReservoirGate,
    LeftReservoirWithImplantedOhmic)
