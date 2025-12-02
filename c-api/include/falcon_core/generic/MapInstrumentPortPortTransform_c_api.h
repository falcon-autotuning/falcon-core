#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairInstrumentPortPortTransform_c_api.h"
#include "falcon_core/generic/ListInstrumentPort_c_api.h"
#include "falcon_core/generic/ListPortTransform_c_api.h"
#include "falcon_core/generic/ListPairInstrumentPortPortTransform_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapInstrumentPortPortTransformHandle;
// Function declarations

MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_create_empty();
MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_create(const PairInstrumentPortPortTransformHandle* data, size_t count);
void MapInstrumentPortPortTransform_destroy(MapInstrumentPortPortTransformHandle handle);
void MapInstrumentPortPortTransform_insert_or_assign(MapInstrumentPortPortTransformHandle handle, const InstrumentPortHandle key, const PortTransformHandle value);
void MapInstrumentPortPortTransform_insert(MapInstrumentPortPortTransformHandle handle, const InstrumentPortHandle key, const PortTransformHandle value);
PortTransformHandle MapInstrumentPortPortTransform_at(MapInstrumentPortPortTransformHandle handle, const InstrumentPortHandle key);
void MapInstrumentPortPortTransform_erase(MapInstrumentPortPortTransformHandle handle, const InstrumentPortHandle key);
size_t MapInstrumentPortPortTransform_size(MapInstrumentPortPortTransformHandle handle);
bool MapInstrumentPortPortTransform_empty(MapInstrumentPortPortTransformHandle handle);
void MapInstrumentPortPortTransform_clear(MapInstrumentPortPortTransformHandle handle);
bool MapInstrumentPortPortTransform_contains(MapInstrumentPortPortTransformHandle handle, const InstrumentPortHandle key);
/* AUTO-DOC from cpp: MapInstrumentPortPortTransform_keys | falcon_core::generic::Map::keys */
/**
 * @brief Return the keys of the Map.
 */
ListInstrumentPortHandle MapInstrumentPortPortTransform_keys(MapInstrumentPortPortTransformHandle handle);
/* AUTO-DOC from cpp: MapInstrumentPortPortTransform_values | falcon_core::generic::Map::values */
/**
 * @brief Return the values of the Map.
 */
ListPortTransformHandle MapInstrumentPortPortTransform_values(MapInstrumentPortPortTransformHandle handle);
ListPairInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_items(MapInstrumentPortPortTransformHandle handle);
bool MapInstrumentPortPortTransform_equal(MapInstrumentPortPortTransformHandle a, MapInstrumentPortPortTransformHandle b);
bool MapInstrumentPortPortTransform_not_equal(MapInstrumentPortPortTransformHandle a, MapInstrumentPortPortTransformHandle b);
// Serialization (from Song)
StringHandle      MapInstrumentPortPortTransform_to_json_string(MapInstrumentPortPortTransformHandle handle);
MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif