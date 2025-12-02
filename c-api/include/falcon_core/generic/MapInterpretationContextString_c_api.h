#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairInterpretationContextString_c_api.h"
#include "falcon_core/generic/ListString_c_api.h"
#include "falcon_core/generic/ListInterpretationContext_c_api.h"
#include "falcon_core/generic/ListPairInterpretationContextString_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapInterpretationContextStringHandle;
// Function declarations

MapInterpretationContextStringHandle MapInterpretationContextString_create_empty();
MapInterpretationContextStringHandle MapInterpretationContextString_create(const PairInterpretationContextStringHandle* data, size_t count);
void MapInterpretationContextString_destroy(MapInterpretationContextStringHandle handle);
void MapInterpretationContextString_insert_or_assign(MapInterpretationContextStringHandle handle, const InterpretationContextHandle key, const StringHandle value);
void MapInterpretationContextString_insert(MapInterpretationContextStringHandle handle, const InterpretationContextHandle key, const StringHandle value);
StringHandle MapInterpretationContextString_at(MapInterpretationContextStringHandle handle, const InterpretationContextHandle key);
void MapInterpretationContextString_erase(MapInterpretationContextStringHandle handle, const InterpretationContextHandle key);
size_t MapInterpretationContextString_size(MapInterpretationContextStringHandle handle);
bool MapInterpretationContextString_empty(MapInterpretationContextStringHandle handle);
void MapInterpretationContextString_clear(MapInterpretationContextStringHandle handle);
bool MapInterpretationContextString_contains(MapInterpretationContextStringHandle handle, const InterpretationContextHandle key);
/* AUTO-DOC from cpp: MapInterpretationContextString_keys | falcon_core::generic::Map::keys */
/**
 * @brief Return the keys of the Map.
 */
ListInterpretationContextHandle MapInterpretationContextString_keys(MapInterpretationContextStringHandle handle);
/* AUTO-DOC from cpp: MapInterpretationContextString_values | falcon_core::generic::Map::values */
/**
 * @brief Return the values of the Map.
 */
ListStringHandle MapInterpretationContextString_values(MapInterpretationContextStringHandle handle);
ListPairInterpretationContextStringHandle MapInterpretationContextString_items(MapInterpretationContextStringHandle handle);
bool MapInterpretationContextString_equal(MapInterpretationContextStringHandle a, MapInterpretationContextStringHandle b);
bool MapInterpretationContextString_not_equal(MapInterpretationContextStringHandle a, MapInterpretationContextStringHandle b);
// Serialization (from Song)
StringHandle      MapInterpretationContextString_to_json_string(MapInterpretationContextStringHandle handle);
MapInterpretationContextStringHandle MapInterpretationContextString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif