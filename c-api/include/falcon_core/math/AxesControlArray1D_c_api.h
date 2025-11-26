#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/ControlArray1D_c_api.h"
#include "falcon_core/generic/ListControlArray1D_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesControlArray1DHandle;
// Function declarations

// @category:allocation
AxesControlArray1DHandle AxesControlArray1D_create_empty();
// @category:allocation
AxesControlArray1DHandle AxesControlArray1D_create_raw(const ControlArray1DHandle* data, size_t count);
// @category:allocation
AxesControlArray1DHandle AxesControlArray1D_create(ListControlArray1DHandle data);
// @category:deallocation
void AxesControlArray1D_destroy(AxesControlArray1DHandle handle);
// @category:write
void AxesControlArray1D_push_back(AxesControlArray1DHandle handle, ControlArray1DHandle value);
// @category:read
size_t AxesControlArray1D_size(AxesControlArray1DHandle handle);
// @category:read
bool AxesControlArray1D_empty(AxesControlArray1DHandle handle);
// @category:write
void AxesControlArray1D_erase_at(AxesControlArray1DHandle handle, size_t idx);
// @category:write
void AxesControlArray1D_clear(AxesControlArray1DHandle handle);
// @category:read
ControlArray1DHandle AxesControlArray1D_at(AxesControlArray1DHandle handle, size_t idx);
// @category:read
size_t AxesControlArray1D_items(AxesControlArray1DHandle handle, ControlArray1DHandle* out_buffer, size_t buffer_size);
// @category:read
bool AxesControlArray1D_contains(AxesControlArray1DHandle handle, ControlArray1DHandle value);
// @category:read
size_t AxesControlArray1D_index(AxesControlArray1DHandle handle, ControlArray1DHandle value);
// @category:read
AxesControlArray1DHandle AxesControlArray1D_intersection(AxesControlArray1DHandle handle, AxesControlArray1DHandle other);
// @category:read
bool AxesControlArray1D_equal(AxesControlArray1DHandle a, AxesControlArray1DHandle b);
// @category:read
bool AxesControlArray1D_not_equal(AxesControlArray1DHandle a, AxesControlArray1DHandle b);

// @category:read
StringHandle      AxesControlArray1D_to_json_string(AxesControlArray1DHandle handle);
// @category:allocation
AxesControlArray1DHandle AxesControlArray1D_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif