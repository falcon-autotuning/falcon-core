#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairIntFloat_c_api.h"
#include <cstddef>

// Forward declarations for opaque handles
typedef void* ListPairIntFloatHandle;
// Function declarations

ListPairIntFloatHandle ListPairIntFloat_create_empty();
ListPairIntFloatHandle ListPairIntFloat_allocate(size_t count);
ListPairIntFloatHandle ListPairIntFloat_fill_value(size_t count, PairIntFloatHandle value);
ListPairIntFloatHandle ListPairIntFloat_create(const PairIntFloatHandle* data, size_t count);
void ListPairIntFloat_destroy(ListPairIntFloatHandle handle);
void ListPairIntFloat_push_back(ListPairIntFloatHandle handle, PairIntFloatHandle value);
size_t ListPairIntFloat_size(ListPairIntFloatHandle handle);
bool ListPairIntFloat_empty(ListPairIntFloatHandle handle);
void ListPairIntFloat_erase_at(ListPairIntFloatHandle handle, size_t idx);
void ListPairIntFloat_clear(ListPairIntFloatHandle handle);
PairIntFloatHandle ListPairIntFloat_at(ListPairIntFloatHandle handle, size_t idx);
size_t ListPairIntFloat_items(ListPairIntFloatHandle handle, PairIntFloatHandle* out_buffer, size_t buffer_size);
bool ListPairIntFloat_contains(ListPairIntFloatHandle handle, PairIntFloatHandle value);
size_t ListPairIntFloat_index(ListPairIntFloatHandle handle, PairIntFloatHandle value);
ListPairIntFloatHandle ListPairIntFloat_intersection(ListPairIntFloatHandle handle, ListPairIntFloatHandle other);
bool ListPairIntFloat_equal(ListPairIntFloatHandle a, ListPairIntFloatHandle b);
bool ListPairIntFloat_not_equal(ListPairIntFloatHandle a, ListPairIntFloatHandle b);
#ifdef __cplusplus
}
#endif