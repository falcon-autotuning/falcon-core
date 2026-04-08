#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

#include "falcon-core/export_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon-core/physics/device_structures/Connection_c_api.h"
#include "falcon-core/physics/units/SymbolUnit_c_api.h"
typedef void* AcquisitionContextHandle;

// @category:allocation
FALCON_CORE_C_API AcquisitionContextHandle
AcquisitionContext_copy(AcquisitionContextHandle handle);
// @category:deallocation
FALCON_CORE_C_API void AcquisitionContext_destroy(
    AcquisitionContextHandle handle);
// @category:read
FALCON_CORE_C_API bool AcquisitionContext_equal(AcquisitionContextHandle handle,
                                                AcquisitionContextHandle other);
// @category:read
FALCON_CORE_C_API bool AcquisitionContext_not_equal(
    AcquisitionContextHandle handle, AcquisitionContextHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
AcquisitionContext_to_json_string(AcquisitionContextHandle handle);
// @category:allocation
FALCON_CORE_C_API AcquisitionContextHandle
AcquisitionContext_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API AcquisitionContextHandle
AcquisitionContext_create(ConnectionHandle connection,
                          StringHandle     instrument_type,
                          SymbolUnitHandle units);
// @category:allocation
FALCON_CORE_C_API AcquisitionContextHandle
AcquisitionContext_create_from_port(InstrumentPortHandle port);
// @category:read
FALCON_CORE_C_API ConnectionHandle
AcquisitionContext_connection(AcquisitionContextHandle handle);
// @category:read
FALCON_CORE_C_API StringHandle
AcquisitionContext_instrument_type(AcquisitionContextHandle handle);
// @category:read
/* AUTO-DOC from cpp: AcquisitionContext_units |
 * falcon_core::autotuner_interfaces::contexts::AcquisitionContext::units */
/**
 * @brief Returns the units of the context.
 */
FALCON_CORE_C_API SymbolUnitHandle
AcquisitionContext_units(AcquisitionContextHandle handle);
// @category:read
FALCON_CORE_C_API AcquisitionContextHandle AcquisitionContext_division_unit(
    AcquisitionContextHandle handle, SymbolUnitHandle other);
// @category:read
FALCON_CORE_C_API AcquisitionContextHandle AcquisitionContext_division(
    AcquisitionContextHandle handle, AcquisitionContextHandle other);
// @category:read
/* AUTO-DOC from cpp: AcquisitionContext_match_connection |
 * falcon_core::autotuner_interfaces::contexts::AcquisitionContext::match_connection
 */
/**
 * @brief Divide the units. The context on the top keeps all other details.
 * @param other: The unit to divide by.
 * @return A new context with the divided units.
 */
FALCON_CORE_C_API bool AcquisitionContext_match_connection(
    AcquisitionContextHandle handle, ConnectionHandle other);
// @category:read
/* AUTO-DOC from cpp: AcquisitionContext_match_instrument_type |
 * falcon_core::autotuner_interfaces::contexts::AcquisitionContext::match_instrument_type
 */
/**
 * @brief Returns if the instrument type matches this context.
 */
FALCON_CORE_C_API bool AcquisitionContext_match_instrument_type(
    AcquisitionContextHandle handle, StringHandle other);

#ifdef __cplusplus
}
#endif
