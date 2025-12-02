#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* StandardRequestHandle;

// Constructors
StandardRequestHandle StandardRequest_create(StringHandle message);

// Destructor
void StandardRequest_destroy(StandardRequestHandle handle);

// Methods
StringHandle StandardRequest_message(StandardRequestHandle handle);
bool         StandardRequest_equal(StandardRequestHandle handle,
                                   StandardRequestHandle other);
bool         StandardRequest_not_equal(StandardRequestHandle handle,
                                       StandardRequestHandle other);

// Serialization (from Song)
StringHandle StandardRequest_to_json_string(StandardRequestHandle handle);
StandardRequestHandle StandardRequest_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
