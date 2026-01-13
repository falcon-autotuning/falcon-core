

# File ListLabelledControlArray\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListLabelledControlArray\_c\_api.h**](ListLabelledControlArray__c__api_8h.md)

[Go to the source code of this file](ListLabelledControlArray__c__api_8h_source.md)



* `#include "falcon_core/math/arrays/LabelledControlArray_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListLabelledControlArrayHandle**](#typedef-listlabelledcontrolarrayhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  LabelledControlArrayHandle | [**ListLabelledControlArray\_at**](#function-listlabelledcontrolarray_at) (ListLabelledControlArrayHandle handle, size\_t idx) <br> |
|  void | [**ListLabelledControlArray\_clear**](#function-listlabelledcontrolarray_clear) (ListLabelledControlArrayHandle handle) <br> |
|  bool | [**ListLabelledControlArray\_contains**](#function-listlabelledcontrolarray_contains) (ListLabelledControlArrayHandle handle, LabelledControlArrayHandle value) <br> |
|  ListLabelledControlArrayHandle | [**ListLabelledControlArray\_copy**](#function-listlabelledcontrolarray_copy) (ListLabelledControlArrayHandle handle) <br> |
|  ListLabelledControlArrayHandle | [**ListLabelledControlArray\_create**](#function-listlabelledcontrolarray_create) (LabelledControlArrayHandle \* data, size\_t count) <br> |
|  ListLabelledControlArrayHandle | [**ListLabelledControlArray\_create\_empty**](#function-listlabelledcontrolarray_create_empty) () <br> |
|  void | [**ListLabelledControlArray\_destroy**](#function-listlabelledcontrolarray_destroy) (ListLabelledControlArrayHandle handle) <br> |
|  bool | [**ListLabelledControlArray\_empty**](#function-listlabelledcontrolarray_empty) (ListLabelledControlArrayHandle handle) <br> |
|  bool | [**ListLabelledControlArray\_equal**](#function-listlabelledcontrolarray_equal) (ListLabelledControlArrayHandle handle, ListLabelledControlArrayHandle other) <br> |
|  void | [**ListLabelledControlArray\_erase\_at**](#function-listlabelledcontrolarray_erase_at) (ListLabelledControlArrayHandle handle, size\_t idx) <br> |
|  ListLabelledControlArrayHandle | [**ListLabelledControlArray\_fill\_value**](#function-listlabelledcontrolarray_fill_value) (size\_t count, LabelledControlArrayHandle value) <br> |
|  ListLabelledControlArrayHandle | [**ListLabelledControlArray\_from\_json\_string**](#function-listlabelledcontrolarray_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListLabelledControlArray\_index**](#function-listlabelledcontrolarray_index) (ListLabelledControlArrayHandle handle, LabelledControlArrayHandle value) <br> |
|  ListLabelledControlArrayHandle | [**ListLabelledControlArray\_intersection**](#function-listlabelledcontrolarray_intersection) (ListLabelledControlArrayHandle handle, ListLabelledControlArrayHandle other) <br> |
|  size\_t | [**ListLabelledControlArray\_items**](#function-listlabelledcontrolarray_items) (ListLabelledControlArrayHandle handle, LabelledControlArrayHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListLabelledControlArray\_not\_equal**](#function-listlabelledcontrolarray_not_equal) (ListLabelledControlArrayHandle handle, ListLabelledControlArrayHandle other) <br> |
|  void | [**ListLabelledControlArray\_push\_back**](#function-listlabelledcontrolarray_push_back) (ListLabelledControlArrayHandle handle, LabelledControlArrayHandle value) <br> |
|  size\_t | [**ListLabelledControlArray\_size**](#function-listlabelledcontrolarray_size) (ListLabelledControlArrayHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListLabelledControlArray\_to\_json\_string**](#function-listlabelledcontrolarray_to_json_string) (ListLabelledControlArrayHandle handle) <br> |




























## Public Types Documentation




### typedef ListLabelledControlArrayHandle 

```C++
typedef void* ListLabelledControlArrayHandle;
```




<hr>
## Public Functions Documentation




### function ListLabelledControlArray\_at 

```C++
LabelledControlArrayHandle ListLabelledControlArray_at (
    ListLabelledControlArrayHandle handle,
    size_t idx
) 
```




<hr>



### function ListLabelledControlArray\_clear 

```C++
void ListLabelledControlArray_clear (
    ListLabelledControlArrayHandle handle
) 
```




<hr>



### function ListLabelledControlArray\_contains 

```C++
bool ListLabelledControlArray_contains (
    ListLabelledControlArrayHandle handle,
    LabelledControlArrayHandle value
) 
```




<hr>



### function ListLabelledControlArray\_copy 

```C++
ListLabelledControlArrayHandle ListLabelledControlArray_copy (
    ListLabelledControlArrayHandle handle
) 
```




<hr>



### function ListLabelledControlArray\_create 

```C++
ListLabelledControlArrayHandle ListLabelledControlArray_create (
    LabelledControlArrayHandle * data,
    size_t count
) 
```




<hr>



### function ListLabelledControlArray\_create\_empty 

```C++
ListLabelledControlArrayHandle ListLabelledControlArray_create_empty () 
```




<hr>



### function ListLabelledControlArray\_destroy 

```C++
void ListLabelledControlArray_destroy (
    ListLabelledControlArrayHandle handle
) 
```




<hr>



### function ListLabelledControlArray\_empty 

```C++
bool ListLabelledControlArray_empty (
    ListLabelledControlArrayHandle handle
) 
```




<hr>



### function ListLabelledControlArray\_equal 

```C++
bool ListLabelledControlArray_equal (
    ListLabelledControlArrayHandle handle,
    ListLabelledControlArrayHandle other
) 
```




<hr>



### function ListLabelledControlArray\_erase\_at 

```C++
void ListLabelledControlArray_erase_at (
    ListLabelledControlArrayHandle handle,
    size_t idx
) 
```




<hr>



### function ListLabelledControlArray\_fill\_value 

```C++
ListLabelledControlArrayHandle ListLabelledControlArray_fill_value (
    size_t count,
    LabelledControlArrayHandle value
) 
```




<hr>



### function ListLabelledControlArray\_from\_json\_string 

```C++
ListLabelledControlArrayHandle ListLabelledControlArray_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListLabelledControlArray\_index 

```C++
size_t ListLabelledControlArray_index (
    ListLabelledControlArrayHandle handle,
    LabelledControlArrayHandle value
) 
```




<hr>



### function ListLabelledControlArray\_intersection 

```C++
ListLabelledControlArrayHandle ListLabelledControlArray_intersection (
    ListLabelledControlArrayHandle handle,
    ListLabelledControlArrayHandle other
) 
```




<hr>



### function ListLabelledControlArray\_items 

```C++
size_t ListLabelledControlArray_items (
    ListLabelledControlArrayHandle handle,
    LabelledControlArrayHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListLabelledControlArray\_not\_equal 

```C++
bool ListLabelledControlArray_not_equal (
    ListLabelledControlArrayHandle handle,
    ListLabelledControlArrayHandle other
) 
```




<hr>



### function ListLabelledControlArray\_push\_back 

```C++
void ListLabelledControlArray_push_back (
    ListLabelledControlArrayHandle handle,
    LabelledControlArrayHandle value
) 
```




<hr>



### function ListLabelledControlArray\_size 

```C++
size_t ListLabelledControlArray_size (
    ListLabelledControlArrayHandle handle
) 
```




<hr>



### function ListLabelledControlArray\_to\_json\_string 

```C++
StringHandle ListLabelledControlArray_to_json_string (
    ListLabelledControlArrayHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListLabelledControlArray_c_api.h`

