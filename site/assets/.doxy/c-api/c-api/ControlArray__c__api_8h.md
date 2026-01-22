

# File ControlArray\_c\_api.h



[**FileList**](files.md) **>** [**arrays**](dir_bfe73c8db2db54615e75c4ba09b4f73a.md) **>** [**ControlArray\_c\_api.h**](ControlArray__c__api_8h.md)

[Go to the source code of this file](ControlArray__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include "falcon_core/generic/FArrayDouble_c_api.h"`
* `#include "falcon_core/generic/ListListSizeT_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ControlArrayHandle**](#typedef-controlarrayhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ControlArrayHandle | [**ControlArray\_abs**](#function-controlarray_abs) (ControlArrayHandle handle) <br> |
|  ControlArrayHandle | [**ControlArray\_copy**](#function-controlarray_copy) (ControlArrayHandle handle) <br> |
|  size\_t | [**ControlArray\_data**](#function-controlarray_data) (ControlArrayHandle handle, double \* out\_buffer, size\_t numdata) <br> |
|  void | [**ControlArray\_destroy**](#function-controlarray_destroy) (ControlArrayHandle handle) <br> |
|  size\_t | [**ControlArray\_dimension**](#function-controlarray_dimension) (ControlArrayHandle handle) <br> |
|  ControlArrayHandle | [**ControlArray\_divides\_double**](#function-controlarray_divides_double) (ControlArrayHandle handle, double other) <br> |
|  void | [**ControlArray\_divides\_equals\_double**](#function-controlarray_divides_equals_double) (ControlArrayHandle handle, double other) <br> |
|  void | [**ControlArray\_divides\_equals\_int**](#function-controlarray_divides_equals_int) (ControlArrayHandle handle, int other) <br> |
|  ControlArrayHandle | [**ControlArray\_divides\_int**](#function-controlarray_divides_int) (ControlArrayHandle handle, int other) <br> |
|  bool | [**ControlArray\_equal**](#function-controlarray_equal) (ControlArrayHandle handle, ControlArrayHandle other) <br> |
|  ControlArrayHandle | [**ControlArray\_flip**](#function-controlarray_flip) (ControlArrayHandle handle, size\_t axis) <br>_Flip the data along the given axis._  |
|  ControlArrayHandle | [**ControlArray\_from\_data**](#function-controlarray_from_data) (const double \* data, const size\_t \* shape, size\_t ndim) <br> |
|  ControlArrayHandle | [**ControlArray\_from\_farray**](#function-controlarray_from_farray) (FArrayDoubleHandle farray) <br> |
|  ControlArrayHandle | [**ControlArray\_from\_json\_string**](#function-controlarray_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ControlArray\_full\_gradient**](#function-controlarray_full_gradient) (ControlArrayHandle handle, FArrayDoubleHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  double | [**ControlArray\_get\_sum\_of\_squares**](#function-controlarray_get_sum_of_squares) (ControlArrayHandle handle) <br> |
|  double | [**ControlArray\_get\_summed\_diff\_array\_of\_squares**](#function-controlarray_get_summed_diff_array_of_squares) (ControlArrayHandle handle, ControlArrayHandle other) <br> |
|  double | [**ControlArray\_get\_summed\_diff\_double\_of\_squares**](#function-controlarray_get_summed_diff_double_of_squares) (ControlArrayHandle handle, double other) <br> |
|  double | [**ControlArray\_get\_summed\_diff\_int\_of\_squares**](#function-controlarray_get_summed_diff_int_of_squares) (ControlArrayHandle handle, int other) <br> |
|  FArrayDoubleHandle | [**ControlArray\_gradient**](#function-controlarray_gradient) (ControlArrayHandle handle, size\_t axis) <br> |
|  bool | [**ControlArray\_greater\_than**](#function-controlarray_greater_than) (ControlArrayHandle handle, double value) <br> |
|  bool | [**ControlArray\_less\_than**](#function-controlarray_less_than) (ControlArrayHandle handle, double value) <br> |
|  double | [**ControlArray\_max**](#function-controlarray_max) (ControlArrayHandle handle) <br>_Return the maximum value of the array._  |
|  ControlArrayHandle | [**ControlArray\_max\_control\_array**](#function-controlarray_max_control_array) (ControlArrayHandle handle, ControlArrayHandle other) <br> |
|  ControlArrayHandle | [**ControlArray\_max\_farray**](#function-controlarray_max_farray) (ControlArrayHandle handle, FArrayDoubleHandle other) <br> |
|  double | [**ControlArray\_min**](#function-controlarray_min) (ControlArrayHandle handle) <br>_Return the minimum value of the array._  |
|  ControlArrayHandle | [**ControlArray\_min\_control\_array**](#function-controlarray_min_control_array) (ControlArrayHandle handle, ControlArrayHandle other) <br> |
|  ControlArrayHandle | [**ControlArray\_min\_farray**](#function-controlarray_min_farray) (ControlArrayHandle handle, FArrayDoubleHandle other) <br> |
|  ControlArrayHandle | [**ControlArray\_minus\_control\_array**](#function-controlarray_minus_control_array) (ControlArrayHandle handle, ControlArrayHandle other) <br> |
|  ControlArrayHandle | [**ControlArray\_minus\_double**](#function-controlarray_minus_double) (ControlArrayHandle handle, double other) <br> |
|  void | [**ControlArray\_minus\_equals\_double**](#function-controlarray_minus_equals_double) (ControlArrayHandle handle, double other) <br> |
|  void | [**ControlArray\_minus\_equals\_farray**](#function-controlarray_minus_equals_farray) (ControlArrayHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**ControlArray\_minus\_equals\_int**](#function-controlarray_minus_equals_int) (ControlArrayHandle handle, int other) <br> |
|  ControlArrayHandle | [**ControlArray\_minus\_farray**](#function-controlarray_minus_farray) (ControlArrayHandle handle, FArrayDoubleHandle other) <br> |
|  ControlArrayHandle | [**ControlArray\_minus\_int**](#function-controlarray_minus_int) (ControlArrayHandle handle, int other) <br> |
|  ControlArrayHandle | [**ControlArray\_negation**](#function-controlarray_negation) (ControlArrayHandle handle) <br> |
|  bool | [**ControlArray\_not\_equal**](#function-controlarray_not_equal) (ControlArrayHandle handle, ControlArrayHandle other) <br> |
|  ControlArrayHandle | [**ControlArray\_plus\_control\_array**](#function-controlarray_plus_control_array) (ControlArrayHandle handle, ControlArrayHandle other) <br> |
|  ControlArrayHandle | [**ControlArray\_plus\_double**](#function-controlarray_plus_double) (ControlArrayHandle handle, double other) <br> |
|  void | [**ControlArray\_plus\_equals\_double**](#function-controlarray_plus_equals_double) (ControlArrayHandle handle, double other) <br> |
|  void | [**ControlArray\_plus\_equals\_farray**](#function-controlarray_plus_equals_farray) (ControlArrayHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**ControlArray\_plus\_equals\_int**](#function-controlarray_plus_equals_int) (ControlArrayHandle handle, int other) <br> |
|  ControlArrayHandle | [**ControlArray\_plus\_farray**](#function-controlarray_plus_farray) (ControlArrayHandle handle, FArrayDoubleHandle other) <br> |
|  ControlArrayHandle | [**ControlArray\_plus\_int**](#function-controlarray_plus_int) (ControlArrayHandle handle, int other) <br> |
|  ControlArrayHandle | [**ControlArray\_pow**](#function-controlarray_pow) (ControlArrayHandle handle, double other) <br> |
|  void | [**ControlArray\_remove\_offset**](#function-controlarray_remove_offset) (ControlArrayHandle handle, double offset) <br> |
|  size\_t | [**ControlArray\_shape**](#function-controlarray_shape) (ControlArrayHandle handle, size\_t \* out\_buffer, size\_t ndim) <br> |
|  size\_t | [**ControlArray\_size**](#function-controlarray_size) (ControlArrayHandle handle) <br> |
|  double | [**ControlArray\_sum**](#function-controlarray_sum) (ControlArrayHandle handle) <br> |
|  ControlArrayHandle | [**ControlArray\_times\_double**](#function-controlarray_times_double) (ControlArrayHandle handle, double other) <br> |
|  void | [**ControlArray\_times\_equals\_double**](#function-controlarray_times_equals_double) (ControlArrayHandle handle, double other) <br> |
|  void | [**ControlArray\_times\_equals\_int**](#function-controlarray_times_equals_int) (ControlArrayHandle handle, int other) <br> |
|  ControlArrayHandle | [**ControlArray\_times\_int**](#function-controlarray_times_int) (ControlArrayHandle handle, int other) <br> |
|  StringHandle | [**ControlArray\_to\_json\_string**](#function-controlarray_to_json_string) (ControlArrayHandle handle) <br> |
|  ListListSizeTHandle | [**ControlArray\_where**](#function-controlarray_where) (ControlArrayHandle handle, double value) <br> |




























## Public Types Documentation




### typedef ControlArrayHandle 

```C++
typedef void* ControlArrayHandle;
```




<hr>
## Public Functions Documentation




### function ControlArray\_abs 

```C++
ControlArrayHandle ControlArray_abs (
    ControlArrayHandle handle
) 
```




<hr>



### function ControlArray\_copy 

```C++
ControlArrayHandle ControlArray_copy (
    ControlArrayHandle handle
) 
```




<hr>



### function ControlArray\_data 

```C++
size_t ControlArray_data (
    ControlArrayHandle handle,
    double * out_buffer,
    size_t numdata
) 
```




<hr>



### function ControlArray\_destroy 

```C++
void ControlArray_destroy (
    ControlArrayHandle handle
) 
```




<hr>



### function ControlArray\_dimension 

```C++
size_t ControlArray_dimension (
    ControlArrayHandle handle
) 
```




<hr>



### function ControlArray\_divides\_double 

```C++
ControlArrayHandle ControlArray_divides_double (
    ControlArrayHandle handle,
    double other
) 
```




<hr>



### function ControlArray\_divides\_equals\_double 

```C++
void ControlArray_divides_equals_double (
    ControlArrayHandle handle,
    double other
) 
```




<hr>



### function ControlArray\_divides\_equals\_int 

```C++
void ControlArray_divides_equals_int (
    ControlArrayHandle handle,
    int other
) 
```




<hr>



### function ControlArray\_divides\_int 

```C++
ControlArrayHandle ControlArray_divides_int (
    ControlArrayHandle handle,
    int other
) 
```




<hr>



### function ControlArray\_equal 

```C++
bool ControlArray_equal (
    ControlArrayHandle handle,
    ControlArrayHandle other
) 
```




<hr>



### function ControlArray\_flip 

_Flip the data along the given axis._ 
```C++
ControlArrayHandle ControlArray_flip (
    ControlArrayHandle handle,
    size_t axis
) 
```





**Parameters:**


* `axis` The axis to flip. 



**Returns:**

A flipped ControlArray. 





        

<hr>



### function ControlArray\_from\_data 

```C++
ControlArrayHandle ControlArray_from_data (
    const double * data,
    const size_t * shape,
    size_t ndim
) 
```




<hr>



### function ControlArray\_from\_farray 

```C++
ControlArrayHandle ControlArray_from_farray (
    FArrayDoubleHandle farray
) 
```




<hr>



### function ControlArray\_from\_json\_string 

```C++
ControlArrayHandle ControlArray_from_json_string (
    StringHandle json
) 
```




<hr>



### function ControlArray\_full\_gradient 

```C++
size_t ControlArray_full_gradient (
    ControlArrayHandle handle,
    FArrayDoubleHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ControlArray\_get\_sum\_of\_squares 

```C++
double ControlArray_get_sum_of_squares (
    ControlArrayHandle handle
) 
```




<hr>



### function ControlArray\_get\_summed\_diff\_array\_of\_squares 

```C++
double ControlArray_get_summed_diff_array_of_squares (
    ControlArrayHandle handle,
    ControlArrayHandle other
) 
```




<hr>



### function ControlArray\_get\_summed\_diff\_double\_of\_squares 

```C++
double ControlArray_get_summed_diff_double_of_squares (
    ControlArrayHandle handle,
    double other
) 
```




<hr>



### function ControlArray\_get\_summed\_diff\_int\_of\_squares 

```C++
double ControlArray_get_summed_diff_int_of_squares (
    ControlArrayHandle handle,
    int other
) 
```




<hr>



### function ControlArray\_gradient 

```C++
FArrayDoubleHandle ControlArray_gradient (
    ControlArrayHandle handle,
    size_t axis
) 
```




<hr>



### function ControlArray\_greater\_than 

```C++
bool ControlArray_greater_than (
    ControlArrayHandle handle,
    double value
) 
```




<hr>



### function ControlArray\_less\_than 

```C++
bool ControlArray_less_than (
    ControlArrayHandle handle,
    double value
) 
```




<hr>



### function ControlArray\_max 

_Return the maximum value of the array._ 
```C++
double ControlArray_max (
    ControlArrayHandle handle
) 
```




<hr>



### function ControlArray\_max\_control\_array 

```C++
ControlArrayHandle ControlArray_max_control_array (
    ControlArrayHandle handle,
    ControlArrayHandle other
) 
```




<hr>



### function ControlArray\_max\_farray 

```C++
ControlArrayHandle ControlArray_max_farray (
    ControlArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function ControlArray\_min 

_Return the minimum value of the array._ 
```C++
double ControlArray_min (
    ControlArrayHandle handle
) 
```




<hr>



### function ControlArray\_min\_control\_array 

```C++
ControlArrayHandle ControlArray_min_control_array (
    ControlArrayHandle handle,
    ControlArrayHandle other
) 
```




<hr>



### function ControlArray\_min\_farray 

```C++
ControlArrayHandle ControlArray_min_farray (
    ControlArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function ControlArray\_minus\_control\_array 

```C++
ControlArrayHandle ControlArray_minus_control_array (
    ControlArrayHandle handle,
    ControlArrayHandle other
) 
```




<hr>



### function ControlArray\_minus\_double 

```C++
ControlArrayHandle ControlArray_minus_double (
    ControlArrayHandle handle,
    double other
) 
```




<hr>



### function ControlArray\_minus\_equals\_double 

```C++
void ControlArray_minus_equals_double (
    ControlArrayHandle handle,
    double other
) 
```




<hr>



### function ControlArray\_minus\_equals\_farray 

```C++
void ControlArray_minus_equals_farray (
    ControlArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function ControlArray\_minus\_equals\_int 

```C++
void ControlArray_minus_equals_int (
    ControlArrayHandle handle,
    int other
) 
```




<hr>



### function ControlArray\_minus\_farray 

```C++
ControlArrayHandle ControlArray_minus_farray (
    ControlArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function ControlArray\_minus\_int 

```C++
ControlArrayHandle ControlArray_minus_int (
    ControlArrayHandle handle,
    int other
) 
```




<hr>



### function ControlArray\_negation 

```C++
ControlArrayHandle ControlArray_negation (
    ControlArrayHandle handle
) 
```




<hr>



### function ControlArray\_not\_equal 

```C++
bool ControlArray_not_equal (
    ControlArrayHandle handle,
    ControlArrayHandle other
) 
```




<hr>



### function ControlArray\_plus\_control\_array 

```C++
ControlArrayHandle ControlArray_plus_control_array (
    ControlArrayHandle handle,
    ControlArrayHandle other
) 
```




<hr>



### function ControlArray\_plus\_double 

```C++
ControlArrayHandle ControlArray_plus_double (
    ControlArrayHandle handle,
    double other
) 
```




<hr>



### function ControlArray\_plus\_equals\_double 

```C++
void ControlArray_plus_equals_double (
    ControlArrayHandle handle,
    double other
) 
```




<hr>



### function ControlArray\_plus\_equals\_farray 

```C++
void ControlArray_plus_equals_farray (
    ControlArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function ControlArray\_plus\_equals\_int 

```C++
void ControlArray_plus_equals_int (
    ControlArrayHandle handle,
    int other
) 
```




<hr>



### function ControlArray\_plus\_farray 

```C++
ControlArrayHandle ControlArray_plus_farray (
    ControlArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function ControlArray\_plus\_int 

```C++
ControlArrayHandle ControlArray_plus_int (
    ControlArrayHandle handle,
    int other
) 
```




<hr>



### function ControlArray\_pow 

```C++
ControlArrayHandle ControlArray_pow (
    ControlArrayHandle handle,
    double other
) 
```




<hr>



### function ControlArray\_remove\_offset 

```C++
void ControlArray_remove_offset (
    ControlArrayHandle handle,
    double offset
) 
```




<hr>



### function ControlArray\_shape 

```C++
size_t ControlArray_shape (
    ControlArrayHandle handle,
    size_t * out_buffer,
    size_t ndim
) 
```




<hr>



### function ControlArray\_size 

```C++
size_t ControlArray_size (
    ControlArrayHandle handle
) 
```




<hr>



### function ControlArray\_sum 

```C++
double ControlArray_sum (
    ControlArrayHandle handle
) 
```




<hr>



### function ControlArray\_times\_double 

```C++
ControlArrayHandle ControlArray_times_double (
    ControlArrayHandle handle,
    double other
) 
```




<hr>



### function ControlArray\_times\_equals\_double 

```C++
void ControlArray_times_equals_double (
    ControlArrayHandle handle,
    double other
) 
```




<hr>



### function ControlArray\_times\_equals\_int 

```C++
void ControlArray_times_equals_int (
    ControlArrayHandle handle,
    int other
) 
```




<hr>



### function ControlArray\_times\_int 

```C++
ControlArrayHandle ControlArray_times_int (
    ControlArrayHandle handle,
    int other
) 
```




<hr>



### function ControlArray\_to\_json\_string 

```C++
StringHandle ControlArray_to_json_string (
    ControlArrayHandle handle
) 
```




<hr>



### function ControlArray\_where 

```C++
ListListSizeTHandle ControlArray_where (
    ControlArrayHandle handle,
    double value
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/arrays/ControlArray_c_api.h`

