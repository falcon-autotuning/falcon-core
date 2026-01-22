#pragma once

#include "falcon_core/export.h"
#include "falcon_core/physics/config/geometries/HasImplantedOhmic.hpp"
#include "falcon_core/physics/config/geometries/HasRightNeighbor.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
/**
 * @brief A special reservoir geometry that has an implanted ohmic contact and
 *the rest of the channel extending to the right.
 **/
class FALCON_CORE_CPP_API LeftReservoirWithImplantedOhmic
    : public device_structures::Connection,
      public HasImplantedOhmic,
      public HasRightNeighbor {
 public:
  LeftReservoirWithImplantedOhmic(
      std::string                     name,
      device_structures::ConnectionSP right_neighbor,
      device_structures::ConnectionSP ohmic);

 protected:
  LeftReservoirWithImplantedOhmic();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<Connection>(this),
       cereal::base_class<HasImplantedOhmic>(this),
       cereal::base_class<HasRightNeighbor>(this));
  }
};
using LeftReservoirWithImplantedOhmicSP =
    std::shared_ptr<LeftReservoirWithImplantedOhmic>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
