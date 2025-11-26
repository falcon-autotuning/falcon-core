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
#include "falcon_core/math/arrays/MeasuredArray_c_api.h"

typedef void* LabelledMeasuredArray1DHandle;

// @category:allocation
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_from_farray(
    FArrayDoubleHandle farray, AcquisitionContextHandle label);
// @category:allocation
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_from_measured_array(
    MeasuredArrayHandle measuredarray, AcquisitionContextHandle label);
// @category:deallocation
void LabelledMeasuredArray1D_destroy(LabelledMeasuredArray1DHandle handle);
// @category:read
bool LabelledMeasuredArray1D_is_1D(LabelledMeasuredArray1DHandle handle);
// @category:read
FArrayDoubleHandle LabelledMeasuredArray1D_as_1D(
    LabelledMeasuredArray1DHandle handle);
// @category:read
double LabelledMeasuredArray1D_get_start(LabelledMeasuredArray1DHandle handle);
// @category:read
double LabelledMeasuredArray1D_get_end(LabelledMeasuredArray1DHandle handle);
// @category:read
bool LabelledMeasuredArray1D_is_decreasing(
    LabelledMeasuredArray1DHandle handle);
// @category:read
bool LabelledMeasuredArray1D_is_increasing(
    LabelledMeasuredArray1DHandle handle);
// @category:read
double LabelledMeasuredArray1D_get_distance(
    LabelledMeasuredArray1DHandle handle);
// @category:read
double LabelledMeasuredArray1D_get_mean(LabelledMeasuredArray1DHandle handle);
// @category:read
double LabelledMeasuredArray1D_get_std(LabelledMeasuredArray1DHandle handle);
// @category:write
void LabelledMeasuredArray1D_reverse(LabelledMeasuredArray1DHandle handle);
// @category:read
size_t LabelledMeasuredArray1D_get_closest_index(
    LabelledMeasuredArray1DHandle handle, double value);
// @category:read
ListFArrayDoubleHandle LabelledMeasuredArray1D_even_divisions(
    LabelledMeasuredArray1DHandle handle, size_t divisions);
// @category:read
AcquisitionContextHandle LabelledMeasuredArray1D_label(
    LabelledMeasuredArray1DHandle handle);
// @category:read
ConnectionHandle LabelledMeasuredArray1D_connection(
    LabelledMeasuredArray1DHandle handle);
// @category:read
StringHandle LabelledMeasuredArray1D_instrument_type(
    LabelledMeasuredArray1DHandle handle);
// @category:read
SymbolUnitHandle LabelledMeasuredArray1D_units(
    LabelledMeasuredArray1DHandle handle);
// @category:read
size_t LabelledMeasuredArray1D_size(LabelledMeasuredArray1DHandle handle);
// @category:read
size_t LabelledMeasuredArray1D_dimension(LabelledMeasuredArray1DHandle handle);
// @category:read
size_t LabelledMeasuredArray1D_shape(LabelledMeasuredArray1DHandle handle,
                                     size_t*                       out_buffer,
                                     size_t                        ndim);
// @category:read
size_t LabelledMeasuredArray1D_data(LabelledMeasuredArray1DHandle handle,
                                    double*                       out_buffer,
                                    size_t                        numdata);
// @category:write
void LabelledMeasuredArray1D_plusequals_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
// @category:write
void LabelledMeasuredArray1D_plusequals_double(
    LabelledMeasuredArray1DHandle handle, double other);
// @category:write
void LabelledMeasuredArray1D_plusequals_int(
    LabelledMeasuredArray1DHandle handle, int other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_plus_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_plus_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_plus_double(
    LabelledMeasuredArray1DHandle handle, double other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_plus_int(
    LabelledMeasuredArray1DHandle handle, int other);
// @category:write
void LabelledMeasuredArray1D_minusequals_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
// @category:write
void LabelledMeasuredArray1D_minusequals_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
// @category:write
void LabelledMeasuredArray1D_minusequals_double(
    LabelledMeasuredArray1DHandle handle, double other);
// @category:write
void LabelledMeasuredArray1D_minusequals_int(
    LabelledMeasuredArray1DHandle handle, int other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_minus_measured_array(
    LabelledMeasuredArray1DHandle handle, MeasuredArrayHandle other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_minus_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_minus_double(
    LabelledMeasuredArray1DHandle handle, double other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_minus_int(
    LabelledMeasuredArray1DHandle handle, int other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_negation(
    LabelledMeasuredArray1DHandle handle);
// @category:read
LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_timesequals_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_timesequals_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
// @category:write
void LabelledMeasuredArray1D_timesequals_double(
    LabelledMeasuredArray1DHandle handle, double other);
// @category:write
void LabelledMeasuredArray1D_timesequals_int(
    LabelledMeasuredArray1DHandle handle, int other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_double(
    LabelledMeasuredArray1DHandle handle, double other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_int(
    LabelledMeasuredArray1DHandle handle, int other);
// @category:read
LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_dividesequals_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_dividesequals_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
// @category:write
void LabelledMeasuredArray1D_dividesequals_double(
    LabelledMeasuredArray1DHandle handle, double other);
// @category:write
void LabelledMeasuredArray1D_dividesequals_int(
    LabelledMeasuredArray1DHandle handle, int other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_double(
    LabelledMeasuredArray1DHandle handle, double other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_int(
    LabelledMeasuredArray1DHandle handle, int other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_pow(
    LabelledMeasuredArray1DHandle handle, double other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_abs(
    LabelledMeasuredArray1DHandle handle);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_min_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_min_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_max_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_max_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
// @category:read
bool LabelledMeasuredArray1D_equality(LabelledMeasuredArray1DHandle handle,
                                      LabelledMeasuredArray1DHandle other);
// @category:read
bool LabelledMeasuredArray1D_notequality(LabelledMeasuredArray1DHandle handle,
                                         LabelledMeasuredArray1DHandle other);
// @category:read
bool LabelledMeasuredArray1D_greaterthan(LabelledMeasuredArray1DHandle handle,
                                         double                        value);
// @category:read
bool LabelledMeasuredArray1D_lessthan(LabelledMeasuredArray1DHandle handle,
                                      double                        value);
// @category:write
void LabelledMeasuredArray1D_remove_offset(LabelledMeasuredArray1DHandle handle,
                                           double offset);
// @category:read
double LabelledMeasuredArray1D_sum(LabelledMeasuredArray1DHandle handle);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_reshape(
    LabelledMeasuredArray1DHandle handle, const size_t* shape, size_t ndims);
// @category:read
ListListSizeTHandle LabelledMeasuredArray1D_where(
    LabelledMeasuredArray1DHandle handle, double value);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_flip(
    LabelledMeasuredArray1DHandle handle, size_t axis);
// @category:read
size_t LabelledMeasuredArray1D_full_gradient(
    LabelledMeasuredArray1DHandle  handle,
    LabelledMeasuredArray1DHandle* out_buffer,
    size_t                         buffer_size);
// @category:read
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_gradient(
    LabelledMeasuredArray1DHandle handle, size_t axis);
// @category:read
double LabelledMeasuredArray1D_get_sum_of_squares(
    LabelledMeasuredArray1DHandle handle);
// @category:read
double LabelledMeasuredArray1D_get_summed_diff_int_of_squares(
    LabelledMeasuredArray1DHandle handle, int other);
// @category:read
double LabelledMeasuredArray1D_get_summed_diff_double_of_squares(
    LabelledMeasuredArray1DHandle handle, double other);
// @category:read
double LabelledMeasuredArray1D_get_summed_diff_array_of_squares(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
// @category:read
StringHandle LabelledMeasuredArray1D_to_json_string(
    LabelledMeasuredArray1DHandle handle);
// @category:allocation
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
