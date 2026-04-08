#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/ListListSizeT_c_api.h"
#include "falcon-core/generic/FArrayDouble_c_api.h"
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* FArrayIntHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API FArrayIntHandle FArrayInt_create_empty(const size_t* shape, size_t ndim);
// @category:allocation
FALCON_CORE_C_API FArrayIntHandle FArrayInt_copy(FArrayIntHandle handle);
// @category:allocation
FALCON_CORE_C_API FArrayIntHandle FArrayInt_create_zeros(const size_t* shape, size_t ndim);
// @category:allocation
FALCON_CORE_C_API FArrayIntHandle FArrayInt_from_shape(const size_t* shape, size_t ndim);
// @category:allocation
FALCON_CORE_C_API FArrayIntHandle FArrayInt_from_data(const int* data, const size_t* shape, size_t ndim);
// @category:deallocation
FALCON_CORE_C_API void FArrayInt_destroy(FArrayIntHandle handle);
// @category:read
FALCON_CORE_C_API size_t FArrayInt_size(FArrayIntHandle handle);
// @category:read
FALCON_CORE_C_API size_t FArrayInt_dimension(FArrayIntHandle handle);
// @category:read
FALCON_CORE_C_API size_t FArrayInt_shape(FArrayIntHandle handle,size_t* out_buffer, size_t ndim);
// @category:read
FALCON_CORE_C_API size_t FArrayInt_data(FArrayIntHandle handle, int* out_buffer, size_t numdata);
// @category:write
FALCON_CORE_C_API void FArrayInt_plus_equals_farray(FArrayIntHandle handle, FArrayIntHandle other);
// @category:write
FALCON_CORE_C_API void FArrayInt_plus_equals_double(FArrayIntHandle handle, double other);
// @category:write
FALCON_CORE_C_API void FArrayInt_plus_equals_int(FArrayIntHandle handle, int other);
// @category:read
FALCON_CORE_C_API FArrayIntHandle FArrayInt_plus_farray(FArrayIntHandle handle, FArrayIntHandle other);
// @category:read
FALCON_CORE_C_API FArrayIntHandle FArrayInt_plus_double(FArrayIntHandle handle,  double other);
// @category:read
FALCON_CORE_C_API FArrayIntHandle FArrayInt_plus_int(FArrayIntHandle handle,  int other);
// @category:write
FALCON_CORE_C_API void FArrayInt_minus_equals_farray(FArrayIntHandle handle, FArrayIntHandle other);
// @category:write
FALCON_CORE_C_API void FArrayInt_minus_equals_double(FArrayIntHandle handle,  double other);
// @category:write
FALCON_CORE_C_API void FArrayInt_minus_equals_int(FArrayIntHandle handle,  int other);
// @category:read
FALCON_CORE_C_API FArrayIntHandle FArrayInt_minus_farray(FArrayIntHandle handle, FArrayIntHandle other);
// @category:read
FALCON_CORE_C_API  FArrayIntHandle FArrayInt_minus_double(FArrayIntHandle handle,  double other);
// @category:read
FALCON_CORE_C_API FArrayIntHandle FArrayInt_minus_int(FArrayIntHandle handle,  int other);
// @category:read
FALCON_CORE_C_API FArrayIntHandle FArrayInt_negation(FArrayIntHandle handle);
// @category:write
FALCON_CORE_C_API void FArrayInt_times_equals_farray(FArrayIntHandle handle, FArrayIntHandle other);
// @category:write
FALCON_CORE_C_API void FArrayInt_times_equals_double(FArrayIntHandle handle,  double other);
// @category:write
FALCON_CORE_C_API void FArrayInt_times_equals_int(FArrayIntHandle handle,  int other);
// @category:read
FALCON_CORE_C_API FArrayIntHandle FArrayInt_times_farray(FArrayIntHandle handle, FArrayIntHandle other);
// @category:read
FALCON_CORE_C_API FArrayIntHandle FArrayInt_times_double(FArrayIntHandle handle,  double other);
// @category:read
FALCON_CORE_C_API FArrayIntHandle FArrayInt_times_int(FArrayIntHandle handle,  int other);
// @category:write
FALCON_CORE_C_API void FArrayInt_divides_equals_farray(FArrayIntHandle handle, FArrayIntHandle other);
// @category:write
FALCON_CORE_C_API void FArrayInt_divides_equals_double(FArrayIntHandle handle,  double other);
// @category:write
FALCON_CORE_C_API void FArrayInt_divides_equals_int(FArrayIntHandle handle,  int other);
// @category:read
FALCON_CORE_C_API FArrayIntHandle FArrayInt_divides_farray(FArrayIntHandle handle, FArrayIntHandle other);
// @category:read
FALCON_CORE_C_API FArrayIntHandle FArrayInt_divides_double(FArrayIntHandle handle,  double other);
// @category:read
FALCON_CORE_C_API FArrayIntHandle FArrayInt_divides_int(FArrayIntHandle handle,  int other);
// @category:read
FALCON_CORE_C_API FArrayIntHandle FArrayInt_pow(FArrayIntHandle handle,  int other);
// @category:read
FALCON_CORE_C_API FArrayDoubleHandle FArrayInt_double_pow(FArrayIntHandle handle,  double other);
// @category:write
FALCON_CORE_C_API void FArrayInt_pow_inplace(FArrayIntHandle handle,  int other);
// @category:read
FALCON_CORE_C_API FArrayIntHandle FArrayInt_abs(FArrayIntHandle handle);
// @category:read
FALCON_CORE_C_API int FArrayInt_min(FArrayIntHandle handle);
// @category:read
FALCON_CORE_C_API FArrayIntHandle FArrayInt_min_arraywise(FArrayIntHandle handle, FArrayIntHandle other);
// @category:read
FALCON_CORE_C_API int FArrayInt_max(FArrayIntHandle handle);
// @category:read
FALCON_CORE_C_API FArrayIntHandle FArrayInt_max_arraywise(FArrayIntHandle handle, FArrayIntHandle other);
// @category:read
FALCON_CORE_C_API bool FArrayInt_equal(FArrayIntHandle handle, FArrayIntHandle other);
// @category:read
FALCON_CORE_C_API bool FArrayInt_not_equal(FArrayIntHandle handle, FArrayIntHandle other);
// @category:read
FALCON_CORE_C_API bool FArrayInt_greater_than(FArrayIntHandle handle,  int value);
// @category:read
FALCON_CORE_C_API bool FArrayInt_less_than(FArrayIntHandle handle,  int value);
// @category:write
FALCON_CORE_C_API void FArrayInt_remove_offset(FArrayIntHandle handle,  int offset);
// @category:read
FALCON_CORE_C_API int FArrayInt_sum(FArrayIntHandle handle);
// @category:read
FALCON_CORE_C_API FArrayIntHandle FArrayInt_reshape(FArrayIntHandle handle, const size_t* shape, size_t ndims);
// @category:read
FALCON_CORE_C_API ListListSizeTHandle FArrayInt_where(FArrayIntHandle handle,  int value);
// @category:read
FALCON_CORE_C_API FArrayIntHandle FArrayInt_flip(FArrayIntHandle handle, size_t axis);
// @category:read
FALCON_CORE_C_API size_t FArrayInt_full_gradient(FArrayIntHandle handle, FArrayIntHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API FArrayIntHandle FArrayInt_gradient(FArrayIntHandle handle, size_t axis);
// @category:read
FALCON_CORE_C_API double FArrayInt_get_sum_of_squares(FArrayIntHandle handle);
// @category:read
FALCON_CORE_C_API double FArrayInt_get_summed_diff_int_of_squares(FArrayIntHandle handle,  int other);
// @category:read
FALCON_CORE_C_API double FArrayInt_get_summed_diff_double_of_squares(FArrayIntHandle handle,  double other);
// @category:read
FALCON_CORE_C_API double FArrayInt_get_summed_diff_array_of_squares(FArrayIntHandle handle, FArrayIntHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      FArrayInt_to_json_string(FArrayIntHandle handle);
// @category:allocation
FALCON_CORE_C_API FArrayIntHandle FArrayInt_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif