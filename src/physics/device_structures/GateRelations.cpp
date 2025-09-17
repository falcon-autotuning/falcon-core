#include "falcon_core/physics/device_structures/GateRelations.hpp"

#include "falcon_core/physics/device_structures/BaseConnection.hpp"
#include "falcon_core/physics/device_structures/BaseConnections.hpp"
namespace falcon_core::physics::device_structures {
GateRelations::GateRelations() = default;
GateRelations::GateRelations(
    std::vector<std::pair<BaseConnectionSP, BaseConnectionsSP>> init)
    : generic::Map<BaseConnection, BaseConnections, GateRelations>(init) {}

void GateRelations::insert_or_assign(const BaseConnectionSP&  key,
                                     const BaseConnectionsSP& value) {
  // Override to ensure proper types
  if (!key->is_gate()) {
    throw std::runtime_error(
        "Only a gate is allowed as keys of the GateRelations");
  }
  if (!value->is_gates()) {
    throw std::runtime_error(
        "Only gates are allowed as values of the GateRelations");
  }
  Map::insert_or_assign(key, value);
}
std::pair<std::vector<std::pair<BaseConnectionSP, BaseConnectionsSP>>::iterator,
          bool>
GateRelations::insert(const BaseConnectionSP&  key,
                      const BaseConnectionsSP& value) {
  // Override to ensure proper types
  if (!key->is_gate()) {
    throw std::runtime_error(
        "Only a gate is allowed as keys of the GateRelations");
  }
  if (!value->is_gates()) {
    throw std::runtime_error(
        "Only gates are allowed as values of the GateRelations");
  }
  return Map::insert(key, value);
}
}  // namespace falcon_core::physics::device_structures
using MapGR = falcon_core::generic::Map<
    falcon_core::physics::device_structures::BaseConnection,
    falcon_core::physics::device_structures::BaseConnections>;
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::GateRelations)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    MapGR, falcon_core::physics::device_structures::GateRelations)
