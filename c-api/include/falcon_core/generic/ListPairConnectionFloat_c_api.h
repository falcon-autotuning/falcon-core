#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairConnectionFloat_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairConnectionFloatHandle;
// Function declarations

ListPairConnectionFloatHandle ListPairConnectionFloat_create_empty();
ListPairConnectionFloatHandle ListPairConnectionFloat_allocate(size_t count);
ListPairConnectionFloatHandle ListPairConnectionFloat_fill_value(size_t count, PairConnectionFloatHandle value);
ListPairConnectionFloatHandle ListPairConnectionFloat_create(PairConnectionFloatHandle* data, size_t count);
void ListPairConnectionFloat_destroy(ListPairConnectionFloatHandle handle);
void ListPairConnectionFloat_push_back(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value);
size_t ListPairConnectionFloat_size(ListPairConnectionFloatHandle handle);
bool ListPairConnectionFloat_empty(ListPairConnectionFloatHandle handle);
void ListPairConnectionFloat_erase_at(ListPairConnectionFloatHandle handle, size_t idx);
void ListPairConnectionFloat_clear(ListPairConnectionFloatHandle handle);
PairConnectionFloatHandle ListPairConnectionFloat_at(ListPairConnectionFloatHandle handle, size_t idx);
size_t ListPairConnectionFloat_items(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle* out_buffer, size_t buffer_size);
bool ListPairConnectionFloat_contains(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value);
size_t ListPairConnectionFloat_index(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value);
ListPairConnectionFloatHandle ListPairConnectionFloat_intersection(ListPairConnectionFloatHandle handle, ListPairConnectionFloatHandle other);
bool ListPairConnectionFloat_equal(ListPairConnectionFloatHandle a, ListPairConnectionFloatHandle b);
bool ListPairConnectionFloat_not_equal(ListPairConnectionFloatHandle a, ListPairConnectionFloatHandle b);

// Serialization (from Song)
StringHandle      ListPairConnectionFloat_to_json_string(ListPairConnectionFloatHandle handle);
ListPairConnectionFloatHandle ListPairConnectionFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif