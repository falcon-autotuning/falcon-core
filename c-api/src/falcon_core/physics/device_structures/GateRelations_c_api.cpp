#include "falcon_core/physics/device_structures/GateRelations_c_api.h"

#include <falcon_core/physics/device_structures/GateRelations.hpp>
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::generic;

extern "C" {

GateRelationsHandle GateRelations_create_empty() { return new GateRelations(); }

GateRelationsHandle GateRelations_create(
    const ListPairConnectionConnectionsHandle items) {
  auto* raw_list = static_cast<List<Pair<Connection, Connections>>*>(items);

  std::vector<std::pair<ConnectionSP, ConnectionsSP>> vec;
  for (const auto& item : *raw_list) {
    vec.push_back(std::make_pair(item->first(), item->second()));
  }

  return new GateRelations(vec);
}

void GateRelations_destroy(GateRelationsHandle handle) {
  delete static_cast<GateRelations*>(handle);
}

void GateRelations_insert_or_assign(GateRelationsHandle handle,
                                    ConnectionHandle    key,
                                    ConnectionsHandle   value) {
  static_cast<GateRelations*>(handle)->insert_or_assign(
      std::shared_ptr<Connection>(static_cast<Connection*>(key),
                                  [](Connection*) {}),
      std::shared_ptr<Connections>(static_cast<Connections*>(value),
                                   [](Connections*) {}));
}

void GateRelations_insert(GateRelationsHandle handle,
                          ConnectionHandle    key,
                          ConnectionsHandle   value) {
  static_cast<GateRelations*>(handle)->insert(
      std::shared_ptr<Connection>(static_cast<Connection*>(key),
                                  [](Connection*) {}),
      std::shared_ptr<Connections>(static_cast<Connections*>(value),
                                   [](Connections*) {}));
}

int GateRelations_at(GateRelationsHandle handle, ConnectionHandle key) {
  auto it =
      static_cast<GateRelations*>(handle)->find(std::shared_ptr<Connection>(
          static_cast<Connection*>(key), [](Connection*) {}));
  if (it != static_cast<GateRelations*>(handle)->end()) {
    return 1;  // Found
  } else {
    return 0;  // Not found
  }
}

void GateRelations_erase(GateRelationsHandle handle, ConnectionHandle key) {
  static_cast<GateRelations*>(handle)->erase(std::shared_ptr<Connection>(
      static_cast<Connection*>(key), [](Connection*) {}));
}

size_t GateRelations_size(GateRelationsHandle handle) {
  return static_cast<GateRelations*>(handle)->size();
}

bool GateRelations_empty(GateRelationsHandle handle) {
  return static_cast<GateRelations*>(handle)->empty();
}

void GateRelations_clear(GateRelationsHandle handle) {
  static_cast<GateRelations*>(handle)->clear();
}

bool GateRelations_contains(GateRelationsHandle handle, ConnectionHandle key) {
  return static_cast<GateRelations*>(handle)->contains(
      std::shared_ptr<Connection>(static_cast<Connection*>(key),
                                  [](Connection*) {}));
}

ListConnectionHandle GateRelations_keys(GateRelationsHandle handle) {
  ListSP<Connection> keys = static_cast<GateRelations*>(handle)->keys();
  return new List<Connection>(*keys);
}

ListConnectionsHandle GateRelations_values(GateRelationsHandle handle) {
  ListSP<Connections> values = static_cast<GateRelations*>(handle)->values();
  return new List<Connections>(*values);
}

ListPairConnectionConnectionsHandle GateRelations_items(
    GateRelationsHandle handle) {
  List<Pair<Connection, Connections>> items =
      static_cast<GateRelations*>(handle)->items();
  return new List<Pair<Connection, Connections>>(items);
}

bool GateRelations_equal(GateRelationsHandle a, GateRelationsHandle b) {
  return *(static_cast<GateRelations*>(a)) == *(static_cast<GateRelations*>(b));
}

bool GateRelations_not_equal(GateRelationsHandle a, GateRelationsHandle b) {
  return *(static_cast<GateRelations*>(a)) != *(static_cast<GateRelations*>(b));
}

const char* GateRelations_to_json_string(GateRelationsHandle handle) {
  static thread_local std::string json;
  json = static_cast<GateRelations*>(handle)->to_json_string();
  return json.c_str();
}

GateRelationsHandle GateRelations_from_json_string(const char* json) {
  auto ptr = GateRelations::from_json_string<GateRelations>(std::string(json));
  return new GateRelations(*ptr);
}
}
