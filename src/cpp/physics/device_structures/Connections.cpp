#include "falcon-core/physics/device_structures/Connections.hpp"

namespace falcon_core {
namespace physics {
namespace device_structures {

Connections::Connections() : generic::List<Connection>() {}
Connections::Connections(size_t count, const ConnectionSP& value)
    : generic::List<Connection>(count, value) {}
Connections::Connections(const std::vector<ConnectionSP>& vec)
    : generic::List<Connection>(vec) {}
Connections::Connections(const generic::ListSP<Connection>& vec)
    : generic::List<Connection>(vec->items()) {}
bool Connections::is_gates() const {
  for (const ConnectionSP& conn : items()) {
    if (!conn->is_gate()) {
      return false;
    }
  }
  return true;
}
bool Connections::is_ohmics() const {
  for (const ConnectionSP& conn : items()) {
    if (!conn->is_ohmic()) {
      return false;
    }
  }
  return true;
}
bool Connections::is_dot_gates() const {
  for (const ConnectionSP& conn : items()) {
    if (!conn->is_dot_gate()) {
      return false;
    }
  }
  return true;
}
bool Connections::is_plunger_gates() const {
  for (const ConnectionSP& conn : items()) {
    if (!conn->is_plunger_gate()) {
      return false;
    }
  }
  return true;
}
bool Connections::is_barrier_gates() const {
  for (const ConnectionSP& conn : items()) {
    if (!conn->is_barrier_gate()) {
      return false;
    }
  }
  return true;
}
bool Connections::is_reservoir_gates() const {
  for (const ConnectionSP& conn : items()) {
    if (!conn->is_reservoir_gate()) {
      return false;
    }
  }
  return true;
}
bool Connections::is_screening_gates() const {
  for (const ConnectionSP& conn : items()) {
    if (!conn->is_screening_gate()) {
      return false;
    }
  }
  return true;
}
ConnectionsSP Connections::intersection(
    const std::shared_ptr<Connections>& other) const {
  if (!other) {
    throw std::invalid_argument(
        "Connections: Cannot intersect with a null connections.");
  }
  generic::ListSP<Connection> other_list =
      std::dynamic_pointer_cast<generic::List<Connection>>(other);
  return std::make_shared<Connections>(
      generic::List<Connection>::intersection(other_list));
}
bool Connections::operator==(const Connections& other) const {
  if (this == &other) return true;
  return static_cast<const List<Connection>&>(*this) ==
         static_cast<const List<Connection>&>(other);
}
bool Connections::operator!=(const Connections& other) const {
  return !(*this == other);
}

}  // namespace device_structures
}  // namespace physics
}  // namespace falcon_core
