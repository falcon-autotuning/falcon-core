#pragma once
#include "falcon_core/generic/FArrayDouble_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif
#include <cstddef>

#include "falcon_core/generic/ListFArrayDouble_c_api.h"
#include "falcon_core/generic/ListListSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MeasuredArray1DHandle;

// Constructors
MeasuredArray1DHandle MeasuredArray1D_from_shape(const size_t* shape,
                                                 size_t        ndim);
MeasuredArray1DHandle MeasuredArray1D_from_data(const double* data,
                                                const size_t* shape,
                                                size_t        ndim);
MeasuredArray1DHandle MeasuredArray1D_from_farray(FArrayDoubleHandle farray);

// Destructor
void MeasuredArray1D_destroy(MeasuredArray1DHandle handle);

// Methods
bool               MeasuredArray1D_is_1D(MeasuredArray1DHandle handle);
FArrayDoubleHandle MeasuredArray1D_as_1D(MeasuredArray1DHandle handle);
double             MeasuredArray1D_get_start(MeasuredArray1DHandle handle);
double             MeasuredArray1D_get_end(MeasuredArray1DHandle handle);
bool               MeasuredArray1D_is_decreasing(MeasuredArray1DHandle handle);
bool               MeasuredArray1D_is_decreasing(MeasuredArray1DHandle handle);
double             MeasuredArray1D_get_distance(MeasuredArray1DHandle handle);
double             MeasuredArray1D_get_mean(MeasuredArray1DHandle handle);
double             MeasuredArray1D_get_std(MeasuredArray1DHandle handle);
void               MeasuredArray1D_reverse(MeasuredArray1DHandle handle);
size_t MeasuredArray1D_get_closest_index(MeasuredArray1DHandle handle,
                                         double                value);
ListFArrayDoubleHandle MeasuredArray1D_even_divisions(
    MeasuredArray1DHandle handle, size_t divisions);
size_t MeasuredArray1D_size(MeasuredArray1DHandle handle);
size_t MeasuredArray1D_dimension(MeasuredArray1DHandle handle);
size_t MeasuredArray1D_shape(MeasuredArray1DHandle handle,
                             size_t*               out_buffer,
                             size_t                ndim);
size_t MeasuredArray1D_data(MeasuredArray1DHandle handle,
                            double*               out_buffer,
                            size_t                numdata);
void   MeasuredArray1D_plusequals_farray(MeasuredArray1DHandle handle,
                                         FArrayDoubleHandle    other);
void   MeasuredArray1D_plusequals_double(MeasuredArray1DHandle handle,
                                         const double          other);
void   MeasuredArray1D_plusequals_int(MeasuredArray1DHandle handle,
                                      const int             other);
MeasuredArray1DHandle MeasuredArray1D_plus_control_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other);
MeasuredArray1DHandle MeasuredArray1D_plus_farray(MeasuredArray1DHandle handle,
                                                  FArrayDoubleHandle    other);
MeasuredArray1DHandle MeasuredArray1D_plus_double(MeasuredArray1DHandle handle,
                                                  const double          other);
MeasuredArray1DHandle MeasuredArray1D_plus_int(MeasuredArray1DHandle handle,
                                               const int             other);
void MeasuredArray1D_minusequals_control_array(MeasuredArray1DHandle handle,
                                               MeasuredArray1DHandle other);
void MeasuredArray1D_minusequals_farray(MeasuredArray1DHandle handle,
                                        FArrayDoubleHandle    other);
void MeasuredArray1D_minusequals_double(MeasuredArray1DHandle handle,
                                        const double          other);
void MeasuredArray1D_minusequals_int(MeasuredArray1DHandle handle,
                                     const int             other);
MeasuredArray1DHandle MeasuredArray1D_minus_control_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other);
MeasuredArray1DHandle MeasuredArray1D_minus_farray(MeasuredArray1DHandle handle,
                                                   FArrayDoubleHandle    other);
MeasuredArray1DHandle MeasuredArray1D_minus_double(MeasuredArray1DHandle handle,
                                                   const double          other);
MeasuredArray1DHandle MeasuredArray1D_minus_int(MeasuredArray1DHandle handle,
                                                const int             other);
MeasuredArray1DHandle MeasuredArray1D_negation(MeasuredArray1DHandle handle);
MeasuredArray1DHandle MeasuredArray1D_timesequals_measured_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other);
MeasuredArray1DHandle MeasuredArray1D_timesequals_farray(
    MeasuredArray1DHandle handle, FArrayDoubleHandle other);
void MeasuredArray1D_timesequals_double(MeasuredArray1DHandle handle,
                                        const double          other);
void MeasuredArray1D_timesequals_int(MeasuredArray1DHandle handle,
                                     const int             other);
MeasuredArray1DHandle MeasuredArray1D_times_measured_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other);
MeasuredArray1DHandle MeasuredArray1D_times_farray(MeasuredArray1DHandle handle,
                                                   FArrayDoubleHandle    other);
MeasuredArray1DHandle MeasuredArray1D_times_double(MeasuredArray1DHandle handle,
                                                   const double          other);
MeasuredArray1DHandle MeasuredArray1D_times_int(MeasuredArray1DHandle handle,
                                                const int             other);
MeasuredArray1DHandle MeasuredArray1D_dividesequals_measured_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other);
MeasuredArray1DHandle MeasuredArray1D_dividesequals_farray(
    MeasuredArray1DHandle handle, FArrayDoubleHandle other);
void MeasuredArray1D_dividesequals_double(MeasuredArray1DHandle handle,
                                          const double          other);
void MeasuredArray1D_dividesequals_int(MeasuredArray1DHandle handle,
                                       const int             other);
MeasuredArray1DHandle MeasuredArray1D_divides_measured_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other);
MeasuredArray1DHandle MeasuredArray1D_divides_farray(
    MeasuredArray1DHandle handle, FArrayDoubleHandle other);
MeasuredArray1DHandle MeasuredArray1D_divides_double(
    MeasuredArray1DHandle handle, const double other);
MeasuredArray1DHandle MeasuredArray1D_divides_int(MeasuredArray1DHandle handle,
                                                  const int             other);
MeasuredArray1DHandle MeasuredArray1D_pow(MeasuredArray1DHandle handle,
                                          const double          other);
MeasuredArray1DHandle MeasuredArray1D_abs(MeasuredArray1DHandle handle);
MeasuredArray1DHandle MeasuredArray1D_min(MeasuredArray1DHandle handle);
MeasuredArray1DHandle MeasuredArray1D_min_farray(MeasuredArray1DHandle handle,
                                                 FArrayDoubleHandle    other);
MeasuredArray1DHandle MeasuredArray1D_min_control_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other);
MeasuredArray1DHandle MeasuredArray1D_max(MeasuredArray1DHandle handle);
MeasuredArray1DHandle MeasuredArray1D_max_farray(MeasuredArray1DHandle handle,
                                                 FArrayDoubleHandle    other);
MeasuredArray1DHandle MeasuredArray1D_max_control_array(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other);
bool MeasuredArray1D_equality(MeasuredArray1DHandle handle,
                              MeasuredArray1DHandle other);
bool MeasuredArray1D_notequality(MeasuredArray1DHandle handle,
                                 MeasuredArray1DHandle other);
bool MeasuredArray1D_greaterthan(MeasuredArray1DHandle handle,
                                 const double          value);
bool MeasuredArray1D_lessthan(MeasuredArray1DHandle handle, const double value);
void MeasuredArray1D_remove_offset(MeasuredArray1DHandle handle,
                                   const double          offset);
double                MeasuredArray1D_sum(MeasuredArray1DHandle handle);
MeasuredArray1DHandle MeasuredArray1D_reshape(MeasuredArray1DHandle handle,
                                              const size_t*         shape,
                                              size_t                ndims);
ListListSizeTHandle   MeasuredArray1D_where(MeasuredArray1DHandle handle,
                                            const double          value);
MeasuredArray1DHandle MeasuredArray1D_flip(MeasuredArray1DHandle handle,
                                           size_t                axis);
size_t MeasuredArray1D_full_gradient(MeasuredArray1DHandle  handle,
                                     MeasuredArray1DHandle* out_buffer,
                                     size_t                 buffer_size);
MeasuredArray1DHandle MeasuredArray1D_gradient(MeasuredArray1DHandle handle,
                                               size_t                axis);
double MeasuredArray1D_get_sum_of_squares(MeasuredArray1DHandle handle);
double MeasuredArray1D_get_summed_diff_int_of_squares(
    MeasuredArray1DHandle handle, const int other);
double MeasuredArray1D_get_summed_diff_double_of_squares(
    MeasuredArray1DHandle handle, const double other);
double MeasuredArray1D_get_summed_diff_array_of_squares(
    MeasuredArray1DHandle handle, MeasuredArray1DHandle other);

// Serialization (from Song)
StringHandle MeasuredArray1D_to_json_string(MeasuredArray1DHandle handle);
MeasuredArray1DHandle MeasuredArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
