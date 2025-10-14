#include "falcon_core/generic/Map_c_api.h"

#include <falcon_core/generic/Map.hpp>
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>

#include "falcon_core/generic/List_c_api.h"
#include "falcon_core/generic/Pair_c_api.h"

using namespace falcon_core::generic;
using namespace falcon_core::physics::device_structures;

// Implementation for all map list types

MapIntIntHandle MapIntInt_create_empty() {
  return new std::shared_ptr<Map<int, int>>(std::make_shared<Map<int, int>>());
}

MapIntIntHandle MapIntInt_create(const PairIntIntHandle* data, size_t count) {
  std::vector<PairSP<int, int>> vec(data, data + count);
  return new std::shared_ptr<Map<int, int>>(
      std::make_shared<Map<int, int>>(vec));
}

void MapIntInt_destroy(MapIntIntHandle handle) {
  delete static_cast<std::shared_ptr<Map<int, int>>*>(handle);
}

void MapIntInt_insert_or_assign(MapIntIntHandle handle,
                                const int       key,
                                const int       value) {
  auto correct_key   = key;
  auto correct_value = value;
  (*static_cast<std::shared_ptr<Map<int, int>>*>(handle))
      ->insert_or_assign(correct_key, correct_value);
}

void MapIntInt_insert(MapIntIntHandle handle, const int key, const int value) {
  auto correct_key   = key;
  auto correct_value = value;
  (*static_cast<std::shared_ptr<Map<int, int>>*>(handle))
      ->insert(correct_key, correct_value);
}

int MapIntInt_at(MapIntIntHandle handle, const int key) {
  auto correct_key = key;
  return (*static_cast<std::shared_ptr<Map<int, int>>*>(handle))
      ->at(correct_key);
}

void MapIntInt_erase(MapIntIntHandle handle, const int key) {
  auto correct_key = key;
  return (*static_cast<std::shared_ptr<Map<int, int>>*>(handle))
      ->erase(correct_key);
}

size_t MapIntInt_size(MapIntIntHandle handle) {
  return (*static_cast<std::shared_ptr<Map<int, int>>*>(handle))->size();
}

bool MapIntInt_empty(MapIntIntHandle handle) {
  return (*static_cast<std::shared_ptr<Map<int, int>>*>(handle))->empty();
}

void MapIntInt_clear(MapIntIntHandle handle) {
  return (*static_cast<std::shared_ptr<Map<int, int>>*>(handle))->clear();
}

bool MapIntInt_contains(MapIntIntHandle handle, int key) {
  auto correct_key = key;
  return (*static_cast<std::shared_ptr<Map<int, int>>*>(handle))
      ->contains(correct_key);
}

ListIntHandle MapIntInt_keys(MapIntIntHandle handle) {
  auto& map     = *static_cast<std::shared_ptr<Map<int, int>>*>(handle);
  auto  keys_sp = map->keys();  // shared_ptr<List<Key>>
  return new std::shared_ptr<List<int>>(keys_sp);
}

ListIntHandle MapIntInt_values(MapIntIntHandle handle) {
  auto& map       = *static_cast<std::shared_ptr<Map<int, int>>*>(handle);
  auto  values_sp = map->values();  // shared_ptr<List<Value>>
  return new std::shared_ptr<List<int>>(values_sp);
}

ListPairIntIntHandle MapIntInt_items(MapIntIntHandle handle) {
  auto& map = *static_cast<std::shared_ptr<Map<int, int>>*>(handle);
  List<Pair<int, int>> items_sp =
      map->items();  // shared_ptr<List<Pair<Key,Value>>>
  return new std::shared_ptr<List<Pair<int, int>>>(
      std::make_shared<List<Pair<int, int>>>(items_sp));
}

bool MapIntInt_equal(MapIntIntHandle a, MapIntIntHandle b) {
  auto& listA = *static_cast<std::shared_ptr<Map<int, int>>*>(a);
  auto& listB = *static_cast<std::shared_ptr<Map<int, int>>*>(b);
  return *listA == *listB;
}

bool MapIntInt_not_equal(MapIntIntHandle a, MapIntIntHandle b) {
  return !MapIntInt_equal(a, b);
}

MapFloatFloatHandle MapFloatFloat_create_empty() {
  return new std::shared_ptr<Map<float, float>>(
      std::make_shared<Map<float, float>>());
}

MapFloatFloatHandle MapFloatFloat_create(const PairFloatFloatHandle* data,
                                         size_t                      count) {
  std::vector<PairSP<float, float>> vec(data, data + count);
  return new std::shared_ptr<Map<float, float>>(
      std::make_shared<Map<float, float>>(vec));
}

void MapFloatFloat_destroy(MapFloatFloatHandle handle) {
  delete static_cast<std::shared_ptr<Map<float, float>>*>(handle);
}

void MapFloatFloat_insert_or_assign(MapFloatFloatHandle handle,
                                    const float         key,
                                    const float         value) {
  auto correct_key   = key;
  auto correct_value = value;
  (*static_cast<std::shared_ptr<Map<float, float>>*>(handle))
      ->insert_or_assign(correct_key, correct_value);
}

void MapFloatFloat_insert(MapFloatFloatHandle handle,
                          const float         key,
                          const float         value) {
  auto correct_key   = key;
  auto correct_value = value;
  (*static_cast<std::shared_ptr<Map<float, float>>*>(handle))
      ->insert(correct_key, correct_value);
}

float MapFloatFloat_at(MapFloatFloatHandle handle, const float key) {
  auto correct_key = key;
  return (*static_cast<std::shared_ptr<Map<float, float>>*>(handle))
      ->at(correct_key);
}

void MapFloatFloat_erase(MapFloatFloatHandle handle, const float key) {
  auto correct_key = key;
  return (*static_cast<std::shared_ptr<Map<float, float>>*>(handle))
      ->erase(correct_key);
}

size_t MapFloatFloat_size(MapFloatFloatHandle handle) {
  return (*static_cast<std::shared_ptr<Map<float, float>>*>(handle))->size();
}

bool MapFloatFloat_empty(MapFloatFloatHandle handle) {
  return (*static_cast<std::shared_ptr<Map<float, float>>*>(handle))->empty();
}

void MapFloatFloat_clear(MapFloatFloatHandle handle) {
  return (*static_cast<std::shared_ptr<Map<float, float>>*>(handle))->clear();
}

bool MapFloatFloat_contains(MapFloatFloatHandle handle, float key) {
  auto correct_key = key;
  return (*static_cast<std::shared_ptr<Map<float, float>>*>(handle))
      ->contains(correct_key);
}

ListFloatHandle MapFloatFloat_keys(MapFloatFloatHandle handle) {
  auto& map     = *static_cast<std::shared_ptr<Map<float, float>>*>(handle);
  auto  keys_sp = map->keys();  // shared_ptr<List<Key>>
  return new std::shared_ptr<List<float>>(keys_sp);
}

ListFloatHandle MapFloatFloat_values(MapFloatFloatHandle handle) {
  auto& map       = *static_cast<std::shared_ptr<Map<float, float>>*>(handle);
  auto  values_sp = map->values();  // shared_ptr<List<Value>>
  return new std::shared_ptr<List<float>>(values_sp);
}

ListPairFloatFloatHandle MapFloatFloat_items(MapFloatFloatHandle handle) {
  auto& map = *static_cast<std::shared_ptr<Map<float, float>>*>(handle);
  List<Pair<float, float>> items_sp =
      map->items();  // shared_ptr<List<Pair<Key,Value>>>
  return new std::shared_ptr<List<Pair<float, float>>>(
      std::make_shared<List<Pair<float, float>>>(items_sp));
}

bool MapFloatFloat_equal(MapFloatFloatHandle a, MapFloatFloatHandle b) {
  auto& listA = *static_cast<std::shared_ptr<Map<float, float>>*>(a);
  auto& listB = *static_cast<std::shared_ptr<Map<float, float>>*>(b);
  return *listA == *listB;
}

bool MapFloatFloat_not_equal(MapFloatFloatHandle a, MapFloatFloatHandle b) {
  return !MapFloatFloat_equal(a, b);
}

MapConnectionFloatHandle MapConnectionFloat_create_empty() {
  return new std::shared_ptr<
      Map<falcon_core::physics::device_structures::Connection, float>>(
      std::make_shared<
          Map<falcon_core::physics::device_structures::Connection, float>>());
}

MapConnectionFloatHandle MapConnectionFloat_create(
    const PairConnectionFloatHandle* data, size_t count) {
  std::vector<
      PairSP<falcon_core::physics::device_structures::Connection, float>>
      vec(data, data + count);
  return new std::shared_ptr<
      Map<falcon_core::physics::device_structures::Connection, float>>(
      std::make_shared<
          Map<falcon_core::physics::device_structures::Connection, float>>(
          vec));
}

void MapConnectionFloat_destroy(MapConnectionFloatHandle handle) {
  delete static_cast<std::shared_ptr<
      Map<falcon_core::physics::device_structures::Connection, float>>*>(
      handle);
}

void MapConnectionFloat_insert_or_assign(MapConnectionFloatHandle handle,
                                         const ConnectionHandle   key,
                                         const float              value) {
  auto temp_key =
      *static_cast<falcon_core::physics::device_structures::Connection*>(key);
  auto correct_key =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          temp_key);
  auto correct_value = value;
  (*static_cast<std::shared_ptr<
       Map<falcon_core::physics::device_structures::Connection, float>>*>(
       handle))
      ->insert_or_assign(correct_key, correct_value);
}

void MapConnectionFloat_insert(MapConnectionFloatHandle handle,
                               const ConnectionHandle   key,
                               const float              value) {
  auto temp_key =
      *static_cast<falcon_core::physics::device_structures::Connection*>(key);
  auto correct_key =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          temp_key);
  auto correct_value = value;
  (*static_cast<std::shared_ptr<
       Map<falcon_core::physics::device_structures::Connection, float>>*>(
       handle))
      ->insert(correct_key, correct_value);
}

float MapConnectionFloat_at(MapConnectionFloatHandle handle,
                            const ConnectionHandle   key) {
  auto temp_key =
      *static_cast<falcon_core::physics::device_structures::Connection*>(key);
  auto correct_key =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          temp_key);
  return (*static_cast<std::shared_ptr<
              Map<falcon_core::physics::device_structures::Connection,
                  float>>*>(handle))
      ->at(correct_key);
}

void MapConnectionFloat_erase(MapConnectionFloatHandle handle,
                              const ConnectionHandle   key) {
  auto temp_key =
      *static_cast<falcon_core::physics::device_structures::Connection*>(key);
  auto correct_key =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          temp_key);
  return (*static_cast<std::shared_ptr<
              Map<falcon_core::physics::device_structures::Connection,
                  float>>*>(handle))
      ->erase(correct_key);
}

size_t MapConnectionFloat_size(MapConnectionFloatHandle handle) {
  return (*static_cast<std::shared_ptr<
              Map<falcon_core::physics::device_structures::Connection,
                  float>>*>(handle))
      ->size();
}

bool MapConnectionFloat_empty(MapConnectionFloatHandle handle) {
  return (*static_cast<std::shared_ptr<
              Map<falcon_core::physics::device_structures::Connection,
                  float>>*>(handle))
      ->empty();
}

void MapConnectionFloat_clear(MapConnectionFloatHandle handle) {
  return (*static_cast<std::shared_ptr<
              Map<falcon_core::physics::device_structures::Connection,
                  float>>*>(handle))
      ->clear();
}

bool MapConnectionFloat_contains(MapConnectionFloatHandle handle,
                                 ConnectionHandle         key) {
  auto temp_key =
      *static_cast<falcon_core::physics::device_structures::Connection*>(key);
  auto correct_key =
      std::make_shared<falcon_core::physics::device_structures::Connection>(
          temp_key);
  return (*static_cast<std::shared_ptr<
              Map<falcon_core::physics::device_structures::Connection,
                  float>>*>(handle))
      ->contains(correct_key);
}

ListConnectionHandle MapConnectionFloat_keys(MapConnectionFloatHandle handle) {
  auto& map = *static_cast<std::shared_ptr<
      Map<falcon_core::physics::device_structures::Connection, float>>*>(
      handle);
  auto keys_sp = map->keys();  // shared_ptr<List<Key>>
  return new std::shared_ptr<
      List<falcon_core::physics::device_structures::Connection>>(keys_sp);
}

ListFloatHandle MapConnectionFloat_values(MapConnectionFloatHandle handle) {
  auto& map = *static_cast<std::shared_ptr<
      Map<falcon_core::physics::device_structures::Connection, float>>*>(
      handle);
  auto values_sp = map->values();  // shared_ptr<List<Value>>
  return new std::shared_ptr<List<float>>(values_sp);
}

ListPairConnectionFloatHandle MapConnectionFloat_items(
    MapConnectionFloatHandle handle) {
  auto& map = *static_cast<std::shared_ptr<
      Map<falcon_core::physics::device_structures::Connection, float>>*>(
      handle);
  List<Pair<falcon_core::physics::device_structures::Connection, float>>
      items_sp = map->items();  // shared_ptr<List<Pair<Key,Value>>>
  return new std::shared_ptr<
      List<Pair<falcon_core::physics::device_structures::Connection, float>>>(
      std::make_shared<List<
          Pair<falcon_core::physics::device_structures::Connection, float>>>(
          items_sp));
}

bool MapConnectionFloat_equal(MapConnectionFloatHandle a,
                              MapConnectionFloatHandle b) {
  auto& listA = *static_cast<std::shared_ptr<
      Map<falcon_core::physics::device_structures::Connection, float>>*>(a);
  auto& listB = *static_cast<std::shared_ptr<
      Map<falcon_core::physics::device_structures::Connection, float>>*>(b);
  return *listA == *listB;
}

bool MapConnectionFloat_not_equal(MapConnectionFloatHandle a,
                                  MapConnectionFloatHandle b) {
  return !MapConnectionFloat_equal(a, b);
}
