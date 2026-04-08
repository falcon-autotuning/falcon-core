#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon-core/physics/device_structures/Connection_c_api.h"
typedef void* ImpedanceHandle;

// @category:allocation
FALCON_CORE_C_API ImpedanceHandle Impedance_copy(ImpedanceHandle handle);
// @category:deallocation
FALCON_CORE_C_API void Impedance_destroy(ImpedanceHandle handle);
// @category:read
FALCON_CORE_C_API bool Impedance_equal(ImpedanceHandle handle,
                                       ImpedanceHandle other);
// @category:read
FALCON_CORE_C_API bool Impedance_not_equal(ImpedanceHandle handle,
                                           ImpedanceHandle other);
// @category:read
FALCON_CORE_C_API StringHandle Impedance_to_json_string(ImpedanceHandle handle);
// @category:allocation
FALCON_CORE_C_API ImpedanceHandle Impedance_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API ImpedanceHandle Impedance_create(ConnectionHandle connection,
                                                   double           resistance,
                                                   double capacitance);
// @category:read
/* AUTO-DOC from cpp: Impedance_connection |
 * falcon_core::physics::device_structures::Impedance::connection */
/**
 * @brief Gets the connection leading to the fridge with this impedance
 * @return A shared pointer to the BaseConnection
 */
FALCON_CORE_C_API ConnectionHandle Impedance_connection(ImpedanceHandle handle);
// @category:read
/* AUTO-DOC from cpp: Impedance_resistance |
 * falcon_core::physics::device_structures::Impedance::resistance */
/**
 * @brief Gets the resistance of the impedance
 * @return The resistance in ohms
 */
FALCON_CORE_C_API double Impedance_resistance(ImpedanceHandle handle);
// @category:read
/* AUTO-DOC from cpp: Impedance_capacitance |
 * falcon_core::physics::device_structures::Impedance::capacitance */
/**
 * @brief Gets the capacitance of the impedance
 * @return The capacitance in farads
 */
FALCON_CORE_C_API double Impedance_capacitance(ImpedanceHandle handle);

#ifdef __cplusplus
}
#endif
