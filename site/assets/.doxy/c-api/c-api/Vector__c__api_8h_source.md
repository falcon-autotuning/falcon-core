

# File Vector\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**Vector\_c\_api.h**](Vector__c__api_8h.md)

[Go to the documentation of this file](Vector__c__api_8h.md)


```C++
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
VectorHandle Vector_copy(VectorHandle handle);
// @category:deallocation
void Vector_destroy(VectorHandle handle);
// @category:read
bool Vector_equal(VectorHandle handle, VectorHandle other);
// @category:read
bool Vector_not_equal(VectorHandle handle, VectorHandle other);
// @category:read
StringHandle Vector_to_json_string(VectorHandle handle);
// @category:allocation
VectorHandle Vector_from_json_string(StringHandle json);
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
// @category:read
/* USER-DOC */
/* MAN-DOC from cpp: Vector_end_point | falcon_core::math::Vector::endPoint */
PointHandle Vector_end_point(VectorHandle handle);
// @category:read
/* MAN-DOC from cpp: Vector_start_point | falcon_core::math::Vector::startPoint
 */
PointHandle Vector_start_point(VectorHandle handle);
// @category:read
/* AUTO-DOC from cpp: Vector_end_quantities |
 * falcon_core::math::Vector::end_quantities */
MapConnectionQuantityHandle Vector_end_quantities(VectorHandle handle);
// @category:read
/* AUTO-DOC from cpp: Vector_start_quantities |
 * falcon_core::math::Vector::start_quantities */
MapConnectionQuantityHandle Vector_start_quantities(VectorHandle handle);
// @category:read
/* AUTO-DOC from cpp: Vector_end_map | falcon_core::math::Vector::end_map */
MapConnectionDoubleHandle Vector_end_map(VectorHandle handle);
// @category:read
/* AUTO-DOC from cpp: Vector_start_map | falcon_core::math::Vector::start_map */
MapConnectionDoubleHandle Vector_start_map(VectorHandle handle);
// @category:read
/* AUTO-DOC from cpp: Vector_connections |
 * falcon_core::math::Vector::connections */
ListConnectionHandle Vector_connections(VectorHandle handle);
// @category:read
/* AUTO-DOC from cpp: Vector_unit | falcon_core::math::Vector::unit */
SymbolUnitHandle Vector_unit(VectorHandle handle);
// @category:read
/* AUTO-DOC from cpp: Vector_principle_connection |
 * falcon_core::math::Vector::principle_connection */
ConnectionHandle Vector_principle_connection(VectorHandle handle);
// @category:read
/* AUTO-DOC from cpp: Vector_magnitude | falcon_core::math::Vector::magnitude */
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
/* AUTO-DOC from cpp: Vector_update_start_from_states |
 * falcon_core::math::Vector::update_start_from_states */
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
/* AUTO-DOC from cpp: Vector_translate | falcon_core::math::Vector::translate */
VectorHandle Vector_translate(VectorHandle handle, PointHandle point);
// @category:read
/* AUTO-DOC from cpp: Vector_translate_to_origin |
 * falcon_core::math::Vector::translate_to_origin */
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
/* AUTO-DOC from cpp: Vector_unit_vector |
 * falcon_core::math::Vector::unit_vector */
VectorHandle Vector_unit_vector(VectorHandle handle);
// @category:read
/* AUTO-DOC from cpp: Vector_normalize | falcon_core::math::Vector::normalize */
VectorHandle Vector_normalize(VectorHandle handle);
// @category:read
/* AUTO-DOC from cpp: Vector_project | falcon_core::math::Vector::project */
VectorHandle Vector_project(VectorHandle handle, VectorHandle other);
// @category:write
/* AUTO-DOC from cpp: Vector_update_unit |
 * falcon_core::math::Vector::update_unit */
void Vector_update_unit(VectorHandle handle, SymbolUnitHandle unit);

#ifdef __cplusplus
}
#endif
```


