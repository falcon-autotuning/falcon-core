#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/config/core/Group_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListGroupHandle;
// Function declarations

ListGroupHandle ListGroup_create_empty();

ListGroupHandle ListGroup_fill_value(size_t count, GroupHandle value);
ListGroupHandle ListGroup_create(GroupHandle* data, size_t count);
void ListGroup_destroy(ListGroupHandle handle);
void ListGroup_push_back(ListGroupHandle handle, GroupHandle value);
size_t ListGroup_size(ListGroupHandle handle);
bool ListGroup_empty(ListGroupHandle handle);
void ListGroup_erase_at(ListGroupHandle handle, size_t idx);
void ListGroup_clear(ListGroupHandle handle);
GroupHandle ListGroup_at(ListGroupHandle handle, size_t idx);
size_t ListGroup_items(ListGroupHandle handle, GroupHandle* out_buffer, size_t buffer_size);
bool ListGroup_contains(ListGroupHandle handle, GroupHandle value);
size_t ListGroup_index(ListGroupHandle handle, GroupHandle value);
ListGroupHandle ListGroup_intersection(ListGroupHandle handle, ListGroupHandle other);
bool ListGroup_equal(ListGroupHandle a, ListGroupHandle b);
bool ListGroup_not_equal(ListGroupHandle a, ListGroupHandle b);

// Serialization (from Song)
StringHandle      ListGroup_to_json_string(ListGroupHandle handle);
ListGroupHandle ListGroup_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif