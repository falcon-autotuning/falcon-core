#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/ListListSizeT_c_api.h"
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* FArrayIntHandle;
// Function declarations

// @category:allocation
FArrayIntHandle FArrayInt_create_empty(const size_t* shape, size_t ndim);
// @category:allocation
FArrayIntHandle FArrayInt_create_zeros(const size_t* shape, size_t ndim);
// @category:allocation
FArrayIntHandle FArrayInt_from_shape(const size_t* shape, size_t ndim);
// @category:allocation
FArrayIntHandle FArrayInt_from_data(const int* data, const size_t* shape, size_t ndim);
// @category:deallocation
void FArrayInt_destroy(FArrayIntHandle handle);
// @category:read
size_t FArrayInt_size(FArrayIntHandle handle);
// @category:read
size_t FArrayInt_dimension(FArrayIntHandle handle);
// @category:read
size_t FArrayInt_shape(FArrayIntHandle handle,size_t* out_buffer, size_t ndim);
// @category:read
size_t FArrayInt_data(FArrayIntHandle handle, int* out_buffer, size_t numdata);
// @category:write
void FArrayInt_plus_equals_farray(FArrayIntHandle handle, FArrayIntHandle other);
// @category:write
void FArrayInt_plus_equals_double(FArrayIntHandle handle, double other);
// @category:write
void FArrayInt_plus_equals_int(FArrayIntHandle handle, int other);
// @category:read
FArrayIntHandle FArrayInt_plus_farray(FArrayIntHandle handle, FArrayIntHandle other);
// @category:read
FArrayIntHandle FArrayInt_plus_double(FArrayIntHandle handle,  double other);
// @category:read
FArrayIntHandle FArrayInt_plus_int(FArrayIntHandle handle,  int other);
// @category:write
void FArrayInt_minus_equals_farray(FArrayIntHandle handle, FArrayIntHandle other);
// @category:write
void FArrayInt_minus_equals_double(FArrayIntHandle handle,  double other);
// @category:write
void FArrayInt_minus_equals_int(FArrayIntHandle handle,  int other);
// @category:read
FArrayIntHandle FArrayInt_minus_farray(FArrayIntHandle handle, FArrayIntHandle other);
// @category:read
FArrayIntHandle FArrayInt_minus_double(FArrayIntHandle handle,  double other);
// @category:read
FArrayIntHandle FArrayInt_minus_int(FArrayIntHandle handle,  int other);
// @category:read
FArrayIntHandle FArrayInt_negation(FArrayIntHandle handle);
// @category:write
void FArrayInt_times_equals_farray(FArrayIntHandle handle, FArrayIntHandle other);
// @category:write
void FArrayInt_times_equals_double(FArrayIntHandle handle,  double other);
// @category:write
void FArrayInt_times_equals_int(FArrayIntHandle handle,  int other);
// @category:read
FArrayIntHandle FArrayInt_times_farray(FArrayIntHandle handle, FArrayIntHandle other);
// @category:read
FArrayIntHandle FArrayInt_times_double(FArrayIntHandle handle,  double other);
// @category:read
FArrayIntHandle FArrayInt_times_int(FArrayIntHandle handle,  int other);
// @category:write
void FArrayInt_divides_equals_farray(FArrayIntHandle handle, FArrayIntHandle other);
// @category:write
void FArrayInt_divides_equals_double(FArrayIntHandle handle,  double other);
// @category:write
void FArrayInt_divides_equals_int(FArrayIntHandle handle,  int other);
// @category:read
FArrayIntHandle FArrayInt_divides_farray(FArrayIntHandle handle, FArrayIntHandle other);
// @category:read
FArrayIntHandle FArrayInt_divides_double(FArrayIntHandle handle,  double other);
// @category:read
FArrayIntHandle FArrayInt_divides_int(FArrayIntHandle handle,  int other);
// @category:read
FArrayIntHandle FArrayInt_pow(FArrayIntHandle handle,  int other);
// @category:read
FArrayDoubleHandle FArrayInt_double_pow(FArrayIntHandle handle,  double other);
// @category:write
void FArrayInt_pow_inplace(FArrayIntHandle handle,  int other);
// @category:read
FArrayIntHandle FArrayInt_abs(FArrayIntHandle handle);
// @category:read
int FArrayInt_min(FArrayIntHandle handle);
// @category:read
FArrayIntHandle FArrayInt_min_arraywise(FArrayIntHandle handle, FArrayIntHandle other);
// @category:read
int FArrayInt_max(FArrayIntHandle handle);
// @category:read
FArrayIntHandle FArrayInt_max_arraywise(FArrayIntHandle handle, FArrayIntHandle other);
// @category:read
bool FArrayInt_equal(FArrayIntHandle handle, FArrayIntHandle other);
// @category:read
bool FArrayInt_not_equal(FArrayIntHandle handle, FArrayIntHandle other);
// @category:read
bool FArrayInt_greater_than(FArrayIntHandle handle,  int value);
// @category:read
bool FArrayInt_less_than(FArrayIntHandle handle,  int value);
// @category:write
void FArrayInt_remove_offset(FArrayIntHandle handle,  int offset);
// @category:read
int FArrayInt_sum(FArrayIntHandle handle);
// @category:read
FArrayIntHandle FArrayInt_reshape(FArrayIntHandle handle, const size_t* shape, size_t ndims);
// @category:read
ListListSizeTHandle FArrayInt_where(FArrayIntHandle handle,  int value);
// @category:read
FArrayIntHandle FArrayInt_flip(FArrayIntHandle handle, size_t axis);
// @category:read
size_t FArrayInt_full_gradient(FArrayIntHandle handle, FArrayIntHandle* out_buffer, size_t buffer_size);
// @category:read
FArrayIntHandle FArrayInt_gradient(FArrayIntHandle handle, size_t axis);
// @category:read
double FArrayInt_get_sum_of_squares(FArrayIntHandle handle);
// @category:read
double FArrayInt_get_summed_diff_int_of_squares(FArrayIntHandle handle,  int other);
// @category:read
double FArrayInt_get_summed_diff_double_of_squares(FArrayIntHandle handle,  double other);
// @category:read
double FArrayInt_get_summed_diff_array_of_squares(FArrayIntHandle handle, FArrayIntHandle other);
// @category:read
StringHandle      FArrayInt_to_json_string(FArrayIntHandle handle);
// @category:allocation
FArrayIntHandle FArrayInt_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif