#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairStringBool_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairStringBoolHandle;
// Function declarations

ListPairStringBoolHandle ListPairStringBool_create_empty();

ListPairStringBoolHandle ListPairStringBool_fill_value(size_t count, PairStringBoolHandle value);
ListPairStringBoolHandle ListPairStringBool_create(PairStringBoolHandle* data, size_t count);
void ListPairStringBool_destroy(ListPairStringBoolHandle handle);
void ListPairStringBool_push_back(ListPairStringBoolHandle handle, PairStringBoolHandle value);
size_t ListPairStringBool_size(ListPairStringBoolHandle handle);
bool ListPairStringBool_empty(ListPairStringBoolHandle handle);
void ListPairStringBool_erase_at(ListPairStringBoolHandle handle, size_t idx);
void ListPairStringBool_clear(ListPairStringBoolHandle handle);
PairStringBoolHandle ListPairStringBool_at(ListPairStringBoolHandle handle, size_t idx);
size_t ListPairStringBool_items(ListPairStringBoolHandle handle, PairStringBoolHandle* out_buffer, size_t buffer_size);
bool ListPairStringBool_contains(ListPairStringBoolHandle handle, PairStringBoolHandle value);
size_t ListPairStringBool_index(ListPairStringBoolHandle handle, PairStringBoolHandle value);
ListPairStringBoolHandle ListPairStringBool_intersection(ListPairStringBoolHandle handle, ListPairStringBoolHandle other);
bool ListPairStringBool_equal(ListPairStringBoolHandle a, ListPairStringBoolHandle b);
bool ListPairStringBool_not_equal(ListPairStringBoolHandle a, ListPairStringBoolHandle b);

// Serialization (from Song)
StringHandle      ListPairStringBool_to_json_string(ListPairStringBoolHandle handle);
ListPairStringBoolHandle ListPairStringBool_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif