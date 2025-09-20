#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"

#include <stdexcept>

namespace falcon_core::physics::config::core {
StandardConfigConnections::StandardConfigConnections() = default;
StandardConfigConnections::StandardConfigConnections(
    const device_structures::ConnectionsSP& screening_gates,
    const device_structures::ConnectionsSP& reservoir_gates,
    const device_structures::ConnectionsSP& plunger_gates,
    const device_structures::ConnectionsSP& barrier_gates,
    const device_structures::ConnectionsSP& ohmics)
    : _screening_gates(screening_gates),
      _reservoir_gates(reservoir_gates),
      _plunger_gates(plunger_gates),
      _barrier_gates(barrier_gates),
      _ohmics(ohmics) {
  if (!_screening_gates->is_screening_gates()) {
    throw std::runtime_error(
        "Expected all the gates in the screening_gates to be screening gates.");
  }
  if (!_reservoir_gates->is_reservoir_gates()) {
    throw std::runtime_error(
        "Expected all the gates in the reservoir_gates to be reservoir gates.");
  }
  if (!_plunger_gates->is_plunger_gates()) {
    throw std::runtime_error(
        "Expected all the gates in the plunger_gates to be plunger gates.");
  }
  if (!_barrier_gates->is_barrier_gates()) {
    throw std::runtime_error(
        "Expected all the gates in the barrier_gates to be barrier gates.");
  }
  if (!_ohmics->is_ohmics()) {
    throw std::runtime_error(
        "Expected all the connections in the ohmics to be ohmic.");
  }
}
device_structures::ConnectionsSP StandardConfigConnections::screening_gates()
    const {
  return _screening_gates;
}
device_structures::ConnectionsSP StandardConfigConnections::reservoir_gates()
    const {
  return _reservoir_gates;
}
device_structures::ConnectionsSP StandardConfigConnections::plunger_gates()
    const {
  return _plunger_gates;
}
device_structures::ConnectionsSP StandardConfigConnections::barrier_gates()
    const {
  return _barrier_gates;
}
device_structures::ConnectionsSP StandardConfigConnections::ohmics() const {
  return _ohmics;
}
device_structures::ConnectionsSP StandardConfigConnections::dot_gates() const {
  device_structures::ConnectionsSP combination;
  combination->insert(
      combination->end(), _barrier_gates->begin(), _barrier_gates->end());
  combination->insert(
      combination->end(), _plunger_gates->begin(), _plunger_gates->end());
  return combination;
}
device_structures::ConnectionSP StandardConfigConnections::get_ohmic() const {
  return _ohmics->at(0);
}
device_structures::ConnectionSP StandardConfigConnections::get_barrier_gate()
    const {
  return _barrier_gates->at(0);
}
device_structures::ConnectionSP StandardConfigConnections::get_plunger_gate()
    const {
  return _plunger_gates->at(0);
}
device_structures::ConnectionSP StandardConfigConnections::get_reservoir_gate()
    const {
  return _reservoir_gates->at(0);
}
device_structures::ConnectionSP StandardConfigConnections::get_screening_gate()
    const {
  return _screening_gates->at(0);
}
device_structures::ConnectionSP StandardConfigConnections::get_dot_gate()
    const {
  if (_plunger_gates->size() > 0) {
    return _plunger_gates->at(0);
  } else if (_barrier_gates->size() > 0) {
    return _barrier_gates->at(0);
  } else {
    return nullptr;
  }
}
device_structures::ConnectionSP StandardConfigConnections::get_gate() const {
  if (_plunger_gates->size() > 0) {
    return _plunger_gates->at(0);
  } else if (_barrier_gates->size() > 0) {
    return _barrier_gates->at(0);
  } else if (_reservoir_gates->size() > 0) {
    return _reservoir_gates->at(0);
  } else if (_screening_gates->size() > 0) {
    return _screening_gates->at(0);
  } else {
    return nullptr;
  }
}
device_structures::ConnectionsSP StandardConfigConnections::get_all_gates()
    const {
  device_structures::ConnectionsSP combination;
  combination->insert(
      combination->end(), _barrier_gates->begin(), _barrier_gates->end());
  combination->insert(
      combination->end(), _plunger_gates->begin(), _plunger_gates->end());
  combination->insert(
      combination->end(), _reservoir_gates->begin(), _reservoir_gates->end());
  combination->insert(
      combination->end(), _screening_gates->begin(), _screening_gates->end());
  return combination;
}
device_structures::ConnectionsSP StandardConfigConnections::get_all_ohmics()
    const {
  return _ohmics;
}
device_structures::ConnectionsSP
StandardConfigConnections::get_all_connections() const {
  device_structures::ConnectionsSP combination;
  device_structures::ConnectionsSP all_gates  = get_all_gates();
  device_structures::ConnectionsSP all_ohmics = ohmics();
  combination->insert(combination->end(), all_gates->begin(), all_gates->end());
  combination->insert(
      combination->end(), all_ohmics->begin(), all_ohmics->end());
  return combination;
}
bool StandardConfigConnections::has_ohmic(
    const device_structures::ConnectionSP& ohmic) const {
  for (auto& o : *_ohmics) {
    if (*o == *ohmic) {
      return true;
    }
  }
  return false;
}
bool StandardConfigConnections::has_gate(
    const device_structures::ConnectionSP& gate) const {
  for (auto& g : *get_all_gates()) {
    if (*g == *gate) {
      return true;
    }
  }
  return false;
}
bool StandardConfigConnections::has_barrier_gate(
    const device_structures::ConnectionSP& gate) const {
  for (device_structures::ConnectionSP& g : *barrier_gates()) {
    if (*g == *gate) {
      return true;
    }
  }
  return false;
}
bool StandardConfigConnections::has_plunger_gate(
    const device_structures::ConnectionSP& gate) const {
  for (device_structures::ConnectionSP& g : *plunger_gates()) {
    if (*g == *gate) {
      return true;
    }
  }
  return false;
}
bool StandardConfigConnections::has_reservoir_gate(
    const device_structures::ConnectionSP& gate) const {
  for (device_structures::ConnectionSP& g : *reservoir_gates()) {
    if (*g == *gate) {
      return true;
    }
  }
  return false;
}
bool StandardConfigConnections::has_screening_gate(
    const device_structures::ConnectionSP& gate) const {
  for (device_structures::ConnectionSP& g : *screening_gates()) {
    if (*g == *gate) {
      return true;
    }
  }
  return false;
}
}  // namespace falcon_core::physics::config::core
CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::core::StandardConfigConnections)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::core::StandardConfigConnections)
