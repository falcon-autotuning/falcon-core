#include "falcon_core/physics/config/geometries/DotGateWithNeighbors_c_api.h"

#include <falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"

using namespace falcon_core::physics::config::geometries;

extern "C" {

DotGateWithNeighborsHandle DotGateWithNeighbors_create_plungergatewithneighbors(
    StringHandle     name,
    ConnectionHandle left_neighbor,
    ConnectionHandle right_neighbor) {
  std::string real_name(name->raw, name->length);
  falcon_core::physics::device_structures::ConnectionSP left_conn =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              left_neighbor));
  falcon_core::physics::device_structures::ConnectionSP right_conn =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              right_neighbor));
  return new DotGateWithNeighbors(
      *DotGateWithNeighbors::PlungerGateWithNeighbors(
          real_name, left_conn, right_conn));
}

DotGateWithNeighborsHandle DotGateWithNeighbors_create_barriergatewithneighbors(
    StringHandle     name,
    ConnectionHandle left_neighbor,
    ConnectionHandle right_neighbor) {
  std::string real_name(name->raw, name->length);
  falcon_core::physics::device_structures::ConnectionSP left_conn =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              left_neighbor));
  falcon_core::physics::device_structures::ConnectionSP right_conn =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          *static_cast<falcon_core::physics::device_structures::Connection*>(
              right_neighbor));
  return new DotGateWithNeighbors(
      *DotGateWithNeighbors::BarrierGateWithNeighbors(
          real_name, left_conn, right_conn));
}

// Destructor
void DotGateWithNeighbors_destroy(DotGateWithNeighborsHandle handle) {
  delete static_cast<DotGateWithNeighbors*>(handle);
}

// Methods
bool DotGateWithNeighbors_equal(DotGateWithNeighborsHandle handle,
                                DotGateWithNeighborsHandle other) {
  DotGateWithNeighbors self       = *static_cast<DotGateWithNeighbors*>(handle);
  DotGateWithNeighbors real_other = *static_cast<DotGateWithNeighbors*>(other);
  return self == real_other;
}

bool DotGateWithNeighbors_not_equal(DotGateWithNeighborsHandle handle,
                                    DotGateWithNeighborsHandle other) {
  DotGateWithNeighbors self       = *static_cast<DotGateWithNeighbors*>(handle);
  DotGateWithNeighbors real_other = *static_cast<DotGateWithNeighbors*>(other);
  return self != real_other;
}

StringHandle DotGateWithNeighbors_name(DotGateWithNeighborsHandle handle) {
  DotGateWithNeighbors self = *static_cast<DotGateWithNeighbors*>(handle);
  return String_create(self.name().c_str(), self.name().size());
}

StringHandle DotGateWithNeighbors_type(DotGateWithNeighborsHandle handle) {
  DotGateWithNeighbors self = *static_cast<DotGateWithNeighbors*>(handle);
  return String_create(self.type().c_str(), self.type().size());
}

ConnectionHandle DotGateWithNeighbors_left_neighbor(
    DotGateWithNeighborsHandle handle) {
  DotGateWithNeighbors self = *static_cast<DotGateWithNeighbors*>(handle);
  return new falcon_core::physics::device_structures::Connection(
      *(self.left_neighbor()));
}

ConnectionHandle DotGateWithNeighbors_right_neighbor(
    DotGateWithNeighborsHandle handle) {
  DotGateWithNeighbors self = *static_cast<DotGateWithNeighbors*>(handle);
  return new falcon_core::physics::device_structures::Connection(
      *(self.right_neighbor()));
}

bool DotGateWithNeighbors_is_barrier_gate(DotGateWithNeighborsHandle handle) {
  DotGateWithNeighbors self = *static_cast<DotGateWithNeighbors*>(handle);
  return self.is_barrier_gate();
}

bool DotGateWithNeighbors_is_plunger_gate(DotGateWithNeighborsHandle handle) {
  DotGateWithNeighbors self = *static_cast<DotGateWithNeighbors*>(handle);
  return self.is_plunger_gate();
}

// Serialization (from Song)
StringHandle DotGateWithNeighbors_to_json_string(
    DotGateWithNeighborsHandle handle) {
  DotGateWithNeighbors self = *static_cast<DotGateWithNeighbors*>(handle);
  return String_create(self.to_json_string().c_str(),
                       self.to_json_string().size());
}

DotGateWithNeighborsHandle DotGateWithNeighbors_from_json_string(
    StringHandle json) {
  std::string real_json(json->raw, json->length);
  return new DotGateWithNeighbors(
      *DotGateWithNeighbors::from_json_string<DotGateWithNeighbors>(real_json));
}

#ifdef __cplusplus
}
#endif
