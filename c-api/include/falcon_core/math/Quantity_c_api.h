#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
typedef void* QuantityHandle;

// @category:allocation
QuantityHandle Quantity_create(double value, SymbolUnitHandle unit);
// @category:deallocation
void Quantity_destroy(QuantityHandle handle);
// @category:read
double Quantity_value(QuantityHandle handle);
// @category:read
SymbolUnitHandle Quantity_unit(QuantityHandle handle);
// @category:write
void Quantity_convert_to(QuantityHandle handle, SymbolUnitHandle target_unit);
// @category:read
QuantityHandle Quantity_multiply_int(QuantityHandle handle, int other);
// @category:read
QuantityHandle Quantity_multiply_double(QuantityHandle handle, double other);
// @category:read
QuantityHandle Quantity_multiply_quantity(QuantityHandle handle,
                                          QuantityHandle other);
// @category:read
QuantityHandle Quantity_multiply_equals_int(QuantityHandle handle, int other);
// @category:read
QuantityHandle Quantity_multiply_equals_double(QuantityHandle handle,
                                               double         other);
// @category:read
QuantityHandle Quantity_multiply_equals_quantity(QuantityHandle handle,
                                                 QuantityHandle other);
// @category:read
QuantityHandle Quantity_divide_int(QuantityHandle handle, int other);
// @category:read
QuantityHandle Quantity_divide_double(QuantityHandle handle, double other);
// @category:read
QuantityHandle Quantity_divide_quantity(QuantityHandle handle,
                                        QuantityHandle other);
// @category:read
QuantityHandle Quantity_divide_equals_int(QuantityHandle handle, int other);
// @category:read
QuantityHandle Quantity_divide_equals_double(QuantityHandle handle,
                                             double         other);
// @category:read
QuantityHandle Quantity_divide_equals_quantity(QuantityHandle handle,
                                               QuantityHandle other);
// @category:read
QuantityHandle Quantity_power(QuantityHandle handle, int other);
// @category:read
QuantityHandle Quantity_add_quantity(QuantityHandle handle,
                                     QuantityHandle other);
// @category:read
QuantityHandle Quantity_add_equals_quantity(QuantityHandle handle,
                                            QuantityHandle other);
// @category:read
QuantityHandle Quantity_subtract_quantity(QuantityHandle handle,
                                          QuantityHandle other);
// @category:read
QuantityHandle Quantity_subtract_equals_quantity(QuantityHandle handle,
                                                 QuantityHandle other);
// @category:read
QuantityHandle Quantity_negate(QuantityHandle handle);
// @category:read
QuantityHandle Quantity_abs(QuantityHandle handle);
// @category:read
bool Quantity_equal(QuantityHandle a, QuantityHandle b);
// @category:read
bool Quantity_not_equal(QuantityHandle a, QuantityHandle b);
// @category:read
StringHandle Quantity_to_json_string(QuantityHandle handle);
// @category:allocation
QuantityHandle Quantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
