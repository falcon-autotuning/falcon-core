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

// @category:allocation
FALCON_CORE_C_API MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_create_empty();
// @category:allocation
FALCON_CORE_C_API MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_copy(MapInstrumentPortPortTransformHandle handle);
// @category:allocation
FALCON_CORE_C_API MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_create(PairInstrumentPortPortTransformHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void MapInstrumentPortPortTransform_destroy(MapInstrumentPortPortTransformHandle handle);
// @category:write
FALCON_CORE_C_API void MapInstrumentPortPortTransform_insert_or_assign(MapInstrumentPortPortTransformHandle handle, InstrumentPortHandle key, PortTransformHandle value);
// @category:write
FALCON_CORE_C_API void MapInstrumentPortPortTransform_insert(MapInstrumentPortPortTransformHandle handle, InstrumentPortHandle key, PortTransformHandle value);
// @category:read
FALCON_CORE_C_API PortTransformHandle MapInstrumentPortPortTransform_at(MapInstrumentPortPortTransformHandle handle, InstrumentPortHandle key);
// @category:write
FALCON_CORE_C_API void MapInstrumentPortPortTransform_erase(MapInstrumentPortPortTransformHandle handle, InstrumentPortHandle key);
// @category:read
FALCON_CORE_C_API size_t MapInstrumentPortPortTransform_size(MapInstrumentPortPortTransformHandle handle);
// @category:read
FALCON_CORE_C_API bool MapInstrumentPortPortTransform_empty(MapInstrumentPortPortTransformHandle handle);
// @category:write
FALCON_CORE_C_API void MapInstrumentPortPortTransform_clear(MapInstrumentPortPortTransformHandle handle);
// @category:read
FALCON_CORE_C_API bool MapInstrumentPortPortTransform_contains(MapInstrumentPortPortTransformHandle handle, InstrumentPortHandle key);
// @category:read
FALCON_CORE_C_API ListInstrumentPortHandle MapInstrumentPortPortTransform_keys(MapInstrumentPortPortTransformHandle handle);
// @category:read
FALCON_CORE_C_API ListPortTransformHandle MapInstrumentPortPortTransform_values(MapInstrumentPortPortTransformHandle handle);
// @category:read
FALCON_CORE_C_API  ListPairInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_items(MapInstrumentPortPortTransformHandle handle);
// @category:read
FALCON_CORE_C_API bool MapInstrumentPortPortTransform_equal(MapInstrumentPortPortTransformHandle handle, MapInstrumentPortPortTransformHandle other);
// @category:read
FALCON_CORE_C_API bool MapInstrumentPortPortTransform_not_equal(MapInstrumentPortPortTransformHandle handle, MapInstrumentPortPortTransformHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      MapInstrumentPortPortTransform_to_json_string(MapInstrumentPortPortTransformHandle handle);
// @category:allocation
FALCON_CORE_C_API MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif