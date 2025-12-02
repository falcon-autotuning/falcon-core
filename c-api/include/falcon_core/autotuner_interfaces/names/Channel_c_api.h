#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"

typedef void* ChannelHandle;

// @category:allocation
ChannelHandle Channel_create(StringHandle name);
// @category:deallocation
void Channel_destroy(ChannelHandle handle);
// @category:read
StringHandle Channel_name(ChannelHandle handle);
// @category:read
bool Channel_equal(ChannelHandle a, ChannelHandle b);
// @category:read
bool Channel_not_equal(ChannelHandle a, ChannelHandle b);
// @category:read
StringHandle Channel_to_json_string(ChannelHandle handle);
// @category:allocation
ChannelHandle Channel_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
