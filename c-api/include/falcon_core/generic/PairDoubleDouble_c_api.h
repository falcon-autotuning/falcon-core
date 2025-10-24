#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairDoubleDoubleHandle;
// Function declarations

PairDoubleDoubleHandle PairDoubleDouble_create(double first, double second);
void PairDoubleDouble_destroy(PairDoubleDoubleHandle handle);
double PairDoubleDouble_first(PairDoubleDoubleHandle handle);
double PairDoubleDouble_second(PairDoubleDoubleHandle handle);
bool PairDoubleDouble_equal(PairDoubleDoubleHandle a, PairDoubleDoubleHandle b);
// Serialization (from Song)
StringHandle      PairDoubleDouble_to_json_string(PairDoubleDoubleHandle handle);
PairDoubleDoubleHandle PairDoubleDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif