

# File Point\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**Point\_c\_api.h**](Point__c__api_8h.md)

[Go to the documentation of this file](Point__c__api_8h.md)


```C++
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
PointHandle Point_copy(PointHandle handle);
// @category:deallocation
void Point_destroy(PointHandle handle);
// @category:read
bool Point_equal(PointHandle handle, PointHandle other);
// @category:read
bool Point_not_equal(PointHandle handle, PointHandle other);
// @category:read
StringHandle Point_to_json_string(PointHandle handle);
// @category:allocation
PointHandle Point_from_json_string(StringHandle json);
// @category:allocation
PointHandle Point_create_empty();
// @category:allocation
PointHandle Point_create(MapConnectionDoubleHandle items,
                         SymbolUnitHandle          unit);
// @category:allocation
PointHandle Point_create_from_parent(MapConnectionQuantityHandle items);
// @category:read
/* AUTO-DOC from cpp: Point_unit | falcon_core::math::Point::unit */
SymbolUnitHandle Point_unit(PointHandle handle);
// @category:write
/* AUTO-DOC from cpp: Point_insert_or_assign |
 * falcon_core::math::Point::insert_or_assign */
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
/* AUTO-DOC from cpp: Point_coordinates | falcon_core::math::Point::coordinates
 */
MapConnectionQuantityHandle Point_coordinates(PointHandle handle);
// @category:read
/* AUTO-DOC from cpp: Point_connections | falcon_core::math::Point::connections
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

#ifdef __cplusplus
}
#endif
```


