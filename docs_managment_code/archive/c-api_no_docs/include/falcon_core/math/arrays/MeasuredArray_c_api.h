#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/ListListSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MeasuredArrayHandle;
// Function declarations

MeasuredArrayHandle MeasuredArray_from_data(const double* data,
                                            const size_t* shape,
                                            size_t        ndim);
MeasuredArrayHandle MeasuredArray_from_farray(FArrayDoubleHandle farray);
void                MeasuredArray_destroy(MeasuredArrayHandle handle);
size_t              MeasuredArray_size(MeasuredArrayHandle handle);
size_t              MeasuredArray_dimension(MeasuredArrayHandle handle);
size_t              MeasuredArray_shape(MeasuredArrayHandle handle,
                                        size_t*             out_buffer,
                                        size_t              ndim);
size_t              MeasuredArray_data(MeasuredArrayHandle handle,
                                       double*             out_buffer,
                                       size_t              numdata);
void                MeasuredArray_plusequals_farray(MeasuredArrayHandle handle,
                                                    FArrayDoubleHandle  other);
void                MeasuredArray_plusequals_double(MeasuredArrayHandle handle,
                                                    const double        other);
void MeasuredArray_plusequals_int(MeasuredArrayHandle handle, const int other);
MeasuredArrayHandle MeasuredArray_plus_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other);
MeasuredArrayHandle MeasuredArray_plus_farray(MeasuredArrayHandle handle,
                                              FArrayDoubleHandle  other);
MeasuredArrayHandle MeasuredArray_plus_double(MeasuredArrayHandle handle,
                                              const double        other);
MeasuredArrayHandle MeasuredArray_plus_int(MeasuredArrayHandle handle,
                                           const int           other);
void                MeasuredArray_minusequals_farray(MeasuredArrayHandle handle,
                                                     FArrayDoubleHandle  other);
void                MeasuredArray_minusequals_double(MeasuredArrayHandle handle,
                                                     const double        other);
void MeasuredArray_minusequals_int(MeasuredArrayHandle handle, const int other);
MeasuredArrayHandle MeasuredArray_minus_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other);
MeasuredArrayHandle MeasuredArray_minus_farray(MeasuredArrayHandle handle,
                                               FArrayDoubleHandle  other);
MeasuredArrayHandle MeasuredArray_minus_double(MeasuredArrayHandle handle,
                                               const double        other);
MeasuredArrayHandle MeasuredArray_minus_int(MeasuredArrayHandle handle,
                                            const int           other);
MeasuredArrayHandle MeasuredArray_negation(MeasuredArrayHandle handle);
MeasuredArrayHandle MeasuredArray_timesequals_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other);
MeasuredArrayHandle MeasuredArray_timesequals_farray(MeasuredArrayHandle handle,
                                                     FArrayDoubleHandle  other);
void                MeasuredArray_timesequals_double(MeasuredArrayHandle handle,
                                                     const double        other);
void MeasuredArray_timesequals_int(MeasuredArrayHandle handle, const int other);
MeasuredArrayHandle MeasuredArray_times_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other);
MeasuredArrayHandle MeasuredArray_times_farray(MeasuredArrayHandle handle,
                                               FArrayDoubleHandle  other);
MeasuredArrayHandle MeasuredArray_times_double(MeasuredArrayHandle handle,
                                               const double        other);
MeasuredArrayHandle MeasuredArray_times_int(MeasuredArrayHandle handle,
                                            const int           other);
MeasuredArrayHandle MeasuredArray_dividesequals_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other);
MeasuredArrayHandle MeasuredArray_dividesequals_farray(
    MeasuredArrayHandle handle, FArrayDoubleHandle other);
void MeasuredArray_dividesequals_double(MeasuredArrayHandle handle,
                                        const double        other);
void MeasuredArray_dividesequals_int(MeasuredArrayHandle handle,
                                     const int           other);
MeasuredArrayHandle MeasuredArray_divides_measured_array(
    MeasuredArrayHandle handle, MeasuredArrayHandle other);
MeasuredArrayHandle MeasuredArray_divides_farray(MeasuredArrayHandle handle,
                                                 FArrayDoubleHandle  other);
MeasuredArrayHandle MeasuredArray_divides_double(MeasuredArrayHandle handle,
                                                 const double        other);
MeasuredArrayHandle MeasuredArray_divides_int(MeasuredArrayHandle handle,
                                              const int           other);
MeasuredArrayHandle MeasuredArray_pow(MeasuredArrayHandle handle,
                                      const double        other);
MeasuredArrayHandle MeasuredArray_abs(MeasuredArrayHandle handle);
MeasuredArrayHandle MeasuredArray_min_farray(MeasuredArrayHandle handle,
                                             FArrayDoubleHandle  other);
MeasuredArrayHandle MeasuredArray_min_measured_array(MeasuredArrayHandle handle,
                                                     MeasuredArrayHandle other);
MeasuredArrayHandle MeasuredArray_max_farray(MeasuredArrayHandle handle,
                                             FArrayDoubleHandle  other);
MeasuredArrayHandle MeasuredArray_max_measured_array(MeasuredArrayHandle handle,
                                                     MeasuredArrayHandle other);
bool                MeasuredArray_equality(MeasuredArrayHandle handle,
                                           MeasuredArrayHandle other);
bool                MeasuredArray_notequality(MeasuredArrayHandle handle,
                                              MeasuredArrayHandle other);
bool MeasuredArray_greaterthan(MeasuredArrayHandle handle, const double value);
bool MeasuredArray_lessthan(MeasuredArrayHandle handle, const double value);
void MeasuredArray_remove_offset(MeasuredArrayHandle handle,
                                 const double        offset);
double              MeasuredArray_sum(MeasuredArrayHandle handle);
MeasuredArrayHandle MeasuredArray_reshape(MeasuredArrayHandle handle,
                                          const size_t*       shape,
                                          size_t              ndims);
ListListSizeTHandle MeasuredArray_where(MeasuredArrayHandle handle,
                                        const double        value);
MeasuredArrayHandle MeasuredArray_flip(MeasuredArrayHandle handle, size_t axis);
size_t              MeasuredArray_full_gradient(MeasuredArrayHandle  handle,
                                                MeasuredArrayHandle* out_buffer,
                                                size_t               buffer_size);
MeasuredArrayHandle MeasuredArray_gradient(MeasuredArrayHandle handle,
                                           size_t              axis);
double MeasuredArray_get_sum_of_squares(MeasuredArrayHandle handle);
double MeasuredArray_get_summed_diff_int_of_squares(MeasuredArrayHandle handle,
                                                    const int           other);
double MeasuredArray_get_summed_diff_double_of_squares(
    MeasuredArrayHandle handle, const double other);
double MeasuredArray_get_summed_diff_array_of_squares(
    MeasuredArrayHandle handle, MeasuredArrayHandle other);
// Serialization (from Song)
StringHandle        MeasuredArray_to_json_string(MeasuredArrayHandle handle);
MeasuredArrayHandle MeasuredArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
