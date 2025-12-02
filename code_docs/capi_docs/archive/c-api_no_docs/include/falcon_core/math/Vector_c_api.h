#pragma once
#include <stddef.h>

#include "falcon_core/communications/voltage_states/DeviceVoltageStates_c_api.h"
#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/generic/ListPairConnectionPairQuantityQuantity_c_api.h"
#include "falcon_core/generic/ListPairQuantityQuantity_c_api.h"
#include "falcon_core/generic/PairQuantityQuantity_c_api.h"
#include "falcon_core/math/Point_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

typedef void* VectorHandle;

// @category:allocation
VectorHandle Vector_create(PointHandle start, PointHandle end);
// @category:allocation
VectorHandle Vector_create_from_end(PointHandle end);
// @category:allocation
VectorHandle Vector_create_from_quantities(MapConnectionQuantityHandle start,
                                           MapConnectionQuantityHandle end);
// @category:allocation
VectorHandle Vector_create_from_end_quantities(MapConnectionQuantityHandle end);
// @category:allocation
VectorHandle Vector_create_from_doubles(MapConnectionDoubleHandle start,
                                        MapConnectionDoubleHandle end,
                                        SymbolUnitHandle          unit);
// @category:allocation
VectorHandle Vector_create_from_end_doubles(MapConnectionDoubleHandle end,
                                            SymbolUnitHandle          unit);

// @category:allocation
VectorHandle Vector_create_from_parent(MapConnectionQuantityHandle items);
// @category:deallocation
void Vector_destroy(VectorHandle handle);
// @category:read
/* USER-DOC */
/**
 * @brief Return the end point of a vector in device coordinates.
 *
 * This function is part of the public C API. It returns the end point
 * associated with the given vector handle, after applying the current
 * device transform.
 *
 * @param v  Handle to a valid Vector instance.
 * @return   A handle to the end point Vector.
 */
PointHandle Vector_end_point(VectorHandle handle);
// @category:read
PointHandle Vector_start_point(VectorHandle handle);
// @category:read
MapConnectionQuantityHandle Vector_end_quantities(VectorHandle handle);
// @category:read
MapConnectionQuantityHandle Vector_start_quantities(VectorHandle handle);
// @category:read
MapConnectionDoubleHandle Vector_end_map(VectorHandle handle);
// @category:read
MapConnectionDoubleHandle Vector_start_map(VectorHandle handle);
// @category:read
ListConnectionHandle Vector_connections(VectorHandle handle);
// @category:read
SymbolUnitHandle Vector_unit(VectorHandle handle);
// @category:read
ConnectionHandle Vector_principle_connection(VectorHandle handle);
// @category:read
double Vector_magnitude(VectorHandle handle);
// @category:write
void Vector_insert_or_assign(VectorHandle               handle,
                             ConnectionHandle           key,
                             PairQuantityQuantityHandle value);
// @category:write
void Vector_insert(VectorHandle               handle,
                   ConnectionHandle           key,
                   PairQuantityQuantityHandle value);
// @category:read
PairQuantityQuantityHandle Vector_at(VectorHandle handle, ConnectionHandle key);
// @category:write
void Vector_erase(VectorHandle handle, ConnectionHandle key);
// @category:read
size_t Vector_size(VectorHandle handle);
// @category:read
bool Vector_empty(VectorHandle handle);
// @category:write
void Vector_clear(VectorHandle handle);
// @category:read
bool Vector_contains(VectorHandle handle, ConnectionHandle key);
// @category:read
ListConnectionHandle Vector_keys(VectorHandle handle);
// @category:read
ListPairQuantityQuantityHandle Vector_values(VectorHandle handle);
// @category:read
ListPairConnectionPairQuantityQuantityHandle Vector_items(VectorHandle handle);
// @category:read
VectorHandle Vector_addition(VectorHandle handle, VectorHandle other);
// @category:read
VectorHandle Vector_subtraction(VectorHandle handle, VectorHandle other);
// @category:read
VectorHandle Vector_double_multiplication(VectorHandle handle, double scalar);
// @category:read
VectorHandle Vector_int_multiplication(VectorHandle handle, int scalar);
// @category:read
VectorHandle Vector_double_division(VectorHandle handle, double scalar);
// @category:read
VectorHandle Vector_int_division(VectorHandle handle, int scalar);
// @category:read
VectorHandle Vector_negation(VectorHandle handle);
// @category:read
VectorHandle Vector_update_start_from_states(VectorHandle              handle,
                                             DeviceVoltageStatesHandle state);
// @category:read
VectorHandle Vector_translate_doubles(VectorHandle              handle,
                                      MapConnectionDoubleHandle point,
                                      SymbolUnitHandle          unit);
// @category:read
VectorHandle Vector_translate_quantities(VectorHandle                handle,
                                         MapConnectionQuantityHandle point);
// @category:read
VectorHandle Vector_translate(VectorHandle handle, PointHandle point);
// @category:read
VectorHandle Vector_translate_to_origin(VectorHandle handle);
// @category:read
VectorHandle Vector_double_extend(VectorHandle handle, double extension);
// @category:read
VectorHandle Vector_int_extend(VectorHandle handle, int extension);
// @category:read
VectorHandle Vector_double_shrink(VectorHandle handle, double extension);
// @category:read
VectorHandle Vector_int_shrink(VectorHandle handle, int extension);
// @category:read
VectorHandle Vector_unit_vector(VectorHandle handle);
// @category:read
VectorHandle Vector_normalize(VectorHandle handle);
// @category:read
VectorHandle Vector_project(VectorHandle handle, VectorHandle other);
// @category:write
void Vector_update_unit(VectorHandle handle, SymbolUnitHandle unit);
// @category:read
bool Vector_equal(VectorHandle a, VectorHandle b);
// @category:read
bool Vector_not_equal(VectorHandle a, VectorHandle b);
// @category:read
StringHandle Vector_to_json_string(VectorHandle handle);
// @category:allocation
VectorHandle Vector_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
