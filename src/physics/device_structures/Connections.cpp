#include "falcon_core/physics/device_structures/Connections.hpp"

namespace falcon_core::physics::device_structures {

Connections::Connections() : List<Connection>() {}
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

}  // namespace falcon_core::physics::device_structures
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::Connections)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<
        falcon_core::physics::device_structures::Connection>,
    falcon_core::physics::device_structures::Connections)
