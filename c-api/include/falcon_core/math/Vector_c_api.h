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
FALCON_CORE_C_API VectorHandle Vector_copy(VectorHandle handle);
// @category:deallocation
FALCON_CORE_C_API void Vector_destroy(VectorHandle handle);
// @category:read
FALCON_CORE_C_API bool Vector_equal(VectorHandle handle, VectorHandle other);
// @category:read
FALCON_CORE_C_API bool Vector_not_equal(VectorHandle handle,
                                        VectorHandle other);
// @category:read
FALCON_CORE_C_API StringHandle Vector_to_json_string(VectorHandle handle);
// @category:allocation
FALCON_CORE_C_API VectorHandle Vector_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API VectorHandle Vector_create(PointHandle start,
                                             PointHandle end);
// @category:allocation
FALCON_CORE_C_API VectorHandle Vector_create_from_end(PointHandle end);
// @category:allocation
FALCON_CORE_C_API VectorHandle Vector_create_from_quantities(
    MapConnectionQuantityHandle start, MapConnectionQuantityHandle end);
// @category:allocation
FALCON_CORE_C_API VectorHandle
Vector_create_from_end_quantities(MapConnectionQuantityHandle end);
// @category:allocation
FALCON_CORE_C_API VectorHandle
Vector_create_from_doubles(MapConnectionDoubleHandle start,
                           MapConnectionDoubleHandle end,
                           SymbolUnitHandle          unit);
// @category:allocation
FALCON_CORE_C_API VectorHandle Vector_create_from_end_doubles(
    MapConnectionDoubleHandle end, SymbolUnitHandle unit);

// @category:allocation
FALCON_CORE_C_API VectorHandle
Vector_create_from_parent(MapConnectionQuantityHandle items);
// @category:read
/* USER-DOC */
/* MAN-DOC from cpp: Vector_end_point | falcon_core::math::Vector::endPoint */
/**
 * @brief Return the end point of a vector in device coordinates.
 *
 * This function is part of the public C API. It returns the end point
 * associated with the given vector handle, after applying the current
 * device transform.
 *
 * @param v  Handle to a valid Vector instance.
 * @return   A handle to the end point Vector.

 *
 * Documentation imported from C++:
 * Returns the point at the end.

*/
FALCON_CORE_C_API PointHandle Vector_end_point(VectorHandle handle);
// @category:read
/* MAN-DOC from cpp: Vector_start_point | falcon_core::math::Vector::startPoint
 */
/**
 * @brief Returns the point at the start.
 */
FALCON_CORE_C_API PointHandle Vector_start_point(VectorHandle handle);
// @category:read
/* AUTO-DOC from cpp: Vector_end_quantities |
 * falcon_core::math::Vector::end_quantities */
/**
 * @brief Returns the raw map of the ending point.
 */
FALCON_CORE_C_API MapConnectionQuantityHandle
Vector_end_quantities(VectorHandle handle);
// @category:read
/* AUTO-DOC from cpp: Vector_start_quantities |
 * falcon_core::math::Vector::start_quantities */
/**
 * @brief Returns the raw map of the starting point.
 */
FALCON_CORE_C_API MapConnectionQuantityHandle
Vector_start_quantities(VectorHandle handle);
// @category:read
/* AUTO-DOC from cpp: Vector_end_map | falcon_core::math::Vector::end_map */
/**
 * @brief Returns the raw unitless map of the ending point.
 */
FALCON_CORE_C_API MapConnectionDoubleHandle Vector_end_map(VectorHandle handle);
// @category:read
/* AUTO-DOC from cpp: Vector_start_map | falcon_core::math::Vector::start_map */
/**
 * @brief Returns the raw unitless map of the starting point.
 */
FALCON_CORE_C_API MapConnectionDoubleHandle
Vector_start_map(VectorHandle handle);
// @category:read
/* AUTO-DOC from cpp: Vector_connections |
 * falcon_core::math::Vector::connections */
/**
 * @brief Returns the affected connections for this vector.
 */
FALCON_CORE_C_API ListConnectionHandle Vector_connections(VectorHandle handle);
// @category:read
/* AUTO-DOC from cpp: Vector_unit | falcon_core::math::Vector::unit */
/**
 * @brief Returns the unit of this vector.
 */
FALCON_CORE_C_API SymbolUnitHandle Vector_unit(VectorHandle handle);
// @category:read
/* AUTO-DOC from cpp: Vector_principle_connection |
 * falcon_core::math::Vector::principle_connection */
/**
 * @brief returns the principle_connection that is the largest.
 */
FALCON_CORE_C_API ConnectionHandle
Vector_principle_connection(VectorHandle handle);
// @category:read
/* AUTO-DOC from cpp: Vector_magnitude | falcon_core::math::Vector::magnitude */
/**
 * @brief The magnitude of the vector.
 */
FALCON_CORE_C_API double Vector_magnitude(VectorHandle handle);
// @category:write
FALCON_CORE_C_API void Vector_insert_or_assign(
    VectorHandle               handle,
    ConnectionHandle           key,
    PairQuantityQuantityHandle value);
// @category:write
FALCON_CORE_C_API void Vector_insert(VectorHandle               handle,
                                     ConnectionHandle           key,
                                     PairQuantityQuantityHandle value);
// @category:read
FALCON_CORE_C_API PairQuantityQuantityHandle Vector_at(VectorHandle     handle,
                                                       ConnectionHandle key);
// @category:write
FALCON_CORE_C_API void Vector_erase(VectorHandle handle, ConnectionHandle key);
// @category:read
FALCON_CORE_C_API size_t Vector_size(VectorHandle handle);
// @category:read
FALCON_CORE_C_API bool Vector_empty(VectorHandle handle);
// @category:write
FALCON_CORE_C_API void Vector_clear(VectorHandle handle);
// @category:read
FALCON_CORE_C_API bool Vector_contains(VectorHandle     handle,
                                       ConnectionHandle key);
// @category:read
FALCON_CORE_C_API ListConnectionHandle Vector_keys(VectorHandle handle);
// @category:read
FALCON_CORE_C_API ListPairQuantityQuantityHandle
Vector_values(VectorHandle handle);
// @category:read
FALCON_CORE_C_API ListPairConnectionPairQuantityQuantityHandle
Vector_items(VectorHandle handle);
// @category:read
FALCON_CORE_C_API VectorHandle Vector_addition(VectorHandle handle,
                                               VectorHandle other);
// @category:read
FALCON_CORE_C_API VectorHandle Vector_subtraction(VectorHandle handle,
                                                  VectorHandle other);
// @category:read
FALCON_CORE_C_API VectorHandle Vector_double_multiplication(VectorHandle handle,
                                                            double scalar);
// @category:read
FALCON_CORE_C_API VectorHandle Vector_int_multiplication(VectorHandle handle,
                                                         int          scalar);
// @category:read
FALCON_CORE_C_API VectorHandle Vector_double_division(VectorHandle handle,
                                                      double       scalar);
// @category:read
FALCON_CORE_C_API VectorHandle Vector_int_division(VectorHandle handle,
                                                   int          scalar);
// @category:read
FALCON_CORE_C_API VectorHandle Vector_negation(VectorHandle handle);
// @category:read
/* AUTO-DOC from cpp: Vector_update_start_from_states |
 * falcon_core::math::Vector::update_start_from_states */
/**
 * @brief Updates the vector to start from teh given DeviceCVoltageStates.
 * @param state the new device voltage state.
 * @returns the displaced vector which starts at the given state.
 */
FALCON_CORE_C_API VectorHandle Vector_update_start_from_states(
    VectorHandle handle, DeviceVoltageStatesHandle state);
// @category:read
FALCON_CORE_C_API VectorHandle
Vector_translate_doubles(VectorHandle              handle,
                         MapConnectionDoubleHandle point,
                         SymbolUnitHandle          unit);
// @category:read
FALCON_CORE_C_API VectorHandle Vector_translate_quantities(
    VectorHandle handle, MapConnectionQuantityHandle point);
// @category:read
/* AUTO-DOC from cpp: Vector_translate | falcon_core::math::Vector::translate */
/**
 * @brief Displaces the origin of a vector by a point.
 * @param point the diplacement
 * @param unit the unit of displacement
 */
FALCON_CORE_C_API VectorHandle Vector_translate(VectorHandle handle,
                                                PointHandle  point);
// @category:read
/* AUTO-DOC from cpp: Vector_translate_to_origin |
 * falcon_core::math::Vector::translate_to_origin */
/**
 * @brief Translates a vector to the origin.
 */
FALCON_CORE_C_API VectorHandle Vector_translate_to_origin(VectorHandle handle);
// @category:read
FALCON_CORE_C_API VectorHandle Vector_double_extend(VectorHandle handle,
                                                    double       extension);
// @category:read
FALCON_CORE_C_API VectorHandle Vector_int_extend(VectorHandle handle,
                                                 int          extension);
// @category:read
FALCON_CORE_C_API VectorHandle Vector_double_shrink(VectorHandle handle,
                                                    double       extension);
// @category:read
FALCON_CORE_C_API VectorHandle Vector_int_shrink(VectorHandle handle,
                                                 int          extension);
// @category:read
/* AUTO-DOC from cpp: Vector_unit_vector |
 * falcon_core::math::Vector::unit_vector */
/**
 * @brief Generates the unit vector for the direction of this vector.
 */
FALCON_CORE_C_API VectorHandle Vector_unit_vector(VectorHandle handle);
// @category:read
/* AUTO-DOC from cpp: Vector_normalize | falcon_core::math::Vector::normalize */
/**
 * @brief Returns the normalized vector starting at the anchored starting
 * point.
 */
FALCON_CORE_C_API VectorHandle Vector_normalize(VectorHandle handle);
// @category:read
/* AUTO-DOC from cpp: Vector_project | falcon_core::math::Vector::project */
/**
 * @brief Projects this vector onto another.
 */
FALCON_CORE_C_API VectorHandle Vector_project(VectorHandle handle,
                                              VectorHandle other);
// @category:write
/* AUTO-DOC from cpp: Vector_update_unit |
 * falcon_core::math::Vector::update_unit */
/**
 * @brief Updates the unit of this vector.
 */
FALCON_CORE_C_API void Vector_update_unit(VectorHandle     handle,
                                          SymbolUnitHandle unit);

#ifdef __cplusplus
}
#endif
