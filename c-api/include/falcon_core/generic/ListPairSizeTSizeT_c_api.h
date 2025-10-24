#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairSizeTSizeT_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairSizeTSizeTHandle;
// Function declarations

ListPairSizeTSizeTHandle ListPairSizeTSizeT_create_empty();
ListPairSizeTSizeTHandle ListPairSizeTSizeT_allocate(size_t count);
ListPairSizeTSizeTHandle ListPairSizeTSizeT_fill_value(size_t count, PairSizeTSizeTHandle value);
ListPairSizeTSizeTHandle ListPairSizeTSizeT_create(const PairSizeTSizeTHandle* data, size_t count);
void ListPairSizeTSizeT_destroy(ListPairSizeTSizeTHandle handle);
void ListPairSizeTSizeT_push_back(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle value);
size_t ListPairSizeTSizeT_size(ListPairSizeTSizeTHandle handle);
bool ListPairSizeTSizeT_empty(ListPairSizeTSizeTHandle handle);
void ListPairSizeTSizeT_erase_at(ListPairSizeTSizeTHandle handle, size_t idx);
void ListPairSizeTSizeT_clear(ListPairSizeTSizeTHandle handle);
PairSizeTSizeTHandle ListPairSizeTSizeT_at(ListPairSizeTSizeTHandle handle, size_t idx);
size_t ListPairSizeTSizeT_items(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle* out_buffer, size_t buffer_size);
bool ListPairSizeTSizeT_contains(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle value);
size_t ListPairSizeTSizeT_index(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle value);
ListPairSizeTSizeTHandle ListPairSizeTSizeT_intersection(ListPairSizeTSizeTHandle handle, ListPairSizeTSizeTHandle other);
bool ListPairSizeTSizeT_equal(ListPairSizeTSizeTHandle a, ListPairSizeTSizeTHandle b);
bool ListPairSizeTSizeT_not_equal(ListPairSizeTSizeTHandle a, ListPairSizeTSizeTHandle b);

// Serialization (from Song)
StringHandle      ListPairSizeTSizeT_to_json_string(ListPairSizeTSizeTHandle handle);
ListPairSizeTSizeTHandle ListPairSizeTSizeT_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif