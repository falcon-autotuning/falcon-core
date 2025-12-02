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

PairInstrumentPortPortTransformHandle PairInstrumentPortPortTransform_create(InstrumentPortHandle first, PortTransformHandle second);
void PairInstrumentPortPortTransform_destroy(PairInstrumentPortPortTransformHandle handle);
InstrumentPortHandle PairInstrumentPortPortTransform_first(PairInstrumentPortPortTransformHandle handle);
PortTransformHandle PairInstrumentPortPortTransform_second(PairInstrumentPortPortTransformHandle handle);
bool PairInstrumentPortPortTransform_equal(PairInstrumentPortPortTransformHandle a, PairInstrumentPortPortTransformHandle b);
bool PairInstrumentPortPortTransform_not_equal(PairInstrumentPortPortTransformHandle a, PairInstrumentPortPortTransformHandle b);
// Serialization (from Song)
StringHandle      PairInstrumentPortPortTransform_to_json_string(PairInstrumentPortPortTransformHandle handle);
PairInstrumentPortPortTransformHandle PairInstrumentPortPortTransform_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif