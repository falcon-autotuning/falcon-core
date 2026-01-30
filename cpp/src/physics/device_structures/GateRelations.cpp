#include "falcon_core/physics/device_structures/GateRelations.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {
GateRelations::GateRelations() = default;
GateRelations::GateRelations(
    std::vector<std::pair<ConnectionSP, ConnectionsSP>> init)
    : generic::Map<Connection, Connections>(init) {}

void GateRelations::insert_or_assign(const ConnectionSP&  key,
                                     const ConnectionsSP& value) {
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
std::pair<generic::List<generic::Pair<Connection, Connections>>::iterator, bool>
GateRelations::insert(const ConnectionSP& key, const ConnectionsSP& value) {
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
bool GateRelations::operator==(const GateRelations& other) const {
  if (this == &other) return true;
  return static_cast<const Map<Connection, Connections>&>(*this) ==
         static_cast<const Map<Connection, Connections>&>(other);
}
bool GateRelations::operator!=(const GateRelations& other) const {
  return !(*this == other);
}
}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
