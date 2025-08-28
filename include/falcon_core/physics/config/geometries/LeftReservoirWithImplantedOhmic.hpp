#pragma once

#include "falcon_core/physics/config/geometries/HasImplantedOhmic.hpp"
#include "falcon_core/physics/config/geometries/HasRightNeighbor.hpp"
#include "falcon_core/physics/device_structures/BarrierGate.hpp"
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
      OhmicSP                          ohmic);
  template <class Archive>
  void serialize(Archive& ar);

 protected:
  LeftReservoirWithImplantedOhmic();
  friend class cereal::access;
};
using LeftReservoirWithImplantedOhmicSP =
    std::shared_ptr<LeftReservoirWithImplantedOhmic>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
