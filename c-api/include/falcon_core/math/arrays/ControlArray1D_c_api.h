#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/ListFArrayDouble_c_api.h"
#include "falcon_core/generic/ListListSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ControlArray1DHandle;

// Constructors
ControlArray1DHandle ControlArray1D_from_data(const double* data,
                                              const size_t* shape,
                                              size_t        ndim);
ControlArray1DHandle ControlArray1D_from_farray(FArrayDoubleHandle farray);

// Destructor
void ControlArray1D_destroy(ControlArray1DHandle handle);

// Methods
bool               ControlArray1D_is_1D(ControlArray1DHandle handle);
FArrayDoubleHandle ControlArray1D_as_1D(ControlArray1DHandle handle);
double             ControlArray1D_get_start(ControlArray1DHandle handle);
double             ControlArray1D_get_end(ControlArray1DHandle handle);
bool               ControlArray1D_is_decreasing(ControlArray1DHandle handle);
bool               ControlArray1D_is_increasing(ControlArray1DHandle handle);
double             ControlArray1D_get_distance(ControlArray1DHandle handle);
double             ControlArray1D_get_mean(ControlArray1DHandle handle);
double             ControlArray1D_get_std(ControlArray1DHandle handle);
void               ControlArray1D_reverse(ControlArray1DHandle handle);
size_t             ControlArray1D_get_closest_index(ControlArray1DHandle handle,
                                                    double               value);
ListFArrayDoubleHandle ControlArray1D_even_divisions(
    ControlArray1DHandle handle, size_t divisions);
size_t ControlArray1D_size(ControlArray1DHandle handle);
size_t ControlArray1D_dimension(ControlArray1DHandle handle);
size_t ControlArray1D_shape(ControlArray1DHandle handle,
                            size_t*              out_buffer,
                            size_t               ndim);
size_t ControlArray1D_data(ControlArray1DHandle handle,
                           double*              out_buffer,
                           size_t               numdata);
void   ControlArray1D_plusequals_farray(ControlArray1DHandle handle,
                                        FArrayDoubleHandle   other);
void   ControlArray1D_plusequals_double(ControlArray1DHandle handle,
                                        const double         other);
void   ControlArray1D_plusequals_int(ControlArray1DHandle handle,
                                     const int            other);
ControlArray1DHandle ControlArray1D_plus_control_array(
    ControlArray1DHandle handle, ControlArray1DHandle other);
ControlArray1DHandle ControlArray1D_plus_farray(ControlArray1DHandle handle,
                                                FArrayDoubleHandle   other);
ControlArray1DHandle ControlArray1D_plus_double(ControlArray1DHandle handle,
                                                const double         other);
ControlArray1DHandle ControlArray1D_plus_int(ControlArray1DHandle handle,
                                             const int            other);
void ControlArray1D_minusequals_farray(ControlArray1DHandle handle,
                                       FArrayDoubleHandle   other);
void ControlArray1D_minusequals_double(ControlArray1DHandle handle,
                                       const double         other);
void ControlArray1D_minusequals_int(ControlArray1DHandle handle,
                                    const int            other);
ControlArray1DHandle ControlArray1D_minus_control_array(
    ControlArray1DHandle handle, ControlArray1DHandle other);
ControlArray1DHandle ControlArray1D_minus_farray(ControlArray1DHandle handle,
                                                 FArrayDoubleHandle   other);
ControlArray1DHandle ControlArray1D_minus_double(ControlArray1DHandle handle,
                                                 const double         other);
ControlArray1DHandle ControlArray1D_minus_int(ControlArray1DHandle handle,
                                              const int            other);
ControlArray1DHandle ControlArray1D_negation(ControlArray1DHandle handle);
void ControlArray1D_timesequals_double(ControlArray1DHandle handle,
                                       const double         other);
void ControlArray1D_timesequals_int(ControlArray1DHandle handle,
                                    const int            other);
ControlArray1DHandle ControlArray1D_times_double(ControlArray1DHandle handle,
                                                 const double         other);
ControlArray1DHandle ControlArray1D_times_int(ControlArray1DHandle handle,
                                              const int            other);
void ControlArray1D_dividesequals_double(ControlArray1DHandle handle,
                                         const double         other);
void ControlArray1D_dividesequals_int(ControlArray1DHandle handle,
                                      const int            other);
ControlArray1DHandle ControlArray1D_divides_double(ControlArray1DHandle handle,
                                                   const double         other);
ControlArray1DHandle ControlArray1D_divides_int(ControlArray1DHandle handle,
                                                const int            other);
ControlArray1DHandle ControlArray1D_pow(ControlArray1DHandle handle,
                                        const double         other);
ControlArray1DHandle ControlArray1D_abs(ControlArray1DHandle handle);
ControlArray1DHandle ControlArray1D_min_farray(ControlArray1DHandle handle,
                                               FArrayDoubleHandle   other);
ControlArray1DHandle ControlArray1D_min_control_array(
    ControlArray1DHandle handle, ControlArray1DHandle other);
ControlArray1DHandle ControlArray1D_max_farray(ControlArray1DHandle handle,
                                               FArrayDoubleHandle   other);
ControlArray1DHandle ControlArray1D_max_control_array(
    ControlArray1DHandle handle, ControlArray1DHandle other);
bool   ControlArray1D_equality(ControlArray1DHandle handle,
                               ControlArray1DHandle other);
bool   ControlArray1D_notequality(ControlArray1DHandle handle,
                                  ControlArray1DHandle other);
bool   ControlArray1D_greaterthan(ControlArray1DHandle handle,
                                  const double         value);
bool   ControlArray1D_lessthan(ControlArray1DHandle handle, const double value);
void   ControlArray1D_remove_offset(ControlArray1DHandle handle,
                                    const double         offset);
double ControlArray1D_sum(ControlArray1DHandle handle);
ListListSizeTHandle  ControlArray1D_where(ControlArray1DHandle handle,
                                          const double         value);
/* AUTO-DOC from cpp: ControlArray1D_flip | falcon_core::math::arrays::ControlArray1D::flip */
/**
 * @brief Flip the data along the given axis.
 * @param axis The axis to flip.
 * @return A flipped ControlArray1D1D.
 */
ControlArray1DHandle ControlArray1D_flip(ControlArray1DHandle handle,
                                         size_t               axis);
size_t               ControlArray1D_full_gradient(ControlArray1DHandle handle,
                                                  FArrayDoubleHandle*  out_buffer,
                                                  size_t               buffer_size);
/* AUTO-DOC from cpp: ControlArray1D_gradient | falcon_core::math::arrays::ControlArray1D::gradient */
/**
 * @brief Return the gradient of the data along a given axis.
 * Computes the gradient along the specified axis using finite differences:
 * - For interior points, uses central difference: (f(x+1) - f(x-1)) / 2
 * - For boundary points, uses forward (first element) or backward (last
 * element) difference.
 * @param axis The axis to compute the gradient.
 * @return The gradient FArray.
 */
FArrayDoubleHandle   ControlArray1D_gradient(ControlArray1DHandle handle,
                                             size_t               axis);
double ControlArray1D_get_sum_of_squares(ControlArray1DHandle handle);
double ControlArray1D_get_summed_diff_int_of_squares(
    ControlArray1DHandle handle, const int other);
double ControlArray1D_get_summed_diff_double_of_squares(
    ControlArray1DHandle handle, const double other);
double ControlArray1D_get_summed_diff_array_of_squares(
    ControlArray1DHandle handle, ControlArray1DHandle other);

// Serialization (from Song)
StringHandle         ControlArray1D_to_json_string(ControlArray1DHandle handle);
ControlArray1DHandle ControlArray1D_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
