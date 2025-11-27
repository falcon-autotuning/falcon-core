#include "falcon_core/physics/config/geometries/GateGeometryArray1D.hpp"

#include <stdexcept>

#include "falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp"
#include "falcon_core/physics/config/geometries/LeftReservoirWithImplantedOhmic.hpp"
namespace falcon_core {
namespace physics {
namespace config {
namespace geometries {
GateGeometryArray1D::GateGeometryArray1D() = default;
GateGeometryArray1D::GateGeometryArray1D(
    device_structures::ConnectionsSP lineararray,
    device_structures::ConnectionsSP screening_gates)
    : _linear_array(lineararray), _screening_gates(screening_gates) {
  if (!lineararray) {
    throw std::invalid_argument(
        "GateGeometryArray1D: The lineararray cannot be null.");
  }
  if (!screening_gates) {
    throw std::invalid_argument(
        "GateGeometryArray1D: The screening_gates cannot be null.");
  }
  if (!screening_gates->is_screening_gates()) {
    throw std::runtime_error(
        "GateGeometryArray1D: Expected the screening_gates to consist of only "
        "screening gates");
  }
  if (screening_gates->size() != 2) {
    throw std::invalid_argument(
        "GateGeometryArray1D: Expected two screening gates.");
  }
  if (lineararray->size() % 2 == 0) {
    throw std::invalid_argument(
        "GateGeometryArray1D: Expected an odd number of elements in the linear "
        "array. Got " +
        std::to_string(lineararray->size()) + " elements.");
  }
  if (!((*lineararray)[0]->is_ohmic()) ||
      !((*lineararray)[lineararray->size() - 1]->is_ohmic())) {
    throw std::invalid_argument(
        "GateGeometryArray1D: Expected Ohmic at the ends of the linear array.");
  }
  if (!((*lineararray)[1]->is_reservoir_gate()) ||
      !((*lineararray)[lineararray->size() - 2]->is_reservoir_gate())) {
    throw std::invalid_argument(
        "GateGeometryArray1D: Expected Reservoir Gates bounding the central "
        "dot gates.");
  }

  // Extract dot gates
  std::vector<device_structures::ConnectionSP> dot_gates;
  for (size_t i = 2; i < lineararray->size() - 2; ++i) {
    device_structures::ConnectionSP dot_gate = (*lineararray)[i];
    if (!(dot_gate->is_dot_gate())) {
      throw std::invalid_argument(
          "GateGeometryArray1D: Expected DotGates in the middle of the linear "
          "array.");
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

  _central_dot_gates = std::make_shared<DotGatesWithNeighbors>();
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
  return _linear_array->begin();
}
GateGeometryArray1D::iterator GateGeometryArray1D::end() {
  return _linear_array->end();
}
GateGeometryArray1D::const_iterator GateGeometryArray1D::begin() const {
  return _linear_array->begin();
}
GateGeometryArray1D::const_iterator GateGeometryArray1D::end() const {
  return _linear_array->end();
}
const device_structures::ConnectionsSP& GateGeometryArray1D::lineararray()
    const {
  return _linear_array;
}
const device_structures::ConnectionsSP& GateGeometryArray1D::screening_gates()
    const {
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
  if (!left_neighbor || !selected_gate || !right_neighbor) {
    throw std::invalid_argument(
        "GateGeometryArray1D: neighbors and selected_gate must not be null");
  }
  if (selected_gate->is_barrier_gate()) {
    if (!(left_neighbor->is_plunger_gate()) ||
        !(right_neighbor->is_plunger_gate())) {
      throw std::invalid_argument(
          "GateGeometryArray1D: Expected PlungerGate bounding selected "
          "BarrierGate.");
    }
    _central_dot_gates->push_back(
        DotGateWithNeighbors::BarrierGateWithNeighbors(
            selected_gate->name(), left_neighbor, right_neighbor));
  } else if (selected_gate->is_plunger_gate()) {
    if (!(left_neighbor->is_barrier_gate()) ||
        !(right_neighbor->is_barrier_gate())) {
      throw std::invalid_argument(
          "GateGeometryArray1D: Expected BarrierGate bounding selected "
          "PlungerGate.");
    }
    _central_dot_gates->push_back(
        DotGateWithNeighbors::PlungerGateWithNeighbors(
            selected_gate->name(), left_neighbor, right_neighbor));
  } else {
    throw std::invalid_argument(
        "Expected either a PlungerGate or BarrierGate.");
  }
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
  device_structures::ConnectionSP gate_geometry = it->second;

  device_structures::ConnectionsSP result =
      std::make_shared<device_structures::Connections>();

  // If gate_geometry is in screening_gates
  for (const auto& sg : *screening_gates()) {
    if (sg->name() == gate_geometry->name()) {
      auto lbar      = left_barrier();
      auto lneighbor = lbar->left_neighbor();
      result->push_back(lneighbor);
      auto central_gates = raw_central_gates();
      for (const auto& g : *central_gates) {
        result->push_back(g);
      }
      auto rbar      = right_barrier();
      auto rneighbor = rbar->right_neighbor();
      result->push_back(rneighbor);
      return result;
    }
  }
  if (gate_geometry->name() == left_reservoir()->name()) {
    auto lres      = left_reservoir();
    auto rneighbor = lres->right_neighbor();
    result->push_back(rneighbor);
    for (const auto& sg : *screening_gates()) {
      result->push_back(sg);
    }
    return result;
  } else if (gate_geometry->name() == right_reservoir()->name()) {
    auto rres      = right_reservoir();
    auto lneighbor = rres->left_neighbor();
    result->push_back(lneighbor);
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
  device_structures::ConnectionSP barrier_gate =

      (*lineararray())[2];
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
  device_structures::ConnectionSP barrier_gate =
      (*lineararray())[lineararray()->size() - 3];
  return std::make_shared<RightReservoirWithImplantedOhmic>(
      name, barrier_gate, ohmic);
}
DotGateWithNeighborsSP GateGeometryArray1D::left_barrier() const {
  std::string                     name = ((*lineararray())[2])->name();
  device_structures::ConnectionSP reservoir_gate = (*lineararray())[1];
  device_structures::ConnectionSP plunger_gate   = (*lineararray())[3];
  return DotGateWithNeighbors::BarrierGateWithNeighbors(
      name, reservoir_gate, plunger_gate);
}
DotGateWithNeighborsSP GateGeometryArray1D::right_barrier() const {
  std::string name = ((*lineararray())[lineararray()->size() - 3])->name();
  device_structures::ConnectionSP reservoir_gate =
      (*lineararray())[lineararray()->size() - 2];
  device_structures::ConnectionSP plunger_gate =
      (*lineararray())[lineararray()->size() - 4];
  return DotGateWithNeighbors::BarrierGateWithNeighbors(
      name, plunger_gate, reservoir_gate);
}
device_structures::ConnectionsSP GateGeometryArray1D::ohmics() const {
  device_structures::ConnectionSP left_ohmic = (*lineararray())[0];
  device_structures::ConnectionSP right_ohmic =
      (*lineararray())[lineararray()->size() - 1];
  std::vector<device_structures::ConnectionSP> tmp({left_ohmic, right_ohmic});
  return std::make_shared<device_structures::Connections>(tmp);
}
bool GateGeometryArray1D::operator==(const GateGeometryArray1D& other) const {
  return (*this->lineararray() == *other.lineararray()) &&
         (*this->screening_gates() == *other.screening_gates());
}
bool GateGeometryArray1D::operator!=(const GateGeometryArray1D& other) const {
  return !(*this == other);
}

}  // namespace geometries
}  // namespace config
}  // namespace physics
}  // namespace falcon_core
CEREAL_REGISTER_TYPE(
    falcon_core::physics::config::geometries::GateGeometryArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::physics::config::geometries::GateGeometryArray1D)
