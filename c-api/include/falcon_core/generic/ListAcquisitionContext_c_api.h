#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListAcquisitionContextHandle;
// Function declarations

// @category:allocation
ListAcquisitionContextHandle ListAcquisitionContext_create_empty();

// @category:allocation
ListAcquisitionContextHandle ListAcquisitionContext_fill_value(size_t count, AcquisitionContextHandle value);
// @category:allocation
ListAcquisitionContextHandle ListAcquisitionContext_create(AcquisitionContextHandle* data, size_t count);
// @category:deallocation
void ListAcquisitionContext_destroy(ListAcquisitionContextHandle handle);
// @category:write
void ListAcquisitionContext_push_back(ListAcquisitionContextHandle handle, AcquisitionContextHandle value);
// @category:read
size_t ListAcquisitionContext_size(ListAcquisitionContextHandle handle);
// @category:read
bool ListAcquisitionContext_empty(ListAcquisitionContextHandle handle);
// @category:write
void ListAcquisitionContext_erase_at(ListAcquisitionContextHandle handle, size_t idx);
// @category:write
void ListAcquisitionContext_clear(ListAcquisitionContextHandle handle);
// @category:read
AcquisitionContextHandle ListAcquisitionContext_at(ListAcquisitionContextHandle handle, size_t idx);
// @category:read
size_t ListAcquisitionContext_items(ListAcquisitionContextHandle handle, AcquisitionContextHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListAcquisitionContext_contains(ListAcquisitionContextHandle handle, AcquisitionContextHandle value);
// @category:read
size_t ListAcquisitionContext_index(ListAcquisitionContextHandle handle, AcquisitionContextHandle value);
// @category:read
ListAcquisitionContextHandle ListAcquisitionContext_intersection(ListAcquisitionContextHandle handle, ListAcquisitionContextHandle other);
// @category:read
bool ListAcquisitionContext_equal(ListAcquisitionContextHandle a, ListAcquisitionContextHandle b);
// @category:read
bool ListAcquisitionContext_not_equal(ListAcquisitionContextHandle a, ListAcquisitionContextHandle b);

// @category:read
StringHandle      ListAcquisitionContext_to_json_string(ListAcquisitionContextHandle handle);
// @category:allocation
ListAcquisitionContextHandle ListAcquisitionContext_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif