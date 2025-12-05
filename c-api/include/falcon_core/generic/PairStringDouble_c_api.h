#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairStringDoubleHandle;
// Function declarations

// @category:allocation
PairStringDoubleHandle PairStringDouble_create(StringHandle first, double second);
// @category:deallocation
void PairStringDouble_destroy(PairStringDoubleHandle handle);
// @category:read
StringHandle PairStringDouble_first(PairStringDoubleHandle handle);
// @category:read
double PairStringDouble_second(PairStringDoubleHandle handle);
// @category:read
bool PairStringDouble_equal(PairStringDoubleHandle a, PairStringDoubleHandle b);
// @category:read
bool PairStringDouble_not_equal(PairStringDoubleHandle a, PairStringDoubleHandle b);
// @category:read
StringHandle      PairStringDouble_to_json_string(PairStringDoubleHandle handle);
// @category:allocation
PairStringDoubleHandle PairStringDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif