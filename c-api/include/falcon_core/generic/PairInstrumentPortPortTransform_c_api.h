#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairInstrumentPortPortTransformHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API PairInstrumentPortPortTransformHandle PairInstrumentPortPortTransform_create(InstrumentPortHandle first, PortTransformHandle second);
// @category:allocation
FALCON_CORE_C_API PairInstrumentPortPortTransformHandle PairInstrumentPortPortTransform_copy(PairInstrumentPortPortTransformHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PairInstrumentPortPortTransform_destroy(PairInstrumentPortPortTransformHandle handle);
// @category:read
FALCON_CORE_C_API InstrumentPortHandle PairInstrumentPortPortTransform_first(PairInstrumentPortPortTransformHandle handle);
// @category:read
FALCON_CORE_C_API PortTransformHandle PairInstrumentPortPortTransform_second(PairInstrumentPortPortTransformHandle handle);
// @category:read
FALCON_CORE_C_API bool PairInstrumentPortPortTransform_equal(PairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle other);
// @category:read
FALCON_CORE_C_API bool PairInstrumentPortPortTransform_not_equal(PairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      PairInstrumentPortPortTransform_to_json_string(PairInstrumentPortPortTransformHandle handle);
// @category:allocation
FALCON_CORE_C_API PairInstrumentPortPortTransformHandle PairInstrumentPortPortTransform_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif