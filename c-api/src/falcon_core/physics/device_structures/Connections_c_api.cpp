#include "falcon_core/physics/device_structures/Connections_c_api.h"

#include <cstddef>
#include <falcon_core/physics/device_structures/Connections.hpp>

#include "falcon_core/generic/List.hpp"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
using namespace falcon_core::physics::device_structures;

extern "C" {

ConnectionsHandle Connections_create_empty() { return new Connections(); }

ConnectionsHandle Connections_create(const ListConnectionHandle items) {
  auto list_ptr = static_cast<falcon_core::generic::List<Connection>*>(items);
  return new Connections(list_ptr->items());
}

void Connections_destroy(ConnectionsHandle handle) {
  delete static_cast<Connections*>(handle);
}

bool Connections_is_gates(ConnectionsHandle handle) {
  return static_cast<Connections*>(handle)->is_gates();
}

bool Connections_is_ohmics(ConnectionsHandle handle) {
  return static_cast<Connections*>(handle)->is_ohmics();
}

bool Connections_is_dot_gates(ConnectionsHandle handle) {
  return static_cast<Connections*>(handle)->is_dot_gates();
}

bool Connections_is_plunger_gates(ConnectionsHandle handle) {
  return static_cast<Connections*>(handle)->is_plunger_gates();
}

bool Connections_is_barrier_gates(ConnectionsHandle handle) {
  return static_cast<Connections*>(handle)->is_barrier_gates();
}

bool Connections_is_reservoir_gates(ConnectionsHandle handle) {
  return static_cast<Connections*>(handle)->is_reservoir_gates();
}

bool Connections_is_screening_gates(ConnectionsHandle handle) {
  return static_cast<Connections*>(handle)->is_screening_gates();
}

ConnectionsHandle Connections_intersection(ConnectionsHandle handle,
                                           ConnectionsHandle other) {
  auto result = static_cast<Connections*>(handle)->intersection(
      std::shared_ptr<Connections>(static_cast<Connections*>(other),
                                   [](Connections*) {}));
  return new Connections(*result);
}

void Connections_push_back(ConnectionsHandle handle, ConnectionHandle value) {
  static_cast<Connections*>(handle)->push_back(std::shared_ptr<Connection>(
      static_cast<Connection*>(value), [](Connection*) {}));
}

size_t Connections_size(ConnectionsHandle handle) {
  return static_cast<Connections*>(handle)->size();
}

bool Connections_empty(ConnectionsHandle handle) {
  return static_cast<Connections*>(handle)->empty();
}

void Connections_erase_at(ConnectionsHandle handle, size_t idx) {
  static_cast<Connections*>(handle)->erase_at(idx);
}

void Connections_clear(ConnectionsHandle handle) {
  static_cast<Connections*>(handle)->clear();
}

ConnectionHandle Connections_at(ConnectionsHandle handle, size_t idx) {
  auto conn = static_cast<Connections*>(handle)->at(idx);
  return static_cast<ConnectionHandle>(conn.get());
}

ListConnectionHandle Connections_items(ConnectionsHandle handle) {
  auto items = static_cast<Connections*>(handle)->items();
  return new falcon_core::generic::List<Connection>(items);
}

bool Connections_contains(ConnectionsHandle handle, ConnectionHandle value) {
  return static_cast<Connections*>(handle)->contains(
      std::shared_ptr<Connection>(static_cast<Connection*>(value),
                                  [](Connection*) {}));
}

size_t Connections_index(ConnectionsHandle handle, ConnectionHandle value) {
  return static_cast<Connections*>(handle)->index(std::shared_ptr<Connection>(
      static_cast<Connection*>(value), [](Connection*) {}));
}

bool Connections_equal(ConnectionsHandle a, ConnectionsHandle b) {
  return *(static_cast<Connections*>(a)) == *(static_cast<Connections*>(b));
}

bool Connections_not_equal(ConnectionsHandle a, ConnectionsHandle b) {
  return *(static_cast<Connections*>(a)) != *(static_cast<Connections*>(b));
}

StringHandle Connections_to_json_string(ConnectionsHandle handle) {
  std::string json = static_cast<Connections*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

ConnectionsHandle Connections_from_json_string(StringHandle json) {
  auto ptr = Connections::from_json_string<Connections>(json->raw);
  return new Connections(*ptr);
}
}
