#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/ListFArrayDouble_c_api.h"
#include "falcon_core/generic/ListListSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/arrays/ControlArray_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
typedef void* LabelledControlArray1DHandle;

// @category:allocation
LabelledControlArray1DHandle LabelledControlArray1D_from_farray(
    FArrayDoubleHandle farray, AcquisitionContextHandle label);
// @category:allocation
LabelledControlArray1DHandle LabelledControlArray1D_from_control_array(
    ControlArrayHandle controlarray, AcquisitionContextHandle label);
// @category:deallocation
void LabelledControlArray1D_destroy(LabelledControlArray1DHandle handle);
// @category:read
bool LabelledControlArray1D_is_1D(LabelledControlArray1DHandle handle);
// @category:read
FArrayDoubleHandle LabelledControlArray1D_as_1D(
    LabelledControlArray1DHandle handle);
// @category:read
double LabelledControlArray1D_get_start(LabelledControlArray1DHandle handle);
// @category:read
double LabelledControlArray1D_get_end(LabelledControlArray1DHandle handle);
// @category:read
bool LabelledControlArray1D_is_decreasing(LabelledControlArray1DHandle handle);
// @category:read
bool LabelledControlArray1D_is_increasing(LabelledControlArray1DHandle handle);
// @category:read
double LabelledControlArray1D_get_distance(LabelledControlArray1DHandle handle);
// @category:read
double LabelledControlArray1D_get_mean(LabelledControlArray1DHandle handle);
// @category:read
double LabelledControlArray1D_get_std(LabelledControlArray1DHandle handle);
// @category:write
void LabelledControlArray1D_reverse(LabelledControlArray1DHandle handle);
// @category:read
size_t LabelledControlArray1D_get_closest_index(
    LabelledControlArray1DHandle handle, double value);
// @category:read
ListFArrayDoubleHandle LabelledControlArray1D_even_divisions(
    LabelledControlArray1DHandle handle, size_t divisions);
// @category:read
AcquisitionContextHandle LabelledControlArray1D_label(
    LabelledControlArray1DHandle handle);
// @category:read
ConnectionHandle LabelledControlArray1D_connection(
    LabelledControlArray1DHandle handle);
// @category:read
StringHandle LabelledControlArray1D_instrument_type(
    LabelledControlArray1DHandle handle);
// @category:read
SymbolUnitHandle LabelledControlArray1D_units(
    LabelledControlArray1DHandle handle);
// @category:read
size_t LabelledControlArray1D_size(LabelledControlArray1DHandle handle);
// @category:read
size_t LabelledControlArray1D_dimension(LabelledControlArray1DHandle handle);
// @category:read
size_t LabelledControlArray1D_shape(LabelledControlArray1DHandle handle,
                                    size_t*                      out_buffer,
                                    size_t                       ndim);
// @category:read
size_t LabelledControlArray1D_data(LabelledControlArray1DHandle handle,
                                   double*                      out_buffer,
                                   size_t                       numdata);
// @category:write
void LabelledControlArray1D_plus_equals_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other);
// @category:write
void LabelledControlArray1D_plus_equals_double(
    LabelledControlArray1DHandle handle, double other);
// @category:write
void LabelledControlArray1D_plus_equals_int(LabelledControlArray1DHandle handle,
                                           int                          other);
// @category:read
LabelledControlArray1DHandle LabelledControlArray1D_plus_control_array(
    LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other);
// @category:read
LabelledControlArray1DHandle LabelledControlArray1D_plus_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other);
// @category:read
LabelledControlArray1DHandle LabelledControlArray1D_plus_double(
    LabelledControlArray1DHandle handle, double other);
// @category:read
LabelledControlArray1DHandle LabelledControlArray1D_plus_int(
    LabelledControlArray1DHandle handle, int other);
// @category:write
void LabelledControlArray1D_minus_equals_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other);
// @category:write
void LabelledControlArray1D_minus_equals_double(
    LabelledControlArray1DHandle handle, double other);
// @category:write
void LabelledControlArray1D_minus_equals_int(LabelledControlArray1DHandle handle,
                                            int                          other);
// @category:read
LabelledControlArray1DHandle LabelledControlArray1D_minus_control_array(
    LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other);
// @category:read
LabelledControlArray1DHandle LabelledControlArray1D_minus_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other);
// @category:read
LabelledControlArray1DHandle LabelledControlArray1D_minus_double(
    LabelledControlArray1DHandle handle, double other);
// @category:read
LabelledControlArray1DHandle LabelledControlArray1D_minus_int(
    LabelledControlArray1DHandle handle, int other);
// @category:read
LabelledControlArray1DHandle LabelledControlArray1D_negation(
    LabelledControlArray1DHandle handle);
// @category:write
void LabelledControlArray1D_times_equals_double(
    LabelledControlArray1DHandle handle, double other);
// @category:write
void LabelledControlArray1D_times_equals_int(LabelledControlArray1DHandle handle,
                                            int                          other);
// @category:read
LabelledControlArray1DHandle LabelledControlArray1D_times_double(
    LabelledControlArray1DHandle handle, double other);
// @category:read
LabelledControlArray1DHandle LabelledControlArray1D_times_int(
    LabelledControlArray1DHandle handle, int other);
// @category:write
void LabelledControlArray1D_divides_equals_double(
    LabelledControlArray1DHandle handle, double other);
// @category:write
void LabelledControlArray1D_divides_equals_int(
    LabelledControlArray1DHandle handle, int other);
// @category:read
LabelledControlArray1DHandle LabelledControlArray1D_divides_double(
    LabelledControlArray1DHandle handle, double other);
// @category:read
LabelledControlArray1DHandle LabelledControlArray1D_divides_int(
    LabelledControlArray1DHandle handle, int other);
// @category:read
LabelledControlArray1DHandle LabelledControlArray1D_pow(
    LabelledControlArray1DHandle handle, double other);
// @category:read
LabelledControlArray1DHandle LabelledControlArray1D_abs(
    LabelledControlArray1DHandle handle);
// @category:read
LabelledControlArray1DHandle LabelledControlArray1D_min_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other);
// @category:read
LabelledControlArray1DHandle LabelledControlArray1D_min_control_array(
    LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other);
// @category:read
LabelledControlArray1DHandle LabelledControlArray1D_max_farray(
    LabelledControlArray1DHandle handle, FArrayDoubleHandle other);
// @category:read
LabelledControlArray1DHandle LabelledControlArray1D_max_control_array(
    LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other);
// @category:read
bool LabelledControlArray1D_equal(LabelledControlArray1DHandle handle,
                                     LabelledControlArray1DHandle other);
// @category:read
bool LabelledControlArray1D_not_equal(LabelledControlArray1DHandle handle,
                                        LabelledControlArray1DHandle other);
// @category:read
bool LabelledControlArray1D_greater_than(LabelledControlArray1DHandle handle,
                                        double                       value);
// @category:read
bool LabelledControlArray1D_less_than(LabelledControlArray1DHandle handle,
                                     double                       value);
// @category:write
void LabelledControlArray1D_remove_offset(LabelledControlArray1DHandle handle,
                                          double                       offset);
// @category:read
double LabelledControlArray1D_sum(LabelledControlArray1DHandle handle);
// @category:read
ListListSizeTHandle LabelledControlArray1D_where(
    LabelledControlArray1DHandle handle, double value);
// @category:read
LabelledControlArray1DHandle LabelledControlArray1D_flip(
    LabelledControlArray1DHandle handle, size_t axis);
// @category:read
size_t LabelledControlArray1D_full_gradient(LabelledControlArray1DHandle handle,
                                            FArrayDoubleHandle* out_buffer,
                                            size_t              buffer_size);
// @category:read
FArrayDoubleHandle LabelledControlArray1D_gradient(
    LabelledControlArray1DHandle handle, size_t axis);
// @category:read
double LabelledControlArray1D_get_sum_of_squares(
    LabelledControlArray1DHandle handle);
// @category:read
double LabelledControlArray1D_get_summed_diff_int_of_squares(
    LabelledControlArray1DHandle handle, int other);
// @category:read
double LabelledControlArray1D_get_summed_diff_double_of_squares(
    LabelledControlArray1DHandle handle, double other);
// @category:read
double LabelledControlArray1D_get_summed_diff_array_of_squares(
    LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other);
// @category:read
StringHandle LabelledControlArray1D_to_json_string(
    LabelledControlArray1DHandle handle);
// @category:allocation
LabelledControlArray1DHandle LabelledControlArray1D_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
