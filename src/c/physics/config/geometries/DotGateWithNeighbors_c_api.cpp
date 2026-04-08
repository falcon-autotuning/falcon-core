#include "falcon-core/physics/config/geometries/DotGateWithNeighbors_c_api.h"

#include <falcon-core/physics/config/geometries/DotGateWithNeighbors.hpp>

#include "falcon-core/Precompiled_c_api.h"

using namespace falcon_core::physics::config::geometries;
using namespace falcon_core::physics::device_structures;

extern "C" {
DEFINE_C_API_COPY(DotGateWithNeighbors);
DEFINE_C_API_DESTROY(DotGateWithNeighbors);
DEFINE_C_API_EQUAL(DotGateWithNeighbors);
DEFINE_C_API_NOT_EQUAL(DotGateWithNeighbors);
DEFINE_C_API_TO_JSON(DotGateWithNeighbors);
DEFINE_C_API_FROM_JSON(DotGateWithNeighbors);
DotGateWithNeighborsHandle
DotGateWithNeighbors_create_plunger_gate_with_neighbors(
    StringHandle     name,
    ConnectionHandle left_neighbor,
    ConnectionHandle right_neighbor) {
  FALCON_C_API_BEGIN
  if (!name) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_create_plungergatewithneighbors: Name cannot be "
        "null");
  }
  if (!left_neighbor) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_create_plungergatewithneighbors: Left neighbor "
        "cannot be null");
  }
  if (!right_neighbor) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_create_plungergatewithneighbors: Right neighbor "
        "cannot be null");
  }
  std::string  real_name(name->raw, name->length);
  ConnectionSP left_conn  = *static_cast<ConnectionSP*>(left_neighbor);
  ConnectionSP right_conn = *static_cast<ConnectionSP*>(right_neighbor);
  return new DotGateWithNeighborsSP(
      DotGateWithNeighbors::PlungerGateWithNeighbors(
          real_name, left_conn, right_conn));
  FALCON_C_API_END(nullptr)
}

DotGateWithNeighborsHandle
DotGateWithNeighbors_create_barrier_gate_with_neighbors(
    StringHandle     name,
    ConnectionHandle left_neighbor,
    ConnectionHandle right_neighbor) {
  FALCON_C_API_BEGIN
  if (!name) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_create_barriergatewithneighbors: Name cannot be "
        "null");
  }
  if (!left_neighbor) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_create_barriergatewithneighbors: Left neighbor "
        "cannot be null");
  }
  if (!right_neighbor) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_create_barriergatewithneighbors: Right neighbor "
        "cannot be null");
  }
  std::string  real_name(name->raw, name->length);
  ConnectionSP left_conn  = *static_cast<ConnectionSP*>(left_neighbor);
  ConnectionSP right_conn = *static_cast<ConnectionSP*>(right_neighbor);
  return new DotGateWithNeighborsSP(
      DotGateWithNeighbors::BarrierGateWithNeighbors(
          real_name, left_conn, right_conn));
  FALCON_C_API_END(nullptr)
}

// Destructor

// Methods

StringHandle DotGateWithNeighbors_name(DotGateWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_name: handle cannot be null");
  }
  DotGateWithNeighborsSP self = *static_cast<DotGateWithNeighborsSP*>(handle);
  return String_create(self->name().c_str(), self->name().size());
  FALCON_C_API_END(nullptr)
}

StringHandle DotGateWithNeighbors_type(DotGateWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_type: handle cannot be null");
  }
  DotGateWithNeighborsSP self = *static_cast<DotGateWithNeighborsSP*>(handle);
  return String_create(self->type().c_str(), self->type().size());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle DotGateWithNeighbors_left_neighbor(
    DotGateWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_left_neighbor: handle cannot be null");
  }
  DotGateWithNeighborsSP self = *static_cast<DotGateWithNeighborsSP*>(handle);
  return new ConnectionSP(self->left_neighbor());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle DotGateWithNeighbors_right_neighbor(
    DotGateWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_right_neighbor: handle cannot be null");
  }
  DotGateWithNeighborsSP self = *static_cast<DotGateWithNeighborsSP*>(handle);
  return new ConnectionSP(self->right_neighbor());
  FALCON_C_API_END(nullptr)
}

bool DotGateWithNeighbors_is_barrier_gate(DotGateWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_is_barrier_gate: handle cannot be null");
  }
  DotGateWithNeighborsSP self = *static_cast<DotGateWithNeighborsSP*>(handle);
  return self->is_barrier_gate();
  FALCON_C_API_END(false)
}

bool DotGateWithNeighbors_is_plunger_gate(DotGateWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_is_plunger_gate: handle cannot be null");
  }
  DotGateWithNeighborsSP self = *static_cast<DotGateWithNeighborsSP*>(handle);
  return self->is_plunger_gate();
  FALCON_C_API_END(false)
}

// Serialization (from Song)
}
