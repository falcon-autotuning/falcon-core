#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* StandardRequestHandle;

// @category:allocation
StandardRequestHandle StandardRequest_create(StringHandle message);
// @category:deallocation
void StandardRequest_destroy(StandardRequestHandle handle);
// @category:read
StringHandle StandardRequest_message(StandardRequestHandle handle);
// @category:read
bool StandardRequest_equal(StandardRequestHandle handle,
                           StandardRequestHandle other);
// @category:read
bool StandardRequest_not_equal(StandardRequestHandle handle,
                               StandardRequestHandle other);
// @category:read
StringHandle StandardRequest_to_json_string(StandardRequestHandle handle);
// @category:allocation
StandardRequestHandle StandardRequest_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
