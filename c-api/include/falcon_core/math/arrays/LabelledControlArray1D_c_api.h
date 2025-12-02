#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/ListFArrayDouble_c_api.h"
#include "falcon_core/generic/ListListSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/arrays/ControlArray_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
// Forward declarations for opaque handles
typedef void* LabelledControlArray1DHandle;

// Constructors
LabelledControlArray1DHandle LabelledControlArray1D_from_farray(
    FArrayDoubleHandle farray, AcquisitionContextHandle label);
LabelledControlArray1DHandle LabelledControlArray1D_from_control_array(
    ControlArrayHandle controlarray, AcquisitionContextHandle label);

// Destructor
void LabelledControlArray1D_destroy(LabelledControlArray1DHandle handle);

// Methods
bool LabelledControlArray1D_is_1D(LabelledControlArray1DHandle handle);
FArrayDoubleHandle LabelledControlArray1D_as_1D(
    LabelledControlArray1DHandle handle);
double LabelledControlArray1D_get_start(LabelledControlArray1DHandle handle);
double LabelledControlArray1D_get_end(LabelledControlArray1DHandle handle);
bool LabelledControlArray1D_is_decreasing(LabelledControlArray1DHandle handle);
bool LabelledControlArray1D_is_increasing(LabelledControlArray1DHandle handle);
double LabelledControlArray1D_get_distance(LabelledControlArray1DHandle handle);
double LabelledControlArray1D_get_mean(LabelledControlArray1DHandle handle);
double LabelledControlArray1D_get_std(LabelledControlArray1DHandle handle);
void   LabelledControlArray1D_reverse(LabelledControlArray1DHandle handle);
size_t LabelledControlArray1D_get_closest_index(
    LabelledControlArray1DHandle handle, double value);
ListFArrayDoubleHandle LabelledControlArray1D_even_divisions(
    LabelledControlArray1DHandle handle, size_t divisions);
AcquisitionContextHandle LabelledControlArray1D_label(
    LabelledControlArray1DHandle handle);
ConnectionHandle LabelledControlArray1D_connection(
    LabelledControlArray1DHandle handle);
StringHandle LabelledControlArray1D_instrument_type(
    LabelledControlArray1DHandle handle);
SymbolUnitHandle LabelledControlArray1D_units(
    LabelledControlArray1DHandle handle);
size_t LabelledControlArray1D_size(LabelledControlArray1DHandle handle);
size_t LabelledControlArray1D_dimension(LabelledControlArray1DHandle handle);
size_t LabelledControlArray1D_shape(LabelledControlArray1DHandle handle,
                                    size_t*                      out_buffer,
                                    size_t                       ndim);
size_t LabelledControlArray1D_data(LabelledControlArray1DHandle handle,
                                   double*                      out_buffer,
                                   size_t                       numdata);
void   LabelledControlArray1D_plusequals_farray(
      LabelledControlArray1DHandle handle, FArrayDoubleHandle other);
void LabelledControlArray1D_plusequals_double(
    LabelledControlArray1DHandle handle, const double other);
void LabelledControlArray1D_plusequals_int(LabelledControlArray1DHandle handle,
                                           const int                    other);
LabelledControlArray1DHandle LabelledControlArray1D_plus_control_array(
    LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other);
LabelledControlArray1DHandle LabelledControlArray1D_plus_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other);
LabelledControlArray1DHandle LabelledControlArray1D_plus_double(
    LabelledControlArray1DHandle handle, const double other);
LabelledControlArray1DHandle LabelledControlArray1D_plus_int(
    LabelledControlArray1DHandle handle, const int other);
void LabelledControlArray1D_minusequals_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other);
void LabelledControlArray1D_minusequals_double(
    LabelledControlArray1DHandle handle, const double other);
void LabelledControlArray1D_minusequals_int(LabelledControlArray1DHandle handle,
                                            const int                    other);
LabelledControlArray1DHandle LabelledControlArray1D_minus_control_array(
    LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other);
LabelledControlArray1DHandle LabelledControlArray1D_minus_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other);
LabelledControlArray1DHandle LabelledControlArray1D_minus_double(
    LabelledControlArray1DHandle handle, const double other);
LabelledControlArray1DHandle LabelledControlArray1D_minus_int(
    LabelledControlArray1DHandle handle, const int other);
LabelledControlArray1DHandle LabelledControlArray1D_negation(
    LabelledControlArray1DHandle handle);
void LabelledControlArray1D_timesequals_double(
    LabelledControlArray1DHandle handle, const double other);
void LabelledControlArray1D_timesequals_int(LabelledControlArray1DHandle handle,
                                            const int                    other);
LabelledControlArray1DHandle LabelledControlArray1D_times_double(
    LabelledControlArray1DHandle handle, const double other);
LabelledControlArray1DHandle LabelledControlArray1D_times_int(
    LabelledControlArray1DHandle handle, const int other);
void LabelledControlArray1D_dividesequals_double(
    LabelledControlArray1DHandle handle, const double other);
void LabelledControlArray1D_dividesequals_int(
    LabelledControlArray1DHandle handle, const int other);
LabelledControlArray1DHandle LabelledControlArray1D_divides_double(
    LabelledControlArray1DHandle handle, const double other);
LabelledControlArray1DHandle LabelledControlArray1D_divides_int(
    LabelledControlArray1DHandle handle, const int other);
LabelledControlArray1DHandle LabelledControlArray1D_pow(
    LabelledControlArray1DHandle handle, const double other);
LabelledControlArray1DHandle LabelledControlArray1D_abs(
    LabelledControlArray1DHandle handle);
LabelledControlArray1DHandle LabelledControlArray1D_min_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other);
LabelledControlArray1DHandle LabelledControlArray1D_min_control_array(
    LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other);
LabelledControlArray1DHandle LabelledControlArray1D_max_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other);
LabelledControlArray1DHandle LabelledControlArray1D_max_control_array(
    LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other);
bool   LabelledControlArray1D_equality(LabelledControlArray1DHandle handle,
                                       LabelledControlArray1DHandle other);
bool   LabelledControlArray1D_notequality(LabelledControlArray1DHandle handle,
                                          LabelledControlArray1DHandle other);
bool   LabelledControlArray1D_greaterthan(LabelledControlArray1DHandle handle,
                                          const double                 value);
bool   LabelledControlArray1D_lessthan(LabelledControlArray1DHandle handle,
                                       const double                 value);
void   LabelledControlArray1D_remove_offset(LabelledControlArray1DHandle handle,
                                            const double                 offset);
double LabelledControlArray1D_sum(LabelledControlArray1DHandle handle);
/* AUTO-DOC from cpp: LabelledControlArray1D_reshape | falcon_core::math::arrays::LabelledControlArray1D::reshape */
/**
 * @brief Return a new Array with the given shape.
 * @param shape The new shape.
 * @return A reshaped LabelledControlArray1D.
 */
LabelledControlArray1DHandle LabelledControlArray1D_reshape(
    LabelledControlArray1DHandle handle, const size_t* shape, size_t ndims);
ListListSizeTHandle LabelledControlArray1D_where(
    LabelledControlArray1DHandle handle, const double value);
/* AUTO-DOC from cpp: LabelledControlArray1D_flip | falcon_core::math::arrays::LabelledControlArray1D::flip */
/**
 * @brief Flip the data along the given axis.
 * @param axis The axis to flip.
 * @return A flipped LabelledControlArray1D.
 */
LabelledControlArray1DHandle LabelledControlArray1D_flip(
    LabelledControlArray1DHandle handle, size_t axis);
size_t LabelledControlArray1D_full_gradient(LabelledControlArray1DHandle handle,
                                            FArrayDoubleHandle* out_buffer,
                                            size_t              buffer_size);
/* AUTO-DOC from cpp: LabelledControlArray1D_gradient | falcon_core::math::arrays::LabelledControlArray1D::gradient */
/**
 * @brief Return the gradient of the data along a given axis.
 * Computes the gradient along the specified axis using finite differences:
 * - For interior points, uses central difference: (f(x+1) - f(x-1)) / 2
 * - For boundary points, uses forward (first element) or backward (last
 * element) difference.
 * @param axis The axis to compute the gradient.
 * @return The gradient FArray.
 */
/* AUTO-DOC from cpp: LabelledControlArray1D_gradient | falcon_core::math::arrays::LabelledControlArray1D::gradient */
/**
 * @brief Return the gradient of the data along a given axis.
 * Computes the gradient along the specified axis using finite differences:
 * - For interior points, uses central difference: (f(x+1) - f(x-1)) / 2
 * - For boundary points, uses forward (first element) or backward (last
 * element) difference.
 * @param axis The axis to compute the gradient.
 * @return The gradient FArray.
 */
FArrayDoubleHandle LabelledControlArray1D_gradient(
    LabelledControlArray1DHandle handle, size_t axis);
double LabelledControlArray1D_get_sum_of_squares(
    LabelledControlArray1DHandle handle);
double LabelledControlArray1D_get_summed_diff_int_of_squares(
    LabelledControlArray1DHandle handle, const int other);
double LabelledControlArray1D_get_summed_diff_double_of_squares(
    LabelledControlArray1DHandle handle, const double other);
double LabelledControlArray1D_get_summed_diff_array_of_squares(
    LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other);
// Serialization (from Song)
StringHandle LabelledControlArray1D_to_json_string(
    LabelledControlArray1DHandle handle);
LabelledControlArray1DHandle LabelledControlArray1D_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
