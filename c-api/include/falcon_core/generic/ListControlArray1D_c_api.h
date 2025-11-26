#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/ControlArray1D_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListControlArray1DHandle;
// Function declarations

// @category:allocation
ListControlArray1DHandle ListControlArray1D_create_empty();

// @category:allocation
ListControlArray1DHandle ListControlArray1D_fill_value(size_t count, ControlArray1DHandle value);
// @category:allocation
ListControlArray1DHandle ListControlArray1D_create(ControlArray1DHandle* data, size_t count);
// @category:deallocation
void ListControlArray1D_destroy(ListControlArray1DHandle handle);
// @category:write
void ListControlArray1D_push_back(ListControlArray1DHandle handle, ControlArray1DHandle value);
// @category:read
size_t ListControlArray1D_size(ListControlArray1DHandle handle);
// @category:read
bool ListControlArray1D_empty(ListControlArray1DHandle handle);
// @category:write
void ListControlArray1D_erase_at(ListControlArray1DHandle handle, size_t idx);
// @category:write
void ListControlArray1D_clear(ListControlArray1DHandle handle);
// @category:read
ControlArray1DHandle ListControlArray1D_at(ListControlArray1DHandle handle, size_t idx);
// @category:read
size_t ListControlArray1D_items(ListControlArray1DHandle handle, ControlArray1DHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListControlArray1D_contains(ListControlArray1DHandle handle, ControlArray1DHandle value);
// @category:read
size_t ListControlArray1D_index(ListControlArray1DHandle handle, ControlArray1DHandle value);
// @category:read
ListControlArray1DHandle ListControlArray1D_intersection(ListControlArray1DHandle handle, ListControlArray1DHandle other);
// @category:read
bool ListControlArray1D_equal(ListControlArray1DHandle a, ListControlArray1DHandle b);
// @category:read
bool ListControlArray1D_not_equal(ListControlArray1DHandle a, ListControlArray1DHandle b);

// @category:read
StringHandle      ListControlArray1D_to_json_string(ListControlArray1DHandle handle);
// @category:allocation
ListControlArray1DHandle ListControlArray1D_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif