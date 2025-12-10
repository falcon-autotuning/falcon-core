#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairConnectionQuantity_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairConnectionQuantityHandle;
// Function declarations

// @category:allocation
ListPairConnectionQuantityHandle ListPairConnectionQuantity_create_empty();
// @category:allocation
ListPairConnectionQuantityHandle ListPairConnectionQuantity_copy(ListPairConnectionQuantityHandle handle);

// @category:allocation
ListPairConnectionQuantityHandle ListPairConnectionQuantity_fill_value(size_t count, PairConnectionQuantityHandle value);
// @category:allocation
ListPairConnectionQuantityHandle ListPairConnectionQuantity_create(PairConnectionQuantityHandle* data, size_t count);
// @category:deallocation
void ListPairConnectionQuantity_destroy(ListPairConnectionQuantityHandle handle);
// @category:write
void ListPairConnectionQuantity_push_back(ListPairConnectionQuantityHandle handle, PairConnectionQuantityHandle value);
// @category:read
size_t ListPairConnectionQuantity_size(ListPairConnectionQuantityHandle handle);
// @category:read
bool ListPairConnectionQuantity_empty(ListPairConnectionQuantityHandle handle);
// @category:write
void ListPairConnectionQuantity_erase_at(ListPairConnectionQuantityHandle handle, size_t idx);
// @category:write
void ListPairConnectionQuantity_clear(ListPairConnectionQuantityHandle handle);
// @category:read
PairConnectionQuantityHandle ListPairConnectionQuantity_at(ListPairConnectionQuantityHandle handle, size_t idx);
// @category:read
size_t ListPairConnectionQuantity_items(ListPairConnectionQuantityHandle handle, PairConnectionQuantityHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListPairConnectionQuantity_contains(ListPairConnectionQuantityHandle handle, PairConnectionQuantityHandle value);
// @category:read
size_t ListPairConnectionQuantity_index(ListPairConnectionQuantityHandle handle, PairConnectionQuantityHandle value);
// @category:read
ListPairConnectionQuantityHandle ListPairConnectionQuantity_intersection(ListPairConnectionQuantityHandle handle, ListPairConnectionQuantityHandle other);
// @category:read
bool ListPairConnectionQuantity_equal(ListPairConnectionQuantityHandle handle, ListPairConnectionQuantityHandle other);
// @category:read
bool ListPairConnectionQuantity_not_equal(ListPairConnectionQuantityHandle handle, ListPairConnectionQuantityHandle other);

// @category:read
StringHandle      ListPairConnectionQuantity_to_json_string(ListPairConnectionQuantityHandle handle);
// @category:allocation
ListPairConnectionQuantityHandle ListPairConnectionQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif