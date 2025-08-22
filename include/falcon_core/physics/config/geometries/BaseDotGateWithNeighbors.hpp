#pragma once

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
    ar(cereal::base_class<device_structures::DotGate>(this));
  }
};
using BaseDotGateWithNeighborsSP = std::shared_ptr<BaseDotGateWithNeighbors>;

}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core;
using namespace falcon_core::physics::config::geometries;
using namespace falcon_core::physics::device_structures;
CEREAL_REGISTER_TYPE(BaseDotGateWithNeighbors)
CEREAL_REGISTER_POLYMORPHIC_RELATION(Gate, BaseDotGateWithNeighbors)
#endif
