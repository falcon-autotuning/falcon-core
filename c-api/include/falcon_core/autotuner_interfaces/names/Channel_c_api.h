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
