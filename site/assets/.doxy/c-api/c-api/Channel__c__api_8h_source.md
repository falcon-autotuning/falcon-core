

# File Channel\_c\_api.h

[**File List**](files.md) **>** [**autotuner\_interfaces**](dir_a97a284a51e1fae1832044fe1b75b0a4.md) **>** [**names**](dir_ad3a832d6f582aa08d8da369374ec299.md) **>** [**Channel\_c\_api.h**](Channel__c__api_8h.md)

[Go to the documentation of this file](Channel__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"

typedef void* ChannelHandle;

// @category:allocation
ChannelHandle Channel_copy(ChannelHandle handle);
// @category:deallocation
void Channel_destroy(ChannelHandle handle);
// @category:read
bool Channel_equal(ChannelHandle handle, ChannelHandle other);
// @category:read
bool Channel_not_equal(ChannelHandle handle, ChannelHandle other);
// @category:read
StringHandle Channel_to_json_string(ChannelHandle handle);
// @category:allocation
ChannelHandle Channel_from_json_string(StringHandle json);
// @category:allocation
ChannelHandle Channel_create(StringHandle name);
// @category:read
StringHandle Channel_name(ChannelHandle handle);

#ifdef __cplusplus
}
#endif
```


