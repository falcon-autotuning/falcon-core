#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <cstddef>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/ListFArrayDouble_c_api.h"
#include "falcon_core/generic/ListListSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/arrays/MeasuredArray_c_api.h"

typedef void* LabelledMeasuredArray1DHandle;

// Constructors
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_from_farray(
    FArrayDoubleHandle farray, AcquisitionContextHandle label);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_from_controlarray(
    MeasuredArrayHandle measuredarray, AcquisitionContextHandle label);

// Destructor
void LabelledMeasuredArray1D_destroy(LabelledMeasuredArray1DHandle handle);

// Methods
bool LabelledMeasuredArray1D_is_1D(LabelledMeasuredArray1DHandle handle);
FArrayDoubleHandle LabelledMeasuredArray1D_as_1D(
    LabelledMeasuredArray1DHandle handle);
double LabelledMeasuredArray1D_get_start(LabelledMeasuredArray1DHandle handle);
double LabelledMeasuredArray1D_get_end(LabelledMeasuredArray1DHandle handle);
bool   LabelledMeasuredArray1D_is_decreasing(
      LabelledMeasuredArray1DHandle handle);
bool LabelledMeasuredArray1D_is_decreasing(
    LabelledMeasuredArray1DHandle handle);
double LabelledMeasuredArray1D_get_distance(
    LabelledMeasuredArray1DHandle handle);
double LabelledMeasuredArray1D_get_mean(LabelledMeasuredArray1DHandle handle);
double LabelledMeasuredArray1D_get_std(LabelledMeasuredArray1DHandle handle);
void   LabelledMeasuredArray1D_reverse(LabelledMeasuredArray1DHandle handle);
size_t LabelledMeasuredArray1D_get_closest_index(
    LabelledMeasuredArray1DHandle handle, double value);
ListFArrayDoubleHandle LabelledMeasuredArray1D_even_divisions(
    LabelledMeasuredArray1DHandle handle, size_t divisions);
AcquisitionContextHandle LabelledMeasuredArray1D_label(
    LabelledMeasuredArray1DHandle handle);
ConnectionHandle LabelledMeasuredArray1D_connection(
    LabelledMeasuredArray1DHandle handle);
StringHandle LabelledMeasuredArray1D_instrument_type(
    LabelledMeasuredArray1DHandle handle);
SymbolUnitHandle LabelledMeasuredArray1D_units(
    LabelledMeasuredArray1DHandle handle);
size_t LabelledMeasuredArray1D_size(LabelledMeasuredArray1DHandle handle);
size_t LabelledMeasuredArray1D_dimension(LabelledMeasuredArray1DHandle handle);
size_t LabelledMeasuredArray1D_shape(LabelledMeasuredArray1DHandle handle,
                                     size_t*                       out_buffer,
                                     size_t                        ndim);
size_t LabelledMeasuredArray1D_data(LabelledMeasuredArray1DHandle handle,
                                    double*                       out_buffer,
                                    size_t                        numdata);
void   LabelledMeasuredArray1D_plusequals_farray(
      LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
void LabelledMeasuredArray1D_plusequals_double(
    LabelledMeasuredArray1DHandle handle, const double other);
void LabelledMeasuredArray1D_plusequals_int(
    LabelledMeasuredArray1DHandle handle, const int other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_plus_control_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_plus_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_plus_double(
    LabelledMeasuredArray1DHandle handle, const double other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_plus_int(
    LabelledMeasuredArray1DHandle handle, const int other);
void LabelledMeasuredArray1D_minusequals_control_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
void LabelledMeasuredArray1D_minusequals_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
void LabelledMeasuredArray1D_minusequals_double(
    LabelledMeasuredArray1DHandle handle, const double other);
void LabelledMeasuredArray1D_minusequals_int(
    LabelledMeasuredArray1DHandle handle, const int other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_minus_control_array(
    LabelledMeasuredArray1DHandle handle, MeasuredArrayHandle other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_minus_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_minus_double(
    LabelledMeasuredArray1DHandle handle, const double other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_minus_int(
    LabelledMeasuredArray1DHandle handle, const int other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_negation(
    LabelledMeasuredArray1DHandle handle);
LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_timesequals_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_timesequals_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
void MeasuredArray_timesequals_double(LabelledMeasuredArray1DHandle handle,
                                      const double                  other);
void LabelledMeasuredArray1D_timesequals_int(
    LabelledMeasuredArray1DHandle handle, const int other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_double(
    LabelledMeasuredArray1DHandle handle, const double other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_int(
    LabelledMeasuredArray1DHandle handle, const int other);
LabelledMeasuredArray1DHandle
LabelledMeasuredArray1D_dividesequals_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_dividesequals_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
void LabelledMeasuredArray1D_dividesequals_double(
    LabelledMeasuredArray1DHandle handle, const double other);
void LabelledMeasuredArray1D_dividesequals_int(
    LabelledMeasuredArray1DHandle handle, const int other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_measured_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_double(
    LabelledMeasuredArray1DHandle handle, const double other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_int(
    LabelledMeasuredArray1DHandle handle, const int other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_pow(
    LabelledMeasuredArray1DHandle handle, const double other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_abs(
    LabelledMeasuredArray1DHandle handle);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_min(
    LabelledMeasuredArray1DHandle handle);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_min_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_min_control_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_max(
    LabelledMeasuredArray1DHandle handle);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_max_farray(
    LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_max_control_array(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
bool LabelledMeasuredArray1D_equality(LabelledMeasuredArray1DHandle handle,
                                      LabelledMeasuredArray1DHandle other);
bool LabelledMeasuredArray1D_notequality(LabelledMeasuredArray1DHandle handle,
                                         LabelledMeasuredArray1DHandle other);
bool LabelledMeasuredArray1D_greaterthan(LabelledMeasuredArray1DHandle handle,
                                         const double                  value);
bool LabelledMeasuredArray1D_lessthan(LabelledMeasuredArray1DHandle handle,
                                      const double                  value);
void LabelledMeasuredArray1D_remove_offset(LabelledMeasuredArray1DHandle handle,
                                           const double offset);
double LabelledMeasuredArray1D_sum(LabelledMeasuredArray1DHandle handle);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_reshape(
    LabelledMeasuredArray1DHandle handle, const size_t* shape, size_t ndims);
ListListSizeTHandle LabelledMeasuredArray1D_where(
    LabelledMeasuredArray1DHandle handle, const double value);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_flip(
    LabelledMeasuredArray1DHandle handle, size_t axis);
size_t LabelledMeasuredArray1D_full_gradient(
    LabelledMeasuredArray1DHandle  handle,
    LabelledMeasuredArray1DHandle* out_buffer,
    size_t                         buffer_size);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_gradient(
    LabelledMeasuredArray1DHandle handle, size_t axis);
double LabelledMeasuredArray1D_get_sum_of_squares(
    LabelledMeasuredArray1DHandle handle);
double LabelledMeasuredArray1D_get_summed_diff_int_of_squares(
    LabelledMeasuredArray1DHandle handle, const int other);
double LabelledMeasuredArray1D_get_summed_diff_double_of_squares(
    LabelledMeasuredArray1DHandle handle, const double other);
double LabelledMeasuredArray1D_get_summed_diff_array_of_squares(
    LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other);
// Serialization (from Song)
StringHandle LabelledMeasuredArray1D_to_json_string(
    LabelledMeasuredArray1DHandle handle);
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
