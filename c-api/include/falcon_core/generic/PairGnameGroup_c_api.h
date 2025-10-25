#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/names/Gname_c_api.h"
#include "falcon_core/physics/config/core/Group_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairGnameGroupHandle;
// Function declarations

PairGnameGroupHandle PairGnameGroup_create(GnameHandle first, GroupHandle second);
void PairGnameGroup_destroy(PairGnameGroupHandle handle);
GnameHandle PairGnameGroup_first(PairGnameGroupHandle handle);
GroupHandle PairGnameGroup_second(PairGnameGroupHandle handle);
bool PairGnameGroup_equal(PairGnameGroupHandle a, PairGnameGroupHandle b);
// Serialization (from Song)
StringHandle      PairGnameGroup_to_json_string(PairGnameGroupHandle handle);
PairGnameGroupHandle PairGnameGroup_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif