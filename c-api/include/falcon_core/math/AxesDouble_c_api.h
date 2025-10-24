#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListDouble_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesDoubleHandle;
// Function declarations

AxesDoubleHandle AxesDouble_create_empty();
AxesDoubleHandle AxesDouble_create_raw(const double* data, size_t count);
AxesDoubleHandle AxesDouble_create(ListDoubleHandle data);
void AxesDouble_destroy(AxesDoubleHandle handle);
void AxesDouble_push_back(AxesDoubleHandle handle, double value);
size_t AxesDouble_size(AxesDoubleHandle handle);
bool AxesDouble_empty(AxesDoubleHandle handle);
void AxesDouble_erase_at(AxesDoubleHandle handle, size_t idx);
void AxesDouble_clear(AxesDoubleHandle handle);
double AxesDouble_at(AxesDoubleHandle handle, size_t idx);
size_t AxesDouble_items(AxesDoubleHandle handle, double* out_buffer, size_t buffer_size);
bool AxesDouble_contains(AxesDoubleHandle handle, double value);
size_t AxesDouble_index(AxesDoubleHandle handle, double value);
AxesDoubleHandle AxesDouble_intersection(AxesDoubleHandle handle, AxesDoubleHandle other);
bool AxesDouble_equal(AxesDoubleHandle a, AxesDoubleHandle b);
bool AxesDouble_not_equal(AxesDoubleHandle a, AxesDoubleHandle b);

// Serialization (from Song)
StringHandle      AxesDouble_to_json_string(AxesDoubleHandle handle);
AxesDoubleHandle AxesDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif