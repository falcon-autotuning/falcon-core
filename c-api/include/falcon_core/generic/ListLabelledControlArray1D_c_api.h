#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/LabelledControlArray1D_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListLabelledControlArray1DHandle;
// Function declarations

ListLabelledControlArray1DHandle ListLabelledControlArray1D_create_empty();

ListLabelledControlArray1DHandle ListLabelledControlArray1D_fill_value(size_t count, LabelledControlArray1DHandle value);
ListLabelledControlArray1DHandle ListLabelledControlArray1D_create(LabelledControlArray1DHandle* data, size_t count);
void ListLabelledControlArray1D_destroy(ListLabelledControlArray1DHandle handle);
void ListLabelledControlArray1D_push_back(ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value);
size_t ListLabelledControlArray1D_size(ListLabelledControlArray1DHandle handle);
bool ListLabelledControlArray1D_empty(ListLabelledControlArray1DHandle handle);
void ListLabelledControlArray1D_erase_at(ListLabelledControlArray1DHandle handle, size_t idx);
void ListLabelledControlArray1D_clear(ListLabelledControlArray1DHandle handle);
LabelledControlArray1DHandle ListLabelledControlArray1D_at(ListLabelledControlArray1DHandle handle, size_t idx);
size_t ListLabelledControlArray1D_items(ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle* out_buffer, size_t buffer_size);
bool ListLabelledControlArray1D_contains(ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value);
size_t ListLabelledControlArray1D_index(ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value);
ListLabelledControlArray1DHandle ListLabelledControlArray1D_intersection(ListLabelledControlArray1DHandle handle, ListLabelledControlArray1DHandle other);
bool ListLabelledControlArray1D_equal(ListLabelledControlArray1DHandle a, ListLabelledControlArray1DHandle b);
bool ListLabelledControlArray1D_not_equal(ListLabelledControlArray1DHandle a, ListLabelledControlArray1DHandle b);

// Serialization (from Song)
StringHandle      ListLabelledControlArray1D_to_json_string(ListLabelledControlArray1DHandle handle);
ListLabelledControlArray1DHandle ListLabelledControlArray1D_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif