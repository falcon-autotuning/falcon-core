#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairDoubleDoubleHandle;
// Function declarations

// @category:allocation
PairDoubleDoubleHandle PairDoubleDouble_create(double first, double second);
// @category:deallocation
void PairDoubleDouble_destroy(PairDoubleDoubleHandle handle);
// @category:read
double PairDoubleDouble_first(PairDoubleDoubleHandle handle);
// @category:read
double PairDoubleDouble_second(PairDoubleDoubleHandle handle);
// @category:read
bool PairDoubleDouble_equal(PairDoubleDoubleHandle a, PairDoubleDoubleHandle b);
// @category:read
bool PairDoubleDouble_not_equal(PairDoubleDoubleHandle a, PairDoubleDoubleHandle b);
// @category:read
StringHandle      PairDoubleDouble_to_json_string(PairDoubleDoubleHandle handle);
// @category:allocation
PairDoubleDoubleHandle PairDoubleDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif