#include "falcon_core/physics/config/geometries/RightReservoirWithImplantedOhmic.hpp"

namespace falcon_core::physics::config::geometries {
RightReservoirWithImplantedOhmic::RightReservoirWithImplantedOhmic() = default;
RightReservoirWithImplantedOhmic::RightReservoirWithImplantedOhmic(
    std::string                      name,
    device_structures::BarrierGateSP right_neighbor,
    device_structures::OhmicSP       ohmic)
    : ReservoirGate(name),
      HasLeftNeighbor(right_neighbor),
      HasImplantedOhmic(ohmic) {}
template <class Archive>
void RightReservoirWithImplantedOhmic::serialize(Archive& ar) {
  ar(cereal::base_class<ReservoirGate>(this),
     cereal::base_class<HasImplantedOhmic>(this),
     cereal::base_class<HasLeftNeighbor>(this));
}
}  // namespace falcon_core::physics::config::geometries

CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::RightReservoirWithImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::ReservoirGate,
    falcon_core::physics::config::geometries::RightReservoirWithImplantedOhmic)
