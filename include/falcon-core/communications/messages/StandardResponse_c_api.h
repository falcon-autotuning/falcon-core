#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon-core/export_c_api.h"
#include "falcon-core/generic/String_c_api.h"
typedef void* StandardResponseHandle;

// @category:allocation
FALCON_CORE_C_API StandardResponseHandle
StandardResponse_copy(StandardResponseHandle handle);
// @category:deallocation
FALCON_CORE_C_API void StandardResponse_destroy(StandardResponseHandle handle);
// @category:read
FALCON_CORE_C_API bool StandardResponse_equal(StandardResponseHandle handle,
                                              StandardResponseHandle other);
// @category:read
FALCON_CORE_C_API bool StandardResponse_not_equal(StandardResponseHandle handle,
                                                  StandardResponseHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
StandardResponse_to_json_string(StandardResponseHandle handle);
// @category:allocation
FALCON_CORE_C_API StandardResponseHandle
StandardResponse_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API StandardResponseHandle
StandardResponse_create(StringHandle message);
// @category:read
FALCON_CORE_C_API StringHandle
StandardResponse_message(StandardResponseHandle handle);

#ifdef __cplusplus
}
#endif
