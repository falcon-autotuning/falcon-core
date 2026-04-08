#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/autotuner_interfaces/names/Gname_c_api.h"
#include "falcon-core/physics/config/core/Group_c_api.h"
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairGnameGroupHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API PairGnameGroupHandle PairGnameGroup_create(GnameHandle first, GroupHandle second);
// @category:allocation
FALCON_CORE_C_API PairGnameGroupHandle PairGnameGroup_copy(PairGnameGroupHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PairGnameGroup_destroy(PairGnameGroupHandle handle);
// @category:read
FALCON_CORE_C_API GnameHandle PairGnameGroup_first(PairGnameGroupHandle handle);
// @category:read
FALCON_CORE_C_API GroupHandle PairGnameGroup_second(PairGnameGroupHandle handle);
// @category:read
FALCON_CORE_C_API bool PairGnameGroup_equal(PairGnameGroupHandle handle, PairGnameGroupHandle other);
// @category:read
FALCON_CORE_C_API bool PairGnameGroup_not_equal(PairGnameGroupHandle handle, PairGnameGroupHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      PairGnameGroup_to_json_string(PairGnameGroupHandle handle);
// @category:allocation
FALCON_CORE_C_API PairGnameGroupHandle PairGnameGroup_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif