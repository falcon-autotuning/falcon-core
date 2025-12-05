#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/Quantity_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListQuantityHandle;
// Function declarations

// @category:allocation
ListQuantityHandle ListQuantity_create_empty();

// @category:allocation
ListQuantityHandle ListQuantity_fill_value(size_t count, QuantityHandle value);
// @category:allocation
ListQuantityHandle ListQuantity_create(QuantityHandle* data, size_t count);
// @category:deallocation
void ListQuantity_destroy(ListQuantityHandle handle);
// @category:write
void ListQuantity_push_back(ListQuantityHandle handle, QuantityHandle value);
// @category:read
size_t ListQuantity_size(ListQuantityHandle handle);
// @category:read
bool ListQuantity_empty(ListQuantityHandle handle);
// @category:write
void ListQuantity_erase_at(ListQuantityHandle handle, size_t idx);
// @category:write
void ListQuantity_clear(ListQuantityHandle handle);
// @category:read
QuantityHandle ListQuantity_at(ListQuantityHandle handle, size_t idx);
// @category:read
size_t ListQuantity_items(ListQuantityHandle handle, QuantityHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListQuantity_contains(ListQuantityHandle handle, QuantityHandle value);
// @category:read
size_t ListQuantity_index(ListQuantityHandle handle, QuantityHandle value);
// @category:read
ListQuantityHandle ListQuantity_intersection(ListQuantityHandle handle, ListQuantityHandle other);
// @category:read
bool ListQuantity_equal(ListQuantityHandle a, ListQuantityHandle b);
// @category:read
bool ListQuantity_not_equal(ListQuantityHandle a, ListQuantityHandle b);

// @category:read
StringHandle      ListQuantity_to_json_string(ListQuantityHandle handle);
// @category:allocation
ListQuantityHandle ListQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif