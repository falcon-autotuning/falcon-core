#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairConnectionDouble_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairConnectionDoubleHandle;
// Function declarations

ListPairConnectionDoubleHandle ListPairConnectionDouble_create_empty();
ListPairConnectionDoubleHandle ListPairConnectionDouble_allocate(size_t count);
ListPairConnectionDoubleHandle ListPairConnectionDouble_fill_value(size_t count, PairConnectionDoubleHandle value);
ListPairConnectionDoubleHandle ListPairConnectionDouble_create(PairConnectionDoubleHandle* data, size_t count);
void ListPairConnectionDouble_destroy(ListPairConnectionDoubleHandle handle);
void ListPairConnectionDouble_push_back(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value);
size_t ListPairConnectionDouble_size(ListPairConnectionDoubleHandle handle);
bool ListPairConnectionDouble_empty(ListPairConnectionDoubleHandle handle);
void ListPairConnectionDouble_erase_at(ListPairConnectionDoubleHandle handle, size_t idx);
void ListPairConnectionDouble_clear(ListPairConnectionDoubleHandle handle);
PairConnectionDoubleHandle ListPairConnectionDouble_at(ListPairConnectionDoubleHandle handle, size_t idx);
size_t ListPairConnectionDouble_items(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle* out_buffer, size_t buffer_size);
bool ListPairConnectionDouble_contains(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value);
size_t ListPairConnectionDouble_index(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value);
ListPairConnectionDoubleHandle ListPairConnectionDouble_intersection(ListPairConnectionDoubleHandle handle, ListPairConnectionDoubleHandle other);
bool ListPairConnectionDouble_equal(ListPairConnectionDoubleHandle a, ListPairConnectionDoubleHandle b);
bool ListPairConnectionDouble_not_equal(ListPairConnectionDoubleHandle a, ListPairConnectionDoubleHandle b);

// Serialization (from Song)
StringHandle      ListPairConnectionDouble_to_json_string(ListPairConnectionDoubleHandle handle);
ListPairConnectionDoubleHandle ListPairConnectionDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif