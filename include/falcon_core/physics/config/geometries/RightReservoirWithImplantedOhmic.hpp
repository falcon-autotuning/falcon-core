#pragma once

#include "falcon_core/physics/config/geometries/HasImplantedOhmic.hpp"
#include "falcon_core/physics/config/geometries/HasLeftNeighbor.hpp"
#include "falcon_core/physics/device_structures/BarrierGate.hpp"
#include "falcon_core/physics/device_structures/ReservoirGate.hpp"

namespace falcon_core::physics::config::geometries {
/**
 * @brief A special reservoir geometry that has an implanted ohmic contact and
 *the rest of the channel extending to the left.
 **/
class RightReservoirWithImplantedOhmic
    : public device_structures::ReservoirGate,
      public config::geometries::HasImplantedOhmic,
      public config::geometries::HasLeftNeighbor {
 public:
  RightReservoirWithImplantedOhmic(
      std::string                      name,
      device_structures::BarrierGateSP right_neighbor,
      device_structures::OhmicSP       ohmic);

 protected:
  RightReservoirWithImplantedOhmic();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<ReservoirGate>(this),
       cereal::base_class<HasImplantedOhmic>(this),
       cereal::base_class<HasLeftNeighbor>(this));
  }
};
using RightReservoirWithImplantedOhmicSP =
    std::shared_ptr<RightReservoirWithImplantedOhmic>;
}  // namespace falcon_core::physics::config::geometries
