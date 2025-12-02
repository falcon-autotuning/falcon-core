#include "falcon_core/physics/config/geometries/GateGeometryArray1D_c_api.h"

#include <falcon_core/physics/config/geometries/GateGeometryArray1D.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connections.hpp"

using namespace falcon_core::physics::config::geometries;
extern "C" {

GateGeometryArray1DHandle GateGeometryArray1D_create(
    ConnectionsHandle lineararray, ConnectionsHandle screening_gates) {
  FALCON_C_API_BEGIN
  if (!lineararray) {
    throw std::invalid_argument(
        "GateGeometryArray1D_create: lineararray cannot be null");
  }
  if (!screening_gates) {
    throw std::invalid_argument(
        "GateGeometryArray1D_create: screening_gates cannot be null");
  }
  falcon_core::physics::device_structures::ConnectionsSP real_linear_array =
      std::make_shared<falcon_core::physics::device_structures::Connections>(
          *static_cast<falcon_core::physics::device_structures::Connections*>(
              lineararray));
  falcon_core::physics::device_structures::ConnectionsSP real_screening_gates =
      std::make_shared<falcon_core::physics::device_structures::Connections>(
          *static_cast<falcon_core::physics::device_structures::Connections*>(
              screening_gates));
  return new GateGeometryArray1D(
      GateGeometryArray1D(real_linear_array, real_screening_gates));
  FALCON_C_API_END(nullptr)
}

void GateGeometryArray1D_destroy(GateGeometryArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_destroy: handle cannot be null");
  }
  delete static_cast<GateGeometryArray1D*>(handle);
  FALCON_C_API_END()
}

void GateGeometryArray1D_append_central_gate(GateGeometryArray1DHandle handle,
                                             ConnectionHandle left_neighbor,
                                             ConnectionHandle selected_gate,
                                             ConnectionHandle right_neighbor) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_append_central_gate: handle cannot be null");
  }
  if (!left_neighbor) {
    throw std::invalid_argument(
        "GateGeometryArray1D_append_central_gate: left_neighbor cannot be "
        "null");
  }
  if (!selected_gate) {
    throw std::invalid_argument(
        "GateGeometryArray1D_append_central_gate: selected_gate cannot be "
        "null");
  }
  if (!right_neighbor) {
    throw std::invalid_argument(
        "GateGeometryArray1D_append_central_gate: right_neighbor cannot be "
        "null");
  }
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_left_neighbor =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              left_neighbor));
  falcon_core::physics::device_structures::ConnectionSP real_selected_gate =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              selected_gate));
  falcon_core::physics::device_structures::ConnectionSP real_right_neighbor =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              right_neighbor));
  self.append_central_gate(
      real_left_neighbor, real_selected_gate, real_right_neighbor);
  FALCON_C_API_END()
}

DotGatesWithNeighborsHandle GateGeometryArray1D_all_dot_gates(
    GateGeometryArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_all_dot_gates: handle cannot be null");
  }
  falcon_core::physics::config::geometries::DotGatesWithNeighborsSP result =
      static_cast<GateGeometryArray1D*>(handle)->all_dot_gates();
  return new DotGatesWithNeighbors(*(result));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle GateGeometryArray1D_query_neighbors(
    GateGeometryArray1DHandle handle, ConnectionHandle gate) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_query_neighbors: handle cannot be null");
  }
  if (!gate) {
    throw std::invalid_argument(
        "GateGeometryArray1D_query_neighbors: gate cannot be null");
  }
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_gate =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              gate));
  return new falcon_core::physics::device_structures::Connections(
      *(self.query_neighbors(real_gate)));
  FALCON_C_API_END(nullptr)
}

LeftReservoirWithImplantedOhmicHandle GateGeometryArray1D_left_reservoir(
    GateGeometryArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_left_reservoir: handle cannot be null");
  }
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  falcon_core::physics::config::geometries::LeftReservoirWithImplantedOhmicSP
      result = self.left_reservoir();
  return new LeftReservoirWithImplantedOhmic(*(result));
  FALCON_C_API_END(nullptr)
}

RightReservoirWithImplantedOhmicHandle GateGeometryArray1D_right_reservoir(
    GateGeometryArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_right_reservoir: handle cannot be null");
  }
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  return new RightReservoirWithImplantedOhmic(*(self.right_reservoir()));
  FALCON_C_API_END(nullptr)
}

DotGateWithNeighborsHandle GateGeometryArray1D_left_barrier(
    GateGeometryArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_left_barrier: handle cannot be null");
  }
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  return new DotGateWithNeighbors(*(self.left_barrier()));
  FALCON_C_API_END(nullptr)
}

DotGateWithNeighborsHandle GateGeometryArray1D_right_barrier(
    GateGeometryArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_right_barrier: handle cannot be null");
  }
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  return new DotGateWithNeighbors(*(self.right_barrier()));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle GateGeometryArray1D_linear_array(
    GateGeometryArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_linear_array: handle cannot be null");
  }
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  return new falcon_core::physics::device_structures::Connections(
      *(self.lineararray()));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle GateGeometryArray1D_screening_gates(
    GateGeometryArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_screening_gates: handle cannot be null");
  }
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  return new falcon_core::physics::device_structures::Connections(
      *(self.screening_gates()));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle GateGeometryArray1D_raw_central_gates(
    GateGeometryArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_raw_central_gates: handle cannot be null");
  }
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  return new falcon_core::physics::device_structures::Connections(
      *(self.raw_central_gates()));
  FALCON_C_API_END(nullptr)
}

DotGatesWithNeighborsHandle GateGeometryArray1D_central_dot_gates(
    GateGeometryArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_central_dot_gates: handle cannot be null");
  }
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  return new DotGatesWithNeighbors(*(self.central_dot_gates()));
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle GateGeometryArray1D_ohmics(GateGeometryArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_ohmics: handle cannot be null");
  }
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  return new falcon_core::physics::device_structures::Connections(
      *(self.ohmics()));
  FALCON_C_API_END(nullptr)
}

bool GateGeometryArray1D_equal(GateGeometryArray1DHandle handle,
                               GateGeometryArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_equal: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "GateGeometryArray1D_equal: other cannot be null");
  }
  GateGeometryArray1D self       = *static_cast<GateGeometryArray1D*>(handle);
  GateGeometryArray1D real_other = *static_cast<GateGeometryArray1D*>(other);
  return self == real_other;
  FALCON_C_API_END(false)
}

bool GateGeometryArray1D_not_equal(GateGeometryArray1DHandle handle,
                                   GateGeometryArray1DHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_not_equal: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "GateGeometryArray1D_not_equal: other cannot be null");
  }
  GateGeometryArray1D self       = *static_cast<GateGeometryArray1D*>(handle);
  GateGeometryArray1D real_other = *static_cast<GateGeometryArray1D*>(other);
  return self != real_other;
  FALCON_C_API_END(false)
}

StringHandle GateGeometryArray1D_to_json_string(
    GateGeometryArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_to_json_string: handle cannot be null");
  }
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  return String_create(self.to_json_string().c_str(),
                       self.to_json_string().size());
  FALCON_C_API_END(nullptr)
}
GateGeometryArray1DHandle GateGeometryArray1D_from_json_string(
    StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "GateGeometryArray1D_from_json_string: json cannot be null");
  }
  std::string real_json(json->raw, json->length);
  return new GateGeometryArray1D(
      *GateGeometryArray1D::from_json_string<GateGeometryArray1D>(real_json));
  FALCON_C_API_END(nullptr)
}
}
