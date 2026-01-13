

# File LabelledControlArray1D\_c\_api.h



[**FileList**](files.md) **>** [**arrays**](dir_bfe73c8db2db54615e75c4ba09b4f73a.md) **>** [**LabelledControlArray1D\_c\_api.h**](LabelledControlArray1D__c__api_8h.md)

[Go to the source code of this file](LabelledControlArray1D__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext_c_api.h"`
* `#include "falcon_core/generic/FArrayDouble_c_api.h"`
* `#include "falcon_core/generic/ListFArrayDouble_c_api.h"`
* `#include "falcon_core/generic/ListListSizeT_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/math/arrays/ControlArray_c_api.h"`
* `#include "falcon_core/physics/units/SymbolUnit_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**LabelledControlArray1DHandle**](#typedef-labelledcontrolarray1dhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_abs**](#function-labelledcontrolarray1d_abs) (LabelledControlArray1DHandle handle) <br> |
|  FArrayDoubleHandle | [**LabelledControlArray1D\_as\_1D**](#function-labelledcontrolarray1d_as_1d) (LabelledControlArray1DHandle handle) <br> |
|  ConnectionHandle | [**LabelledControlArray1D\_connection**](#function-labelledcontrolarray1d_connection) (LabelledControlArray1DHandle handle) <br> |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_copy**](#function-labelledcontrolarray1d_copy) (LabelledControlArray1DHandle handle) <br> |
|  size\_t | [**LabelledControlArray1D\_data**](#function-labelledcontrolarray1d_data) (LabelledControlArray1DHandle handle, double \* out\_buffer, size\_t numdata) <br> |
|  void | [**LabelledControlArray1D\_destroy**](#function-labelledcontrolarray1d_destroy) (LabelledControlArray1DHandle handle) <br> |
|  size\_t | [**LabelledControlArray1D\_dimension**](#function-labelledcontrolarray1d_dimension) (LabelledControlArray1DHandle handle) <br> |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_divides\_double**](#function-labelledcontrolarray1d_divides_double) (LabelledControlArray1DHandle handle, double other) <br> |
|  void | [**LabelledControlArray1D\_divides\_equals\_double**](#function-labelledcontrolarray1d_divides_equals_double) (LabelledControlArray1DHandle handle, double other) <br> |
|  void | [**LabelledControlArray1D\_divides\_equals\_int**](#function-labelledcontrolarray1d_divides_equals_int) (LabelledControlArray1DHandle handle, int other) <br> |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_divides\_int**](#function-labelledcontrolarray1d_divides_int) (LabelledControlArray1DHandle handle, int other) <br> |
|  bool | [**LabelledControlArray1D\_equal**](#function-labelledcontrolarray1d_equal) (LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other) <br> |
|  ListFArrayDoubleHandle | [**LabelledControlArray1D\_even\_divisions**](#function-labelledcontrolarray1d_even_divisions) (LabelledControlArray1DHandle handle, size\_t divisions) <br> |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_flip**](#function-labelledcontrolarray1d_flip) (LabelledControlArray1DHandle handle, size\_t axis) <br>_Flip the data along the given axis._  |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_from\_control\_array**](#function-labelledcontrolarray1d_from_control_array) (ControlArrayHandle controlarray, AcquisitionContextHandle label) <br> |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_from\_farray**](#function-labelledcontrolarray1d_from_farray) (FArrayDoubleHandle farray, AcquisitionContextHandle label) <br> |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_from\_json\_string**](#function-labelledcontrolarray1d_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**LabelledControlArray1D\_full\_gradient**](#function-labelledcontrolarray1d_full_gradient) (LabelledControlArray1DHandle handle, FArrayDoubleHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  size\_t | [**LabelledControlArray1D\_get\_closest\_index**](#function-labelledcontrolarray1d_get_closest_index) (LabelledControlArray1DHandle handle, double value) <br> |
|  double | [**LabelledControlArray1D\_get\_distance**](#function-labelledcontrolarray1d_get_distance) (LabelledControlArray1DHandle handle) <br> |
|  double | [**LabelledControlArray1D\_get\_end**](#function-labelledcontrolarray1d_get_end) (LabelledControlArray1DHandle handle) <br> |
|  double | [**LabelledControlArray1D\_get\_mean**](#function-labelledcontrolarray1d_get_mean) (LabelledControlArray1DHandle handle) <br> |
|  double | [**LabelledControlArray1D\_get\_start**](#function-labelledcontrolarray1d_get_start) (LabelledControlArray1DHandle handle) <br> |
|  double | [**LabelledControlArray1D\_get\_std**](#function-labelledcontrolarray1d_get_std) (LabelledControlArray1DHandle handle) <br> |
|  double | [**LabelledControlArray1D\_get\_sum\_of\_squares**](#function-labelledcontrolarray1d_get_sum_of_squares) (LabelledControlArray1DHandle handle) <br> |
|  double | [**LabelledControlArray1D\_get\_summed\_diff\_array\_of\_squares**](#function-labelledcontrolarray1d_get_summed_diff_array_of_squares) (LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other) <br> |
|  double | [**LabelledControlArray1D\_get\_summed\_diff\_double\_of\_squares**](#function-labelledcontrolarray1d_get_summed_diff_double_of_squares) (LabelledControlArray1DHandle handle, double other) <br> |
|  double | [**LabelledControlArray1D\_get\_summed\_diff\_int\_of\_squares**](#function-labelledcontrolarray1d_get_summed_diff_int_of_squares) (LabelledControlArray1DHandle handle, int other) <br> |
|  FArrayDoubleHandle | [**LabelledControlArray1D\_gradient**](#function-labelledcontrolarray1d_gradient) (LabelledControlArray1DHandle handle, size\_t axis) <br>_Return the gradient of the data along a given axis. Computes the gradient along the specified axis using finite differences:_  |
|  bool | [**LabelledControlArray1D\_greater\_than**](#function-labelledcontrolarray1d_greater_than) (LabelledControlArray1DHandle handle, double value) <br> |
|  [**StringHandle**](structstring.md) | [**LabelledControlArray1D\_instrument\_type**](#function-labelledcontrolarray1d_instrument_type) (LabelledControlArray1DHandle handle) <br> |
|  bool | [**LabelledControlArray1D\_is\_1D**](#function-labelledcontrolarray1d_is_1d) (LabelledControlArray1DHandle handle) <br> |
|  bool | [**LabelledControlArray1D\_is\_decreasing**](#function-labelledcontrolarray1d_is_decreasing) (LabelledControlArray1DHandle handle) <br> |
|  bool | [**LabelledControlArray1D\_is\_increasing**](#function-labelledcontrolarray1d_is_increasing) (LabelledControlArray1DHandle handle) <br> |
|  AcquisitionContextHandle | [**LabelledControlArray1D\_label**](#function-labelledcontrolarray1d_label) (LabelledControlArray1DHandle handle) <br> |
|  bool | [**LabelledControlArray1D\_less\_than**](#function-labelledcontrolarray1d_less_than) (LabelledControlArray1DHandle handle, double value) <br> |
|  double | [**LabelledControlArray1D\_max**](#function-labelledcontrolarray1d_max) (LabelledControlArray1DHandle handle) <br>_Return the maximum value of the array._  |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_max\_control\_array**](#function-labelledcontrolarray1d_max_control_array) (LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other) <br> |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_max\_farray**](#function-labelledcontrolarray1d_max_farray) (LabelledControlArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  double | [**LabelledControlArray1D\_min**](#function-labelledcontrolarray1d_min) (LabelledControlArray1DHandle handle) <br>_Return the minimum value of the array._  |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_min\_control\_array**](#function-labelledcontrolarray1d_min_control_array) (LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other) <br> |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_min\_farray**](#function-labelledcontrolarray1d_min_farray) (LabelledControlArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_minus\_control\_array**](#function-labelledcontrolarray1d_minus_control_array) (LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other) <br> |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_minus\_double**](#function-labelledcontrolarray1d_minus_double) (LabelledControlArray1DHandle handle, double other) <br> |
|  void | [**LabelledControlArray1D\_minus\_equals\_double**](#function-labelledcontrolarray1d_minus_equals_double) (LabelledControlArray1DHandle handle, double other) <br> |
|  void | [**LabelledControlArray1D\_minus\_equals\_farray**](#function-labelledcontrolarray1d_minus_equals_farray) (LabelledControlArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**LabelledControlArray1D\_minus\_equals\_int**](#function-labelledcontrolarray1d_minus_equals_int) (LabelledControlArray1DHandle handle, int other) <br> |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_minus\_farray**](#function-labelledcontrolarray1d_minus_farray) (LabelledControlArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_minus\_int**](#function-labelledcontrolarray1d_minus_int) (LabelledControlArray1DHandle handle, int other) <br> |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_negation**](#function-labelledcontrolarray1d_negation) (LabelledControlArray1DHandle handle) <br> |
|  bool | [**LabelledControlArray1D\_not\_equal**](#function-labelledcontrolarray1d_not_equal) (LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other) <br> |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_plus\_control\_array**](#function-labelledcontrolarray1d_plus_control_array) (LabelledControlArray1DHandle handle, LabelledControlArray1DHandle other) <br> |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_plus\_double**](#function-labelledcontrolarray1d_plus_double) (LabelledControlArray1DHandle handle, double other) <br> |
|  void | [**LabelledControlArray1D\_plus\_equals\_double**](#function-labelledcontrolarray1d_plus_equals_double) (LabelledControlArray1DHandle handle, double other) <br> |
|  void | [**LabelledControlArray1D\_plus\_equals\_farray**](#function-labelledcontrolarray1d_plus_equals_farray) (LabelledControlArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  void | [**LabelledControlArray1D\_plus\_equals\_int**](#function-labelledcontrolarray1d_plus_equals_int) (LabelledControlArray1DHandle handle, int other) <br> |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_plus\_farray**](#function-labelledcontrolarray1d_plus_farray) (LabelledControlArray1DHandle handle, FArrayDoubleHandle other) <br> |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_plus\_int**](#function-labelledcontrolarray1d_plus_int) (LabelledControlArray1DHandle handle, int other) <br> |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_pow**](#function-labelledcontrolarray1d_pow) (LabelledControlArray1DHandle handle, double other) <br> |
|  void | [**LabelledControlArray1D\_remove\_offset**](#function-labelledcontrolarray1d_remove_offset) (LabelledControlArray1DHandle handle, double offset) <br> |
|  void | [**LabelledControlArray1D\_reverse**](#function-labelledcontrolarray1d_reverse) (LabelledControlArray1DHandle handle) <br> |
|  size\_t | [**LabelledControlArray1D\_shape**](#function-labelledcontrolarray1d_shape) (LabelledControlArray1DHandle handle, size\_t \* out\_buffer, size\_t ndim) <br> |
|  size\_t | [**LabelledControlArray1D\_size**](#function-labelledcontrolarray1d_size) (LabelledControlArray1DHandle handle) <br> |
|  double | [**LabelledControlArray1D\_sum**](#function-labelledcontrolarray1d_sum) (LabelledControlArray1DHandle handle) <br> |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_times\_double**](#function-labelledcontrolarray1d_times_double) (LabelledControlArray1DHandle handle, double other) <br> |
|  void | [**LabelledControlArray1D\_times\_equals\_double**](#function-labelledcontrolarray1d_times_equals_double) (LabelledControlArray1DHandle handle, double other) <br> |
|  void | [**LabelledControlArray1D\_times\_equals\_int**](#function-labelledcontrolarray1d_times_equals_int) (LabelledControlArray1DHandle handle, int other) <br> |
|  LabelledControlArray1DHandle | [**LabelledControlArray1D\_times\_int**](#function-labelledcontrolarray1d_times_int) (LabelledControlArray1DHandle handle, int other) <br> |
|  [**StringHandle**](structstring.md) | [**LabelledControlArray1D\_to\_json\_string**](#function-labelledcontrolarray1d_to_json_string) (LabelledControlArray1DHandle handle) <br> |
|  SymbolUnitHandle | [**LabelledControlArray1D\_units**](#function-labelledcontrolarray1d_units) (LabelledControlArray1DHandle handle) <br> |
|  ListListSizeTHandle | [**LabelledControlArray1D\_where**](#function-labelledcontrolarray1d_where) (LabelledControlArray1DHandle handle, double value) <br> |




























## Public Types Documentation




### typedef LabelledControlArray1DHandle 

```C++
typedef void* LabelledControlArray1DHandle;
```




<hr>
## Public Functions Documentation




### function LabelledControlArray1D\_abs 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_abs (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_as\_1D 

```C++
FArrayDoubleHandle LabelledControlArray1D_as_1D (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_connection 

```C++
ConnectionHandle LabelledControlArray1D_connection (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_copy 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_copy (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_data 

```C++
size_t LabelledControlArray1D_data (
    LabelledControlArray1DHandle handle,
    double * out_buffer,
    size_t numdata
) 
```




<hr>



### function LabelledControlArray1D\_destroy 

```C++
void LabelledControlArray1D_destroy (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_dimension 

```C++
size_t LabelledControlArray1D_dimension (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_divides\_double 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_divides_double (
    LabelledControlArray1DHandle handle,
    double other
) 
```




<hr>



### function LabelledControlArray1D\_divides\_equals\_double 

```C++
void LabelledControlArray1D_divides_equals_double (
    LabelledControlArray1DHandle handle,
    double other
) 
```




<hr>



### function LabelledControlArray1D\_divides\_equals\_int 

```C++
void LabelledControlArray1D_divides_equals_int (
    LabelledControlArray1DHandle handle,
    int other
) 
```




<hr>



### function LabelledControlArray1D\_divides\_int 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_divides_int (
    LabelledControlArray1DHandle handle,
    int other
) 
```




<hr>



### function LabelledControlArray1D\_equal 

```C++
bool LabelledControlArray1D_equal (
    LabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle other
) 
```




<hr>



### function LabelledControlArray1D\_even\_divisions 

```C++
ListFArrayDoubleHandle LabelledControlArray1D_even_divisions (
    LabelledControlArray1DHandle handle,
    size_t divisions
) 
```




<hr>



### function LabelledControlArray1D\_flip 

_Flip the data along the given axis._ 
```C++
LabelledControlArray1DHandle LabelledControlArray1D_flip (
    LabelledControlArray1DHandle handle,
    size_t axis
) 
```





**Parameters:**


* `axis` The axis to flip. 



**Returns:**

A flipped LabelledControlArray1D. 





        

<hr>



### function LabelledControlArray1D\_from\_control\_array 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_from_control_array (
    ControlArrayHandle controlarray,
    AcquisitionContextHandle label
) 
```




<hr>



### function LabelledControlArray1D\_from\_farray 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_from_farray (
    FArrayDoubleHandle farray,
    AcquisitionContextHandle label
) 
```




<hr>



### function LabelledControlArray1D\_from\_json\_string 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_from_json_string (
    StringHandle json
) 
```




<hr>



### function LabelledControlArray1D\_full\_gradient 

```C++
size_t LabelledControlArray1D_full_gradient (
    LabelledControlArray1DHandle handle,
    FArrayDoubleHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function LabelledControlArray1D\_get\_closest\_index 

```C++
size_t LabelledControlArray1D_get_closest_index (
    LabelledControlArray1DHandle handle,
    double value
) 
```




<hr>



### function LabelledControlArray1D\_get\_distance 

```C++
double LabelledControlArray1D_get_distance (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_get\_end 

```C++
double LabelledControlArray1D_get_end (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_get\_mean 

```C++
double LabelledControlArray1D_get_mean (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_get\_start 

```C++
double LabelledControlArray1D_get_start (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_get\_std 

```C++
double LabelledControlArray1D_get_std (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_get\_sum\_of\_squares 

```C++
double LabelledControlArray1D_get_sum_of_squares (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_get\_summed\_diff\_array\_of\_squares 

```C++
double LabelledControlArray1D_get_summed_diff_array_of_squares (
    LabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle other
) 
```




<hr>



### function LabelledControlArray1D\_get\_summed\_diff\_double\_of\_squares 

```C++
double LabelledControlArray1D_get_summed_diff_double_of_squares (
    LabelledControlArray1DHandle handle,
    double other
) 
```




<hr>



### function LabelledControlArray1D\_get\_summed\_diff\_int\_of\_squares 

```C++
double LabelledControlArray1D_get_summed_diff_int_of_squares (
    LabelledControlArray1DHandle handle,
    int other
) 
```




<hr>



### function LabelledControlArray1D\_gradient 

_Return the gradient of the data along a given axis. Computes the gradient along the specified axis using finite differences:_ 
```C++
FArrayDoubleHandle LabelledControlArray1D_gradient (
    LabelledControlArray1DHandle handle,
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



### function LabelledControlArray1D\_greater\_than 

```C++
bool LabelledControlArray1D_greater_than (
    LabelledControlArray1DHandle handle,
    double value
) 
```




<hr>



### function LabelledControlArray1D\_instrument\_type 

```C++
StringHandle LabelledControlArray1D_instrument_type (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_is\_1D 

```C++
bool LabelledControlArray1D_is_1D (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_is\_decreasing 

```C++
bool LabelledControlArray1D_is_decreasing (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_is\_increasing 

```C++
bool LabelledControlArray1D_is_increasing (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_label 

```C++
AcquisitionContextHandle LabelledControlArray1D_label (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_less\_than 

```C++
bool LabelledControlArray1D_less_than (
    LabelledControlArray1DHandle handle,
    double value
) 
```




<hr>



### function LabelledControlArray1D\_max 

_Return the maximum value of the array._ 
```C++
double LabelledControlArray1D_max (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_max\_control\_array 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_max_control_array (
    LabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle other
) 
```




<hr>



### function LabelledControlArray1D\_max\_farray 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_max_farray (
    LabelledControlArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledControlArray1D\_min 

_Return the minimum value of the array._ 
```C++
double LabelledControlArray1D_min (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_min\_control\_array 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_min_control_array (
    LabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle other
) 
```




<hr>



### function LabelledControlArray1D\_min\_farray 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_min_farray (
    LabelledControlArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledControlArray1D\_minus\_control\_array 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_minus_control_array (
    LabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle other
) 
```




<hr>



### function LabelledControlArray1D\_minus\_double 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_minus_double (
    LabelledControlArray1DHandle handle,
    double other
) 
```




<hr>



### function LabelledControlArray1D\_minus\_equals\_double 

```C++
void LabelledControlArray1D_minus_equals_double (
    LabelledControlArray1DHandle handle,
    double other
) 
```




<hr>



### function LabelledControlArray1D\_minus\_equals\_farray 

```C++
void LabelledControlArray1D_minus_equals_farray (
    LabelledControlArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledControlArray1D\_minus\_equals\_int 

```C++
void LabelledControlArray1D_minus_equals_int (
    LabelledControlArray1DHandle handle,
    int other
) 
```




<hr>



### function LabelledControlArray1D\_minus\_farray 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_minus_farray (
    LabelledControlArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledControlArray1D\_minus\_int 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_minus_int (
    LabelledControlArray1DHandle handle,
    int other
) 
```




<hr>



### function LabelledControlArray1D\_negation 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_negation (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_not\_equal 

```C++
bool LabelledControlArray1D_not_equal (
    LabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle other
) 
```




<hr>



### function LabelledControlArray1D\_plus\_control\_array 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_plus_control_array (
    LabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle other
) 
```




<hr>



### function LabelledControlArray1D\_plus\_double 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_plus_double (
    LabelledControlArray1DHandle handle,
    double other
) 
```




<hr>



### function LabelledControlArray1D\_plus\_equals\_double 

```C++
void LabelledControlArray1D_plus_equals_double (
    LabelledControlArray1DHandle handle,
    double other
) 
```




<hr>



### function LabelledControlArray1D\_plus\_equals\_farray 

```C++
void LabelledControlArray1D_plus_equals_farray (
    LabelledControlArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledControlArray1D\_plus\_equals\_int 

```C++
void LabelledControlArray1D_plus_equals_int (
    LabelledControlArray1DHandle handle,
    int other
) 
```




<hr>



### function LabelledControlArray1D\_plus\_farray 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_plus_farray (
    LabelledControlArray1DHandle handle,
    FArrayDoubleHandle other
) 
```




<hr>



### function LabelledControlArray1D\_plus\_int 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_plus_int (
    LabelledControlArray1DHandle handle,
    int other
) 
```




<hr>



### function LabelledControlArray1D\_pow 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_pow (
    LabelledControlArray1DHandle handle,
    double other
) 
```




<hr>



### function LabelledControlArray1D\_remove\_offset 

```C++
void LabelledControlArray1D_remove_offset (
    LabelledControlArray1DHandle handle,
    double offset
) 
```




<hr>



### function LabelledControlArray1D\_reverse 

```C++
void LabelledControlArray1D_reverse (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_shape 

```C++
size_t LabelledControlArray1D_shape (
    LabelledControlArray1DHandle handle,
    size_t * out_buffer,
    size_t ndim
) 
```




<hr>



### function LabelledControlArray1D\_size 

```C++
size_t LabelledControlArray1D_size (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_sum 

```C++
double LabelledControlArray1D_sum (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_times\_double 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_times_double (
    LabelledControlArray1DHandle handle,
    double other
) 
```




<hr>



### function LabelledControlArray1D\_times\_equals\_double 

```C++
void LabelledControlArray1D_times_equals_double (
    LabelledControlArray1DHandle handle,
    double other
) 
```




<hr>



### function LabelledControlArray1D\_times\_equals\_int 

```C++
void LabelledControlArray1D_times_equals_int (
    LabelledControlArray1DHandle handle,
    int other
) 
```




<hr>



### function LabelledControlArray1D\_times\_int 

```C++
LabelledControlArray1DHandle LabelledControlArray1D_times_int (
    LabelledControlArray1DHandle handle,
    int other
) 
```




<hr>



### function LabelledControlArray1D\_to\_json\_string 

```C++
StringHandle LabelledControlArray1D_to_json_string (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_units 

```C++
SymbolUnitHandle LabelledControlArray1D_units (
    LabelledControlArray1DHandle handle
) 
```




<hr>



### function LabelledControlArray1D\_where 

```C++
ListListSizeTHandle LabelledControlArray1D_where (
    LabelledControlArray1DHandle handle,
    double value
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/arrays/LabelledControlArray1D_c_api.h`

