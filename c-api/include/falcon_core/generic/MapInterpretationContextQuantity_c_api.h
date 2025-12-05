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

// @category:allocation
MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_create_empty();
// @category:allocation
MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_create(PairInterpretationContextQuantityHandle* data, size_t count);
// @category:deallocation
void MapInterpretationContextQuantity_destroy(MapInterpretationContextQuantityHandle handle);
// @category:write
void MapInterpretationContextQuantity_insert_or_assign(MapInterpretationContextQuantityHandle handle, InterpretationContextHandle key, QuantityHandle value);
// @category:write
void MapInterpretationContextQuantity_insert(MapInterpretationContextQuantityHandle handle, InterpretationContextHandle key, QuantityHandle value);
// @category:read
QuantityHandle MapInterpretationContextQuantity_at(MapInterpretationContextQuantityHandle handle, InterpretationContextHandle key);
// @category:write
void MapInterpretationContextQuantity_erase(MapInterpretationContextQuantityHandle handle, InterpretationContextHandle key);
// @category:read
size_t MapInterpretationContextQuantity_size(MapInterpretationContextQuantityHandle handle);
// @category:read
bool MapInterpretationContextQuantity_empty(MapInterpretationContextQuantityHandle handle);
// @category:write
void MapInterpretationContextQuantity_clear(MapInterpretationContextQuantityHandle handle);
// @category:read
bool MapInterpretationContextQuantity_contains(MapInterpretationContextQuantityHandle handle, InterpretationContextHandle key);
// @category:read
ListInterpretationContextHandle MapInterpretationContextQuantity_keys(MapInterpretationContextQuantityHandle handle);
// @category:read
ListQuantityHandle MapInterpretationContextQuantity_values(MapInterpretationContextQuantityHandle handle);
// @category:read
ListPairInterpretationContextQuantityHandle MapInterpretationContextQuantity_items(MapInterpretationContextQuantityHandle handle);
// @category:read
bool MapInterpretationContextQuantity_equal(MapInterpretationContextQuantityHandle a, MapInterpretationContextQuantityHandle b);
// @category:read
bool MapInterpretationContextQuantity_not_equal(MapInterpretationContextQuantityHandle a, MapInterpretationContextQuantityHandle b);
// @category:read
StringHandle      MapInterpretationContextQuantity_to_json_string(MapInterpretationContextQuantityHandle handle);
// @category:allocation
MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif