#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairIntInt_c_api.h"
#include <cstddef>

// Forward declarations for opaque handles
typedef void* ListPairIntIntHandle;
// Function declarations

ListPairIntIntHandle ListPairIntInt_create_empty();
ListPairIntIntHandle ListPairIntInt_allocate(size_t count);
ListPairIntIntHandle ListPairIntInt_fill_value(size_t count, PairIntIntHandle value);
ListPairIntIntHandle ListPairIntInt_create(const PairIntIntHandle* data, size_t count);
void ListPairIntInt_destroy(ListPairIntIntHandle handle);
void ListPairIntInt_push_back(ListPairIntIntHandle handle, PairIntIntHandle value);
size_t ListPairIntInt_size(ListPairIntIntHandle handle);
bool ListPairIntInt_empty(ListPairIntIntHandle handle);
void ListPairIntInt_erase_at(ListPairIntIntHandle handle, size_t idx);
void ListPairIntInt_clear(ListPairIntIntHandle handle);
PairIntIntHandle ListPairIntInt_at(ListPairIntIntHandle handle, size_t idx);
size_t ListPairIntInt_items(ListPairIntIntHandle handle, PairIntIntHandle* out_buffer, size_t buffer_size);
bool ListPairIntInt_contains(ListPairIntIntHandle handle, PairIntIntHandle value);
size_t ListPairIntInt_index(ListPairIntIntHandle handle, PairIntIntHandle value);
ListPairIntIntHandle ListPairIntInt_intersection(ListPairIntIntHandle handle, ListPairIntIntHandle other);
bool ListPairIntInt_equal(ListPairIntIntHandle a, ListPairIntIntHandle b);
bool ListPairIntInt_not_equal(ListPairIntIntHandle a, ListPairIntIntHandle b);

// Serialization (from Song)
const char*      ListPairIntInt_to_json_string(ListPairIntIntHandle handle);
ListPairIntIntHandle ListPairIntInt_from_json_string(const char* json);

#ifdef __cplusplus
}
#endif