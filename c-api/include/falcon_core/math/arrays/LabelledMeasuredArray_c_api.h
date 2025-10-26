#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <cstddef>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/ListListSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/arrays/MeasuredArray_c_api.h"

typedef void* LabelledMeasuredArrayHandle;

// Constructors
LabelledMeasuredArrayHandle LabelledMeasuredArray_from_farray(
    FArrayDoubleHandle farray, AcquisitionContextHandle label);
LabelledMeasuredArrayHandle LabelledMeasuredArray_from_controlarray(
    MeasuredArrayHandle measuredarray, AcquisitionContextHandle label);

// Destructor
void LabelledMeasuredArray_destroy(LabelledMeasuredArrayHandle handle);

// Methods
AcquisitionContextHandle LabelledMeasuredArray_label(
    LabelledMeasuredArrayHandle handle);
ConnectionHandle LabelledMeasuredArray_connection(
    LabelledMeasuredArrayHandle handle);
StringHandle LabelledMeasuredArray_instrument_type(
    LabelledMeasuredArrayHandle handle);
SymbolUnitHandle LabelledMeasuredArray_units(
    LabelledMeasuredArrayHandle handle);
size_t LabelledMeasuredArray_size(LabelledMeasuredArrayHandle handle);
size_t LabelledMeasuredArray_dimension(LabelledMeasuredArrayHandle handle);
size_t LabelledMeasuredArray_shape(LabelledMeasuredArrayHandle handle,
                                   size_t*                     out_buffer,
                                   size_t                      ndim);
size_t LabelledMeasuredArray_data(LabelledMeasuredArrayHandle handle,
                                  double*                     out_buffer,
                                  size_t                      numdata);
void LabelledMeasuredArray_plusequals_farray(LabelledMeasuredArrayHandle handle,
                                             FArrayDoubleHandle          other);
void LabelledMeasuredArray_plusequals_double(LabelledMeasuredArrayHandle handle,
                                             const double                other);
void LabelledMeasuredArray_plusequals_int(LabelledMeasuredArrayHandle handle,
                                          const int                   other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_plus_control_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_plus_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_plus_double(
    LabelledMeasuredArrayHandle handle, const double other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_plus_int(
    LabelledMeasuredArrayHandle handle, const int other);
void LabelledMeasuredArray_minusequals_control_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other);
void LabelledMeasuredArray_minusequals_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other);
void LabelledMeasuredArray_minusequals_double(
    LabelledMeasuredArrayHandle handle, const double other);
void LabelledMeasuredArray_minusequals_int(LabelledMeasuredArrayHandle handle,
                                           const int                   other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_minus_control_array(
    LabelledMeasuredArrayHandle handle, MeasuredArrayHandle other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_minus_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_minus_double(
    LabelledMeasuredArrayHandle handle, const double other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_minus_int(
    LabelledMeasuredArrayHandle handle, const int other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_negation(
    LabelledMeasuredArrayHandle handle);
LabelledMeasuredArrayHandle LabelledMeasuredArray_timesequals_measured_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_timesequals_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other);
void MeasuredArray_timesequals_double(LabelledMeasuredArrayHandle handle,
                                      const double                other);
void LabelledMeasuredArray_timesequals_int(LabelledMeasuredArrayHandle handle,
                                           const int                   other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_times_measured_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_times_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_times_double(
    LabelledMeasuredArrayHandle handle, const double other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_times_int(
    LabelledMeasuredArrayHandle handle, const int other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_dividesequals_measured_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_dividesequals_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other);
void LabelledMeasuredArray_dividesequals_double(
    LabelledMeasuredArrayHandle handle, const double other);
void LabelledMeasuredArray_dividesequals_int(LabelledMeasuredArrayHandle handle,
                                             const int                   other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_divides_measured_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_divides_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_divides_double(
    LabelledMeasuredArrayHandle handle, const double other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_divides_int(
    LabelledMeasuredArrayHandle handle, const int other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_pow(
    LabelledMeasuredArrayHandle handle, const double other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_abs(
    LabelledMeasuredArrayHandle handle);
LabelledMeasuredArrayHandle LabelledMeasuredArray_min(
    LabelledMeasuredArrayHandle handle);
LabelledMeasuredArrayHandle LabelledMeasuredArray_min_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_min_control_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_max(
    LabelledMeasuredArrayHandle handle);
LabelledMeasuredArrayHandle LabelledMeasuredArray_max_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other);
LabelledMeasuredArrayHandle LabelledMeasuredArray_max_control_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other);
bool   LabelledMeasuredArray_equality(LabelledMeasuredArrayHandle handle,
                                      LabelledMeasuredArrayHandle other);
bool   LabelledMeasuredArray_notequality(LabelledMeasuredArrayHandle handle,
                                         LabelledMeasuredArrayHandle other);
bool   LabelledMeasuredArray_greaterthan(LabelledMeasuredArrayHandle handle,
                                         const double                value);
bool   LabelledMeasuredArray_lessthan(LabelledMeasuredArrayHandle handle,
                                      const double                value);
void   LabelledMeasuredArray_remove_offset(LabelledMeasuredArrayHandle handle,
                                           const double                offset);
double LabelledMeasuredArray_sum(LabelledMeasuredArrayHandle handle);
LabelledMeasuredArrayHandle LabelledMeasuredArray_reshape(
    LabelledMeasuredArrayHandle handle, const size_t* shape, size_t ndims);
ListListSizeTHandle LabelledMeasuredArray_where(
    LabelledMeasuredArrayHandle handle, const double value);
LabelledMeasuredArrayHandle LabelledMeasuredArray_flip(
    LabelledMeasuredArrayHandle handle, size_t axis);
size_t LabelledMeasuredArray_full_gradient(
    LabelledMeasuredArrayHandle  handle,
    LabelledMeasuredArrayHandle* out_buffer,
    size_t                       buffer_size);
LabelledMeasuredArrayHandle LabelledMeasuredArray_gradient(
    LabelledMeasuredArrayHandle handle, size_t axis);
double LabelledMeasuredArray_get_sum_of_squares(
    LabelledMeasuredArrayHandle handle);
double LabelledMeasuredArray_get_summed_diff_int_of_squares(
    LabelledMeasuredArrayHandle handle, const int other);
double LabelledMeasuredArray_get_summed_diff_double_of_squares(
    LabelledMeasuredArrayHandle handle, const double other);
double LabelledMeasuredArray_get_summed_diff_array_of_squares(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other);
// Serialization (from Song)
StringHandle LabelledMeasuredArray_to_json_string(
    LabelledMeasuredArrayHandle handle);
LabelledMeasuredArrayHandle LabelledMeasuredArray_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
