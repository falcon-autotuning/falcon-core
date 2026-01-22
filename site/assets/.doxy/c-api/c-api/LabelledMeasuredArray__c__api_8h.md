

# File LabelledMeasuredArray\_c\_api.h



[**FileList**](files.md) **>** [**arrays**](dir_bfe73c8db2db54615e75c4ba09b4f73a.md) **>** [**LabelledMeasuredArray\_c\_api.h**](LabelledMeasuredArray__c__api_8h.md)

[Go to the source code of this file](LabelledMeasuredArray__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"`
* `#include "falcon_core/generic/FArrayDouble_c_api.h"`
* `#include "falcon_core/generic/ListListSizeT_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/math/arrays/MeasuredArray_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**LabelledMeasuredArrayHandle**](#typedef-labelledmeasuredarrayhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_abs**](#function-labelledmeasuredarray_abs) (LabelledMeasuredArrayHandle handle) <br> |
|  ConnectionHandle | [**LabelledMeasuredArray\_connection**](#function-labelledmeasuredarray_connection) (LabelledMeasuredArrayHandle handle) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_copy**](#function-labelledmeasuredarray_copy) (LabelledMeasuredArrayHandle handle) <br> |
|  size\_t | [**LabelledMeasuredArray\_data**](#function-labelledmeasuredarray_data) (LabelledMeasuredArrayHandle handle, double \* out\_buffer, size\_t numdata) <br> |
|  void | [**LabelledMeasuredArray\_destroy**](#function-labelledmeasuredarray_destroy) (LabelledMeasuredArrayHandle handle) <br> |
|  size\_t | [**LabelledMeasuredArray\_dimension**](#function-labelledmeasuredarray_dimension) (LabelledMeasuredArrayHandle handle) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_divides\_double**](#function-labelledmeasuredarray_divides_double) (LabelledMeasuredArrayHandle handle, double other) <br> |
|  void | [**LabelledMeasuredArray\_divides\_equals\_double**](#function-labelledmeasuredarray_divides_equals_double) (LabelledMeasuredArrayHandle handle, double other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_divides\_equals\_farray**](#function-labelledmeasuredarray_divides_equals_farray) (LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**LabelledMeasuredArray\_divides\_equals\_int**](#function-labelledmeasuredarray_divides_equals_int) (LabelledMeasuredArrayHandle handle, int other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_divides\_equals\_measured\_array**](#function-labelledmeasuredarray_divides_equals_measured_array) (LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_divides\_farray**](#function-labelledmeasuredarray_divides_farray) (LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_divides\_int**](#function-labelledmeasuredarray_divides_int) (LabelledMeasuredArrayHandle handle, int other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_divides\_measured\_array**](#function-labelledmeasuredarray_divides_measured_array) (LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other) <br> |
|  bool | [**LabelledMeasuredArray\_equal**](#function-labelledmeasuredarray_equal) (LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_flip**](#function-labelledmeasuredarray_flip) (LabelledMeasuredArrayHandle handle, size\_t axis) <br>_Flip the data along the given axis._  |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_from\_farray**](#function-labelledmeasuredarray_from_farray) (FArrayDoubleHandle farray, AcquisitionContextHandle label) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_from\_json\_string**](#function-labelledmeasuredarray_from_json_string) (StringHandle json) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_from\_measured\_array**](#function-labelledmeasuredarray_from_measured_array) (MeasuredArrayHandle measuredarray, AcquisitionContextHandle label) <br> |
|  size\_t | [**LabelledMeasuredArray\_full\_gradient**](#function-labelledmeasuredarray_full_gradient) (LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  double | [**LabelledMeasuredArray\_get\_sum\_of\_squares**](#function-labelledmeasuredarray_get_sum_of_squares) (LabelledMeasuredArrayHandle handle) <br> |
|  double | [**LabelledMeasuredArray\_get\_summed\_diff\_array\_of\_squares**](#function-labelledmeasuredarray_get_summed_diff_array_of_squares) (LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other) <br> |
|  double | [**LabelledMeasuredArray\_get\_summed\_diff\_double\_of\_squares**](#function-labelledmeasuredarray_get_summed_diff_double_of_squares) (LabelledMeasuredArrayHandle handle, double other) <br> |
|  double | [**LabelledMeasuredArray\_get\_summed\_diff\_int\_of\_squares**](#function-labelledmeasuredarray_get_summed_diff_int_of_squares) (LabelledMeasuredArrayHandle handle, int other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_gradient**](#function-labelledmeasuredarray_gradient) (LabelledMeasuredArrayHandle handle, size\_t axis) <br>_Return the gradient of the data along a given axis. Computes the gradient along the specified axis using finite differences:_  |
|  bool | [**LabelledMeasuredArray\_greater\_than**](#function-labelledmeasuredarray_greater_than) (LabelledMeasuredArrayHandle handle, double value) <br> |
|  StringHandle | [**LabelledMeasuredArray\_instrument\_type**](#function-labelledmeasuredarray_instrument_type) (LabelledMeasuredArrayHandle handle) <br> |
|  AcquisitionContextHandle | [**LabelledMeasuredArray\_label**](#function-labelledmeasuredarray_label) (LabelledMeasuredArrayHandle handle) <br> |
|  bool | [**LabelledMeasuredArray\_less\_than**](#function-labelledmeasuredarray_less_than) (LabelledMeasuredArrayHandle handle, double value) <br> |
|  double | [**LabelledMeasuredArray\_max**](#function-labelledmeasuredarray_max) (LabelledMeasuredArrayHandle handle) <br>_Return the maximum value of the array._  |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_max\_farray**](#function-labelledmeasuredarray_max_farray) (LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_max\_measured\_array**](#function-labelledmeasuredarray_max_measured_array) (LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other) <br> |
|  double | [**LabelledMeasuredArray\_min**](#function-labelledmeasuredarray_min) (LabelledMeasuredArrayHandle handle) <br>_Return the minimum value of the array._  |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_min\_farray**](#function-labelledmeasuredarray_min_farray) (LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_min\_measured\_array**](#function-labelledmeasuredarray_min_measured_array) (LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_minus\_double**](#function-labelledmeasuredarray_minus_double) (LabelledMeasuredArrayHandle handle, double other) <br> |
|  void | [**LabelledMeasuredArray\_minus\_equals\_double**](#function-labelledmeasuredarray_minus_equals_double) (LabelledMeasuredArrayHandle handle, double other) <br> |
|  void | [**LabelledMeasuredArray\_minus\_equals\_farray**](#function-labelledmeasuredarray_minus_equals_farray) (LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**LabelledMeasuredArray\_minus\_equals\_int**](#function-labelledmeasuredarray_minus_equals_int) (LabelledMeasuredArrayHandle handle, int other) <br> |
|  void | [**LabelledMeasuredArray\_minus\_equals\_measured\_array**](#function-labelledmeasuredarray_minus_equals_measured_array) (LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_minus\_farray**](#function-labelledmeasuredarray_minus_farray) (LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_minus\_int**](#function-labelledmeasuredarray_minus_int) (LabelledMeasuredArrayHandle handle, int other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_minus\_measured\_array**](#function-labelledmeasuredarray_minus_measured_array) (LabelledMeasuredArrayHandle handle, MeasuredArrayHandle other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_negation**](#function-labelledmeasuredarray_negation) (LabelledMeasuredArrayHandle handle) <br> |
|  bool | [**LabelledMeasuredArray\_not\_equal**](#function-labelledmeasuredarray_not_equal) (LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_plus\_double**](#function-labelledmeasuredarray_plus_double) (LabelledMeasuredArrayHandle handle, double other) <br> |
|  void | [**LabelledMeasuredArray\_plus\_equals\_double**](#function-labelledmeasuredarray_plus_equals_double) (LabelledMeasuredArrayHandle handle, double other) <br> |
|  void | [**LabelledMeasuredArray\_plus\_equals\_farray**](#function-labelledmeasuredarray_plus_equals_farray) (LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**LabelledMeasuredArray\_plus\_equals\_int**](#function-labelledmeasuredarray_plus_equals_int) (LabelledMeasuredArrayHandle handle, int other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_plus\_farray**](#function-labelledmeasuredarray_plus_farray) (LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_plus\_int**](#function-labelledmeasuredarray_plus_int) (LabelledMeasuredArrayHandle handle, int other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_plus\_measured\_array**](#function-labelledmeasuredarray_plus_measured_array) (LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_pow**](#function-labelledmeasuredarray_pow) (LabelledMeasuredArrayHandle handle, double other) <br> |
|  void | [**LabelledMeasuredArray\_remove\_offset**](#function-labelledmeasuredarray_remove_offset) (LabelledMeasuredArrayHandle handle, double offset) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_reshape**](#function-labelledmeasuredarray_reshape) (LabelledMeasuredArrayHandle handle, const size\_t \* shape, size\_t ndims) <br>_Return a new Array with the given shape._  |
|  size\_t | [**LabelledMeasuredArray\_shape**](#function-labelledmeasuredarray_shape) (LabelledMeasuredArrayHandle handle, size\_t \* out\_buffer, size\_t ndim) <br> |
|  size\_t | [**LabelledMeasuredArray\_size**](#function-labelledmeasuredarray_size) (LabelledMeasuredArrayHandle handle) <br> |
|  double | [**LabelledMeasuredArray\_sum**](#function-labelledmeasuredarray_sum) (LabelledMeasuredArrayHandle handle) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_times\_double**](#function-labelledmeasuredarray_times_double) (LabelledMeasuredArrayHandle handle, double other) <br> |
|  void | [**LabelledMeasuredArray\_times\_equals\_double**](#function-labelledmeasuredarray_times_equals_double) (LabelledMeasuredArrayHandle handle, double other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_times\_equals\_farray**](#function-labelledmeasuredarray_times_equals_farray) (LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**LabelledMeasuredArray\_times\_equals\_int**](#function-labelledmeasuredarray_times_equals_int) (LabelledMeasuredArrayHandle handle, int other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_times\_equals\_measured\_array**](#function-labelledmeasuredarray_times_equals_measured_array) (LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_times\_farray**](#function-labelledmeasuredarray_times_farray) (LabelledMeasuredArrayHandle handle, FArrayDoubleHandle other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_times\_int**](#function-labelledmeasuredarray_times_int) (LabelledMeasuredArrayHandle handle, int other) <br> |
|  LabelledMeasuredArrayHandle | [**LabelledMeasuredArray\_times\_measured\_array**](#function-labelledmeasuredarray_times_measured_array) (LabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle other) <br> |
|  StringHandle | [**LabelledMeasuredArray\_to\_json\_string**](#function-labelledmeasuredarray_to_json_string) (LabelledMeasuredArrayHandle handle) <br> |
|  SymbolUnitHandle | [**LabelledMeasuredArray\_units**](#function-labelledmeasuredarray_units) (LabelledMeasuredArrayHandle handle) <br> |
|  ListListSizeTHandle | [**LabelledMeasuredArray\_where**](#function-labelledmeasuredarray_where) (LabelledMeasuredArrayHandle handle, double value) <br> |




























## Public Types Documentation




### typedef LabelledMeasuredArrayHandle 

```C++
typedef void* LabelledMeasuredArrayHandle;
```




<hr>
## Public Functions Documentation




### function LabelledMeasuredArray\_abs 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_abs (
    LabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledMeasuredArray\_connection 

```C++
ConnectionHandle LabelledMeasuredArray_connection (
    LabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledMeasuredArray\_copy 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_copy (
    LabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledMeasuredArray\_data 

```C++
size_t LabelledMeasuredArray_data (
    LabelledMeasuredArrayHandle handle,
    double * out_buffer,
    size_t numdata
) 
```




<hr>



### function LabelledMeasuredArray\_destroy 

```C++
void LabelledMeasuredArray_destroy (
    LabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledMeasuredArray\_dimension 

```C++
size_t LabelledMeasuredArray_dimension (
    LabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledMeasuredArray\_divides\_double 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_divides_double (
    LabelledMeasuredArrayHandle handle,
    double other
) 
```




<hr>



### function LabelledMeasuredArray\_divides\_equals\_double 

```C++
void LabelledMeasuredArray_divides_equals_double (
    LabelledMeasuredArrayHandle handle,
    double other
) 
```




<hr>



### function LabelledMeasuredArray\_divides\_equals\_farray 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_divides_equals_farray (
    LabelledMeasuredArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledMeasuredArray\_divides\_equals\_int 

```C++
void LabelledMeasuredArray_divides_equals_int (
    LabelledMeasuredArrayHandle handle,
    int other
) 
```




<hr>



### function LabelledMeasuredArray\_divides\_equals\_measured\_array 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_divides_equals_measured_array (
    LabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle other
) 
```




<hr>



### function LabelledMeasuredArray\_divides\_farray 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_divides_farray (
    LabelledMeasuredArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledMeasuredArray\_divides\_int 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_divides_int (
    LabelledMeasuredArrayHandle handle,
    int other
) 
```




<hr>



### function LabelledMeasuredArray\_divides\_measured\_array 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_divides_measured_array (
    LabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle other
) 
```




<hr>



### function LabelledMeasuredArray\_equal 

```C++
bool LabelledMeasuredArray_equal (
    LabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle other
) 
```




<hr>



### function LabelledMeasuredArray\_flip 

_Flip the data along the given axis._ 
```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_flip (
    LabelledMeasuredArrayHandle handle,
    size_t axis
) 
```





**Parameters:**


* `axis` The axis to flip. 



**Returns:**

A flipped LabelledMeasuredArray. 





        

<hr>



### function LabelledMeasuredArray\_from\_farray 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_from_farray (
    FArrayDoubleHandle farray,
    AcquisitionContextHandle label
) 
```




<hr>



### function LabelledMeasuredArray\_from\_json\_string 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_from_json_string (
    StringHandle json
) 
```




<hr>



### function LabelledMeasuredArray\_from\_measured\_array 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_from_measured_array (
    MeasuredArrayHandle measuredarray,
    AcquisitionContextHandle label
) 
```




<hr>



### function LabelledMeasuredArray\_full\_gradient 

```C++
size_t LabelledMeasuredArray_full_gradient (
    LabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function LabelledMeasuredArray\_get\_sum\_of\_squares 

```C++
double LabelledMeasuredArray_get_sum_of_squares (
    LabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledMeasuredArray\_get\_summed\_diff\_array\_of\_squares 

```C++
double LabelledMeasuredArray_get_summed_diff_array_of_squares (
    LabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle other
) 
```




<hr>



### function LabelledMeasuredArray\_get\_summed\_diff\_double\_of\_squares 

```C++
double LabelledMeasuredArray_get_summed_diff_double_of_squares (
    LabelledMeasuredArrayHandle handle,
    double other
) 
```




<hr>



### function LabelledMeasuredArray\_get\_summed\_diff\_int\_of\_squares 

```C++
double LabelledMeasuredArray_get_summed_diff_int_of_squares (
    LabelledMeasuredArrayHandle handle,
    int other
) 
```




<hr>



### function LabelledMeasuredArray\_gradient 

_Return the gradient of the data along a given axis. Computes the gradient along the specified axis using finite differences:_ 
```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_gradient (
    LabelledMeasuredArrayHandle handle,
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



### function LabelledMeasuredArray\_greater\_than 

```C++
bool LabelledMeasuredArray_greater_than (
    LabelledMeasuredArrayHandle handle,
    double value
) 
```




<hr>



### function LabelledMeasuredArray\_instrument\_type 

```C++
StringHandle LabelledMeasuredArray_instrument_type (
    LabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledMeasuredArray\_label 

```C++
AcquisitionContextHandle LabelledMeasuredArray_label (
    LabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledMeasuredArray\_less\_than 

```C++
bool LabelledMeasuredArray_less_than (
    LabelledMeasuredArrayHandle handle,
    double value
) 
```




<hr>



### function LabelledMeasuredArray\_max 

_Return the maximum value of the array._ 
```C++
double LabelledMeasuredArray_max (
    LabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledMeasuredArray\_max\_farray 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_max_farray (
    LabelledMeasuredArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledMeasuredArray\_max\_measured\_array 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_max_measured_array (
    LabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle other
) 
```




<hr>



### function LabelledMeasuredArray\_min 

_Return the minimum value of the array._ 
```C++
double LabelledMeasuredArray_min (
    LabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledMeasuredArray\_min\_farray 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_min_farray (
    LabelledMeasuredArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledMeasuredArray\_min\_measured\_array 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_min_measured_array (
    LabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle other
) 
```




<hr>



### function LabelledMeasuredArray\_minus\_double 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_minus_double (
    LabelledMeasuredArrayHandle handle,
    double other
) 
```




<hr>



### function LabelledMeasuredArray\_minus\_equals\_double 

```C++
void LabelledMeasuredArray_minus_equals_double (
    LabelledMeasuredArrayHandle handle,
    double other
) 
```




<hr>



### function LabelledMeasuredArray\_minus\_equals\_farray 

```C++
void LabelledMeasuredArray_minus_equals_farray (
    LabelledMeasuredArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledMeasuredArray\_minus\_equals\_int 

```C++
void LabelledMeasuredArray_minus_equals_int (
    LabelledMeasuredArrayHandle handle,
    int other
) 
```




<hr>



### function LabelledMeasuredArray\_minus\_equals\_measured\_array 

```C++
void LabelledMeasuredArray_minus_equals_measured_array (
    LabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle other
) 
```




<hr>



### function LabelledMeasuredArray\_minus\_farray 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_minus_farray (
    LabelledMeasuredArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledMeasuredArray\_minus\_int 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_minus_int (
    LabelledMeasuredArrayHandle handle,
    int other
) 
```




<hr>



### function LabelledMeasuredArray\_minus\_measured\_array 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_minus_measured_array (
    LabelledMeasuredArrayHandle handle,
    MeasuredArrayHandle other
) 
```




<hr>



### function LabelledMeasuredArray\_negation 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_negation (
    LabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledMeasuredArray\_not\_equal 

```C++
bool LabelledMeasuredArray_not_equal (
    LabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle other
) 
```




<hr>



### function LabelledMeasuredArray\_plus\_double 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_plus_double (
    LabelledMeasuredArrayHandle handle,
    double other
) 
```




<hr>



### function LabelledMeasuredArray\_plus\_equals\_double 

```C++
void LabelledMeasuredArray_plus_equals_double (
    LabelledMeasuredArrayHandle handle,
    double other
) 
```




<hr>



### function LabelledMeasuredArray\_plus\_equals\_farray 

```C++
void LabelledMeasuredArray_plus_equals_farray (
    LabelledMeasuredArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledMeasuredArray\_plus\_equals\_int 

```C++
void LabelledMeasuredArray_plus_equals_int (
    LabelledMeasuredArrayHandle handle,
    int other
) 
```




<hr>



### function LabelledMeasuredArray\_plus\_farray 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_plus_farray (
    LabelledMeasuredArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledMeasuredArray\_plus\_int 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_plus_int (
    LabelledMeasuredArrayHandle handle,
    int other
) 
```




<hr>



### function LabelledMeasuredArray\_plus\_measured\_array 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_plus_measured_array (
    LabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle other
) 
```




<hr>



### function LabelledMeasuredArray\_pow 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_pow (
    LabelledMeasuredArrayHandle handle,
    double other
) 
```




<hr>



### function LabelledMeasuredArray\_remove\_offset 

```C++
void LabelledMeasuredArray_remove_offset (
    LabelledMeasuredArrayHandle handle,
    double offset
) 
```




<hr>



### function LabelledMeasuredArray\_reshape 

_Return a new Array with the given shape._ 
```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_reshape (
    LabelledMeasuredArrayHandle handle,
    const size_t * shape,
    size_t ndims
) 
```





**Parameters:**


* `shape` The new shape. 



**Returns:**

A reshaped LabelledMeasuredArray. 





        

<hr>



### function LabelledMeasuredArray\_shape 

```C++
size_t LabelledMeasuredArray_shape (
    LabelledMeasuredArrayHandle handle,
    size_t * out_buffer,
    size_t ndim
) 
```




<hr>



### function LabelledMeasuredArray\_size 

```C++
size_t LabelledMeasuredArray_size (
    LabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledMeasuredArray\_sum 

```C++
double LabelledMeasuredArray_sum (
    LabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledMeasuredArray\_times\_double 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_times_double (
    LabelledMeasuredArrayHandle handle,
    double other
) 
```




<hr>



### function LabelledMeasuredArray\_times\_equals\_double 

```C++
void LabelledMeasuredArray_times_equals_double (
    LabelledMeasuredArrayHandle handle,
    double other
) 
```




<hr>



### function LabelledMeasuredArray\_times\_equals\_farray 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_times_equals_farray (
    LabelledMeasuredArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledMeasuredArray\_times\_equals\_int 

```C++
void LabelledMeasuredArray_times_equals_int (
    LabelledMeasuredArrayHandle handle,
    int other
) 
```




<hr>



### function LabelledMeasuredArray\_times\_equals\_measured\_array 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_times_equals_measured_array (
    LabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle other
) 
```




<hr>



### function LabelledMeasuredArray\_times\_farray 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_times_farray (
    LabelledMeasuredArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledMeasuredArray\_times\_int 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_times_int (
    LabelledMeasuredArrayHandle handle,
    int other
) 
```




<hr>



### function LabelledMeasuredArray\_times\_measured\_array 

```C++
LabelledMeasuredArrayHandle LabelledMeasuredArray_times_measured_array (
    LabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle other
) 
```




<hr>



### function LabelledMeasuredArray\_to\_json\_string 

```C++
StringHandle LabelledMeasuredArray_to_json_string (
    LabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledMeasuredArray\_units 

```C++
SymbolUnitHandle LabelledMeasuredArray_units (
    LabelledMeasuredArrayHandle handle
) 
```




<hr>



### function LabelledMeasuredArray\_where 

```C++
ListListSizeTHandle LabelledMeasuredArray_where (
    LabelledMeasuredArrayHandle handle,
    double value
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/arrays/LabelledMeasuredArray_c_api.h`

