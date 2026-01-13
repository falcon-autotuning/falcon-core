

# File ControlArray\_c\_api.h

[**File List**](files.md) **>** [**arrays**](dir_bfe73c8db2db54615e75c4ba09b4f73a.md) **>** [**ControlArray\_c\_api.h**](ControlArray__c__api_8h.md)

[Go to the documentation of this file](ControlArray__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/ListListSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"

typedef void* ControlArrayHandle;

// @category:allocation
ControlArrayHandle ControlArray_copy(ControlArrayHandle handle);
// @category:deallocation
void ControlArray_destroy(ControlArrayHandle handle);
// @category:read
bool ControlArray_equal(ControlArrayHandle handle, ControlArrayHandle other);
// @category:read
bool ControlArray_not_equal(ControlArrayHandle handle,
                            ControlArrayHandle other);
// @category:read
StringHandle ControlArray_to_json_string(ControlArrayHandle handle);
// @category:allocation
ControlArrayHandle ControlArray_from_json_string(StringHandle json);
// @category:allocation
ControlArrayHandle ControlArray_from_data(const double* data,
                                          const size_t* shape,
                                          size_t        ndim);
// @category:allocation
ControlArrayHandle ControlArray_from_farray(FArrayDoubleHandle farray);
// @category:read
size_t ControlArray_size(ControlArrayHandle handle);
// @category:read
size_t ControlArray_dimension(ControlArrayHandle handle);
// @category:read
size_t ControlArray_shape(ControlArrayHandle handle,
                          size_t*            out_buffer,
                          size_t             ndim);
// @category:read
size_t ControlArray_data(ControlArrayHandle handle,
                         double*            out_buffer,
                         size_t             numdata);
// @category:write
void ControlArray_plus_equals_farray(ControlArrayHandle handle,
                                     FArrayDoubleHandle other);
// @category:write
void ControlArray_plus_equals_double(ControlArrayHandle handle, double other);
// @category:write
void ControlArray_plus_equals_int(ControlArrayHandle handle, int other);
// @category:read
ControlArrayHandle ControlArray_plus_control_array(ControlArrayHandle handle,
                                                   ControlArrayHandle other);
// @category:read
ControlArrayHandle ControlArray_plus_farray(ControlArrayHandle handle,
                                            FArrayDoubleHandle other);
// @category:read
ControlArrayHandle ControlArray_plus_double(ControlArrayHandle handle,
                                            double             other);
// @category:read
ControlArrayHandle ControlArray_plus_int(ControlArrayHandle handle, int other);
// @category:write
void ControlArray_minus_equals_farray(ControlArrayHandle handle,
                                      FArrayDoubleHandle other);
// @category:write
void ControlArray_minus_equals_double(ControlArrayHandle handle, double other);
// @category:write
void ControlArray_minus_equals_int(ControlArrayHandle handle, int other);
// @category:read
ControlArrayHandle ControlArray_minus_control_array(ControlArrayHandle handle,
                                                    ControlArrayHandle other);
// @category:read
ControlArrayHandle ControlArray_minus_farray(ControlArrayHandle handle,
                                             FArrayDoubleHandle other);
// @category:read
ControlArrayHandle ControlArray_minus_double(ControlArrayHandle handle,
                                             double             other);
// @category:read
ControlArrayHandle ControlArray_minus_int(ControlArrayHandle handle, int other);
// @category:read
ControlArrayHandle ControlArray_negation(ControlArrayHandle handle);
// @category:write
void ControlArray_times_equals_double(ControlArrayHandle handle, double other);
// @category:write
void ControlArray_times_equals_int(ControlArrayHandle handle, int other);
// @category:read
ControlArrayHandle ControlArray_times_double(ControlArrayHandle handle,
                                             double             other);
// @category:read
ControlArrayHandle ControlArray_times_int(ControlArrayHandle handle, int other);
// @category:write
void ControlArray_divides_equals_double(ControlArrayHandle handle,
                                        double             other);
// @category:write
void ControlArray_divides_equals_int(ControlArrayHandle handle, int other);
// @category:read
ControlArrayHandle ControlArray_divides_double(ControlArrayHandle handle,
                                               double             other);
// @category:read
ControlArrayHandle ControlArray_divides_int(ControlArrayHandle handle,
                                            int                other);
// @category:read
ControlArrayHandle ControlArray_pow(ControlArrayHandle handle, double other);
// @category:read
ControlArrayHandle ControlArray_abs(ControlArrayHandle handle);
// @category:read
/* AUTO-DOC from cpp: ControlArray_min |
 * falcon_core::math::arrays::ControlArray::min */
double ControlArray_min(ControlArrayHandle handle);
// @category:read
ControlArrayHandle ControlArray_min_farray(ControlArrayHandle handle,
                                           FArrayDoubleHandle other);
// @category:read
ControlArrayHandle ControlArray_min_control_array(ControlArrayHandle handle,
                                                  ControlArrayHandle other);
// @category:read
/* AUTO-DOC from cpp: ControlArray_max |
 * falcon_core::math::arrays::ControlArray::max */
double ControlArray_max(ControlArrayHandle handle);
// @category:read
ControlArrayHandle ControlArray_max_farray(ControlArrayHandle handle,
                                           FArrayDoubleHandle other);
// @category:read
ControlArrayHandle ControlArray_max_control_array(ControlArrayHandle handle,
                                                  ControlArrayHandle other);
// @category:read
bool ControlArray_greater_than(ControlArrayHandle handle, double value);
// @category:read
bool ControlArray_less_than(ControlArrayHandle handle, double value);
// @category:write
void ControlArray_remove_offset(ControlArrayHandle handle, double offset);
// @category:read
double ControlArray_sum(ControlArrayHandle handle);
// @category:read
ListListSizeTHandle ControlArray_where(ControlArrayHandle handle, double value);
// @category:read
/* AUTO-DOC from cpp: ControlArray_flip |
 * falcon_core::math::arrays::ControlArray::flip */
ControlArrayHandle ControlArray_flip(ControlArrayHandle handle, size_t axis);
// @category:read
size_t ControlArray_full_gradient(ControlArrayHandle  handle,
                                  FArrayDoubleHandle* out_buffer,
                                  size_t              buffer_size);
// @category:read
FArrayDoubleHandle ControlArray_gradient(ControlArrayHandle handle,
                                         size_t             axis);
// @category:read
double ControlArray_get_sum_of_squares(ControlArrayHandle handle);
// @category:read
double ControlArray_get_summed_diff_int_of_squares(ControlArrayHandle handle,
                                                   int                other);
// @category:read
double ControlArray_get_summed_diff_double_of_squares(ControlArrayHandle handle,
                                                      double             other);
// @category:read
double ControlArray_get_summed_diff_array_of_squares(ControlArrayHandle handle,
                                                     ControlArrayHandle other);

#ifdef __cplusplus
}
#endif
```


