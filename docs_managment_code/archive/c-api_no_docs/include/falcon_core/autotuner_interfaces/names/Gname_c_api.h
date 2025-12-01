#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* GnameHandle;

// Constructors
GnameHandle Gname_create_from_num(int num);
GnameHandle Gname_create(StringHandle name);

// Destructor
void Gname_destroy(GnameHandle handle);

// Methods
StringHandle Gname_gname(GnameHandle handle);
bool         Gname_equal(GnameHandle a, GnameHandle b);
bool         Gname_not_equal(GnameHandle a, GnameHandle b);

// Serialization (from Song)
StringHandle Gname_to_json_string(GnameHandle handle);
GnameHandle  Gname_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
