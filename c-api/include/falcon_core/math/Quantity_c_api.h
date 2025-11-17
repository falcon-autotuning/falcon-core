#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
typedef void* QuantityHandle;

// Constructors
QuantityHandle Quantity_create(
    double value, SymbolUnitHandle unit = SymbolUnit_create_volt());

// Destructor
void Quantity_destroy(QuantityHandle handle);

// Methods
double           Quantity_value(QuantityHandle handle);
SymbolUnitHandle Quantity_unit(QuantityHandle handle);
void Quantity_convert_to(QuantityHandle handle, SymbolUnitHandle target_unit);
QuantityHandle Quantity_multiply_int(QuantityHandle handle, int other);
QuantityHandle Quantity_multiply_double(QuantityHandle handle, double other);
QuantityHandle Quantity_multiply_quantity(QuantityHandle handle,
                                          QuantityHandle other);
QuantityHandle Quantity_multiply_equals_int(QuantityHandle handle, int other);
QuantityHandle Quantity_multiply_equals_double(QuantityHandle handle,
                                               double         other);
QuantityHandle Quantity_multiply_equals_quantity(QuantityHandle handle,
                                                 QuantityHandle other);
QuantityHandle Quantity_divide_int(QuantityHandle handle, int other);
QuantityHandle Quantity_divide_double(QuantityHandle handle, double other);
QuantityHandle Quantity_divide_quantity(QuantityHandle handle,
                                        QuantityHandle other);
QuantityHandle Quantity_divide_equals_int(QuantityHandle handle, int other);
QuantityHandle Quantity_divide_equals_double(QuantityHandle handle,
                                             double         other);
QuantityHandle Quantity_divide_equals_quantity(QuantityHandle handle,
                                               QuantityHandle other);
QuantityHandle Quantity_power(QuantityHandle handle, int other);
QuantityHandle Quantity_add_quantity(QuantityHandle handle,
                                     QuantityHandle other);
QuantityHandle Quantity_add_equals_quantity(QuantityHandle handle,
                                            QuantityHandle other);
QuantityHandle Quantity_subtract_quantity(QuantityHandle handle,
                                          QuantityHandle other);
QuantityHandle Quantity_subtract_equals_quantity(QuantityHandle handle,
                                                 QuantityHandle other);
QuantityHandle Quantity_negate(QuantityHandle handle);
QuantityHandle Quantity_abs(QuantityHandle handle);
bool           Quantity_equal(QuantityHandle a, QuantityHandle b);
bool           Quantity_not_equal(QuantityHandle a, QuantityHandle b);

// Serialization (from Song)
StringHandle   Quantity_to_json_string(QuantityHandle handle);
QuantityHandle Quantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
