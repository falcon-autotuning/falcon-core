#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/ListFArrayDouble_c_api.h"
#include "falcon_core/generic/ListListSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"

typedef void* MeasuredArray1DHandle;

// @category:allocation
MeasuredArray1DHandle MeasuredArray1D_from_data(const double* data,
                                                const size_t* shape,
                                                size_t        ndim);
// @category:allocation
MeasuredArray1DHandle MeasuredArray1D_from_farray(FArrayDoubleHandle farray);
// @category:deallocation
void MeasuredArray1D_destroy(MeasuredArray1DHandle handle);
// @category:read
bool MeasuredArray1D_is_1D(MeasuredArray1DHandle handle);
// @category:read
FArrayDoubleHandle MeasuredArray1D_as_1D(MeasuredArray1DHandle handle);
// @category:read
double MeasuredArray1D_get_start(MeasuredArray1DHandle handle);
// @category:read
double MeasuredArray1D_get_end(MeasuredArray1DHandle handle);
// @category:read
bool MeasuredArray1D_is_decreasing(MeasuredArray1DHandle handle);
// @category:read
bool MeasuredArray1D_is_increasing(MeasuredArray1DHandle handle);
// @category:read
double MeasuredArray1D_get_distance(MeasuredArray1DHandle handle);
// @category:read
double MeasuredArray1D_get_mean(MeasuredArray1DHandle handle);
// @category:read
double MeasuredArray1D_get_std(MeasuredArray1DHandle handle);
// @category:write
void MeasuredArray1D_reverse(MeasuredArray1DHandle handle);
// @category:read
size_t MeasuredArray1D_get_closest_index(MeasuredArray1DHandle handle,
                                         double                value);
// @category:read
ListFArrayDoubleHandle MeasuredArray1D_even_divisions(
    MeasuredArray1DHandle handle, size_t divisions);
// @category:read
size_t MeasuredArray1D_size(MeasuredArray1DHandle handle);
// @category:read
size_t MeasuredArray1D_dimension(MeasuredArray1DHandle handle);
// @category:read
size_t MeasuredArray1D_shape(MeasuredArray1DHandle handle,
                             size_t*               out_buffer,
                             size_t                ndim);
// @category:read
size_t MeasuredArray1D_data(MeasuredArray1DHandle handle,
                            double*               out_buffer,
                            size_t                numdata);
// @category:write
void MeasuredArray1D_plus_equals_farray(MeasuredArray1DHandle handle,
                                       FArrayDoubleHandle    other);
// @category:write
void MeasuredArray1D_plus_equals_double(MeasuredArray1DHandle handle,
                                       double                other);
// @category:write
void MeasuredArray1D_plus_equals_int(MeasuredArray1DHandle handle, int other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_plus_measured_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_plus_farray(MeasuredArray1DHandle handle,
                                                  FArrayDoubleHandle    other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_plus_double(MeasuredArray1DHandle handle,
                                                  double                other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_plus_int(MeasuredArray1DHandle handle,
                                               int                   other);
// @category:write
void MeasuredArray1D_minus_equals_farray(MeasuredArray1DHandle handle,
                                        FArrayDoubleHandle    other);
// @category:write
void MeasuredArray1D_minus_equals_double(MeasuredArray1DHandle handle,
                                        double                other);
// @category:write
void MeasuredArray1D_minus_equals_int(MeasuredArray1DHandle handle, int other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_minus_measured_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_minus_farray(MeasuredArray1DHandle handle,
                                                   FArrayDoubleHandle    other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_minus_double(MeasuredArray1DHandle handle,
                                                   double                other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_minus_int(MeasuredArray1DHandle handle,
                                                int                   other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_negation(MeasuredArray1DHandle handle);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_times_equals_farray(
    MeasuredArray1DHandle handle, FArrayDoubleHandle other);
// @category:write
void MeasuredArray1D_times_equals_double(MeasuredArray1DHandle handle,
                                        double                other);
// @category:write
void MeasuredArray1D_times_equals_int(MeasuredArray1DHandle handle, int other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_times_measured_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_times_farray(MeasuredArray1DHandle handle,
                                                   FArrayDoubleHandle    other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_times_double(MeasuredArray1DHandle handle,
                                                   double                other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_times_int(MeasuredArray1DHandle handle,
                                                int                   other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_divides_equals_measured_array(
    MeasuredArray1DHandle handle, FArrayDoubleHandle other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_divides_equals_farray(
    MeasuredArray1DHandle handle, FArrayDoubleHandle other);
// @category:write
void MeasuredArray1D_divides_equals_double(MeasuredArray1DHandle handle,
                                          double                other);
// @category:write
void MeasuredArray1D_divides_equals_int(MeasuredArray1DHandle handle, int other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_divides_measured_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_divides_farray(
    MeasuredArray1DHandle handle, FArrayDoubleHandle other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_divides_double(
    MeasuredArray1DHandle handle, double other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_divides_int(MeasuredArray1DHandle handle,
                                                  int                   other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_pow(MeasuredArray1DHandle handle,
                                          double                other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_abs(MeasuredArray1DHandle handle);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_min_farray(MeasuredArray1DHandle handle,
                                                 FArrayDoubleHandle    other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_min_measured_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_max_farray(MeasuredArray1DHandle handle,
                                                 FArrayDoubleHandle    other);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_max_measured_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other);
// @category:read
bool MeasuredArray1D_equal(MeasuredArray1DHandle handle,
                              MeasuredArray1DHandle other);
// @category:read
bool MeasuredArray1D_not_equal(MeasuredArray1DHandle handle,
                                 MeasuredArray1DHandle other);
// @category:read
bool MeasuredArray1D_greater_than(MeasuredArray1DHandle handle, double value);
// @category:read
bool MeasuredArray1D_less_than(MeasuredArray1DHandle handle, double value);
// @category:write
void MeasuredArray1D_remove_offset(MeasuredArray1DHandle handle, double offset);
// @category:read
double MeasuredArray1D_sum(MeasuredArray1DHandle handle);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_reshape(MeasuredArray1DHandle handle,
                                              const size_t*         shape,
                                              size_t                ndims);
// @category:read
ListListSizeTHandle MeasuredArray1D_where(MeasuredArray1DHandle handle,
                                          double                value);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_flip(MeasuredArray1DHandle handle,
                                           size_t                axis);
// @category:read
size_t MeasuredArray1D_full_gradient(MeasuredArray1DHandle  handle,
                                     MeasuredArray1DHandle* out_buffer,
                                     size_t                 buffer_size);
// @category:read
MeasuredArray1DHandle MeasuredArray1D_gradient(MeasuredArray1DHandle handle,
                                               size_t                axis);
// @category:read
double MeasuredArray1D_get_sum_of_squares(MeasuredArray1DHandle handle);
// @category:read
double MeasuredArray1D_get_summed_diff_int_of_squares(
    MeasuredArray1DHandle handle, int other);
// @category:read
double MeasuredArray1D_get_summed_diff_double_of_squares(
    MeasuredArray1DHandle handle, double other);
// @category:read
double MeasuredArray1D_get_summed_diff_array_of_squares(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other);
// @category:read
StringHandle MeasuredArray1D_to_json_string(MeasuredArray1DHandle handle);
// @category:allocation
MeasuredArray1DHandle MeasuredArray1D_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
