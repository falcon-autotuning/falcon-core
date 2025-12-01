#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
typedef void* QuantityHandle;

// Constructors
QuantityHandle Quantity_create(double value, SymbolUnitHandle unit);

// Destructor
void Quantity_destroy(QuantityHandle handle);

// Methods
/* AUTO-DOC from cpp: Quantity_value | falcon_core::math::Quantity::value */
/**
 * @brief (from C++: falcon_core::math::Quantity::value)
 * @brief Return the value of the quantity.
 */
double           Quantity_value(QuantityHandle handle);
/* AUTO-DOC from cpp: Quantity_unit | falcon_core::math::Quantity::unit */
/**
 * @brief (from C++: falcon_core::math::Quantity::unit)
 * @brief Return the unit of the quantity.
 */
SymbolUnitHandle Quantity_unit(QuantityHandle handle);
/* AUTO-DOC from cpp: Quantity_convert_to | falcon_core::math::Quantity::convert_to */
/**
 * @brief (from C++: falcon_core::math::Quantity::convert_to)
 * @brief Convert the quantity to a different unit.
 * @param target_unit the raget unit to convert to.
 */
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
