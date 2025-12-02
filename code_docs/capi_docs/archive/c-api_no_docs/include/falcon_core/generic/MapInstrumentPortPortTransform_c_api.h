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
MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_create_empty();
// @category:allocation
MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_create(PairInstrumentPortPortTransformHandle* data, size_t count);
// @category:deallocation
void MapInstrumentPortPortTransform_destroy(MapInstrumentPortPortTransformHandle handle);
// @category:write
void MapInstrumentPortPortTransform_insert_or_assign(MapInstrumentPortPortTransformHandle handle, InstrumentPortHandle key, PortTransformHandle value);
// @category:write
void MapInstrumentPortPortTransform_insert(MapInstrumentPortPortTransformHandle handle, InstrumentPortHandle key, PortTransformHandle value);
// @category:read
PortTransformHandle MapInstrumentPortPortTransform_at(MapInstrumentPortPortTransformHandle handle, InstrumentPortHandle key);
// @category:write
void MapInstrumentPortPortTransform_erase(MapInstrumentPortPortTransformHandle handle, InstrumentPortHandle key);
// @category:read
size_t MapInstrumentPortPortTransform_size(MapInstrumentPortPortTransformHandle handle);
// @category:read
bool MapInstrumentPortPortTransform_empty(MapInstrumentPortPortTransformHandle handle);
// @category:write
void MapInstrumentPortPortTransform_clear(MapInstrumentPortPortTransformHandle handle);
// @category:read
bool MapInstrumentPortPortTransform_contains(MapInstrumentPortPortTransformHandle handle, InstrumentPortHandle key);
// @category:read
ListInstrumentPortHandle MapInstrumentPortPortTransform_keys(MapInstrumentPortPortTransformHandle handle);
// @category:read
ListPortTransformHandle MapInstrumentPortPortTransform_values(MapInstrumentPortPortTransformHandle handle);
// @category:read
ListPairInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_items(MapInstrumentPortPortTransformHandle handle);
// @category:read
bool MapInstrumentPortPortTransform_equal(MapInstrumentPortPortTransformHandle a, MapInstrumentPortPortTransformHandle b);
// @category:read
bool MapInstrumentPortPortTransform_not_equal(MapInstrumentPortPortTransformHandle a, MapInstrumentPortPortTransformHandle b);
// @category:read
StringHandle      MapInstrumentPortPortTransform_to_json_string(MapInstrumentPortPortTransformHandle handle);
// @category:allocation
MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif