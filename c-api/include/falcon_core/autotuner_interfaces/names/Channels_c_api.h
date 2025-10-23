#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/autotuner_interfaces/names/Channel_c_api.h"
#include "falcon_core/generic/ListChannel_c_api.h"
typedef void* ChannelsHandle;

// Constructors
ChannelsHandle Channels_create_empty();
ChannelsHandle Channels_create(ListChannelHandle items);

// Destructor
void Channels_destroy(ChannelsHandle handle);

// Methods
ChannelsHandle Channels_intersection(ChannelsHandle handle,
                                     ChannelsHandle other);
void           Channels_push_back(ChannelsHandle handle, ChannelHandle value);
size_t         Channels_size(ChannelsHandle handle);
bool           Channels_empty(ChannelsHandle handle);
void           Channels_erase_at(ChannelsHandle handle, size_t idx);
void           Channels_clear(ChannelsHandle handle);
const ChannelHandle Channels_const_at(ChannelsHandle handle, size_t idx);
ChannelHandle       Channels_at(ChannelsHandle handle, size_t idx);
size_t              Channels_items(ChannelsHandle handle,
                                   ChannelHandle* out_buffer,
                                   size_t         buffer_size);
bool   Channels_contains(ChannelsHandle handle, ChannelHandle value);
size_t Channels_index(ChannelsHandle handle, ChannelHandle value);
bool   Channels_equal(ChannelsHandle a, ChannelsHandle b);
bool   Channels_not_equal(ChannelsHandle a, ChannelsHandle b);

// Serialization (from Song)
const char*    Channels_to_json_string(ChannelsHandle handle);
ChannelsHandle Channels_from_json_string(const char* json);

#ifdef __cplusplus
}
#endif
