#pragma once

#include "falcon_core/generic/Map.hpp"
#include "falcon_core/physics/device_structures/Gate.hpp"
#include "falcon_core/physics/device_structures/Gates.hpp"
namespace falcon_core {
namespace physics {
namespace device_structures {

/**
 * @brief Holds the relations between gates and their neighbors.
 */
class GateRelations : public generic::Map<Gate, Gates<Gate>, GateRelations> {
 public:
  GateRelations();
  GateRelations(std::initializer_list<std::pair<GateSP, GatesSP>> init);
  template <class Archive>
  void serialize(Archive& ar);

 protected:
  friend class cereal::access;
};
using GateRelationsSP = std::shared_ptr<GateRelations>;
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
