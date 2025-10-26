#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairStringDouble_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairStringDoubleHandle;
// Function declarations

ListPairStringDoubleHandle ListPairStringDouble_create_empty();
ListPairStringDoubleHandle ListPairStringDouble_allocate(size_t count);
ListPairStringDoubleHandle ListPairStringDouble_fill_value(size_t count, PairStringDoubleHandle value);
ListPairStringDoubleHandle ListPairStringDouble_create(PairStringDoubleHandle* data, size_t count);
void ListPairStringDouble_destroy(ListPairStringDoubleHandle handle);
void ListPairStringDouble_push_back(ListPairStringDoubleHandle handle, PairStringDoubleHandle value);
size_t ListPairStringDouble_size(ListPairStringDoubleHandle handle);
bool ListPairStringDouble_empty(ListPairStringDoubleHandle handle);
void ListPairStringDouble_erase_at(ListPairStringDoubleHandle handle, size_t idx);
void ListPairStringDouble_clear(ListPairStringDoubleHandle handle);
PairStringDoubleHandle ListPairStringDouble_at(ListPairStringDoubleHandle handle, size_t idx);
size_t ListPairStringDouble_items(ListPairStringDoubleHandle handle, PairStringDoubleHandle* out_buffer, size_t buffer_size);
bool ListPairStringDouble_contains(ListPairStringDoubleHandle handle, PairStringDoubleHandle value);
size_t ListPairStringDouble_index(ListPairStringDoubleHandle handle, PairStringDoubleHandle value);
ListPairStringDoubleHandle ListPairStringDouble_intersection(ListPairStringDoubleHandle handle, ListPairStringDoubleHandle other);
bool ListPairStringDouble_equal(ListPairStringDoubleHandle a, ListPairStringDoubleHandle b);
bool ListPairStringDouble_not_equal(ListPairStringDoubleHandle a, ListPairStringDoubleHandle b);

// Serialization (from Song)
StringHandle      ListPairStringDouble_to_json_string(ListPairStringDoubleHandle handle);
ListPairStringDoubleHandle ListPairStringDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif