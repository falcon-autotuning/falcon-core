#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/autotuner_interfaces/names/Channel_c_api.h"
#include "falcon_core/generic/ListChannel_c_api.h"
#include "falcon_core/generic/ListString_c_api.h"
typedef void* ChannelsHandle;

// @category:allocation
ChannelsHandle Channels_create_empty();
// @category:allocation
ChannelsHandle Channels_create(ListChannelHandle items);
// @category:deallocation
void Channels_destroy(ChannelsHandle handle);
// @category:read
ChannelsHandle Channels_intersection(ChannelsHandle handle,
                                     ChannelsHandle other);
// @category:write
void Channels_push_back(ChannelsHandle handle, ChannelHandle value);
// @category:read
size_t Channels_size(ChannelsHandle handle);
// @category:read
bool Channels_empty(ChannelsHandle handle);
// @category:write
void Channels_erase_at(ChannelsHandle handle, size_t idx);
// @category:write
void Channels_clear(ChannelsHandle handle);
// @category:read
ChannelHandle Channels_at(ChannelsHandle handle, size_t idx);
// @category:read
ListStringHandle Channels_items(ChannelsHandle handle);
// @category:read
bool Channels_contains(ChannelsHandle handle, ChannelHandle value);
// @category:read
size_t Channels_index(ChannelsHandle handle, ChannelHandle value);
// @category:read
bool Channels_equal(ChannelsHandle a, ChannelsHandle b);
// @category:read
bool Channels_not_equal(ChannelsHandle a, ChannelsHandle b);
// @category:read
StringHandle Channels_to_json_string(ChannelsHandle handle);
// @category:allocation
ChannelsHandle Channels_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
