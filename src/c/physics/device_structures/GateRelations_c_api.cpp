#include "falcon-core/physics/device_structures/GateRelations_c_api.h"

#include <falcon-core/physics/device_structures/GateRelations.hpp>

#include "falcon-core/Precompiled_c_api.h"

using namespace falcon_core::physics::device_structures;
using namespace falcon_core::generic;

extern "C" {
DEFINE_C_API_COPY(GateRelations);
DEFINE_C_API_DESTROY(GateRelations);
DEFINE_C_API_EQUAL(GateRelations);
DEFINE_C_API_NOT_EQUAL(GateRelations);
DEFINE_C_API_TO_JSON(GateRelations);
DEFINE_C_API_FROM_JSON(GateRelations);
GateRelationsHandle GateRelations_create_empty() {
  FALCON_C_API_BEGIN
  return new GateRelationsSP(std::make_shared<GateRelations>());
  FALCON_C_API_END(nullptr)
}

GateRelationsHandle GateRelations_create(
    const ListPairConnectionConnectionsHandle items) {
  FALCON_C_API_BEGIN
  if (!items) {
    throw std::invalid_argument("GateRelations_create: items cannot be null");
  }
  auto raw_list =
      *(*static_cast<ListSP<Pair<Connection, Connections>>*>(items));

  std::vector<std::pair<ConnectionSP, ConnectionsSP>> vec;
  for (const auto& item : raw_list) {
    vec.push_back(std::make_pair(item->first(), item->second()));
  }

  return new GateRelationsSP(std::make_shared<GateRelations>(vec));
  FALCON_C_API_END(nullptr)
}

void GateRelations_insert_or_assign(GateRelationsHandle handle,
                                    ConnectionHandle    key,
                                    ConnectionsHandle   value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateRelations_insert_or_assign: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument(
        "GateRelations_insert_or_assign: key cannot be null");
  }
  if (!value) {
    throw std::invalid_argument(
        "GateRelations_insert_or_assign: value cannot be null");
  }
  (*static_cast<GateRelationsSP*>(handle))
      ->insert_or_assign(*static_cast<ConnectionSP*>(key),
                         *static_cast<ConnectionsSP*>(value));
  FALCON_C_API_END()
}

void GateRelations_insert(GateRelationsHandle handle,
                          ConnectionHandle    key,
                          ConnectionsHandle   value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("GateRelations_insert: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument("GateRelations_insert: key cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("GateRelations_insert: value cannot be null");
  }
  (*static_cast<GateRelationsSP*>(handle))
      ->insert(*static_cast<ConnectionSP*>(key),
               *static_cast<ConnectionsSP*>(value));
  FALCON_C_API_END()
}

ConnectionsHandle GateRelations_at(GateRelationsHandle handle,
                                   ConnectionHandle    key) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("GateRelations_at: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument("GateRelations_at: key cannot be null");
  }
  return new ConnectionsSP((*static_cast<GateRelationsSP*>(handle))
                               ->at(*static_cast<ConnectionSP*>(key)));
  FALCON_C_API_END(nullptr)
}

void GateRelations_erase(GateRelationsHandle handle, ConnectionHandle key) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("GateRelations_erase: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument("GateRelations_erase: key cannot be null");
  }
  (*static_cast<GateRelationsSP*>(handle))
      ->erase(*static_cast<ConnectionSP*>(key));
  FALCON_C_API_END()
}

size_t GateRelations_size(GateRelationsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("GateRelations_size: handle cannot be null");
  }
  return (*static_cast<GateRelationsSP*>(handle))->size();
  FALCON_C_API_END(0)
}

bool GateRelations_empty(GateRelationsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("GateRelations_empty: handle cannot be null");
  }
  return (*static_cast<GateRelationsSP*>(handle))->empty();
  FALCON_C_API_END(false)
}

void GateRelations_clear(GateRelationsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("GateRelations_clear: handle cannot be null");
  }
  (*static_cast<GateRelationsSP*>(handle))->clear();
  FALCON_C_API_END()
}

bool GateRelations_contains(GateRelationsHandle handle, ConnectionHandle key) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateRelations_contains: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument("GateRelations_contains: key cannot be null");
  }
  return (*static_cast<GateRelationsSP*>(handle))
      ->contains(*static_cast<ConnectionSP*>(key));
  FALCON_C_API_END(false)
}

ListConnectionHandle GateRelations_keys(GateRelationsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("GateRelations_keys: handle cannot be null");
  }
  ListSP<Connection> keys = (*static_cast<GateRelationsSP*>(handle))->keys();
  return new ListSP<Connection>(keys);
  FALCON_C_API_END(nullptr)
}

ListConnectionsHandle GateRelations_values(GateRelationsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("GateRelations_values: handle cannot be null");
  }
  ListSP<Connections> values =
      (*static_cast<GateRelationsSP*>(handle))->values();
  return new ListSP<Connections>(values);
  FALCON_C_API_END(nullptr)
}

ListPairConnectionConnectionsHandle GateRelations_items(
    GateRelationsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("GateRelations_items: handle cannot be null");
  }
  ListSP<Pair<Connection, Connections>> items =
      (*static_cast<GateRelationsSP*>(handle))->items();
  return new ListSP<Pair<Connection, Connections>>(items);
  FALCON_C_API_END(nullptr)
}
}
