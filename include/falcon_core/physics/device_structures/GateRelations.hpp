#pragma once

#include <initializer_list>
#include <memory>

#include "falcon_core/generic/Map.hpp"
#include "falcon_core/physics/device_structures/Gate.hpp"
#include "falcon_core/physics/device_structures/Gates.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief Holds the relations between gates and their neighbors.
 */
class GateRelations : public generic::Map<Gate, Gates<Gate>> {
 public:
  GateRelations() = default;
  GateRelations(std::initializer_list<std::pair<GateSP, GatesSP<Gate>>> init)
      : generic::Map<Gate, Gates<Gate>>(init) {};
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Map<Gate, Gates<Gate>>>(this));
  }

 protected:
  friend class cereal::access;
};
using GateRelationsSP = std::shared_ptr<GateRelations>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
#ifndef SWIG
using namespace falcon_core::physics::device_structures;
using MapGR = falcon_core::generic::Map<Gate, Gates<Gate>>;
CEREAL_REGISTER_TYPE(MapGR)
CEREAL_REGISTER_TYPE(GateRelations)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, MapGR)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, GateRelations)
#endif
