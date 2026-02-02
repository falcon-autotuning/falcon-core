#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/config/core/Group_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListGroupHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListGroupHandle ListGroup_create_empty();
// @category:allocation
FALCON_CORE_C_API ListGroupHandle ListGroup_copy(ListGroupHandle handle);

// @category:allocation
FALCON_CORE_C_API ListGroupHandle ListGroup_fill_value(size_t count, GroupHandle value);
// @category:allocation
FALCON_CORE_C_API ListGroupHandle ListGroup_create(GroupHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListGroup_destroy(ListGroupHandle handle);
// @category:write
FALCON_CORE_C_API void ListGroup_push_back(ListGroupHandle handle, GroupHandle value);
// @category:read
FALCON_CORE_C_API size_t ListGroup_size(ListGroupHandle handle);
// @category:read
FALCON_CORE_C_API bool ListGroup_empty(ListGroupHandle handle);
// @category:write
FALCON_CORE_C_API void ListGroup_erase_at(ListGroupHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListGroup_clear(ListGroupHandle handle);
// @category:read
FALCON_CORE_C_API GroupHandle ListGroup_at(ListGroupHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListGroup_items(ListGroupHandle handle, GroupHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListGroup_contains(ListGroupHandle handle, GroupHandle value);
// @category:read
FALCON_CORE_C_API size_t ListGroup_index(ListGroupHandle handle, GroupHandle value);
// @category:read
FALCON_CORE_C_API ListGroupHandle ListGroup_intersection(ListGroupHandle handle, ListGroupHandle other);
// @category:read
FALCON_CORE_C_API bool ListGroup_equal(ListGroupHandle handle, ListGroupHandle other);
// @category:read
FALCON_CORE_C_API bool ListGroup_not_equal(ListGroupHandle handle, ListGroupHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListGroup_to_json_string(ListGroupHandle handle);
// @category:allocation
FALCON_CORE_C_API ListGroupHandle ListGroup_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif