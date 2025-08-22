#pragma once

#include "falcon_core/physics/config/geometries/HasImplantedOhmic.hpp"
#include "falcon_core/physics/config/geometries/HasRightNeighbor.hpp"
#include "falcon_core/physics/device_structures/BarrierGate.hpp"
#include "falcon_core/physics/device_structures/Ohmic.hpp"
#include "falcon_core/physics/device_structures/ReservoirGate.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
/**
 * @brief A special reservoir geometry that has an implanted ohmic contact and
 *the rest of the channel extending to the left.
 **/
class RightReservoirWithImplantedOhmic
    : public device_structures::ReservoirGate,
      public HasImplantedOhmic,
      public HasRightNeighbor<device_structures::BarrierGate> {
 public:
  RightReservoirWithImplantedOhmic(
      std::string                      name,
      device_structures::BarrierGateSP right_neighbor,
      device_structures::OhmicSP       ohmic)
      : device_structures::ReservoirGate(name),
        HasRightNeighbor(right_neighbor),
        HasImplantedOhmic(ohmic) {}
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<ReservoirGate>(this),
       cereal::base_class<HasImplantedOhmic>(this),
       cereal::base_class<HasRightNeighbor>(this));
  }

 protected:
  RightReservoirWithImplantedOhmic() = default;
  friend class cereal::access;
};
using RightReservoirWithImplantedOhmicSP =
    std::shared_ptr<RightReservoirWithImplantedOhmic>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::config::geometries;
CEREAL_REGISTER_TYPE(RightReservoirWithImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::ReservoirGate,
    RightReservoirWithImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(HasImplantedOhmic,
                                     RightReservoirWithImplantedOhmic)
using HRNBG =
    HasRightNeighbor<falcon_core::physics::device_structures::BarrierGate>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(HRNBG, RightReservoirWithImplantedOhmic)
#endif
