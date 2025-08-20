#pragma once

#include "falcon_core/physics/config/geometries/HasLeftNeighbor.hpp"
#include "falcon_core/physics/config/geometries/HasRightNeighbor.hpp"
#include "falcon_core/physics/device_structures/BarrierGate.hpp"
#include "falcon_core/physics/device_structures/PlungerGate.hpp"
#include "falcon_core/physics/device_structures/ReservoirGate.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
/*
 * @brief A special barrier with two neighbor gates.
 */
class BarrierGateWithNeighbors : public device_structures::BarrierGate,
                                 public HasLeftNeighbor,
                                 public HasRightNeighbor {
 public:
  template <typename RightNeighbor, typename LeftNeighbor>
  BarrierGateWithNeighbors(
      std::string   name,
      RightNeighbor right_neighbor,
      LeftNeighbor  left_neighbor,
      typename std::enable_if<
          (std::is_same<RightNeighbor,
                        device_structures::ReservoirGateSP>::value ||
           std::is_same<RightNeighbor,
                        device_structures::PlungerGateSP>::value) &&
              (std::is_same<LeftNeighbor,
                            device_structures::ReservoirGateSP>::value ||
               std::is_same<LeftNeighbor,
                            device_structures::PlungerGateSP>::value),
          int>::type = 0)
      : device_structures::BarrierGate(name),
        HasLeftNeighbor(left_neighbor),
        HasRightNeighbor(right_neighbor) {}
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BarrierGate>(this),
       cereal::base_class<HasLeftNeighbor>(this),
       cereal::base_class<HasRightNeighbor>(this));
  }

 protected:
  BarrierGateWithNeighbors() = default;
  friend class cereal::access;
};
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::config::geometries;
CEREAL_REGISTER_TYPE(BarrierGateWithNeighbors)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::physics::device_structures::BarrierGate,
    BarrierGateWithNeighbors)
CEREAL_REGISTER_POLYMORPHIC_RELATION(HasLeftNeighbor, BarrierGateWithNeighbors)
CEREAL_REGISTER_POLYMORPHIC_RELATION(HasRightNeighbor, BarrierGateWithNeighbors)
#endif
