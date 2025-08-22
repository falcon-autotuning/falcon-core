#pragma once

#include "falcon_core/physics/config/geometries/HasLeftNeighbor.hpp"
#include "falcon_core/physics/config/geometries/HasRightNeighbor.hpp"
#include "falcon_core/physics/device_structures/DotGate.hpp"
#include "falcon_core/physics/device_structures/Gate.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {

// Non-template base for polymorphism
class BaseDotGateWithNeighbors : public device_structures::DotGate {
 public:
  using Ptr = std::shared_ptr<BaseDotGateWithNeighbors>;
  BaseDotGateWithNeighbors(std::string name)
      : device_structures::DotGate(std::move(name)) {}
  virtual ~BaseDotGateWithNeighbors() = default;
  virtual std::shared_ptr<device_structures::Gate> left_neighbor() const  = 0;
  virtual std::shared_ptr<device_structures::Gate> right_neighbor() const = 0;

 protected:
  BaseDotGateWithNeighbors() = default;
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<device_structures::Gate>(this));
  }
};

// Template implementation
template <typename LeftNeighbor, typename BaseGate, typename RightNeighbor>
class GateWithNeighbors : public BaseDotGateWithNeighbors,
                          public HasLeftNeighbor<LeftNeighbor>,
                          public HasRightNeighbor<RightNeighbor> {
  static_assert(std::is_base_of<device_structures::Gate, RightNeighbor>::value,
                "RightNeighbor must be device_structures::Gate.");
  static_assert(std::is_base_of<device_structures::Gate, LeftNeighbor>::value,
                "LeftNeighbor must be device_structures::Gate.");
  static_assert(std::is_base_of<device_structures::Gate, BaseGate>::value,
                "BaseGate must be device_structures::Gate.");

 public:
  GateWithNeighbors(std::string                    name,
                    std::shared_ptr<LeftNeighbor>  left_neighbor,
                    std::shared_ptr<RightNeighbor> right_neighbor)
      : BaseDotGateWithNeighbors(name),
        BaseGate(name),
        HasLeftNeighbor<LeftNeighbor>(left_neighbor),
        HasRightNeighbor<RightNeighbor>(right_neighbor) {}

  std::shared_ptr<device_structures::Gate> left_neighbor() const override {
    return HasLeftNeighbor<LeftNeighbor>::left_neighbor();
  }
  std::shared_ptr<device_structures::Gate> right_neighbor() const override {
    return HasRightNeighbor<RightNeighbor>::right_neighbor();
  }
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseDotGateWithNeighbors>(this),
       cereal::base_class<BaseGate>(this),
       cereal::base_class<HasLeftNeighbor<LeftNeighbor>>(this),
       cereal::base_class<HasRightNeighbor<RightNeighbor>>(this));
  }

 protected:
  GateWithNeighbors() = default;
  friend class cereal::access;
};

template <typename L, typename B, typename R>
using GateWithNeighborsSP        = std::shared_ptr<GateWithNeighbors<L, B, R>>;
using BaseDotGateWithNeighborsSP = std::shared_ptr<BaseDotGateWithNeighbors>;

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
CEREAL_REGISTER_TYPE(BaseDotGateWithNeighbors)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Gate, BaseDotGateWithNeighbors)
CEREAL_REGISTER_POLYMORPHIC_RELATION(BaseDotGateWithNeighbors, GWN)
CEREAL_REGISTER_POLYMORPHIC_RELATION(HasLeftNeighbor<Gate>, GWN)
CEREAL_REGISTER_POLYMORPHIC_RELATION(HasRightNeighbor<Gate>, GWN)
#endif
