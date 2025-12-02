#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>

#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/generic/MapConnectionDouble_c_api.h"
#include "falcon_core/generic/MapConnectionQuantity_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/Quantity_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

typedef void* PointHandle;

// @category:allocation
PointHandle Point_create_empty();
// @category:allocation
PointHandle Point_create(MapConnectionDoubleHandle items,
                         SymbolUnitHandle          unit);
// @category:allocation
PointHandle Point_create_from_parent(MapConnectionQuantityHandle items);
// @category:deallocation
void Point_destroy(PointHandle handle);
// @category:read
/* AUTO-DOC from cpp: Point_unit | falcon_core::math::Point::unit */
/**
 * @brief Returns the SI unit for the point.
 */
SymbolUnitHandle Point_unit(PointHandle handle);
// @category:write
/* AUTO-DOC from cpp: Point_insert_or_assign | falcon_core::math::Point::insert_or_assign */
/**
 * @brief an overide of insert to make sure units are fixed.
 */
void Point_insert_or_assign(PointHandle      handle,
                            ConnectionHandle key,
                            QuantityHandle   value);
// @category:write
void Point_insert(PointHandle      handle,
                  ConnectionHandle key,
                  QuantityHandle   value);
// @category:read
QuantityHandle Point_at(PointHandle handle, ConnectionHandle key);
// @category:write
void Point_erase(PointHandle handle, ConnectionHandle key);
// @category:read
size_t Point_size(PointHandle handle);
// @category:read
bool Point_empty(PointHandle handle);
// @category:write
void Point_clear(PointHandle handle);
// @category:read
bool Point_contains(PointHandle handle, ConnectionHandle key);
// @category:read
ListConnectionHandle Point_keys(PointHandle handle);
// @category:read
ListQuantityHandle Point_values(PointHandle handle);
// @category:read
ListPairConnectionQuantityHandle Point_items(PointHandle handle);
// @category:read
/* AUTO-DOC from cpp: Point_coordinates | falcon_core::math::Point::coordinates */
/**
 * @brief Returns the coordinates for the point.
 */
MapConnectionQuantityHandle Point_coordinates(PointHandle handle);
// @category:read
/* AUTO-DOC from cpp: Point_connections | falcon_core::math::Point::connections */
/**
 * @brief Returns the connections for the point.
 */
ListConnectionHandle Point_connections(PointHandle handle);
// @category:read
PointHandle Point_addition(PointHandle handle, PointHandle other);
// @category:read
PointHandle Point_subtraction(PointHandle handle, PointHandle other);
// @category:read
PointHandle Point_multiplication(PointHandle handle, double scalar);
// @category:read
PointHandle Point_division(PointHandle handle, double scalar);
// @category:read
PointHandle Point_negation(PointHandle handle);
// @category:write
void Point_set_unit(PointHandle handle, SymbolUnitHandle unit);
// @category:read
bool Point_equal(PointHandle a, PointHandle b);
// @category:read
bool Point_not_equal(PointHandle a, PointHandle b);
// @category:read
StringHandle Point_to_json_string(PointHandle handle);
// @category:allocation
PointHandle Point_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
