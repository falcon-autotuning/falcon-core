

# File ControlArray1D\_c\_api.h



[**FileList**](files.md) **>** [**arrays**](dir_bfe73c8db2db54615e75c4ba09b4f73a.md) **>** [**ControlArray1D\_c\_api.h**](ControlArray1D__c__api_8h.md)

[Go to the source code of this file](ControlArray1D__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include "falcon_core/generic/FArrayDouble_c_api.h"`
* `#include "falcon_core/generic/ListFArrayDouble_c_api.h"`
* `#include "falcon_core/generic/ListListSizeT_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ControlArray1DHandle**](#typedef-controlarray1dhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ControlArray1DHandle | [**ControlArray1D\_abs**](#function-controlarray1d_abs) (ControlArray1DHandle handle) <br> |
|  FArrayDoubleHandle | [**ControlArray1D\_as\_1D**](#function-controlarray1d_as_1d) (ControlArray1DHandle handle) <br> |
|  ControlArray1DHandle | [**ControlArray1D\_copy**](#function-controlarray1d_copy) (ControlArray1DHandle handle) <br> |
|  size\_t | [**ControlArray1D\_data**](#function-controlarray1d_data) (ControlArray1DHandle handle, double \* out\_buffer, size\_t numdata) <br> |
|  void | [**ControlArray1D\_destroy**](#function-controlarray1d_destroy) (ControlArray1DHandle handle) <br> |
|  size\_t | [**ControlArray1D\_dimension**](#function-controlarray1d_dimension) (ControlArray1DHandle handle) <br> |
|  ControlArray1DHandle | [**ControlArray1D\_divides\_double**](#function-controlarray1d_divides_double) (ControlArray1DHandle handle, double other) <br> |
|  void | [**ControlArray1D\_divides\_equals\_double**](#function-controlarray1d_divides_equals_double) (ControlArray1DHandle handle, double other) <br> |
|  void | [**ControlArray1D\_divides\_equals\_int**](#function-controlarray1d_divides_equals_int) (ControlArray1DHandle handle, int other) <br> |
|  ControlArray1DHandle | [**ControlArray1D\_divides\_int**](#function-controlarray1d_divides_int) (ControlArray1DHandle handle, int other) <br> |
|  bool | [**ControlArray1D\_equal**](#function-controlarray1d_equal) (ControlArray1DHandle handle, ControlArray1DHandle other) <br> |
|  ListFArrayDoubleHandle | [**ControlArray1D\_even\_divisions**](#function-controlarray1d_even_divisions) (ControlArray1DHandle handle, size\_t divisions) <br> |
|  ControlArray1DHandle | [**ControlArray1D\_flip**](#function-controlarray1d_flip) (ControlArray1DHandle handle, size\_t axis) <br>_Flip the data along the given axis._  |
|  ControlArray1DHandle | [**ControlArray1D\_from\_data**](#function-controlarray1d_from_data) (const double \* data, const size\_t \* shape, size\_t ndim) <br> |
|  ControlArray1DHandle | [**ControlArray1D\_from\_farray**](#function-controlarray1d_from_farray) (FArrayDoubleHandle farray) <br> |
|  ControlArray1DHandle | [**ControlArray1D\_from\_json\_string**](#function-controlarray1d_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ControlArray1D\_full\_gradient**](#function-controlarray1d_full_gradient) (ControlArray1DHandle handle, FArrayDoubleHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  size\_t | [**ControlArray1D\_get\_closest\_index**](#function-controlarray1d_get_closest_index) (ControlArray1DHandle handle, double value) <br> |
|  double | [**ControlArray1D\_get\_distance**](#function-controlarray1d_get_distance) (ControlArray1DHandle handle) <br> |
|  double | [**ControlArray1D\_get\_end**](#function-controlarray1d_get_end) (ControlArray1DHandle handle) <br> |
|  double | [**ControlArray1D\_get\_mean**](#function-controlarray1d_get_mean) (ControlArray1DHandle handle) <br> |
|  double | [**ControlArray1D\_get\_start**](#function-controlarray1d_get_start) (ControlArray1DHandle handle) <br> |
|  double | [**ControlArray1D\_get\_std**](#function-controlarray1d_get_std) (ControlArray1DHandle handle) <br> |
|  double | [**ControlArray1D\_get\_sum\_of\_squares**](#function-controlarray1d_get_sum_of_squares) (ControlArray1DHandle handle) <br> |
|  double | [**ControlArray1D\_get\_summed\_diff\_array\_of\_squares**](#function-controlarray1d_get_summed_diff_array_of_squares) (ControlArray1DHandle handle, ControlArray1DHandle other) <br> |
|  double | [**ControlArray1D\_get\_summed\_diff\_double\_of\_squares**](#function-controlarray1d_get_summed_diff_double_of_squares) (ControlArray1DHandle handle, double other) <br> |
|  double | [**ControlArray1D\_get\_summed\_diff\_int\_of\_squares**](#function-controlarray1d_get_summed_diff_int_of_squares) (ControlArray1DHandle handle, int other) <br> |
|  FArrayDoubleHandle | [**ControlArray1D\_gradient**](#function-controlarray1d_gradient) (ControlArray1DHandle handle, size\_t axis) <br>_Return the gradient of the data along a given axis. Computes the gradient along the specified axis using finite differences:_  |
|  bool | [**ControlArray1D\_greater\_than**](#function-controlarray1d_greater_than) (ControlArray1DHandle handle, double value) <br> |
|  bool | [**ControlArray1D\_is\_1D**](#function-controlarray1d_is_1d) (ControlArray1DHandle handle) <br> |
|  bool | [**ControlArray1D\_is\_decreasing**](#function-controlarray1d_is_decreasing) (ControlArray1DHandle handle) <br> |
|  bool | [**ControlArray1D\_is\_increasing**](#function-controlarray1d_is_increasing) (ControlArray1DHandle handle) <br> |
|  bool | [**ControlArray1D\_less\_than**](#function-controlarray1d_less_than) (ControlArray1DHandle handle, double value) <br> |
|  double | [**ControlArray1D\_max**](#function-controlarray1d_max) (ControlArray1DHandle handle) <br>_Return the maximum value of the array._  |
|  ControlArray1DHandle | [**ControlArray1D\_max\_control\_array**](#function-controlarray1d_max_control_array) (ControlArray1DHandle handle, ControlArray1DHandle other) <br> |
|  ControlArray1DHandle | [**ControlArray1D\_max\_farray**](#function-controlarray1d_max_farray) (ControlArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  double | [**ControlArray1D\_min**](#function-controlarray1d_min) (ControlArray1DHandle handle) <br>_Return the minimum value of the array._  |
|  ControlArray1DHandle | [**ControlArray1D\_min\_control\_array**](#function-controlarray1d_min_control_array) (ControlArray1DHandle handle, ControlArray1DHandle other) <br> |
|  ControlArray1DHandle | [**ControlArray1D\_min\_farray**](#function-controlarray1d_min_farray) (ControlArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  ControlArray1DHandle | [**ControlArray1D\_minus\_control\_array**](#function-controlarray1d_minus_control_array) (ControlArray1DHandle handle, ControlArray1DHandle other) <br> |
|  ControlArray1DHandle | [**ControlArray1D\_minus\_double**](#function-controlarray1d_minus_double) (ControlArray1DHandle handle, double other) <br> |
|  void | [**ControlArray1D\_minus\_equals\_double**](#function-controlarray1d_minus_equals_double) (ControlArray1DHandle handle, double other) <br> |
|  void | [**ControlArray1D\_minus\_equals\_farray**](#function-controlarray1d_minus_equals_farray) (ControlArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**ControlArray1D\_minus\_equals\_int**](#function-controlarray1d_minus_equals_int) (ControlArray1DHandle handle, int other) <br> |
|  ControlArray1DHandle | [**ControlArray1D\_minus\_farray**](#function-controlarray1d_minus_farray) (ControlArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  ControlArray1DHandle | [**ControlArray1D\_minus\_int**](#function-controlarray1d_minus_int) (ControlArray1DHandle handle, int other) <br> |
|  ControlArray1DHandle | [**ControlArray1D\_negation**](#function-controlarray1d_negation) (ControlArray1DHandle handle) <br> |
|  bool | [**ControlArray1D\_not\_equal**](#function-controlarray1d_not_equal) (ControlArray1DHandle handle, ControlArray1DHandle other) <br> |
|  ControlArray1DHandle | [**ControlArray1D\_plus\_control\_array**](#function-controlarray1d_plus_control_array) (ControlArray1DHandle handle, ControlArray1DHandle other) <br> |
|  ControlArray1DHandle | [**ControlArray1D\_plus\_double**](#function-controlarray1d_plus_double) (ControlArray1DHandle handle, double other) <br> |
|  void | [**ControlArray1D\_plus\_equals\_double**](#function-controlarray1d_plus_equals_double) (ControlArray1DHandle handle, double other) <br> |
|  void | [**ControlArray1D\_plus\_equals\_farray**](#function-controlarray1d_plus_equals_farray) (ControlArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**ControlArray1D\_plus\_equals\_int**](#function-controlarray1d_plus_equals_int) (ControlArray1DHandle handle, int other) <br> |
|  ControlArray1DHandle | [**ControlArray1D\_plus\_farray**](#function-controlarray1d_plus_farray) (ControlArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  ControlArray1DHandle | [**ControlArray1D\_plus\_int**](#function-controlarray1d_plus_int) (ControlArray1DHandle handle, int other) <br> |
|  ControlArray1DHandle | [**ControlArray1D\_pow**](#function-controlarray1d_pow) (ControlArray1DHandle handle, double other) <br> |
|  void | [**ControlArray1D\_remove\_offset**](#function-controlarray1d_remove_offset) (ControlArray1DHandle handle, double offset) <br> |
|  void | [**ControlArray1D\_reverse**](#function-controlarray1d_reverse) (ControlArray1DHandle handle) <br> |
|  size\_t | [**ControlArray1D\_shape**](#function-controlarray1d_shape) (ControlArray1DHandle handle, size\_t \* out\_buffer, size\_t ndim) <br> |
|  size\_t | [**ControlArray1D\_size**](#function-controlarray1d_size) (ControlArray1DHandle handle) <br> |
|  double | [**ControlArray1D\_sum**](#function-controlarray1d_sum) (ControlArray1DHandle handle) <br> |
|  ControlArray1DHandle | [**ControlArray1D\_times\_double**](#function-controlarray1d_times_double) (ControlArray1DHandle handle, double other) <br> |
|  void | [**ControlArray1D\_times\_equals\_double**](#function-controlarray1d_times_equals_double) (ControlArray1DHandle handle, double other) <br> |
|  void | [**ControlArray1D\_times\_equals\_int**](#function-controlarray1d_times_equals_int) (ControlArray1DHandle handle, int other) <br> |
|  ControlArray1DHandle | [**ControlArray1D\_times\_int**](#function-controlarray1d_times_int) (ControlArray1DHandle handle, int other) <br> |
|  StringHandle | [**ControlArray1D\_to\_json\_string**](#function-controlarray1d_to_json_string) (ControlArray1DHandle handle) <br> |
|  ListListSizeTHandle | [**ControlArray1D\_where**](#function-controlarray1d_where) (ControlArray1DHandle handle, double value) <br> |




























## Public Types Documentation




### typedef ControlArray1DHandle 

```C++
typedef void* ControlArray1DHandle;
```




<hr>
## Public Functions Documentation




### function ControlArray1D\_abs 

```C++
ControlArray1DHandle ControlArray1D_abs (
    ControlArray1DHandle handle
) 
```




<hr>



### function ControlArray1D\_as\_1D 

```C++
FArrayDoubleHandle ControlArray1D_as_1D (
    ControlArray1DHandle handle
) 
```




<hr>



### function ControlArray1D\_copy 

```C++
ControlArray1DHandle ControlArray1D_copy (
    ControlArray1DHandle handle
) 
```




<hr>



### function ControlArray1D\_data 

```C++
size_t ControlArray1D_data (
    ControlArray1DHandle handle,
    double * out_buffer,
    size_t numdata
) 
```




<hr>



### function ControlArray1D\_destroy 

```C++
void ControlArray1D_destroy (
    ControlArray1DHandle handle
) 
```




<hr>



### function ControlArray1D\_dimension 

```C++
size_t ControlArray1D_dimension (
    ControlArray1DHandle handle
) 
```




<hr>



### function ControlArray1D\_divides\_double 

```C++
ControlArray1DHandle ControlArray1D_divides_double (
    ControlArray1DHandle handle,
    double other
) 
```




<hr>



### function ControlArray1D\_divides\_equals\_double 

```C++
void ControlArray1D_divides_equals_double (
    ControlArray1DHandle handle,
    double other
) 
```




<hr>



### function ControlArray1D\_divides\_equals\_int 

```C++
void ControlArray1D_divides_equals_int (
    ControlArray1DHandle handle,
    int other
) 
```




<hr>



### function ControlArray1D\_divides\_int 

```C++
ControlArray1DHandle ControlArray1D_divides_int (
    ControlArray1DHandle handle,
    int other
) 
```




<hr>



### function ControlArray1D\_equal 

```C++
bool ControlArray1D_equal (
    ControlArray1DHandle handle,
    ControlArray1DHandle other
) 
```




<hr>



### function ControlArray1D\_even\_divisions 

```C++
ListFArrayDoubleHandle ControlArray1D_even_divisions (
    ControlArray1DHandle handle,
    size_t divisions
) 
```




<hr>



### function ControlArray1D\_flip 

_Flip the data along the given axis._ 
```C++
ControlArray1DHandle ControlArray1D_flip (
    ControlArray1DHandle handle,
    size_t axis
) 
```





**Parameters:**


* `axis` The axis to flip. 



**Returns:**

A flipped ControlArray1D1D. 





        

<hr>



### function ControlArray1D\_from\_data 

```C++
ControlArray1DHandle ControlArray1D_from_data (
    const double * data,
    const size_t * shape,
    size_t ndim
) 
```




<hr>



### function ControlArray1D\_from\_farray 

```C++
ControlArray1DHandle ControlArray1D_from_farray (
    FArrayDoubleHandle farray
) 
```




<hr>



### function ControlArray1D\_from\_json\_string 

```C++
ControlArray1DHandle ControlArray1D_from_json_string (
    StringHandle json
) 
```




<hr>



### function ControlArray1D\_full\_gradient 

```C++
size_t ControlArray1D_full_gradient (
    ControlArray1DHandle handle,
    FArrayDoubleHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ControlArray1D\_get\_closest\_index 

```C++
size_t ControlArray1D_get_closest_index (
    ControlArray1DHandle handle,
    double value
) 
```




<hr>



### function ControlArray1D\_get\_distance 

```C++
double ControlArray1D_get_distance (
    ControlArray1DHandle handle
) 
```




<hr>



### function ControlArray1D\_get\_end 

```C++
double ControlArray1D_get_end (
    ControlArray1DHandle handle
) 
```




<hr>



### function ControlArray1D\_get\_mean 

```C++
double ControlArray1D_get_mean (
    ControlArray1DHandle handle
) 
```




<hr>



### function ControlArray1D\_get\_start 

```C++
double ControlArray1D_get_start (
    ControlArray1DHandle handle
) 
```




<hr>



### function ControlArray1D\_get\_std 

```C++
double ControlArray1D_get_std (
    ControlArray1DHandle handle
) 
```




<hr>



### function ControlArray1D\_get\_sum\_of\_squares 

```C++
double ControlArray1D_get_sum_of_squares (
    ControlArray1DHandle handle
) 
```




<hr>



### function ControlArray1D\_get\_summed\_diff\_array\_of\_squares 

```C++
double ControlArray1D_get_summed_diff_array_of_squares (
    ControlArray1DHandle handle,
    ControlArray1DHandle other
) 
```




<hr>



### function ControlArray1D\_get\_summed\_diff\_double\_of\_squares 

```C++
double ControlArray1D_get_summed_diff_double_of_squares (
    ControlArray1DHandle handle,
    double other
) 
```




<hr>



### function ControlArray1D\_get\_summed\_diff\_int\_of\_squares 

```C++
double ControlArray1D_get_summed_diff_int_of_squares (
    ControlArray1DHandle handle,
    int other
) 
```




<hr>



### function ControlArray1D\_gradient 

_Return the gradient of the data along a given axis. Computes the gradient along the specified axis using finite differences:_ 
```C++
FArrayDoubleHandle ControlArray1D_gradient (
    ControlArray1DHandle handle,
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



### function ControlArray1D\_greater\_than 

```C++
bool ControlArray1D_greater_than (
    ControlArray1DHandle handle,
    double value
) 
```




<hr>



### function ControlArray1D\_is\_1D 

```C++
bool ControlArray1D_is_1D (
    ControlArray1DHandle handle
) 
```




<hr>



### function ControlArray1D\_is\_decreasing 

```C++
bool ControlArray1D_is_decreasing (
    ControlArray1DHandle handle
) 
```




<hr>



### function ControlArray1D\_is\_increasing 

```C++
bool ControlArray1D_is_increasing (
    ControlArray1DHandle handle
) 
```




<hr>



### function ControlArray1D\_less\_than 

```C++
bool ControlArray1D_less_than (
    ControlArray1DHandle handle,
    double value
) 
```




<hr>



### function ControlArray1D\_max 

_Return the maximum value of the array._ 
```C++
double ControlArray1D_max (
    ControlArray1DHandle handle
) 
```




<hr>



### function ControlArray1D\_max\_control\_array 

```C++
ControlArray1DHandle ControlArray1D_max_control_array (
    ControlArray1DHandle handle,
    ControlArray1DHandle other
) 
```




<hr>



### function ControlArray1D\_max\_farray 

```C++
ControlArray1DHandle ControlArray1D_max_farray (
    ControlArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function ControlArray1D\_min 

_Return the minimum value of the array._ 
```C++
double ControlArray1D_min (
    ControlArray1DHandle handle
) 
```




<hr>



### function ControlArray1D\_min\_control\_array 

```C++
ControlArray1DHandle ControlArray1D_min_control_array (
    ControlArray1DHandle handle,
    ControlArray1DHandle other
) 
```




<hr>



### function ControlArray1D\_min\_farray 

```C++
ControlArray1DHandle ControlArray1D_min_farray (
    ControlArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function ControlArray1D\_minus\_control\_array 

```C++
ControlArray1DHandle ControlArray1D_minus_control_array (
    ControlArray1DHandle handle,
    ControlArray1DHandle other
) 
```




<hr>



### function ControlArray1D\_minus\_double 

```C++
ControlArray1DHandle ControlArray1D_minus_double (
    ControlArray1DHandle handle,
    double other
) 
```




<hr>



### function ControlArray1D\_minus\_equals\_double 

```C++
void ControlArray1D_minus_equals_double (
    ControlArray1DHandle handle,
    double other
) 
```




<hr>



### function ControlArray1D\_minus\_equals\_farray 

```C++
void ControlArray1D_minus_equals_farray (
    ControlArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function ControlArray1D\_minus\_equals\_int 

```C++
void ControlArray1D_minus_equals_int (
    ControlArray1DHandle handle,
    int other
) 
```




<hr>



### function ControlArray1D\_minus\_farray 

```C++
ControlArray1DHandle ControlArray1D_minus_farray (
    ControlArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function ControlArray1D\_minus\_int 

```C++
ControlArray1DHandle ControlArray1D_minus_int (
    ControlArray1DHandle handle,
    int other
) 
```




<hr>



### function ControlArray1D\_negation 

```C++
ControlArray1DHandle ControlArray1D_negation (
    ControlArray1DHandle handle
) 
```




<hr>



### function ControlArray1D\_not\_equal 

```C++
bool ControlArray1D_not_equal (
    ControlArray1DHandle handle,
    ControlArray1DHandle other
) 
```




<hr>



### function ControlArray1D\_plus\_control\_array 

```C++
ControlArray1DHandle ControlArray1D_plus_control_array (
    ControlArray1DHandle handle,
    ControlArray1DHandle other
) 
```




<hr>



### function ControlArray1D\_plus\_double 

```C++
ControlArray1DHandle ControlArray1D_plus_double (
    ControlArray1DHandle handle,
    double other
) 
```




<hr>



### function ControlArray1D\_plus\_equals\_double 

```C++
void ControlArray1D_plus_equals_double (
    ControlArray1DHandle handle,
    double other
) 
```




<hr>



### function ControlArray1D\_plus\_equals\_farray 

```C++
void ControlArray1D_plus_equals_farray (
    ControlArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function ControlArray1D\_plus\_equals\_int 

```C++
void ControlArray1D_plus_equals_int (
    ControlArray1DHandle handle,
    int other
) 
```




<hr>



### function ControlArray1D\_plus\_farray 

```C++
ControlArray1DHandle ControlArray1D_plus_farray (
    ControlArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function ControlArray1D\_plus\_int 

```C++
ControlArray1DHandle ControlArray1D_plus_int (
    ControlArray1DHandle handle,
    int other
) 
```




<hr>



### function ControlArray1D\_pow 

```C++
ControlArray1DHandle ControlArray1D_pow (
    ControlArray1DHandle handle,
    double other
) 
```




<hr>



### function ControlArray1D\_remove\_offset 

```C++
void ControlArray1D_remove_offset (
    ControlArray1DHandle handle,
    double offset
) 
```




<hr>



### function ControlArray1D\_reverse 

```C++
void ControlArray1D_reverse (
    ControlArray1DHandle handle
) 
```




<hr>



### function ControlArray1D\_shape 

```C++
size_t ControlArray1D_shape (
    ControlArray1DHandle handle,
    size_t * out_buffer,
    size_t ndim
) 
```




<hr>



### function ControlArray1D\_size 

```C++
size_t ControlArray1D_size (
    ControlArray1DHandle handle
) 
```




<hr>



### function ControlArray1D\_sum 

```C++
double ControlArray1D_sum (
    ControlArray1DHandle handle
) 
```




<hr>



### function ControlArray1D\_times\_double 

```C++
ControlArray1DHandle ControlArray1D_times_double (
    ControlArray1DHandle handle,
    double other
) 
```




<hr>



### function ControlArray1D\_times\_equals\_double 

```C++
void ControlArray1D_times_equals_double (
    ControlArray1DHandle handle,
    double other
) 
```




<hr>



### function ControlArray1D\_times\_equals\_int 

```C++
void ControlArray1D_times_equals_int (
    ControlArray1DHandle handle,
    int other
) 
```




<hr>



### function ControlArray1D\_times\_int 

```C++
ControlArray1DHandle ControlArray1D_times_int (
    ControlArray1DHandle handle,
    int other
) 
```




<hr>



### function ControlArray1D\_to\_json\_string 

```C++
StringHandle ControlArray1D_to_json_string (
    ControlArray1DHandle handle
) 
```




<hr>



### function ControlArray1D\_where 

```C++
ListListSizeTHandle ControlArray1D_where (
    ControlArray1DHandle handle,
    double value
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/arrays/ControlArray1D_c_api.h`

