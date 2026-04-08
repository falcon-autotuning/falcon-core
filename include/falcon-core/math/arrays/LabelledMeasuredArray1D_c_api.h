#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon-core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"
#include "falcon-core/generic/FArrayDouble_c_api.h"
#include "falcon-core/generic/ListFArrayDouble_c_api.h"
#include "falcon-core/generic/ListListSizeT_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/math/arrays/MeasuredArray_c_api.h"

typedef void* LabelledMeasuredArray1DHandle;

// @category:allocation
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_copy(LabelledMeasuredArray1DHandle handle);
// @category:deallocation
FALCON_CORE_C_API void LabelledMeasuredArray1D_destroy(
    LabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API bool LabelledMeasuredArray1D_equal(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
// @category:read
FALCON_CORE_C_API bool LabelledMeasuredArray1D_not_equal(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
LabelledMeasuredArray1D_to_json_string(LabelledMeasuredArray1DHandle handle);
// @category:allocation
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_from_farray(FArrayDoubleHandle       farray,
                                    AcquisitionContextHandle label);
// @category:allocation
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_from_measured_array(MeasuredArrayHandle measuredarray,
                                            AcquisitionContextHandle label);
// @category:read
FALCON_CORE_C_API bool LabelledMeasuredArray1D_is_1D(
    LabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API FArrayDoubleHandle
LabelledMeasuredArray1D_as_1D(LabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API double LabelledMeasuredArray1D_get_start(
    LabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API double LabelledMeasuredArray1D_get_end(
    LabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API bool LabelledMeasuredArray1D_is_decreasing(
    LabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API bool LabelledMeasuredArray1D_is_increasing(
    LabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API double LabelledMeasuredArray1D_get_distance(
    LabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API double LabelledMeasuredArray1D_get_mean(
    LabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API double LabelledMeasuredArray1D_get_std(
    LabelledMeasuredArray1DHandle handle);
// @category:write
FALCON_CORE_C_API void LabelledMeasuredArray1D_reverse(
    LabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API size_t LabelledMeasuredArray1D_get_closest_index(
    LabelledMeasuredArray1DHandle handle, double value);
// @category:read
FALCON_CORE_C_API ListFArrayDoubleHandle LabelledMeasuredArray1D_even_divisions(
    LabelledMeasuredArray1DHandle handle, size_t divisions);
// @category:read
FALCON_CORE_C_API AcquisitionContextHandle
LabelledMeasuredArray1D_label(LabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API ConnectionHandle
LabelledMeasuredArray1D_connection(LabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API StringHandle
LabelledMeasuredArray1D_instrument_type(LabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API SymbolUnitHandle
LabelledMeasuredArray1D_units(LabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API size_t
LabelledMeasuredArray1D_size(LabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API size_t
LabelledMeasuredArray1D_dimension(LabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API size_t LabelledMeasuredArray1D_shape(
    LabelledMeasuredArray1DHandle handle, size_t* out_buffer, size_t ndim);
// @category:read
FALCON_CORE_C_API size_t LabelledMeasuredArray1D_data(
    LabelledMeasuredArray1DHandle handle, double* out_buffer, size_t numdata);
// @category:write
FALCON_CORE_C_API void LabelledMeasuredArray1D_plus_equals_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
// @category:write
FALCON_CORE_C_API void LabelledMeasuredArray1D_plus_equals_double(
    LabelledMeasuredArray1DHandle handle, double other);
// @category:write
FALCON_CORE_C_API void LabelledMeasuredArray1D_plus_equals_int(
    LabelledMeasuredArray1DHandle handle, int other);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_plus_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_plus_farray(LabelledMeasuredArray1DHandle handle,
                                    FArrayDoubleHandle            other);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_plus_double(LabelledMeasuredArray1DHandle handle,
                                    double                        other);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_plus_int(LabelledMeasuredArray1DHandle handle,
                                 int                           other);
// @category:write
FALCON_CORE_C_API void LabelledMeasuredArray1D_minus_equals_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
// @category:write
FALCON_CORE_C_API void LabelledMeasuredArray1D_minus_equals_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
// @category:write
FALCON_CORE_C_API void LabelledMeasuredArray1D_minus_equals_double(
    LabelledMeasuredArray1DHandle handle, double other);
// @category:write
FALCON_CORE_C_API void LabelledMeasuredArray1D_minus_equals_int(
    LabelledMeasuredArray1DHandle handle, int other);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_minus_measured_array(
    LabelledMeasuredArray1DHandle handle, MeasuredArrayHandle other);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_minus_farray(LabelledMeasuredArray1DHandle handle,
                                     FArrayDoubleHandle            other);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_minus_double(LabelledMeasuredArray1DHandle handle,
                                     double                        other);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_minus_int(LabelledMeasuredArray1DHandle handle,
                                  int                           other);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_negation(LabelledMeasuredArray1DHandle handle);
// @category:write
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_times_equals_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
// @category:write
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_times_equals_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
// @category:write
FALCON_CORE_C_API void LabelledMeasuredArray1D_times_equals_double(
    LabelledMeasuredArray1DHandle handle, double other);
// @category:write
FALCON_CORE_C_API void LabelledMeasuredArray1D_times_equals_int(
    LabelledMeasuredArray1DHandle handle, int other);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_times_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_times_farray(LabelledMeasuredArray1DHandle handle,
                                     FArrayDoubleHandle            other);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_times_double(LabelledMeasuredArray1DHandle handle,
                                     double                        other);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_times_int(LabelledMeasuredArray1DHandle handle,
                                  int                           other);
// @category:write
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_divides_equals_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
// @category:write
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_divides_equals_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
// @category:write
FALCON_CORE_C_API void LabelledMeasuredArray1D_divides_equals_double(
    LabelledMeasuredArray1DHandle handle, double other);
// @category:write
FALCON_CORE_C_API void LabelledMeasuredArray1D_divides_equals_int(
    LabelledMeasuredArray1DHandle handle, int other);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_divides_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_divides_farray(LabelledMeasuredArray1DHandle handle,
                                       FArrayDoubleHandle            other);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_divides_double(LabelledMeasuredArray1DHandle handle,
                                       double                        other);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_divides_int(LabelledMeasuredArray1DHandle handle,
                                    int                           other);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_pow(LabelledMeasuredArray1DHandle handle, double other);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_abs(LabelledMeasuredArray1DHandle handle);
// @category:read
/* AUTO-DOC from cpp: LabelledMeasuredArray1D_min |
 * falcon_core::math::arrays::LabelledMeasuredArray1D::min */
/**
 * @brief Return the minimum value of the array.
 */
FALCON_CORE_C_API double LabelledMeasuredArray1D_min(
    LabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_min_farray(LabelledMeasuredArray1DHandle handle,
                                   FArrayDoubleHandle            other);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_min_measured_array(LabelledMeasuredArray1DHandle handle,
                                           LabelledMeasuredArray1DHandle other);
// @category:read
/* AUTO-DOC from cpp: LabelledMeasuredArray1D_max |
 * falcon_core::math::arrays::LabelledMeasuredArray1D::max */
/**
 * @brief Return the maximum value of the array.
 */
FALCON_CORE_C_API double LabelledMeasuredArray1D_max(
    LabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_max_farray(LabelledMeasuredArray1DHandle handle,
                                   FArrayDoubleHandle            other);
// @category:read
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_max_measured_array(LabelledMeasuredArray1DHandle handle,
                                           LabelledMeasuredArray1DHandle other);
// @category:read
FALCON_CORE_C_API bool LabelledMeasuredArray1D_greater_than(
    LabelledMeasuredArray1DHandle handle, double value);
// @category:read
FALCON_CORE_C_API bool LabelledMeasuredArray1D_less_than(
    LabelledMeasuredArray1DHandle handle, double value);
// @category:write
FALCON_CORE_C_API void LabelledMeasuredArray1D_remove_offset(
    LabelledMeasuredArray1DHandle handle, double offset);
// @category:read
FALCON_CORE_C_API double LabelledMeasuredArray1D_sum(
    LabelledMeasuredArray1DHandle handle);
// @category:read
/* AUTO-DOC from cpp: LabelledMeasuredArray1D_reshape |
 * falcon_core::math::arrays::LabelledMeasuredArray1D::reshape */
/**
 * @brief Return a new Array with the given shape.
 * @param shape The new shape.
 * @return A reshaped LabelledMeasuredArray1D.
 */
FALCON_CORE_C_API LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_reshape(
    LabelledMeasuredArray1DHandle handle, const size_t* shape, size_t ndims);
// @category:read
FALCON_CORE_C_API ListListSizeTHandle LabelledMeasuredArray1D_where(
    LabelledMeasuredArray1DHandle handle, double value);
// @category:read
/* AUTO-DOC from cpp: LabelledMeasuredArray1D_flip |
 * falcon_core::math::arrays::LabelledMeasuredArray1D::flip */
/**
 * @brief Flip the data along the given axis.
 * @param axis The axis to flip.
 * @return A flipped LabelledMeasuredArray1D.
 */
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_flip(LabelledMeasuredArray1DHandle handle, size_t axis);
// @category:read
FALCON_CORE_C_API size_t
LabelledMeasuredArray1D_full_gradient(LabelledMeasuredArray1DHandle  handle,
                                      LabelledMeasuredArray1DHandle* out_buffer,
                                      size_t buffer_size);
// @category:read
/* AUTO-DOC from cpp: LabelledMeasuredArray1D_gradient |
 * falcon_core::math::arrays::LabelledMeasuredArray1D::gradient */
/**
 * @brief Return the gradient of the data along a given axis.
 * Computes the gradient along the specified axis using finite differences:
 * - For interior points, uses central difference: (f(x+1) - f(x-1)) / 2
 * - For boundary points, uses forward (first element) or backward (last
 * element) difference.
 * @param axis The axis to compute the gradient.
 * @return The gradient FArray.
 */
/* AUTO-DOC from cpp: LabelledMeasuredArray1D_gradient |
 * falcon_core::math::arrays::LabelledMeasuredArray1D::gradient */
/**
 * @brief Return the gradient of the data along a given axis.
 * Computes the gradient along the specified axis using finite differences:
 * - For interior points, uses central difference: (f(x+1) - f(x-1)) / 2
 * - For boundary points, uses forward (first element) or backward (last
 * element) difference.
 * @param axis The axis to compute the gradient.
 * @return The gradient FArray.
 */
FALCON_CORE_C_API LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_gradient(LabelledMeasuredArray1DHandle handle,
                                 size_t                        axis);
// @category:read
FALCON_CORE_C_API double LabelledMeasuredArray1D_get_sum_of_squares(
    LabelledMeasuredArray1DHandle handle);
// @category:read
FALCON_CORE_C_API double LabelledMeasuredArray1D_get_summed_diff_int_of_squares(
    LabelledMeasuredArray1DHandle handle, int other);
// @category:read
FALCON_CORE_C_API double
LabelledMeasuredArray1D_get_summed_diff_double_of_squares(
    LabelledMeasuredArray1DHandle handle, double other);
// @category:read
FALCON_CORE_C_API double
LabelledMeasuredArray1D_get_summed_diff_array_of_squares(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);

#ifdef __cplusplus
}
#endif
