#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/names/Channel_c_api.h"
#include <cstddef>

// Forward declarations for opaque handles
typedef void* ListChannelHandle;
// Function declarations

ListChannelHandle ListChannel_create_empty();
ListChannelHandle ListChannel_allocate(size_t count);
ListChannelHandle ListChannel_fill_value(size_t count, ChannelHandle value);
ListChannelHandle ListChannel_create(const ChannelHandle* data, size_t count);
void ListChannel_destroy(ListChannelHandle handle);
void ListChannel_push_back(ListChannelHandle handle, ChannelHandle value);
size_t ListChannel_size(ListChannelHandle handle);
bool ListChannel_empty(ListChannelHandle handle);
void ListChannel_erase_at(ListChannelHandle handle, size_t idx);
void ListChannel_clear(ListChannelHandle handle);
ChannelHandle ListChannel_at(ListChannelHandle handle, size_t idx);
size_t ListChannel_items(ListChannelHandle handle, ChannelHandle* out_buffer, size_t buffer_size);
bool ListChannel_contains(ListChannelHandle handle, ChannelHandle value);
size_t ListChannel_index(ListChannelHandle handle, ChannelHandle value);
ListChannelHandle ListChannel_intersection(ListChannelHandle handle, ListChannelHandle other);
bool ListChannel_equal(ListChannelHandle a, ListChannelHandle b);
bool ListChannel_not_equal(ListChannelHandle a, ListChannelHandle b);

// Serialization (from Song)
const char*      ListChannel_to_json_string(ListChannelHandle handle);
ListChannelHandle ListChannel_from_json_string(const char* json);

#ifdef __cplusplus
}
#endif