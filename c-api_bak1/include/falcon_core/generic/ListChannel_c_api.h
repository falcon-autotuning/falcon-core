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

ListChannelHandle ListChannel_create_empty();

ListChannelHandle ListChannel_fill_value(size_t count, ChannelHandle value);
ListChannelHandle ListChannel_create(ChannelHandle* data, size_t count);
void ListChannel_destroy(ListChannelHandle handle);
void ListChannel_push_back(ListChannelHandle handle, ChannelHandle value);
size_t ListChannel_size(ListChannelHandle handle);
bool ListChannel_empty(ListChannelHandle handle);
/* AUTO-DOC from cpp: ListChannel_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListChannel_erase_at(ListChannelHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListChannel_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListChannel_clear(ListChannelHandle handle);
ChannelHandle ListChannel_at(ListChannelHandle handle, size_t idx);
size_t ListChannel_items(ListChannelHandle handle, ChannelHandle* out_buffer, size_t buffer_size);
bool ListChannel_contains(ListChannelHandle handle, ChannelHandle value);
size_t ListChannel_index(ListChannelHandle handle, ChannelHandle value);
/* AUTO-DOC from cpp: ListChannel_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListChannelHandle ListChannel_intersection(ListChannelHandle handle, ListChannelHandle other);
bool ListChannel_equal(ListChannelHandle a, ListChannelHandle b);
bool ListChannel_not_equal(ListChannelHandle a, ListChannelHandle b);

// Serialization (from Song)
/* AUTO-DOC from cpp: ListChannel_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      ListChannel_to_json_string(ListChannelHandle handle);
/* AUTO-DOC from cpp: ListChannel_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
ListChannelHandle ListChannel_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif