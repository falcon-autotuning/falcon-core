#pragma once

#include "falcon_core/physics/config/geometries/HasImplantedOhmic.hpp"
#include "falcon_core/physics/config/geometries/HasRightNeighbor.hpp"
#include "falcon_core/physics/device_structures/BarrierGate.hpp"
#include "falcon_core/physics/device_structures/ReservoirGate.hpp"

namespace falcon_core::physics::config::geometries {
/**
 * @brief A special reservoir geometry that has an implanted ohmic contact and
 *the rest of the channel extending to the right.
 **/
class LeftReservoirWithImplantedOhmic : public device_structures::ReservoirGate,
                                        public HasImplantedOhmic,
                                        public HasRightNeighbor {
 public:
  LeftReservoirWithImplantedOhmic(
      std::string                      name,
      device_structures::BarrierGateSP right_neighbor,
      device_structures::OhmicSP       ohmic);

 protected:
  LeftReservoirWithImplantedOhmic();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<ReservoirGate>(this),
       cereal::base_class<HasImplantedOhmic>(this),
       cereal::base_class<HasRightNeighbor>(this));
  }
};
using LeftReservoirWithImplantedOhmicSP =
    std::shared_ptr<LeftReservoirWithImplantedOhmic>;
}  // namespace falcon_core::physics::config::geometries
