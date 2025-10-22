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
ConnectionHandle Impedance_connection(ImpedanceHandle handle);
double           Impedance_resistance(ImpedanceHandle handle);
double           Impedance_capacitance(ImpedanceHandle handle);
bool             Impedance_equal(ImpedanceHandle a, ImpedanceHandle b);
bool             Impedance_not_equal(ImpedanceHandle a, ImpedanceHandle b);

// Serialization (from Song)
const char*     Impedance_to_json_string(ImpedanceHandle handle);
ImpedanceHandle Impedance_from_json_string(const char* json);

#ifdef __cplusplus
}
#endif
