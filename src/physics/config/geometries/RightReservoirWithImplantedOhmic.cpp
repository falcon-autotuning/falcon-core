#include "falcon_core/physics/config/geometries/RightReservoirWithImplantedOhmic.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
RightReservoirWithImplantedOhmic::RightReservoirWithImplantedOhmic() = default;
RightReservoirWithImplantedOhmic::RightReservoirWithImplantedOhmic(
    std::string name, BarrierGateSP right_neighbor, OhmicSP ohmic)
    : ReservoirGate(name),
      HasLeftNeighbor(right_neighbor),
      HasImplantedOhmic(ohmic) {}
template <class Archive>
void RightReservoirWithImplantedOhmic::serialize(Archive& ar) {
  ar(cereal::base_class<ReservoirGate>(this),
     cereal::base_class<HasImplantedOhmic>(this),
     cereal::base_class<HasLeftNeighbor>(this));
}
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(RightReservoirWithImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(ReservoirGate,
                                     RightReservoirWithImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(HasImplantedOhmic,
                                     RightReservoirWithImplantedOhmic)
using HLNBG = HasLeftNeighbor<BarrierGate>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(HLNBG, RightReservoirWithImplantedOhmic)
