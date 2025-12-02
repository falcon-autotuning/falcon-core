#include "falcon_core/physics/config/geometries/DotGateWithNeighbors_c_api.h"

#include <falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"

using namespace falcon_core::physics::config::geometries;
using namespace falcon_core::physics::device_structures;

extern "C" {
DotGateWithNeighborsHandle DotGateWithNeighbors_create_plungergatewithneighbors(
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
  ConnectionSP left_conn =
      std::make_shared<Connection>(*static_cast<Connection*>(left_neighbor));
  ConnectionSP right_conn =
      std::make_shared<Connection>(*static_cast<Connection*>(right_neighbor));
  return new DotGateWithNeighbors(
      *DotGateWithNeighbors::PlungerGateWithNeighbors(
          real_name, left_conn, right_conn));
  FALCON_C_API_END(nullptr)
}

DotGateWithNeighborsHandle DotGateWithNeighbors_create_barriergatewithneighbors(
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
  ConnectionSP left_conn =
      std::make_shared<Connection>(*static_cast<Connection*>(left_neighbor));
  ConnectionSP right_conn =
      std::make_shared<Connection>(*static_cast<Connection*>(right_neighbor));
  return new DotGateWithNeighbors(
      *DotGateWithNeighbors::BarrierGateWithNeighbors(
          real_name, left_conn, right_conn));
  FALCON_C_API_END(nullptr)
}

// Destructor
void DotGateWithNeighbors_destroy(DotGateWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_destroy: handle cannot be null");
  }
  delete static_cast<DotGateWithNeighbors*>(handle);
  FALCON_C_API_END()
}

// Methods
bool DotGateWithNeighbors_equal(DotGateWithNeighborsHandle handle,
                                DotGateWithNeighborsHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_equal: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_equal: other cannot be null");
  }
  DotGateWithNeighbors self       = *static_cast<DotGateWithNeighbors*>(handle);
  DotGateWithNeighbors real_other = *static_cast<DotGateWithNeighbors*>(other);
  return self == real_other;
  FALCON_C_API_END(false)
}

bool DotGateWithNeighbors_not_equal(DotGateWithNeighborsHandle handle,
                                    DotGateWithNeighborsHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_not_equal: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_not_equal: other cannot be null");
  }
  DotGateWithNeighbors self       = *static_cast<DotGateWithNeighbors*>(handle);
  DotGateWithNeighbors real_other = *static_cast<DotGateWithNeighbors*>(other);
  return self != real_other;
  FALCON_C_API_END(false)
}

StringHandle DotGateWithNeighbors_name(DotGateWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_name: handle cannot be null");
  }
  DotGateWithNeighbors self = *static_cast<DotGateWithNeighbors*>(handle);
  return String_create(self.name().c_str(), self.name().size());
  FALCON_C_API_END(nullptr)
}

StringHandle DotGateWithNeighbors_type(DotGateWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_type: handle cannot be null");
  }
  DotGateWithNeighbors self = *static_cast<DotGateWithNeighbors*>(handle);
  return String_create(self.type().c_str(), self.type().size());
  FALCON_C_API_END(nullptr)
}

ConnectionHandle DotGateWithNeighbors_left_neighbor(
    DotGateWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_left_neighbor: handle cannot be null");
  }
  DotGateWithNeighbors self = *static_cast<DotGateWithNeighbors*>(handle);
  return new Connection(*(self.left_neighbor()));
  FALCON_C_API_END(nullptr)
}

ConnectionHandle DotGateWithNeighbors_right_neighbor(
    DotGateWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_right_neighbor: handle cannot be null");
  }
  DotGateWithNeighbors self = *static_cast<DotGateWithNeighbors*>(handle);
  return new Connection(*(self.right_neighbor()));
  FALCON_C_API_END(nullptr)
}

bool DotGateWithNeighbors_is_barrier_gate(DotGateWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_is_barrier_gate: handle cannot be null");
  }
  DotGateWithNeighbors self = *static_cast<DotGateWithNeighbors*>(handle);
  return self.is_barrier_gate();
  FALCON_C_API_END(false)
}

bool DotGateWithNeighbors_is_plunger_gate(DotGateWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_is_plunger_gate: handle cannot be null");
  }
  DotGateWithNeighbors self = *static_cast<DotGateWithNeighbors*>(handle);
  return self.is_plunger_gate();
  FALCON_C_API_END(false)
}

// Serialization (from Song)
StringHandle DotGateWithNeighbors_to_json_string(
    DotGateWithNeighborsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_to_json_string: handle cannot be null");
  }
  DotGateWithNeighbors self = *static_cast<DotGateWithNeighbors*>(handle);
  return String_create(self.to_json_string().c_str(),
                       self.to_json_string().size());
  FALCON_C_API_END(nullptr)
}

DotGateWithNeighborsHandle DotGateWithNeighbors_from_json_string(
    StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "DotGateWithNeighbors_from_json_string: json cannot be null");
  }
  std::string real_json(json->raw, json->length);
  return new DotGateWithNeighbors(
      *DotGateWithNeighbors::from_json_string<DotGateWithNeighbors>(real_json));
  FALCON_C_API_END(nullptr)
}
}
