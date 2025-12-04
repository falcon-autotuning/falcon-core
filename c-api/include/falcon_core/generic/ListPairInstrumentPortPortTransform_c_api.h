#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairInstrumentPortPortTransform_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairInstrumentPortPortTransformHandle;
// Function declarations

// @category:allocation
ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_create_empty();

// @category:allocation
ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_fill_value(size_t count, PairInstrumentPortPortTransformHandle value);
// @category:allocation
ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_create(PairInstrumentPortPortTransformHandle* data, size_t count);
// @category:deallocation
void ListPairInstrumentPortPortTransform_destroy(ListPairInstrumentPortPortTransformHandle handle);
// @category:write
void ListPairInstrumentPortPortTransform_push_back(ListPairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle value);
// @category:read
size_t ListPairInstrumentPortPortTransform_size(ListPairInstrumentPortPortTransformHandle handle);
// @category:read
bool ListPairInstrumentPortPortTransform_empty(ListPairInstrumentPortPortTransformHandle handle);
// @category:write
void ListPairInstrumentPortPortTransform_erase_at(ListPairInstrumentPortPortTransformHandle handle, size_t idx);
// @category:write
void ListPairInstrumentPortPortTransform_clear(ListPairInstrumentPortPortTransformHandle handle);
// @category:read
PairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_at(ListPairInstrumentPortPortTransformHandle handle, size_t idx);
// @category:read
size_t ListPairInstrumentPortPortTransform_items(ListPairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListPairInstrumentPortPortTransform_contains(ListPairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle value);
// @category:read
size_t ListPairInstrumentPortPortTransform_index(ListPairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle value);
// @category:read
ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_intersection(ListPairInstrumentPortPortTransformHandle handle, ListPairInstrumentPortPortTransformHandle other);
// @category:read
bool ListPairInstrumentPortPortTransform_equal(ListPairInstrumentPortPortTransformHandle a, ListPairInstrumentPortPortTransformHandle b);
// @category:read
bool ListPairInstrumentPortPortTransform_not_equal(ListPairInstrumentPortPortTransformHandle a, ListPairInstrumentPortPortTransformHandle b);

// @category:read
StringHandle      ListPairInstrumentPortPortTransform_to_json_string(ListPairInstrumentPortPortTransformHandle handle);
// @category:allocation
ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif