

# File FArrayInt\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**FArrayInt\_c\_api.h**](FArrayInt__c__api_8h.md)

[Go to the source code of this file](FArrayInt__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/ListListSizeT_c_api.h"`
* `#include "falcon_core/generic/FArrayDouble_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**FArrayIntHandle**](#typedef-farrayinthandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  FArrayIntHandle | [**FArrayInt\_abs**](#function-farrayint_abs) (FArrayIntHandle handle) <br> |
|  FArrayIntHandle | [**FArrayInt\_copy**](#function-farrayint_copy) (FArrayIntHandle handle) <br> |
|  FArrayIntHandle | [**FArrayInt\_create\_empty**](#function-farrayint_create_empty) (const size\_t \* shape, size\_t ndim) <br> |
|  FArrayIntHandle | [**FArrayInt\_create\_zeros**](#function-farrayint_create_zeros) (const size\_t \* shape, size\_t ndim) <br> |
|  size\_t | [**FArrayInt\_data**](#function-farrayint_data) (FArrayIntHandle handle, int \* out\_buffer, size\_t numdata) <br> |
|  void | [**FArrayInt\_destroy**](#function-farrayint_destroy) (FArrayIntHandle handle) <br> |
|  size\_t | [**FArrayInt\_dimension**](#function-farrayint_dimension) (FArrayIntHandle handle) <br> |
|  FArrayIntHandle | [**FArrayInt\_divides\_double**](#function-farrayint_divides_double) (FArrayIntHandle handle, double other) <br> |
|  void | [**FArrayInt\_divides\_equals\_double**](#function-farrayint_divides_equals_double) (FArrayIntHandle handle, double other) <br> |
|  void | [**FArrayInt\_divides\_equals\_farray**](#function-farrayint_divides_equals_farray) (FArrayIntHandle handle, FArrayIntHandle other) <br> |
|  void | [**FArrayInt\_divides\_equals\_int**](#function-farrayint_divides_equals_int) (FArrayIntHandle handle, int other) <br> |
|  FArrayIntHandle | [**FArrayInt\_divides\_farray**](#function-farrayint_divides_farray) (FArrayIntHandle handle, FArrayIntHandle other) <br> |
|  FArrayIntHandle | [**FArrayInt\_divides\_int**](#function-farrayint_divides_int) (FArrayIntHandle handle, int other) <br> |
|  FArrayDoubleHandle | [**FArrayInt\_double\_pow**](#function-farrayint_double_pow) (FArrayIntHandle handle, double other) <br> |
|  bool | [**FArrayInt\_equal**](#function-farrayint_equal) (FArrayIntHandle handle, FArrayIntHandle other) <br> |
|  FArrayIntHandle | [**FArrayInt\_flip**](#function-farrayint_flip) (FArrayIntHandle handle, size\_t axis) <br> |
|  FArrayIntHandle | [**FArrayInt\_from\_data**](#function-farrayint_from_data) (const int \* data, const size\_t \* shape, size\_t ndim) <br> |
|  FArrayIntHandle | [**FArrayInt\_from\_json\_string**](#function-farrayint_from_json_string) (StringHandle json) <br> |
|  FArrayIntHandle | [**FArrayInt\_from\_shape**](#function-farrayint_from_shape) (const size\_t \* shape, size\_t ndim) <br> |
|  size\_t | [**FArrayInt\_full\_gradient**](#function-farrayint_full_gradient) (FArrayIntHandle handle, FArrayIntHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  double | [**FArrayInt\_get\_sum\_of\_squares**](#function-farrayint_get_sum_of_squares) (FArrayIntHandle handle) <br> |
|  double | [**FArrayInt\_get\_summed\_diff\_array\_of\_squares**](#function-farrayint_get_summed_diff_array_of_squares) (FArrayIntHandle handle, FArrayIntHandle other) <br> |
|  double | [**FArrayInt\_get\_summed\_diff\_double\_of\_squares**](#function-farrayint_get_summed_diff_double_of_squares) (FArrayIntHandle handle, double other) <br> |
|  double | [**FArrayInt\_get\_summed\_diff\_int\_of\_squares**](#function-farrayint_get_summed_diff_int_of_squares) (FArrayIntHandle handle, int other) <br> |
|  FArrayIntHandle | [**FArrayInt\_gradient**](#function-farrayint_gradient) (FArrayIntHandle handle, size\_t axis) <br> |
|  bool | [**FArrayInt\_greater\_than**](#function-farrayint_greater_than) (FArrayIntHandle handle, int value) <br> |
|  bool | [**FArrayInt\_less\_than**](#function-farrayint_less_than) (FArrayIntHandle handle, int value) <br> |
|  int | [**FArrayInt\_max**](#function-farrayint_max) (FArrayIntHandle handle) <br> |
|  FArrayIntHandle | [**FArrayInt\_max\_arraywise**](#function-farrayint_max_arraywise) (FArrayIntHandle handle, FArrayIntHandle other) <br> |
|  int | [**FArrayInt\_min**](#function-farrayint_min) (FArrayIntHandle handle) <br> |
|  FArrayIntHandle | [**FArrayInt\_min\_arraywise**](#function-farrayint_min_arraywise) (FArrayIntHandle handle, FArrayIntHandle other) <br> |
|  FArrayIntHandle | [**FArrayInt\_minus\_double**](#function-farrayint_minus_double) (FArrayIntHandle handle, double other) <br> |
|  void | [**FArrayInt\_minus\_equals\_double**](#function-farrayint_minus_equals_double) (FArrayIntHandle handle, double other) <br> |
|  void | [**FArrayInt\_minus\_equals\_farray**](#function-farrayint_minus_equals_farray) (FArrayIntHandle handle, FArrayIntHandle other) <br> |
|  void | [**FArrayInt\_minus\_equals\_int**](#function-farrayint_minus_equals_int) (FArrayIntHandle handle, int other) <br> |
|  FArrayIntHandle | [**FArrayInt\_minus\_farray**](#function-farrayint_minus_farray) (FArrayIntHandle handle, FArrayIntHandle other) <br> |
|  FArrayIntHandle | [**FArrayInt\_minus\_int**](#function-farrayint_minus_int) (FArrayIntHandle handle, int other) <br> |
|  FArrayIntHandle | [**FArrayInt\_negation**](#function-farrayint_negation) (FArrayIntHandle handle) <br> |
|  bool | [**FArrayInt\_not\_equal**](#function-farrayint_not_equal) (FArrayIntHandle handle, FArrayIntHandle other) <br> |
|  FArrayIntHandle | [**FArrayInt\_plus\_double**](#function-farrayint_plus_double) (FArrayIntHandle handle, double other) <br> |
|  void | [**FArrayInt\_plus\_equals\_double**](#function-farrayint_plus_equals_double) (FArrayIntHandle handle, double other) <br> |
|  void | [**FArrayInt\_plus\_equals\_farray**](#function-farrayint_plus_equals_farray) (FArrayIntHandle handle, FArrayIntHandle other) <br> |
|  void | [**FArrayInt\_plus\_equals\_int**](#function-farrayint_plus_equals_int) (FArrayIntHandle handle, int other) <br> |
|  FArrayIntHandle | [**FArrayInt\_plus\_farray**](#function-farrayint_plus_farray) (FArrayIntHandle handle, FArrayIntHandle other) <br> |
|  FArrayIntHandle | [**FArrayInt\_plus\_int**](#function-farrayint_plus_int) (FArrayIntHandle handle, int other) <br> |
|  FArrayIntHandle | [**FArrayInt\_pow**](#function-farrayint_pow) (FArrayIntHandle handle, int other) <br> |
|  void | [**FArrayInt\_pow\_inplace**](#function-farrayint_pow_inplace) (FArrayIntHandle handle, int other) <br> |
|  void | [**FArrayInt\_remove\_offset**](#function-farrayint_remove_offset) (FArrayIntHandle handle, int offset) <br> |
|  FArrayIntHandle | [**FArrayInt\_reshape**](#function-farrayint_reshape) (FArrayIntHandle handle, const size\_t \* shape, size\_t ndims) <br> |
|  size\_t | [**FArrayInt\_shape**](#function-farrayint_shape) (FArrayIntHandle handle, size\_t \* out\_buffer, size\_t ndim) <br> |
|  size\_t | [**FArrayInt\_size**](#function-farrayint_size) (FArrayIntHandle handle) <br> |
|  int | [**FArrayInt\_sum**](#function-farrayint_sum) (FArrayIntHandle handle) <br> |
|  FArrayIntHandle | [**FArrayInt\_times\_double**](#function-farrayint_times_double) (FArrayIntHandle handle, double other) <br> |
|  void | [**FArrayInt\_times\_equals\_double**](#function-farrayint_times_equals_double) (FArrayIntHandle handle, double other) <br> |
|  void | [**FArrayInt\_times\_equals\_farray**](#function-farrayint_times_equals_farray) (FArrayIntHandle handle, FArrayIntHandle other) <br> |
|  void | [**FArrayInt\_times\_equals\_int**](#function-farrayint_times_equals_int) (FArrayIntHandle handle, int other) <br> |
|  FArrayIntHandle | [**FArrayInt\_times\_farray**](#function-farrayint_times_farray) (FArrayIntHandle handle, FArrayIntHandle other) <br> |
|  FArrayIntHandle | [**FArrayInt\_times\_int**](#function-farrayint_times_int) (FArrayIntHandle handle, int other) <br> |
|  StringHandle | [**FArrayInt\_to\_json\_string**](#function-farrayint_to_json_string) (FArrayIntHandle handle) <br> |
|  ListListSizeTHandle | [**FArrayInt\_where**](#function-farrayint_where) (FArrayIntHandle handle, int value) <br> |




























## Public Types Documentation




### typedef FArrayIntHandle 

```C++
typedef void* FArrayIntHandle;
```




<hr>
## Public Functions Documentation




### function FArrayInt\_abs 

```C++
FArrayIntHandle FArrayInt_abs (
    FArrayIntHandle handle
) 
```




<hr>



### function FArrayInt\_copy 

```C++
FArrayIntHandle FArrayInt_copy (
    FArrayIntHandle handle
) 
```




<hr>



### function FArrayInt\_create\_empty 

```C++
FArrayIntHandle FArrayInt_create_empty (
    const size_t * shape,
    size_t ndim
) 
```




<hr>



### function FArrayInt\_create\_zeros 

```C++
FArrayIntHandle FArrayInt_create_zeros (
    const size_t * shape,
    size_t ndim
) 
```




<hr>



### function FArrayInt\_data 

```C++
size_t FArrayInt_data (
    FArrayIntHandle handle,
    int * out_buffer,
    size_t numdata
) 
```




<hr>



### function FArrayInt\_destroy 

```C++
void FArrayInt_destroy (
    FArrayIntHandle handle
) 
```




<hr>



### function FArrayInt\_dimension 

```C++
size_t FArrayInt_dimension (
    FArrayIntHandle handle
) 
```




<hr>



### function FArrayInt\_divides\_double 

```C++
FArrayIntHandle FArrayInt_divides_double (
    FArrayIntHandle handle,
    double other
) 
```




<hr>



### function FArrayInt\_divides\_equals\_double 

```C++
void FArrayInt_divides_equals_double (
    FArrayIntHandle handle,
    double other
) 
```




<hr>



### function FArrayInt\_divides\_equals\_farray 

```C++
void FArrayInt_divides_equals_farray (
    FArrayIntHandle handle,
    FArrayIntHandle other
) 
```




<hr>



### function FArrayInt\_divides\_equals\_int 

```C++
void FArrayInt_divides_equals_int (
    FArrayIntHandle handle,
    int other
) 
```




<hr>



### function FArrayInt\_divides\_farray 

```C++
FArrayIntHandle FArrayInt_divides_farray (
    FArrayIntHandle handle,
    FArrayIntHandle other
) 
```




<hr>



### function FArrayInt\_divides\_int 

```C++
FArrayIntHandle FArrayInt_divides_int (
    FArrayIntHandle handle,
    int other
) 
```




<hr>



### function FArrayInt\_double\_pow 

```C++
FArrayDoubleHandle FArrayInt_double_pow (
    FArrayIntHandle handle,
    double other
) 
```




<hr>



### function FArrayInt\_equal 

```C++
bool FArrayInt_equal (
    FArrayIntHandle handle,
    FArrayIntHandle other
) 
```




<hr>



### function FArrayInt\_flip 

```C++
FArrayIntHandle FArrayInt_flip (
    FArrayIntHandle handle,
    size_t axis
) 
```




<hr>



### function FArrayInt\_from\_data 

```C++
FArrayIntHandle FArrayInt_from_data (
    const int * data,
    const size_t * shape,
    size_t ndim
) 
```




<hr>



### function FArrayInt\_from\_json\_string 

```C++
FArrayIntHandle FArrayInt_from_json_string (
    StringHandle json
) 
```




<hr>



### function FArrayInt\_from\_shape 

```C++
FArrayIntHandle FArrayInt_from_shape (
    const size_t * shape,
    size_t ndim
) 
```




<hr>



### function FArrayInt\_full\_gradient 

```C++
size_t FArrayInt_full_gradient (
    FArrayIntHandle handle,
    FArrayIntHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function FArrayInt\_get\_sum\_of\_squares 

```C++
double FArrayInt_get_sum_of_squares (
    FArrayIntHandle handle
) 
```




<hr>



### function FArrayInt\_get\_summed\_diff\_array\_of\_squares 

```C++
double FArrayInt_get_summed_diff_array_of_squares (
    FArrayIntHandle handle,
    FArrayIntHandle other
) 
```




<hr>



### function FArrayInt\_get\_summed\_diff\_double\_of\_squares 

```C++
double FArrayInt_get_summed_diff_double_of_squares (
    FArrayIntHandle handle,
    double other
) 
```




<hr>



### function FArrayInt\_get\_summed\_diff\_int\_of\_squares 

```C++
double FArrayInt_get_summed_diff_int_of_squares (
    FArrayIntHandle handle,
    int other
) 
```




<hr>



### function FArrayInt\_gradient 

```C++
FArrayIntHandle FArrayInt_gradient (
    FArrayIntHandle handle,
    size_t axis
) 
```




<hr>



### function FArrayInt\_greater\_than 

```C++
bool FArrayInt_greater_than (
    FArrayIntHandle handle,
    int value
) 
```




<hr>



### function FArrayInt\_less\_than 

```C++
bool FArrayInt_less_than (
    FArrayIntHandle handle,
    int value
) 
```




<hr>



### function FArrayInt\_max 

```C++
int FArrayInt_max (
    FArrayIntHandle handle
) 
```




<hr>



### function FArrayInt\_max\_arraywise 

```C++
FArrayIntHandle FArrayInt_max_arraywise (
    FArrayIntHandle handle,
    FArrayIntHandle other
) 
```




<hr>



### function FArrayInt\_min 

```C++
int FArrayInt_min (
    FArrayIntHandle handle
) 
```




<hr>



### function FArrayInt\_min\_arraywise 

```C++
FArrayIntHandle FArrayInt_min_arraywise (
    FArrayIntHandle handle,
    FArrayIntHandle other
) 
```




<hr>



### function FArrayInt\_minus\_double 

```C++
FArrayIntHandle FArrayInt_minus_double (
    FArrayIntHandle handle,
    double other
) 
```




<hr>



### function FArrayInt\_minus\_equals\_double 

```C++
void FArrayInt_minus_equals_double (
    FArrayIntHandle handle,
    double other
) 
```




<hr>



### function FArrayInt\_minus\_equals\_farray 

```C++
void FArrayInt_minus_equals_farray (
    FArrayIntHandle handle,
    FArrayIntHandle other
) 
```




<hr>



### function FArrayInt\_minus\_equals\_int 

```C++
void FArrayInt_minus_equals_int (
    FArrayIntHandle handle,
    int other
) 
```




<hr>



### function FArrayInt\_minus\_farray 

```C++
FArrayIntHandle FArrayInt_minus_farray (
    FArrayIntHandle handle,
    FArrayIntHandle other
) 
```




<hr>



### function FArrayInt\_minus\_int 

```C++
FArrayIntHandle FArrayInt_minus_int (
    FArrayIntHandle handle,
    int other
) 
```




<hr>



### function FArrayInt\_negation 

```C++
FArrayIntHandle FArrayInt_negation (
    FArrayIntHandle handle
) 
```




<hr>



### function FArrayInt\_not\_equal 

```C++
bool FArrayInt_not_equal (
    FArrayIntHandle handle,
    FArrayIntHandle other
) 
```




<hr>



### function FArrayInt\_plus\_double 

```C++
FArrayIntHandle FArrayInt_plus_double (
    FArrayIntHandle handle,
    double other
) 
```




<hr>



### function FArrayInt\_plus\_equals\_double 

```C++
void FArrayInt_plus_equals_double (
    FArrayIntHandle handle,
    double other
) 
```




<hr>



### function FArrayInt\_plus\_equals\_farray 

```C++
void FArrayInt_plus_equals_farray (
    FArrayIntHandle handle,
    FArrayIntHandle other
) 
```




<hr>



### function FArrayInt\_plus\_equals\_int 

```C++
void FArrayInt_plus_equals_int (
    FArrayIntHandle handle,
    int other
) 
```




<hr>



### function FArrayInt\_plus\_farray 

```C++
FArrayIntHandle FArrayInt_plus_farray (
    FArrayIntHandle handle,
    FArrayIntHandle other
) 
```




<hr>



### function FArrayInt\_plus\_int 

```C++
FArrayIntHandle FArrayInt_plus_int (
    FArrayIntHandle handle,
    int other
) 
```




<hr>



### function FArrayInt\_pow 

```C++
FArrayIntHandle FArrayInt_pow (
    FArrayIntHandle handle,
    int other
) 
```




<hr>



### function FArrayInt\_pow\_inplace 

```C++
void FArrayInt_pow_inplace (
    FArrayIntHandle handle,
    int other
) 
```




<hr>



### function FArrayInt\_remove\_offset 

```C++
void FArrayInt_remove_offset (
    FArrayIntHandle handle,
    int offset
) 
```




<hr>



### function FArrayInt\_reshape 

```C++
FArrayIntHandle FArrayInt_reshape (
    FArrayIntHandle handle,
    const size_t * shape,
    size_t ndims
) 
```




<hr>



### function FArrayInt\_shape 

```C++
size_t FArrayInt_shape (
    FArrayIntHandle handle,
    size_t * out_buffer,
    size_t ndim
) 
```




<hr>



### function FArrayInt\_size 

```C++
size_t FArrayInt_size (
    FArrayIntHandle handle
) 
```




<hr>



### function FArrayInt\_sum 

```C++
int FArrayInt_sum (
    FArrayIntHandle handle
) 
```




<hr>



### function FArrayInt\_times\_double 

```C++
FArrayIntHandle FArrayInt_times_double (
    FArrayIntHandle handle,
    double other
) 
```




<hr>



### function FArrayInt\_times\_equals\_double 

```C++
void FArrayInt_times_equals_double (
    FArrayIntHandle handle,
    double other
) 
```




<hr>



### function FArrayInt\_times\_equals\_farray 

```C++
void FArrayInt_times_equals_farray (
    FArrayIntHandle handle,
    FArrayIntHandle other
) 
```




<hr>



### function FArrayInt\_times\_equals\_int 

```C++
void FArrayInt_times_equals_int (
    FArrayIntHandle handle,
    int other
) 
```




<hr>



### function FArrayInt\_times\_farray 

```C++
FArrayIntHandle FArrayInt_times_farray (
    FArrayIntHandle handle,
    FArrayIntHandle other
) 
```




<hr>



### function FArrayInt\_times\_int 

```C++
FArrayIntHandle FArrayInt_times_int (
    FArrayIntHandle handle,
    int other
) 
```




<hr>



### function FArrayInt\_to\_json\_string 

```C++
StringHandle FArrayInt_to_json_string (
    FArrayIntHandle handle
) 
```




<hr>



### function FArrayInt\_where 

```C++
ListListSizeTHandle FArrayInt_where (
    FArrayIntHandle handle,
    int value
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/FArrayInt_c_api.h`

