#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <cstddef>
#include "falcon_core/generic/ListListSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* FArrayDoubleHandle;
// Function declarations

FArrayDoubleHandle FArrayDouble_create_empty();
FArrayDoubleHandle FArrayDouble_from_shape(const size_t* shape, size_t ndim);
FArrayDoubleHandle FArrayDouble_from_data(const double* data, const size_t* shape, size_t ndim);
void FArrayDouble_destroy(FArrayDoubleHandle handle);
size_t FArrayDouble_size(FArrayDoubleHandle handle);
size_t FArrayDouble_dimension(FArrayDoubleHandle handle);
size_t FArrayDouble_shape(FArrayDoubleHandle handle, size_t* out_buffer, size_t ndim);
size_t FArrayDouble_data(FArrayDoubleHandle handle, double* out_buffer, size_t numdata);
void FArrayDouble_plusequals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other);
void FArrayDouble_plusequals_double(FArrayDoubleHandle handle, const double other);
void FArrayDouble_plusequals_int(FArrayDoubleHandle handle, const int other);
FArrayDoubleHandle FArrayDouble_plus_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other);
FArrayDoubleHandle FArrayDouble_plus_double(FArrayDoubleHandle handle, const double other);
FArrayDoubleHandle FArrayDouble_plus_int(FArrayDoubleHandle handle, const int other);
void FArrayDouble_minusequals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other);
void FArrayDouble_minusequals_double(FArrayDoubleHandle handle, const double other);
void FArrayDouble_minusequals_int(FArrayDoubleHandle handle, const int other);
FArrayDoubleHandle FArrayDouble_minus_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other);
FArrayDoubleHandle FArrayDouble_minus_double(FArrayDoubleHandle handle, const double other);
FArrayDoubleHandle FArrayDouble_minus_int(FArrayDoubleHandle handle, const int other);
FArrayDoubleHandle FArrayDouble_negation(FArrayDoubleHandle handle);
void FArrayDouble_timesequals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other);
void FArrayDouble_timesequals_double(FArrayDoubleHandle handle, const double other);
void FArrayDouble_timesequals_int(FArrayDoubleHandle handle, const int other);
FArrayDoubleHandle FArrayDouble_times_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other);
FArrayDoubleHandle FArrayDouble_times_double(FArrayDoubleHandle handle, const double other);
FArrayDoubleHandle FArrayDouble_times_int(FArrayDoubleHandle handle, const int other);
void FArrayDouble_dividesequals_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other);
void FArrayDouble_dividesequals_double(FArrayDoubleHandle handle, const double other);
void FArrayDouble_dividesequals_int(FArrayDoubleHandle handle, const int other);
FArrayDoubleHandle FArrayDouble_divides_farray(FArrayDoubleHandle handle, FArrayDoubleHandle other);
FArrayDoubleHandle FArrayDouble_divides_double(FArrayDoubleHandle handle, const double other);
FArrayDoubleHandle FArrayDouble_divides_int(FArrayDoubleHandle handle, const int other);
FArrayDoubleHandle FArrayDouble_pow(FArrayDoubleHandle handle, const double other);
FArrayDoubleHandle FArrayDouble_abs(FArrayDoubleHandle handle);
FArrayDoubleHandle FArrayDouble_min(FArrayDoubleHandle handle);
FArrayDoubleHandle FArrayDouble_min_arraywise(FArrayDoubleHandle handle, FArrayDoubleHandle other);
FArrayDoubleHandle FArrayDouble_max(FArrayDoubleHandle handle);
FArrayDoubleHandle FArrayDouble_max_arraywise(FArrayDoubleHandle handle, FArrayDoubleHandle other);
bool FArrayDouble_equality(FArrayDoubleHandle handle, FArrayDoubleHandle other);
bool FArrayDouble_notequality(FArrayDoubleHandle handle, FArrayDoubleHandle other);
bool FArrayDouble_greaterthan(FArrayDoubleHandle handle, const double value);
bool FArrayDouble_lessthan(FArrayDoubleHandle handle, const double value);
void FArrayDouble_remove_offset(FArrayDoubleHandle handle, const double offset);
double FArrayDouble_sum(FArrayDoubleHandle handle);
FArrayDoubleHandle FArrayDouble_reshape(FArrayDoubleHandle handle, const size_t* shape, size_t ndims);
ListListSizeTHandle FArrayDouble_where(FArrayDoubleHandle handle, const double value);
FArrayDoubleHandle FArrayDouble_flip(FArrayDoubleHandle handle, size_t axis);
size_t FArrayDouble_full_gradient(FArrayDoubleHandle handle, FArrayDoubleHandle* out_buffer, size_t buffer_size);
FArrayDoubleHandle FArrayDouble_gradient(FArrayDoubleHandle handle, size_t axis);
double FArrayDouble_get_sum_of_squares(FArrayDoubleHandle handle);
double FArrayDouble_get_summed_diff_int_of_squares(FArrayDoubleHandle handle, const int other);
double FArrayDouble_get_summed_diff_double_of_squares(FArrayDoubleHandle handle, const double other);
double FArrayDouble_get_summed_diff_array_of_squares(FArrayDoubleHandle handle, FArrayDoubleHandle other);
// Serialization (from Song)
StringHandle      FArrayDouble_to_json_string(FArrayDoubleHandle handle);
FArrayDoubleHandle FArrayDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif