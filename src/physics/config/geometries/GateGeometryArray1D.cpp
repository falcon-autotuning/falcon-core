#include "falcon_core/physics/config/geometries/GateGeometryArray1D.hpp"

#include <memory>

#include "falcon_core/macros.hpp"
#include "falcon_core/physics/config/geometries/LeftReservoirWithImplantedOhmic.hpp"
#include "falcon_core/physics/config/geometries/PlungerGateWithNeighbors.hpp"
#include "falcon_core/physics/device_structures/BarrierGate.hpp"
#include "falcon_core/physics/device_structures/DotGates.hpp"
#include "falcon_core/physics/device_structures/PlungerGate.hpp"
using namespace falcon_core::physics::config::geometries;

GateGeometryArray1D::GateGeometryArray1D(
    BaseConnectionsSP<BaseConnection> lineararray,
    ScreeningGatesSP                  screening_gates)
    : _lineararray(lineararray), _screening_gates(screening_gates) {
  if (screening_gates->size() != 2) {
    throw std::invalid_argument("Expected two screening gates.");
  }
  if (lineararray->size() % 2 == 0) {
    throw std::invalid_argument(
        "Expected an odd number of elements in the linear array. Got " +
        std::to_string(lineararray->size()) + " elements.");
  }
  if (!std::dynamic_pointer_cast<Ohmic>((*lineararray)[0]) ||
      !std::dynamic_pointer_cast<Ohmic>(
          (*lineararray)[lineararray->size() - 1])) {
    throw std::invalid_argument(
        "Expected Ohmic at the ends of the linear array.");
  }
  if (!std::dynamic_pointer_cast<ReservoirGate>((*lineararray)[1]) ||
      !std::dynamic_pointer_cast<ReservoirGate>(
          (*lineararray)[lineararray->size() - 2])) {
    throw std::invalid_argument(
        "Expected Reservoir Gates bounding the central dot gates.");
  }

  // Extract dot gates
  std::vector<DotGateSP> dot_gates;
  for (size_t i = 2; i < lineararray->size() - 2; ++i) {
    auto dot_gate = std::dynamic_pointer_cast<DotGate>((*lineararray)[i]);
    if (!dot_gate) {
      throw std::invalid_argument(
          "Expected DotGates in the middle of the linear array.");
    }
    dot_gates.push_back(dot_gate);
  }
  _raw_central_gates = DotGates<DotGate>(dot_gates);

  if (!std::dynamic_pointer_cast<BarrierGate>(dot_gates.front()) ||
      !std::dynamic_pointer_cast<BarrierGate>(dot_gates.back())) {
    throw std::invalid_argument(
        "Expected Barrier Gates bounding the exterior reservoir gates.");
  }
  if (!std::dynamic_pointer_cast<PlungerGate>(dot_gates[1]) ||
      !std::dynamic_pointer_cast<PlungerGate>(
          dot_gates[dot_gates.size() - 2])) {
    throw std::invalid_argument(
        "Expected Plunger Gates at the correct positions.");
  }

  // Central dot gates logic (example, adjust as needed)
  for (size_t i = 1; i + 1 < dot_gates.size(); ++i) {
    auto left_neighbor  = dot_gates[i - 1];
    auto selected_gate  = dot_gates[i];
    auto right_neighbor = dot_gates[i + 1];
    append_central_gate(left_neighbor, selected_gate, right_neighbor);
  }

  // Build the gate name map
  for (const auto& screening_gate : *_screening_gates) {
    _gate_name_map[screening_gate->name()] = screening_gate;
  }
  _gate_name_map[left_reservoir()->name()]  = left_reservoir();
  _gate_name_map[right_reservoir()->name()] = right_reservoir();
  auto all_dot                              = all_dot_gates();
  for (const auto& dot_gate : *all_dot) {
    _gate_name_map[dot_gate->name()] = dot_gate;
  }
}
BaseConnectionSP GateGeometryArray1D::begin() const {
  return SP(BaseConnection, _lineararray->begin());
}
BaseConnectionSP GateGeometryArray1D::end() const {
  return SP(BaseConnection, _lineararray->end());
}
void GateGeometryArray1D::append_central_gate(const DotGateSP& left_neighbor,
                                              const DotGateSP& selected_gate,
                                              const DotGateSP& right_neighbor) {
  if (auto barrier = std::dynamic_pointer_cast<BarrierGate>(selected_gate)) {
    if (!std::dynamic_pointer_cast<PlungerGate>(left_neighbor) ||
        !std::dynamic_pointer_cast<PlungerGate>(right_neighbor)) {
      throw std::invalid_argument(
          "Expected PlungerGate bounding selected BarrierGate.");
    }
    _central_dot_gates.push_back(std::static_pointer_cast<
                                 BaseDotGateWithNeighbors>(
        std::make_shared<BarrierGateWithNeighbors<PlungerGate, PlungerGate>>(
            barrier->name(), left_neighbor, right_neighbor)));
  } else if (auto plunger =
                 std::dynamic_pointer_cast<PlungerGate>(selected_gate)) {
    if (!std::dynamic_pointer_cast<BarrierGate>(left_neighbor) ||
        !std::dynamic_pointer_cast<BarrierGate>(right_neighbor)) {
      throw std::invalid_argument(
          "Expected BarrierGate bounding selected PlungerGate.");
    }
    _central_dot_gates.push_back(
        std::static_pointer_cast<BaseDotGateWithNeighbors>(
            std::make_shared<PlungerGateWithNeighbors>(
                plunger->name(), left_neighbor, right_neighbor)));
  } else {
    throw std::invalid_argument(
        "Expected either a PlungerGate or BarrierGate.");
  }
}
std::shared_ptr<DotGates<BaseDotGateWithNeighbors>>
GateGeometryArray1D::all_dot_gates() const {
  DotGates<BaseDotGateWithNeighbors> all_dot_gates;
  all_dot_gates.push_back(
      std::static_pointer_cast<BaseDotGateWithNeighbors>(left_barrier()));
  for (const auto& gate : _central_dot_gates) {
    all_dot_gates.push_back(
        std::static_pointer_cast<BaseDotGateWithNeighbors>(gate));
  }
  all_dot_gates.push_back(
      std::static_pointer_cast<BaseDotGateWithNeighbors>(right_barrier()));
  return std::make_shared<DotGates<BaseDotGateWithNeighbors>>(all_dot_gates);
}
GatesSP<Gate> GateGeometryArray1D::query_neighbors(const GateSP& gate) const {
  auto it = _gate_name_map.find(gate->name());
  if (it == _gate_name_map.end()) {
    throw std::invalid_argument("Gate " + gate->name() +
                                " not found in geometry.");
  }
  auto gate_geometry = it->second;

  Gates<Gate> result;

  // If gate_geometry is in screening_gates
  for (const auto& sg : *screening_gates()) {
    if (sg->name() == gate_geometry->name()) {
      result.push_back(left_barrier()->left_neighbor());
      for (const auto& g : raw_central_gates()) {
        result.push_back(g);
      }
      result.push_back(right_barrier()->right_neighbor());
      return std::make_shared<Gates<Gate>>(result);
    }
  }
  if (gate_geometry->name() == left_reservoir()->name()) {
    result.push_back(left_reservoir()->right_neighbor());
    for (const auto& sg : *screening_gates()) {
      result.push_back(sg);
    }
    return std::make_shared<Gates<Gate>>(result);
  } else if (gate_geometry->name() == right_reservoir()->name()) {
    result.push_back(right_reservoir()->left_neighbor());
    for (const auto& sg : *screening_gates()) {
      result.push_back(sg);
    }
    return std::make_shared<Gates<Gate>>(result);
  }
  auto gate_geom =
      std::dynamic_pointer_cast<BaseDotGateWithNeighbors>(gate_geometry);
  result.push_back(gate_geom->left_neighbor());
  result.push_back(gate_geom->right_neighbor());
  for (const auto& sg : *screening_gates()) {
    result.push_back(sg);
  }
  return std::make_shared<Gates<Gate>>(result);
}
LeftReservoirWithImplantedOhmicSP GateGeometryArray1D::left_reservoir() const {
  std::string   name  = ((*lineararray())[1])->name();
  OhmicSP       ohmic = std::dynamic_pointer_cast<Ohmic>((*lineararray())[0]);
  BarrierGateSP barrier_gate =
      std::dynamic_pointer_cast<BarrierGate>((*lineararray())[2]);
  LeftReservoirWithImplantedOhmic left_reservoir =
      LeftReservoirWithImplantedOhmic(name, barrier_gate, ohmic);
  return SP(LeftReservoirWithImplantedOhmic, left_reservoir);
}
RightReservoirWithImplantedOhmicSP GateGeometryArray1D::right_reservoir()
    const {
  std::string name  = (*lineararray())[lineararray()->size() - 2]->name();
  OhmicSP     ohmic = std::dynamic_pointer_cast<Ohmic>(
      (*lineararray())[lineararray()->size() - 1]);
  BarrierGateSP barrier_gate = std::dynamic_pointer_cast<BarrierGate>(
      (*lineararray())[lineararray()->size() - 3]);
  return std::make_shared<RightReservoirWithImplantedOhmic>(
      name, barrier_gate, ohmic);
}
BarrierGateWithNeighborsSP<ReservoirGate, PlungerGate>
GateGeometryArray1D::left_barrier() const {
  std::string     name = ((*lineararray())[2])->name();
  ReservoirGateSP reservoir_gate =
      std::dynamic_pointer_cast<ReservoirGate>((*lineararray())[1]);
  PlungerGateSP plunger_gate =
      std::dynamic_pointer_cast<PlungerGate>((*lineararray())[3]);
  return std::make_shared<BarrierGateWithNeighbors<ReservoirGate, PlungerGate>>(
      name, reservoir_gate, plunger_gate);
}
BarrierGateWithNeighborsSP<PlungerGate, ReservoirGate>
GateGeometryArray1D::right_barrier() const {
  std::string     name = ((*lineararray())[lineararray()->size() - 3])->name();
  ReservoirGateSP reservoir_gate = std::dynamic_pointer_cast<ReservoirGate>(
      (*lineararray())[lineararray()->size() - 2]);
  PlungerGateSP plunger_gate = std::dynamic_pointer_cast<PlungerGate>(
      (*lineararray())[lineararray()->size() - 4]);
  return std::make_shared<BarrierGateWithNeighbors<PlungerGate, ReservoirGate>>(
      name, plunger_gate, reservoir_gate);
}
OhmicsSP GateGeometryArray1D::ohmics() const {
  OhmicSP left_ohmic  = std::dynamic_pointer_cast<Ohmic>((*lineararray())[0]);
  OhmicSP right_ohmic = std::dynamic_pointer_cast<Ohmic>(
      (*lineararray())[lineararray()->size() - 1]);
  Ohmics tmp{left_ohmic, right_ohmic};
  return std::make_shared<Ohmics>(tmp);
}
