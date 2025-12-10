#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairStringBoolHandle;
// Function declarations

// @category:allocation
PairStringBoolHandle PairStringBool_create(StringHandle first, bool second);
// @category:deallocation
void PairStringBool_destroy(PairStringBoolHandle handle);
// @category:read
StringHandle PairStringBool_first(PairStringBoolHandle handle);
// @category:read
bool PairStringBool_second(PairStringBoolHandle handle);
// @category:read
bool PairStringBool_equal(PairStringBoolHandle a, PairStringBoolHandle b);
// @category:read
bool PairStringBool_not_equal(PairStringBoolHandle a, PairStringBoolHandle b);
// @category:read
StringHandle      PairStringBool_to_json_string(PairStringBoolHandle handle);
// @category:allocation
PairStringBoolHandle PairStringBool_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif