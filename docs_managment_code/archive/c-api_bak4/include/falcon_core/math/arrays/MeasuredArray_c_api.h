#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/ListListSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"

typedef void* MeasuredArrayHandle;

// @category:allocation
MeasuredArrayHandle MeasuredArray_from_data(const double* data,
                                            const size_t* shape,
                                            size_t        ndim);
// @category:allocation
MeasuredArrayHandle MeasuredArray_from_farray(FArrayDoubleHandle farray);
// @category:deallocation
void MeasuredArray_destroy(MeasuredArrayHandle handle);
// @category:read
size_t MeasuredArray_size(MeasuredArrayHandle handle);
// @category:read
size_t MeasuredArray_dimension(MeasuredArrayHandle handle);
// @category:read
size_t MeasuredArray_shape(MeasuredArrayHandle handle,
                           size_t*             out_buffer,
                           size_t              ndim);
// @category:read
size_t MeasuredArray_data(MeasuredArrayHandle handle,
                          double*             out_buffer,
                          size_t              numdata);
// @category:write
void MeasuredArray_plus_equals_farray(MeasuredArrayHandle handle,
                                      FArrayDoubleHandle  other);
// @category:write
void MeasuredArray_plus_equals_double(MeasuredArrayHandle handle, double other);
// @category:write
void MeasuredArray_plus_equals_int(MeasuredArrayHandle handle, int other);
// @category:read
MeasuredArrayHandle MeasuredArray_plus_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other);
// @category:read
MeasuredArrayHandle MeasuredArray_plus_farray(MeasuredArrayHandle handle,
                                              FArrayDoubleHandle  other);
// @category:read
MeasuredArrayHandle MeasuredArray_plus_double(MeasuredArrayHandle handle,
                                              double              other);
// @category:read
MeasuredArrayHandle MeasuredArray_plus_int(MeasuredArrayHandle handle,
                                           int                 other);
// @category:write
void MeasuredArray_minus_equals_farray(MeasuredArrayHandle handle,
                                       FArrayDoubleHandle  other);
// @category:write
void MeasuredArray_minus_equals_double(MeasuredArrayHandle handle,
                                       double              other);
// @category:write
void MeasuredArray_minus_equals_int(MeasuredArrayHandle handle, int other);
// @category:read
MeasuredArrayHandle MeasuredArray_minus_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other);
// @category:read
MeasuredArrayHandle MeasuredArray_minus_farray(MeasuredArrayHandle handle,
                                               FArrayDoubleHandle  other);
// @category:read
MeasuredArrayHandle MeasuredArray_minus_double(MeasuredArrayHandle handle,
                                               double              other);
// @category:read
MeasuredArrayHandle MeasuredArray_minus_int(MeasuredArrayHandle handle,
                                            int                 other);
// @category:read
MeasuredArrayHandle MeasuredArray_negation(MeasuredArrayHandle handle);
// @category:write
MeasuredArrayHandle MeasuredArray_times_equals_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other);
// @category:write
MeasuredArrayHandle MeasuredArray_times_equals_farray(
    MeasuredArrayHandle handle, FArrayDoubleHandle other);
// @category:write
void MeasuredArray_times_equals_double(MeasuredArrayHandle handle,
                                       double              other);
// @category:write
void MeasuredArray_times_equals_int(MeasuredArrayHandle handle, int other);
// @category:read
MeasuredArrayHandle MeasuredArray_times_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other);
// @category:read
MeasuredArrayHandle MeasuredArray_times_farray(MeasuredArrayHandle handle,
                                               FArrayDoubleHandle  other);
// @category:read
MeasuredArrayHandle MeasuredArray_times_double(MeasuredArrayHandle handle,
                                               double              other);
// @category:read
MeasuredArrayHandle MeasuredArray_times_int(MeasuredArrayHandle handle,
                                            int                 other);
// @category:write
MeasuredArrayHandle MeasuredArray_divides_equals_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other);
// @category:write
MeasuredArrayHandle MeasuredArray_divides_equals_farray(
    MeasuredArrayHandle handle, FArrayDoubleHandle other);
// @category:write
void MeasuredArray_divides_equals_double(MeasuredArrayHandle handle,
                                         double              other);
// @category:write
void MeasuredArray_divides_equals_int(MeasuredArrayHandle handle, int other);
// @category:read
MeasuredArrayHandle MeasuredArray_divides_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other);
// @category:read
MeasuredArrayHandle MeasuredArray_divides_farray(MeasuredArrayHandle handle,
                                                 FArrayDoubleHandle  other);
// @category:read
MeasuredArrayHandle MeasuredArray_divides_double(MeasuredArrayHandle handle,
                                                 double              other);
// @category:read
MeasuredArrayHandle MeasuredArray_divides_int(MeasuredArrayHandle handle,
                                              int                 other);
// @category:read
MeasuredArrayHandle MeasuredArray_pow(MeasuredArrayHandle handle, double other);
// @category:read
MeasuredArrayHandle MeasuredArray_abs(MeasuredArrayHandle handle);
// @category:read
/* AUTO-DOC from cpp: MeasuredArray_min | falcon_core::math::arrays::MeasuredArray::min */
/**
 * @brief Return the minimum value of the array.
 */
double MeasuredArray_min(MeasuredArrayHandle handle);
// @category:read
MeasuredArrayHandle MeasuredArray_min_farray(MeasuredArrayHandle handle,
                                             FArrayDoubleHandle  other);
// @category:read
MeasuredArrayHandle MeasuredArray_min_measured_array(MeasuredArrayHandle handle,
                                                     MeasuredArrayHandle other);
// @category:read
/* AUTO-DOC from cpp: MeasuredArray_max | falcon_core::math::arrays::MeasuredArray::max */
/**
 * @brief Return the maximum value of the array.
 */
double MeasuredArray_max(MeasuredArrayHandle handle);
// @category:read
MeasuredArrayHandle MeasuredArray_max_farray(MeasuredArrayHandle handle,
                                             FArrayDoubleHandle  other);
// @category:read
MeasuredArrayHandle MeasuredArray_max_measured_array(MeasuredArrayHandle handle,
                                                     MeasuredArrayHandle other);
// @category:read
bool MeasuredArray_equal(MeasuredArrayHandle handle, MeasuredArrayHandle other);
// @category:read
bool MeasuredArray_not_equal(MeasuredArrayHandle handle,
                             MeasuredArrayHandle other);
// @category:read
bool MeasuredArray_greater_than(MeasuredArrayHandle handle, double value);
// @category:read
bool MeasuredArray_less_than(MeasuredArrayHandle handle, double value);
// @category:write
void MeasuredArray_remove_offset(MeasuredArrayHandle handle, double offset);
// @category:read
double MeasuredArray_sum(MeasuredArrayHandle handle);
// @category:read
/* AUTO-DOC from cpp: MeasuredArray_reshape | falcon_core::math::arrays::MeasuredArray::reshape */
/**
 * @brief Return a new Array with the given shape.
 * @param shape The new shape.
 * @return A reshaped MeasuredArray.
 */
MeasuredArrayHandle MeasuredArray_reshape(MeasuredArrayHandle handle,
                                          const size_t*       shape,
                                          size_t              ndims);
// @category:read
ListListSizeTHandle MeasuredArray_where(MeasuredArrayHandle handle,
                                        double              value);
// @category:read
/* AUTO-DOC from cpp: MeasuredArray_flip | falcon_core::math::arrays::MeasuredArray::flip */
/**
 * @brief Flip the data along the given axis.
 * @param axis The axis to flip.
 * @return A flipped MeasuredArray.
 */
MeasuredArrayHandle MeasuredArray_flip(MeasuredArrayHandle handle, size_t axis);
// @category:read
size_t MeasuredArray_full_gradient(MeasuredArrayHandle  handle,
                                   MeasuredArrayHandle* out_buffer,
                                   size_t               buffer_size);
// @category:read
/* AUTO-DOC from cpp: MeasuredArray_gradient | falcon_core::math::arrays::MeasuredArray::gradient */
/**
 * @brief Return the gradient of the data along a given axis.
 * Computes the gradient along the specified axis using finite differences:
 * - For interior points, uses central difference: (f(x+1) - f(x-1)) / 2
 * - For boundary points, uses forward (first element) or backward (last
 * element) difference.
 * @param axis The axis to compute the gradient.
 * @return The gradient FArray.
 */
MeasuredArrayHandle MeasuredArray_gradient(MeasuredArrayHandle handle,
                                           size_t              axis);
// @category:read
double MeasuredArray_get_sum_of_squares(MeasuredArrayHandle handle);
// @category:read
double MeasuredArray_get_summed_diff_int_of_squares(MeasuredArrayHandle handle,
                                                    int                 other);
// @category:read
double MeasuredArray_get_summed_diff_double_of_squares(
    MeasuredArrayHandle handle, double other);
// @category:read
double MeasuredArray_get_summed_diff_array_of_squares(
    MeasuredArrayHandle handle, MeasuredArrayHandle other);
// @category:read
StringHandle MeasuredArray_to_json_string(MeasuredArrayHandle handle);
// @category:allocation
MeasuredArrayHandle MeasuredArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
