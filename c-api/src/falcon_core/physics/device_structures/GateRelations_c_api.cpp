#include "falcon_core/physics/device_structures/GateRelations_c_api.h"

#include <falcon_core/physics/device_structures/GateRelations.hpp>

#include "falcon_core/generic/ErrorHandling_c_api.h"
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::generic;

extern "C" {
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

void GateRelations_destroy(GateRelationsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("GateRelations_destroy: handle cannot be null");
  }
  delete static_cast<GateRelationsSP*>(handle);
  FALCON_C_API_END()
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

bool GateRelations_equal(GateRelationsHandle handle,
                         GateRelationsHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("GateRelations_equal: handle a cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("GateRelations_equal: handle b cannot be null");
  }
  return *(*static_cast<GateRelationsSP*>(handle)) ==
         *(*static_cast<GateRelationsSP*>(other));
  FALCON_C_API_END(false)
}

bool GateRelations_not_equal(GateRelationsHandle handle,
                             GateRelationsHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateRelations_not_equal: handle a cannot be null");
  }
  if (!other) {
    throw std::invalid_argument(
        "GateRelations_not_equal: handle b cannot be null");
  }
  return *(*static_cast<GateRelationsSP*>(handle)) !=
         *(*static_cast<GateRelationsSP*>(other));
  FALCON_C_API_END(false)
}

StringHandle GateRelations_to_json_string(GateRelationsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "GateRelations_to_json_string: handle cannot be null");
  }
  std::string json = (*static_cast<GateRelationsSP*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

GateRelationsHandle GateRelations_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "GateRelations_from_json_string: json cannot be null");
  }
  auto ptr = GateRelations::from_json_string<GateRelations>(json->raw);
  return new GateRelationsSP(ptr);
  FALCON_C_API_END(nullptr)
}
}
