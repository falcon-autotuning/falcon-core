

# File Quantity\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**Quantity\_c\_api.h**](Quantity__c__api_8h.md)

[Go to the documentation of this file](Quantity__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
typedef void* QuantityHandle;

// @category:allocation
QuantityHandle Quantity_copy(QuantityHandle handle);
// @category:deallocation
void Quantity_destroy(QuantityHandle handle);
// @category:read
bool Quantity_equal(QuantityHandle handle, QuantityHandle other);
// @category:read
bool Quantity_not_equal(QuantityHandle handle, QuantityHandle other);
// @category:read
StringHandle Quantity_to_json_string(QuantityHandle handle);
// @category:allocation
QuantityHandle Quantity_from_json_string(StringHandle json);
// @category:allocation
QuantityHandle Quantity_create(double value, SymbolUnitHandle unit);
// @category:read
/* AUTO-DOC from cpp: Quantity_value | falcon_core::math::Quantity::value */
double Quantity_value(QuantityHandle handle);
// @category:read
/* AUTO-DOC from cpp: Quantity_unit | falcon_core::math::Quantity::unit */
SymbolUnitHandle Quantity_unit(QuantityHandle handle);
// @category:write
/* AUTO-DOC from cpp: Quantity_convert_to |
 * falcon_core::math::Quantity::convert_to */
void Quantity_convert_to(QuantityHandle handle, SymbolUnitHandle target_unit);
// @category:read
QuantityHandle Quantity_multiply_int(QuantityHandle handle, int other);
// @category:read
QuantityHandle Quantity_multiply_double(QuantityHandle handle, double other);
// @category:read
QuantityHandle Quantity_multiply_quantity(QuantityHandle handle,
                                          QuantityHandle other);
// @category:write
QuantityHandle Quantity_multiply_equals_int(QuantityHandle handle, int other);
// @category:write
QuantityHandle Quantity_multiply_equals_double(QuantityHandle handle,
                                               double         other);
// @category:write
QuantityHandle Quantity_multiply_equals_quantity(QuantityHandle handle,
                                                 QuantityHandle other);
// @category:read
QuantityHandle Quantity_divide_int(QuantityHandle handle, int other);
// @category:read
QuantityHandle Quantity_divide_double(QuantityHandle handle, double other);
// @category:read
QuantityHandle Quantity_divide_quantity(QuantityHandle handle,
                                        QuantityHandle other);
// @category:write
QuantityHandle Quantity_divide_equals_int(QuantityHandle handle, int other);
// @category:write
QuantityHandle Quantity_divide_equals_double(QuantityHandle handle,
                                             double         other);
// @category:write
QuantityHandle Quantity_divide_equals_quantity(QuantityHandle handle,
                                               QuantityHandle other);
// @category:read
QuantityHandle Quantity_power(QuantityHandle handle, int other);
// @category:read
QuantityHandle Quantity_add_quantity(QuantityHandle handle,
                                     QuantityHandle other);
// @category:write
QuantityHandle Quantity_add_equals_quantity(QuantityHandle handle,
                                            QuantityHandle other);
// @category:read
QuantityHandle Quantity_subtract_quantity(QuantityHandle handle,
                                          QuantityHandle other);
// @category:write
QuantityHandle Quantity_subtract_equals_quantity(QuantityHandle handle,
                                                 QuantityHandle other);
// @category:read
QuantityHandle Quantity_negate(QuantityHandle handle);
// @category:read
QuantityHandle Quantity_abs(QuantityHandle handle);

#ifdef __cplusplus
}
#endif
```


