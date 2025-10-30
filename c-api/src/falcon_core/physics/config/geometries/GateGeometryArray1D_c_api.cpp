#include "falcon_core/physics/config/geometries/GateGeometryArray1D_c_api.h"

#include <falcon_core/physics/config/geometries/GateGeometryArray1D.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connections.hpp"

using namespace falcon_core::physics::config::geometries;

extern "C" {

GateGeometryArray1DHandle GateGeometryArray1D_create(
    ConnectionsHandle lineararray, ConnectionsHandle screening_gates) {
  falcon_core::physics::device_structures::ConnectionsSP real_lineararray =
      std::make_shared<falcon_core::physics::device_structures::Connections>(
          *static_cast<falcon_core::physics::device_structures::Connections*>(
              lineararray));
  falcon_core::physics::device_structures::ConnectionsSP real_screening_gates =
      std::make_shared<falcon_core::physics::device_structures::Connections>(
          *static_cast<falcon_core::physics::device_structures::Connections*>(
              screening_gates));
  return new GateGeometryArray1D(
      GateGeometryArray1D(real_lineararray, real_screening_gates));
}

void GateGeometryArray1D_destroy(GateGeometryArray1DHandle handle) {
  delete static_cast<GateGeometryArray1D*>(handle);
}

void GateGeometryArray1D_append_central_gate(GateGeometryArray1DHandle handle,
                                             ConnectionHandle left_neighbor,
                                             ConnectionHandle selected_gate,
                                             ConnectionHandle right_neighbor) {
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
}

DotGatesWithNeighborsHandle GateGeometryArray1D_all_dot_gates(
    GateGeometryArray1DHandle handle) {
  falcon_core::physics::config::geometries::DotGatesWithNeighborsSP result =
      static_cast<GateGeometryArray1D*>(handle)->all_dot_gates();
  return new DotGatesWithNeighbors(*(result));
}

ConnectionsHandle GateGeometryArray1D_query_neighbors(
    GateGeometryArray1DHandle handle, ConnectionHandle gate) {
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_gate =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              gate));
  return new falcon_core::physics::device_structures::Connections(
      *(self.query_neighbors(real_gate)));
}

LeftReservoirWithImplantedOhmicHandle GateGeometryArray1D_left_reservoir(
    GateGeometryArray1DHandle handle) {
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  falcon_core::physics::config::geometries::LeftReservoirWithImplantedOhmicSP
      result = self.left_reservoir();
  return new LeftReservoirWithImplantedOhmic(*(result));
}

RightReservoirWithImplantedOhmicHandle GateGeometryArray1D_right_reservoir(
    GateGeometryArray1DHandle handle) {
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  return new RightReservoirWithImplantedOhmic(*(self.right_reservoir()));
}

DotGateWithNeighborsHandle GateGeometryArray1D_left_barrier(
    GateGeometryArray1DHandle handle) {
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  return new DotGateWithNeighbors(*(self.left_barrier()));
}

DotGateWithNeighborsHandle GateGeometryArray1D_right_barrier(
    GateGeometryArray1DHandle handle) {
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  return new DotGateWithNeighbors(*(self.right_barrier()));
}

ConnectionsHandle GateGeometryArray1D_lineararray(
    GateGeometryArray1DHandle handle) {
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  return new falcon_core::physics::device_structures::Connections(
      *(self.lineararray()));
}

ConnectionsHandle GateGeometryArray1D_screening_gates(
    GateGeometryArray1DHandle handle) {
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  return new falcon_core::physics::device_structures::Connections(
      *(self.screening_gates()));
}

ConnectionsHandle GateGeometryArray1D_raw_central_gates(
    GateGeometryArray1DHandle handle) {
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  return new falcon_core::physics::device_structures::Connections(
      *(self.raw_central_gates()));
}

DotGatesWithNeighborsHandle GateGeometryArray1D_central_dot_gates(
    GateGeometryArray1DHandle handle) {
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  return new DotGatesWithNeighbors(*(self.central_dot_gates()));
}

ConnectionsHandle GateGeometryArray1D_ohmics(GateGeometryArray1DHandle handle) {
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  return new falcon_core::physics::device_structures::Connections(
      *(self.ohmics()));
}

bool GateGeometryArray1D_equal(GateGeometryArray1DHandle handle,
                               GateGeometryArray1DHandle other) {
  GateGeometryArray1D self       = *static_cast<GateGeometryArray1D*>(handle);
  GateGeometryArray1D real_other = *static_cast<GateGeometryArray1D*>(other);
  return self == real_other;
}

bool GateGeometryArray1D_not_equal(GateGeometryArray1DHandle handle,
                                   GateGeometryArray1DHandle other) {
  GateGeometryArray1D self       = *static_cast<GateGeometryArray1D*>(handle);
  GateGeometryArray1D real_other = *static_cast<GateGeometryArray1D*>(other);
  return self != real_other;
}

StringHandle GateGeometryArray1D_to_json_string(
    GateGeometryArray1DHandle handle) {
  GateGeometryArray1D self = *static_cast<GateGeometryArray1D*>(handle);
  return String_create(self.to_json_string().c_str(),
                       self.to_json_string().size());
}
GateGeometryArray1DHandle GateGeometryArray1D_from_json_string(
    StringHandle json) {
  std::string real_json(json->raw, json->length);
  return new GateGeometryArray1D(
      *GateGeometryArray1D::from_json_string<GateGeometryArray1D>(real_json));
}

#ifdef __cplusplus
}
#endif
