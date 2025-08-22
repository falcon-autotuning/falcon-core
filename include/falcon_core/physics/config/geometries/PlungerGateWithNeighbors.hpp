#pragma once

#include "falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp"
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
    : public DotGateWithNeighbors<BarrierGate, PlungerGate, BarrierGate> {
 public:
  using DotGateWithNeighbors<BarrierGate, PlungerGate, BarrierGate>::
      DotGateWithNeighbors;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<PlungerGate>(this),
       cereal::base_class<HasLeftNeighbor<BarrierGate>>(this),
       cereal::base_class<HasRightNeighbor<BarrierGate>>(this));
  }

 protected:
  PlungerGateWithNeighbors() = default;
  friend class cereal::access;
};
using PlungerGateWithNeighborsSP = std::shared_ptr<PlungerGateWithNeighbors>;
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
