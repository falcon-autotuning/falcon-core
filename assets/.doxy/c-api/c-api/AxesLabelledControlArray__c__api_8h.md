

# File AxesLabelledControlArray\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AxesLabelledControlArray\_c\_api.h**](AxesLabelledControlArray__c__api_8h.md)

[Go to the source code of this file](AxesLabelledControlArray__c__api_8h_source.md)



* `#include "falcon_core/math/arrays/LabelledControlArray_c_api.h"`
* `#include "falcon_core/generic/ListLabelledControlArray_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**AxesLabelledControlArrayHandle**](#typedef-axeslabelledcontrolarrayhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  LabelledControlArrayHandle | [**AxesLabelledControlArray\_at**](#function-axeslabelledcontrolarray_at) (AxesLabelledControlArrayHandle handle, size\_t idx) <br> |
|  void | [**AxesLabelledControlArray\_clear**](#function-axeslabelledcontrolarray_clear) (AxesLabelledControlArrayHandle handle) <br> |
|  bool | [**AxesLabelledControlArray\_contains**](#function-axeslabelledcontrolarray_contains) (AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle value) <br> |
|  AxesLabelledControlArrayHandle | [**AxesLabelledControlArray\_copy**](#function-axeslabelledcontrolarray_copy) (AxesLabelledControlArrayHandle handle) <br> |
|  AxesLabelledControlArrayHandle | [**AxesLabelledControlArray\_create**](#function-axeslabelledcontrolarray_create) (ListLabelledControlArrayHandle data) <br> |
|  AxesLabelledControlArrayHandle | [**AxesLabelledControlArray\_create\_empty**](#function-axeslabelledcontrolarray_create_empty) () <br> |
|  void | [**AxesLabelledControlArray\_destroy**](#function-axeslabelledcontrolarray_destroy) (AxesLabelledControlArrayHandle handle) <br> |
|  bool | [**AxesLabelledControlArray\_empty**](#function-axeslabelledcontrolarray_empty) (AxesLabelledControlArrayHandle handle) <br> |
|  bool | [**AxesLabelledControlArray\_equal**](#function-axeslabelledcontrolarray_equal) (AxesLabelledControlArrayHandle handle, AxesLabelledControlArrayHandle other) <br> |
|  void | [**AxesLabelledControlArray\_erase\_at**](#function-axeslabelledcontrolarray_erase_at) (AxesLabelledControlArrayHandle handle, size\_t idx) <br> |
|  AxesLabelledControlArrayHandle | [**AxesLabelledControlArray\_from\_json\_string**](#function-axeslabelledcontrolarray_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**AxesLabelledControlArray\_index**](#function-axeslabelledcontrolarray_index) (AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle value) <br> |
|  AxesLabelledControlArrayHandle | [**AxesLabelledControlArray\_intersection**](#function-axeslabelledcontrolarray_intersection) (AxesLabelledControlArrayHandle handle, AxesLabelledControlArrayHandle other) <br> |
|  size\_t | [**AxesLabelledControlArray\_items**](#function-axeslabelledcontrolarray_items) (AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**AxesLabelledControlArray\_not\_equal**](#function-axeslabelledcontrolarray_not_equal) (AxesLabelledControlArrayHandle handle, AxesLabelledControlArrayHandle other) <br> |
|  void | [**AxesLabelledControlArray\_push\_back**](#function-axeslabelledcontrolarray_push_back) (AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle value) <br> |
|  size\_t | [**AxesLabelledControlArray\_size**](#function-axeslabelledcontrolarray_size) (AxesLabelledControlArrayHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**AxesLabelledControlArray\_to\_json\_string**](#function-axeslabelledcontrolarray_to_json_string) (AxesLabelledControlArrayHandle handle) <br> |




























## Public Types Documentation




### typedef AxesLabelledControlArrayHandle 

```C++
typedef void* AxesLabelledControlArrayHandle;
```




<hr>
## Public Functions Documentation




### function AxesLabelledControlArray\_at 

```C++
LabelledControlArrayHandle AxesLabelledControlArray_at (
    AxesLabelledControlArrayHandle handle,
    size_t idx
) 
```




<hr>



### function AxesLabelledControlArray\_clear 

```C++
void AxesLabelledControlArray_clear (
    AxesLabelledControlArrayHandle handle
) 
```




<hr>



### function AxesLabelledControlArray\_contains 

```C++
bool AxesLabelledControlArray_contains (
    AxesLabelledControlArrayHandle handle,
    LabelledControlArrayHandle value
) 
```




<hr>



### function AxesLabelledControlArray\_copy 

```C++
AxesLabelledControlArrayHandle AxesLabelledControlArray_copy (
    AxesLabelledControlArrayHandle handle
) 
```




<hr>



### function AxesLabelledControlArray\_create 

```C++
AxesLabelledControlArrayHandle AxesLabelledControlArray_create (
    ListLabelledControlArrayHandle data
) 
```




<hr>



### function AxesLabelledControlArray\_create\_empty 

```C++
AxesLabelledControlArrayHandle AxesLabelledControlArray_create_empty () 
```




<hr>



### function AxesLabelledControlArray\_destroy 

```C++
void AxesLabelledControlArray_destroy (
    AxesLabelledControlArrayHandle handle
) 
```




<hr>



### function AxesLabelledControlArray\_empty 

```C++
bool AxesLabelledControlArray_empty (
    AxesLabelledControlArrayHandle handle
) 
```




<hr>



### function AxesLabelledControlArray\_equal 

```C++
bool AxesLabelledControlArray_equal (
    AxesLabelledControlArrayHandle handle,
    AxesLabelledControlArrayHandle other
) 
```




<hr>



### function AxesLabelledControlArray\_erase\_at 

```C++
void AxesLabelledControlArray_erase_at (
    AxesLabelledControlArrayHandle handle,
    size_t idx
) 
```




<hr>



### function AxesLabelledControlArray\_from\_json\_string 

```C++
AxesLabelledControlArrayHandle AxesLabelledControlArray_from_json_string (
    StringHandle json
) 
```




<hr>



### function AxesLabelledControlArray\_index 

```C++
size_t AxesLabelledControlArray_index (
    AxesLabelledControlArrayHandle handle,
    LabelledControlArrayHandle value
) 
```




<hr>



### function AxesLabelledControlArray\_intersection 

```C++
AxesLabelledControlArrayHandle AxesLabelledControlArray_intersection (
    AxesLabelledControlArrayHandle handle,
    AxesLabelledControlArrayHandle other
) 
```




<hr>



### function AxesLabelledControlArray\_items 

```C++
size_t AxesLabelledControlArray_items (
    AxesLabelledControlArrayHandle handle,
    LabelledControlArrayHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function AxesLabelledControlArray\_not\_equal 

```C++
bool AxesLabelledControlArray_not_equal (
    AxesLabelledControlArrayHandle handle,
    AxesLabelledControlArrayHandle other
) 
```




<hr>



### function AxesLabelledControlArray\_push\_back 

```C++
void AxesLabelledControlArray_push_back (
    AxesLabelledControlArrayHandle handle,
    LabelledControlArrayHandle value
) 
```




<hr>



### function AxesLabelledControlArray\_size 

```C++
size_t AxesLabelledControlArray_size (
    AxesLabelledControlArrayHandle handle
) 
```




<hr>



### function AxesLabelledControlArray\_to\_json\_string 

```C++
StringHandle AxesLabelledControlArray_to_json_string (
    AxesLabelledControlArrayHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/AxesLabelledControlArray_c_api.h`

