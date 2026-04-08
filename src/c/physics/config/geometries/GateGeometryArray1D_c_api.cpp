#include "falcon-core/physics/config/geometries/GateGeometryArray1D_c_api.h"

#include <falcon-core/physics/config/geometries/GateGeometryArray1D.hpp>

#include "falcon-core/Precompiled_c_api.h"
#include "falcon-core/physics/device_structures/Connections.hpp"

using namespace falcon_core::physics::config::geometries;
extern "C" {
DEFINE_C_API_COPY(GateGeometryArray1D);
DEFINE_C_API_DESTROY(GateGeometryArray1D);
DEFINE_C_API_EQUAL(GateGeometryArray1D);
DEFINE_C_API_NOT_EQUAL(GateGeometryArray1D);
DEFINE_C_API_TO_JSON(GateGeometryArray1D);
DEFINE_C_API_FROM_JSON(GateGeometryArray1D);

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
      *static_cast<falcon_core::physics::device_structures::ConnectionsSP*>(
          lineararray);
  falcon_core::physics::device_structures::ConnectionsSP real_screening_gates =
      *static_cast<falcon_core::physics::device_structures::ConnectionsSP*>(
          screening_gates);
  return new GateGeometryArray1DSP(std::make_shared<GateGeometryArray1D>(
      real_linear_array, real_screening_gates));
  FALCON_C_API_END(nullptr)
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
  GateGeometryArray1DSP self = *static_cast<GateGeometryArray1DSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_left_neighbor =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          left_neighbor);
  falcon_core::physics::device_structures::ConnectionSP real_selected_gate =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          selected_gate);
  falcon_core::physics::device_structures::ConnectionSP real_right_neighbor =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          right_neighbor);
  self->append_central_gate(
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
      (*static_cast<GateGeometryArray1DSP*>(handle))->all_dot_gates();
  return new DotGatesWithNeighborsSP(result);
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
  GateGeometryArray1DSP self = *static_cast<GateGeometryArray1DSP*>(handle);
  falcon_core::physics::device_structures::ConnectionSP real_gate =
      *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(
          gate);
  return new falcon_core::physics::device_structures::ConnectionsSP(
      self->query_neighbors(real_gate));
  FALCON_C_API_END(nullptr)
}

LeftReservoirWithImplantedOhmicHandle GateGeometryArray1D_left_reservoir(
    GateGeometryArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_left_reservoir: handle cannot be null");
  }
  GateGeometryArray1DSP self = *static_cast<GateGeometryArray1DSP*>(handle);
  falcon_core::physics::config::geometries::LeftReservoirWithImplantedOhmicSP
      result = self->left_reservoir();
  return new LeftReservoirWithImplantedOhmicSP(result);
  FALCON_C_API_END(nullptr)
}

RightReservoirWithImplantedOhmicHandle GateGeometryArray1D_right_reservoir(
    GateGeometryArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_right_reservoir: handle cannot be null");
  }
  GateGeometryArray1DSP self = *static_cast<GateGeometryArray1DSP*>(handle);
  return new RightReservoirWithImplantedOhmicSP(self->right_reservoir());
  FALCON_C_API_END(nullptr)
}

DotGateWithNeighborsHandle GateGeometryArray1D_left_barrier(
    GateGeometryArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_left_barrier: handle cannot be null");
  }
  GateGeometryArray1DSP self = *static_cast<GateGeometryArray1DSP*>(handle);
  return new DotGateWithNeighborsSP(self->left_barrier());
  FALCON_C_API_END(nullptr)
}

DotGateWithNeighborsHandle GateGeometryArray1D_right_barrier(
    GateGeometryArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_right_barrier: handle cannot be null");
  }
  GateGeometryArray1DSP self = *static_cast<GateGeometryArray1DSP*>(handle);
  return new DotGateWithNeighborsSP(self->right_barrier());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle GateGeometryArray1D_linear_array(
    GateGeometryArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_linear_array: handle cannot be null");
  }
  GateGeometryArray1DSP self = *static_cast<GateGeometryArray1DSP*>(handle);
  return new falcon_core::physics::device_structures::ConnectionsSP(
      self->lineararray());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle GateGeometryArray1D_screening_gates(
    GateGeometryArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_screening_gates: handle cannot be null");
  }
  GateGeometryArray1DSP self = *static_cast<GateGeometryArray1DSP*>(handle);
  return new falcon_core::physics::device_structures::ConnectionsSP(
      self->screening_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle GateGeometryArray1D_raw_central_gates(
    GateGeometryArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_raw_central_gates: handle cannot be null");
  }
  GateGeometryArray1DSP self = *static_cast<GateGeometryArray1DSP*>(handle);
  return new falcon_core::physics::device_structures::ConnectionsSP(
      self->raw_central_gates());
  FALCON_C_API_END(nullptr)
}

DotGatesWithNeighborsHandle GateGeometryArray1D_central_dot_gates(
    GateGeometryArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_central_dot_gates: handle cannot be null");
  }
  GateGeometryArray1DSP self = *static_cast<GateGeometryArray1DSP*>(handle);
  return new DotGatesWithNeighborsSP(self->central_dot_gates());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle GateGeometryArray1D_ohmics(GateGeometryArray1DHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateGeometryArray1D_ohmics: handle cannot be null");
  }
  GateGeometryArray1DSP self = *static_cast<GateGeometryArray1DSP*>(handle);
  return new falcon_core::physics::device_structures::ConnectionsSP(
      self->ohmics());
  FALCON_C_API_END(nullptr)
}
}
