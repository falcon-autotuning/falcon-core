

# File MeasuredArray1D\_c\_api.h



[**FileList**](files.md) **>** [**arrays**](dir_bfe73c8db2db54615e75c4ba09b4f73a.md) **>** [**MeasuredArray1D\_c\_api.h**](MeasuredArray1D__c__api_8h.md)

[Go to the source code of this file](MeasuredArray1D__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include "falcon_core/generic/FArrayDouble_c_api.h"`
* `#include "falcon_core/generic/ListFArrayDouble_c_api.h"`
* `#include "falcon_core/generic/ListListSizeT_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**MeasuredArray1DHandle**](#typedef-measuredarray1dhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_abs**](#function-measuredarray1d_abs) (MeasuredArray1DHandle handle) <br> |
|  FArrayDoubleHandle | [**MeasuredArray1D\_as\_1D**](#function-measuredarray1d_as_1d) (MeasuredArray1DHandle handle) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_copy**](#function-measuredarray1d_copy) (MeasuredArray1DHandle handle) <br> |
|  size\_t | [**MeasuredArray1D\_data**](#function-measuredarray1d_data) (MeasuredArray1DHandle handle, double \* out\_buffer, size\_t numdata) <br> |
|  void | [**MeasuredArray1D\_destroy**](#function-measuredarray1d_destroy) (MeasuredArray1DHandle handle) <br> |
|  size\_t | [**MeasuredArray1D\_dimension**](#function-measuredarray1d_dimension) (MeasuredArray1DHandle handle) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_divides\_double**](#function-measuredarray1d_divides_double) (MeasuredArray1DHandle handle, double other) <br> |
|  void | [**MeasuredArray1D\_divides\_equals\_double**](#function-measuredarray1d_divides_equals_double) (MeasuredArray1DHandle handle, double other) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_divides\_equals\_farray**](#function-measuredarray1d_divides_equals_farray) (MeasuredArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**MeasuredArray1D\_divides\_equals\_int**](#function-measuredarray1d_divides_equals_int) (MeasuredArray1DHandle handle, int other) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_divides\_equals\_measured\_array**](#function-measuredarray1d_divides_equals_measured_array) (MeasuredArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_divides\_farray**](#function-measuredarray1d_divides_farray) (MeasuredArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_divides\_int**](#function-measuredarray1d_divides_int) (MeasuredArray1DHandle handle, int other) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_divides\_measured\_array**](#function-measuredarray1d_divides_measured_array) (MeasuredArray1DHandle handle, MeasuredArray1DHandle other) <br> |
|  bool | [**MeasuredArray1D\_equal**](#function-measuredarray1d_equal) (MeasuredArray1DHandle handle, MeasuredArray1DHandle other) <br> |
|  ListFArrayDoubleHandle | [**MeasuredArray1D\_even\_divisions**](#function-measuredarray1d_even_divisions) (MeasuredArray1DHandle handle, size\_t divisions) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_flip**](#function-measuredarray1d_flip) (MeasuredArray1DHandle handle, size\_t axis) <br>_Flip the data along the given axis._  |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_from\_data**](#function-measuredarray1d_from_data) (const double \* data, const size\_t \* shape, size\_t ndim) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_from\_farray**](#function-measuredarray1d_from_farray) (FArrayDoubleHandle farray) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_from\_json\_string**](#function-measuredarray1d_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**MeasuredArray1D\_full\_gradient**](#function-measuredarray1d_full_gradient) (MeasuredArray1DHandle handle, MeasuredArray1DHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  size\_t | [**MeasuredArray1D\_get\_closest\_index**](#function-measuredarray1d_get_closest_index) (MeasuredArray1DHandle handle, double value) <br> |
|  double | [**MeasuredArray1D\_get\_distance**](#function-measuredarray1d_get_distance) (MeasuredArray1DHandle handle) <br> |
|  double | [**MeasuredArray1D\_get\_end**](#function-measuredarray1d_get_end) (MeasuredArray1DHandle handle) <br> |
|  double | [**MeasuredArray1D\_get\_mean**](#function-measuredarray1d_get_mean) (MeasuredArray1DHandle handle) <br> |
|  double | [**MeasuredArray1D\_get\_start**](#function-measuredarray1d_get_start) (MeasuredArray1DHandle handle) <br> |
|  double | [**MeasuredArray1D\_get\_std**](#function-measuredarray1d_get_std) (MeasuredArray1DHandle handle) <br> |
|  double | [**MeasuredArray1D\_get\_sum\_of\_squares**](#function-measuredarray1d_get_sum_of_squares) (MeasuredArray1DHandle handle) <br> |
|  double | [**MeasuredArray1D\_get\_summed\_diff\_array\_of\_squares**](#function-measuredarray1d_get_summed_diff_array_of_squares) (MeasuredArray1DHandle handle, MeasuredArray1DHandle other) <br> |
|  double | [**MeasuredArray1D\_get\_summed\_diff\_double\_of\_squares**](#function-measuredarray1d_get_summed_diff_double_of_squares) (MeasuredArray1DHandle handle, double other) <br> |
|  double | [**MeasuredArray1D\_get\_summed\_diff\_int\_of\_squares**](#function-measuredarray1d_get_summed_diff_int_of_squares) (MeasuredArray1DHandle handle, int other) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_gradient**](#function-measuredarray1d_gradient) (MeasuredArray1DHandle handle, size\_t axis) <br>_Return the gradient of the data along a given axis. Computes the gradient along the specified axis using finite differences:_  |
|  bool | [**MeasuredArray1D\_greater\_than**](#function-measuredarray1d_greater_than) (MeasuredArray1DHandle handle, double value) <br> |
|  bool | [**MeasuredArray1D\_is\_1D**](#function-measuredarray1d_is_1d) (MeasuredArray1DHandle handle) <br> |
|  bool | [**MeasuredArray1D\_is\_decreasing**](#function-measuredarray1d_is_decreasing) (MeasuredArray1DHandle handle) <br> |
|  bool | [**MeasuredArray1D\_is\_increasing**](#function-measuredarray1d_is_increasing) (MeasuredArray1DHandle handle) <br> |
|  bool | [**MeasuredArray1D\_less\_than**](#function-measuredarray1d_less_than) (MeasuredArray1DHandle handle, double value) <br> |
|  double | [**MeasuredArray1D\_max**](#function-measuredarray1d_max) (MeasuredArray1DHandle handle) <br>_Return the maximum value of the array._  |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_max\_farray**](#function-measuredarray1d_max_farray) (MeasuredArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_max\_measured\_array**](#function-measuredarray1d_max_measured_array) (MeasuredArray1DHandle handle, MeasuredArray1DHandle other) <br> |
|  double | [**MeasuredArray1D\_min**](#function-measuredarray1d_min) (MeasuredArray1DHandle handle) <br>_Return the minimum value of the array._  |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_min\_farray**](#function-measuredarray1d_min_farray) (MeasuredArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_min\_measured\_array**](#function-measuredarray1d_min_measured_array) (MeasuredArray1DHandle handle, MeasuredArray1DHandle other) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_minus\_double**](#function-measuredarray1d_minus_double) (MeasuredArray1DHandle handle, double other) <br> |
|  void | [**MeasuredArray1D\_minus\_equals\_double**](#function-measuredarray1d_minus_equals_double) (MeasuredArray1DHandle handle, double other) <br> |
|  void | [**MeasuredArray1D\_minus\_equals\_farray**](#function-measuredarray1d_minus_equals_farray) (MeasuredArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**MeasuredArray1D\_minus\_equals\_int**](#function-measuredarray1d_minus_equals_int) (MeasuredArray1DHandle handle, int other) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_minus\_farray**](#function-measuredarray1d_minus_farray) (MeasuredArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_minus\_int**](#function-measuredarray1d_minus_int) (MeasuredArray1DHandle handle, int other) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_minus\_measured\_array**](#function-measuredarray1d_minus_measured_array) (MeasuredArray1DHandle handle, MeasuredArray1DHandle other) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_negation**](#function-measuredarray1d_negation) (MeasuredArray1DHandle handle) <br> |
|  bool | [**MeasuredArray1D\_not\_equal**](#function-measuredarray1d_not_equal) (MeasuredArray1DHandle handle, MeasuredArray1DHandle other) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_plus\_double**](#function-measuredarray1d_plus_double) (MeasuredArray1DHandle handle, double other) <br> |
|  void | [**MeasuredArray1D\_plus\_equals\_double**](#function-measuredarray1d_plus_equals_double) (MeasuredArray1DHandle handle, double other) <br> |
|  void | [**MeasuredArray1D\_plus\_equals\_farray**](#function-measuredarray1d_plus_equals_farray) (MeasuredArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**MeasuredArray1D\_plus\_equals\_int**](#function-measuredarray1d_plus_equals_int) (MeasuredArray1DHandle handle, int other) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_plus\_farray**](#function-measuredarray1d_plus_farray) (MeasuredArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_plus\_int**](#function-measuredarray1d_plus_int) (MeasuredArray1DHandle handle, int other) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_plus\_measured\_array**](#function-measuredarray1d_plus_measured_array) (MeasuredArray1DHandle handle, MeasuredArray1DHandle other) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_pow**](#function-measuredarray1d_pow) (MeasuredArray1DHandle handle, double other) <br> |
|  void | [**MeasuredArray1D\_remove\_offset**](#function-measuredarray1d_remove_offset) (MeasuredArray1DHandle handle, double offset) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_reshape**](#function-measuredarray1d_reshape) (MeasuredArray1DHandle handle, const size\_t \* shape, size\_t ndims) <br>_Return a new Array with the given shape._  |
|  void | [**MeasuredArray1D\_reverse**](#function-measuredarray1d_reverse) (MeasuredArray1DHandle handle) <br> |
|  size\_t | [**MeasuredArray1D\_shape**](#function-measuredarray1d_shape) (MeasuredArray1DHandle handle, size\_t \* out\_buffer, size\_t ndim) <br> |
|  size\_t | [**MeasuredArray1D\_size**](#function-measuredarray1d_size) (MeasuredArray1DHandle handle) <br> |
|  double | [**MeasuredArray1D\_sum**](#function-measuredarray1d_sum) (MeasuredArray1DHandle handle) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_times\_double**](#function-measuredarray1d_times_double) (MeasuredArray1DHandle handle, double other) <br> |
|  void | [**MeasuredArray1D\_times\_equals\_double**](#function-measuredarray1d_times_equals_double) (MeasuredArray1DHandle handle, double other) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_times\_equals\_farray**](#function-measuredarray1d_times_equals_farray) (MeasuredArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**MeasuredArray1D\_times\_equals\_int**](#function-measuredarray1d_times_equals_int) (MeasuredArray1DHandle handle, int other) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_times\_farray**](#function-measuredarray1d_times_farray) (MeasuredArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_times\_int**](#function-measuredarray1d_times_int) (MeasuredArray1DHandle handle, int other) <br> |
|  MeasuredArray1DHandle | [**MeasuredArray1D\_times\_measured\_array**](#function-measuredarray1d_times_measured_array) (MeasuredArray1DHandle handle, MeasuredArray1DHandle other) <br> |
|  [**StringHandle**](structstring.md) | [**MeasuredArray1D\_to\_json\_string**](#function-measuredarray1d_to_json_string) (MeasuredArray1DHandle handle) <br> |
|  ListListSizeTHandle | [**MeasuredArray1D\_where**](#function-measuredarray1d_where) (MeasuredArray1DHandle handle, double value) <br> |




























## Public Types Documentation




### typedef MeasuredArray1DHandle 

```C++
typedef void* MeasuredArray1DHandle;
```




<hr>
## Public Functions Documentation




### function MeasuredArray1D\_abs 

```C++
MeasuredArray1DHandle MeasuredArray1D_abs (
    MeasuredArray1DHandle handle
) 
```




<hr>



### function MeasuredArray1D\_as\_1D 

```C++
FArrayDoubleHandle MeasuredArray1D_as_1D (
    MeasuredArray1DHandle handle
) 
```




<hr>



### function MeasuredArray1D\_copy 

```C++
MeasuredArray1DHandle MeasuredArray1D_copy (
    MeasuredArray1DHandle handle
) 
```




<hr>



### function MeasuredArray1D\_data 

```C++
size_t MeasuredArray1D_data (
    MeasuredArray1DHandle handle,
    double * out_buffer,
    size_t numdata
) 
```




<hr>



### function MeasuredArray1D\_destroy 

```C++
void MeasuredArray1D_destroy (
    MeasuredArray1DHandle handle
) 
```




<hr>



### function MeasuredArray1D\_dimension 

```C++
size_t MeasuredArray1D_dimension (
    MeasuredArray1DHandle handle
) 
```




<hr>



### function MeasuredArray1D\_divides\_double 

```C++
MeasuredArray1DHandle MeasuredArray1D_divides_double (
    MeasuredArray1DHandle handle,
    double other
) 
```




<hr>



### function MeasuredArray1D\_divides\_equals\_double 

```C++
void MeasuredArray1D_divides_equals_double (
    MeasuredArray1DHandle handle,
    double other
) 
```




<hr>



### function MeasuredArray1D\_divides\_equals\_farray 

```C++
MeasuredArray1DHandle MeasuredArray1D_divides_equals_farray (
    MeasuredArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function MeasuredArray1D\_divides\_equals\_int 

```C++
void MeasuredArray1D_divides_equals_int (
    MeasuredArray1DHandle handle,
    int other
) 
```




<hr>



### function MeasuredArray1D\_divides\_equals\_measured\_array 

```C++
MeasuredArray1DHandle MeasuredArray1D_divides_equals_measured_array (
    MeasuredArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function MeasuredArray1D\_divides\_farray 

```C++
MeasuredArray1DHandle MeasuredArray1D_divides_farray (
    MeasuredArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function MeasuredArray1D\_divides\_int 

```C++
MeasuredArray1DHandle MeasuredArray1D_divides_int (
    MeasuredArray1DHandle handle,
    int other
) 
```




<hr>



### function MeasuredArray1D\_divides\_measured\_array 

```C++
MeasuredArray1DHandle MeasuredArray1D_divides_measured_array (
    MeasuredArray1DHandle handle,
    MeasuredArray1DHandle other
) 
```




<hr>



### function MeasuredArray1D\_equal 

```C++
bool MeasuredArray1D_equal (
    MeasuredArray1DHandle handle,
    MeasuredArray1DHandle other
) 
```




<hr>



### function MeasuredArray1D\_even\_divisions 

```C++
ListFArrayDoubleHandle MeasuredArray1D_even_divisions (
    MeasuredArray1DHandle handle,
    size_t divisions
) 
```




<hr>



### function MeasuredArray1D\_flip 

_Flip the data along the given axis._ 
```C++
MeasuredArray1DHandle MeasuredArray1D_flip (
    MeasuredArray1DHandle handle,
    size_t axis
) 
```





**Parameters:**


* `axis` The axis to flip. 



**Returns:**

A flipped MeasuredArray1D. 





        

<hr>



### function MeasuredArray1D\_from\_data 

```C++
MeasuredArray1DHandle MeasuredArray1D_from_data (
    const double * data,
    const size_t * shape,
    size_t ndim
) 
```




<hr>



### function MeasuredArray1D\_from\_farray 

```C++
MeasuredArray1DHandle MeasuredArray1D_from_farray (
    FArrayDoubleHandle farray
) 
```




<hr>



### function MeasuredArray1D\_from\_json\_string 

```C++
MeasuredArray1DHandle MeasuredArray1D_from_json_string (
    StringHandle json
) 
```




<hr>



### function MeasuredArray1D\_full\_gradient 

```C++
size_t MeasuredArray1D_full_gradient (
    MeasuredArray1DHandle handle,
    MeasuredArray1DHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function MeasuredArray1D\_get\_closest\_index 

```C++
size_t MeasuredArray1D_get_closest_index (
    MeasuredArray1DHandle handle,
    double value
) 
```




<hr>



### function MeasuredArray1D\_get\_distance 

```C++
double MeasuredArray1D_get_distance (
    MeasuredArray1DHandle handle
) 
```




<hr>



### function MeasuredArray1D\_get\_end 

```C++
double MeasuredArray1D_get_end (
    MeasuredArray1DHandle handle
) 
```




<hr>



### function MeasuredArray1D\_get\_mean 

```C++
double MeasuredArray1D_get_mean (
    MeasuredArray1DHandle handle
) 
```




<hr>



### function MeasuredArray1D\_get\_start 

```C++
double MeasuredArray1D_get_start (
    MeasuredArray1DHandle handle
) 
```




<hr>



### function MeasuredArray1D\_get\_std 

```C++
double MeasuredArray1D_get_std (
    MeasuredArray1DHandle handle
) 
```




<hr>



### function MeasuredArray1D\_get\_sum\_of\_squares 

```C++
double MeasuredArray1D_get_sum_of_squares (
    MeasuredArray1DHandle handle
) 
```




<hr>



### function MeasuredArray1D\_get\_summed\_diff\_array\_of\_squares 

```C++
double MeasuredArray1D_get_summed_diff_array_of_squares (
    MeasuredArray1DHandle handle,
    MeasuredArray1DHandle other
) 
```




<hr>



### function MeasuredArray1D\_get\_summed\_diff\_double\_of\_squares 

```C++
double MeasuredArray1D_get_summed_diff_double_of_squares (
    MeasuredArray1DHandle handle,
    double other
) 
```




<hr>



### function MeasuredArray1D\_get\_summed\_diff\_int\_of\_squares 

```C++
double MeasuredArray1D_get_summed_diff_int_of_squares (
    MeasuredArray1DHandle handle,
    int other
) 
```




<hr>



### function MeasuredArray1D\_gradient 

_Return the gradient of the data along a given axis. Computes the gradient along the specified axis using finite differences:_ 
```C++
MeasuredArray1DHandle MeasuredArray1D_gradient (
    MeasuredArray1DHandle handle,
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



### function MeasuredArray1D\_greater\_than 

```C++
bool MeasuredArray1D_greater_than (
    MeasuredArray1DHandle handle,
    double value
) 
```




<hr>



### function MeasuredArray1D\_is\_1D 

```C++
bool MeasuredArray1D_is_1D (
    MeasuredArray1DHandle handle
) 
```




<hr>



### function MeasuredArray1D\_is\_decreasing 

```C++
bool MeasuredArray1D_is_decreasing (
    MeasuredArray1DHandle handle
) 
```




<hr>



### function MeasuredArray1D\_is\_increasing 

```C++
bool MeasuredArray1D_is_increasing (
    MeasuredArray1DHandle handle
) 
```




<hr>



### function MeasuredArray1D\_less\_than 

```C++
bool MeasuredArray1D_less_than (
    MeasuredArray1DHandle handle,
    double value
) 
```




<hr>



### function MeasuredArray1D\_max 

_Return the maximum value of the array._ 
```C++
double MeasuredArray1D_max (
    MeasuredArray1DHandle handle
) 
```




<hr>



### function MeasuredArray1D\_max\_farray 

```C++
MeasuredArray1DHandle MeasuredArray1D_max_farray (
    MeasuredArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function MeasuredArray1D\_max\_measured\_array 

```C++
MeasuredArray1DHandle MeasuredArray1D_max_measured_array (
    MeasuredArray1DHandle handle,
    MeasuredArray1DHandle other
) 
```




<hr>



### function MeasuredArray1D\_min 

_Return the minimum value of the array._ 
```C++
double MeasuredArray1D_min (
    MeasuredArray1DHandle handle
) 
```




<hr>



### function MeasuredArray1D\_min\_farray 

```C++
MeasuredArray1DHandle MeasuredArray1D_min_farray (
    MeasuredArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function MeasuredArray1D\_min\_measured\_array 

```C++
MeasuredArray1DHandle MeasuredArray1D_min_measured_array (
    MeasuredArray1DHandle handle,
    MeasuredArray1DHandle other
) 
```




<hr>



### function MeasuredArray1D\_minus\_double 

```C++
MeasuredArray1DHandle MeasuredArray1D_minus_double (
    MeasuredArray1DHandle handle,
    double other
) 
```




<hr>



### function MeasuredArray1D\_minus\_equals\_double 

```C++
void MeasuredArray1D_minus_equals_double (
    MeasuredArray1DHandle handle,
    double other
) 
```




<hr>



### function MeasuredArray1D\_minus\_equals\_farray 

```C++
void MeasuredArray1D_minus_equals_farray (
    MeasuredArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function MeasuredArray1D\_minus\_equals\_int 

```C++
void MeasuredArray1D_minus_equals_int (
    MeasuredArray1DHandle handle,
    int other
) 
```




<hr>



### function MeasuredArray1D\_minus\_farray 

```C++
MeasuredArray1DHandle MeasuredArray1D_minus_farray (
    MeasuredArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function MeasuredArray1D\_minus\_int 

```C++
MeasuredArray1DHandle MeasuredArray1D_minus_int (
    MeasuredArray1DHandle handle,
    int other
) 
```




<hr>



### function MeasuredArray1D\_minus\_measured\_array 

```C++
MeasuredArray1DHandle MeasuredArray1D_minus_measured_array (
    MeasuredArray1DHandle handle,
    MeasuredArray1DHandle other
) 
```




<hr>



### function MeasuredArray1D\_negation 

```C++
MeasuredArray1DHandle MeasuredArray1D_negation (
    MeasuredArray1DHandle handle
) 
```




<hr>



### function MeasuredArray1D\_not\_equal 

```C++
bool MeasuredArray1D_not_equal (
    MeasuredArray1DHandle handle,
    MeasuredArray1DHandle other
) 
```




<hr>



### function MeasuredArray1D\_plus\_double 

```C++
MeasuredArray1DHandle MeasuredArray1D_plus_double (
    MeasuredArray1DHandle handle,
    double other
) 
```




<hr>



### function MeasuredArray1D\_plus\_equals\_double 

```C++
void MeasuredArray1D_plus_equals_double (
    MeasuredArray1DHandle handle,
    double other
) 
```




<hr>



### function MeasuredArray1D\_plus\_equals\_farray 

```C++
void MeasuredArray1D_plus_equals_farray (
    MeasuredArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function MeasuredArray1D\_plus\_equals\_int 

```C++
void MeasuredArray1D_plus_equals_int (
    MeasuredArray1DHandle handle,
    int other
) 
```




<hr>



### function MeasuredArray1D\_plus\_farray 

```C++
MeasuredArray1DHandle MeasuredArray1D_plus_farray (
    MeasuredArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function MeasuredArray1D\_plus\_int 

```C++
MeasuredArray1DHandle MeasuredArray1D_plus_int (
    MeasuredArray1DHandle handle,
    int other
) 
```




<hr>



### function MeasuredArray1D\_plus\_measured\_array 

```C++
MeasuredArray1DHandle MeasuredArray1D_plus_measured_array (
    MeasuredArray1DHandle handle,
    MeasuredArray1DHandle other
) 
```




<hr>



### function MeasuredArray1D\_pow 

```C++
MeasuredArray1DHandle MeasuredArray1D_pow (
    MeasuredArray1DHandle handle,
    double other
) 
```




<hr>



### function MeasuredArray1D\_remove\_offset 

```C++
void MeasuredArray1D_remove_offset (
    MeasuredArray1DHandle handle,
    double offset
) 
```




<hr>



### function MeasuredArray1D\_reshape 

_Return a new Array with the given shape._ 
```C++
MeasuredArray1DHandle MeasuredArray1D_reshape (
    MeasuredArray1DHandle handle,
    const size_t * shape,
    size_t ndims
) 
```





**Parameters:**


* `shape` The new shape. 



**Returns:**

A reshaped MeasuredArray1D. 





        

<hr>



### function MeasuredArray1D\_reverse 

```C++
void MeasuredArray1D_reverse (
    MeasuredArray1DHandle handle
) 
```




<hr>



### function MeasuredArray1D\_shape 

```C++
size_t MeasuredArray1D_shape (
    MeasuredArray1DHandle handle,
    size_t * out_buffer,
    size_t ndim
) 
```




<hr>



### function MeasuredArray1D\_size 

```C++
size_t MeasuredArray1D_size (
    MeasuredArray1DHandle handle
) 
```




<hr>



### function MeasuredArray1D\_sum 

```C++
double MeasuredArray1D_sum (
    MeasuredArray1DHandle handle
) 
```




<hr>



### function MeasuredArray1D\_times\_double 

```C++
MeasuredArray1DHandle MeasuredArray1D_times_double (
    MeasuredArray1DHandle handle,
    double other
) 
```




<hr>



### function MeasuredArray1D\_times\_equals\_double 

```C++
void MeasuredArray1D_times_equals_double (
    MeasuredArray1DHandle handle,
    double other
) 
```




<hr>



### function MeasuredArray1D\_times\_equals\_farray 

```C++
MeasuredArray1DHandle MeasuredArray1D_times_equals_farray (
    MeasuredArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function MeasuredArray1D\_times\_equals\_int 

```C++
void MeasuredArray1D_times_equals_int (
    MeasuredArray1DHandle handle,
    int other
) 
```




<hr>



### function MeasuredArray1D\_times\_farray 

```C++
MeasuredArray1DHandle MeasuredArray1D_times_farray (
    MeasuredArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function MeasuredArray1D\_times\_int 

```C++
MeasuredArray1DHandle MeasuredArray1D_times_int (
    MeasuredArray1DHandle handle,
    int other
) 
```




<hr>



### function MeasuredArray1D\_times\_measured\_array 

```C++
MeasuredArray1DHandle MeasuredArray1D_times_measured_array (
    MeasuredArray1DHandle handle,
    MeasuredArray1DHandle other
) 
```




<hr>



### function MeasuredArray1D\_to\_json\_string 

```C++
StringHandle MeasuredArray1D_to_json_string (
    MeasuredArray1DHandle handle
) 
```




<hr>



### function MeasuredArray1D\_where 

```C++
ListListSizeTHandle MeasuredArray1D_where (
    MeasuredArray1DHandle handle,
    double value
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/arrays/MeasuredArray1D_c_api.h`

