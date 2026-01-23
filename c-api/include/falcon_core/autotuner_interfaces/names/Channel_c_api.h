#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

#include "falcon_core/export_c_api.h"
#include "falcon_core/generic/String_c_api.h"

typedef void* ChannelHandle;

// @category:allocation
FALCON_CORE_C_API ChannelHandle Channel_copy(ChannelHandle handle);
// @category:deallocation
FALCON_CORE_C_API void Channel_destroy(ChannelHandle handle);
// @category:read
FALCON_CORE_C_API bool Channel_equal(ChannelHandle handle, ChannelHandle other);
// @category:read
FALCON_CORE_C_API bool Channel_not_equal(ChannelHandle handle,
                                         ChannelHandle other);
// @category:read
FALCON_CORE_C_API StringHandle Channel_to_json_string(ChannelHandle handle);
// @category:allocation
FALCON_CORE_C_API ChannelHandle Channel_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API ChannelHandle Channel_create(StringHandle name);
// @category:read
FALCON_CORE_C_API StringHandle Channel_name(ChannelHandle handle);

#ifdef __cplusplus
}
#endif
