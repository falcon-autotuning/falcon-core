#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/names/Gname_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListGnameHandle;
// Function declarations

ListGnameHandle ListGname_create_empty();

ListGnameHandle ListGname_fill_value(size_t count, GnameHandle value);
ListGnameHandle ListGname_create(GnameHandle* data, size_t count);
void ListGname_destroy(ListGnameHandle handle);
void ListGname_push_back(ListGnameHandle handle, GnameHandle value);
size_t ListGname_size(ListGnameHandle handle);
bool ListGname_empty(ListGnameHandle handle);
void ListGname_erase_at(ListGnameHandle handle, size_t idx);
void ListGname_clear(ListGnameHandle handle);
GnameHandle ListGname_at(ListGnameHandle handle, size_t idx);
size_t ListGname_items(ListGnameHandle handle, GnameHandle* out_buffer, size_t buffer_size);
bool ListGname_contains(ListGnameHandle handle, GnameHandle value);
size_t ListGname_index(ListGnameHandle handle, GnameHandle value);
ListGnameHandle ListGname_intersection(ListGnameHandle handle, ListGnameHandle other);
bool ListGname_equal(ListGnameHandle a, ListGnameHandle b);
bool ListGname_not_equal(ListGnameHandle a, ListGnameHandle b);

// Serialization (from Song)
StringHandle      ListGname_to_json_string(ListGnameHandle handle);
ListGnameHandle ListGname_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif