#pragma once

#include "falcon_core/physics/config/geometries/HasLeftNeighbor.hpp"
#include "falcon_core/physics/config/geometries/HasRightNeighbor.hpp"
#include "falcon_core/physics/device_structures/Gate.hpp"
namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
/*
 * @brief A base class for gates with a left and right neighbor.
 */
template <typename LeftNeighbor, typename BaseGate, typename RightNeighbor>
class GateWithNeighbors : public BaseGate,
                          public HasLeftNeighbor<LeftNeighbor>,
                          public HasRightNeighbor<RightNeighbor> {
  static_assert(std::is_base_of<device_structures::Gate, RightNeighbor>::value,
                "RightNeighbor must be device_structures::Gate.");
  static_assert(std::is_base_of<device_structures::Gate, LeftNeighbor>::value,
                "RightNeighbor must be device_structures::Gate.");

 public:
  GateWithNeighbors(std::string                    name,
                    std::shared_ptr<LeftNeighbor>  left_neighbor,
                    std::shared_ptr<RightNeighbor> right_neighbor)
      : BaseGate(name),
        HasLeftNeighbor<LeftNeighbor>(left_neighbor),
        HasRightNeighbor<RightNeighbor>(right_neighbor) {}
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseGate>(this),
       cereal::base_class<HasLeftNeighbor<LeftNeighbor>>(this),
       cereal::base_class<HasRightNeighbor<RightNeighbor>>(this));
  }

 protected:
  GateWithNeighbors() = default;
  friend class cereal::access;
};
template <typename LeftNeighbor, typename BaseGate, typename RightNeighbor>
using GateWithNeighborsSP =
    std::shared_ptr<GateWithNeighbors<LeftNeighbor, BaseGate, RightNeighbor>>;
}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core;
using namespace falcon_core::physics::config::geometries;
using namespace falcon_core::physics::device_structures;
using GWN = GateWithNeighbors<Gate, Gate, Gate>;
CEREAL_REGISTER_TYPE(GWN)
CEREAL_REGISTER_POLYMORPHIC_RELATION(generic::Song, GWN)
#endif
