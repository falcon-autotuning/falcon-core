#pragma once

#include "falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp"
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
template <typename LeftNeighbor, typename RightNeighbor>
class BarrierGateWithNeighbors
    : public DotGateWithNeighbors<LeftNeighbor, BarrierGate, RightNeighbor> {
  static_assert(std::is_same<RightNeighbor, ReservoirGate>::value ||
                    std::is_same<RightNeighbor, PlungerGate>::value,
                "RightNeighbor must be device_structures::ReservoirGate or "
                "device_structures::PlungerGate.");
  static_assert(std::is_same<LeftNeighbor, ReservoirGate>::value ||
                    std::is_same<LeftNeighbor, PlungerGate>::value,
                "RightNeighbor must be device_structures::ReservoirGate or "
                "device_structures::PlungerGate.");

 public:
  using DotGateWithNeighbors<LeftNeighbor, BarrierGate, RightNeighbor>::
      DotGateWithNeighbors;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BarrierGate>(this),
       cereal::base_class<HasLeftNeighbor<LeftNeighbor>>(this),
       cereal::base_class<HasRightNeighbor<RightNeighbor>>(this));
  }

 protected:
  BarrierGateWithNeighbors() = default;
  friend class cereal::access;
};
template <typename LeftNeighbor, typename RightNeighbor>
using BarrierGateWithNeighborsSP =
    std::shared_ptr<BarrierGateWithNeighbors<LeftNeighbor, RightNeighbor>>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::config::geometries;
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::generic;
using BarrierGateWithLeftResNeighborRightResNeighbor =
    BarrierGateWithNeighbors<ReservoirGate, ReservoirGate>;
using BarrierGateWithLeftPluNeighborRightResNeighbor =
    BarrierGateWithNeighbors<PlungerGate, ReservoirGate>;
using BarrierGateWithLeftPluNeighborRightPluNeighbor =
    BarrierGateWithNeighbors<PlungerGate, PlungerGate>;
using BarrierGateWithLeftResNeighborRightPlueNeighbor =
    BarrierGateWithNeighbors<ReservoirGate, PlungerGate>;
CEREAL_REGISTER_TYPE(BarrierGateWithLeftResNeighborRightResNeighbor)
CEREAL_REGISTER_TYPE(BarrierGateWithLeftPluNeighborRightResNeighbor)
CEREAL_REGISTER_TYPE(BarrierGateWithLeftPluNeighborRightPluNeighbor)
CEREAL_REGISTER_TYPE(BarrierGateWithLeftResNeighborRightPlueNeighbor)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    Song, BarrierGateWithLeftResNeighborRightResNeighbor)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    Song, BarrierGateWithLeftPluNeighborRightResNeighbor)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    Song, BarrierGateWithLeftPluNeighborRightPluNeighbor)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    Song, BarrierGateWithLeftResNeighborRightPlueNeighbor)
#endif
