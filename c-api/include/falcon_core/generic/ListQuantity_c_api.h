#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/Quantity_c_api.h"
#include <cstddef>

// Forward declarations for opaque handles
typedef void* ListQuantityHandle;
// Function declarations

ListQuantityHandle ListQuantity_create_empty();
ListQuantityHandle ListQuantity_allocate(size_t count);
ListQuantityHandle ListQuantity_fill_value(size_t count, QuantityHandle value);
ListQuantityHandle ListQuantity_create(const QuantityHandle* data, size_t count);
void ListQuantity_destroy(ListQuantityHandle handle);
void ListQuantity_push_back(ListQuantityHandle handle, QuantityHandle value);
size_t ListQuantity_size(ListQuantityHandle handle);
bool ListQuantity_empty(ListQuantityHandle handle);
void ListQuantity_erase_at(ListQuantityHandle handle, size_t idx);
void ListQuantity_clear(ListQuantityHandle handle);
QuantityHandle ListQuantity_at(ListQuantityHandle handle, size_t idx);
size_t ListQuantity_items(ListQuantityHandle handle, QuantityHandle* out_buffer, size_t buffer_size);
bool ListQuantity_contains(ListQuantityHandle handle, QuantityHandle value);
size_t ListQuantity_index(ListQuantityHandle handle, QuantityHandle value);
ListQuantityHandle ListQuantity_intersection(ListQuantityHandle handle, ListQuantityHandle other);
bool ListQuantity_equal(ListQuantityHandle a, ListQuantityHandle b);
bool ListQuantity_not_equal(ListQuantityHandle a, ListQuantityHandle b);

// Serialization (from Song)
const char*      ListQuantity_to_json_string(ListQuantityHandle handle);
ListQuantityHandle ListQuantity_from_json_string(const char* json);

#ifdef __cplusplus
}
#endif