

# File LabelledMeasuredArray\_c\_api.h

[**File List**](files.md) **>** [**arrays**](dir_bfe73c8db2db54615e75c4ba09b4f73a.md) **>** [**LabelledMeasuredArray\_c\_api.h**](LabelledMeasuredArray__c__api_8h.md)

[Go to the documentation of this file](LabelledMeasuredArray__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/ListListSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/arrays/MeasuredArray_c_api.h"

typedef void* LabelledMeasuredArrayHandle;

// @category:allocation
LabelledMeasuredArrayHandle LabelledMeasuredArray_copy(
    LabelledMeasuredArrayHandle handle);
// @category:deallocation
void LabelledMeasuredArray_destroy(LabelledMeasuredArrayHandle handle);
// @category:read
bool LabelledMeasuredArray_equal(LabelledMeasuredArrayHandle handle,
                                 LabelledMeasuredArrayHandle other);
// @category:read
bool LabelledMeasuredArray_not_equal(LabelledMeasuredArrayHandle handle,
                                     LabelledMeasuredArrayHandle other);
// @category:read
StringHandle LabelledMeasuredArray_to_json_string(
    LabelledMeasuredArrayHandle handle);
// @category:allocation
LabelledMeasuredArrayHandle LabelledMeasuredArray_from_json_string(
    StringHandle json);
// @category:allocation
LabelledMeasuredArrayHandle LabelledMeasuredArray_from_farray(
    FArrayDoubleHandle farray, AcquisitionContextHandle label);
// @category:allocation
LabelledMeasuredArrayHandle LabelledMeasuredArray_from_measured_array(
    MeasuredArrayHandle measuredarray, AcquisitionContextHandle label);
// @category:read
AcquisitionContextHandle LabelledMeasuredArray_label(
    LabelledMeasuredArrayHandle handle);
// @category:read
ConnectionHandle LabelledMeasuredArray_connection(
    LabelledMeasuredArrayHandle handle);
// @category:read
StringHandle LabelledMeasuredArray_instrument_type(
    LabelledMeasuredArrayHandle handle);
// @category:read
SymbolUnitHandle LabelledMeasuredArray_units(
    LabelledMeasuredArrayHandle handle);
// @category:read
size_t LabelledMeasuredArray_size(LabelledMeasuredArrayHandle handle);
// @category:read
size_t LabelledMeasuredArray_dimension(LabelledMeasuredArrayHandle handle);
// @category:read
size_t LabelledMeasuredArray_shape(LabelledMeasuredArrayHandle handle,
                                   size_t*                     out_buffer,
                                   size_t                      ndim);
// @category:read
size_t LabelledMeasuredArray_data(LabelledMeasuredArrayHandle handle,
                                  double*                     out_buffer,
                                  size_t                      numdata);
// @category:write
void LabelledMeasuredArray_plus_equals_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other);
// @category:write
void LabelledMeasuredArray_plus_equals_double(
    LabelledMeasuredArrayHandle handle, double other);
// @category:write
void LabelledMeasuredArray_plus_equals_int(LabelledMeasuredArrayHandle handle,
                                           int                         other);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_plus_measured_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_plus_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_plus_double(
    LabelledMeasuredArrayHandle handle, double other);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_plus_int(
    LabelledMeasuredArrayHandle handle, int other);
// @category:write
void LabelledMeasuredArray_minus_equals_measured_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other);
// @category:write
void LabelledMeasuredArray_minus_equals_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other);
// @category:write
void LabelledMeasuredArray_minus_equals_double(
    LabelledMeasuredArrayHandle handle, double other);
// @category:write
void LabelledMeasuredArray_minus_equals_int(LabelledMeasuredArrayHandle handle,
                                            int                         other);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_minus_measured_array(
    LabelledMeasuredArrayHandle handle, MeasuredArrayHandle other);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_minus_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_minus_double(
    LabelledMeasuredArrayHandle handle, double other);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_minus_int(
    LabelledMeasuredArrayHandle handle, int other);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_negation(
    LabelledMeasuredArrayHandle handle);
// @category:write
LabelledMeasuredArrayHandle LabelledMeasuredArray_times_equals_measured_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other);
// @category:write
LabelledMeasuredArrayHandle LabelledMeasuredArray_times_equals_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other);
// @category:write
void LabelledMeasuredArray_times_equals_double(
    LabelledMeasuredArrayHandle handle, double other);
// @category:write
void LabelledMeasuredArray_times_equals_int(LabelledMeasuredArrayHandle handle,
                                            int                         other);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_times_measured_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_times_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_times_double(
    LabelledMeasuredArrayHandle handle, double other);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_times_int(
    LabelledMeasuredArrayHandle handle, int other);
// @category:write
LabelledMeasuredArrayHandle LabelledMeasuredArray_divides_equals_measured_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other);
// @category:write
LabelledMeasuredArrayHandle LabelledMeasuredArray_divides_equals_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other);
// @category:write
void LabelledMeasuredArray_divides_equals_double(
    LabelledMeasuredArrayHandle handle, double other);
// @category:write
void LabelledMeasuredArray_divides_equals_int(
    LabelledMeasuredArrayHandle handle, int other);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_divides_measured_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_divides_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_divides_double(
    LabelledMeasuredArrayHandle handle, double other);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_divides_int(
    LabelledMeasuredArrayHandle handle, int other);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_pow(
    LabelledMeasuredArrayHandle handle, double other);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_abs(
    LabelledMeasuredArrayHandle handle);
// @category:read
/* AUTO-DOC from cpp: LabelledMeasuredArray_min |
 * falcon_core::math::arrays::LabelledMeasuredArray::min */
double LabelledMeasuredArray_min(LabelledMeasuredArrayHandle handle);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_min_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_min_measured_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other);
// @category:read
/* AUTO-DOC from cpp: LabelledMeasuredArray_max |
 * falcon_core::math::arrays::LabelledMeasuredArray::max */
double LabelledMeasuredArray_max(LabelledMeasuredArrayHandle handle);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_max_farray(
    LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other);
// @category:read
LabelledMeasuredArrayHandle LabelledMeasuredArray_max_measured_array(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other);
// @category:read
bool LabelledMeasuredArray_greater_than(LabelledMeasuredArrayHandle handle,
                                        double                      value);
// @category:read
bool LabelledMeasuredArray_less_than(LabelledMeasuredArrayHandle handle,
                                     double                      value);
// @category:write
void LabelledMeasuredArray_remove_offset(LabelledMeasuredArrayHandle handle,
                                         double                      offset);
// @category:read
double LabelledMeasuredArray_sum(LabelledMeasuredArrayHandle handle);
// @category:read
/* AUTO-DOC from cpp: LabelledMeasuredArray_reshape |
 * falcon_core::math::arrays::LabelledMeasuredArray::reshape */
LabelledMeasuredArrayHandle LabelledMeasuredArray_reshape(
    LabelledMeasuredArrayHandle handle, const size_t* shape, size_t ndims);
// @category:read
ListListSizeTHandle LabelledMeasuredArray_where(
    LabelledMeasuredArrayHandle handle, double value);
// @category:read
/* AUTO-DOC from cpp: LabelledMeasuredArray_flip |
 * falcon_core::math::arrays::LabelledMeasuredArray::flip */
LabelledMeasuredArrayHandle LabelledMeasuredArray_flip(
    LabelledMeasuredArrayHandle handle, size_t axis);
// @category:read
size_t LabelledMeasuredArray_full_gradient(
    LabelledMeasuredArrayHandle  handle,
    LabelledMeasuredArrayHandle* out_buffer,
    size_t                       buffer_size);
// @category:read
/* AUTO-DOC from cpp: LabelledMeasuredArray_gradient |
 * falcon_core::math::arrays::LabelledMeasuredArray::gradient */
/* AUTO-DOC from cpp: LabelledMeasuredArray_gradient |
 * falcon_core::math::arrays::LabelledMeasuredArray::gradient */
LabelledMeasuredArrayHandle LabelledMeasuredArray_gradient(
    LabelledMeasuredArrayHandle handle, size_t axis);
// @category:read
double LabelledMeasuredArray_get_sum_of_squares(
    LabelledMeasuredArrayHandle handle);
// @category:read
double LabelledMeasuredArray_get_summed_diff_int_of_squares(
    LabelledMeasuredArrayHandle handle, int other);
// @category:read
double LabelledMeasuredArray_get_summed_diff_double_of_squares(
    LabelledMeasuredArrayHandle handle, double other);
// @category:read
double LabelledMeasuredArray_get_summed_diff_array_of_squares(
    LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other);

#ifdef __cplusplus
}
#endif
```


