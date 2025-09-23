#include "falcon_core/physics/device_structures/Connections.hpp"

namespace falcon_core::physics::device_structures {

Connections::Connections() = default;
Connections::Connections(size_t count) : generic::List<Connection>(count) {}
Connections::Connections(size_t count, const ConnectionSP& value)
    : generic::List<Connection>(count, value) {}
Connections::Connections(const std::vector<ConnectionSP>& vec)
    : generic::List<Connection>(vec) {}
Connections::Connections(const generic::ListSP<Connection>& vec)
    : generic::List<Connection>(vec->items()) {}
bool Connections::is_gates() const {
  return std::all_of(this->begin(), this->end(), [](const ConnectionSP& conn) {
    return conn->is_gate();
  });
}
bool Connections::is_ohmics() const {
  return std::all_of(this->begin(), this->end(), [](const ConnectionSP& conn) {
    return conn->is_ohmic();
  });
}
bool Connections::is_dot_gates() const {
  return std::all_of(this->begin(), this->end(), [](const ConnectionSP& conn) {
    return conn->is_dot_gate();
  });
}
bool Connections::is_plunger_gates() const {
  return std::all_of(this->begin(), this->end(), [](const ConnectionSP& conn) {
    return conn->is_plunger_gate();
  });
}
bool Connections::is_barrier_gates() const {
  return std::all_of(this->begin(), this->end(), [](const ConnectionSP& conn) {
    return conn->is_barrier_gate();
  });
}
bool Connections::is_reservoir_gates() const {
  return std::all_of(this->begin(), this->end(), [](const ConnectionSP& conn) {
    return conn->is_reservoir_gate();
  });
}
bool Connections::is_screening_gates() const {
  return std::all_of(this->begin(), this->end(), [](const ConnectionSP& conn) {
    return conn->is_screening_gate();
  });
}

}  // namespace falcon_core::physics::device_structures
CEREAL_REGISTER_TYPE(falcon_core::physics::device_structures::Connections)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::List<
        falcon_core::physics::device_structures::Connection>,
    falcon_core::physics::device_structures::Connections)
