#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"

#include <memory>

#include "falcon_core/physics/device_structures/BarrierGate.hpp"

namespace falcon_core {
namespace physics {
namespace config {
namespace core {
StandardConfigConnections::StandardConfigConnections() = default;
StandardConfigConnections::StandardConfigConnections(
    const ScreeningGatesSP& screening_gates,
    const ReservoirGatesSP& reservoir_gates,
    const PlungerGatesSP&   plunger_gates,
    const BarrierGatesSP&   barrier_gates,
    const OhmicsSP&         ohmics)
    : _screening_gates(screening_gates),
      _reservoir_gates(reservoir_gates),
      _plunger_gates(plunger_gates),
      _barrier_gates(barrier_gates),
      _ohmics(ohmics) {}
ScreeningGatesSP StandardConfigConnections::screening_gates() const {
  return _screening_gates;
}
ReservoirGatesSP StandardConfigConnections::reservoir_gates() const {
  return _reservoir_gates;
}
PlungerGatesSP StandardConfigConnections::plunger_gates() const {
  return _plunger_gates;
}
BarrierGatesSP StandardConfigConnections::barrier_gates() const {
  return _barrier_gates;
}
OhmicsSP StandardConfigConnections::ohmics() const { return _ohmics; }
OhmicsSP StandardConfigConnections::get_connections(
    const OhmicSP& conn_type) const {
  return _ohmics;
}
BarrierGatesSP StandardConfigConnections::get_connections(
    const BarrierGateSP& conn_type) const {
  return _barrier_gates;
}
PlungerGatesSP StandardConfigConnections::get_connections(
    const PlungerGateSP& conn_type) const {
  return _plunger_gates;
}
ReservoirGatesSP StandardConfigConnections::get_connections(
    const ReservoirGateSP& conn_type) const {
  return _reservoir_gates;
}
ScreeningGatesSP StandardConfigConnections::get_connections(
    const ScreeningGateSP& conn_type) const {
  return _screening_gates;
}
DotGatesSP StandardConfigConnections::get_connections(
    const DotGateSP& conn_type) const {
  auto plunger = std::dynamic_pointer_cast<DotGates<DotGate>>(_plunger_gates);
  auto barrier = std::dynamic_pointer_cast<DotGates<DotGate>>(_barrier_gates);
  DotGates<DotGate> combination;
  combination.insert(combination.end(), barrier->begin(), barrier->end());
  combination.insert(combination.end(), plunger->begin(), plunger->end());
  return std::make_shared<DotGates<DotGate>>(combination);
}
GatesSP StandardConfigConnections::get_connections(
    const GateSP& conn_type) const {
  auto plunger   = std::dynamic_pointer_cast<Gates<Gate>>(_plunger_gates);
  auto barrier   = std::dynamic_pointer_cast<Gates<Gate>>(_barrier_gates);
  auto reservoir = std::dynamic_pointer_cast<Gates<Gate>>(_reservoir_gates);
  auto screening = std::dynamic_pointer_cast<Gates<Gate>>(_screening_gates);
  Gates<Gate> combination;
  combination.insert(combination.end(), barrier->begin(), barrier->end());
  combination.insert(combination.end(), plunger->begin(), plunger->end());
  combination.insert(combination.end(), reservoir->begin(), reservoir->end());
  combination.insert(combination.end(), screening->begin(), screening->end());
  return std::make_shared<Gates<Gate>>(combination);
}
OhmicSP StandardConfigConnections::get_connection(
    const OhmicSP& conn_type) const {
  return _ohmics->at(0);
}
BarrierGateSP StandardConfigConnections::get_connection(
    const BarrierGateSP& conn_type) const {
  return _barrier_gates->at(0);
}
PlungerGateSP StandardConfigConnections::get_connection(
    const PlungerGateSP& conn_type) const {
  return _plunger_gates->at(0);
}
ReservoirGateSP StandardConfigConnections::get_connection(
    const ReservoirGateSP& conn_type) const {
  return _reservoir_gates->at(0);
}
ScreeningGateSP StandardConfigConnections::get_connection(
    const ScreeningGateSP& conn_type) const {
  return _screening_gates->at(0);
}
DotGateSP StandardConfigConnections::get_connection(
    const DotGateSP& conn_type) const {
  auto plunger = std::dynamic_pointer_cast<DotGates<DotGate>>(_plunger_gates);
  auto barrier = std::dynamic_pointer_cast<DotGates<DotGate>>(_barrier_gates);
  if (plunger->size() > 0) {
    return plunger->at(0);
  } else if (barrier->size() > 0) {
    return barrier->at(0);
  } else {
    return nullptr;
  }
}
GateSP StandardConfigConnections::get_connection(
    const GateSP& conn_type) const {
  auto plunger   = std::dynamic_pointer_cast<Gates<Gate>>(_plunger_gates);
  auto barrier   = std::dynamic_pointer_cast<Gates<Gate>>(_barrier_gates);
  auto reservoir = std::dynamic_pointer_cast<Gates<Gate>>(_reservoir_gates);
  auto screening = std::dynamic_pointer_cast<Gates<Gate>>(_screening_gates);
  if (plunger->size() > 0) {
    return plunger->at(0);
  } else if (barrier->size() > 0) {
    return barrier->at(0);
  } else if (reservoir->size() > 0) {
    return reservoir->at(0);
  } else if (screening->size() > 0) {
    return screening->at(0);
  } else {
    return nullptr;
  }
}
GatesSP StandardConfigConnections::get_all_gates() const {
  auto plunger   = std::dynamic_pointer_cast<Gates<Gate>>(_plunger_gates);
  auto barrier   = std::dynamic_pointer_cast<Gates<Gate>>(_barrier_gates);
  auto reservoir = std::dynamic_pointer_cast<Gates<Gate>>(_reservoir_gates);
  auto screening = std::dynamic_pointer_cast<Gates<Gate>>(_screening_gates);
  Gates<Gate> combination;
  combination.insert(combination.end(), barrier->begin(), barrier->end());
  combination.insert(combination.end(), plunger->begin(), plunger->end());
  combination.insert(combination.end(), reservoir->begin(), reservoir->end());
  combination.insert(combination.end(), screening->begin(), screening->end());
  return std::make_shared<Gates<Gate>>(combination);
}
OhmicsSP StandardConfigConnections::get_all_ohmics() const { return _ohmics; }
BaseConnectionsSP StandardConfigConnections::get_all_connections() const {
  auto ohmic =
      std::dynamic_pointer_cast<BaseConnections<BaseConnection>>(_ohmics);
  auto plunger = std::dynamic_pointer_cast<BaseConnections<BaseConnection>>(
      _plunger_gates);
  auto barrier = std::dynamic_pointer_cast<BaseConnections<BaseConnection>>(
      _barrier_gates);
  auto reservoir = std::dynamic_pointer_cast<BaseConnections<BaseConnection>>(
      _reservoir_gates);
  auto screening = std::dynamic_pointer_cast<BaseConnections<BaseConnection>>(
      _screening_gates);
  BaseConnections<BaseConnection> combination;
  combination.insert(combination.end(), barrier->begin(), barrier->end());
  combination.insert(combination.end(), plunger->begin(), plunger->end());
  combination.insert(combination.end(), reservoir->begin(), reservoir->end());
  combination.insert(combination.end(), screening->begin(), screening->end());
  combination.insert(combination.end(), ohmic->begin(), ohmic->end());
  return std::make_shared<BaseConnections<BaseConnection>>(combination);
}
bool StandardConfigConnections::has_ohmic(const OhmicSP& ohmic) const {
  for (auto& o : *_ohmics) {
    if (*o == *ohmic) {
      return true;
    }
  }
  return false;
}
bool StandardConfigConnections::has_gate(const GateSP& gate) const {
  for (auto& g : *get_all_gates()) {
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
}  // namespace core
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::core::StandardConfigConnections)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::core::StandardConfigConnections)
