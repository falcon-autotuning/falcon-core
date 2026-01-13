

# File UnitSpace\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**UnitSpace\_c\_api.h**](UnitSpace__c__api_8h.md)

[Go to the source code of this file](UnitSpace__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include "falcon_core/generic/FArrayDouble_c_api.h"`
* `#include "falcon_core/generic/ListInt_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/math/AxesControlArray_c_api.h"`
* `#include "falcon_core/math/AxesDiscretizer_c_api.h"`
* `#include "falcon_core/math/AxesDouble_c_api.h"`
* `#include "falcon_core/math/AxesInt_c_api.h"`
* `#include "falcon_core/math/discrete_spaces/Discretizer_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**UnitSpaceHandle**](#typedef-unitspacehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  DiscretizerHandle | [**UnitSpace\_at**](#function-unitspace_at) (UnitSpaceHandle handle, size\_t idx) <br> |
|  AxesDiscretizerHandle | [**UnitSpace\_axes**](#function-unitspace_axes) (UnitSpaceHandle handle) <br>_Return the axes of the space._  |
|  void | [**UnitSpace\_clear**](#function-unitspace_clear) (UnitSpaceHandle handle) <br> |
|  void | [**UnitSpace\_compile**](#function-unitspace_compile) (UnitSpaceHandle handle) <br>_Compile the unit space into a space._  |
|  bool | [**UnitSpace\_contains**](#function-unitspace_contains) (UnitSpaceHandle handle, DiscretizerHandle value) <br> |
|  UnitSpaceHandle | [**UnitSpace\_copy**](#function-unitspace_copy) (UnitSpaceHandle handle) <br> |
|  UnitSpaceHandle | [**UnitSpace\_create**](#function-unitspace_create) (AxesDiscretizerHandle axes, DomainHandle domain) <br> |
|  AxesControlArrayHandle | [**UnitSpace\_create\_array**](#function-unitspace_create_array) (UnitSpaceHandle handle, AxesIntHandle axes) <br>_Return the projection of the space onto the given axes. The projection contains the indexes of the axes to project onto._  |
|  UnitSpaceHandle | [**UnitSpace\_create\_cartesian\_1D\_space**](#function-unitspace_create_cartesian_1d_space) (double delta, DomainHandle domain) <br> |
|  UnitSpaceHandle | [**UnitSpace\_create\_cartesian\_2D\_space**](#function-unitspace_create_cartesian_2d_space) (AxesDoubleHandle deltas, DomainHandle domain) <br> |
|  UnitSpaceHandle | [**UnitSpace\_create\_cartesian\_space**](#function-unitspace_create_cartesian_space) (AxesDoubleHandle deltas, DomainHandle domain) <br> |
|  UnitSpaceHandle | [**UnitSpace\_create\_ray\_space**](#function-unitspace_create_ray_space) (double dr, double dtheta, DomainHandle domain) <br> |
|  void | [**UnitSpace\_destroy**](#function-unitspace_destroy) (UnitSpaceHandle handle) <br> |
|  size\_t | [**UnitSpace\_dimension**](#function-unitspace_dimension) (UnitSpaceHandle handle) <br>_Return the number of dimensions in the space._  |
|  DomainHandle | [**UnitSpace\_domain**](#function-unitspace_domain) (UnitSpaceHandle handle) <br>_Return the domain of the space._  |
|  bool | [**UnitSpace\_empty**](#function-unitspace_empty) (UnitSpaceHandle handle) <br> |
|  bool | [**UnitSpace\_equal**](#function-unitspace_equal) (UnitSpaceHandle handle, UnitSpaceHandle other) <br> |
|  void | [**UnitSpace\_erase\_at**](#function-unitspace_erase_at) (UnitSpaceHandle handle, size\_t idx) <br> |
|  UnitSpaceHandle | [**UnitSpace\_from\_json\_string**](#function-unitspace_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**UnitSpace\_index**](#function-unitspace_index) (UnitSpaceHandle handle, DiscretizerHandle value) <br> |
|  UnitSpaceHandle | [**UnitSpace\_intersection**](#function-unitspace_intersection) (UnitSpaceHandle handle, UnitSpaceHandle other) <br> |
|  size\_t | [**UnitSpace\_items**](#function-unitspace_items) (UnitSpaceHandle handle, DiscretizerHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**UnitSpace\_not\_equal**](#function-unitspace_not_equal) (UnitSpaceHandle handle, UnitSpaceHandle other) <br> |
|  void | [**UnitSpace\_push\_back**](#function-unitspace_push_back) (UnitSpaceHandle handle, DiscretizerHandle value) <br> |
|  ListIntHandle | [**UnitSpace\_shape**](#function-unitspace_shape) (UnitSpaceHandle handle) <br>_Return the shape of the unit space._  |
|  size\_t | [**UnitSpace\_size**](#function-unitspace_size) (UnitSpaceHandle handle) <br> |
|  FArrayDoubleHandle | [**UnitSpace\_space**](#function-unitspace_space) (UnitSpaceHandle handle) <br>_Return the stored space._  |
|  [**StringHandle**](structstring.md) | [**UnitSpace\_to\_json\_string**](#function-unitspace_to_json_string) (UnitSpaceHandle handle) <br> |




























## Public Types Documentation




### typedef UnitSpaceHandle 

```C++
typedef void* UnitSpaceHandle;
```




<hr>
## Public Functions Documentation




### function UnitSpace\_at 

```C++
DiscretizerHandle UnitSpace_at (
    UnitSpaceHandle handle,
    size_t idx
) 
```




<hr>



### function UnitSpace\_axes 

_Return the axes of the space._ 
```C++
AxesDiscretizerHandle UnitSpace_axes (
    UnitSpaceHandle handle
) 
```




<hr>



### function UnitSpace\_clear 

```C++
void UnitSpace_clear (
    UnitSpaceHandle handle
) 
```




<hr>



### function UnitSpace\_compile 

_Compile the unit space into a space._ 
```C++
void UnitSpace_compile (
    UnitSpaceHandle handle
) 
```




<hr>



### function UnitSpace\_contains 

```C++
bool UnitSpace_contains (
    UnitSpaceHandle handle,
    DiscretizerHandle value
) 
```




<hr>



### function UnitSpace\_copy 

```C++
UnitSpaceHandle UnitSpace_copy (
    UnitSpaceHandle handle
) 
```




<hr>



### function UnitSpace\_create 

```C++
UnitSpaceHandle UnitSpace_create (
    AxesDiscretizerHandle axes,
    DomainHandle domain
) 
```




<hr>



### function UnitSpace\_create\_array 

_Return the projection of the space onto the given axes. The projection contains the indexes of the axes to project onto._ 
```C++
AxesControlArrayHandle UnitSpace_create_array (
    UnitSpaceHandle handle,
    AxesIntHandle axes
) 
```





**Parameters:**


* `axes` The axes to project onto. 



**Returns:**

A set of proper Control Arrays 





        

<hr>



### function UnitSpace\_create\_cartesian\_1D\_space 

```C++
UnitSpaceHandle UnitSpace_create_cartesian_1D_space (
    double delta,
    DomainHandle domain
) 
```




<hr>



### function UnitSpace\_create\_cartesian\_2D\_space 

```C++
UnitSpaceHandle UnitSpace_create_cartesian_2D_space (
    AxesDoubleHandle deltas,
    DomainHandle domain
) 
```




<hr>



### function UnitSpace\_create\_cartesian\_space 

```C++
UnitSpaceHandle UnitSpace_create_cartesian_space (
    AxesDoubleHandle deltas,
    DomainHandle domain
) 
```




<hr>



### function UnitSpace\_create\_ray\_space 

```C++
UnitSpaceHandle UnitSpace_create_ray_space (
    double dr,
    double dtheta,
    DomainHandle domain
) 
```




<hr>



### function UnitSpace\_destroy 

```C++
void UnitSpace_destroy (
    UnitSpaceHandle handle
) 
```




<hr>



### function UnitSpace\_dimension 

_Return the number of dimensions in the space._ 
```C++
size_t UnitSpace_dimension (
    UnitSpaceHandle handle
) 
```




<hr>



### function UnitSpace\_domain 

_Return the domain of the space._ 
```C++
DomainHandle UnitSpace_domain (
    UnitSpaceHandle handle
) 
```




<hr>



### function UnitSpace\_empty 

```C++
bool UnitSpace_empty (
    UnitSpaceHandle handle
) 
```




<hr>



### function UnitSpace\_equal 

```C++
bool UnitSpace_equal (
    UnitSpaceHandle handle,
    UnitSpaceHandle other
) 
```




<hr>



### function UnitSpace\_erase\_at 

```C++
void UnitSpace_erase_at (
    UnitSpaceHandle handle,
    size_t idx
) 
```




<hr>



### function UnitSpace\_from\_json\_string 

```C++
UnitSpaceHandle UnitSpace_from_json_string (
    StringHandle json
) 
```




<hr>



### function UnitSpace\_index 

```C++
size_t UnitSpace_index (
    UnitSpaceHandle handle,
    DiscretizerHandle value
) 
```




<hr>



### function UnitSpace\_intersection 

```C++
UnitSpaceHandle UnitSpace_intersection (
    UnitSpaceHandle handle,
    UnitSpaceHandle other
) 
```




<hr>



### function UnitSpace\_items 

```C++
size_t UnitSpace_items (
    UnitSpaceHandle handle,
    DiscretizerHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function UnitSpace\_not\_equal 

```C++
bool UnitSpace_not_equal (
    UnitSpaceHandle handle,
    UnitSpaceHandle other
) 
```




<hr>



### function UnitSpace\_push\_back 

```C++
void UnitSpace_push_back (
    UnitSpaceHandle handle,
    DiscretizerHandle value
) 
```




<hr>



### function UnitSpace\_shape 

_Return the shape of the unit space._ 
```C++
ListIntHandle UnitSpace_shape (
    UnitSpaceHandle handle
) 
```




<hr>



### function UnitSpace\_size 

```C++
size_t UnitSpace_size (
    UnitSpaceHandle handle
) 
```




<hr>



### function UnitSpace\_space 

_Return the stored space._ 
```C++
FArrayDoubleHandle UnitSpace_space (
    UnitSpaceHandle handle
) 
```




<hr>



### function UnitSpace\_to\_json\_string 

```C++
StringHandle UnitSpace_to_json_string (
    UnitSpaceHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/UnitSpace_c_api.h`

