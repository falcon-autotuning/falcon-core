#include "falcon_core/physics/device_structures/GateRelations_c_api.h"

#include <falcon_core/physics/device_structures/GateRelations.hpp>
using namespace falcon_core::physics::device_structures;
using namespace falcon_core::generic;

extern "C" {

GateRelationsHandle GateRelations_create_empty() { return new GateRelations(); }

GateRelationsHandle GateRelations_create(
    const ListPairConnectionConnectionsHandle items) {
  if (!items) {
    throw std::invalid_argument("GateRelations_create: items cannot be null");
  }
  auto* raw_list = static_cast<List<Pair<Connection, Connections>>*>(items);

  std::vector<std::pair<ConnectionSP, ConnectionsSP>> vec;
  for (const auto& item : *raw_list) {
    vec.push_back(std::make_pair(item->first(), item->second()));
  }

  return new GateRelations(vec);
}

void GateRelations_destroy(GateRelationsHandle handle) {
  if (!handle) {
    throw std::invalid_argument("GateRelations_destroy: handle cannot be null");
  }
  delete static_cast<GateRelations*>(handle);
}

void GateRelations_insert_or_assign(GateRelationsHandle handle,
                                    ConnectionHandle    key,
                                    ConnectionsHandle   value) {
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
  static_cast<GateRelations*>(handle)->insert_or_assign(
      std::shared_ptr<Connection>(static_cast<Connection*>(key),
                                  [](Connection*) {}),
      std::shared_ptr<Connections>(static_cast<Connections*>(value),
                                   [](Connections*) {}));
}

void GateRelations_insert(GateRelationsHandle handle,
                          ConnectionHandle    key,
                          ConnectionsHandle   value) {
  if (!handle) {
    throw std::invalid_argument("GateRelations_insert: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument("GateRelations_insert: key cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("GateRelations_insert: value cannot be null");
  }
  static_cast<GateRelations*>(handle)->insert(
      std::shared_ptr<Connection>(static_cast<Connection*>(key),
                                  [](Connection*) {}),
      std::shared_ptr<Connections>(static_cast<Connections*>(value),
                                   [](Connections*) {}));
}

ConnectionsHandle GateRelations_at(GateRelationsHandle handle,
                                   ConnectionHandle    key) {
  if (!handle) {
    throw std::invalid_argument("GateRelations_at: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument("GateRelations_at: key cannot be null");
  }
  return new Connections(
      static_cast<GateRelations*>(handle)->at(std::shared_ptr<Connection>(
          static_cast<Connection*>(key), [](Connection*) {})));
}

void GateRelations_erase(GateRelationsHandle handle, ConnectionHandle key) {
  if (!handle) {
    throw std::invalid_argument("GateRelations_erase: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument("GateRelations_erase: key cannot be null");
  }
  static_cast<GateRelations*>(handle)->erase(std::shared_ptr<Connection>(
      static_cast<Connection*>(key), [](Connection*) {}));
}

size_t GateRelations_size(GateRelationsHandle handle) {
  if (!handle) {
    throw std::invalid_argument("GateRelations_size: handle cannot be null");
  }
  return static_cast<GateRelations*>(handle)->size();
}

bool GateRelations_empty(GateRelationsHandle handle) {
  if (!handle) {
    throw std::invalid_argument("GateRelations_empty: handle cannot be null");
  }
  return static_cast<GateRelations*>(handle)->empty();
}

void GateRelations_clear(GateRelationsHandle handle) {
  if (!handle) {
    throw std::invalid_argument("GateRelations_clear: handle cannot be null");
  }
  static_cast<GateRelations*>(handle)->clear();
}

bool GateRelations_contains(GateRelationsHandle handle, ConnectionHandle key) {
  if (!handle) {
    throw std::invalid_argument(
        "GateRelations_contains: handle cannot be null");
  }
  if (!key) {
    throw std::invalid_argument("GateRelations_contains: key cannot be null");
  }
  return static_cast<GateRelations*>(handle)->contains(
      std::shared_ptr<Connection>(static_cast<Connection*>(key),
                                  [](Connection*) {}));
}

ListConnectionHandle GateRelations_keys(GateRelationsHandle handle) {
  if (!handle) {
    throw std::invalid_argument("GateRelations_keys: handle cannot be null");
  }
  ListSP<Connection> keys = static_cast<GateRelations*>(handle)->keys();
  return new List<Connection>(*keys);
}

ListConnectionsHandle GateRelations_values(GateRelationsHandle handle) {
  if (!handle) {
    throw std::invalid_argument("GateRelations_values: handle cannot be null");
  }
  ListSP<Connections> values = static_cast<GateRelations*>(handle)->values();
  return new List<Connections>(*values);
}

ListPairConnectionConnectionsHandle GateRelations_items(
    GateRelationsHandle handle) {
  if (!handle) {
    throw std::invalid_argument("GateRelations_items: handle cannot be null");
  }
  List<Pair<Connection, Connections>> items =
      static_cast<GateRelations*>(handle)->items();
  return new List<Pair<Connection, Connections>>(items);
}

bool GateRelations_equal(GateRelationsHandle a, GateRelationsHandle b) {
  if (!a) {
    throw std::invalid_argument("GateRelations_equal: handle a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("GateRelations_equal: handle b cannot be null");
  }
  return *(static_cast<GateRelations*>(a)) == *(static_cast<GateRelations*>(b));
}

bool GateRelations_not_equal(GateRelationsHandle a, GateRelationsHandle b) {
  if (!a) {
    throw std::invalid_argument(
        "GateRelations_not_equal: handle a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument(
        "GateRelations_not_equal: handle b cannot be null");
  }
  return *(static_cast<GateRelations*>(a)) != *(static_cast<GateRelations*>(b));
}

StringHandle GateRelations_to_json_string(GateRelationsHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "GateRelations_to_json_string: handle cannot be null");
  }
  std::string json = static_cast<GateRelations*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

GateRelationsHandle GateRelations_from_json_string(StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "GateRelations_from_json_string: json cannot be null");
  }
  auto ptr = GateRelations::from_json_string<GateRelations>(json->raw);
  return new GateRelations(*ptr);
}
}
