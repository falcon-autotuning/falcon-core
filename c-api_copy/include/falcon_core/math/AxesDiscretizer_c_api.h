#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/discrete_spaces/Discretizer_c_api.h"
#include "falcon_core/generic/ListDiscretizer_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesDiscretizerHandle;
// Function declarations

AxesDiscretizerHandle AxesDiscretizer_create_empty();
AxesDiscretizerHandle AxesDiscretizer_create_raw(const DiscretizerHandle* data, size_t count);
AxesDiscretizerHandle AxesDiscretizer_create(ListDiscretizerHandle data);
void AxesDiscretizer_destroy(AxesDiscretizerHandle handle);
void AxesDiscretizer_push_back(AxesDiscretizerHandle handle, DiscretizerHandle value);
size_t AxesDiscretizer_size(AxesDiscretizerHandle handle);
bool AxesDiscretizer_empty(AxesDiscretizerHandle handle);
void AxesDiscretizer_erase_at(AxesDiscretizerHandle handle, size_t idx);
void AxesDiscretizer_clear(AxesDiscretizerHandle handle);
DiscretizerHandle AxesDiscretizer_at(AxesDiscretizerHandle handle, size_t idx);
size_t AxesDiscretizer_items(AxesDiscretizerHandle handle, DiscretizerHandle* out_buffer, size_t buffer_size);
bool AxesDiscretizer_contains(AxesDiscretizerHandle handle, DiscretizerHandle value);
size_t AxesDiscretizer_index(AxesDiscretizerHandle handle, DiscretizerHandle value);
AxesDiscretizerHandle AxesDiscretizer_intersection(AxesDiscretizerHandle handle, AxesDiscretizerHandle other);
bool AxesDiscretizer_equal(AxesDiscretizerHandle a, AxesDiscretizerHandle b);
bool AxesDiscretizer_not_equal(AxesDiscretizerHandle a, AxesDiscretizerHandle b);

// Serialization (from Song)
StringHandle      AxesDiscretizer_to_json_string(AxesDiscretizerHandle handle);
AxesDiscretizerHandle AxesDiscretizer_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif