#pragma once

#include "falcon_core/physics/config/geometries/HasLeftNeighbor.hpp"
#include "falcon_core/physics/config/geometries/HasRightNeighbor.hpp"
#include "falcon_core/physics/device_structures/BarrierGate.hpp"
#include "falcon_core/physics/device_structures/PlungerGate.hpp"
namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
/*
 * @brief A special plunger gate with two neighbor barrier gates.
 */
class PlungerGateWithNeighbors
    : public device_structures::PlungerGate,
      public HasLeftNeighbor<device_structures::BarrierGate>,
      public HasRightNeighbor<device_structures::BarrierGate> {
 public:
  PlungerGateWithNeighbors(std::string                      name,
                           device_structures::BarrierGateSP right_neighbor,
                           device_structures::BarrierGateSP left_neighbor)
      : device_structures::PlungerGate(name),
        HasLeftNeighbor<device_structures::BarrierGate>(left_neighbor),
        HasRightNeighbor<device_structures::BarrierGate>(right_neighbor) {}
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<PlungerGate>(this),
       cereal::base_class<HasLeftNeighbor<device_structures::BarrierGate>>(
           this),
       cereal::base_class<HasRightNeighbor<device_structures::BarrierGate>>(
           this));
  }

 protected:
  PlungerGateWithNeighbors() = default;
  friend class cereal::access;
};
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::config::geometries;
CEREAL_REGISTER_TYPE(PlungerGateWithNeighbors)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     PlungerGateWithNeighbors)
#endif
