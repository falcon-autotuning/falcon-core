#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* GnameHandle;

// @category:allocation
GnameHandle Gname_create_from_num(int num);
// @category:allocation
GnameHandle Gname_create(StringHandle name);
// @category:deallocation
void Gname_destroy(GnameHandle handle);
// @category:read
StringHandle Gname_gname(GnameHandle handle);
// @category:read
bool Gname_equal(GnameHandle a, GnameHandle b);
// @category:read
bool Gname_not_equal(GnameHandle a, GnameHandle b);
// @category:read
StringHandle Gname_to_json_string(GnameHandle handle);
// @category:allocation
GnameHandle Gname_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
