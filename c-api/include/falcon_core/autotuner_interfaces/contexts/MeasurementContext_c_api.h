#pragma once
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
typedef void* MeasurementContextHandle;

// Constructors
MeasurementContextHandle MeasurementContext_create(ConnectionHandle connection,
                                                   const char* instrument_type,
                                                   SymbolUnitHandle units);
MeasurementContextHandle MeasurementContext_create_from_port(
    InstrumentPortHandle port);

// Destructor
void MeasurementContext_destroy(MeasurementContextHandle handle);

// Methods
ConnectionHandle MeasurementContext_connection(MeasurementContextHandle handle);
const char* MeasurementContext_instrument_type(MeasurementContextHandle handle);
bool        MeasurementContext_equal(MeasurementContextHandle a,
                                     MeasurementContextHandle b);
bool        MeasurementContext_not_equal(MeasurementContextHandle a,
                                         MeasurementContextHandle b);

// Serialization (from Song)
const char* MeasurementContext_to_json_string(MeasurementContextHandle handle);
MeasurementContextHandle MeasurementContext_from_json_string(const char* json);

#ifdef __cplusplus
}
#endif
