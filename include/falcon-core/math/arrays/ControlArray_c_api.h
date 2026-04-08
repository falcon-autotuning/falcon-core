#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon-core/export_c_api.h"
#include "falcon-core/generic/FArrayDouble_c_api.h"
#include "falcon-core/generic/ListListSizeT_c_api.h"
#include "falcon-core/generic/String_c_api.h"

typedef void* ControlArrayHandle;

// @category:allocation
FALCON_CORE_C_API ControlArrayHandle
ControlArray_copy(ControlArrayHandle handle);
// @category:deallocation
FALCON_CORE_C_API void ControlArray_destroy(ControlArrayHandle handle);
// @category:read
FALCON_CORE_C_API bool ControlArray_equal(ControlArrayHandle handle,
                                          ControlArrayHandle other);
// @category:read
FALCON_CORE_C_API bool ControlArray_not_equal(ControlArrayHandle handle,
                                              ControlArrayHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
ControlArray_to_json_string(ControlArrayHandle handle);
// @category:allocation
FALCON_CORE_C_API ControlArrayHandle
ControlArray_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API ControlArrayHandle ControlArray_from_data(const double* data,
                                                            const size_t* shape,
                                                            size_t        ndim);
// @category:allocation
FALCON_CORE_C_API ControlArrayHandle
ControlArray_from_farray(FArrayDoubleHandle farray);
// @category:read
FALCON_CORE_C_API size_t ControlArray_size(ControlArrayHandle handle);
// @category:read
FALCON_CORE_C_API size_t ControlArray_dimension(ControlArrayHandle handle);
// @category:read
FALCON_CORE_C_API size_t ControlArray_shape(ControlArrayHandle handle,
                                            size_t*            out_buffer,
                                            size_t             ndim);
// @category:read
FALCON_CORE_C_API size_t ControlArray_data(ControlArrayHandle handle,
                                           double*            out_buffer,
                                           size_t             numdata);
// @category:write
FALCON_CORE_C_API void ControlArray_plus_equals_farray(
    ControlArrayHandle handle, FArrayDoubleHandle other);
// @category:write
FALCON_CORE_C_API void ControlArray_plus_equals_double(
    ControlArrayHandle handle, double other);
// @category:write
FALCON_CORE_C_API void ControlArray_plus_equals_int(ControlArrayHandle handle,
                                                    int                other);
// @category:read
FALCON_CORE_C_API ControlArrayHandle ControlArray_plus_control_array(
    ControlArrayHandle handle, ControlArrayHandle other);
// @category:read
FALCON_CORE_C_API ControlArrayHandle
ControlArray_plus_farray(ControlArrayHandle handle, FArrayDoubleHandle other);
// @category:read
FALCON_CORE_C_API ControlArrayHandle
ControlArray_plus_double(ControlArrayHandle handle, double other);
// @category:read
FALCON_CORE_C_API ControlArrayHandle
ControlArray_plus_int(ControlArrayHandle handle, int other);
// @category:write
FALCON_CORE_C_API void ControlArray_minus_equals_farray(
    ControlArrayHandle handle, FArrayDoubleHandle other);
// @category:write
FALCON_CORE_C_API void ControlArray_minus_equals_double(
    ControlArrayHandle handle, double other);
// @category:write
FALCON_CORE_C_API void ControlArray_minus_equals_int(ControlArrayHandle handle,
                                                     int                other);
// @category:read
FALCON_CORE_C_API ControlArrayHandle ControlArray_minus_control_array(
    ControlArrayHandle handle, ControlArrayHandle other);
// @category:read
FALCON_CORE_C_API ControlArrayHandle
ControlArray_minus_farray(ControlArrayHandle handle, FArrayDoubleHandle other);
// @category:read
FALCON_CORE_C_API ControlArrayHandle
ControlArray_minus_double(ControlArrayHandle handle, double other);
// @category:read
FALCON_CORE_C_API ControlArrayHandle
ControlArray_minus_int(ControlArrayHandle handle, int other);
// @category:read
FALCON_CORE_C_API ControlArrayHandle
ControlArray_negation(ControlArrayHandle handle);
// @category:write
FALCON_CORE_C_API void ControlArray_times_equals_double(
    ControlArrayHandle handle, double other);
// @category:write
FALCON_CORE_C_API void ControlArray_times_equals_int(ControlArrayHandle handle,
                                                     int                other);
// @category:read
FALCON_CORE_C_API ControlArrayHandle
ControlArray_times_double(ControlArrayHandle handle, double other);
// @category:read
FALCON_CORE_C_API ControlArrayHandle
ControlArray_times_int(ControlArrayHandle handle, int other);
// @category:write
FALCON_CORE_C_API void ControlArray_divides_equals_double(
    ControlArrayHandle handle, double other);
// @category:write
FALCON_CORE_C_API void ControlArray_divides_equals_int(
    ControlArrayHandle handle, int other);
// @category:read
FALCON_CORE_C_API ControlArrayHandle
ControlArray_divides_double(ControlArrayHandle handle, double other);
// @category:read
FALCON_CORE_C_API ControlArrayHandle
ControlArray_divides_int(ControlArrayHandle handle, int other);
// @category:read
FALCON_CORE_C_API ControlArrayHandle ControlArray_pow(ControlArrayHandle handle,
                                                      double             other);
// @category:read
FALCON_CORE_C_API ControlArrayHandle
ControlArray_abs(ControlArrayHandle handle);
// @category:read
/* AUTO-DOC from cpp: ControlArray_min |
 * falcon_core::math::arrays::ControlArray::min */
/**
 * @brief Return the minimum value of the array.
 */
FALCON_CORE_C_API double ControlArray_min(ControlArrayHandle handle);
// @category:read
FALCON_CORE_C_API ControlArrayHandle
ControlArray_min_farray(ControlArrayHandle handle, FArrayDoubleHandle other);
// @category:read
FALCON_CORE_C_API ControlArrayHandle ControlArray_min_control_array(
    ControlArrayHandle handle, ControlArrayHandle other);
// @category:read
/* AUTO-DOC from cpp: ControlArray_max |
 * falcon_core::math::arrays::ControlArray::max */
/**
 * @brief Return the maximum value of the array.
 */
FALCON_CORE_C_API double ControlArray_max(ControlArrayHandle handle);
// @category:read
FALCON_CORE_C_API ControlArrayHandle
ControlArray_max_farray(ControlArrayHandle handle, FArrayDoubleHandle other);
// @category:read
FALCON_CORE_C_API ControlArrayHandle ControlArray_max_control_array(
    ControlArrayHandle handle, ControlArrayHandle other);
// @category:read
FALCON_CORE_C_API bool ControlArray_greater_than(ControlArrayHandle handle,
                                                 double             value);
// @category:read
FALCON_CORE_C_API bool ControlArray_less_than(ControlArrayHandle handle,
                                              double             value);
// @category:write
FALCON_CORE_C_API void ControlArray_remove_offset(ControlArrayHandle handle,
                                                  double             offset);
// @category:read
FALCON_CORE_C_API double ControlArray_sum(ControlArrayHandle handle);
// @category:read
FALCON_CORE_C_API ListListSizeTHandle
ControlArray_where(ControlArrayHandle handle, double value);
// @category:read
/* AUTO-DOC from cpp: ControlArray_flip |
 * falcon_core::math::arrays::ControlArray::flip */
/**
 * @brief Flip the data along the given axis.
 * @param axis The axis to flip.
 * @return A flipped ControlArray.
 */
FALCON_CORE_C_API ControlArrayHandle
ControlArray_flip(ControlArrayHandle handle, size_t axis);
// @category:read
FALCON_CORE_C_API size_t
ControlArray_full_gradient(ControlArrayHandle  handle,
                           FArrayDoubleHandle* out_buffer,
                           size_t              buffer_size);
// @category:read
FALCON_CORE_C_API FArrayDoubleHandle
ControlArray_gradient(ControlArrayHandle handle, size_t axis);
// @category:read
FALCON_CORE_C_API double ControlArray_get_sum_of_squares(
    ControlArrayHandle handle);
// @category:read
FALCON_CORE_C_API double ControlArray_get_summed_diff_int_of_squares(
    ControlArrayHandle handle, int other);
// @category:read
FALCON_CORE_C_API double ControlArray_get_summed_diff_double_of_squares(
    ControlArrayHandle handle, double other);
// @category:read
FALCON_CORE_C_API double ControlArray_get_summed_diff_array_of_squares(
    ControlArrayHandle handle, ControlArrayHandle other);

#ifdef __cplusplus
}
#endif
