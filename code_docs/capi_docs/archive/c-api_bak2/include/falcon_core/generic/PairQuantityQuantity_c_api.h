#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/Quantity_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairQuantityQuantityHandle;
// Function declarations

// @category:allocation
PairQuantityQuantityHandle PairQuantityQuantity_create(QuantityHandle first, QuantityHandle second);
// @category:allocation
PairQuantityQuantityHandle PairQuantityQuantity_copy(PairQuantityQuantityHandle handle);
// @category:deallocation
void PairQuantityQuantity_destroy(PairQuantityQuantityHandle handle);
// @category:read
QuantityHandle PairQuantityQuantity_first(PairQuantityQuantityHandle handle);
// @category:read
QuantityHandle PairQuantityQuantity_second(PairQuantityQuantityHandle handle);
// @category:read
bool PairQuantityQuantity_equal(PairQuantityQuantityHandle handle, PairQuantityQuantityHandle other);
// @category:read
bool PairQuantityQuantity_not_equal(PairQuantityQuantityHandle handle, PairQuantityQuantityHandle other);
// @category:read
StringHandle      PairQuantityQuantity_to_json_string(PairQuantityQuantityHandle handle);
// @category:allocation
PairQuantityQuantityHandle PairQuantityQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif