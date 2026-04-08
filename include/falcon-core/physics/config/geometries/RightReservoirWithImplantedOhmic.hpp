#pragma once

#include "falcon-core/export.h"
#include "falcon-core/physics/config/geometries/HasImplantedOhmic.hpp"
#include "falcon-core/physics/config/geometries/HasLeftNeighbor.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
/**
 * @brief A special reservoir geometry that has an implanted ohmic contact and
 *the rest of the channel extending to the left.
 **/
class FALCON_CORE_CPP_API RightReservoirWithImplantedOhmic
    : public device_structures::Connection,
      public HasImplantedOhmic,
      public HasLeftNeighbor {
 public:
  RightReservoirWithImplantedOhmic(
      std::string                     name,
      device_structures::ConnectionSP right_neighbor,
      device_structures::ConnectionSP ohmic);

 protected:
  RightReservoirWithImplantedOhmic();
  friend class cereal::access;
  template <class Archive>
  inline void serialize(Archive& ar) {
    ar(cereal::base_class<Connection>(this),
       cereal::base_class<HasImplantedOhmic>(this),
       cereal::base_class<HasLeftNeighbor>(this));
  }
};
using RightReservoirWithImplantedOhmicSP =
    std::shared_ptr<RightReservoirWithImplantedOhmic>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
