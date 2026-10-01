#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/generic/PairInstrumentPortQuantity_c_api.h"
#include "falcon-core/generic/ListInstrumentPort_c_api.h"
#include "falcon-core/generic/ListQuantity_c_api.h"
#include "falcon-core/generic/ListPairInstrumentPortQuantity_c_api.h"
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapInstrumentPortQuantityHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API MapInstrumentPortQuantityHandle MapInstrumentPortQuantity_create_empty();
// @category:allocation
FALCON_CORE_C_API MapInstrumentPortQuantityHandle MapInstrumentPortQuantity_copy(MapInstrumentPortQuantityHandle handle);
// @category:allocation
FALCON_CORE_C_API MapInstrumentPortQuantityHandle MapInstrumentPortQuantity_create(PairInstrumentPortQuantityHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void MapInstrumentPortQuantity_destroy(MapInstrumentPortQuantityHandle handle);
// @category:write
FALCON_CORE_C_API void MapInstrumentPortQuantity_insert_or_assign(MapInstrumentPortQuantityHandle handle, InstrumentPortHandle key, QuantityHandle value);
// @category:write
FALCON_CORE_C_API void MapInstrumentPortQuantity_insert(MapInstrumentPortQuantityHandle handle, InstrumentPortHandle key, QuantityHandle value);
// @category:read
FALCON_CORE_C_API QuantityHandle MapInstrumentPortQuantity_at(MapInstrumentPortQuantityHandle handle, InstrumentPortHandle key);
// @category:write
FALCON_CORE_C_API void MapInstrumentPortQuantity_erase(MapInstrumentPortQuantityHandle handle, InstrumentPortHandle key);
// @category:read
FALCON_CORE_C_API size_t MapInstrumentPortQuantity_size(MapInstrumentPortQuantityHandle handle);
// @category:read
FALCON_CORE_C_API bool MapInstrumentPortQuantity_empty(MapInstrumentPortQuantityHandle handle);
// @category:write
FALCON_CORE_C_API void MapInstrumentPortQuantity_clear(MapInstrumentPortQuantityHandle handle);
// @category:read
FALCON_CORE_C_API bool MapInstrumentPortQuantity_contains(MapInstrumentPortQuantityHandle handle, InstrumentPortHandle key);
// @category:read
FALCON_CORE_C_API ListInstrumentPortHandle MapInstrumentPortQuantity_keys(MapInstrumentPortQuantityHandle handle);
// @category:read
FALCON_CORE_C_API ListQuantityHandle MapInstrumentPortQuantity_values(MapInstrumentPortQuantityHandle handle);
// @category:read
FALCON_CORE_C_API  ListPairInstrumentPortQuantityHandle MapInstrumentPortQuantity_items(MapInstrumentPortQuantityHandle handle);
// @category:read
FALCON_CORE_C_API bool MapInstrumentPortQuantity_equal(MapInstrumentPortQuantityHandle handle, MapInstrumentPortQuantityHandle other);
// @category:read
FALCON_CORE_C_API bool MapInstrumentPortQuantity_not_equal(MapInstrumentPortQuantityHandle handle, MapInstrumentPortQuantityHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      MapInstrumentPortQuantity_to_json_string(MapInstrumentPortQuantityHandle handle);
// @category:allocation
FALCON_CORE_C_API MapInstrumentPortQuantityHandle MapInstrumentPortQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif