

# File Channels\_c\_api.h

[**File List**](files.md) **>** [**autotuner\_interfaces**](dir_a97a284a51e1fae1832044fe1b75b0a4.md) **>** [**names**](dir_ad3a832d6f582aa08d8da369374ec299.md) **>** [**Channels\_c\_api.h**](Channels__c__api_8h.md)

[Go to the documentation of this file](Channels__c__api_8h.md)


```C++
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
ChannelsHandle Channels_copy(ChannelsHandle handle);
// @category:deallocation
void Channels_destroy(ChannelsHandle handle);
// @category:read
bool Channels_equal(ChannelsHandle handle, ChannelsHandle other);
// @category:read
bool Channels_not_equal(ChannelsHandle handle, ChannelsHandle other);
// @category:read
StringHandle Channels_to_json_string(ChannelsHandle handle);
// @category:allocation
ChannelsHandle Channels_from_json_string(StringHandle json);
// @category:allocation
ChannelsHandle Channels_create_empty();
// @category:allocation
ChannelsHandle Channels_create(ListChannelHandle items);
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

#ifdef __cplusplus
}
#endif
```


