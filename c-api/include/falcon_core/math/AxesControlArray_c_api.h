#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/ControlArray_c_api.h"
#include "falcon_core/generic/ListControlArray_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesControlArrayHandle;
// Function declarations

// @category:allocation
AxesControlArrayHandle AxesControlArray_create_empty();
// @category:allocation
AxesControlArrayHandle AxesControlArray_create(ListControlArrayHandle data);
// @category:deallocation
void AxesControlArray_destroy(AxesControlArrayHandle handle);
// @category:write
void AxesControlArray_push_back(AxesControlArrayHandle handle, ControlArrayHandle value);
// @category:read
size_t AxesControlArray_size(AxesControlArrayHandle handle);
// @category:read
bool AxesControlArray_empty(AxesControlArrayHandle handle);
// @category:write
void AxesControlArray_erase_at(AxesControlArrayHandle handle, size_t idx);
// @category:write
void AxesControlArray_clear(AxesControlArrayHandle handle);
// @category:read
ControlArrayHandle AxesControlArray_at(AxesControlArrayHandle handle, size_t idx);
// @category:read
size_t AxesControlArray_items(AxesControlArrayHandle handle, ControlArrayHandle* out_buffer, size_t buffer_size);
// @category:read
bool AxesControlArray_contains(AxesControlArrayHandle handle, ControlArrayHandle value);
// @category:read
size_t AxesControlArray_index(AxesControlArrayHandle handle, ControlArrayHandle value);
// @category:read
AxesControlArrayHandle AxesControlArray_intersection(AxesControlArrayHandle handle, AxesControlArrayHandle other);
// @category:read
bool AxesControlArray_equal(AxesControlArrayHandle a, AxesControlArrayHandle b);
// @category:read
bool AxesControlArray_not_equal(AxesControlArrayHandle a, AxesControlArrayHandle b);

// @category:read
StringHandle      AxesControlArray_to_json_string(AxesControlArrayHandle handle);
// @category:allocation
AxesControlArrayHandle AxesControlArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif