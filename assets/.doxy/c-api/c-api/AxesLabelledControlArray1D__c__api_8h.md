

# File AxesLabelledControlArray1D\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AxesLabelledControlArray1D\_c\_api.h**](AxesLabelledControlArray1D__c__api_8h.md)

[Go to the source code of this file](AxesLabelledControlArray1D__c__api_8h_source.md)



* `#include "falcon_core/math/arrays/LabelledControlArray1D_c_api.h"`
* `#include "falcon_core/generic/ListLabelledControlArray1D_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**AxesLabelledControlArray1DHandle**](#typedef-axeslabelledcontrolarray1dhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  LabelledControlArray1DHandle | [**AxesLabelledControlArray1D\_at**](#function-axeslabelledcontrolarray1d_at) (AxesLabelledControlArray1DHandle handle, size\_t idx) <br> |
|  void | [**AxesLabelledControlArray1D\_clear**](#function-axeslabelledcontrolarray1d_clear) (AxesLabelledControlArray1DHandle handle) <br> |
|  bool | [**AxesLabelledControlArray1D\_contains**](#function-axeslabelledcontrolarray1d_contains) (AxesLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) <br> |
|  AxesLabelledControlArray1DHandle | [**AxesLabelledControlArray1D\_copy**](#function-axeslabelledcontrolarray1d_copy) (AxesLabelledControlArray1DHandle handle) <br> |
|  AxesLabelledControlArray1DHandle | [**AxesLabelledControlArray1D\_create**](#function-axeslabelledcontrolarray1d_create) (ListLabelledControlArray1DHandle data) <br> |
|  AxesLabelledControlArray1DHandle | [**AxesLabelledControlArray1D\_create\_empty**](#function-axeslabelledcontrolarray1d_create_empty) () <br> |
|  void | [**AxesLabelledControlArray1D\_destroy**](#function-axeslabelledcontrolarray1d_destroy) (AxesLabelledControlArray1DHandle handle) <br> |
|  bool | [**AxesLabelledControlArray1D\_empty**](#function-axeslabelledcontrolarray1d_empty) (AxesLabelledControlArray1DHandle handle) <br> |
|  bool | [**AxesLabelledControlArray1D\_equal**](#function-axeslabelledcontrolarray1d_equal) (AxesLabelledControlArray1DHandle handle, AxesLabelledControlArray1DHandle other) <br> |
|  void | [**AxesLabelledControlArray1D\_erase\_at**](#function-axeslabelledcontrolarray1d_erase_at) (AxesLabelledControlArray1DHandle handle, size\_t idx) <br> |
|  AxesLabelledControlArray1DHandle | [**AxesLabelledControlArray1D\_from\_json\_string**](#function-axeslabelledcontrolarray1d_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**AxesLabelledControlArray1D\_index**](#function-axeslabelledcontrolarray1d_index) (AxesLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) <br> |
|  AxesLabelledControlArray1DHandle | [**AxesLabelledControlArray1D\_intersection**](#function-axeslabelledcontrolarray1d_intersection) (AxesLabelledControlArray1DHandle handle, AxesLabelledControlArray1DHandle other) <br> |
|  size\_t | [**AxesLabelledControlArray1D\_items**](#function-axeslabelledcontrolarray1d_items) (AxesLabelledControlArray1DHandle handle, LabelledControlArray1DHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**AxesLabelledControlArray1D\_not\_equal**](#function-axeslabelledcontrolarray1d_not_equal) (AxesLabelledControlArray1DHandle handle, AxesLabelledControlArray1DHandle other) <br> |
|  void | [**AxesLabelledControlArray1D\_push\_back**](#function-axeslabelledcontrolarray1d_push_back) (AxesLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) <br> |
|  size\_t | [**AxesLabelledControlArray1D\_size**](#function-axeslabelledcontrolarray1d_size) (AxesLabelledControlArray1DHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**AxesLabelledControlArray1D\_to\_json\_string**](#function-axeslabelledcontrolarray1d_to_json_string) (AxesLabelledControlArray1DHandle handle) <br> |




























## Public Types Documentation




### typedef AxesLabelledControlArray1DHandle 

```C++
typedef void* AxesLabelledControlArray1DHandle;
```




<hr>
## Public Functions Documentation




### function AxesLabelledControlArray1D\_at 

```C++
LabelledControlArray1DHandle AxesLabelledControlArray1D_at (
    AxesLabelledControlArray1DHandle handle,
    size_t idx
) 
```




<hr>



### function AxesLabelledControlArray1D\_clear 

```C++
void AxesLabelledControlArray1D_clear (
    AxesLabelledControlArray1DHandle handle
) 
```




<hr>



### function AxesLabelledControlArray1D\_contains 

```C++
bool AxesLabelledControlArray1D_contains (
    AxesLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle value
) 
```




<hr>



### function AxesLabelledControlArray1D\_copy 

```C++
AxesLabelledControlArray1DHandle AxesLabelledControlArray1D_copy (
    AxesLabelledControlArray1DHandle handle
) 
```




<hr>



### function AxesLabelledControlArray1D\_create 

```C++
AxesLabelledControlArray1DHandle AxesLabelledControlArray1D_create (
    ListLabelledControlArray1DHandle data
) 
```




<hr>



### function AxesLabelledControlArray1D\_create\_empty 

```C++
AxesLabelledControlArray1DHandle AxesLabelledControlArray1D_create_empty () 
```




<hr>



### function AxesLabelledControlArray1D\_destroy 

```C++
void AxesLabelledControlArray1D_destroy (
    AxesLabelledControlArray1DHandle handle
) 
```




<hr>



### function AxesLabelledControlArray1D\_empty 

```C++
bool AxesLabelledControlArray1D_empty (
    AxesLabelledControlArray1DHandle handle
) 
```




<hr>



### function AxesLabelledControlArray1D\_equal 

```C++
bool AxesLabelledControlArray1D_equal (
    AxesLabelledControlArray1DHandle handle,
    AxesLabelledControlArray1DHandle other
) 
```




<hr>



### function AxesLabelledControlArray1D\_erase\_at 

```C++
void AxesLabelledControlArray1D_erase_at (
    AxesLabelledControlArray1DHandle handle,
    size_t idx
) 
```




<hr>



### function AxesLabelledControlArray1D\_from\_json\_string 

```C++
AxesLabelledControlArray1DHandle AxesLabelledControlArray1D_from_json_string (
    StringHandle json
) 
```




<hr>



### function AxesLabelledControlArray1D\_index 

```C++
size_t AxesLabelledControlArray1D_index (
    AxesLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle value
) 
```




<hr>



### function AxesLabelledControlArray1D\_intersection 

```C++
AxesLabelledControlArray1DHandle AxesLabelledControlArray1D_intersection (
    AxesLabelledControlArray1DHandle handle,
    AxesLabelledControlArray1DHandle other
) 
```




<hr>



### function AxesLabelledControlArray1D\_items 

```C++
size_t AxesLabelledControlArray1D_items (
    AxesLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function AxesLabelledControlArray1D\_not\_equal 

```C++
bool AxesLabelledControlArray1D_not_equal (
    AxesLabelledControlArray1DHandle handle,
    AxesLabelledControlArray1DHandle other
) 
```




<hr>



### function AxesLabelledControlArray1D\_push\_back 

```C++
void AxesLabelledControlArray1D_push_back (
    AxesLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle value
) 
```




<hr>



### function AxesLabelledControlArray1D\_size 

```C++
size_t AxesLabelledControlArray1D_size (
    AxesLabelledControlArray1DHandle handle
) 
```




<hr>



### function AxesLabelledControlArray1D\_to\_json\_string 

```C++
StringHandle AxesLabelledControlArray1D_to_json_string (
    AxesLabelledControlArray1DHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/AxesLabelledControlArray1D_c_api.h`

