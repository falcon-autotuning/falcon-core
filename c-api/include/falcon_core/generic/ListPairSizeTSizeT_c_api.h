#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairSizeTSizeT_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairSizeTSizeTHandle;
// Function declarations

// @category:allocation
ListPairSizeTSizeTHandle ListPairSizeTSizeT_create_empty();

// @category:allocation
ListPairSizeTSizeTHandle ListPairSizeTSizeT_fill_value(size_t count, PairSizeTSizeTHandle value);
// @category:allocation
ListPairSizeTSizeTHandle ListPairSizeTSizeT_create(PairSizeTSizeTHandle* data, size_t count);
// @category:deallocation
void ListPairSizeTSizeT_destroy(ListPairSizeTSizeTHandle handle);
// @category:write
void ListPairSizeTSizeT_push_back(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle value);
// @category:read
size_t ListPairSizeTSizeT_size(ListPairSizeTSizeTHandle handle);
// @category:read
bool ListPairSizeTSizeT_empty(ListPairSizeTSizeTHandle handle);
// @category:write
void ListPairSizeTSizeT_erase_at(ListPairSizeTSizeTHandle handle, size_t idx);
// @category:write
void ListPairSizeTSizeT_clear(ListPairSizeTSizeTHandle handle);
// @category:read
PairSizeTSizeTHandle ListPairSizeTSizeT_at(ListPairSizeTSizeTHandle handle, size_t idx);
// @category:read
size_t ListPairSizeTSizeT_items(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListPairSizeTSizeT_contains(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle value);
// @category:read
size_t ListPairSizeTSizeT_index(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle value);
// @category:read
ListPairSizeTSizeTHandle ListPairSizeTSizeT_intersection(ListPairSizeTSizeTHandle handle, ListPairSizeTSizeTHandle other);
// @category:read
bool ListPairSizeTSizeT_equal(ListPairSizeTSizeTHandle a, ListPairSizeTSizeTHandle b);
// @category:read
bool ListPairSizeTSizeT_not_equal(ListPairSizeTSizeTHandle a, ListPairSizeTSizeTHandle b);

// @category:read
StringHandle      ListPairSizeTSizeT_to_json_string(ListPairSizeTSizeTHandle handle);
// @category:allocation
ListPairSizeTSizeTHandle ListPairSizeTSizeT_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif