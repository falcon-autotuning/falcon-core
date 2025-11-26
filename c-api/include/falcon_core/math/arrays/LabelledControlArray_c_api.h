#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/ListListSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/arrays/ControlArray_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
typedef void* LabelledControlArrayHandle;

// @category:allocation
LabelledControlArrayHandle LabelledControlArray_from_farray(
    FArrayDoubleHandle farray, AcquisitionContextHandle label);
// @category:allocation
LabelledControlArrayHandle LabelledControlArray_from_control_array(
    ControlArrayHandle controlarray, AcquisitionContextHandle label);
// @category:deallocation
void LabelledControlArray_destroy(LabelledControlArrayHandle handle);
// @category:read
AcquisitionContextHandle LabelledControlArray_label(
    LabelledControlArrayHandle handle);
// @category:read
ConnectionHandle LabelledControlArray_connection(
    LabelledControlArrayHandle handle);
// @category:read
StringHandle LabelledControlArray_instrument_type(
    LabelledControlArrayHandle handle);
// @category:read
SymbolUnitHandle LabelledControlArray_units(LabelledControlArrayHandle handle);
// @category:read
size_t LabelledControlArray_size(LabelledControlArrayHandle handle);
// @category:read
size_t LabelledControlArray_dimension(LabelledControlArrayHandle handle);
// @category:read
size_t LabelledControlArray_shape(LabelledControlArrayHandle handle,
                                  size_t*                    out_buffer,
                                  size_t                     ndim);
// @category:read
size_t LabelledControlArray_data(LabelledControlArrayHandle handle,
                                 double*                    out_buffer,
                                 size_t                     numdata);
// @category:write
void LabelledControlArray_plus_equals_farray(LabelledControlArrayHandle handle,
                                            FArrayDoubleHandle         other);
// @category:write
void LabelledControlArray_plus_equals_double(LabelledControlArrayHandle handle,
                                            double                     other);
// @category:write
void LabelledControlArray_plus_equals_int(LabelledControlArrayHandle handle,
                                         int                        other);
// @category:read
LabelledControlArrayHandle LabelledControlArray_plus_control_array(
    LabelledControlArrayHandle handle, LabelledControlArrayHandle other);
// @category:read
LabelledControlArrayHandle LabelledControlArray_plus_farray(
    LabelledControlArrayHandle handle, FArrayDoubleHandle other);
// @category:read
LabelledControlArrayHandle LabelledControlArray_plus_double(
    LabelledControlArrayHandle handle, double other);
// @category:read
LabelledControlArrayHandle LabelledControlArray_plus_int(
    LabelledControlArrayHandle handle, int other);
// @category:write
void LabelledControlArray_minus_equals_control_array(
    LabelledControlArrayHandle handle, LabelledControlArrayHandle other);
// @category:write
void LabelledControlArray_minus_equals_farray(LabelledControlArrayHandle handle,
                                             FArrayDoubleHandle         other);
// @category:write
void LabelledControlArray_minus_equals_double(LabelledControlArrayHandle handle,
                                             double                     other);
// @category:write
void LabelledControlArray_minus_equals_int(LabelledControlArrayHandle handle,
                                          int                        other);
// @category:read
LabelledControlArrayHandle LabelledControlArray_minus_control_array(
    LabelledControlArrayHandle handle, LabelledControlArrayHandle other);
// @category:read
LabelledControlArrayHandle LabelledControlArray_minus_farray(
    LabelledControlArrayHandle handle, FArrayDoubleHandle other);
// @category:read
LabelledControlArrayHandle LabelledControlArray_minus_double(
    LabelledControlArrayHandle handle, double other);
// @category:read
LabelledControlArrayHandle LabelledControlArray_minus_int(
    LabelledControlArrayHandle handle, int other);
// @category:read
LabelledControlArrayHandle LabelledControlArray_negation(
    LabelledControlArrayHandle handle);
// @category:write
void LabelledControlArray_times_equals_double(LabelledControlArrayHandle handle,
                                             double                     other);
// @category:write
void LabelledControlArray_times_equals_int(LabelledControlArrayHandle handle,
                                          int                        other);
// @category:read
LabelledControlArrayHandle LabelledControlArray_times_double(
    LabelledControlArrayHandle handle, double other);
// @category:read
LabelledControlArrayHandle LabelledControlArray_times_int(
    LabelledControlArrayHandle handle, int other);
// @category:write
void LabelledControlArray_divides_equals_double(
    LabelledControlArrayHandle handle, double other);
// @category:write
void LabelledControlArray_divides_equals_int(LabelledControlArrayHandle handle,
                                            int                        other);
// @category:read
LabelledControlArrayHandle LabelledControlArray_divides_double(
    LabelledControlArrayHandle handle, double other);
// @category:read
LabelledControlArrayHandle LabelledControlArray_divides_int(
    LabelledControlArrayHandle handle, int other);
// @category:read
LabelledControlArrayHandle LabelledControlArray_pow(
    LabelledControlArrayHandle handle, double other);
// @category:read
LabelledControlArrayHandle LabelledControlArray_abs(
    LabelledControlArrayHandle handle);
// @category:read
LabelledControlArrayHandle LabelledControlArray_min(
    LabelledControlArrayHandle handle);
// @category:read
LabelledControlArrayHandle LabelledControlArray_min_farray(
    LabelledControlArrayHandle handle, FArrayDoubleHandle other);
// @category:read
LabelledControlArrayHandle LabelledControlArray_min_control_array(
    LabelledControlArrayHandle handle, LabelledControlArrayHandle other);
// @category:read
LabelledControlArrayHandle LabelledControlArray_max(
    LabelledControlArrayHandle handle);
// @category:read
LabelledControlArrayHandle LabelledControlArray_max_farray(
    LabelledControlArrayHandle handle, FArrayDoubleHandle other);
// @category:read
LabelledControlArrayHandle LabelledControlArray_max_control_array(
    LabelledControlArrayHandle handle, LabelledControlArrayHandle other);
// @category:read
bool LabelledControlArray_equality(LabelledControlArrayHandle handle,
                                   LabelledControlArrayHandle other);
// @category:read
bool LabelledControlArray_notequality(LabelledControlArrayHandle handle,
                                      LabelledControlArrayHandle other);
// @category:read
bool LabelledControlArray_greaterthan(LabelledControlArrayHandle handle,
                                      double                     value);
// @category:read
bool LabelledControlArray_lessthan(LabelledControlArrayHandle handle,
                                   double                     value);
// @category:write
void LabelledControlArray_remove_offset(LabelledControlArrayHandle handle,
                                        double                     offset);
// @category:read
double LabelledControlArray_sum(LabelledControlArrayHandle handle);
// @category:read
ListListSizeTHandle LabelledControlArray_where(
    LabelledControlArrayHandle handle, double value);
// @category:read
LabelledControlArrayHandle LabelledControlArray_flip(
    LabelledControlArrayHandle handle, size_t axis);
// @category:read
size_t LabelledControlArray_full_gradient(LabelledControlArrayHandle handle,
                                          FArrayDoubleHandle*        out_buffer,
                                          size_t buffer_size);
// @category:read
FArrayDoubleHandle LabelledControlArray_gradient(
    LabelledControlArrayHandle handle, size_t axis);
// @category:read
double LabelledControlArray_get_sum_of_squares(
    LabelledControlArrayHandle handle);
// @category:read
double LabelledControlArray_get_summed_diff_int_of_squares(
    LabelledControlArrayHandle handle, int other);
// @category:read
double LabelledControlArray_get_summed_diff_double_of_squares(
    LabelledControlArrayHandle handle, double other);
// @category:read
double LabelledControlArray_get_summed_diff_array_of_squares(
    LabelledControlArrayHandle handle, LabelledControlArrayHandle other);
// @category:read
StringHandle LabelledControlArray_to_json_string(
    LabelledControlArrayHandle handle);
// @category:allocation
LabelledControlArrayHandle LabelledControlArray_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
