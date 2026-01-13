

# File ListChannel\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListChannel\_c\_api.h**](ListChannel__c__api_8h.md)

[Go to the documentation of this file](ListChannel__c__api_8h.md)


```C++
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
ListChannelHandle ListChannel_copy(ListChannelHandle handle);

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
void ListChannel_erase_at(ListChannelHandle handle, size_t idx);
// @category:write
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
ListChannelHandle ListChannel_intersection(ListChannelHandle handle, ListChannelHandle other);
// @category:read
bool ListChannel_equal(ListChannelHandle handle, ListChannelHandle other);
// @category:read
bool ListChannel_not_equal(ListChannelHandle handle, ListChannelHandle other);

// @category:read
StringHandle      ListChannel_to_json_string(ListChannelHandle handle);
// @category:allocation
ListChannelHandle ListChannel_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


