#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/physics/device_structures/Connection_c_api.h"
typedef void* ImpedanceHandle;

// @category:allocation
ImpedanceHandle Impedance_create(ConnectionHandle connection,
                                 double           resistance,
                                 double           capacitance);
// @category:deallocation
void Impedance_destroy(ImpedanceHandle handle);
// @category:read
ConnectionHandle Impedance_connection(ImpedanceHandle handle);
// @category:read
double Impedance_resistance(ImpedanceHandle handle);
// @category:read
double Impedance_capacitance(ImpedanceHandle handle);
// @category:read
bool Impedance_equal(ImpedanceHandle handle, ImpedanceHandle other);
// @category:read
bool Impedance_not_equal(ImpedanceHandle handle, ImpedanceHandle other);
// @category:read
StringHandle Impedance_to_json_string(ImpedanceHandle handle);
// @category:allocation
ImpedanceHandle Impedance_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
