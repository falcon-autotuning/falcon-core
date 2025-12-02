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

// Constructors
PointHandle Point_create_empty();
PointHandle Point_create(MapConnectionDoubleHandle items,
                         SymbolUnitHandle          unit);
PointHandle Point_create_from_parent(MapConnectionQuantityHandle items);

// Destructor
void Point_destroy(PointHandle handle);

// Methods
/* AUTO-DOC from cpp: Point_unit | falcon_core::math::Point::unit */
/**
 * @brief Returns the SI unit for the point.
 */
SymbolUnitHandle     Point_unit(PointHandle handle);
/* AUTO-DOC from cpp: Point_insert_or_assign | falcon_core::math::Point::insert_or_assign */
/**
 * @brief an overide of insert to make sure units are fixed.
 */
void                 Point_insert_or_assign(PointHandle      handle,
                                            ConnectionHandle key,
                                            QuantityHandle   value);
void                 Point_insert(PointHandle      handle,
                                  ConnectionHandle key,
                                  QuantityHandle   value);
QuantityHandle       Point_at(PointHandle handle, ConnectionHandle key);
void                 Point_erase(PointHandle handle, ConnectionHandle key);
size_t               Point_size(PointHandle handle);
bool                 Point_empty(PointHandle handle);
void                 Point_clear(PointHandle handle);
bool                 Point_contains(PointHandle handle, ConnectionHandle key);
ListConnectionHandle Point_keys(PointHandle handle);
ListQuantityHandle   Point_values(PointHandle handle);
ListPairConnectionQuantityHandle Point_items(PointHandle handle);
/* AUTO-DOC from cpp: Point_coordinates | falcon_core::math::Point::coordinates */
/**
 * @brief Returns the coordinates for the point.
 */
MapConnectionQuantityHandle      Point_coordinates(PointHandle handle);
/* AUTO-DOC from cpp: Point_connections | falcon_core::math::Point::connections */
/**
 * @brief Returns the connections for the point.
 */
ListConnectionHandle             Point_connections(PointHandle handle);
PointHandle Point_addition(PointHandle handle, PointHandle other);
PointHandle Point_subtraction(PointHandle handle, PointHandle other);
PointHandle Point_multiplication(PointHandle handle, double scalar);
PointHandle Point_division(PointHandle handle, double scalar);
PointHandle Point_negation(PointHandle handle);
void        Point_set_unit(PointHandle handle, SymbolUnitHandle unit);
bool        Point_equal(PointHandle a, PointHandle b);
bool        Point_not_equal(PointHandle a, PointHandle b);

// Serialization (from Song)
StringHandle Point_to_json_string(PointHandle handle);
PointHandle  Point_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
