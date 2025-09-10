#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"

#include <memory>

#include "falcon_core/physics/device_structures/BarrierGate.hpp"
#include "falcon_core/physics/device_structures/BaseConnections.hpp"
#include "falcon_core/physics/device_structures/Ohmic.hpp"

namespace falcon_core::physics::config::core {
StandardConfigConnections::StandardConfigConnections() = default;
StandardConfigConnections::StandardConfigConnections(
    const device_structures::ScreeningGatesSP& screening_gates,
    const device_structures::ReservoirGatesSP& reservoir_gates,
    const device_structures::PlungerGatesSP&   plunger_gates,
    const device_structures::BarrierGatesSP&   barrier_gates,
    const device_structures::OhmicsSP&         ohmics)
    : _screening_gates(screening_gates),
      _reservoir_gates(reservoir_gates),
      _plunger_gates(plunger_gates),
      _barrier_gates(barrier_gates),
      _ohmics(ohmics) {}
device_structures::ScreeningGatesSP StandardConfigConnections::screening_gates()
    const {
  return _screening_gates;
}
device_structures::ReservoirGatesSP StandardConfigConnections::reservoir_gates()
    const {
  return _reservoir_gates;
}
device_structures::PlungerGatesSP StandardConfigConnections::plunger_gates()
    const {
  return _plunger_gates;
}
device_structures::BarrierGatesSP StandardConfigConnections::barrier_gates()
    const {
  return _barrier_gates;
}
device_structures::OhmicsSP StandardConfigConnections::ohmics() const {
  return _ohmics;
}
device_structures::BaseConnectionsSP StandardConfigConnections::dot_gates()
    const {
  device_structures::BaseConnectionsSP combination;
  combination->insert(
      combination->end(), _barrier_gates->begin(), _barrier_gates->end());
  combination->insert(
      combination->end(), _plunger_gates->begin(), _plunger_gates->end());
  return combination;
}
device_structures::OhmicSP StandardConfigConnections::get_ohmic() const {
  return std::dynamic_pointer_cast<device_structures::Ohmic>(_ohmics->at(0));
}
device_structures::BarrierGateSP StandardConfigConnections::get_barrier_gate()
    const {
  return std::dynamic_pointer_cast<device_structures::BarrierGate>(
      _barrier_gates->at(0));
}
device_structures::PlungerGateSP StandardConfigConnections::get_plunger_gate()
    const {
  return std::dynamic_pointer_cast<device_structures::PlungerGate>(
      _plunger_gates->at(0));
}
device_structures::ReservoirGateSP
StandardConfigConnections::get_reservoir_gate() const {
  return std::dynamic_pointer_cast<device_structures::ReservoirGate>(
      _reservoir_gates->at(0));
}
device_structures::ScreeningGateSP
StandardConfigConnections::get_screening_gate() const {
  return std::dynamic_pointer_cast<device_structures::ScreeningGate>(
      _screening_gates->at(0));
}
device_structures::BaseConnectionSP StandardConfigConnections::get_dot_gate()
    const {
  if (_plunger_gates->size() > 0) {
    return _plunger_gates->at(0);
  } else if (_barrier_gates->size() > 0) {
    return _barrier_gates->at(0);
  } else {
    return nullptr;
  }
}
device_structures::BaseConnectionSP StandardConfigConnections::get_gate()
    const {
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
device_structures::BaseConnectionsSP StandardConfigConnections::get_all_gates()
    const {
  device_structures::BaseConnectionsSP combination;
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
device_structures::OhmicsSP StandardConfigConnections::get_all_ohmics() const {
  return _ohmics;
}
device_structures::BaseConnectionsSP
StandardConfigConnections::get_all_connections() const {
  device_structures::BaseConnectionsSP combination;
  device_structures::BaseConnectionsSP all_gates  = get_all_gates();
  device_structures::OhmicsSP          all_ohmics = ohmics();
  combination->insert(combination->end(), all_gates->begin(), all_gates->end());
  combination->insert(
      combination->end(), all_ohmics->begin(), all_ohmics->end());
  return combination;
}
bool StandardConfigConnections::has_ohmic(
    const device_structures::OhmicSP& ohmic) const {
  for (auto& o : *_ohmics) {
    if (*o == *ohmic) {
      return true;
    }
  }
  return false;
}
bool StandardConfigConnections::has_gate(
    const device_structures::BaseConnectionSP& gate) const {
  for (auto& g : *get_all_gates()) {
    if (*g == *gate) {
      return true;
    }
  }
  return false;
}
bool StandardConfigConnections::has_barrier_gate(
    const device_structures::BarrierGateSP& gate) const {
  for (device_structures::BaseConnectionSP& g : *barrier_gates()) {
    if (*g == *gate) {
      return true;
    }
  }
  return false;
}
bool StandardConfigConnections::has_plunger_gate(
    const device_structures::PlungerGateSP& gate) const {
  for (device_structures::BaseConnectionSP& g : *plunger_gates()) {
    if (*g == *gate) {
      return true;
    }
  }
  return false;
}
bool StandardConfigConnections::has_reservoir_gate(
    const device_structures::ReservoirGateSP& gate) const {
  for (device_structures::BaseConnectionSP& g : *reservoir_gates()) {
    if (*g == *gate) {
      return true;
    }
  }
  return false;
}
bool StandardConfigConnections::has_screening_gate(
    const device_structures::ScreeningGateSP& gate) const {
  for (device_structures::BaseConnectionSP& g : *screening_gates()) {
    if (*g == *gate) {
      return true;
    }
  }
  return false;
}
template <class Archive>
void StandardConfigConnections::serialize(Archive& ar) {
  ar(cereal::base_class<generic::Song>(this),
     _screening_gates,
     _reservoir_gates,
     _plunger_gates,
     _barrier_gates,
     _ohmics);
}
}  // namespace falcon_core::physics::config::core
CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::core::StandardConfigConnections)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::core::StandardConfigConnections)
