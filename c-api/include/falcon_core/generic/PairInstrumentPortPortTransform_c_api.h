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
PairInstrumentPortPortTransformHandle PairInstrumentPortPortTransform_create(InstrumentPortHandle first, PortTransformHandle second);
// @category:allocation
PairInstrumentPortPortTransformHandle PairInstrumentPortPortTransform_copy(PairInstrumentPortPortTransformHandle handle);
// @category:deallocation
void PairInstrumentPortPortTransform_destroy(PairInstrumentPortPortTransformHandle handle);
// @category:read
InstrumentPortHandle PairInstrumentPortPortTransform_first(PairInstrumentPortPortTransformHandle handle);
// @category:read
PortTransformHandle PairInstrumentPortPortTransform_second(PairInstrumentPortPortTransformHandle handle);
// @category:read
bool PairInstrumentPortPortTransform_equal(PairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle other);
// @category:read
bool PairInstrumentPortPortTransform_not_equal(PairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle other);
// @category:read
StringHandle      PairInstrumentPortPortTransform_to_json_string(PairInstrumentPortPortTransformHandle handle);
// @category:allocation
PairInstrumentPortPortTransformHandle PairInstrumentPortPortTransform_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif