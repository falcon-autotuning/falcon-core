#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairStringBoolHandle;
// Function declarations

PairStringBoolHandle PairStringBool_create(StringHandle first, bool second);
void PairStringBool_destroy(PairStringBoolHandle handle);
StringHandle PairStringBool_first(PairStringBoolHandle handle);
bool PairStringBool_second(PairStringBoolHandle handle);
bool PairStringBool_equal(PairStringBoolHandle a, PairStringBoolHandle b);
// Serialization (from Song)
StringHandle      PairStringBool_to_json_string(PairStringBoolHandle handle);
PairStringBoolHandle PairStringBool_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif