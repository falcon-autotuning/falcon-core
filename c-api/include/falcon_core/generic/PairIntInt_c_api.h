#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairIntIntHandle;
// Function declarations

// @category:allocation
PairIntIntHandle PairIntInt_create(int first, int second);
// @category:allocation
PairIntIntHandle PairIntInt_copy(PairIntIntHandle handle);
// @category:deallocation
void PairIntInt_destroy(PairIntIntHandle handle);
// @category:read
int PairIntInt_first(PairIntIntHandle handle);
// @category:read
int PairIntInt_second(PairIntIntHandle handle);
// @category:read
bool PairIntInt_equal(PairIntIntHandle handle, PairIntIntHandle other);
// @category:read
bool PairIntInt_not_equal(PairIntIntHandle handle, PairIntIntHandle other);
// @category:read
StringHandle      PairIntInt_to_json_string(PairIntIntHandle handle);
// @category:allocation
PairIntIntHandle PairIntInt_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif