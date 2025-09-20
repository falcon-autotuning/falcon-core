#include "falcon_core/physics/config/geometries/GateGeometryArray1D.hpp"

#include <stdexcept>

#include "falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp"
#include "falcon_core/physics/config/geometries/LeftReservoirWithImplantedOhmic.hpp"
#include "falcon_core/physics/config/geometries/PlungerGateWithNeighbors.hpp"
namespace falcon_core::physics::config::geometries {
GateGeometryArray1D::GateGeometryArray1D() = default;
GateGeometryArray1D::GateGeometryArray1D(
    device_structures::ConnectionsSP lineararray,
    device_structures::ConnectionsSP screening_gates)
    : _lineararray(lineararray), _screening_gates(screening_gates) {
  if (!screening_gates->is_screening_gates()) {
    throw std::runtime_error(
        "Expected the screening_gates to consist of only screening gates");
  }
  if (screening_gates->size() != 2) {
    throw std::invalid_argument("Expected two screening gates.");
  }
  if (lineararray->size() % 2 == 0) {
    throw std::invalid_argument(
        "Expected an odd number of elements in the linear array. Got " +
        std::to_string(lineararray->size()) + " elements.");
  }
  if (!((*lineararray)[0]->is_ohmic()) ||
      !((*lineararray)[lineararray->size() - 1]->is_ohmic())) {
    throw std::invalid_argument(
        "Expected Ohmic at the ends of the linear array.");
  }
  if (!((*lineararray)[1]->is_reservoir_gate()) ||
      !((*lineararray)[lineararray->size() - 2]->is_reservoir_gate())) {
    throw std::invalid_argument(
        "Expected Reservoir Gates bounding the central dot gates.");
  }

  // Extract dot gates
  std::vector<device_structures::ConnectionSP> dot_gates;
  for (size_t i = 2; i < lineararray->size() - 2; ++i) {
    device_structures::ConnectionSP dot_gate = (*lineararray)[i];
    if (!(dot_gate->is_dot_gate())) {
      throw std::invalid_argument(
          "Expected DotGates in the middle of the linear array.");
    }
    dot_gates.push_back(dot_gate);
  }
  _raw_central_gates = device_structures::Connections(dot_gates);

  if (!(dot_gates.front()->is_barrier_gate()) ||
      !(dot_gates.back()->is_barrier_gate())) {
    throw std::invalid_argument(
        "Expected Barrier Gates bounding the exterior reservoir gates.");
  }
  if (!(dot_gates[1]->is_plunger_gate()) ||
      !(dot_gates[dot_gates.size() - 2]->is_plunger_gate())) {
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
GateGeometryArray1D::iterator GateGeometryArray1D::begin() {
  return _lineararray->begin();
}
GateGeometryArray1D::iterator GateGeometryArray1D::end() {
  return _lineararray->end();
}
GateGeometryArray1D::const_iterator GateGeometryArray1D::begin() const {
  return _lineararray->begin();
}
GateGeometryArray1D::const_iterator GateGeometryArray1D::end() const {
  return _lineararray->end();
}
device_structures::ConnectionsSP GateGeometryArray1D::lineararray() const {
  return _lineararray;
}
device_structures::ConnectionsSP GateGeometryArray1D::screening_gates() const {
  if (!_screening_gates->is_screening_gates()) {
    throw std::runtime_error(
        "Expected the screening_gates to only be screening_gates");
  }
  return _screening_gates;
}
device_structures::ConnectionsSP GateGeometryArray1D::raw_central_gates()
    const {
  return std::make_shared<device_structures::Connections>(_raw_central_gates);
}
DotGatesWithNeighborsSP GateGeometryArray1D::central_dot_gates() const {
  return _central_dot_gates;
}
void GateGeometryArray1D::append_central_gate(
    const device_structures::ConnectionSP& left_neighbor,
    const device_structures::ConnectionSP& selected_gate,
    const device_structures::ConnectionSP& right_neighbor) {
  if (selected_gate->is_barrier_gate()) {
    if (!(left_neighbor->is_plunger_gate()) ||
        !(right_neighbor->is_plunger_gate())) {
      throw std::invalid_argument(
          "Expected PlungerGate bounding selected BarrierGate.");
    }
  } else if (selected_gate->is_plunger_gate()) {
    if (!(left_neighbor->is_barrier_gate()) ||
        !(right_neighbor->is_barrier_gate())) {
      throw std::invalid_argument(
          "Expected BarrierGate bounding selected PlungerGate.");
    }
  } else {
    throw std::invalid_argument(
        "Expected either a PlungerGate or BarrierGate.");
  }

  _central_dot_gates->push_back(std::static_pointer_cast<DotGateWithNeighbors>(
      std::make_shared<PlungerGateWithNeighbors>(
          selected_gate->name(), left_neighbor, right_neighbor)));
}
DotGatesWithNeighborsSP GateGeometryArray1D::all_dot_gates() const {
  DotGatesWithNeighbors all_dot_gates;
  all_dot_gates.push_back(left_barrier());
  for (const auto& gate : *_central_dot_gates) {
    all_dot_gates.push_back(gate);
  }
  all_dot_gates.push_back(right_barrier());
  return std::make_shared<DotGatesWithNeighbors>(all_dot_gates);
}
device_structures::ConnectionsSP GateGeometryArray1D::query_neighbors(
    const device_structures::ConnectionSP& gate) const {
  auto it = _gate_name_map.find(gate->name());
  if (it == _gate_name_map.end()) {
    throw std::invalid_argument("Gate " + gate->name() +
                                " not found in geometry.");
  }
  auto gate_geometry = it->second;

  device_structures::ConnectionsSP result;

  // If gate_geometry is in screening_gates
  for (const auto& sg : *screening_gates()) {
    if (sg->name() == gate_geometry->name()) {
      result->push_back(left_barrier()->left_neighbor());
      for (const auto& g : *raw_central_gates()) {
        result->push_back(g);
      }
      result->push_back(right_barrier()->right_neighbor());
      return result;
    }
  }
  if (gate_geometry->name() == left_reservoir()->name()) {
    result->push_back(left_reservoir()->right_neighbor());
    for (const auto& sg : *screening_gates()) {
      result->push_back(sg);
    }
    return result;
  } else if (gate_geometry->name() == right_reservoir()->name()) {
    result->push_back(right_reservoir()->left_neighbor());
    for (const auto& sg : *screening_gates()) {
      result->push_back(sg);
    }
    return result;
  }
  auto gate_geom =
      std::dynamic_pointer_cast<DotGateWithNeighbors>(gate_geometry);
  result->push_back(gate_geom->left_neighbor());
  result->push_back(gate_geom->right_neighbor());
  for (const auto& sg : *screening_gates()) {
    result->push_back(sg);
  }
  return result;
}
LeftReservoirWithImplantedOhmicSP GateGeometryArray1D::left_reservoir() const {
  std::string                     name  = ((*lineararray())[1])->name();
  device_structures::ConnectionSP ohmic = (*lineararray())[0];
  if (!ohmic->is_ohmic()) {
    throw std::runtime_error(
        "Expected the first element of the array to be an ohmic and not " +
        ohmic->type());
  }
  device_structures::ConnectionSP barrier_gate =

      (*lineararray())[2];
  if (!barrier_gate->is_barrier_gate()) {
    throw std::runtime_error(
        "Expected the second element of the array to be a barrier gate and "
        "not " +
        barrier_gate->type());
  }
  LeftReservoirWithImplantedOhmicSP left_reservoir =
      std::make_shared<LeftReservoirWithImplantedOhmic>(
          name, barrier_gate, ohmic);
  return left_reservoir;
}
RightReservoirWithImplantedOhmicSP GateGeometryArray1D::right_reservoir()
    const {
  std::string name = (*lineararray())[lineararray()->size() - 2] -> name();
  device_structures::ConnectionSP ohmic =
      (*lineararray())[lineararray()->size() - 1];
  if (!ohmic->is_ohmic()) {
    throw std::runtime_error(
        "Expected the last element of the array to be an ohmic and not " +
        ohmic->type());
  }
  device_structures::ConnectionSP barrier_gate =
      (*lineararray())[lineararray()->size() - 3];
  if (!barrier_gate->is_barrier_gate()) {
    throw std::runtime_error(
        "Expected the second to last element of the array to be a barrier gate "
        "and "
        "not " +
        barrier_gate->type());
  }
  return std::make_shared<RightReservoirWithImplantedOhmic>(
      name, barrier_gate, ohmic);
}
BarrierGateWithNeighborsSP GateGeometryArray1D::left_barrier() const {
  std::string                     name = ((*lineararray())[2])->name();
  device_structures::ConnectionSP reservoir_gate = (*lineararray())[1];
  device_structures::ConnectionSP plunger_gate   = (*lineararray())[3];
  if (!reservoir_gate->is_reservoir_gate()) {
    throw std::runtime_error(
        "Expected the second element of the array to be a reservoir gate "
        "and "
        "not " +
        reservoir_gate->type());
  }
  if (!plunger_gate->is_plunger_gate()) {
    throw std::runtime_error(
        "Expected the fourth element of the array to be a plunger gate "
        "and "
        "not " +
        plunger_gate->type());
  }
  return std::make_shared<BarrierGateWithNeighbors>(
      name, reservoir_gate, plunger_gate);
}
BarrierGateWithNeighborsSP GateGeometryArray1D::right_barrier() const {
  std::string name = ((*lineararray())[lineararray()->size() - 3])->name();
  device_structures::ConnectionSP reservoir_gate =
      (*lineararray())[lineararray()->size() - 2];
  device_structures::ConnectionSP plunger_gate =
      (*lineararray())[lineararray()->size() - 4];
  if (!reservoir_gate->is_reservoir_gate()) {
    throw std::runtime_error(
        "Expected the second to last element of the array to be a reservoir "
        "gate "
        "and "
        "not " +
        reservoir_gate->type());
  }
  if (!plunger_gate->is_plunger_gate()) {
    throw std::runtime_error(
        "Expected the fourth to last element of the array to be a plunger gate "
        "and "
        "not " +
        plunger_gate->type());
  }
  return std::make_shared<BarrierGateWithNeighbors>(
      name, plunger_gate, reservoir_gate);
}
device_structures::ConnectionsSP GateGeometryArray1D::ohmics() const {
  device_structures::ConnectionSP left_ohmic = (*lineararray())[0];
  device_structures::ConnectionSP right_ohmic =
      (*lineararray())[lineararray()->size() - 1];
  if (!left_ohmic->is_ohmic()) {
    throw std::runtime_error(
        "Expected the first element of the array to be an ohmic and not " +
        left_ohmic->type());
  }
  if (!right_ohmic->is_ohmic()) {
    throw std::runtime_error(
        "Expected the last element of the array to be an ohmic and not " +
        right_ohmic->type());
  }
  std::vector<device_structures::ConnectionSP> tmp({left_ohmic, right_ohmic});
  return std::make_shared<device_structures::Connections>(tmp);
}
}  // namespace falcon_core::physics::config::geometries
CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::GateGeometryArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::geometries::GateGeometryArray1D)
