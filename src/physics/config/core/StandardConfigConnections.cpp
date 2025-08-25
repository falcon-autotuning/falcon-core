#include "falcon_core/physics/config/core/StandardConfigConnections.hpp"

#include <memory>

#include "falcon_core/physics/device_structures/BarrierGate.hpp"

using namespace falcon_core::physics::config::core;

OhmicsSP StandardConfigConnections::get_connections(OhmicSP conn_type) const {
  return _ohmics;
}
BarrierGatesSP StandardConfigConnections::get_connections(
    BarrierGateSP conn_type) const {
  return _barrier_gates;
}
PlungerGatesSP StandardConfigConnections::get_connections(
    PlungerGateSP conn_type) const {
  return _plunger_gates;
}
ReservoirGatesSP StandardConfigConnections::get_connections(
    ReservoirGateSP conn_type) const {
  return _reservoir_gates;
}
ScreeningGatesSP StandardConfigConnections::get_connections(
    ScreeningGateSP conn_type) const {
  return _screening_gates;
}
DotGatesSP<DotGate> StandardConfigConnections::get_connections(
    DotGateSP conn_type) const {
  auto plunger = std::dynamic_pointer_cast<DotGates<DotGate>>(_plunger_gates);
  auto barrier = std::dynamic_pointer_cast<DotGates<DotGate>>(_barrier_gates);
  return std::make_shared<DotGates<DotGate>>(*plunger + *barrier);
}
GatesSP<Gate> StandardConfigConnections::get_connections(
    GateSP conn_type) const {
  auto plunger   = std::dynamic_pointer_cast<Gates<Gate>>(_plunger_gates);
  auto barrier   = std::dynamic_pointer_cast<Gates<Gate>>(_barrier_gates);
  auto reservoir = std::dynamic_pointer_cast<Gates<Gate>>(_reservoir_gates);
  auto screening = std::dynamic_pointer_cast<Gates<Gate>>(_screening_gates);
  return std::make_shared<Gates<Gate>>(*plunger + *barrier + *reservoir +
                                       *screening);
}
OhmicSP StandardConfigConnections::get_connection(OhmicSP conn_type) const {
  return _ohmics->at(0);
}
BarrierGateSP StandardConfigConnections::get_connection(
    BarrierGateSP conn_type) const {
  return _barrier_gates->at(0);
}
PlungerGateSP StandardConfigConnections::get_connection(
    PlungerGateSP conn_type) const {
  return _plunger_gates->at(0);
}
ReservoirGateSP StandardConfigConnections::get_connection(
    ReservoirGateSP conn_type) const {
  return _reservoir_gates->at(0);
}
ScreeningGateSP StandardConfigConnections::get_connection(
    ScreeningGateSP conn_type) const {
  return _screening_gates->at(0);
}
DotGateSP StandardConfigConnections::get_connection(DotGateSP conn_type) const {
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
GateSP StandardConfigConnections::get_connection(GateSP conn_type) const {
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
GatesSP<Gate> StandardConfigConnections::get_all_gates() const {
  auto plunger   = std::dynamic_pointer_cast<Gates<Gate>>(_plunger_gates);
  auto barrier   = std::dynamic_pointer_cast<Gates<Gate>>(_barrier_gates);
  auto reservoir = std::dynamic_pointer_cast<Gates<Gate>>(_reservoir_gates);
  auto screening = std::dynamic_pointer_cast<Gates<Gate>>(_screening_gates);
  return std::make_shared<Gates<Gate>>(*plunger + *barrier + *reservoir +
                                       *screening);
}
OhmicsSP StandardConfigConnections::get_all_ohmics() const { return _ohmics; }
BaseConnectionsSP<BaseConnection>
StandardConfigConnections::get_all_connections() const {
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
  return std::make_shared<BaseConnections<BaseConnection>>(
      *ohmic + *plunger + *barrier + *reservoir + *screening);
}
bool StandardConfigConnections::has_ohmic(OhmicSP ohmic) const {
  for (auto& o : *_ohmics) {
    if (*o == *ohmic) {
      return true;
    }
  }
  return false;
}
bool StandardConfigConnections::has_gate(GateSP gate) const {
  for (auto& g : *get_all_gates()) {
    if (*g == *gate) {
      return true;
    }
  }
  return false;
}
