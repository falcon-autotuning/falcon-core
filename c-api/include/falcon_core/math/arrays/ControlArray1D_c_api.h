#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/ListFArrayDouble_c_api.h"
#include "falcon_core/generic/ListListSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"

typedef void* ControlArray1DHandle;

// @category:allocation
ControlArray1DHandle ControlArray1D_from_data(const double* data,
                                              const size_t* shape,
                                              size_t        ndim);
// @category:allocation
ControlArray1DHandle ControlArray1D_from_farray(FArrayDoubleHandle farray);
// @category:deallocation
void ControlArray1D_destroy(ControlArray1DHandle handle);
// @category:read
bool ControlArray1D_is_1D(ControlArray1DHandle handle);
// @category:read
FArrayDoubleHandle ControlArray1D_as_1D(ControlArray1DHandle handle);
// @category:read
double ControlArray1D_get_start(ControlArray1DHandle handle);
// @category:read
double ControlArray1D_get_end(ControlArray1DHandle handle);
// @category:read
bool ControlArray1D_is_decreasing(ControlArray1DHandle handle);
// @category:read
bool ControlArray1D_is_increasing(ControlArray1DHandle handle);
// @category:read
double ControlArray1D_get_distance(ControlArray1DHandle handle);
// @category:read
double ControlArray1D_get_mean(ControlArray1DHandle handle);
// @category:read
double ControlArray1D_get_std(ControlArray1DHandle handle);
// @category:write
void ControlArray1D_reverse(ControlArray1DHandle handle);
// @category:read
size_t ControlArray1D_get_closest_index(ControlArray1DHandle handle,
                                        double               value);
// @category:read
ListFArrayDoubleHandle ControlArray1D_even_divisions(
    ControlArray1DHandle handle, size_t divisions);
// @category:read
size_t ControlArray1D_size(ControlArray1DHandle handle);
// @category:read
size_t ControlArray1D_dimension(ControlArray1DHandle handle);
// @category:read
size_t ControlArray1D_shape(ControlArray1DHandle handle,
                            size_t*              out_buffer,
                            size_t               ndim);
// @category:read
size_t ControlArray1D_data(ControlArray1DHandle handle,
                           double*              out_buffer,
                           size_t               numdata);
// @category:write
void ControlArray1D_plus_equals_farray(ControlArray1DHandle handle,
                                      FArrayDoubleHandle   other);
// @category:write
void ControlArray1D_plus_equals_double(ControlArray1DHandle handle,
                                      double               other);
// @category:write
void ControlArray1D_plus_equals_int(ControlArray1DHandle handle, int other);
// @category:read
ControlArray1DHandle ControlArray1D_plus_control_array(
    ControlArray1DHandle handle, ControlArray1DHandle other);
// @category:read
ControlArray1DHandle ControlArray1D_plus_farray(ControlArray1DHandle handle,
                                                FArrayDoubleHandle   other);
// @category:read
ControlArray1DHandle ControlArray1D_plus_double(ControlArray1DHandle handle,
                                                double               other);
// @category:read
ControlArray1DHandle ControlArray1D_plus_int(ControlArray1DHandle handle,
                                             int                  other);
// @category:write
void ControlArray1D_minus_equals_farray(ControlArray1DHandle handle,
                                       FArrayDoubleHandle   other);
// @category:write
void ControlArray1D_minus_equals_double(ControlArray1DHandle handle,
                                       double               other);
// @category:write
void ControlArray1D_minus_equals_int(ControlArray1DHandle handle, int other);
// @category:read
ControlArray1DHandle ControlArray1D_minus_control_array(
    ControlArray1DHandle handle, ControlArray1DHandle other);
// @category:read
ControlArray1DHandle ControlArray1D_minus_farray(ControlArray1DHandle handle,
                                                 FArrayDoubleHandle   other);
// @category:read
ControlArray1DHandle ControlArray1D_minus_double(ControlArray1DHandle handle,
                                                 double               other);
// @category:read
ControlArray1DHandle ControlArray1D_minus_int(ControlArray1DHandle handle,
                                              int                  other);
// @category:read
ControlArray1DHandle ControlArray1D_negation(ControlArray1DHandle handle);
// @category:write
void ControlArray1D_times_equals_double(ControlArray1DHandle handle,
                                       double               other);
// @category:write
void ControlArray1D_times_equals_int(ControlArray1DHandle handle, int other);
// @category:read
ControlArray1DHandle ControlArray1D_times_double(ControlArray1DHandle handle,
                                                 double               other);
// @category:read
ControlArray1DHandle ControlArray1D_times_int(ControlArray1DHandle handle,
                                              int                  other);
// @category:write
void ControlArray1D_divides_equals_double(ControlArray1DHandle handle,
                                         double               other);
// @category:write
void ControlArray1D_divides_equals_int(ControlArray1DHandle handle, int other);
// @category:read
ControlArray1DHandle ControlArray1D_divides_double(ControlArray1DHandle handle,
                                                   double               other);
// @category:read
ControlArray1DHandle ControlArray1D_divides_int(ControlArray1DHandle handle,
                                                int                  other);
// @category:read
ControlArray1DHandle ControlArray1D_pow(ControlArray1DHandle handle,
                                        double               other);
// @category:read
ControlArray1DHandle ControlArray1D_abs(ControlArray1DHandle handle);
// @category:read
ControlArray1DHandle ControlArray1D_min_farray(ControlArray1DHandle handle,
                                               FArrayDoubleHandle   other);
// @category:read
ControlArray1DHandle ControlArray1D_min_control_array(
    ControlArray1DHandle handle, ControlArray1DHandle other);
// @category:read
ControlArray1DHandle ControlArray1D_max_farray(ControlArray1DHandle handle,
                                               FArrayDoubleHandle   other);
// @category:read
ControlArray1DHandle ControlArray1D_max_control_array(
    ControlArray1DHandle handle, ControlArray1DHandle other);
// @category:read
bool ControlArray1D_equal(ControlArray1DHandle handle,
                             ControlArray1DHandle other);
// @category:read
bool ControlArray1D_not_equal(ControlArray1DHandle handle,
                                ControlArray1DHandle other);
// @category:read
bool ControlArray1D_greater_than(ControlArray1DHandle handle, double value);
// @category:read
bool ControlArray1D_less_than(ControlArray1DHandle handle, double value);
// @category:write
void ControlArray1D_remove_offset(ControlArray1DHandle handle, double offset);
// @category:read
double ControlArray1D_sum(ControlArray1DHandle handle);
// @category:read
ListListSizeTHandle ControlArray1D_where(ControlArray1DHandle handle,
                                         double               value);
// @category:read
ControlArray1DHandle ControlArray1D_flip(ControlArray1DHandle handle,
                                         size_t               axis);
// @category:read
size_t ControlArray1D_full_gradient(ControlArray1DHandle handle,
                                    FArrayDoubleHandle*  out_buffer,
                                    size_t               buffer_size);
// @category:read
FArrayDoubleHandle ControlArray1D_gradient(ControlArray1DHandle handle,
                                           size_t               axis);
// @category:read
double ControlArray1D_get_sum_of_squares(ControlArray1DHandle handle);
// @category:read
double ControlArray1D_get_summed_diff_int_of_squares(
    ControlArray1DHandle handle, int other);
// @category:read
double ControlArray1D_get_summed_diff_double_of_squares(
    ControlArray1DHandle handle, double other);
// @category:read
double ControlArray1D_get_summed_diff_array_of_squares(
    ControlArray1DHandle handle, ControlArray1DHandle other);
// @category:read
StringHandle ControlArray1D_to_json_string(ControlArray1DHandle handle);
// @category:allocation
ControlArray1DHandle ControlArray1D_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
