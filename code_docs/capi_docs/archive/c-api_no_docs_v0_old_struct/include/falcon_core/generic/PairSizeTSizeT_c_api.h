#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairSizeTSizeTHandle;
// Function declarations

PairSizeTSizeTHandle PairSizeTSizeT_create(size_t first, size_t second);
void PairSizeTSizeT_destroy(PairSizeTSizeTHandle handle);
size_t PairSizeTSizeT_first(PairSizeTSizeTHandle handle);
size_t PairSizeTSizeT_second(PairSizeTSizeTHandle handle);
bool PairSizeTSizeT_equal(PairSizeTSizeTHandle a, PairSizeTSizeTHandle b);
bool PairSizeTSizeT_not_equal(PairSizeTSizeTHandle a, PairSizeTSizeTHandle b);
// Serialization (from Song)
StringHandle      PairSizeTSizeT_to_json_string(PairSizeTSizeTHandle handle);
PairSizeTSizeTHandle PairSizeTSizeT_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif