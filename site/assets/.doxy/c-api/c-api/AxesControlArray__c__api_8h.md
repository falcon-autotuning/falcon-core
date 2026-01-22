

# File AxesControlArray\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AxesControlArray\_c\_api.h**](AxesControlArray__c__api_8h.md)

[Go to the source code of this file](AxesControlArray__c__api_8h_source.md)



* `#include "falcon_core/math/arrays/ControlArray_c_api.h"`
* `#include "falcon_core/generic/ListControlArray_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**AxesControlArrayHandle**](#typedef-axescontrolarrayhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ControlArrayHandle | [**AxesControlArray\_at**](#function-axescontrolarray_at) (AxesControlArrayHandle handle, size\_t idx) <br> |
|  void | [**AxesControlArray\_clear**](#function-axescontrolarray_clear) (AxesControlArrayHandle handle) <br> |
|  bool | [**AxesControlArray\_contains**](#function-axescontrolarray_contains) (AxesControlArrayHandle handle, ControlArrayHandle value) <br> |
|  AxesControlArrayHandle | [**AxesControlArray\_copy**](#function-axescontrolarray_copy) (AxesControlArrayHandle handle) <br> |
|  AxesControlArrayHandle | [**AxesControlArray\_create**](#function-axescontrolarray_create) (ListControlArrayHandle data) <br> |
|  AxesControlArrayHandle | [**AxesControlArray\_create\_empty**](#function-axescontrolarray_create_empty) () <br> |
|  void | [**AxesControlArray\_destroy**](#function-axescontrolarray_destroy) (AxesControlArrayHandle handle) <br> |
|  bool | [**AxesControlArray\_empty**](#function-axescontrolarray_empty) (AxesControlArrayHandle handle) <br> |
|  bool | [**AxesControlArray\_equal**](#function-axescontrolarray_equal) (AxesControlArrayHandle handle, AxesControlArrayHandle other) <br> |
|  void | [**AxesControlArray\_erase\_at**](#function-axescontrolarray_erase_at) (AxesControlArrayHandle handle, size\_t idx) <br> |
|  AxesControlArrayHandle | [**AxesControlArray\_from\_json\_string**](#function-axescontrolarray_from_json_string) (StringHandle json) <br> |
|  size\_t | [**AxesControlArray\_index**](#function-axescontrolarray_index) (AxesControlArrayHandle handle, ControlArrayHandle value) <br> |
|  AxesControlArrayHandle | [**AxesControlArray\_intersection**](#function-axescontrolarray_intersection) (AxesControlArrayHandle handle, AxesControlArrayHandle other) <br> |
|  size\_t | [**AxesControlArray\_items**](#function-axescontrolarray_items) (AxesControlArrayHandle handle, ControlArrayHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**AxesControlArray\_not\_equal**](#function-axescontrolarray_not_equal) (AxesControlArrayHandle handle, AxesControlArrayHandle other) <br> |
|  void | [**AxesControlArray\_push\_back**](#function-axescontrolarray_push_back) (AxesControlArrayHandle handle, ControlArrayHandle value) <br> |
|  size\_t | [**AxesControlArray\_size**](#function-axescontrolarray_size) (AxesControlArrayHandle handle) <br> |
|  StringHandle | [**AxesControlArray\_to\_json\_string**](#function-axescontrolarray_to_json_string) (AxesControlArrayHandle handle) <br> |




























## Public Types Documentation




### typedef AxesControlArrayHandle 

```C++
typedef void* AxesControlArrayHandle;
```




<hr>
## Public Functions Documentation




### function AxesControlArray\_at 

```C++
ControlArrayHandle AxesControlArray_at (
    AxesControlArrayHandle handle,
    size_t idx
) 
```




<hr>



### function AxesControlArray\_clear 

```C++
void AxesControlArray_clear (
    AxesControlArrayHandle handle
) 
```




<hr>



### function AxesControlArray\_contains 

```C++
bool AxesControlArray_contains (
    AxesControlArrayHandle handle,
    ControlArrayHandle value
) 
```




<hr>



### function AxesControlArray\_copy 

```C++
AxesControlArrayHandle AxesControlArray_copy (
    AxesControlArrayHandle handle
) 
```




<hr>



### function AxesControlArray\_create 

```C++
AxesControlArrayHandle AxesControlArray_create (
    ListControlArrayHandle data
) 
```




<hr>



### function AxesControlArray\_create\_empty 

```C++
AxesControlArrayHandle AxesControlArray_create_empty () 
```




<hr>



### function AxesControlArray\_destroy 

```C++
void AxesControlArray_destroy (
    AxesControlArrayHandle handle
) 
```




<hr>



### function AxesControlArray\_empty 

```C++
bool AxesControlArray_empty (
    AxesControlArrayHandle handle
) 
```




<hr>



### function AxesControlArray\_equal 

```C++
bool AxesControlArray_equal (
    AxesControlArrayHandle handle,
    AxesControlArrayHandle other
) 
```




<hr>



### function AxesControlArray\_erase\_at 

```C++
void AxesControlArray_erase_at (
    AxesControlArrayHandle handle,
    size_t idx
) 
```




<hr>



### function AxesControlArray\_from\_json\_string 

```C++
AxesControlArrayHandle AxesControlArray_from_json_string (
    StringHandle json
) 
```




<hr>



### function AxesControlArray\_index 

```C++
size_t AxesControlArray_index (
    AxesControlArrayHandle handle,
    ControlArrayHandle value
) 
```




<hr>



### function AxesControlArray\_intersection 

```C++
AxesControlArrayHandle AxesControlArray_intersection (
    AxesControlArrayHandle handle,
    AxesControlArrayHandle other
) 
```




<hr>



### function AxesControlArray\_items 

```C++
size_t AxesControlArray_items (
    AxesControlArrayHandle handle,
    ControlArrayHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function AxesControlArray\_not\_equal 

```C++
bool AxesControlArray_not_equal (
    AxesControlArrayHandle handle,
    AxesControlArrayHandle other
) 
```




<hr>



### function AxesControlArray\_push\_back 

```C++
void AxesControlArray_push_back (
    AxesControlArrayHandle handle,
    ControlArrayHandle value
) 
```




<hr>



### function AxesControlArray\_size 

```C++
size_t AxesControlArray_size (
    AxesControlArrayHandle handle
) 
```




<hr>



### function AxesControlArray\_to\_json\_string 

```C++
StringHandle AxesControlArray_to_json_string (
    AxesControlArrayHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/AxesControlArray_c_api.h`

