#include "falcon_core/physics/config/geometries/LeftReservoirWithImplantedOhmic.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
LeftReservoirWithImplantedOhmic::LeftReservoirWithImplantedOhmic() = default;
LeftReservoirWithImplantedOhmic::LeftReservoirWithImplantedOhmic(
    std::string name, BarrierGateSP right_neighbor, OhmicSP ohmic)
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
CEREAL_REGISTER_POLYMORPHIC_RELATION(ReservoirGate,
                                     LeftReservoirWithImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(HasImplantedOhmic,
                                     LeftReservoirWithImplantedOhmic)
using HRNBG = HasRightNeighbor<BarrierGate>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(HRNBG, LeftReservoirWithImplantedOhmic)
