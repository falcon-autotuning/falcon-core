#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon-core/autotuner_interfaces/names/Channel_c_api.h"
#include "falcon-core/generic/ListChannel_c_api.h"
#include "falcon-core/generic/ListString_c_api.h"
typedef void* ChannelsHandle;

// @category:allocation
FALCON_CORE_C_API ChannelsHandle Channels_copy(ChannelsHandle handle);
// @category:deallocation
FALCON_CORE_C_API void Channels_destroy(ChannelsHandle handle);
// @category:read
FALCON_CORE_C_API bool Channels_equal(ChannelsHandle handle,
                                      ChannelsHandle other);
// @category:read
FALCON_CORE_C_API bool Channels_not_equal(ChannelsHandle handle,
                                          ChannelsHandle other);
// @category:read
FALCON_CORE_C_API StringHandle Channels_to_json_string(ChannelsHandle handle);
// @category:allocation
FALCON_CORE_C_API ChannelsHandle Channels_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API ChannelsHandle Channels_create_empty();
// @category:allocation
FALCON_CORE_C_API ChannelsHandle Channels_create(ListChannelHandle items);
// @category:read
FALCON_CORE_C_API ChannelsHandle Channels_intersection(ChannelsHandle handle,
                                                       ChannelsHandle other);
// @category:write
FALCON_CORE_C_API void Channels_push_back(ChannelsHandle handle,
                                          ChannelHandle  value);
// @category:read
FALCON_CORE_C_API size_t Channels_size(ChannelsHandle handle);
// @category:read
FALCON_CORE_C_API bool Channels_empty(ChannelsHandle handle);
// @category:write
FALCON_CORE_C_API void Channels_erase_at(ChannelsHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void Channels_clear(ChannelsHandle handle);
// @category:read
FALCON_CORE_C_API ChannelHandle Channels_at(ChannelsHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API ListStringHandle Channels_items(ChannelsHandle handle);
// @category:read
FALCON_CORE_C_API bool Channels_contains(ChannelsHandle handle,
                                         ChannelHandle  value);
// @category:read
FALCON_CORE_C_API size_t Channels_index(ChannelsHandle handle,
                                        ChannelHandle  value);

#ifdef __cplusplus
}
#endif
