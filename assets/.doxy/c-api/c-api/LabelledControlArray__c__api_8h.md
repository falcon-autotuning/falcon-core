

# File LabelledControlArray\_c\_api.h



[**FileList**](files.md) **>** [**arrays**](dir_bfe73c8db2db54615e75c4ba09b4f73a.md) **>** [**LabelledControlArray\_c\_api.h**](LabelledControlArray__c__api_8h.md)

[Go to the source code of this file](LabelledControlArray__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"`
* `#include "falcon_core/generic/FArrayDouble_c_api.h"`
* `#include "falcon_core/generic/ListListSizeT_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/math/arrays/ControlArray_c_api.h"`
* `#include "falcon_core/physics/units/SymbolUnit_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**LabelledControlArrayHandle**](#typedef-labelledcontrolarrayhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  LabelledControlArrayHandle | [**LabelledControlArray\_abs**](#function-labelledcontrolarray_abs) (LabelledControlArrayHandle handle) <br> |
|  ConnectionHandle | [**LabelledControlArray\_connection**](#function-labelledcontrolarray_connection) (LabelledControlArrayHandle handle) <br> |
|  LabelledControlArrayHandle | [**LabelledControlArray\_copy**](#function-labelledcontrolarray_copy) (LabelledControlArrayHandle handle) <br> |
|  size\_t | [**LabelledControlArray\_data**](#function-labelledcontrolarray_data) (LabelledControlArrayHandle handle, double \* out\_buffer, size\_t numdata) <br> |
|  void | [**LabelledControlArray\_destroy**](#function-labelledcontrolarray_destroy) (LabelledControlArrayHandle handle) <br> |
|  size\_t | [**LabelledControlArray\_dimension**](#function-labelledcontrolarray_dimension) (LabelledControlArrayHandle handle) <br> |
|  LabelledControlArrayHandle | [**LabelledControlArray\_divides\_double**](#function-labelledcontrolarray_divides_double) (LabelledControlArrayHandle handle, double other) <br> |
|  void | [**LabelledControlArray\_divides\_equals\_double**](#function-labelledcontrolarray_divides_equals_double) (LabelledControlArrayHandle handle, double other) <br> |
|  void | [**LabelledControlArray\_divides\_equals\_int**](#function-labelledcontrolarray_divides_equals_int) (LabelledControlArrayHandle handle, int other) <br> |
|  LabelledControlArrayHandle | [**LabelledControlArray\_divides\_int**](#function-labelledcontrolarray_divides_int) (LabelledControlArrayHandle handle, int other) <br> |
|  bool | [**LabelledControlArray\_equal**](#function-labelledcontrolarray_equal) (LabelledControlArrayHandle handle, LabelledControlArrayHandle other) <br> |
|  LabelledControlArrayHandle | [**LabelledControlArray\_flip**](#function-labelledcontrolarray_flip) (LabelledControlArrayHandle handle, size\_t axis) <br>_Flip the data along the given axis._  |
|  LabelledControlArrayHandle | [**LabelledControlArray\_from\_control\_array**](#function-labelledcontrolarray_from_control_array) (ControlArrayHandle controlarray, AcquisitionContextHandle label) <br> |
|  LabelledControlArrayHandle | [**LabelledControlArray\_from\_farray**](#function-labelledcontrolarray_from_farray) (FArrayDoubleHandle farray, AcquisitionContextHandle label) <br> |
|  LabelledControlArrayHandle | [**LabelledControlArray\_from\_json\_string**](#function-labelledcontrolarray_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**LabelledControlArray\_full\_gradient**](#function-labelledcontrolarray_full_gradient) (LabelledControlArrayHandle handle, FArrayDoubleHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  double | [**LabelledControlArray\_get\_sum\_of\_squares**](#function-labelledcontrolarray_get_sum_of_squares) (LabelledControlArrayHandle handle) <br> |
|  double | [**LabelledControlArray\_get\_summed\_diff\_array\_of\_squares**](#function-labelledcontrolarray_get_summed_diff_array_of_squares) (LabelledControlArrayHandle handle, LabelledControlArrayHandle other) <br> |
|  double | [**LabelledControlArray\_get\_summed\_diff\_double\_of\_squares**](#function-labelledcontrolarray_get_summed_diff_double_of_squares) (LabelledControlArrayHandle handle, double other) <br> |
|  double | [**LabelledControlArray\_get\_summed\_diff\_int\_of\_squares**](#function-labelledcontrolarray_get_summed_diff_int_of_squares) (LabelledControlArrayHandle handle, int other) <br> |
|  FArrayDoubleHandle | [**LabelledControlArray\_gradient**](#function-labelledcontrolarray_gradient) (LabelledControlArrayHandle handle, size\_t axis) <br>_Return the gradient of the data along a given axis. Computes the gradient along the specified axis using finite differences:_  |
|  bool | [**LabelledControlArray\_greater\_than**](#function-labelledcontrolarray_greater_than) (LabelledControlArrayHandle handle, double value) <br> |
|  [**StringHandle**](structstring.md) | [**LabelledControlArray\_instrument\_type**](#function-labelledcontrolarray_instrument_type) (LabelledControlArrayHandle handle) <br> |
|  AcquisitionContextHandle | [**LabelledControlArray\_label**](#function-labelledcontrolarray_label) (LabelledControlArrayHandle handle) <br> |
|  bool | [**LabelledControlArray\_less\_than**](#function-labelledcontrolarray_less_than) (LabelledControlArrayHandle handle, double value) <br> |
|  double | [**LabelledControlArray\_max**](#function-labelledcontrolarray_max) (LabelledControlArrayHandle handle) <br>_Return the maximum value of the array._  |
|  LabelledControlArrayHandle | [**LabelledControlArray\_max\_control\_array**](#function-labelledcontrolarray_max_control_array) (LabelledControlArrayHandle handle, LabelledControlArrayHandle other) <br> |
|  LabelledControlArrayHandle | [**LabelledControlArray\_max\_farray**](#function-labelledcontrolarray_max_farray) (LabelledControlArrayHandle handle, FArrayDoubleHandle other) <br> |
|  double | [**LabelledControlArray\_min**](#function-labelledcontrolarray_min) (LabelledControlArrayHandle handle) <br>_Return the minimum value of the array._  |
|  LabelledControlArrayHandle | [**LabelledControlArray\_min\_control\_array**](#function-labelledcontrolarray_min_control_array) (LabelledControlArrayHandle handle, LabelledControlArrayHandle other) <br> |
|  LabelledControlArrayHandle | [**LabelledControlArray\_min\_farray**](#function-labelledcontrolarray_min_farray) (LabelledControlArrayHandle handle, FArrayDoubleHandle other) <br> |
|  LabelledControlArrayHandle | [**LabelledControlArray\_minus\_control\_array**](#function-labelledcontrolarray_minus_control_array) (LabelledControlArrayHandle handle, LabelledControlArrayHandle other) <br> |
|  LabelledControlArrayHandle | [**LabelledControlArray\_minus\_double**](#function-labelledcontrolarray_minus_double) (LabelledControlArrayHandle handle, double other) <br> |
|  void | [**LabelledControlArray\_minus\_equals\_control\_array**](#function-labelledcontrolarray_minus_equals_control_array) (LabelledControlArrayHandle handle, LabelledControlArrayHandle other) <br> |
|  void | [**LabelledControlArray\_minus\_equals\_double**](#function-labelledcontrolarray_minus_equals_double) (LabelledControlArrayHandle handle, double other) <br> |
|  void | [**LabelledControlArray\_minus\_equals\_farray**](#function-labelledcontrolarray_minus_equals_farray) (LabelledControlArrayHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**LabelledControlArray\_minus\_equals\_int**](#function-labelledcontrolarray_minus_equals_int) (LabelledControlArrayHandle handle, int other) <br> |
|  LabelledControlArrayHandle | [**LabelledControlArray\_minus\_farray**](#function-labelledcontrolarray_minus_farray) (LabelledControlArrayHandle handle, FArrayDoubleHandle other) <br> |
|  LabelledControlArrayHandle | [**LabelledControlArray\_minus\_int**](#function-labelledcontrolarray_minus_int) (LabelledControlArrayHandle handle, int other) <br> |
|  LabelledControlArrayHandle | [**LabelledControlArray\_negation**](#function-labelledcontrolarray_negation) (LabelledControlArrayHandle handle) <br> |
|  bool | [**LabelledControlArray\_not\_equal**](#function-labelledcontrolarray_not_equal) (LabelledControlArrayHandle handle, LabelledControlArrayHandle other) <br> |
|  LabelledControlArrayHandle | [**LabelledControlArray\_plus\_control\_array**](#function-labelledcontrolarray_plus_control_array) (LabelledControlArrayHandle handle, LabelledControlArrayHandle other) <br> |
|  LabelledControlArrayHandle | [**LabelledControlArray\_plus\_double**](#function-labelledcontrolarray_plus_double) (LabelledControlArrayHandle handle, double other) <br> |
|  void | [**LabelledControlArray\_plus\_equals\_double**](#function-labelledcontrolarray_plus_equals_double) (LabelledControlArrayHandle handle, double other) <br> |
|  void | [**LabelledControlArray\_plus\_equals\_farray**](#function-labelledcontrolarray_plus_equals_farray) (LabelledControlArrayHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**LabelledControlArray\_plus\_equals\_int**](#function-labelledcontrolarray_plus_equals_int) (LabelledControlArrayHandle handle, int other) <br> |
|  LabelledControlArrayHandle | [**LabelledControlArray\_plus\_farray**](#function-labelledcontrolarray_plus_farray) (LabelledControlArrayHandle handle, FArrayDoubleHandle other) <br> |
|  LabelledControlArrayHandle | [**LabelledControlArray\_plus\_int**](#function-labelledcontrolarray_plus_int) (LabelledControlArrayHandle handle, int other) <br> |
|  LabelledControlArrayHandle | [**LabelledControlArray\_pow**](#function-labelledcontrolarray_pow) (LabelledControlArrayHandle handle, double other) <br> |
|  void | [**LabelledControlArray\_remove\_offset**](#function-labelledcontrolarray_remove_offset) (LabelledControlArrayHandle handle, double offset) <br> |
|  size\_t | [**LabelledControlArray\_shape**](#function-labelledcontrolarray_shape) (LabelledControlArrayHandle handle, size\_t \* out\_buffer, size\_t ndim) <br> |
|  size\_t | [**LabelledControlArray\_size**](#function-labelledcontrolarray_size) (LabelledControlArrayHandle handle) <br> |
|  double | [**LabelledControlArray\_sum**](#function-labelledcontrolarray_sum) (LabelledControlArrayHandle handle) <br> |
|  LabelledControlArrayHandle | [**LabelledControlArray\_times\_double**](#function-labelledcontrolarray_times_double) (LabelledControlArrayHandle handle, double other) <br> |
|  void | [**LabelledControlArray\_times\_equals\_double**](#function-labelledcontrolarray_times_equals_double) (LabelledControlArrayHandle handle, double other) <br> |
|  void | [**LabelledControlArray\_times\_equals\_int**](#function-labelledcontrolarray_times_equals_int) (LabelledControlArrayHandle handle, int other) <br> |
|  LabelledControlArrayHandle | [**LabelledControlArray\_times\_int**](#function-labelledcontrolarray_times_int) (LabelledControlArrayHandle handle, int other) <br> |
|  [**StringHandle**](structstring.md) | [**LabelledControlArray\_to\_json\_string**](#function-labelledcontrolarray_to_json_string) (LabelledControlArrayHandle handle) <br> |
|  SymbolUnitHandle | [**LabelledControlArray\_units**](#function-labelledcontrolarray_units) (LabelledControlArrayHandle handle) <br> |
|  ListListSizeTHandle | [**LabelledControlArray\_where**](#function-labelledcontrolarray_where) (LabelledControlArrayHandle handle, double value) <br> |




























## Public Types Documentation




### typedef LabelledControlArrayHandle 

```C++
typedef void* LabelledControlArrayHandle;
```




<hr>
## Public Functions Documentation




### function LabelledControlArray\_abs 

```C++
LabelledControlArrayHandle LabelledControlArray_abs (
    LabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledControlArray\_connection 

```C++
ConnectionHandle LabelledControlArray_connection (
    LabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledControlArray\_copy 

```C++
LabelledControlArrayHandle LabelledControlArray_copy (
    LabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledControlArray\_data 

```C++
size_t LabelledControlArray_data (
    LabelledControlArrayHandle handle,
    double * out_buffer,
    size_t numdata
) 
```




<hr>



### function LabelledControlArray\_destroy 

```C++
void LabelledControlArray_destroy (
    LabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledControlArray\_dimension 

```C++
size_t LabelledControlArray_dimension (
    LabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledControlArray\_divides\_double 

```C++
LabelledControlArrayHandle LabelledControlArray_divides_double (
    LabelledControlArrayHandle handle,
    double other
) 
```




<hr>



### function LabelledControlArray\_divides\_equals\_double 

```C++
void LabelledControlArray_divides_equals_double (
    LabelledControlArrayHandle handle,
    double other
) 
```




<hr>



### function LabelledControlArray\_divides\_equals\_int 

```C++
void LabelledControlArray_divides_equals_int (
    LabelledControlArrayHandle handle,
    int other
) 
```




<hr>



### function LabelledControlArray\_divides\_int 

```C++
LabelledControlArrayHandle LabelledControlArray_divides_int (
    LabelledControlArrayHandle handle,
    int other
) 
```




<hr>



### function LabelledControlArray\_equal 

```C++
bool LabelledControlArray_equal (
    LabelledControlArrayHandle handle,
    LabelledControlArrayHandle other
) 
```




<hr>



### function LabelledControlArray\_flip 

_Flip the data along the given axis._ 
```C++
LabelledControlArrayHandle LabelledControlArray_flip (
    LabelledControlArrayHandle handle,
    size_t axis
) 
```





**Parameters:**


* `axis` The axis to flip. 



**Returns:**

A flipped LabelledControlArray. 





        

<hr>



### function LabelledControlArray\_from\_control\_array 

```C++
LabelledControlArrayHandle LabelledControlArray_from_control_array (
    ControlArrayHandle controlarray,
    AcquisitionContextHandle label
) 
```




<hr>



### function LabelledControlArray\_from\_farray 

```C++
LabelledControlArrayHandle LabelledControlArray_from_farray (
    FArrayDoubleHandle farray,
    AcquisitionContextHandle label
) 
```




<hr>



### function LabelledControlArray\_from\_json\_string 

```C++
LabelledControlArrayHandle LabelledControlArray_from_json_string (
    StringHandle json
) 
```




<hr>



### function LabelledControlArray\_full\_gradient 

```C++
size_t LabelledControlArray_full_gradient (
    LabelledControlArrayHandle handle,
    FArrayDoubleHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function LabelledControlArray\_get\_sum\_of\_squares 

```C++
double LabelledControlArray_get_sum_of_squares (
    LabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledControlArray\_get\_summed\_diff\_array\_of\_squares 

```C++
double LabelledControlArray_get_summed_diff_array_of_squares (
    LabelledControlArrayHandle handle,
    LabelledControlArrayHandle other
) 
```




<hr>



### function LabelledControlArray\_get\_summed\_diff\_double\_of\_squares 

```C++
double LabelledControlArray_get_summed_diff_double_of_squares (
    LabelledControlArrayHandle handle,
    double other
) 
```




<hr>



### function LabelledControlArray\_get\_summed\_diff\_int\_of\_squares 

```C++
double LabelledControlArray_get_summed_diff_int_of_squares (
    LabelledControlArrayHandle handle,
    int other
) 
```




<hr>



### function LabelledControlArray\_gradient 

_Return the gradient of the data along a given axis. Computes the gradient along the specified axis using finite differences:_ 
```C++
FArrayDoubleHandle LabelledControlArray_gradient (
    LabelledControlArrayHandle handle,
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



### function LabelledControlArray\_greater\_than 

```C++
bool LabelledControlArray_greater_than (
    LabelledControlArrayHandle handle,
    double value
) 
```




<hr>



### function LabelledControlArray\_instrument\_type 

```C++
StringHandle LabelledControlArray_instrument_type (
    LabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledControlArray\_label 

```C++
AcquisitionContextHandle LabelledControlArray_label (
    LabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledControlArray\_less\_than 

```C++
bool LabelledControlArray_less_than (
    LabelledControlArrayHandle handle,
    double value
) 
```




<hr>



### function LabelledControlArray\_max 

_Return the maximum value of the array._ 
```C++
double LabelledControlArray_max (
    LabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledControlArray\_max\_control\_array 

```C++
LabelledControlArrayHandle LabelledControlArray_max_control_array (
    LabelledControlArrayHandle handle,
    LabelledControlArrayHandle other
) 
```




<hr>



### function LabelledControlArray\_max\_farray 

```C++
LabelledControlArrayHandle LabelledControlArray_max_farray (
    LabelledControlArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledControlArray\_min 

_Return the minimum value of the array._ 
```C++
double LabelledControlArray_min (
    LabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledControlArray\_min\_control\_array 

```C++
LabelledControlArrayHandle LabelledControlArray_min_control_array (
    LabelledControlArrayHandle handle,
    LabelledControlArrayHandle other
) 
```




<hr>



### function LabelledControlArray\_min\_farray 

```C++
LabelledControlArrayHandle LabelledControlArray_min_farray (
    LabelledControlArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledControlArray\_minus\_control\_array 

```C++
LabelledControlArrayHandle LabelledControlArray_minus_control_array (
    LabelledControlArrayHandle handle,
    LabelledControlArrayHandle other
) 
```




<hr>



### function LabelledControlArray\_minus\_double 

```C++
LabelledControlArrayHandle LabelledControlArray_minus_double (
    LabelledControlArrayHandle handle,
    double other
) 
```




<hr>



### function LabelledControlArray\_minus\_equals\_control\_array 

```C++
void LabelledControlArray_minus_equals_control_array (
    LabelledControlArrayHandle handle,
    LabelledControlArrayHandle other
) 
```




<hr>



### function LabelledControlArray\_minus\_equals\_double 

```C++
void LabelledControlArray_minus_equals_double (
    LabelledControlArrayHandle handle,
    double other
) 
```




<hr>



### function LabelledControlArray\_minus\_equals\_farray 

```C++
void LabelledControlArray_minus_equals_farray (
    LabelledControlArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledControlArray\_minus\_equals\_int 

```C++
void LabelledControlArray_minus_equals_int (
    LabelledControlArrayHandle handle,
    int other
) 
```




<hr>



### function LabelledControlArray\_minus\_farray 

```C++
LabelledControlArrayHandle LabelledControlArray_minus_farray (
    LabelledControlArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledControlArray\_minus\_int 

```C++
LabelledControlArrayHandle LabelledControlArray_minus_int (
    LabelledControlArrayHandle handle,
    int other
) 
```




<hr>



### function LabelledControlArray\_negation 

```C++
LabelledControlArrayHandle LabelledControlArray_negation (
    LabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledControlArray\_not\_equal 

```C++
bool LabelledControlArray_not_equal (
    LabelledControlArrayHandle handle,
    LabelledControlArrayHandle other
) 
```




<hr>



### function LabelledControlArray\_plus\_control\_array 

```C++
LabelledControlArrayHandle LabelledControlArray_plus_control_array (
    LabelledControlArrayHandle handle,
    LabelledControlArrayHandle other
) 
```




<hr>



### function LabelledControlArray\_plus\_double 

```C++
LabelledControlArrayHandle LabelledControlArray_plus_double (
    LabelledControlArrayHandle handle,
    double other
) 
```




<hr>



### function LabelledControlArray\_plus\_equals\_double 

```C++
void LabelledControlArray_plus_equals_double (
    LabelledControlArrayHandle handle,
    double other
) 
```




<hr>



### function LabelledControlArray\_plus\_equals\_farray 

```C++
void LabelledControlArray_plus_equals_farray (
    LabelledControlArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledControlArray\_plus\_equals\_int 

```C++
void LabelledControlArray_plus_equals_int (
    LabelledControlArrayHandle handle,
    int other
) 
```




<hr>



### function LabelledControlArray\_plus\_farray 

```C++
LabelledControlArrayHandle LabelledControlArray_plus_farray (
    LabelledControlArrayHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledControlArray\_plus\_int 

```C++
LabelledControlArrayHandle LabelledControlArray_plus_int (
    LabelledControlArrayHandle handle,
    int other
) 
```




<hr>



### function LabelledControlArray\_pow 

```C++
LabelledControlArrayHandle LabelledControlArray_pow (
    LabelledControlArrayHandle handle,
    double other
) 
```




<hr>



### function LabelledControlArray\_remove\_offset 

```C++
void LabelledControlArray_remove_offset (
    LabelledControlArrayHandle handle,
    double offset
) 
```




<hr>



### function LabelledControlArray\_shape 

```C++
size_t LabelledControlArray_shape (
    LabelledControlArrayHandle handle,
    size_t * out_buffer,
    size_t ndim
) 
```




<hr>



### function LabelledControlArray\_size 

```C++
size_t LabelledControlArray_size (
    LabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledControlArray\_sum 

```C++
double LabelledControlArray_sum (
    LabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledControlArray\_times\_double 

```C++
LabelledControlArrayHandle LabelledControlArray_times_double (
    LabelledControlArrayHandle handle,
    double other
) 
```




<hr>



### function LabelledControlArray\_times\_equals\_double 

```C++
void LabelledControlArray_times_equals_double (
    LabelledControlArrayHandle handle,
    double other
) 
```




<hr>



### function LabelledControlArray\_times\_equals\_int 

```C++
void LabelledControlArray_times_equals_int (
    LabelledControlArrayHandle handle,
    int other
) 
```




<hr>



### function LabelledControlArray\_times\_int 

```C++
LabelledControlArrayHandle LabelledControlArray_times_int (
    LabelledControlArrayHandle handle,
    int other
) 
```




<hr>



### function LabelledControlArray\_to\_json\_string 

```C++
StringHandle LabelledControlArray_to_json_string (
    LabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledControlArray\_units 

```C++
SymbolUnitHandle LabelledControlArray_units (
    LabelledControlArrayHandle handle
) 
```




<hr>



### function LabelledControlArray\_where 

```C++
ListListSizeTHandle LabelledControlArray_where (
    LabelledControlArrayHandle handle,
    double value
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/arrays/LabelledControlArray_c_api.h`

