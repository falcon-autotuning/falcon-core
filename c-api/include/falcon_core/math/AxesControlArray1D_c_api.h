#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/ControlArray1D_c_api.h"
#include "falcon_core/generic/ListControlArray1D_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesControlArray1DHandle;
// Function declarations

AxesControlArray1DHandle AxesControlArray1D_create_empty();
AxesControlArray1DHandle AxesControlArray1D_create_raw(const ControlArray1DHandle* data, size_t count);
AxesControlArray1DHandle AxesControlArray1D_create(ListControlArray1DHandle data);
void AxesControlArray1D_destroy(AxesControlArray1DHandle handle);
void AxesControlArray1D_push_back(AxesControlArray1DHandle handle, ControlArray1DHandle value);
size_t AxesControlArray1D_size(AxesControlArray1DHandle handle);
bool AxesControlArray1D_empty(AxesControlArray1DHandle handle);
void AxesControlArray1D_erase_at(AxesControlArray1DHandle handle, size_t idx);
void AxesControlArray1D_clear(AxesControlArray1DHandle handle);
ControlArray1DHandle AxesControlArray1D_at(AxesControlArray1DHandle handle, size_t idx);
size_t AxesControlArray1D_items(AxesControlArray1DHandle handle, ControlArray1DHandle* out_buffer, size_t buffer_size);
bool AxesControlArray1D_contains(AxesControlArray1DHandle handle, ControlArray1DHandle value);
size_t AxesControlArray1D_index(AxesControlArray1DHandle handle, ControlArray1DHandle value);
AxesControlArray1DHandle AxesControlArray1D_intersection(AxesControlArray1DHandle handle, AxesControlArray1DHandle other);
bool AxesControlArray1D_equal(AxesControlArray1DHandle a, AxesControlArray1DHandle b);
bool AxesControlArray1D_not_equal(AxesControlArray1DHandle a, AxesControlArray1DHandle b);

// Serialization (from Song)
StringHandle      AxesControlArray1D_to_json_string(AxesControlArray1DHandle handle);
AxesControlArray1DHandle AxesControlArray1D_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif