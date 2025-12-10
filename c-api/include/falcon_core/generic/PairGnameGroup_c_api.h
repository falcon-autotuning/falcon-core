#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/names/Gname_c_api.h"
#include "falcon_core/physics/config/core/Group_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairGnameGroupHandle;
// Function declarations

// @category:allocation
PairGnameGroupHandle PairGnameGroup_create(GnameHandle first, GroupHandle second);
// @category:allocation
PairGnameGroupHandle PairGnameGroup_copy(PairGnameGroupHandle handle);
// @category:deallocation
void PairGnameGroup_destroy(PairGnameGroupHandle handle);
// @category:read
GnameHandle PairGnameGroup_first(PairGnameGroupHandle handle);
// @category:read
GroupHandle PairGnameGroup_second(PairGnameGroupHandle handle);
// @category:read
bool PairGnameGroup_equal(PairGnameGroupHandle handle, PairGnameGroupHandle other);
// @category:read
bool PairGnameGroup_not_equal(PairGnameGroupHandle handle, PairGnameGroupHandle other);
// @category:read
StringHandle      PairGnameGroup_to_json_string(PairGnameGroupHandle handle);
// @category:allocation
PairGnameGroupHandle PairGnameGroup_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif