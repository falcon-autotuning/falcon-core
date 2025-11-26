#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/ListListSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* FArrayDoubleHandle;
// Function declarations

// @category:allocation
FArrayDoubleHandle FArrayDouble_create_empty(const size_t* shape, size_t ndim);
// @category:allocation
FArrayDoubleHandle FArrayDouble_create_zeros(const size_t* shape, size_t ndim);
// @category:allocation
FArrayDoubleHandle FArrayDouble_from_shape(const size_t* shape, size_t ndim);
// @category:allocation
FArrayDoubleHandle FArrayDouble_from_data(const double* data, const size_t* shape, size_t ndim);
// @category:deallocation
void FArrayDouble_destroy(FArrayDoubleHandle handle);
// @category:read
size_t FArrayDouble_size(FArrayDoubleHandle handle);
// @category:read
size_t FArrayDouble_dimension(FArrayDoubleHandle handle);
// @category:read
size_t FArrayDouble_shape(FArrayDoubleHandle handle,size_t* out_buffer, size_t ndim);
// @category:read
size_t FArrayDouble_data(FArrayDoubleHandle handle, double* out_buffer, size_t numdata);
// @category:write
void FArrayDouble_plus_equals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other);
// @category:write
void FArrayDouble_plus_equals_double(FArrayDoubleHandle handle, double other);
// @category:write
void FArrayDouble_plus_equals_int(FArrayDoubleHandle handle, int other);
// @category:read
FArrayDoubleHandle FArrayDouble_plus_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other);
// @category:read
FArrayDoubleHandle FArrayDouble_plus_double(FArrayDoubleHandle handle,  double other);
// @category:read
FArrayDoubleHandle FArrayDouble_plus_int(FArrayDoubleHandle handle,  int other);
// @category:write
void FArrayDouble_minus_equals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other);
// @category:write
void FArrayDouble_minus_equals_double(FArrayDoubleHandle handle,  double other);
// @category:write
void FArrayDouble_minus_equals_int(FArrayDoubleHandle handle,  int other);
// @category:read
FArrayDoubleHandle FArrayDouble_minus_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other);
// @category:read
FArrayDoubleHandle FArrayDouble_minus_double(FArrayDoubleHandle handle,  double other);
// @category:read
FArrayDoubleHandle FArrayDouble_minus_int(FArrayDoubleHandle handle,  int other);
// @category:read
FArrayDoubleHandle FArrayDouble_negation(FArrayDoubleHandle handle);
// @category:write
void FArrayDouble_times_equals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other);
// @category:write
void FArrayDouble_times_equals_double(FArrayDoubleHandle handle,  double other);
// @category:write
void FArrayDouble_times_equals_int(FArrayDoubleHandle handle,  int other);
// @category:read
FArrayDoubleHandle FArrayDouble_times_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other);
// @category:read
FArrayDoubleHandle FArrayDouble_times_double(FArrayDoubleHandle handle,  double other);
// @category:read
FArrayDoubleHandle FArrayDouble_times_int(FArrayDoubleHandle handle,  int other);
// @category:write
void FArrayDouble_divides_equals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other);
// @category:write
void FArrayDouble_divides_equals_double(FArrayDoubleHandle handle,  double other);
// @category:write
void FArrayDouble_divides_equals_int(FArrayDoubleHandle handle,  int other);
// @category:read
FArrayDoubleHandle FArrayDouble_divides_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other);
// @category:read
FArrayDoubleHandle FArrayDouble_divides_double(FArrayDoubleHandle handle,  double other);
// @category:read
FArrayDoubleHandle FArrayDouble_divides_int(FArrayDoubleHandle handle,  int other);
// @category:read
FArrayDoubleHandle FArrayDouble_pow(FArrayDoubleHandle handle,  double other);
// @category:read
FArrayDoubleHandle FArrayDouble_double_pow(FArrayDoubleHandle handle,  double other);
// @category:write
void FArrayDouble_pow_inplace(FArrayDoubleHandle handle,  double other);
// @category:read
FArrayDoubleHandle FArrayDouble_abs(FArrayDoubleHandle handle);
// @category:read
double FArrayDouble_min(FArrayDoubleHandle handle);
// @category:read
FArrayDoubleHandle FArrayDouble_min_arraywise(FArrayDoubleHandle handle, FArrayDoubleHandle other);
// @category:read
double FArrayDouble_max(FArrayDoubleHandle handle);
// @category:read
FArrayDoubleHandle FArrayDouble_max_arraywise(FArrayDoubleHandle handle, FArrayDoubleHandle other);
// @category:read
bool FArrayDouble_equality(FArrayDoubleHandle handle, FArrayDoubleHandle other);
// @category:read
bool FArrayDouble_notequality(FArrayDoubleHandle handle, FArrayDoubleHandle other);
// @category:read
bool FArrayDouble_greaterthan(FArrayDoubleHandle handle,  double value);
// @category:read
bool FArrayDouble_lessthan(FArrayDoubleHandle handle,  double value);
// @category:write
void FArrayDouble_remove_offset(FArrayDoubleHandle handle,  double offset);
// @category:read
double FArrayDouble_sum(FArrayDoubleHandle handle);
// @category:read
FArrayDoubleHandle FArrayDouble_reshape(FArrayDoubleHandle handle, const size_t* shape, size_t ndims);
// @category:read
ListListSizeTHandle FArrayDouble_where(FArrayDoubleHandle handle,  double value);
// @category:read
FArrayDoubleHandle FArrayDouble_flip(FArrayDoubleHandle handle, size_t axis);
// @category:read
size_t FArrayDouble_full_gradient(FArrayDoubleHandle handle, FArrayDoubleHandle* out_buffer, size_t buffer_size);
// @category:read
FArrayDoubleHandle FArrayDouble_gradient(FArrayDoubleHandle handle, size_t axis);
// @category:read
double FArrayDouble_get_sum_of_squares(FArrayDoubleHandle handle);
// @category:read
double FArrayDouble_get_summed_diff_int_of_squares(FArrayDoubleHandle handle,  int other);
// @category:read
double FArrayDouble_get_summed_diff_double_of_squares(FArrayDoubleHandle handle,  double other);
// @category:read
double FArrayDouble_get_summed_diff_array_of_squares(FArrayDoubleHandle handle, FArrayDoubleHandle other);
// @category:read
StringHandle      FArrayDouble_to_json_string(FArrayDoubleHandle handle);
// @category:allocation
FArrayDoubleHandle FArrayDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
