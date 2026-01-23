#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/export_c_api.h"
#include "falcon_core/generic/String_c_api.h"
typedef void* StandardRequestHandle;

// @category:allocation
FALCON_CORE_C_API StandardRequestHandle
StandardRequest_copy(StandardRequestHandle handle);
// @category:deallocation
FALCON_CORE_C_API void StandardRequest_destroy(StandardRequestHandle handle);
// @category:read
FALCON_CORE_C_API bool StandardRequest_equal(StandardRequestHandle handle,
                                             StandardRequestHandle other);
// @category:read
FALCON_CORE_C_API bool StandardRequest_not_equal(StandardRequestHandle handle,
                                                 StandardRequestHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
StandardRequest_to_json_string(StandardRequestHandle handle);
// @category:allocation
FALCON_CORE_C_API StandardRequestHandle
StandardRequest_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API StandardRequestHandle
StandardRequest_create(StringHandle message);
// @category:read
FALCON_CORE_C_API StringHandle
StandardRequest_message(StandardRequestHandle handle);

#ifdef __cplusplus
}
#endif
