#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
typedef void* MeasurementContextHandle;

// Constructors
MeasurementContextHandle MeasurementContext_create(
    ConnectionHandle connection, StringHandle instrument_type);
MeasurementContextHandle MeasurementContext_create_from_port(
    InstrumentPortHandle port);

// Destructor
void MeasurementContext_destroy(MeasurementContextHandle handle);

// Methods
/* AUTO-DOC from cpp: MeasurementContext_connection | falcon_core::autotuner_interfaces::contexts::BaseContext::connection */
/**
 * @brief (from C++: falcon_core::autotuner_interfaces::contexts::BaseContext::connection)
 * @brief Return the connection.
 */
ConnectionHandle MeasurementContext_connection(MeasurementContextHandle handle);
/* AUTO-DOC from cpp: MeasurementContext_instrument_type | falcon_core::autotuner_interfaces::contexts::BaseContext::instrument_type */
/**
 * @brief (from C++: falcon_core::autotuner_interfaces::contexts::BaseContext::instrument_type)
 * @brief Return the instrument type.
 */
StringHandle     MeasurementContext_instrument_type(
        MeasurementContextHandle handle);
bool MeasurementContext_equal(MeasurementContextHandle a,
                              MeasurementContextHandle b);
bool MeasurementContext_not_equal(MeasurementContextHandle a,
                                  MeasurementContextHandle b);

// Serialization (from Song)
StringHandle MeasurementContext_to_json_string(MeasurementContextHandle handle);
MeasurementContextHandle MeasurementContext_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
