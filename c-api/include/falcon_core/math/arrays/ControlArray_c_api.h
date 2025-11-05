#pragma once
#include "falcon_core/generic/FArrayDouble_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif
#include <cstddef>

#include "falcon_core/generic/ListListSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ControlArrayHandle;
// Function declarations

ControlArrayHandle ControlArray_from_data(const double* data,
                                          const size_t* shape,
                                          size_t        ndim);
ControlArrayHandle ControlArray_from_farray(FArrayDoubleHandle farray);
void               ControlArray_destroy(ControlArrayHandle handle);
size_t             ControlArray_size(ControlArrayHandle handle);
size_t             ControlArray_dimension(ControlArrayHandle handle);
size_t             ControlArray_shape(ControlArrayHandle handle,
                                      size_t*            out_buffer,
                                      size_t             ndim);
size_t             ControlArray_data(ControlArrayHandle handle,
                                     double*            out_buffer,
                                     size_t             numdata);
void               ControlArray_plusequals_farray(ControlArrayHandle handle,
                                                  FArrayDoubleHandle other);
void               ControlArray_plusequals_double(ControlArrayHandle handle,
                                                  const double       other);
void ControlArray_plusequals_int(ControlArrayHandle handle, const int other);
ControlArrayHandle ControlArray_plus_control_array(ControlArrayHandle handle,
                                                   ControlArrayHandle other);
ControlArrayHandle ControlArray_plus_farray(ControlArrayHandle handle,
                                            FArrayDoubleHandle other);
ControlArrayHandle ControlArray_plus_double(ControlArrayHandle handle,
                                            const double       other);
ControlArrayHandle ControlArray_plus_int(ControlArrayHandle handle,
                                         const int          other);
void               ControlArray_minusequals_farray(ControlArrayHandle handle,
                                                   FArrayDoubleHandle other);
void               ControlArray_minusequals_double(ControlArrayHandle handle,
                                                   const double       other);
void ControlArray_minusequals_int(ControlArrayHandle handle, const int other);
ControlArrayHandle ControlArray_minus_control_array(ControlArrayHandle handle,
                                                    ControlArrayHandle other);
ControlArrayHandle ControlArray_minus_farray(ControlArrayHandle handle,
                                             FArrayDoubleHandle other);
ControlArrayHandle ControlArray_minus_double(ControlArrayHandle handle,
                                             const double       other);
ControlArrayHandle ControlArray_minus_int(ControlArrayHandle handle,
                                          const int          other);
ControlArrayHandle ControlArray_negation(ControlArrayHandle handle);
void               ControlArray_timesequals_double(ControlArrayHandle handle,
                                                   const double       other);
void ControlArray_timesequals_int(ControlArrayHandle handle, const int other);
ControlArrayHandle ControlArray_times_double(ControlArrayHandle handle,
                                             const double       other);
ControlArrayHandle ControlArray_times_int(ControlArrayHandle handle,
                                          const int          other);
void               ControlArray_dividesequals_double(ControlArrayHandle handle,
                                                     const double       other);
void ControlArray_dividesequals_int(ControlArrayHandle handle, const int other);
ControlArrayHandle ControlArray_divides_double(ControlArrayHandle handle,
                                               const double       other);
ControlArrayHandle ControlArray_divides_int(ControlArrayHandle handle,
                                            const int          other);
ControlArrayHandle ControlArray_pow(ControlArrayHandle handle,
                                    const double       other);
ControlArrayHandle ControlArray_abs(ControlArrayHandle handle);
ControlArrayHandle ControlArray_min_farray(ControlArrayHandle handle,
                                           FArrayDoubleHandle other);
ControlArrayHandle ControlArray_min_control_array(ControlArrayHandle handle,
                                                  ControlArrayHandle other);
ControlArrayHandle ControlArray_max_farray(ControlArrayHandle handle,
                                           FArrayDoubleHandle other);
ControlArrayHandle ControlArray_max_control_array(ControlArrayHandle handle,
                                                  ControlArrayHandle other);
bool ControlArray_equality(ControlArrayHandle handle, ControlArrayHandle other);
bool ControlArray_notequality(ControlArrayHandle handle,
                              ControlArrayHandle other);
bool ControlArray_greaterthan(ControlArrayHandle handle, const double value);
bool ControlArray_lessthan(ControlArrayHandle handle, const double value);
void ControlArray_remove_offset(ControlArrayHandle handle, const double offset);
double              ControlArray_sum(ControlArrayHandle handle);
ListListSizeTHandle ControlArray_where(ControlArrayHandle handle,
                                       const double       value);
ControlArrayHandle  ControlArray_flip(ControlArrayHandle handle, size_t axis);
size_t              ControlArray_full_gradient(ControlArrayHandle  handle,
                                               FArrayDoubleHandle* out_buffer,
                                               size_t              buffer_size);
FArrayDoubleHandle  ControlArray_gradient(ControlArrayHandle handle,
                                          size_t             axis);
double              ControlArray_get_sum_of_squares(ControlArrayHandle handle);
double ControlArray_get_summed_diff_int_of_squares(ControlArrayHandle handle,
                                                   const int          other);
double ControlArray_get_summed_diff_double_of_squares(ControlArrayHandle handle,
                                                      const double       other);
double ControlArray_get_summed_diff_array_of_squares(ControlArrayHandle handle,
                                                     ControlArrayHandle other);
// Serialization (from Song)
StringHandle       ControlArray_to_json_string(ControlArrayHandle handle);
ControlArrayHandle ControlArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
