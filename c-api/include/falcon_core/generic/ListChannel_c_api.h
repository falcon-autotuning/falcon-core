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
FALCON_CORE_C_API ListChannelHandle ListChannel_create_empty();
// @category:allocation
FALCON_CORE_C_API ListChannelHandle ListChannel_copy(ListChannelHandle handle);

// @category:allocation
FALCON_CORE_C_API ListChannelHandle ListChannel_fill_value(size_t count, ChannelHandle value);
// @category:allocation
FALCON_CORE_C_API ListChannelHandle ListChannel_create(ChannelHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListChannel_destroy(ListChannelHandle handle);
// @category:write
FALCON_CORE_C_API void ListChannel_push_back(ListChannelHandle handle, ChannelHandle value);
// @category:read
FALCON_CORE_C_API size_t ListChannel_size(ListChannelHandle handle);
// @category:read
FALCON_CORE_C_API bool ListChannel_empty(ListChannelHandle handle);
// @category:write
FALCON_CORE_C_API void ListChannel_erase_at(ListChannelHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListChannel_clear(ListChannelHandle handle);
// @category:read
FALCON_CORE_C_API ChannelHandle ListChannel_at(ListChannelHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListChannel_items(ListChannelHandle handle, ChannelHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListChannel_contains(ListChannelHandle handle, ChannelHandle value);
// @category:read
FALCON_CORE_C_API size_t ListChannel_index(ListChannelHandle handle, ChannelHandle value);
// @category:read
FALCON_CORE_C_API ListChannelHandle ListChannel_intersection(ListChannelHandle handle, ListChannelHandle other);
// @category:read
FALCON_CORE_C_API bool ListChannel_equal(ListChannelHandle handle, ListChannelHandle other);
// @category:read
FALCON_CORE_C_API bool ListChannel_not_equal(ListChannelHandle handle, ListChannelHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListChannel_to_json_string(ListChannelHandle handle);
// @category:allocation
FALCON_CORE_C_API ListChannelHandle ListChannel_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif