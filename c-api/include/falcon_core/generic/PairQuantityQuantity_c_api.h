#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/Quantity_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairQuantityQuantityHandle;
// Function declarations

PairQuantityQuantityHandle PairQuantityQuantity_create(QuantityHandle first, QuantityHandle second);
void PairQuantityQuantity_destroy(PairQuantityQuantityHandle handle);
QuantityHandle PairQuantityQuantity_first(PairQuantityQuantityHandle handle);
QuantityHandle PairQuantityQuantity_second(PairQuantityQuantityHandle handle);
bool PairQuantityQuantity_equal(PairQuantityQuantityHandle a, PairQuantityQuantityHandle b);
// Serialization (from Song)
StringHandle      PairQuantityQuantity_to_json_string(PairQuantityQuantityHandle handle);
PairQuantityQuantityHandle PairQuantityQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif