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
 *the rest of the channel extending to the right.
 **/
class LeftReservoirWithImplantedOhmic
    : public device_structures::ReservoirGate,
      public HasImplantedOhmic,
      public HasRightNeighbor<device_structures::BarrierGate> {
 public:
  LeftReservoirWithImplantedOhmic(
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
  LeftReservoirWithImplantedOhmic() = default;
  friend class cereal::access;
};
using LeftReservoirWithImplantedOhmicSP =
    std::shared_ptr<LeftReservoirWithImplantedOhmic>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::config::geometries;
CEREAL_REGISTER_TYPE(LeftReservoirWithImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::ReservoirGate,
    LeftReservoirWithImplantedOhmic)
CEREAL_REGISTER_POLYMORPHIC_RELATION(HasImplantedOhmic,
                                     LeftReservoirWithImplantedOhmic)
using HRNBG =
    HasRightNeighbor<falcon_core::physics::device_structures::BarrierGate>;
CEREAL_REGISTER_POLYMORPHIC_RELATION(HRNBG, LeftReservoirWithImplantedOhmic)
#endif
