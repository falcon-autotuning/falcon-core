

# File MeasuredArray\_c\_api.h



[**FileList**](files.md) **>** [**arrays**](dir_bfe73c8db2db54615e75c4ba09b4f73a.md) **>** [**MeasuredArray\_c\_api.h**](MeasuredArray__c__api_8h.md)

[Go to the source code of this file](MeasuredArray__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include "falcon_core/generic/FArrayDouble_c_api.h"`
* `#include "falcon_core/generic/ListListSizeT_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**MeasuredArrayHandle**](#typedef-measuredarrayhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  MeasuredArrayHandle | [**MeasuredArray\_abs**](#function-measuredarray_abs) (MeasuredArrayHandle handle) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_copy**](#function-measuredarray_copy) (MeasuredArrayHandle handle) <br> |
|  size\_t | [**MeasuredArray\_data**](#function-measuredarray_data) (MeasuredArrayHandle handle, double \* out\_buffer, size\_t numdata) <br> |
|  void | [**MeasuredArray\_destroy**](#function-measuredarray_destroy) (MeasuredArrayHandle handle) <br> |
|  size\_t | [**MeasuredArray\_dimension**](#function-measuredarray_dimension) (MeasuredArrayHandle handle) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_divides\_double**](#function-measuredarray_divides_double) (MeasuredArrayHandle handle, double other) <br> |
|  void | [**MeasuredArray\_divides\_equals\_double**](#function-measuredarray_divides_equals_double) (MeasuredArrayHandle handle, double other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_divides\_equals\_farray**](#function-measuredarray_divides_equals_farray) (MeasuredArrayHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**MeasuredArray\_divides\_equals\_int**](#function-measuredarray_divides_equals_int) (MeasuredArrayHandle handle, int other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_divides\_equals\_measured\_array**](#function-measuredarray_divides_equals_measured_array) (MeasuredArrayHandle handle, MeasuredArrayHandle other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_divides\_farray**](#function-measuredarray_divides_farray) (MeasuredArrayHandle handle, FArrayDoubleHandle other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_divides\_int**](#function-measuredarray_divides_int) (MeasuredArrayHandle handle, int other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_divides\_measured\_array**](#function-measuredarray_divides_measured_array) (MeasuredArrayHandle handle, MeasuredArrayHandle other) <br> |
|  bool | [**MeasuredArray\_equal**](#function-measuredarray_equal) (MeasuredArrayHandle handle, MeasuredArrayHandle other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_flip**](#function-measuredarray_flip) (MeasuredArrayHandle handle, size\_t axis) <br>_Flip the data along the given axis._  |
|  MeasuredArrayHandle | [**MeasuredArray\_from\_data**](#function-measuredarray_from_data) (const double \* data, const size\_t \* shape, size\_t ndim) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_from\_farray**](#function-measuredarray_from_farray) (FArrayDoubleHandle farray) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_from\_json\_string**](#function-measuredarray_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**MeasuredArray\_full\_gradient**](#function-measuredarray_full_gradient) (MeasuredArrayHandle handle, MeasuredArrayHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  double | [**MeasuredArray\_get\_sum\_of\_squares**](#function-measuredarray_get_sum_of_squares) (MeasuredArrayHandle handle) <br> |
|  double | [**MeasuredArray\_get\_summed\_diff\_array\_of\_squares**](#function-measuredarray_get_summed_diff_array_of_squares) (MeasuredArrayHandle handle, MeasuredArrayHandle other) <br> |
|  double | [**MeasuredArray\_get\_summed\_diff\_double\_of\_squares**](#function-measuredarray_get_summed_diff_double_of_squares) (MeasuredArrayHandle handle, double other) <br> |
|  double | [**MeasuredArray\_get\_summed\_diff\_int\_of\_squares**](#function-measuredarray_get_summed_diff_int_of_squares) (MeasuredArrayHandle handle, int other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_gradient**](#function-measuredarray_gradient) (MeasuredArrayHandle handle, size\_t axis) <br>_Return the gradient of the data along a given axis. Computes the gradient along the specified axis using finite differences:_  |
|  bool | [**MeasuredArray\_greater\_than**](#function-measuredarray_greater_than) (MeasuredArrayHandle handle, double value) <br> |
|  bool | [**MeasuredArray\_less\_than**](#function-measuredarray_less_than) (MeasuredArrayHandle handle, double value) <br> |
|  double | [**MeasuredArray\_max**](#function-measuredarray_max) (MeasuredArrayHandle handle) <br>_Return the maximum value of the array._  |
|  MeasuredArrayHandle | [**MeasuredArray\_max\_farray**](#function-measuredarray_max_farray) (MeasuredArrayHandle handle, FArrayDoubleHandle other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_max\_measured\_array**](#function-measuredarray_max_measured_array) (MeasuredArrayHandle handle, MeasuredArrayHandle other) <br> |
|  double | [**MeasuredArray\_min**](#function-measuredarray_min) (MeasuredArrayHandle handle) <br>_Return the minimum value of the array._  |
|  MeasuredArrayHandle | [**MeasuredArray\_min\_farray**](#function-measuredarray_min_farray) (MeasuredArrayHandle handle, FArrayDoubleHandle other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_min\_measured\_array**](#function-measuredarray_min_measured_array) (MeasuredArrayHandle handle, MeasuredArrayHandle other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_minus\_double**](#function-measuredarray_minus_double) (MeasuredArrayHandle handle, double other) <br> |
|  void | [**MeasuredArray\_minus\_equals\_double**](#function-measuredarray_minus_equals_double) (MeasuredArrayHandle handle, double other) <br> |
|  void | [**MeasuredArray\_minus\_equals\_farray**](#function-measuredarray_minus_equals_farray) (MeasuredArrayHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**MeasuredArray\_minus\_equals\_int**](#function-measuredarray_minus_equals_int) (MeasuredArrayHandle handle, int other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_minus\_farray**](#function-measuredarray_minus_farray) (MeasuredArrayHandle handle, FArrayDoubleHandle other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_minus\_int**](#function-measuredarray_minus_int) (MeasuredArrayHandle handle, int other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_minus\_measured\_array**](#function-measuredarray_minus_measured_array) (MeasuredArrayHandle handle, MeasuredArrayHandle other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_negation**](#function-measuredarray_negation) (MeasuredArrayHandle handle) <br> |
|  bool | [**MeasuredArray\_not\_equal**](#function-measuredarray_not_equal) (MeasuredArrayHandle handle, MeasuredArrayHandle other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_plus\_double**](#function-measuredarray_plus_double) (MeasuredArrayHandle handle, double other) <br> |
|  void | [**MeasuredArray\_plus\_equals\_double**](#function-measuredarray_plus_equals_double) (MeasuredArrayHandle handle, double other) <br> |
|  void | [**MeasuredArray\_plus\_equals\_farray**](#function-measuredarray_plus_equals_farray) (MeasuredArrayHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**MeasuredArray\_plus\_equals\_int**](#function-measuredarray_plus_equals_int) (MeasuredArrayHandle handle, int other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_plus\_farray**](#function-measuredarray_plus_farray) (MeasuredArrayHandle handle, FArrayDoubleHandle other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_plus\_int**](#function-measuredarray_plus_int) (MeasuredArrayHandle handle, int other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_plus\_measured\_array**](#function-measuredarray_plus_measured_array) (MeasuredArrayHandle handle, MeasuredArrayHandle other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_pow**](#function-measuredarray_pow) (MeasuredArrayHandle handle, double other) <br> |
|  void | [**MeasuredArray\_remove\_offset**](#function-measuredarray_remove_offset) (MeasuredArrayHandle handle, double offset) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_reshape**](#function-measuredarray_reshape) (MeasuredArrayHandle handle, const size\_t \* shape, size\_t ndims) <br>_Return a new Array with the given shape._  |
|  size\_t | [**MeasuredArray\_shape**](#function-measuredarray_shape) (MeasuredArrayHandle handle, size\_t \* out\_buffer, size\_t ndim) <br> |
|  size\_t | [**MeasuredArray\_size**](#function-measuredarray_size) (MeasuredArrayHandle handle) <br> |
|  double | [**MeasuredArray\_sum**](#function-measuredarray_sum) (MeasuredArrayHandle handle) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_times\_double**](#function-measuredarray_times_double) (MeasuredArrayHandle handle, double other) <br> |
|  void | [**MeasuredArray\_times\_equals\_double**](#function-measuredarray_times_equals_double) (MeasuredArrayHandle handle, double other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_times\_equals\_farray**](#function-measuredarray_times_equals_farray) (MeasuredArrayHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**MeasuredArray\_times\_equals\_int**](#function-measuredarray_times_equals_int) (MeasuredArrayHandle handle, int other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_times\_equals\_measured\_array**](#function-measuredarray_times_equals_measured_array) (MeasuredArrayHandle handle, MeasuredArrayHandle other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_times\_farray**](#function-measuredarray_times_farray) (MeasuredArrayHandle handle, FArrayDoubleHandle other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_times\_int**](#function-measuredarray_times_int) (MeasuredArrayHandle handle, int other) <br> |
|  MeasuredArrayHandle | [**MeasuredArray\_times\_measured\_array**](#function-measuredarray_times_measured_array) (MeasuredArrayHandle handle, MeasuredArrayHandle other) <br> |
|  [**StringHandle**](structstring.md) | [**MeasuredArray\_to\_json\_string**](#function-measuredarray_to_json_string) (MeasuredArrayHandle handle) <br> |
|  ListListSizeTHandle | [**MeasuredArray\_where**](#function-measuredarray_where) (MeasuredArrayHandle handle, double value) <br> |




























## Public Types Documentation




### typedef MeasuredArrayHandle 

```C++
typedef void* MeasuredArrayHandle;
```




<hr>
## Public Functions Documentation




### function MeasuredArray\_abs 

```C++
MeasuredArrayHandle MeasuredArray_abs (
    MeasuredArrayHandle handle
) 
```




<hr>



### function MeasuredArray\_copy 

```C++
MeasuredArrayHandle MeasuredArray_copy (
    MeasuredArrayHandle handle
) 
```




<hr>



### function MeasuredArray\_data 

```C++
size_t MeasuredArray_data (
    MeasuredArrayHandle handle,
    double * out_buffer,
    size_t numdata
) 
```




<hr>



### function MeasuredArray\_destroy 

```C++
void MeasuredArray_destroy (
    MeasuredArrayHandle handle
) 
```




<hr>



### function MeasuredArray\_dimension 

```C++
size_t MeasuredArray_dimension (
    MeasuredArrayHandle handle
) 
```




<hr>



### function MeasuredArray\_divides\_double 

```C++
MeasuredArrayHandle MeasuredArray_divides_double (
    MeasuredArrayHandle handle,
    double other
) 
```




<hr>



### function MeasuredArray\_divides\_equals\_double 

```C++
void MeasuredArray_divides_equals_double (
    MeasuredArrayHandle handle,
    double other
) 
```




<hr>



### function MeasuredArray\_divides\_equals\_farray 

```C++
MeasuredArrayHandle MeasuredArray_divides_equals_farray (
    MeasuredArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function MeasuredArray\_divides\_equals\_int 

```C++
void MeasuredArray_divides_equals_int (
    MeasuredArrayHandle handle,
    int other
) 
```




<hr>



### function MeasuredArray\_divides\_equals\_measured\_array 

```C++
MeasuredArrayHandle MeasuredArray_divides_equals_measured_array (
    MeasuredArrayHandle handle,
    MeasuredArrayHandle other
) 
```




<hr>



### function MeasuredArray\_divides\_farray 

```C++
MeasuredArrayHandle MeasuredArray_divides_farray (
    MeasuredArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function MeasuredArray\_divides\_int 

```C++
MeasuredArrayHandle MeasuredArray_divides_int (
    MeasuredArrayHandle handle,
    int other
) 
```




<hr>



### function MeasuredArray\_divides\_measured\_array 

```C++
MeasuredArrayHandle MeasuredArray_divides_measured_array (
    MeasuredArrayHandle handle,
    MeasuredArrayHandle other
) 
```




<hr>



### function MeasuredArray\_equal 

```C++
bool MeasuredArray_equal (
    MeasuredArrayHandle handle,
    MeasuredArrayHandle other
) 
```




<hr>



### function MeasuredArray\_flip 

_Flip the data along the given axis._ 
```C++
MeasuredArrayHandle MeasuredArray_flip (
    MeasuredArrayHandle handle,
    size_t axis
) 
```





**Parameters:**


* `axis` The axis to flip. 



**Returns:**

A flipped MeasuredArray. 





        

<hr>



### function MeasuredArray\_from\_data 

```C++
MeasuredArrayHandle MeasuredArray_from_data (
    const double * data,
    const size_t * shape,
    size_t ndim
) 
```




<hr>



### function MeasuredArray\_from\_farray 

```C++
MeasuredArrayHandle MeasuredArray_from_farray (
    FArrayDoubleHandle farray
) 
```




<hr>



### function MeasuredArray\_from\_json\_string 

```C++
MeasuredArrayHandle MeasuredArray_from_json_string (
    StringHandle json
) 
```




<hr>



### function MeasuredArray\_full\_gradient 

```C++
size_t MeasuredArray_full_gradient (
    MeasuredArrayHandle handle,
    MeasuredArrayHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function MeasuredArray\_get\_sum\_of\_squares 

```C++
double MeasuredArray_get_sum_of_squares (
    MeasuredArrayHandle handle
) 
```




<hr>



### function MeasuredArray\_get\_summed\_diff\_array\_of\_squares 

```C++
double MeasuredArray_get_summed_diff_array_of_squares (
    MeasuredArrayHandle handle,
    MeasuredArrayHandle other
) 
```




<hr>



### function MeasuredArray\_get\_summed\_diff\_double\_of\_squares 

```C++
double MeasuredArray_get_summed_diff_double_of_squares (
    MeasuredArrayHandle handle,
    double other
) 
```




<hr>



### function MeasuredArray\_get\_summed\_diff\_int\_of\_squares 

```C++
double MeasuredArray_get_summed_diff_int_of_squares (
    MeasuredArrayHandle handle,
    int other
) 
```




<hr>



### function MeasuredArray\_gradient 

_Return the gradient of the data along a given axis. Computes the gradient along the specified axis using finite differences:_ 
```C++
MeasuredArrayHandle MeasuredArray_gradient (
    MeasuredArrayHandle handle,
    size_t axis
) 
```




* For interior points, uses central difference: (f(x+1) - f(x-1)) / 2
* For boundary points, uses forward (first element) or backward (last element) difference. 

**Parameters:**


  * `axis` The axis to compute the gradient. 



**Returns:**

The gradient FArray. 







        

<hr>



### function MeasuredArray\_greater\_than 

```C++
bool MeasuredArray_greater_than (
    MeasuredArrayHandle handle,
    double value
) 
```




<hr>



### function MeasuredArray\_less\_than 

```C++
bool MeasuredArray_less_than (
    MeasuredArrayHandle handle,
    double value
) 
```




<hr>



### function MeasuredArray\_max 

_Return the maximum value of the array._ 
```C++
double MeasuredArray_max (
    MeasuredArrayHandle handle
) 
```




<hr>



### function MeasuredArray\_max\_farray 

```C++
MeasuredArrayHandle MeasuredArray_max_farray (
    MeasuredArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function MeasuredArray\_max\_measured\_array 

```C++
MeasuredArrayHandle MeasuredArray_max_measured_array (
    MeasuredArrayHandle handle,
    MeasuredArrayHandle other
) 
```




<hr>



### function MeasuredArray\_min 

_Return the minimum value of the array._ 
```C++
double MeasuredArray_min (
    MeasuredArrayHandle handle
) 
```




<hr>



### function MeasuredArray\_min\_farray 

```C++
MeasuredArrayHandle MeasuredArray_min_farray (
    MeasuredArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function MeasuredArray\_min\_measured\_array 

```C++
MeasuredArrayHandle MeasuredArray_min_measured_array (
    MeasuredArrayHandle handle,
    MeasuredArrayHandle other
) 
```




<hr>



### function MeasuredArray\_minus\_double 

```C++
MeasuredArrayHandle MeasuredArray_minus_double (
    MeasuredArrayHandle handle,
    double other
) 
```




<hr>



### function MeasuredArray\_minus\_equals\_double 

```C++
void MeasuredArray_minus_equals_double (
    MeasuredArrayHandle handle,
    double other
) 
```




<hr>



### function MeasuredArray\_minus\_equals\_farray 

```C++
void MeasuredArray_minus_equals_farray (
    MeasuredArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function MeasuredArray\_minus\_equals\_int 

```C++
void MeasuredArray_minus_equals_int (
    MeasuredArrayHandle handle,
    int other
) 
```




<hr>



### function MeasuredArray\_minus\_farray 

```C++
MeasuredArrayHandle MeasuredArray_minus_farray (
    MeasuredArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function MeasuredArray\_minus\_int 

```C++
MeasuredArrayHandle MeasuredArray_minus_int (
    MeasuredArrayHandle handle,
    int other
) 
```




<hr>



### function MeasuredArray\_minus\_measured\_array 

```C++
MeasuredArrayHandle MeasuredArray_minus_measured_array (
    MeasuredArrayHandle handle,
    MeasuredArrayHandle other
) 
```




<hr>



### function MeasuredArray\_negation 

```C++
MeasuredArrayHandle MeasuredArray_negation (
    MeasuredArrayHandle handle
) 
```




<hr>



### function MeasuredArray\_not\_equal 

```C++
bool MeasuredArray_not_equal (
    MeasuredArrayHandle handle,
    MeasuredArrayHandle other
) 
```




<hr>



### function MeasuredArray\_plus\_double 

```C++
MeasuredArrayHandle MeasuredArray_plus_double (
    MeasuredArrayHandle handle,
    double other
) 
```




<hr>



### function MeasuredArray\_plus\_equals\_double 

```C++
void MeasuredArray_plus_equals_double (
    MeasuredArrayHandle handle,
    double other
) 
```




<hr>



### function MeasuredArray\_plus\_equals\_farray 

```C++
void MeasuredArray_plus_equals_farray (
    MeasuredArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function MeasuredArray\_plus\_equals\_int 

```C++
void MeasuredArray_plus_equals_int (
    MeasuredArrayHandle handle,
    int other
) 
```




<hr>



### function MeasuredArray\_plus\_farray 

```C++
MeasuredArrayHandle MeasuredArray_plus_farray (
    MeasuredArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function MeasuredArray\_plus\_int 

```C++
MeasuredArrayHandle MeasuredArray_plus_int (
    MeasuredArrayHandle handle,
    int other
) 
```




<hr>



### function MeasuredArray\_plus\_measured\_array 

```C++
MeasuredArrayHandle MeasuredArray_plus_measured_array (
    MeasuredArrayHandle handle,
    MeasuredArrayHandle other
) 
```




<hr>



### function MeasuredArray\_pow 

```C++
MeasuredArrayHandle MeasuredArray_pow (
    MeasuredArrayHandle handle,
    double other
) 
```




<hr>



### function MeasuredArray\_remove\_offset 

```C++
void MeasuredArray_remove_offset (
    MeasuredArrayHandle handle,
    double offset
) 
```




<hr>



### function MeasuredArray\_reshape 

_Return a new Array with the given shape._ 
```C++
MeasuredArrayHandle MeasuredArray_reshape (
    MeasuredArrayHandle handle,
    const size_t * shape,
    size_t ndims
) 
```





**Parameters:**


* `shape` The new shape. 



**Returns:**

A reshaped MeasuredArray. 





        

<hr>



### function MeasuredArray\_shape 

```C++
size_t MeasuredArray_shape (
    MeasuredArrayHandle handle,
    size_t * out_buffer,
    size_t ndim
) 
```




<hr>



### function MeasuredArray\_size 

```C++
size_t MeasuredArray_size (
    MeasuredArrayHandle handle
) 
```




<hr>



### function MeasuredArray\_sum 

```C++
double MeasuredArray_sum (
    MeasuredArrayHandle handle
) 
```




<hr>



### function MeasuredArray\_times\_double 

```C++
MeasuredArrayHandle MeasuredArray_times_double (
    MeasuredArrayHandle handle,
    double other
) 
```




<hr>



### function MeasuredArray\_times\_equals\_double 

```C++
void MeasuredArray_times_equals_double (
    MeasuredArrayHandle handle,
    double other
) 
```




<hr>



### function MeasuredArray\_times\_equals\_farray 

```C++
MeasuredArrayHandle MeasuredArray_times_equals_farray (
    MeasuredArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function MeasuredArray\_times\_equals\_int 

```C++
void MeasuredArray_times_equals_int (
    MeasuredArrayHandle handle,
    int other
) 
```




<hr>



### function MeasuredArray\_times\_equals\_measured\_array 

```C++
MeasuredArrayHandle MeasuredArray_times_equals_measured_array (
    MeasuredArrayHandle handle,
    MeasuredArrayHandle other
) 
```




<hr>



### function MeasuredArray\_times\_farray 

```C++
MeasuredArrayHandle MeasuredArray_times_farray (
    MeasuredArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function MeasuredArray\_times\_int 

```C++
MeasuredArrayHandle MeasuredArray_times_int (
    MeasuredArrayHandle handle,
    int other
) 
```




<hr>



### function MeasuredArray\_times\_measured\_array 

```C++
MeasuredArrayHandle MeasuredArray_times_measured_array (
    MeasuredArrayHandle handle,
    MeasuredArrayHandle other
) 
```




<hr>



### function MeasuredArray\_to\_json\_string 

```C++
StringHandle MeasuredArray_to_json_string (
    MeasuredArrayHandle handle
) 
```




<hr>



### function MeasuredArray\_where 

```C++
ListListSizeTHandle MeasuredArray_where (
    MeasuredArrayHandle handle,
    double value
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/arrays/MeasuredArray_c_api.h`

