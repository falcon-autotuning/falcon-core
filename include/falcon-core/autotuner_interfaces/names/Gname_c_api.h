#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon-core/export_c_api.h"
#include "falcon-core/generic/String_c_api.h"
typedef void* GnameHandle;

// @category:allocation
FALCON_CORE_C_API GnameHandle Gname_copy(GnameHandle handle);
// @category:deallocation
FALCON_CORE_C_API void Gname_destroy(GnameHandle handle);
// @category:read
FALCON_CORE_C_API bool Gname_equal(GnameHandle handle, GnameHandle other);
// @category:read
FALCON_CORE_C_API bool Gname_not_equal(GnameHandle handle, GnameHandle other);
// @category:read
FALCON_CORE_C_API StringHandle Gname_to_json_string(GnameHandle handle);
// @category:allocation
FALCON_CORE_C_API GnameHandle Gname_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API GnameHandle Gname_create_from_num(int num);
// @category:allocation
FALCON_CORE_C_API GnameHandle Gname_create(StringHandle name);
// @category:read
/* AUTO-DOC from cpp: Gname_gname |
 * falcon_core::autotuner_interfaces::names::Gname::gname */
/**
 * @brief Collect the gname as a string.
 */
FALCON_CORE_C_API StringHandle Gname_gname(GnameHandle handle);

#ifdef __cplusplus
}
#endif
