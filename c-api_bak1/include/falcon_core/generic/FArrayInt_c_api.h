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

FArrayIntHandle FArrayInt_create_empty(const size_t* shape, size_t ndim);
FArrayIntHandle FArrayInt_create_zeros(const size_t* shape, size_t ndim);
FArrayIntHandle FArrayInt_from_shape(const size_t* shape, size_t ndim);
FArrayIntHandle FArrayInt_from_data(const int* data, const size_t* shape, size_t ndim);
void FArrayInt_destroy(FArrayIntHandle handle);
size_t FArrayInt_size(FArrayIntHandle handle);
size_t FArrayInt_dimension(FArrayIntHandle handle);
size_t FArrayInt_shape(FArrayIntHandle handle, size_t* out_buffer, size_t ndim);
size_t FArrayInt_data(FArrayIntHandle handle, int* out_buffer, size_t numdata);
void FArrayInt_plusequals_farray(FArrayIntHandle handle, FArrayIntHandle other);
void FArrayInt_plusequals_double(FArrayIntHandle handle, const double other);
void FArrayInt_plusequals_int(FArrayIntHandle handle, const int other);
FArrayIntHandle FArrayInt_plus_farray(FArrayIntHandle handle, FArrayIntHandle other);
FArrayIntHandle FArrayInt_plus_double(FArrayIntHandle handle, const double other);
FArrayIntHandle FArrayInt_plus_int(FArrayIntHandle handle, const int other);
void FArrayInt_minusequals_farray(FArrayIntHandle handle, FArrayIntHandle other);
void FArrayInt_minusequals_double(FArrayIntHandle handle, const double other);
void FArrayInt_minusequals_int(FArrayIntHandle handle, const int other);
FArrayIntHandle FArrayInt_minus_farray(FArrayIntHandle handle, FArrayIntHandle other);
FArrayIntHandle FArrayInt_minus_double(FArrayIntHandle handle, const double other);
FArrayIntHandle FArrayInt_minus_int(FArrayIntHandle handle, const int other);
FArrayIntHandle FArrayInt_negation(FArrayIntHandle handle);
void FArrayInt_timesequals_farray(FArrayIntHandle handle, FArrayIntHandle other);
void FArrayInt_timesequals_double(FArrayIntHandle handle, const double other);
void FArrayInt_timesequals_int(FArrayIntHandle handle, const int other);
FArrayIntHandle FArrayInt_times_farray(FArrayIntHandle handle, FArrayIntHandle other);
FArrayIntHandle FArrayInt_times_double(FArrayIntHandle handle, const double other);
FArrayIntHandle FArrayInt_times_int(FArrayIntHandle handle, const int other);
void FArrayInt_dividesequals_farray(FArrayIntHandle handle, FArrayIntHandle other);
void FArrayInt_dividesequals_double(FArrayIntHandle handle, const double other);
void FArrayInt_dividesequals_int(FArrayIntHandle handle, const int other);
FArrayIntHandle FArrayInt_divides_farray(FArrayIntHandle handle, FArrayIntHandle other);
FArrayIntHandle FArrayInt_divides_double(FArrayIntHandle handle, const double other);
FArrayIntHandle FArrayInt_divides_int(FArrayIntHandle handle, const int other);
FArrayIntHandle FArrayInt_pow(FArrayIntHandle handle, const int other);
FArrayDoubleHandle FArrayInt_double_pow(FArrayIntHandle handle, const double other);
void FArrayInt_pow_inplace(FArrayIntHandle handle, const int other);
FArrayIntHandle FArrayInt_abs(FArrayIntHandle handle);
int FArrayInt_min(FArrayIntHandle handle);
FArrayIntHandle FArrayInt_min_arraywise(FArrayIntHandle handle, FArrayIntHandle other);
int FArrayInt_max(FArrayIntHandle handle);
FArrayIntHandle FArrayInt_max_arraywise(FArrayIntHandle handle, FArrayIntHandle other);
bool FArrayInt_equality(FArrayIntHandle handle, FArrayIntHandle other);
bool FArrayInt_notequality(FArrayIntHandle handle, FArrayIntHandle other);
bool FArrayInt_greaterthan(FArrayIntHandle handle, const int value);
bool FArrayInt_lessthan(FArrayIntHandle handle, const int value);
void FArrayInt_remove_offset(FArrayIntHandle handle, const int offset);
int FArrayInt_sum(FArrayIntHandle handle);
/* AUTO-DOC from cpp: FArrayInt_reshape | falcon_core::generic::FArray::reshape */
/**
 * @brief (from C++: falcon_core::generic::FArray::reshape)
 * @brief Return a new Array with the given shape.
 * @param shape The new shape.
 * @return A reshaped FArray.
 */
FArrayIntHandle FArrayInt_reshape(FArrayIntHandle handle, const size_t* shape, size_t ndims);
ListListSizeTHandle FArrayInt_where(FArrayIntHandle handle, const int value);
/* AUTO-DOC from cpp: FArrayInt_flip | falcon_core::generic::FArray::flip */
/**
 * @brief (from C++: falcon_core::generic::FArray::flip)
 * @brief Flip the data along the given axis.
 * @param axis The axis to flip.
 * @return A flipped FArray.
 */
FArrayIntHandle FArrayInt_flip(FArrayIntHandle handle, size_t axis);
size_t FArrayInt_full_gradient(FArrayIntHandle handle, FArrayIntHandle* out_buffer, size_t buffer_size);
/* AUTO-DOC from cpp: FArrayInt_gradient | falcon_core::generic::FArray::gradient */
/**
 * @brief (from C++: falcon_core::generic::FArray::gradient)
 * @brief Return the gradient of the data along all axes.
 * Computes the gradient for each axis of the array using finite differences:
 * - For interior points, uses central difference: (f(x+1) - f(x-1)) / 2
 * - For boundary points, uses forward (first element) or backward (last
 * element) difference.
 * @return A vector of FArray gradients (one for each axis).
 */
FArrayIntHandle FArrayInt_gradient(FArrayIntHandle handle, size_t axis);
double FArrayInt_get_sum_of_squares(FArrayIntHandle handle);
double FArrayInt_get_summed_diff_int_of_squares(FArrayIntHandle handle, const int other);
double FArrayInt_get_summed_diff_double_of_squares(FArrayIntHandle handle, const double other);
double FArrayInt_get_summed_diff_array_of_squares(FArrayIntHandle handle, FArrayIntHandle other);
// Serialization (from Song)
/* AUTO-DOC from cpp: FArrayInt_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      FArrayInt_to_json_string(FArrayIntHandle handle);
/* AUTO-DOC from cpp: FArrayInt_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
FArrayIntHandle FArrayInt_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif