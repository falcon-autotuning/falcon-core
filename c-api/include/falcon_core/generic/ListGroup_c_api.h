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
ListGroupHandle ListGroup_create_empty();
// @category:allocation
ListGroupHandle ListGroup_copy(ListGroupHandle handle);

// @category:allocation
ListGroupHandle ListGroup_fill_value(size_t count, GroupHandle value);
// @category:allocation
ListGroupHandle ListGroup_create(GroupHandle* data, size_t count);
// @category:deallocation
void ListGroup_destroy(ListGroupHandle handle);
// @category:write
void ListGroup_push_back(ListGroupHandle handle, GroupHandle value);
// @category:read
size_t ListGroup_size(ListGroupHandle handle);
// @category:read
bool ListGroup_empty(ListGroupHandle handle);
// @category:write
void ListGroup_erase_at(ListGroupHandle handle, size_t idx);
// @category:write
void ListGroup_clear(ListGroupHandle handle);
// @category:read
GroupHandle ListGroup_at(ListGroupHandle handle, size_t idx);
// @category:read
size_t ListGroup_items(ListGroupHandle handle, GroupHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListGroup_contains(ListGroupHandle handle, GroupHandle value);
// @category:read
size_t ListGroup_index(ListGroupHandle handle, GroupHandle value);
// @category:read
ListGroupHandle ListGroup_intersection(ListGroupHandle handle, ListGroupHandle other);
// @category:read
bool ListGroup_equal(ListGroupHandle handle, ListGroupHandle other);
// @category:read
bool ListGroup_not_equal(ListGroupHandle handle, ListGroupHandle other);

// @category:read
StringHandle      ListGroup_to_json_string(ListGroupHandle handle);
// @category:allocation
ListGroupHandle ListGroup_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif