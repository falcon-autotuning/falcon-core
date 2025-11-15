#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairStringStringHandle;
// Function declarations

PairStringStringHandle PairStringString_create(StringHandle first, StringHandle second);
void PairStringString_destroy(PairStringStringHandle handle);
StringHandle PairStringString_first(PairStringStringHandle handle);
StringHandle PairStringString_second(PairStringStringHandle handle);
bool PairStringString_equal(PairStringStringHandle a, PairStringStringHandle b);
bool PairStringString_not_equal(PairStringStringHandle a, PairStringStringHandle b);
// Serialization (from Song)
StringHandle      PairStringString_to_json_string(PairStringStringHandle handle);
PairStringStringHandle PairStringString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif