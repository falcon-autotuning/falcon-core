#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon-core/math/Quantity_c_api.h"
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairInstrumentPortQuantityHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API PairInstrumentPortQuantityHandle PairInstrumentPortQuantity_create(InstrumentPortHandle first, QuantityHandle second);
// @category:allocation
FALCON_CORE_C_API PairInstrumentPortQuantityHandle PairInstrumentPortQuantity_copy(PairInstrumentPortQuantityHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PairInstrumentPortQuantity_destroy(PairInstrumentPortQuantityHandle handle);
// @category:read
FALCON_CORE_C_API InstrumentPortHandle PairInstrumentPortQuantity_first(PairInstrumentPortQuantityHandle handle);
// @category:read
FALCON_CORE_C_API QuantityHandle PairInstrumentPortQuantity_second(PairInstrumentPortQuantityHandle handle);
// @category:read
FALCON_CORE_C_API bool PairInstrumentPortQuantity_equal(PairInstrumentPortQuantityHandle handle, PairInstrumentPortQuantityHandle other);
// @category:read
FALCON_CORE_C_API bool PairInstrumentPortQuantity_not_equal(PairInstrumentPortQuantityHandle handle, PairInstrumentPortQuantityHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      PairInstrumentPortQuantity_to_json_string(PairInstrumentPortQuantityHandle handle);
// @category:allocation
FALCON_CORE_C_API PairInstrumentPortQuantityHandle PairInstrumentPortQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif