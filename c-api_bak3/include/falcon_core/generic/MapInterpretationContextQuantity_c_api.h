#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairInterpretationContextQuantity_c_api.h"
#include "falcon_core/generic/ListQuantity_c_api.h"
#include "falcon_core/generic/ListInterpretationContext_c_api.h"
#include "falcon_core/generic/ListPairInterpretationContextQuantity_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapInterpretationContextQuantityHandle;
// Function declarations

MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_create_empty();
MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_create(const PairInterpretationContextQuantityHandle* data, size_t count);
void MapInterpretationContextQuantity_destroy(MapInterpretationContextQuantityHandle handle);
void MapInterpretationContextQuantity_insert_or_assign(MapInterpretationContextQuantityHandle handle, const InterpretationContextHandle key, const QuantityHandle value);
void MapInterpretationContextQuantity_insert(MapInterpretationContextQuantityHandle handle, const InterpretationContextHandle key, const QuantityHandle value);
QuantityHandle MapInterpretationContextQuantity_at(MapInterpretationContextQuantityHandle handle, const InterpretationContextHandle key);
void MapInterpretationContextQuantity_erase(MapInterpretationContextQuantityHandle handle, const InterpretationContextHandle key);
size_t MapInterpretationContextQuantity_size(MapInterpretationContextQuantityHandle handle);
bool MapInterpretationContextQuantity_empty(MapInterpretationContextQuantityHandle handle);
void MapInterpretationContextQuantity_clear(MapInterpretationContextQuantityHandle handle);
bool MapInterpretationContextQuantity_contains(MapInterpretationContextQuantityHandle handle, const InterpretationContextHandle key);
/* AUTO-DOC from cpp: MapInterpretationContextQuantity_keys | falcon_core::generic::Map::keys */
/**
 * @brief (from C++: falcon_core::generic::Map::keys)
 * @brief Return the keys of the Map.
 */
ListInterpretationContextHandle MapInterpretationContextQuantity_keys(MapInterpretationContextQuantityHandle handle);
/* AUTO-DOC from cpp: MapInterpretationContextQuantity_values | falcon_core::generic::Map::values */
/**
 * @brief (from C++: falcon_core::generic::Map::values)
 * @brief Return the values of the Map.
 */
ListQuantityHandle MapInterpretationContextQuantity_values(MapInterpretationContextQuantityHandle handle);
ListPairInterpretationContextQuantityHandle MapInterpretationContextQuantity_items(MapInterpretationContextQuantityHandle handle);
bool MapInterpretationContextQuantity_equal(MapInterpretationContextQuantityHandle a, MapInterpretationContextQuantityHandle b);
bool MapInterpretationContextQuantity_not_equal(MapInterpretationContextQuantityHandle a, MapInterpretationContextQuantityHandle b);
// Serialization (from Song)
StringHandle      MapInterpretationContextQuantity_to_json_string(MapInterpretationContextQuantityHandle handle);
MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif