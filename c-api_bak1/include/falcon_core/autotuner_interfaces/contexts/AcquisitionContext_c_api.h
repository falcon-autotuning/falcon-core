#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
typedef void* AcquisitionContextHandle;

// Constructors
AcquisitionContextHandle AcquisitionContext_create(ConnectionHandle connection,
                                                   StringHandle instrument_type,
                                                   SymbolUnitHandle units);
AcquisitionContextHandle AcquisitionContext_create_from_port(
    InstrumentPortHandle port);

// Destructor
void AcquisitionContext_destroy(AcquisitionContextHandle handle);

// Methods
/* AUTO-DOC from cpp: AcquisitionContext_connection | falcon_core::autotuner_interfaces::contexts::BaseContext::connection */
/**
 * @brief (from C++: falcon_core::autotuner_interfaces::contexts::BaseContext::connection)
 * @brief Return the connection.
 */
ConnectionHandle AcquisitionContext_connection(AcquisitionContextHandle handle);
/* AUTO-DOC from cpp: AcquisitionContext_instrument_type | falcon_core::autotuner_interfaces::contexts::BaseContext::instrument_type */
/**
 * @brief (from C++: falcon_core::autotuner_interfaces::contexts::BaseContext::instrument_type)
 * @brief Return the instrument type.
 */
StringHandle     AcquisitionContext_instrument_type(
        AcquisitionContextHandle handle);
/* AUTO-DOC from cpp: AcquisitionContext_units | falcon_core::autotuner_interfaces::contexts::AcquisitionContext::units */
/**
 * @brief (from C++: falcon_core::autotuner_interfaces::contexts::AcquisitionContext::units)
 * @brief Returns the units of the context.
 */
SymbolUnitHandle AcquisitionContext_units(AcquisitionContextHandle handle);
AcquisitionContextHandle AcquisitionContext_division_unit(
    AcquisitionContextHandle handle, SymbolUnitHandle other);
AcquisitionContextHandle AcquisitionContext_division(
    AcquisitionContextHandle handle, AcquisitionContextHandle other);
/* AUTO-DOC from cpp: AcquisitionContext_match_connection | falcon_core::autotuner_interfaces::contexts::AcquisitionContext::match_connection */
/**
 * @brief (from C++: falcon_core::autotuner_interfaces::contexts::AcquisitionContext::match_connection)
 * @brief Divide the units. The context on the top keeps all other details.
 * @param other: The unit to divide by.
 * @return A new context with the divided units.
 */
bool AcquisitionContext_match_connection(AcquisitionContextHandle handle,
                                         ConnectionHandle         other);
/* AUTO-DOC from cpp: AcquisitionContext_match_instrument_type | falcon_core::autotuner_interfaces::contexts::AcquisitionContext::match_instrument_type */
/**
 * @brief (from C++: falcon_core::autotuner_interfaces::contexts::AcquisitionContext::match_instrument_type)
 * @brief Returns if the instrument type matches this context.
 */
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
