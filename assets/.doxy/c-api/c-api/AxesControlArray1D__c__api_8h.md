

# File AxesControlArray1D\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AxesControlArray1D\_c\_api.h**](AxesControlArray1D__c__api_8h.md)

[Go to the source code of this file](AxesControlArray1D__c__api_8h_source.md)



* `#include "falcon_core/math/arrays/ControlArray1D_c_api.h"`
* `#include "falcon_core/generic/ListControlArray1D_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**AxesControlArray1DHandle**](#typedef-axescontrolarray1dhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ControlArray1DHandle | [**AxesControlArray1D\_at**](#function-axescontrolarray1d_at) (AxesControlArray1DHandle handle, size\_t idx) <br> |
|  void | [**AxesControlArray1D\_clear**](#function-axescontrolarray1d_clear) (AxesControlArray1DHandle handle) <br> |
|  bool | [**AxesControlArray1D\_contains**](#function-axescontrolarray1d_contains) (AxesControlArray1DHandle handle, ControlArray1DHandle value) <br> |
|  AxesControlArray1DHandle | [**AxesControlArray1D\_copy**](#function-axescontrolarray1d_copy) (AxesControlArray1DHandle handle) <br> |
|  AxesControlArray1DHandle | [**AxesControlArray1D\_create**](#function-axescontrolarray1d_create) (ListControlArray1DHandle data) <br> |
|  AxesControlArray1DHandle | [**AxesControlArray1D\_create\_empty**](#function-axescontrolarray1d_create_empty) () <br> |
|  void | [**AxesControlArray1D\_destroy**](#function-axescontrolarray1d_destroy) (AxesControlArray1DHandle handle) <br> |
|  bool | [**AxesControlArray1D\_empty**](#function-axescontrolarray1d_empty) (AxesControlArray1DHandle handle) <br> |
|  bool | [**AxesControlArray1D\_equal**](#function-axescontrolarray1d_equal) (AxesControlArray1DHandle handle, AxesControlArray1DHandle other) <br> |
|  void | [**AxesControlArray1D\_erase\_at**](#function-axescontrolarray1d_erase_at) (AxesControlArray1DHandle handle, size\_t idx) <br> |
|  AxesControlArray1DHandle | [**AxesControlArray1D\_from\_json\_string**](#function-axescontrolarray1d_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**AxesControlArray1D\_index**](#function-axescontrolarray1d_index) (AxesControlArray1DHandle handle, ControlArray1DHandle value) <br> |
|  AxesControlArray1DHandle | [**AxesControlArray1D\_intersection**](#function-axescontrolarray1d_intersection) (AxesControlArray1DHandle handle, AxesControlArray1DHandle other) <br> |
|  size\_t | [**AxesControlArray1D\_items**](#function-axescontrolarray1d_items) (AxesControlArray1DHandle handle, ControlArray1DHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**AxesControlArray1D\_not\_equal**](#function-axescontrolarray1d_not_equal) (AxesControlArray1DHandle handle, AxesControlArray1DHandle other) <br> |
|  void | [**AxesControlArray1D\_push\_back**](#function-axescontrolarray1d_push_back) (AxesControlArray1DHandle handle, ControlArray1DHandle value) <br> |
|  size\_t | [**AxesControlArray1D\_size**](#function-axescontrolarray1d_size) (AxesControlArray1DHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**AxesControlArray1D\_to\_json\_string**](#function-axescontrolarray1d_to_json_string) (AxesControlArray1DHandle handle) <br> |




























## Public Types Documentation




### typedef AxesControlArray1DHandle 

```C++
typedef void* AxesControlArray1DHandle;
```




<hr>
## Public Functions Documentation




### function AxesControlArray1D\_at 

```C++
ControlArray1DHandle AxesControlArray1D_at (
    AxesControlArray1DHandle handle,
    size_t idx
) 
```




<hr>



### function AxesControlArray1D\_clear 

```C++
void AxesControlArray1D_clear (
    AxesControlArray1DHandle handle
) 
```




<hr>



### function AxesControlArray1D\_contains 

```C++
bool AxesControlArray1D_contains (
    AxesControlArray1DHandle handle,
    ControlArray1DHandle value
) 
```




<hr>



### function AxesControlArray1D\_copy 

```C++
AxesControlArray1DHandle AxesControlArray1D_copy (
    AxesControlArray1DHandle handle
) 
```




<hr>



### function AxesControlArray1D\_create 

```C++
AxesControlArray1DHandle AxesControlArray1D_create (
    ListControlArray1DHandle data
) 
```




<hr>



### function AxesControlArray1D\_create\_empty 

```C++
AxesControlArray1DHandle AxesControlArray1D_create_empty () 
```




<hr>



### function AxesControlArray1D\_destroy 

```C++
void AxesControlArray1D_destroy (
    AxesControlArray1DHandle handle
) 
```




<hr>



### function AxesControlArray1D\_empty 

```C++
bool AxesControlArray1D_empty (
    AxesControlArray1DHandle handle
) 
```




<hr>



### function AxesControlArray1D\_equal 

```C++
bool AxesControlArray1D_equal (
    AxesControlArray1DHandle handle,
    AxesControlArray1DHandle other
) 
```




<hr>



### function AxesControlArray1D\_erase\_at 

```C++
void AxesControlArray1D_erase_at (
    AxesControlArray1DHandle handle,
    size_t idx
) 
```




<hr>



### function AxesControlArray1D\_from\_json\_string 

```C++
AxesControlArray1DHandle AxesControlArray1D_from_json_string (
    StringHandle json
) 
```




<hr>



### function AxesControlArray1D\_index 

```C++
size_t AxesControlArray1D_index (
    AxesControlArray1DHandle handle,
    ControlArray1DHandle value
) 
```




<hr>



### function AxesControlArray1D\_intersection 

```C++
AxesControlArray1DHandle AxesControlArray1D_intersection (
    AxesControlArray1DHandle handle,
    AxesControlArray1DHandle other
) 
```




<hr>



### function AxesControlArray1D\_items 

```C++
size_t AxesControlArray1D_items (
    AxesControlArray1DHandle handle,
    ControlArray1DHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function AxesControlArray1D\_not\_equal 

```C++
bool AxesControlArray1D_not_equal (
    AxesControlArray1DHandle handle,
    AxesControlArray1DHandle other
) 
```




<hr>



### function AxesControlArray1D\_push\_back 

```C++
void AxesControlArray1D_push_back (
    AxesControlArray1DHandle handle,
    ControlArray1DHandle value
) 
```




<hr>



### function AxesControlArray1D\_size 

```C++
size_t AxesControlArray1D_size (
    AxesControlArray1DHandle handle
) 
```




<hr>



### function AxesControlArray1D\_to\_json\_string 

```C++
StringHandle AxesControlArray1D_to_json_string (
    AxesControlArray1DHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/AxesControlArray1D_c_api.h`

