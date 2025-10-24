#pragma once
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
typedef void* AcquisitionContextHandle;

// Constructors
AcquisitionContextHandle AcquisitionContext_create(ConnectionHandle connection,
                                                   const char* instrument_type,
                                                   SymbolUnitHandle units);
AcquisitionContextHandle AcquisitionContext_create_from_port(
    InstrumentPortHandle port);

// Destructor
void AcquisitionContext_destroy(AcquisitionContextHandle handle);

// Methods
ConnectionHandle AcquisitionContext_connection(AcquisitionContextHandle handle);
const char* AcquisitionContext_instrument_type(AcquisitionContextHandle handle);
SymbolUnitHandle AcquisitionContext_units(AcquisitionContextHandle handle);
AcquisitionContextHandle AcquisitionContext_division_unit(
    AcquisitionContextHandle handle, SymbolUnitHandle other);
AcquisitionContextHandle AcquisitionContext_division(
    AcquisitionContextHandle handle, AcquisitionContextHandle other);
bool AcquisitionContext_match_connection(AcquisitionContextHandle handle,
                                         ConnectionHandle         other);
bool AcquisitionContext_match_instrument_type(AcquisitionContextHandle handle,
                                              StringHandle             other);
bool AcquisitionContext_equal(AcquisitionContextHandle a,
                              AcquisitionContextHandle b);
bool AcquisitionContext_not_equal(AcquisitionContextHandle a,
                                  AcquisitionContextHandle b);

// Serialization (from Song)
StringHandle AcquisitionContext_to_json_string(AcquisitionContextHandle handle);
AcquisitionContextHandle AcquisitionContext_from_json_string(
    const StringHandle json);

#ifdef __cplusplus
}
#endif
