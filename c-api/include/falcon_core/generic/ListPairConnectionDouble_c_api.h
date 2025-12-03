#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairConnectionDouble_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairConnectionDoubleHandle;
// Function declarations

// @category:allocation
ListPairConnectionDoubleHandle ListPairConnectionDouble_create_empty();

// @category:allocation
ListPairConnectionDoubleHandle ListPairConnectionDouble_fill_value(size_t count, PairConnectionDoubleHandle value);
// @category:allocation
ListPairConnectionDoubleHandle ListPairConnectionDouble_create(PairConnectionDoubleHandle* data, size_t count);
// @category:deallocation
void ListPairConnectionDouble_destroy(ListPairConnectionDoubleHandle handle);
// @category:write
void ListPairConnectionDouble_push_back(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value);
// @category:read
size_t ListPairConnectionDouble_size(ListPairConnectionDoubleHandle handle);
// @category:read
bool ListPairConnectionDouble_empty(ListPairConnectionDoubleHandle handle);
// @category:write
void ListPairConnectionDouble_erase_at(ListPairConnectionDoubleHandle handle, size_t idx);
// @category:write
void ListPairConnectionDouble_clear(ListPairConnectionDoubleHandle handle);
// @category:read
PairConnectionDoubleHandle ListPairConnectionDouble_at(ListPairConnectionDoubleHandle handle, size_t idx);
// @category:read
size_t ListPairConnectionDouble_items(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListPairConnectionDouble_contains(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value);
// @category:read
size_t ListPairConnectionDouble_index(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value);
// @category:read
ListPairConnectionDoubleHandle ListPairConnectionDouble_intersection(ListPairConnectionDoubleHandle handle, ListPairConnectionDoubleHandle other);
// @category:read
bool ListPairConnectionDouble_equal(ListPairConnectionDoubleHandle a, ListPairConnectionDoubleHandle b);
// @category:read
bool ListPairConnectionDouble_not_equal(ListPairConnectionDoubleHandle a, ListPairConnectionDoubleHandle b);

// @category:read
StringHandle      ListPairConnectionDouble_to_json_string(ListPairConnectionDoubleHandle handle);
// @category:allocation
ListPairConnectionDoubleHandle ListPairConnectionDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif