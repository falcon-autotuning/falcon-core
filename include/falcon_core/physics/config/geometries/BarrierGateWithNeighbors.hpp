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
template <typename LeftNeighbor, typename RightNeighbor>
class BarrierGateWithNeighbors : public device_structures::BarrierGate,
                                 public HasLeftNeighbor<LeftNeighbor>,
                                 public HasRightNeighbor<RightNeighbor> {
  static_assert(
      std::is_same<RightNeighbor, device_structures::ReservoirGate>::value ||
          std::is_same<RightNeighbor, device_structures::PlungerGate>::value,
      "RightNeighbor must be device_structures::ReservoirGate or "
      "device_structures::PlungerGate.");
  static_assert(
      std::is_same<LeftNeighbor, device_structures::ReservoirGate>::value ||
          std::is_same<LeftNeighbor, device_structures::PlungerGate>::value,
      "RightNeighbor must be device_structures::ReservoirGate or "
      "device_structures::PlungerGate.");

 public:
  BarrierGateWithNeighbors(std::string                    name,
                           std::shared_ptr<RightNeighbor> right_neighbor,
                           std::shared_ptr<LeftNeighbor>  left_neighbor)
      : device_structures::BarrierGate(name),
        HasLeftNeighbor<LeftNeighbor>(left_neighbor),
        HasRightNeighbor<RightNeighbor>(right_neighbor) {}
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
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::config::geometries;
using BarrierGateWithLeftResNeighborRightResNeighbor = BarrierGateWithNeighbors<
    falcon_core::physics::device_structures::ReservoirGate,
    falcon_core::physics::device_structures::ReservoirGate>;
using BarrierGateWithLeftPluNeighborRightResNeighbor = BarrierGateWithNeighbors<
    falcon_core::physics::device_structures::PlungerGate,
    falcon_core::physics::device_structures::ReservoirGate>;
using BarrierGateWithLeftPluNeighborRightPluNeighbor = BarrierGateWithNeighbors<
    falcon_core::physics::device_structures::PlungerGate,
    falcon_core::physics::device_structures::PlungerGate>;
using BarrierGateWithLeftResNeighborRightPlueNeighbor =
    BarrierGateWithNeighbors<
        falcon_core::physics::device_structures::ReservoirGate,
        falcon_core::physics::device_structures::PlungerGate>;
CEREAL_REGISTER_TYPE(BarrierGateWithLeftResNeighborRightResNeighbor)
CEREAL_REGISTER_TYPE(BarrierGateWithLeftPluNeighborRightResNeighbor)
CEREAL_REGISTER_TYPE(BarrierGateWithLeftPluNeighborRightPluNeighbor)
CEREAL_REGISTER_TYPE(BarrierGateWithLeftResNeighborRightPlueNeighbor)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, BarrierGateWithLeftResNeighborRightResNeighbor)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, BarrierGateWithLeftPluNeighborRightResNeighbor)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, BarrierGateWithLeftPluNeighborRightPluNeighbor)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song, BarrierGateWithLeftResNeighborRightPlueNeighbor)
#endif
