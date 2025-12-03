#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/LabelledMeasuredArray1D_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListLabelledMeasuredArray1DHandle;
// Function declarations

// @category:allocation
ListLabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_create_empty();

// @category:allocation
ListLabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_fill_value(size_t count, LabelledMeasuredArray1DHandle value);
// @category:allocation
ListLabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_create(LabelledMeasuredArray1DHandle* data, size_t count);
// @category:deallocation
void ListLabelledMeasuredArray1D_destroy(ListLabelledMeasuredArray1DHandle handle);
// @category:write
void ListLabelledMeasuredArray1D_push_back(ListLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value);
// @category:read
size_t ListLabelledMeasuredArray1D_size(ListLabelledMeasuredArray1DHandle handle);
// @category:read
bool ListLabelledMeasuredArray1D_empty(ListLabelledMeasuredArray1DHandle handle);
// @category:write
void ListLabelledMeasuredArray1D_erase_at(ListLabelledMeasuredArray1DHandle handle, size_t idx);
// @category:write
void ListLabelledMeasuredArray1D_clear(ListLabelledMeasuredArray1DHandle handle);
// @category:read
LabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_at(ListLabelledMeasuredArray1DHandle handle, size_t idx);
// @category:read
size_t ListLabelledMeasuredArray1D_items(ListLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListLabelledMeasuredArray1D_contains(ListLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value);
// @category:read
size_t ListLabelledMeasuredArray1D_index(ListLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value);
// @category:read
ListLabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_intersection(ListLabelledMeasuredArray1DHandle handle, ListLabelledMeasuredArray1DHandle other);
// @category:read
bool ListLabelledMeasuredArray1D_equal(ListLabelledMeasuredArray1DHandle a, ListLabelledMeasuredArray1DHandle b);
// @category:read
bool ListLabelledMeasuredArray1D_not_equal(ListLabelledMeasuredArray1DHandle a, ListLabelledMeasuredArray1DHandle b);

// @category:read
StringHandle      ListLabelledMeasuredArray1D_to_json_string(ListLabelledMeasuredArray1DHandle handle);
// @category:allocation
ListLabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif