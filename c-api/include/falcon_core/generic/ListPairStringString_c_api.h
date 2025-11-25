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

ListPairStringStringHandle ListPairStringString_create_empty();

ListPairStringStringHandle ListPairStringString_fill_value(size_t count, PairStringStringHandle value);
ListPairStringStringHandle ListPairStringString_create(PairStringStringHandle* data, size_t count);
void ListPairStringString_destroy(ListPairStringStringHandle handle);
void ListPairStringString_push_back(ListPairStringStringHandle handle, PairStringStringHandle value);
size_t ListPairStringString_size(ListPairStringStringHandle handle);
bool ListPairStringString_empty(ListPairStringStringHandle handle);
void ListPairStringString_erase_at(ListPairStringStringHandle handle, size_t idx);
void ListPairStringString_clear(ListPairStringStringHandle handle);
PairStringStringHandle ListPairStringString_at(ListPairStringStringHandle handle, size_t idx);
size_t ListPairStringString_items(ListPairStringStringHandle handle, PairStringStringHandle* out_buffer, size_t buffer_size);
bool ListPairStringString_contains(ListPairStringStringHandle handle, PairStringStringHandle value);
size_t ListPairStringString_index(ListPairStringStringHandle handle, PairStringStringHandle value);
ListPairStringStringHandle ListPairStringString_intersection(ListPairStringStringHandle handle, ListPairStringStringHandle other);
bool ListPairStringString_equal(ListPairStringStringHandle a, ListPairStringStringHandle b);
bool ListPairStringString_not_equal(ListPairStringStringHandle a, ListPairStringStringHandle b);

// Serialization (from Song)
StringHandle      ListPairStringString_to_json_string(ListPairStringStringHandle handle);
ListPairStringStringHandle ListPairStringString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif