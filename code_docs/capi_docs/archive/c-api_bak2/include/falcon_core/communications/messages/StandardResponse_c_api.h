#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* StandardResponseHandle;

// @category:allocation
StandardResponseHandle StandardResponse_copy(StandardResponseHandle handle);
// @category:deallocation
void StandardResponse_destroy(StandardResponseHandle handle);
// @category:read
bool StandardResponse_equal(StandardResponseHandle handle,
                            StandardResponseHandle other);
// @category:read
bool StandardResponse_not_equal(StandardResponseHandle handle,
                                StandardResponseHandle other);
// @category:read
StringHandle StandardResponse_to_json_string(StandardResponseHandle handle);
// @category:allocation
StandardResponseHandle StandardResponse_from_json_string(StringHandle json);
// @category:allocation
StandardResponseHandle StandardResponse_create(StringHandle message);
// @category:read
StringHandle StandardResponse_message(StandardResponseHandle handle);

#ifdef __cplusplus
}
#endif
