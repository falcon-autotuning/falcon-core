#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairStringDouble_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairStringDoubleHandle;
// Function declarations

// @category:allocation
ListPairStringDoubleHandle ListPairStringDouble_create_empty();
// @category:allocation
ListPairStringDoubleHandle ListPairStringDouble_copy(ListPairStringDoubleHandle handle);

// @category:allocation
ListPairStringDoubleHandle ListPairStringDouble_fill_value(size_t count, PairStringDoubleHandle value);
// @category:allocation
ListPairStringDoubleHandle ListPairStringDouble_create(PairStringDoubleHandle* data, size_t count);
// @category:deallocation
void ListPairStringDouble_destroy(ListPairStringDoubleHandle handle);
// @category:write
void ListPairStringDouble_push_back(ListPairStringDoubleHandle handle, PairStringDoubleHandle value);
// @category:read
size_t ListPairStringDouble_size(ListPairStringDoubleHandle handle);
// @category:read
bool ListPairStringDouble_empty(ListPairStringDoubleHandle handle);
// @category:write
void ListPairStringDouble_erase_at(ListPairStringDoubleHandle handle, size_t idx);
// @category:write
void ListPairStringDouble_clear(ListPairStringDoubleHandle handle);
// @category:read
PairStringDoubleHandle ListPairStringDouble_at(ListPairStringDoubleHandle handle, size_t idx);
// @category:read
size_t ListPairStringDouble_items(ListPairStringDoubleHandle handle, PairStringDoubleHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListPairStringDouble_contains(ListPairStringDoubleHandle handle, PairStringDoubleHandle value);
// @category:read
size_t ListPairStringDouble_index(ListPairStringDoubleHandle handle, PairStringDoubleHandle value);
// @category:read
ListPairStringDoubleHandle ListPairStringDouble_intersection(ListPairStringDoubleHandle handle, ListPairStringDoubleHandle other);
// @category:read
bool ListPairStringDouble_equal(ListPairStringDoubleHandle handle, ListPairStringDoubleHandle other);
// @category:read
bool ListPairStringDouble_not_equal(ListPairStringDoubleHandle handle, ListPairStringDoubleHandle other);

// @category:read
StringHandle      ListPairStringDouble_to_json_string(ListPairStringDoubleHandle handle);
// @category:allocation
ListPairStringDoubleHandle ListPairStringDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif