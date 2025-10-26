#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairFloatFloat_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairFloatFloatHandle;
// Function declarations

ListPairFloatFloatHandle ListPairFloatFloat_create_empty();
ListPairFloatFloatHandle ListPairFloatFloat_allocate(size_t count);
ListPairFloatFloatHandle ListPairFloatFloat_fill_value(size_t count, PairFloatFloatHandle value);
ListPairFloatFloatHandle ListPairFloatFloat_create(PairFloatFloatHandle* data, size_t count);
void ListPairFloatFloat_destroy(ListPairFloatFloatHandle handle);
void ListPairFloatFloat_push_back(ListPairFloatFloatHandle handle, PairFloatFloatHandle value);
size_t ListPairFloatFloat_size(ListPairFloatFloatHandle handle);
bool ListPairFloatFloat_empty(ListPairFloatFloatHandle handle);
void ListPairFloatFloat_erase_at(ListPairFloatFloatHandle handle, size_t idx);
void ListPairFloatFloat_clear(ListPairFloatFloatHandle handle);
PairFloatFloatHandle ListPairFloatFloat_at(ListPairFloatFloatHandle handle, size_t idx);
size_t ListPairFloatFloat_items(ListPairFloatFloatHandle handle, PairFloatFloatHandle* out_buffer, size_t buffer_size);
bool ListPairFloatFloat_contains(ListPairFloatFloatHandle handle, PairFloatFloatHandle value);
size_t ListPairFloatFloat_index(ListPairFloatFloatHandle handle, PairFloatFloatHandle value);
ListPairFloatFloatHandle ListPairFloatFloat_intersection(ListPairFloatFloatHandle handle, ListPairFloatFloatHandle other);
bool ListPairFloatFloat_equal(ListPairFloatFloatHandle a, ListPairFloatFloatHandle b);
bool ListPairFloatFloat_not_equal(ListPairFloatFloatHandle a, ListPairFloatFloatHandle b);

// Serialization (from Song)
StringHandle      ListPairFloatFloat_to_json_string(ListPairFloatFloatHandle handle);
ListPairFloatFloatHandle ListPairFloatFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif