

# File LabelledMeasuredArray1D\_c\_api.h



[**FileList**](files.md) **>** [**arrays**](dir_bfe73c8db2db54615e75c4ba09b4f73a.md) **>** [**LabelledMeasuredArray1D\_c\_api.h**](LabelledMeasuredArray1D__c__api_8h.md)

[Go to the source code of this file](LabelledMeasuredArray1D__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"`
* `#include "falcon_core/generic/FArrayDouble_c_api.h"`
* `#include "falcon_core/generic/ListFArrayDouble_c_api.h"`
* `#include "falcon_core/generic/ListListSizeT_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/math/arrays/MeasuredArray_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**LabelledMeasuredArray1DHandle**](#typedef-labelledmeasuredarray1dhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_abs**](#function-labelledmeasuredarray1d_abs) (LabelledMeasuredArray1DHandle handle) <br> |
|  FArrayDoubleHandle | [**LabelledMeasuredArray1D\_as\_1D**](#function-labelledmeasuredarray1d_as_1d) (LabelledMeasuredArray1DHandle handle) <br> |
|  ConnectionHandle | [**LabelledMeasuredArray1D\_connection**](#function-labelledmeasuredarray1d_connection) (LabelledMeasuredArray1DHandle handle) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_copy**](#function-labelledmeasuredarray1d_copy) (LabelledMeasuredArray1DHandle handle) <br> |
|  size\_t | [**LabelledMeasuredArray1D\_data**](#function-labelledmeasuredarray1d_data) (LabelledMeasuredArray1DHandle handle, double \* out\_buffer, size\_t numdata) <br> |
|  void | [**LabelledMeasuredArray1D\_destroy**](#function-labelledmeasuredarray1d_destroy) (LabelledMeasuredArray1DHandle handle) <br> |
|  size\_t | [**LabelledMeasuredArray1D\_dimension**](#function-labelledmeasuredarray1d_dimension) (LabelledMeasuredArray1DHandle handle) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_divides\_double**](#function-labelledmeasuredarray1d_divides_double) (LabelledMeasuredArray1DHandle handle, double other) <br> |
|  void | [**LabelledMeasuredArray1D\_divides\_equals\_double**](#function-labelledmeasuredarray1d_divides_equals_double) (LabelledMeasuredArray1DHandle handle, double other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_divides\_equals\_farray**](#function-labelledmeasuredarray1d_divides_equals_farray) (LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**LabelledMeasuredArray1D\_divides\_equals\_int**](#function-labelledmeasuredarray1d_divides_equals_int) (LabelledMeasuredArray1DHandle handle, int other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_divides\_equals\_measured\_array**](#function-labelledmeasuredarray1d_divides_equals_measured_array) (LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_divides\_farray**](#function-labelledmeasuredarray1d_divides_farray) (LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_divides\_int**](#function-labelledmeasuredarray1d_divides_int) (LabelledMeasuredArray1DHandle handle, int other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_divides\_measured\_array**](#function-labelledmeasuredarray1d_divides_measured_array) (LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) <br> |
|  bool | [**LabelledMeasuredArray1D\_equal**](#function-labelledmeasuredarray1d_equal) (LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) <br> |
|  ListFArrayDoubleHandle | [**LabelledMeasuredArray1D\_even\_divisions**](#function-labelledmeasuredarray1d_even_divisions) (LabelledMeasuredArray1DHandle handle, size\_t divisions) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_flip**](#function-labelledmeasuredarray1d_flip) (LabelledMeasuredArray1DHandle handle, size\_t axis) <br>_Flip the data along the given axis._  |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_from\_farray**](#function-labelledmeasuredarray1d_from_farray) (FArrayDoubleHandle farray, AcquisitionContextHandle label) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_from\_json\_string**](#function-labelledmeasuredarray1d_from_json_string) (StringHandle json) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_from\_measured\_array**](#function-labelledmeasuredarray1d_from_measured_array) (MeasuredArrayHandle measuredarray, AcquisitionContextHandle label) <br> |
|  size\_t | [**LabelledMeasuredArray1D\_full\_gradient**](#function-labelledmeasuredarray1d_full_gradient) (LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  size\_t | [**LabelledMeasuredArray1D\_get\_closest\_index**](#function-labelledmeasuredarray1d_get_closest_index) (LabelledMeasuredArray1DHandle handle, double value) <br> |
|  double | [**LabelledMeasuredArray1D\_get\_distance**](#function-labelledmeasuredarray1d_get_distance) (LabelledMeasuredArray1DHandle handle) <br> |
|  double | [**LabelledMeasuredArray1D\_get\_end**](#function-labelledmeasuredarray1d_get_end) (LabelledMeasuredArray1DHandle handle) <br> |
|  double | [**LabelledMeasuredArray1D\_get\_mean**](#function-labelledmeasuredarray1d_get_mean) (LabelledMeasuredArray1DHandle handle) <br> |
|  double | [**LabelledMeasuredArray1D\_get\_start**](#function-labelledmeasuredarray1d_get_start) (LabelledMeasuredArray1DHandle handle) <br> |
|  double | [**LabelledMeasuredArray1D\_get\_std**](#function-labelledmeasuredarray1d_get_std) (LabelledMeasuredArray1DHandle handle) <br> |
|  double | [**LabelledMeasuredArray1D\_get\_sum\_of\_squares**](#function-labelledmeasuredarray1d_get_sum_of_squares) (LabelledMeasuredArray1DHandle handle) <br> |
|  double | [**LabelledMeasuredArray1D\_get\_summed\_diff\_array\_of\_squares**](#function-labelledmeasuredarray1d_get_summed_diff_array_of_squares) (LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) <br> |
|  double | [**LabelledMeasuredArray1D\_get\_summed\_diff\_double\_of\_squares**](#function-labelledmeasuredarray1d_get_summed_diff_double_of_squares) (LabelledMeasuredArray1DHandle handle, double other) <br> |
|  double | [**LabelledMeasuredArray1D\_get\_summed\_diff\_int\_of\_squares**](#function-labelledmeasuredarray1d_get_summed_diff_int_of_squares) (LabelledMeasuredArray1DHandle handle, int other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_gradient**](#function-labelledmeasuredarray1d_gradient) (LabelledMeasuredArray1DHandle handle, size\_t axis) <br>_Return the gradient of the data along a given axis. Computes the gradient along the specified axis using finite differences:_  |
|  bool | [**LabelledMeasuredArray1D\_greater\_than**](#function-labelledmeasuredarray1d_greater_than) (LabelledMeasuredArray1DHandle handle, double value) <br> |
|  StringHandle | [**LabelledMeasuredArray1D\_instrument\_type**](#function-labelledmeasuredarray1d_instrument_type) (LabelledMeasuredArray1DHandle handle) <br> |
|  bool | [**LabelledMeasuredArray1D\_is\_1D**](#function-labelledmeasuredarray1d_is_1d) (LabelledMeasuredArray1DHandle handle) <br> |
|  bool | [**LabelledMeasuredArray1D\_is\_decreasing**](#function-labelledmeasuredarray1d_is_decreasing) (LabelledMeasuredArray1DHandle handle) <br> |
|  bool | [**LabelledMeasuredArray1D\_is\_increasing**](#function-labelledmeasuredarray1d_is_increasing) (LabelledMeasuredArray1DHandle handle) <br> |
|  AcquisitionContextHandle | [**LabelledMeasuredArray1D\_label**](#function-labelledmeasuredarray1d_label) (LabelledMeasuredArray1DHandle handle) <br> |
|  bool | [**LabelledMeasuredArray1D\_less\_than**](#function-labelledmeasuredarray1d_less_than) (LabelledMeasuredArray1DHandle handle, double value) <br> |
|  double | [**LabelledMeasuredArray1D\_max**](#function-labelledmeasuredarray1d_max) (LabelledMeasuredArray1DHandle handle) <br>_Return the maximum value of the array._  |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_max\_farray**](#function-labelledmeasuredarray1d_max_farray) (LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_max\_measured\_array**](#function-labelledmeasuredarray1d_max_measured_array) (LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) <br> |
|  double | [**LabelledMeasuredArray1D\_min**](#function-labelledmeasuredarray1d_min) (LabelledMeasuredArray1DHandle handle) <br>_Return the minimum value of the array._  |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_min\_farray**](#function-labelledmeasuredarray1d_min_farray) (LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_min\_measured\_array**](#function-labelledmeasuredarray1d_min_measured_array) (LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_minus\_double**](#function-labelledmeasuredarray1d_minus_double) (LabelledMeasuredArray1DHandle handle, double other) <br> |
|  void | [**LabelledMeasuredArray1D\_minus\_equals\_double**](#function-labelledmeasuredarray1d_minus_equals_double) (LabelledMeasuredArray1DHandle handle, double other) <br> |
|  void | [**LabelledMeasuredArray1D\_minus\_equals\_farray**](#function-labelledmeasuredarray1d_minus_equals_farray) (LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**LabelledMeasuredArray1D\_minus\_equals\_int**](#function-labelledmeasuredarray1d_minus_equals_int) (LabelledMeasuredArray1DHandle handle, int other) <br> |
|  void | [**LabelledMeasuredArray1D\_minus\_equals\_measured\_array**](#function-labelledmeasuredarray1d_minus_equals_measured_array) (LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_minus\_farray**](#function-labelledmeasuredarray1d_minus_farray) (LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_minus\_int**](#function-labelledmeasuredarray1d_minus_int) (LabelledMeasuredArray1DHandle handle, int other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_minus\_measured\_array**](#function-labelledmeasuredarray1d_minus_measured_array) (LabelledMeasuredArray1DHandle handle, MeasuredArrayHandle other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_negation**](#function-labelledmeasuredarray1d_negation) (LabelledMeasuredArray1DHandle handle) <br> |
|  bool | [**LabelledMeasuredArray1D\_not\_equal**](#function-labelledmeasuredarray1d_not_equal) (LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_plus\_double**](#function-labelledmeasuredarray1d_plus_double) (LabelledMeasuredArray1DHandle handle, double other) <br> |
|  void | [**LabelledMeasuredArray1D\_plus\_equals\_double**](#function-labelledmeasuredarray1d_plus_equals_double) (LabelledMeasuredArray1DHandle handle, double other) <br> |
|  void | [**LabelledMeasuredArray1D\_plus\_equals\_farray**](#function-labelledmeasuredarray1d_plus_equals_farray) (LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**LabelledMeasuredArray1D\_plus\_equals\_int**](#function-labelledmeasuredarray1d_plus_equals_int) (LabelledMeasuredArray1DHandle handle, int other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_plus\_farray**](#function-labelledmeasuredarray1d_plus_farray) (LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_plus\_int**](#function-labelledmeasuredarray1d_plus_int) (LabelledMeasuredArray1DHandle handle, int other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_plus\_measured\_array**](#function-labelledmeasuredarray1d_plus_measured_array) (LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_pow**](#function-labelledmeasuredarray1d_pow) (LabelledMeasuredArray1DHandle handle, double other) <br> |
|  void | [**LabelledMeasuredArray1D\_remove\_offset**](#function-labelledmeasuredarray1d_remove_offset) (LabelledMeasuredArray1DHandle handle, double offset) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_reshape**](#function-labelledmeasuredarray1d_reshape) (LabelledMeasuredArray1DHandle handle, const size\_t \* shape, size\_t ndims) <br>_Return a new Array with the given shape._  |
|  void | [**LabelledMeasuredArray1D\_reverse**](#function-labelledmeasuredarray1d_reverse) (LabelledMeasuredArray1DHandle handle) <br> |
|  size\_t | [**LabelledMeasuredArray1D\_shape**](#function-labelledmeasuredarray1d_shape) (LabelledMeasuredArray1DHandle handle, size\_t \* out\_buffer, size\_t ndim) <br> |
|  size\_t | [**LabelledMeasuredArray1D\_size**](#function-labelledmeasuredarray1d_size) (LabelledMeasuredArray1DHandle handle) <br> |
|  double | [**LabelledMeasuredArray1D\_sum**](#function-labelledmeasuredarray1d_sum) (LabelledMeasuredArray1DHandle handle) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_times\_double**](#function-labelledmeasuredarray1d_times_double) (LabelledMeasuredArray1DHandle handle, double other) <br> |
|  void | [**LabelledMeasuredArray1D\_times\_equals\_double**](#function-labelledmeasuredarray1d_times_equals_double) (LabelledMeasuredArray1DHandle handle, double other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_times\_equals\_farray**](#function-labelledmeasuredarray1d_times_equals_farray) (LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**LabelledMeasuredArray1D\_times\_equals\_int**](#function-labelledmeasuredarray1d_times_equals_int) (LabelledMeasuredArray1DHandle handle, int other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_times\_equals\_measured\_array**](#function-labelledmeasuredarray1d_times_equals_measured_array) (LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_times\_farray**](#function-labelledmeasuredarray1d_times_farray) (LabelledMeasuredArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_times\_int**](#function-labelledmeasuredarray1d_times_int) (LabelledMeasuredArray1DHandle handle, int other) <br> |
|  LabelledMeasuredArray1DHandle | [**LabelledMeasuredArray1D\_times\_measured\_array**](#function-labelledmeasuredarray1d_times_measured_array) (LabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle other) <br> |
|  StringHandle | [**LabelledMeasuredArray1D\_to\_json\_string**](#function-labelledmeasuredarray1d_to_json_string) (LabelledMeasuredArray1DHandle handle) <br> |
|  SymbolUnitHandle | [**LabelledMeasuredArray1D\_units**](#function-labelledmeasuredarray1d_units) (LabelledMeasuredArray1DHandle handle) <br> |
|  ListListSizeTHandle | [**LabelledMeasuredArray1D\_where**](#function-labelledmeasuredarray1d_where) (LabelledMeasuredArray1DHandle handle, double value) <br> |




























## Public Types Documentation




### typedef LabelledMeasuredArray1DHandle 

```C++
typedef void* LabelledMeasuredArray1DHandle;
```




<hr>
## Public Functions Documentation




### function LabelledMeasuredArray1D\_abs 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_abs (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_as\_1D 

```C++
FArrayDoubleHandle LabelledMeasuredArray1D_as_1D (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_connection 

```C++
ConnectionHandle LabelledMeasuredArray1D_connection (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_copy 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_copy (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_data 

```C++
size_t LabelledMeasuredArray1D_data (
    LabelledMeasuredArray1DHandle handle,
    double * out_buffer,
    size_t numdata
) 
```




<hr>



### function LabelledMeasuredArray1D\_destroy 

```C++
void LabelledMeasuredArray1D_destroy (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_dimension 

```C++
size_t LabelledMeasuredArray1D_dimension (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_divides\_double 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_double (
    LabelledMeasuredArray1DHandle handle,
    double other
) 
```




<hr>



### function LabelledMeasuredArray1D\_divides\_equals\_double 

```C++
void LabelledMeasuredArray1D_divides_equals_double (
    LabelledMeasuredArray1DHandle handle,
    double other
) 
```




<hr>



### function LabelledMeasuredArray1D\_divides\_equals\_farray 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_equals_farray (
    LabelledMeasuredArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledMeasuredArray1D\_divides\_equals\_int 

```C++
void LabelledMeasuredArray1D_divides_equals_int (
    LabelledMeasuredArray1DHandle handle,
    int other
) 
```




<hr>



### function LabelledMeasuredArray1D\_divides\_equals\_measured\_array 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_equals_measured_array (
    LabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle other
) 
```




<hr>



### function LabelledMeasuredArray1D\_divides\_farray 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_farray (
    LabelledMeasuredArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledMeasuredArray1D\_divides\_int 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_int (
    LabelledMeasuredArray1DHandle handle,
    int other
) 
```




<hr>



### function LabelledMeasuredArray1D\_divides\_measured\_array 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_divides_measured_array (
    LabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle other
) 
```




<hr>



### function LabelledMeasuredArray1D\_equal 

```C++
bool LabelledMeasuredArray1D_equal (
    LabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle other
) 
```




<hr>



### function LabelledMeasuredArray1D\_even\_divisions 

```C++
ListFArrayDoubleHandle LabelledMeasuredArray1D_even_divisions (
    LabelledMeasuredArray1DHandle handle,
    size_t divisions
) 
```




<hr>



### function LabelledMeasuredArray1D\_flip 

_Flip the data along the given axis._ 
```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_flip (
    LabelledMeasuredArray1DHandle handle,
    size_t axis
) 
```





**Parameters:**


* `axis` The axis to flip. 



**Returns:**

A flipped LabelledMeasuredArray1D. 





        

<hr>



### function LabelledMeasuredArray1D\_from\_farray 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_from_farray (
    FArrayDoubleHandle farray,
    AcquisitionContextHandle label
) 
```




<hr>



### function LabelledMeasuredArray1D\_from\_json\_string 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_from_json_string (
    StringHandle json
) 
```




<hr>



### function LabelledMeasuredArray1D\_from\_measured\_array 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_from_measured_array (
    MeasuredArrayHandle measuredarray,
    AcquisitionContextHandle label
) 
```




<hr>



### function LabelledMeasuredArray1D\_full\_gradient 

```C++
size_t LabelledMeasuredArray1D_full_gradient (
    LabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function LabelledMeasuredArray1D\_get\_closest\_index 

```C++
size_t LabelledMeasuredArray1D_get_closest_index (
    LabelledMeasuredArray1DHandle handle,
    double value
) 
```




<hr>



### function LabelledMeasuredArray1D\_get\_distance 

```C++
double LabelledMeasuredArray1D_get_distance (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_get\_end 

```C++
double LabelledMeasuredArray1D_get_end (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_get\_mean 

```C++
double LabelledMeasuredArray1D_get_mean (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_get\_start 

```C++
double LabelledMeasuredArray1D_get_start (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_get\_std 

```C++
double LabelledMeasuredArray1D_get_std (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_get\_sum\_of\_squares 

```C++
double LabelledMeasuredArray1D_get_sum_of_squares (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_get\_summed\_diff\_array\_of\_squares 

```C++
double LabelledMeasuredArray1D_get_summed_diff_array_of_squares (
    LabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle other
) 
```




<hr>



### function LabelledMeasuredArray1D\_get\_summed\_diff\_double\_of\_squares 

```C++
double LabelledMeasuredArray1D_get_summed_diff_double_of_squares (
    LabelledMeasuredArray1DHandle handle,
    double other
) 
```




<hr>



### function LabelledMeasuredArray1D\_get\_summed\_diff\_int\_of\_squares 

```C++
double LabelledMeasuredArray1D_get_summed_diff_int_of_squares (
    LabelledMeasuredArray1DHandle handle,
    int other
) 
```




<hr>



### function LabelledMeasuredArray1D\_gradient 

_Return the gradient of the data along a given axis. Computes the gradient along the specified axis using finite differences:_ 
```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_gradient (
    LabelledMeasuredArray1DHandle handle,
    size_t axis
) 
```




* For interior points, uses central difference: (f(x+1) - f(x-1)) / 2
* For boundary points, uses forward (first element) or backward (last element) difference. 

**Parameters:**


  * `axis` The axis to compute the gradient. 



**Returns:**

The gradient FArray.


Return the gradient of the data along a given axis. Computes the gradient along the specified axis using finite differences:
* For interior points, uses central difference: (f(x+1) - f(x-1)) / 2
* For boundary points, uses forward (first element) or backward (last element) difference. 

**Parameters:**


  * `axis` The axis to compute the gradient. 



**Returns:**

The gradient FArray. 







        

<hr>



### function LabelledMeasuredArray1D\_greater\_than 

```C++
bool LabelledMeasuredArray1D_greater_than (
    LabelledMeasuredArray1DHandle handle,
    double value
) 
```




<hr>



### function LabelledMeasuredArray1D\_instrument\_type 

```C++
StringHandle LabelledMeasuredArray1D_instrument_type (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_is\_1D 

```C++
bool LabelledMeasuredArray1D_is_1D (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_is\_decreasing 

```C++
bool LabelledMeasuredArray1D_is_decreasing (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_is\_increasing 

```C++
bool LabelledMeasuredArray1D_is_increasing (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_label 

```C++
AcquisitionContextHandle LabelledMeasuredArray1D_label (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_less\_than 

```C++
bool LabelledMeasuredArray1D_less_than (
    LabelledMeasuredArray1DHandle handle,
    double value
) 
```




<hr>



### function LabelledMeasuredArray1D\_max 

_Return the maximum value of the array._ 
```C++
double LabelledMeasuredArray1D_max (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_max\_farray 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_max_farray (
    LabelledMeasuredArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledMeasuredArray1D\_max\_measured\_array 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_max_measured_array (
    LabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle other
) 
```




<hr>



### function LabelledMeasuredArray1D\_min 

_Return the minimum value of the array._ 
```C++
double LabelledMeasuredArray1D_min (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_min\_farray 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_min_farray (
    LabelledMeasuredArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledMeasuredArray1D\_min\_measured\_array 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_min_measured_array (
    LabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle other
) 
```




<hr>



### function LabelledMeasuredArray1D\_minus\_double 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_minus_double (
    LabelledMeasuredArray1DHandle handle,
    double other
) 
```




<hr>



### function LabelledMeasuredArray1D\_minus\_equals\_double 

```C++
void LabelledMeasuredArray1D_minus_equals_double (
    LabelledMeasuredArray1DHandle handle,
    double other
) 
```




<hr>



### function LabelledMeasuredArray1D\_minus\_equals\_farray 

```C++
void LabelledMeasuredArray1D_minus_equals_farray (
    LabelledMeasuredArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledMeasuredArray1D\_minus\_equals\_int 

```C++
void LabelledMeasuredArray1D_minus_equals_int (
    LabelledMeasuredArray1DHandle handle,
    int other
) 
```




<hr>



### function LabelledMeasuredArray1D\_minus\_equals\_measured\_array 

```C++
void LabelledMeasuredArray1D_minus_equals_measured_array (
    LabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle other
) 
```




<hr>



### function LabelledMeasuredArray1D\_minus\_farray 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_minus_farray (
    LabelledMeasuredArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledMeasuredArray1D\_minus\_int 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_minus_int (
    LabelledMeasuredArray1DHandle handle,
    int other
) 
```




<hr>



### function LabelledMeasuredArray1D\_minus\_measured\_array 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_minus_measured_array (
    LabelledMeasuredArray1DHandle handle,
    MeasuredArrayHandle other
) 
```




<hr>



### function LabelledMeasuredArray1D\_negation 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_negation (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_not\_equal 

```C++
bool LabelledMeasuredArray1D_not_equal (
    LabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle other
) 
```




<hr>



### function LabelledMeasuredArray1D\_plus\_double 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_plus_double (
    LabelledMeasuredArray1DHandle handle,
    double other
) 
```




<hr>



### function LabelledMeasuredArray1D\_plus\_equals\_double 

```C++
void LabelledMeasuredArray1D_plus_equals_double (
    LabelledMeasuredArray1DHandle handle,
    double other
) 
```




<hr>



### function LabelledMeasuredArray1D\_plus\_equals\_farray 

```C++
void LabelledMeasuredArray1D_plus_equals_farray (
    LabelledMeasuredArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledMeasuredArray1D\_plus\_equals\_int 

```C++
void LabelledMeasuredArray1D_plus_equals_int (
    LabelledMeasuredArray1DHandle handle,
    int other
) 
```




<hr>



### function LabelledMeasuredArray1D\_plus\_farray 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_plus_farray (
    LabelledMeasuredArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledMeasuredArray1D\_plus\_int 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_plus_int (
    LabelledMeasuredArray1DHandle handle,
    int other
) 
```




<hr>



### function LabelledMeasuredArray1D\_plus\_measured\_array 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_plus_measured_array (
    LabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle other
) 
```




<hr>



### function LabelledMeasuredArray1D\_pow 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_pow (
    LabelledMeasuredArray1DHandle handle,
    double other
) 
```




<hr>



### function LabelledMeasuredArray1D\_remove\_offset 

```C++
void LabelledMeasuredArray1D_remove_offset (
    LabelledMeasuredArray1DHandle handle,
    double offset
) 
```




<hr>



### function LabelledMeasuredArray1D\_reshape 

_Return a new Array with the given shape._ 
```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_reshape (
    LabelledMeasuredArray1DHandle handle,
    const size_t * shape,
    size_t ndims
) 
```





**Parameters:**


* `shape` The new shape. 



**Returns:**

A reshaped LabelledMeasuredArray1D. 





        

<hr>



### function LabelledMeasuredArray1D\_reverse 

```C++
void LabelledMeasuredArray1D_reverse (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_shape 

```C++
size_t LabelledMeasuredArray1D_shape (
    LabelledMeasuredArray1DHandle handle,
    size_t * out_buffer,
    size_t ndim
) 
```




<hr>



### function LabelledMeasuredArray1D\_size 

```C++
size_t LabelledMeasuredArray1D_size (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_sum 

```C++
double LabelledMeasuredArray1D_sum (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_times\_double 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_double (
    LabelledMeasuredArray1DHandle handle,
    double other
) 
```




<hr>



### function LabelledMeasuredArray1D\_times\_equals\_double 

```C++
void LabelledMeasuredArray1D_times_equals_double (
    LabelledMeasuredArray1DHandle handle,
    double other
) 
```




<hr>



### function LabelledMeasuredArray1D\_times\_equals\_farray 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_equals_farray (
    LabelledMeasuredArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledMeasuredArray1D\_times\_equals\_int 

```C++
void LabelledMeasuredArray1D_times_equals_int (
    LabelledMeasuredArray1DHandle handle,
    int other
) 
```




<hr>



### function LabelledMeasuredArray1D\_times\_equals\_measured\_array 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_equals_measured_array (
    LabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle other
) 
```




<hr>



### function LabelledMeasuredArray1D\_times\_farray 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_farray (
    LabelledMeasuredArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledMeasuredArray1D\_times\_int 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_int (
    LabelledMeasuredArray1DHandle handle,
    int other
) 
```




<hr>



### function LabelledMeasuredArray1D\_times\_measured\_array 

```C++
LabelledMeasuredArray1DHandle LabelledMeasuredArray1D_times_measured_array (
    LabelledMeasuredArray1DHandle handle,
    LabelledMeasuredArray1DHandle other
) 
```




<hr>



### function LabelledMeasuredArray1D\_to\_json\_string 

```C++
StringHandle LabelledMeasuredArray1D_to_json_string (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_units 

```C++
SymbolUnitHandle LabelledMeasuredArray1D_units (
    LabelledMeasuredArray1DHandle handle
) 
```




<hr>



### function LabelledMeasuredArray1D\_where 

```C++
ListListSizeTHandle LabelledMeasuredArray1D_where (
    LabelledMeasuredArray1DHandle handle,
    double value
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/arrays/LabelledMeasuredArray1D_c_api.h`

