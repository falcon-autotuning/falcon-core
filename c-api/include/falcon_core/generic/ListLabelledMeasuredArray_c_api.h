#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/LabelledMeasuredArray_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListLabelledMeasuredArrayHandle;
// Function declarations

// @category:allocation
ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_create_empty();

// @category:allocation
ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_fill_value(size_t count, LabelledMeasuredArrayHandle value);
// @category:allocation
ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_create(LabelledMeasuredArrayHandle* data, size_t count);
// @category:deallocation
void ListLabelledMeasuredArray_destroy(ListLabelledMeasuredArrayHandle handle);
// @category:write
void ListLabelledMeasuredArray_push_back(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value);
// @category:read
size_t ListLabelledMeasuredArray_size(ListLabelledMeasuredArrayHandle handle);
// @category:read
bool ListLabelledMeasuredArray_empty(ListLabelledMeasuredArrayHandle handle);
// @category:write
void ListLabelledMeasuredArray_erase_at(ListLabelledMeasuredArrayHandle handle, size_t idx);
// @category:write
void ListLabelledMeasuredArray_clear(ListLabelledMeasuredArrayHandle handle);
// @category:read
LabelledMeasuredArrayHandle ListLabelledMeasuredArray_at(ListLabelledMeasuredArrayHandle handle, size_t idx);
// @category:read
size_t ListLabelledMeasuredArray_items(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListLabelledMeasuredArray_contains(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value);
// @category:read
size_t ListLabelledMeasuredArray_index(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value);
// @category:read
ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_intersection(ListLabelledMeasuredArrayHandle handle, ListLabelledMeasuredArrayHandle other);
// @category:read
bool ListLabelledMeasuredArray_equal(ListLabelledMeasuredArrayHandle a, ListLabelledMeasuredArrayHandle b);
// @category:read
bool ListLabelledMeasuredArray_not_equal(ListLabelledMeasuredArrayHandle a, ListLabelledMeasuredArrayHandle b);

// @category:read
StringHandle      ListLabelledMeasuredArray_to_json_string(ListLabelledMeasuredArrayHandle handle);
// @category:allocation
ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif