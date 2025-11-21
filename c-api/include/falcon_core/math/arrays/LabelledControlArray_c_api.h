#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/ListListSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/arrays/ControlArray_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
// Forward declarations for opaque handles
typedef void* LabelledControlArrayHandle;

// Constructors
LabelledControlArrayHandle LabelledControlArray_from_farray(
    FArrayDoubleHandle farray, AcquisitionContextHandle label);
LabelledControlArrayHandle LabelledControlArray_from_control_array(
    ControlArrayHandle controlarray, AcquisitionContextHandle label);

// Destructor
void LabelledControlArray_destroy(LabelledControlArrayHandle handle);

// Methods
AcquisitionContextHandle LabelledControlArray_label(
    LabelledControlArrayHandle handle);
ConnectionHandle LabelledControlArray_connection(
    LabelledControlArrayHandle handle);
StringHandle LabelledControlArray_instrument_type(
    LabelledControlArrayHandle handle);
SymbolUnitHandle LabelledControlArray_units(LabelledControlArrayHandle handle);
size_t           LabelledControlArray_size(LabelledControlArrayHandle handle);
size_t LabelledControlArray_dimension(LabelledControlArrayHandle handle);
size_t LabelledControlArray_shape(LabelledControlArrayHandle handle,
                                  size_t*                    out_buffer,
                                  size_t                     ndim);
size_t LabelledControlArray_data(LabelledControlArrayHandle handle,
                                 double*                    out_buffer,
                                 size_t                     numdata);
void   LabelledControlArray_plusequals_farray(LabelledControlArrayHandle handle,
                                              FArrayDoubleHandle         other);
void   LabelledControlArray_plusequals_double(LabelledControlArrayHandle handle,
                                              const double               other);
void   LabelledControlArray_plusequals_int(LabelledControlArrayHandle handle,
                                           const int                  other);
LabelledControlArrayHandle LabelledControlArray_plus_control_array(
    LabelledControlArrayHandle handle, LabelledControlArrayHandle other);
LabelledControlArrayHandle LabelledControlArray_plus_farray(
    LabelledControlArrayHandle handle, FArrayDoubleHandle other);
LabelledControlArrayHandle LabelledControlArray_plus_double(
    LabelledControlArrayHandle handle, const double other);
LabelledControlArrayHandle LabelledControlArray_plus_int(
    LabelledControlArrayHandle handle, const int other);
void LabelledControlArray_minusequals_control_array(
    LabelledControlArrayHandle handle, LabelledControlArrayHandle other);
void LabelledControlArray_minusequals_farray(LabelledControlArrayHandle handle,
                                             FArrayDoubleHandle         other);
void LabelledControlArray_minusequals_double(LabelledControlArrayHandle handle,
                                             const double               other);
void LabelledControlArray_minusequals_int(LabelledControlArrayHandle handle,
                                          const int                  other);
LabelledControlArrayHandle LabelledControlArray_minus_control_array(
    LabelledControlArrayHandle handle, LabelledControlArrayHandle other);
LabelledControlArrayHandle LabelledControlArray_minus_farray(
    LabelledControlArrayHandle handle, FArrayDoubleHandle other);
LabelledControlArrayHandle LabelledControlArray_minus_double(
    LabelledControlArrayHandle handle, const double other);
LabelledControlArrayHandle LabelledControlArray_minus_int(
    LabelledControlArrayHandle handle, const int other);
LabelledControlArrayHandle LabelledControlArray_negation(
    LabelledControlArrayHandle handle);
void LabelledControlArray_timesequals_double(LabelledControlArrayHandle handle,
                                             const double               other);
void LabelledControlArray_timesequals_int(LabelledControlArrayHandle handle,
                                          const int                  other);
LabelledControlArrayHandle LabelledControlArray_times_double(
    LabelledControlArrayHandle handle, const double other);
LabelledControlArrayHandle LabelledControlArray_times_int(
    LabelledControlArrayHandle handle, const int other);
void LabelledControlArray_dividesequals_double(
    LabelledControlArrayHandle handle, const double other);
void LabelledControlArray_dividesequals_int(LabelledControlArrayHandle handle,
                                            const int                  other);
LabelledControlArrayHandle LabelledControlArray_divides_double(
    LabelledControlArrayHandle handle, const double other);
LabelledControlArrayHandle LabelledControlArray_divides_int(
    LabelledControlArrayHandle handle, const int other);
LabelledControlArrayHandle LabelledControlArray_pow(
    LabelledControlArrayHandle handle, const double other);
LabelledControlArrayHandle LabelledControlArray_abs(
    LabelledControlArrayHandle handle);
LabelledControlArrayHandle LabelledControlArray_min(
    LabelledControlArrayHandle handle);
LabelledControlArrayHandle LabelledControlArray_min_farray(
    LabelledControlArrayHandle handle, FArrayDoubleHandle other);
LabelledControlArrayHandle LabelledControlArray_min_control_array(
    LabelledControlArrayHandle handle, LabelledControlArrayHandle other);
LabelledControlArrayHandle LabelledControlArray_max(
    LabelledControlArrayHandle handle);
LabelledControlArrayHandle LabelledControlArray_max_farray(
    LabelledControlArrayHandle handle, FArrayDoubleHandle other);
LabelledControlArrayHandle LabelledControlArray_max_control_array(
    LabelledControlArrayHandle handle, LabelledControlArrayHandle other);
bool   LabelledControlArray_equality(LabelledControlArrayHandle handle,
                                     LabelledControlArrayHandle other);
bool   LabelledControlArray_notequality(LabelledControlArrayHandle handle,
                                        LabelledControlArrayHandle other);
bool   LabelledControlArray_greaterthan(LabelledControlArrayHandle handle,
                                        const double               value);
bool   LabelledControlArray_lessthan(LabelledControlArrayHandle handle,
                                     const double               value);
void   LabelledControlArray_remove_offset(LabelledControlArrayHandle handle,
                                          const double               offset);
double LabelledControlArray_sum(LabelledControlArrayHandle handle);
/* AUTO-DOC from cpp: LabelledControlArray_reshape | falcon_core::math::arrays::LabelledControlArray::reshape */
/**
 * @brief (from C++: falcon_core::math::arrays::LabelledControlArray::reshape)
 * @brief Return a new Array with the given shape.
 * @param shape The new shape.
 * @return A reshaped LabelledControlArray.
 */
LabelledControlArrayHandle LabelledControlArray_reshape(
    LabelledControlArrayHandle handle, const size_t* shape, size_t ndims);
ListListSizeTHandle LabelledControlArray_where(
    LabelledControlArrayHandle handle, const double value);
/* AUTO-DOC from cpp: LabelledControlArray_flip | falcon_core::math::arrays::LabelledControlArray::flip */
/**
 * @brief (from C++: falcon_core::math::arrays::LabelledControlArray::flip)
 * @brief Flip the data along the given axis.
 * @param axis The axis to flip.
 * @return A flipped LabelledControlArray.
 */
LabelledControlArrayHandle LabelledControlArray_flip(
    LabelledControlArrayHandle handle, size_t axis);
size_t LabelledControlArray_full_gradient(LabelledControlArrayHandle handle,
                                          FArrayDoubleHandle*        out_buffer,
                                          size_t buffer_size);
/* AUTO-DOC from cpp: LabelledControlArray_gradient | falcon_core::math::arrays::LabelledControlArray::gradient */
/**
 * @brief (from C++: falcon_core::math::arrays::LabelledControlArray::gradient)
 * @brief Return the gradient of the data along a given axis.
 * Computes the gradient along the specified axis using finite differences:
 * - For interior points, uses central difference: (f(x+1) - f(x-1)) / 2
 * - For boundary points, uses forward (first element) or backward (last
 * element) difference.
 * @param axis The axis to compute the gradient.
 * @return The gradient FArray.
 */
FArrayDoubleHandle LabelledControlArray_gradient(
    LabelledControlArrayHandle handle, size_t axis);
double LabelledControlArray_get_sum_of_squares(
    LabelledControlArrayHandle handle);
double LabelledControlArray_get_summed_diff_int_of_squares(
    LabelledControlArrayHandle handle, const int other);
double LabelledControlArray_get_summed_diff_double_of_squares(
    LabelledControlArrayHandle handle, const double other);
double LabelledControlArray_get_summed_diff_array_of_squares(
    LabelledControlArrayHandle handle, LabelledControlArrayHandle other);
// Serialization (from Song)
StringHandle LabelledControlArray_to_json_string(
    LabelledControlArrayHandle handle);
LabelledControlArrayHandle LabelledControlArray_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
