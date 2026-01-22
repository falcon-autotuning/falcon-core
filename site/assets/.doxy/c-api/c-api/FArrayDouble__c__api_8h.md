

# File FArrayDouble\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**FArrayDouble\_c\_api.h**](FArrayDouble__c__api_8h.md)

[Go to the source code of this file](FArrayDouble__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/ListListSizeT_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**FArrayDoubleHandle**](#typedef-farraydoublehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  FArrayDoubleHandle | [**FArrayDouble\_abs**](#function-farraydouble_abs) (FArrayDoubleHandle handle) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_copy**](#function-farraydouble_copy) (FArrayDoubleHandle handle) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_create\_empty**](#function-farraydouble_create_empty) (const size\_t \* shape, size\_t ndim) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_create\_zeros**](#function-farraydouble_create_zeros) (const size\_t \* shape, size\_t ndim) <br> |
|  size\_t | [**FArrayDouble\_data**](#function-farraydouble_data) (FArrayDoubleHandle handle, double \* out\_buffer, size\_t numdata) <br> |
|  void | [**FArrayDouble\_destroy**](#function-farraydouble_destroy) (FArrayDoubleHandle handle) <br> |
|  size\_t | [**FArrayDouble\_dimension**](#function-farraydouble_dimension) (FArrayDoubleHandle handle) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_divides\_double**](#function-farraydouble_divides_double) (FArrayDoubleHandle handle, double other) <br> |
|  void | [**FArrayDouble\_divides\_equals\_double**](#function-farraydouble_divides_equals_double) (FArrayDoubleHandle handle, double other) <br> |
|  void | [**FArrayDouble\_divides\_equals\_farray**](#function-farraydouble_divides_equals_farray) (FArrayDoubleHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**FArrayDouble\_divides\_equals\_int**](#function-farraydouble_divides_equals_int) (FArrayDoubleHandle handle, int other) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_divides\_farray**](#function-farraydouble_divides_farray) (FArrayDoubleHandle handle, FArrayDoubleHandle other) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_divides\_int**](#function-farraydouble_divides_int) (FArrayDoubleHandle handle, int other) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_double\_pow**](#function-farraydouble_double_pow) (FArrayDoubleHandle handle, double other) <br> |
|  bool | [**FArrayDouble\_equal**](#function-farraydouble_equal) (FArrayDoubleHandle handle, FArrayDoubleHandle other) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_flip**](#function-farraydouble_flip) (FArrayDoubleHandle handle, size\_t axis) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_from\_data**](#function-farraydouble_from_data) (const double \* data, const size\_t \* shape, size\_t ndim) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_from\_json\_string**](#function-farraydouble_from_json_string) (StringHandle json) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_from\_shape**](#function-farraydouble_from_shape) (const size\_t \* shape, size\_t ndim) <br> |
|  size\_t | [**FArrayDouble\_full\_gradient**](#function-farraydouble_full_gradient) (FArrayDoubleHandle handle, FArrayDoubleHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  double | [**FArrayDouble\_get\_sum\_of\_squares**](#function-farraydouble_get_sum_of_squares) (FArrayDoubleHandle handle) <br> |
|  double | [**FArrayDouble\_get\_summed\_diff\_array\_of\_squares**](#function-farraydouble_get_summed_diff_array_of_squares) (FArrayDoubleHandle handle, FArrayDoubleHandle other) <br> |
|  double | [**FArrayDouble\_get\_summed\_diff\_double\_of\_squares**](#function-farraydouble_get_summed_diff_double_of_squares) (FArrayDoubleHandle handle, double other) <br> |
|  double | [**FArrayDouble\_get\_summed\_diff\_int\_of\_squares**](#function-farraydouble_get_summed_diff_int_of_squares) (FArrayDoubleHandle handle, int other) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_gradient**](#function-farraydouble_gradient) (FArrayDoubleHandle handle, size\_t axis) <br> |
|  bool | [**FArrayDouble\_greater\_than**](#function-farraydouble_greater_than) (FArrayDoubleHandle handle, double value) <br> |
|  bool | [**FArrayDouble\_less\_than**](#function-farraydouble_less_than) (FArrayDoubleHandle handle, double value) <br> |
|  double | [**FArrayDouble\_max**](#function-farraydouble_max) (FArrayDoubleHandle handle) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_max\_arraywise**](#function-farraydouble_max_arraywise) (FArrayDoubleHandle handle, FArrayDoubleHandle other) <br> |
|  double | [**FArrayDouble\_min**](#function-farraydouble_min) (FArrayDoubleHandle handle) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_min\_arraywise**](#function-farraydouble_min_arraywise) (FArrayDoubleHandle handle, FArrayDoubleHandle other) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_minus\_double**](#function-farraydouble_minus_double) (FArrayDoubleHandle handle, double other) <br> |
|  void | [**FArrayDouble\_minus\_equals\_double**](#function-farraydouble_minus_equals_double) (FArrayDoubleHandle handle, double other) <br> |
|  void | [**FArrayDouble\_minus\_equals\_farray**](#function-farraydouble_minus_equals_farray) (FArrayDoubleHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**FArrayDouble\_minus\_equals\_int**](#function-farraydouble_minus_equals_int) (FArrayDoubleHandle handle, int other) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_minus\_farray**](#function-farraydouble_minus_farray) (FArrayDoubleHandle handle, FArrayDoubleHandle other) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_minus\_int**](#function-farraydouble_minus_int) (FArrayDoubleHandle handle, int other) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_negation**](#function-farraydouble_negation) (FArrayDoubleHandle handle) <br> |
|  bool | [**FArrayDouble\_not\_equal**](#function-farraydouble_not_equal) (FArrayDoubleHandle handle, FArrayDoubleHandle other) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_plus\_double**](#function-farraydouble_plus_double) (FArrayDoubleHandle handle, double other) <br> |
|  void | [**FArrayDouble\_plus\_equals\_double**](#function-farraydouble_plus_equals_double) (FArrayDoubleHandle handle, double other) <br> |
|  void | [**FArrayDouble\_plus\_equals\_farray**](#function-farraydouble_plus_equals_farray) (FArrayDoubleHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**FArrayDouble\_plus\_equals\_int**](#function-farraydouble_plus_equals_int) (FArrayDoubleHandle handle, int other) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_plus\_farray**](#function-farraydouble_plus_farray) (FArrayDoubleHandle handle, FArrayDoubleHandle other) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_plus\_int**](#function-farraydouble_plus_int) (FArrayDoubleHandle handle, int other) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_pow**](#function-farraydouble_pow) (FArrayDoubleHandle handle, double other) <br> |
|  void | [**FArrayDouble\_pow\_inplace**](#function-farraydouble_pow_inplace) (FArrayDoubleHandle handle, double other) <br> |
|  void | [**FArrayDouble\_remove\_offset**](#function-farraydouble_remove_offset) (FArrayDoubleHandle handle, double offset) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_reshape**](#function-farraydouble_reshape) (FArrayDoubleHandle handle, const size\_t \* shape, size\_t ndims) <br> |
|  size\_t | [**FArrayDouble\_shape**](#function-farraydouble_shape) (FArrayDoubleHandle handle, size\_t \* out\_buffer, size\_t ndim) <br> |
|  size\_t | [**FArrayDouble\_size**](#function-farraydouble_size) (FArrayDoubleHandle handle) <br> |
|  double | [**FArrayDouble\_sum**](#function-farraydouble_sum) (FArrayDoubleHandle handle) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_times\_double**](#function-farraydouble_times_double) (FArrayDoubleHandle handle, double other) <br> |
|  void | [**FArrayDouble\_times\_equals\_double**](#function-farraydouble_times_equals_double) (FArrayDoubleHandle handle, double other) <br> |
|  void | [**FArrayDouble\_times\_equals\_farray**](#function-farraydouble_times_equals_farray) (FArrayDoubleHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**FArrayDouble\_times\_equals\_int**](#function-farraydouble_times_equals_int) (FArrayDoubleHandle handle, int other) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_times\_farray**](#function-farraydouble_times_farray) (FArrayDoubleHandle handle, FArrayDoubleHandle other) <br> |
|  FArrayDoubleHandle | [**FArrayDouble\_times\_int**](#function-farraydouble_times_int) (FArrayDoubleHandle handle, int other) <br> |
|  StringHandle | [**FArrayDouble\_to\_json\_string**](#function-farraydouble_to_json_string) (FArrayDoubleHandle handle) <br> |
|  ListListSizeTHandle | [**FArrayDouble\_where**](#function-farraydouble_where) (FArrayDoubleHandle handle, double value) <br> |




























## Public Types Documentation




### typedef FArrayDoubleHandle 

```C++
typedef void* FArrayDoubleHandle;
```




<hr>
## Public Functions Documentation




### function FArrayDouble\_abs 

```C++
FArrayDoubleHandle FArrayDouble_abs (
    FArrayDoubleHandle handle
) 
```




<hr>



### function FArrayDouble\_copy 

```C++
FArrayDoubleHandle FArrayDouble_copy (
    FArrayDoubleHandle handle
) 
```




<hr>



### function FArrayDouble\_create\_empty 

```C++
FArrayDoubleHandle FArrayDouble_create_empty (
    const size_t * shape,
    size_t ndim
) 
```




<hr>



### function FArrayDouble\_create\_zeros 

```C++
FArrayDoubleHandle FArrayDouble_create_zeros (
    const size_t * shape,
    size_t ndim
) 
```




<hr>



### function FArrayDouble\_data 

```C++
size_t FArrayDouble_data (
    FArrayDoubleHandle handle,
    double * out_buffer,
    size_t numdata
) 
```




<hr>



### function FArrayDouble\_destroy 

```C++
void FArrayDouble_destroy (
    FArrayDoubleHandle handle
) 
```




<hr>



### function FArrayDouble\_dimension 

```C++
size_t FArrayDouble_dimension (
    FArrayDoubleHandle handle
) 
```




<hr>



### function FArrayDouble\_divides\_double 

```C++
FArrayDoubleHandle FArrayDouble_divides_double (
    FArrayDoubleHandle handle,
    double other
) 
```




<hr>



### function FArrayDouble\_divides\_equals\_double 

```C++
void FArrayDouble_divides_equals_double (
    FArrayDoubleHandle handle,
    double other
) 
```




<hr>



### function FArrayDouble\_divides\_equals\_farray 

```C++
void FArrayDouble_divides_equals_farray (
    FArrayDoubleHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function FArrayDouble\_divides\_equals\_int 

```C++
void FArrayDouble_divides_equals_int (
    FArrayDoubleHandle handle,
    int other
) 
```




<hr>



### function FArrayDouble\_divides\_farray 

```C++
FArrayDoubleHandle FArrayDouble_divides_farray (
    FArrayDoubleHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function FArrayDouble\_divides\_int 

```C++
FArrayDoubleHandle FArrayDouble_divides_int (
    FArrayDoubleHandle handle,
    int other
) 
```




<hr>



### function FArrayDouble\_double\_pow 

```C++
FArrayDoubleHandle FArrayDouble_double_pow (
    FArrayDoubleHandle handle,
    double other
) 
```




<hr>



### function FArrayDouble\_equal 

```C++
bool FArrayDouble_equal (
    FArrayDoubleHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function FArrayDouble\_flip 

```C++
FArrayDoubleHandle FArrayDouble_flip (
    FArrayDoubleHandle handle,
    size_t axis
) 
```




<hr>



### function FArrayDouble\_from\_data 

```C++
FArrayDoubleHandle FArrayDouble_from_data (
    const double * data,
    const size_t * shape,
    size_t ndim
) 
```




<hr>



### function FArrayDouble\_from\_json\_string 

```C++
FArrayDoubleHandle FArrayDouble_from_json_string (
    StringHandle json
) 
```




<hr>



### function FArrayDouble\_from\_shape 

```C++
FArrayDoubleHandle FArrayDouble_from_shape (
    const size_t * shape,
    size_t ndim
) 
```




<hr>



### function FArrayDouble\_full\_gradient 

```C++
size_t FArrayDouble_full_gradient (
    FArrayDoubleHandle handle,
    FArrayDoubleHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function FArrayDouble\_get\_sum\_of\_squares 

```C++
double FArrayDouble_get_sum_of_squares (
    FArrayDoubleHandle handle
) 
```




<hr>



### function FArrayDouble\_get\_summed\_diff\_array\_of\_squares 

```C++
double FArrayDouble_get_summed_diff_array_of_squares (
    FArrayDoubleHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function FArrayDouble\_get\_summed\_diff\_double\_of\_squares 

```C++
double FArrayDouble_get_summed_diff_double_of_squares (
    FArrayDoubleHandle handle,
    double other
) 
```




<hr>



### function FArrayDouble\_get\_summed\_diff\_int\_of\_squares 

```C++
double FArrayDouble_get_summed_diff_int_of_squares (
    FArrayDoubleHandle handle,
    int other
) 
```




<hr>



### function FArrayDouble\_gradient 

```C++
FArrayDoubleHandle FArrayDouble_gradient (
    FArrayDoubleHandle handle,
    size_t axis
) 
```




<hr>



### function FArrayDouble\_greater\_than 

```C++
bool FArrayDouble_greater_than (
    FArrayDoubleHandle handle,
    double value
) 
```




<hr>



### function FArrayDouble\_less\_than 

```C++
bool FArrayDouble_less_than (
    FArrayDoubleHandle handle,
    double value
) 
```




<hr>



### function FArrayDouble\_max 

```C++
double FArrayDouble_max (
    FArrayDoubleHandle handle
) 
```




<hr>



### function FArrayDouble\_max\_arraywise 

```C++
FArrayDoubleHandle FArrayDouble_max_arraywise (
    FArrayDoubleHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function FArrayDouble\_min 

```C++
double FArrayDouble_min (
    FArrayDoubleHandle handle
) 
```




<hr>



### function FArrayDouble\_min\_arraywise 

```C++
FArrayDoubleHandle FArrayDouble_min_arraywise (
    FArrayDoubleHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function FArrayDouble\_minus\_double 

```C++
FArrayDoubleHandle FArrayDouble_minus_double (
    FArrayDoubleHandle handle,
    double other
) 
```




<hr>



### function FArrayDouble\_minus\_equals\_double 

```C++
void FArrayDouble_minus_equals_double (
    FArrayDoubleHandle handle,
    double other
) 
```




<hr>



### function FArrayDouble\_minus\_equals\_farray 

```C++
void FArrayDouble_minus_equals_farray (
    FArrayDoubleHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function FArrayDouble\_minus\_equals\_int 

```C++
void FArrayDouble_minus_equals_int (
    FArrayDoubleHandle handle,
    int other
) 
```




<hr>



### function FArrayDouble\_minus\_farray 

```C++
FArrayDoubleHandle FArrayDouble_minus_farray (
    FArrayDoubleHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function FArrayDouble\_minus\_int 

```C++
FArrayDoubleHandle FArrayDouble_minus_int (
    FArrayDoubleHandle handle,
    int other
) 
```




<hr>



### function FArrayDouble\_negation 

```C++
FArrayDoubleHandle FArrayDouble_negation (
    FArrayDoubleHandle handle
) 
```




<hr>



### function FArrayDouble\_not\_equal 

```C++
bool FArrayDouble_not_equal (
    FArrayDoubleHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function FArrayDouble\_plus\_double 

```C++
FArrayDoubleHandle FArrayDouble_plus_double (
    FArrayDoubleHandle handle,
    double other
) 
```




<hr>



### function FArrayDouble\_plus\_equals\_double 

```C++
void FArrayDouble_plus_equals_double (
    FArrayDoubleHandle handle,
    double other
) 
```




<hr>



### function FArrayDouble\_plus\_equals\_farray 

```C++
void FArrayDouble_plus_equals_farray (
    FArrayDoubleHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function FArrayDouble\_plus\_equals\_int 

```C++
void FArrayDouble_plus_equals_int (
    FArrayDoubleHandle handle,
    int other
) 
```




<hr>



### function FArrayDouble\_plus\_farray 

```C++
FArrayDoubleHandle FArrayDouble_plus_farray (
    FArrayDoubleHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function FArrayDouble\_plus\_int 

```C++
FArrayDoubleHandle FArrayDouble_plus_int (
    FArrayDoubleHandle handle,
    int other
) 
```




<hr>



### function FArrayDouble\_pow 

```C++
FArrayDoubleHandle FArrayDouble_pow (
    FArrayDoubleHandle handle,
    double other
) 
```




<hr>



### function FArrayDouble\_pow\_inplace 

```C++
void FArrayDouble_pow_inplace (
    FArrayDoubleHandle handle,
    double other
) 
```




<hr>



### function FArrayDouble\_remove\_offset 

```C++
void FArrayDouble_remove_offset (
    FArrayDoubleHandle handle,
    double offset
) 
```




<hr>



### function FArrayDouble\_reshape 

```C++
FArrayDoubleHandle FArrayDouble_reshape (
    FArrayDoubleHandle handle,
    const size_t * shape,
    size_t ndims
) 
```




<hr>



### function FArrayDouble\_shape 

```C++
size_t FArrayDouble_shape (
    FArrayDoubleHandle handle,
    size_t * out_buffer,
    size_t ndim
) 
```




<hr>



### function FArrayDouble\_size 

```C++
size_t FArrayDouble_size (
    FArrayDoubleHandle handle
) 
```




<hr>



### function FArrayDouble\_sum 

```C++
double FArrayDouble_sum (
    FArrayDoubleHandle handle
) 
```




<hr>



### function FArrayDouble\_times\_double 

```C++
FArrayDoubleHandle FArrayDouble_times_double (
    FArrayDoubleHandle handle,
    double other
) 
```




<hr>



### function FArrayDouble\_times\_equals\_double 

```C++
void FArrayDouble_times_equals_double (
    FArrayDoubleHandle handle,
    double other
) 
```




<hr>



### function FArrayDouble\_times\_equals\_farray 

```C++
void FArrayDouble_times_equals_farray (
    FArrayDoubleHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function FArrayDouble\_times\_equals\_int 

```C++
void FArrayDouble_times_equals_int (
    FArrayDoubleHandle handle,
    int other
) 
```




<hr>



### function FArrayDouble\_times\_farray 

```C++
FArrayDoubleHandle FArrayDouble_times_farray (
    FArrayDoubleHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function FArrayDouble\_times\_int 

```C++
FArrayDoubleHandle FArrayDouble_times_int (
    FArrayDoubleHandle handle,
    int other
) 
```




<hr>



### function FArrayDouble\_to\_json\_string 

```C++
StringHandle FArrayDouble_to_json_string (
    FArrayDoubleHandle handle
) 
```




<hr>



### function FArrayDouble\_where 

```C++
ListListSizeTHandle FArrayDouble_where (
    FArrayDoubleHandle handle,
    double value
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/FArrayDouble_c_api.h`

