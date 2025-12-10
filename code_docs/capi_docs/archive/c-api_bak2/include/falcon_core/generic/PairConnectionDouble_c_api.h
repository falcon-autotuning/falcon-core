#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairConnectionDoubleHandle;
// Function declarations

// @category:allocation
PairConnectionDoubleHandle PairConnectionDouble_create(ConnectionHandle first, double second);
// @category:allocation
PairConnectionDoubleHandle PairConnectionDouble_copy(PairConnectionDoubleHandle handle);
// @category:deallocation
void PairConnectionDouble_destroy(PairConnectionDoubleHandle handle);
// @category:read
ConnectionHandle PairConnectionDouble_first(PairConnectionDoubleHandle handle);
// @category:read
double PairConnectionDouble_second(PairConnectionDoubleHandle handle);
// @category:read
bool PairConnectionDouble_equal(PairConnectionDoubleHandle handle, PairConnectionDoubleHandle other);
// @category:read
bool PairConnectionDouble_not_equal(PairConnectionDoubleHandle handle, PairConnectionDoubleHandle other);
// @category:read
StringHandle      PairConnectionDouble_to_json_string(PairConnectionDoubleHandle handle);
// @category:allocation
PairConnectionDoubleHandle PairConnectionDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif