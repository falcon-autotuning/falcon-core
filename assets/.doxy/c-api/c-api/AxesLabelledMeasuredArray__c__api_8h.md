

# File AxesLabelledMeasuredArray\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AxesLabelledMeasuredArray\_c\_api.h**](AxesLabelledMeasuredArray__c__api_8h.md)

[Go to the source code of this file](AxesLabelledMeasuredArray__c__api_8h_source.md)



* `#include "falcon_core/math/arrays/LabelledMeasuredArray_c_api.h"`
* `#include "falcon_core/generic/ListLabelledMeasuredArray_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**AxesLabelledMeasuredArrayHandle**](#typedef-axeslabelledmeasuredarrayhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  LabelledMeasuredArrayHandle | [**AxesLabelledMeasuredArray\_at**](#function-axeslabelledmeasuredarray_at) (AxesLabelledMeasuredArrayHandle handle, size\_t idx) <br> |
|  void | [**AxesLabelledMeasuredArray\_clear**](#function-axeslabelledmeasuredarray_clear) (AxesLabelledMeasuredArrayHandle handle) <br> |
|  bool | [**AxesLabelledMeasuredArray\_contains**](#function-axeslabelledmeasuredarray_contains) (AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) <br> |
|  AxesLabelledMeasuredArrayHandle | [**AxesLabelledMeasuredArray\_copy**](#function-axeslabelledmeasuredarray_copy) (AxesLabelledMeasuredArrayHandle handle) <br> |
|  AxesLabelledMeasuredArrayHandle | [**AxesLabelledMeasuredArray\_create**](#function-axeslabelledmeasuredarray_create) (ListLabelledMeasuredArrayHandle data) <br> |
|  AxesLabelledMeasuredArrayHandle | [**AxesLabelledMeasuredArray\_create\_empty**](#function-axeslabelledmeasuredarray_create_empty) () <br> |
|  void | [**AxesLabelledMeasuredArray\_destroy**](#function-axeslabelledmeasuredarray_destroy) (AxesLabelledMeasuredArrayHandle handle) <br> |
|  bool | [**AxesLabelledMeasuredArray\_empty**](#function-axeslabelledmeasuredarray_empty) (AxesLabelledMeasuredArrayHandle handle) <br> |
|  bool | [**AxesLabelledMeasuredArray\_equal**](#function-axeslabelledmeasuredarray_equal) (AxesLabelledMeasuredArrayHandle handle, AxesLabelledMeasuredArrayHandle other) <br> |
|  void | [**AxesLabelledMeasuredArray\_erase\_at**](#function-axeslabelledmeasuredarray_erase_at) (AxesLabelledMeasuredArrayHandle handle, size\_t idx) <br> |
|  AxesLabelledMeasuredArrayHandle | [**AxesLabelledMeasuredArray\_from\_json\_string**](#function-axeslabelledmeasuredarray_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**AxesLabelledMeasuredArray\_index**](#function-axeslabelledmeasuredarray_index) (AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) <br> |
|  AxesLabelledMeasuredArrayHandle | [**AxesLabelledMeasuredArray\_intersection**](#function-axeslabelledmeasuredarray_intersection) (AxesLabelledMeasuredArrayHandle handle, AxesLabelledMeasuredArrayHandle other) <br> |
|  size\_t | [**AxesLabelledMeasuredArray\_items**](#function-axeslabelledmeasuredarray_items) (AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**AxesLabelledMeasuredArray\_not\_equal**](#function-axeslabelledmeasuredarray_not_equal) (AxesLabelledMeasuredArrayHandle handle, AxesLabelledMeasuredArrayHandle other) <br> |
|  void | [**AxesLabelledMeasuredArray\_push\_back**](#function-axeslabelledmeasuredarray_push_back) (AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) <br> |
|  size\_t | [**AxesLabelledMeasuredArray\_size**](#function-axeslabelledmeasuredarray_size) (AxesLabelledMeasuredArrayHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**AxesLabelledMeasuredArray\_to\_json\_string**](#function-axeslabelledmeasuredarray_to_json_string) (AxesLabelledMeasuredArrayHandle handle) <br> |




























## Public Types Documentation




### typedef AxesLabelledMeasuredArrayHandle 

```C++
typedef void* AxesLabelledMeasuredArrayHandle;
```




<hr>
## Public Functions Documentation




### function AxesLabelledMeasuredArray\_at 

```C++
LabelledMeasuredArrayHandle AxesLabelledMeasuredArray_at (
    AxesLabelledMeasuredArrayHandle handle,
    size_t idx
) 
```




<hr>



### function AxesLabelledMeasuredArray\_clear 

```C++
void AxesLabelledMeasuredArray_clear (
    AxesLabelledMeasuredArrayHandle handle
) 
```




<hr>



### function AxesLabelledMeasuredArray\_contains 

```C++
bool AxesLabelledMeasuredArray_contains (
    AxesLabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle value
) 
```




<hr>



### function AxesLabelledMeasuredArray\_copy 

```C++
AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_copy (
    AxesLabelledMeasuredArrayHandle handle
) 
```




<hr>



### function AxesLabelledMeasuredArray\_create 

```C++
AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_create (
    ListLabelledMeasuredArrayHandle data
) 
```




<hr>



### function AxesLabelledMeasuredArray\_create\_empty 

```C++
AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_create_empty () 
```




<hr>



### function AxesLabelledMeasuredArray\_destroy 

```C++
void AxesLabelledMeasuredArray_destroy (
    AxesLabelledMeasuredArrayHandle handle
) 
```




<hr>



### function AxesLabelledMeasuredArray\_empty 

```C++
bool AxesLabelledMeasuredArray_empty (
    AxesLabelledMeasuredArrayHandle handle
) 
```




<hr>



### function AxesLabelledMeasuredArray\_equal 

```C++
bool AxesLabelledMeasuredArray_equal (
    AxesLabelledMeasuredArrayHandle handle,
    AxesLabelledMeasuredArrayHandle other
) 
```




<hr>



### function AxesLabelledMeasuredArray\_erase\_at 

```C++
void AxesLabelledMeasuredArray_erase_at (
    AxesLabelledMeasuredArrayHandle handle,
    size_t idx
) 
```




<hr>



### function AxesLabelledMeasuredArray\_from\_json\_string 

```C++
AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_from_json_string (
    StringHandle json
) 
```




<hr>



### function AxesLabelledMeasuredArray\_index 

```C++
size_t AxesLabelledMeasuredArray_index (
    AxesLabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle value
) 
```




<hr>



### function AxesLabelledMeasuredArray\_intersection 

```C++
AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_intersection (
    AxesLabelledMeasuredArrayHandle handle,
    AxesLabelledMeasuredArrayHandle other
) 
```




<hr>



### function AxesLabelledMeasuredArray\_items 

```C++
size_t AxesLabelledMeasuredArray_items (
    AxesLabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function AxesLabelledMeasuredArray\_not\_equal 

```C++
bool AxesLabelledMeasuredArray_not_equal (
    AxesLabelledMeasuredArrayHandle handle,
    AxesLabelledMeasuredArrayHandle other
) 
```




<hr>



### function AxesLabelledMeasuredArray\_push\_back 

```C++
void AxesLabelledMeasuredArray_push_back (
    AxesLabelledMeasuredArrayHandle handle,
    LabelledMeasuredArrayHandle value
) 
```




<hr>



### function AxesLabelledMeasuredArray\_size 

```C++
size_t AxesLabelledMeasuredArray_size (
    AxesLabelledMeasuredArrayHandle handle
) 
```




<hr>



### function AxesLabelledMeasuredArray\_to\_json\_string 

```C++
StringHandle AxesLabelledMeasuredArray_to_json_string (
    AxesLabelledMeasuredArrayHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/math/AxesLabelledMeasuredArray_c_api.h`

