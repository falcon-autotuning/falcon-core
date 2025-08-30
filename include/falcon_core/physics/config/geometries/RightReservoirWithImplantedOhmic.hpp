#pragma once

#include "falcon_core/physics/config/geometries/HasImplantedOhmic.hpp"
#include "falcon_core/physics/config/geometries/HasLeftNeighbor.hpp"
#include "falcon_core/physics/device_structures/BarrierGate.hpp"
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
      public HasLeftNeighbor {
 public:
  RightReservoirWithImplantedOhmic(
      std::string                      name,
      device_structures::BarrierGateSP right_neighbor,
      device_structures::OhmicSP       ohmic);
  template <class Archive>
  void serialize(Archive& ar);

 protected:
  RightReservoirWithImplantedOhmic();
  friend class cereal::access;
};
using RightReservoirWithImplantedOhmicSP =
    std::shared_ptr<RightReservoirWithImplantedOhmic>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
