#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/physics/device_structures/Connection_c_api.h"
typedef void* ImpedanceHandle;

// Constructors
ImpedanceHandle Impedance_create(ConnectionHandle connection,
                                 double           resistance,
                                 double           capacitance);

// Destructor
void Impedance_destroy(ImpedanceHandle handle);

// Methods
/* AUTO-DOC from cpp: Impedance_connection | falcon_core::physics::device_structures::Impedance::connection */
/**
 * @brief Gets the connection leading to the fridge with this impedance
 * @return A shared pointer to the BaseConnection
 */
ConnectionHandle Impedance_connection(ImpedanceHandle handle);
/* AUTO-DOC from cpp: Impedance_resistance | falcon_core::physics::device_structures::Impedance::resistance */
/**
 * @brief Gets the resistance of the impedance
 * @return The resistance in ohms
 */
double           Impedance_resistance(ImpedanceHandle handle);
/* AUTO-DOC from cpp: Impedance_capacitance | falcon_core::physics::device_structures::Impedance::capacitance */
/**
 * @brief Gets the capacitance of the impedance
 * @return The capacitance in farads
 */
double           Impedance_capacitance(ImpedanceHandle handle);
bool             Impedance_equal(ImpedanceHandle a, ImpedanceHandle b);
bool             Impedance_not_equal(ImpedanceHandle a, ImpedanceHandle b);

// Serialization (from Song)
StringHandle    Impedance_to_json_string(ImpedanceHandle handle);
ImpedanceHandle Impedance_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
