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

// @category:allocation
AxesDiscretizerHandle AxesDiscretizer_create_empty();
// @category:allocation
AxesDiscretizerHandle AxesDiscretizer_create_raw(const DiscretizerHandle* data, size_t count);
// @category:allocation
AxesDiscretizerHandle AxesDiscretizer_create(ListDiscretizerHandle data);
// @category:deallocation
void AxesDiscretizer_destroy(AxesDiscretizerHandle handle);
// @category:write
void AxesDiscretizer_push_back(AxesDiscretizerHandle handle, DiscretizerHandle value);
// @category:read
size_t AxesDiscretizer_size(AxesDiscretizerHandle handle);
// @category:read
bool AxesDiscretizer_empty(AxesDiscretizerHandle handle);
// @category:write
void AxesDiscretizer_erase_at(AxesDiscretizerHandle handle, size_t idx);
// @category:write
void AxesDiscretizer_clear(AxesDiscretizerHandle handle);
// @category:read
DiscretizerHandle AxesDiscretizer_at(AxesDiscretizerHandle handle, size_t idx);
// @category:read
size_t AxesDiscretizer_items(AxesDiscretizerHandle handle, DiscretizerHandle* out_buffer, size_t buffer_size);
// @category:read
bool AxesDiscretizer_contains(AxesDiscretizerHandle handle, DiscretizerHandle value);
// @category:read
size_t AxesDiscretizer_index(AxesDiscretizerHandle handle, DiscretizerHandle value);
// @category:read
AxesDiscretizerHandle AxesDiscretizer_intersection(AxesDiscretizerHandle handle, AxesDiscretizerHandle other);
// @category:read
bool AxesDiscretizer_equal(AxesDiscretizerHandle a, AxesDiscretizerHandle b);
// @category:read
bool AxesDiscretizer_not_equal(AxesDiscretizerHandle a, AxesDiscretizerHandle b);

// @category:read
StringHandle      AxesDiscretizer_to_json_string(AxesDiscretizerHandle handle);
// @category:allocation
AxesDiscretizerHandle AxesDiscretizer_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif