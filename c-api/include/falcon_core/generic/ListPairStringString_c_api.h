#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairStringString_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairStringStringHandle;
// Function declarations

// @category:allocation
ListPairStringStringHandle ListPairStringString_create_empty();

// @category:allocation
ListPairStringStringHandle ListPairStringString_fill_value(size_t count, PairStringStringHandle value);
// @category:allocation
ListPairStringStringHandle ListPairStringString_create(PairStringStringHandle* data, size_t count);
// @category:deallocation
void ListPairStringString_destroy(ListPairStringStringHandle handle);
// @category:write
void ListPairStringString_push_back(ListPairStringStringHandle handle, PairStringStringHandle value);
// @category:read
size_t ListPairStringString_size(ListPairStringStringHandle handle);
// @category:read
bool ListPairStringString_empty(ListPairStringStringHandle handle);
// @category:write
void ListPairStringString_erase_at(ListPairStringStringHandle handle, size_t idx);
// @category:write
void ListPairStringString_clear(ListPairStringStringHandle handle);
// @category:read
PairStringStringHandle ListPairStringString_at(ListPairStringStringHandle handle, size_t idx);
// @category:read
size_t ListPairStringString_items(ListPairStringStringHandle handle, PairStringStringHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListPairStringString_contains(ListPairStringStringHandle handle, PairStringStringHandle value);
// @category:read
size_t ListPairStringString_index(ListPairStringStringHandle handle, PairStringStringHandle value);
// @category:read
ListPairStringStringHandle ListPairStringString_intersection(ListPairStringStringHandle handle, ListPairStringStringHandle other);
// @category:read
bool ListPairStringString_equal(ListPairStringStringHandle a, ListPairStringStringHandle b);
// @category:read
bool ListPairStringString_not_equal(ListPairStringStringHandle a, ListPairStringStringHandle b);

// @category:read
StringHandle      ListPairStringString_to_json_string(ListPairStringStringHandle handle);
// @category:allocation
ListPairStringStringHandle ListPairStringString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif