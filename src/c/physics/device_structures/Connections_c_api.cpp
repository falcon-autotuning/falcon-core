#include "falcon-core/physics/device_structures/Connections_c_api.h"

#include <cstddef>
#include <falcon-core/physics/device_structures/Connections.hpp>

#include "falcon-core/Precompiled_c_api.h"
using namespace falcon_core::physics::device_structures;

extern "C" {
DEFINE_C_API_COPY(Connections);
DEFINE_C_API_DESTROY(Connections);
DEFINE_C_API_EQUAL(Connections);
DEFINE_C_API_NOT_EQUAL(Connections);
DEFINE_C_API_TO_JSON(Connections);
DEFINE_C_API_FROM_JSON(Connections);
ConnectionsHandle Connections_create_empty() {
  FALCON_C_API_BEGIN
  return new ConnectionsSP(std::make_shared<Connections>());
  FALCON_C_API_END(nullptr)
}

ConnectionsHandle Connections_create(const ListConnectionHandle items) {
  FALCON_C_API_BEGIN
  if (!items) {
    throw std::invalid_argument("Connections_create: items cannot be null");
  }
  auto list_ptr =
      *static_cast<falcon_core::generic::ListSP<Connection>*>(items);
  return new ConnectionsSP(std::make_shared<Connections>(list_ptr->items()));
  FALCON_C_API_END(nullptr)
}

bool Connections_is_gates(ConnectionsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Connections_is_gates: handle cannot be null");
  }
  return (*static_cast<ConnectionsSP*>(handle))->is_gates();
  FALCON_C_API_END(false)
}

bool Connections_is_ohmics(ConnectionsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Connections_is_ohmics: handle cannot be null");
  }
  return (*static_cast<ConnectionsSP*>(handle))->is_ohmics();
  FALCON_C_API_END(false)
}

bool Connections_is_dot_gates(ConnectionsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Connections_is_dot_gates: handle cannot be null");
  }
  return (*static_cast<ConnectionsSP*>(handle))->is_dot_gates();
  FALCON_C_API_END(false)
}

bool Connections_is_plunger_gates(ConnectionsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Connections_is_plunger_gates: handle cannot be null");
  }
  return (*static_cast<ConnectionsSP*>(handle))->is_plunger_gates();
  FALCON_C_API_END(false)
}

bool Connections_is_barrier_gates(ConnectionsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Connections_is_barrier_gates: handle cannot be null");
  }
  return (*static_cast<ConnectionsSP*>(handle))->is_barrier_gates();
  FALCON_C_API_END(false)
}

bool Connections_is_reservoir_gates(ConnectionsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Connections_is_reservoir_gates: handle cannot be null");
  }
  return (*static_cast<ConnectionsSP*>(handle))->is_reservoir_gates();
  FALCON_C_API_END(false)
}

bool Connections_is_screening_gates(ConnectionsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Connections_is_screening_gates: handle cannot be null");
  }
  return (*static_cast<ConnectionsSP*>(handle))->is_screening_gates();
  FALCON_C_API_END(false)
}

ConnectionsHandle Connections_intersection(ConnectionsHandle handle,
                                           ConnectionsHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Connections_is_intersection: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "Connections_is_intersection: other cannot be null");
  }
  auto result = (*static_cast<ConnectionsSP*>(handle))
                    ->intersection(*static_cast<ConnectionsSP*>(other));
  return new ConnectionsSP(result);
  FALCON_C_API_END(nullptr)
}

void Connections_push_back(ConnectionsHandle handle, ConnectionHandle value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Connections_push_back: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Connections_push_back: value cannot be null");
  }
  ConnectionsSP connections    = *static_cast<ConnectionsSP*>(handle);
  ConnectionSP  connection_ptr = *static_cast<ConnectionSP*>(value);
  connections->push_back(connection_ptr);
  FALCON_C_API_END()
}

size_t Connections_size(ConnectionsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Connections_size: handle cannot be null");
  }
  return (*static_cast<ConnectionsSP*>(handle))->size();
  FALCON_C_API_END(0)
}

bool Connections_empty(ConnectionsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Connections_empty: handle cannot be null");
  }
  return (*static_cast<ConnectionsSP*>(handle))->empty();
  FALCON_C_API_END(false)
}

void Connections_erase_at(ConnectionsHandle handle, size_t idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Connections_erase_at: handle cannot be null");
  }
  (*static_cast<ConnectionsSP*>(handle))->erase_at(idx);
  FALCON_C_API_END()
}

void Connections_clear(ConnectionsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Connections_clear: handle cannot be null");
  }
  (*static_cast<ConnectionsSP*>(handle))->clear();
  FALCON_C_API_END()
}

ConnectionHandle Connections_at(ConnectionsHandle handle, size_t idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Connections_at: handle cannot be null");
  }
  auto conn = (*static_cast<ConnectionsSP*>(handle))->at(idx);
  return new ConnectionSP(conn);
  FALCON_C_API_END(nullptr)
}

ListConnectionHandle Connections_items(ConnectionsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Connections_items: handle cannot be null");
  }
  auto items = (*static_cast<ConnectionsSP*>(handle))->items();
  return new falcon_core::generic::ListSP<Connection>(
      std::make_shared<falcon_core::generic::List<Connection>>(items));
  FALCON_C_API_END(nullptr)
}

bool Connections_contains(ConnectionsHandle handle, ConnectionHandle value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Connections_contains: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Connections_contains: value cannot be null");
  }
  return (*static_cast<ConnectionsSP*>(handle))
      ->contains(*static_cast<ConnectionSP*>(value));
  FALCON_C_API_END(false)
}

size_t Connections_index(ConnectionsHandle handle, ConnectionHandle value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Connections_index: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Connections_index: value cannot be null");
  }
  return (*static_cast<ConnectionsSP*>(handle))
      ->index(*static_cast<ConnectionSP*>(value));
  FALCON_C_API_END(0)
}
}
