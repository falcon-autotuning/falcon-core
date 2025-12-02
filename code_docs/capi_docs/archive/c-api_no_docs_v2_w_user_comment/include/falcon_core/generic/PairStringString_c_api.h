#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairStringStringHandle;
// Function declarations

// @category:allocation
PairStringStringHandle PairStringString_create(StringHandle first, StringHandle second);
// @category:deallocation
void PairStringString_destroy(PairStringStringHandle handle);
// @category:read
StringHandle PairStringString_first(PairStringStringHandle handle);
// @category:read
StringHandle PairStringString_second(PairStringStringHandle handle);
// @category:read
bool PairStringString_equal(PairStringStringHandle a, PairStringStringHandle b);
// @category:read
bool PairStringString_not_equal(PairStringStringHandle a, PairStringStringHandle b);
// @category:read
StringHandle      PairStringString_to_json_string(PairStringStringHandle handle);
// @category:allocation
PairStringStringHandle PairStringString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif