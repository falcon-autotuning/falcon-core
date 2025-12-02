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

// @category:allocation
MapInterpretationContextStringHandle MapInterpretationContextString_create_empty();
// @category:allocation
MapInterpretationContextStringHandle MapInterpretationContextString_create(PairInterpretationContextStringHandle* data, size_t count);
// @category:deallocation
void MapInterpretationContextString_destroy(MapInterpretationContextStringHandle handle);
// @category:write
void MapInterpretationContextString_insert_or_assign(MapInterpretationContextStringHandle handle, InterpretationContextHandle key, StringHandle value);
// @category:write
void MapInterpretationContextString_insert(MapInterpretationContextStringHandle handle, InterpretationContextHandle key, StringHandle value);
// @category:read
StringHandle MapInterpretationContextString_at(MapInterpretationContextStringHandle handle, InterpretationContextHandle key);
// @category:write
void MapInterpretationContextString_erase(MapInterpretationContextStringHandle handle, InterpretationContextHandle key);
// @category:read
size_t MapInterpretationContextString_size(MapInterpretationContextStringHandle handle);
// @category:read
bool MapInterpretationContextString_empty(MapInterpretationContextStringHandle handle);
// @category:write
void MapInterpretationContextString_clear(MapInterpretationContextStringHandle handle);
// @category:read
bool MapInterpretationContextString_contains(MapInterpretationContextStringHandle handle, InterpretationContextHandle key);
// @category:read
/* AUTO-DOC from cpp: MapInterpretationContextString_keys | falcon_core::generic::Map::keys */
/**
 * @brief Return the keys of the Map.
 */
ListInterpretationContextHandle MapInterpretationContextString_keys(MapInterpretationContextStringHandle handle);
// @category:read
/* AUTO-DOC from cpp: MapInterpretationContextString_values | falcon_core::generic::Map::values */
/**
 * @brief Return the values of the Map.
 */
ListStringHandle MapInterpretationContextString_values(MapInterpretationContextStringHandle handle);
// @category:read
ListPairInterpretationContextStringHandle MapInterpretationContextString_items(MapInterpretationContextStringHandle handle);
// @category:read
bool MapInterpretationContextString_equal(MapInterpretationContextStringHandle a, MapInterpretationContextStringHandle b);
// @category:read
bool MapInterpretationContextString_not_equal(MapInterpretationContextStringHandle a, MapInterpretationContextStringHandle b);
// @category:read
StringHandle      MapInterpretationContextString_to_json_string(MapInterpretationContextStringHandle handle);
// @category:allocation
MapInterpretationContextStringHandle MapInterpretationContextString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif