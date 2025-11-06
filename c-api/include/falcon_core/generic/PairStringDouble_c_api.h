#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairStringDoubleHandle;
// Function declarations

PairStringDoubleHandle PairStringDouble_create(StringHandle first, double second);
void PairStringDouble_destroy(PairStringDoubleHandle handle);
StringHandle PairStringDouble_first(PairStringDoubleHandle handle);
double PairStringDouble_second(PairStringDoubleHandle handle);
bool PairStringDouble_equal(PairStringDoubleHandle a, PairStringDoubleHandle b);
bool PairStringDouble_not_equal(PairStringDoubleHandle a, PairStringDoubleHandle b);
// Serialization (from Song)
StringHandle      PairStringDouble_to_json_string(PairStringDoubleHandle handle);
PairStringDoubleHandle PairStringDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif