#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/names/Channel_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListChannelHandle;
// Function declarations

// @category:allocation
ListChannelHandle ListChannel_create_empty();

// @category:allocation
ListChannelHandle ListChannel_fill_value(size_t count, ChannelHandle value);
// @category:allocation
ListChannelHandle ListChannel_create(ChannelHandle* data, size_t count);
// @category:deallocation
void ListChannel_destroy(ListChannelHandle handle);
// @category:write
void ListChannel_push_back(ListChannelHandle handle, ChannelHandle value);
// @category:read
size_t ListChannel_size(ListChannelHandle handle);
// @category:read
bool ListChannel_empty(ListChannelHandle handle);
// @category:write
/* AUTO-DOC from cpp: ListChannel_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListChannel_erase_at(ListChannelHandle handle, size_t idx);
// @category:write
/* AUTO-DOC from cpp: ListChannel_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListChannel_clear(ListChannelHandle handle);
// @category:read
ChannelHandle ListChannel_at(ListChannelHandle handle, size_t idx);
// @category:read
size_t ListChannel_items(ListChannelHandle handle, ChannelHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListChannel_contains(ListChannelHandle handle, ChannelHandle value);
// @category:read
size_t ListChannel_index(ListChannelHandle handle, ChannelHandle value);
// @category:read
/* AUTO-DOC from cpp: ListChannel_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListChannelHandle ListChannel_intersection(ListChannelHandle handle, ListChannelHandle other);
// @category:read
bool ListChannel_equal(ListChannelHandle a, ListChannelHandle b);
// @category:read
bool ListChannel_not_equal(ListChannelHandle a, ListChannelHandle b);

// @category:read
StringHandle      ListChannel_to_json_string(ListChannelHandle handle);
// @category:allocation
ListChannelHandle ListChannel_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif