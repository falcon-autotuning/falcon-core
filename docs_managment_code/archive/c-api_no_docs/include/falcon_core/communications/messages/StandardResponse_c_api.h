#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* StandardResponseHandle;

// Constructors
StandardResponseHandle StandardResponse_create(StringHandle message);

// Destructor
void StandardResponse_destroy(StandardResponseHandle handle);

// Methods
StringHandle StandardResponse_message(StandardResponseHandle handle);
bool         StandardResponse_equal(StandardResponseHandle handle,
                                    StandardResponseHandle other);
bool         StandardResponse_not_equal(StandardResponseHandle handle,
                                        StandardResponseHandle other);

// Serialization (from Song)
StringHandle StandardResponse_to_json_string(StandardResponseHandle handle);
StandardResponseHandle StandardResponse_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
