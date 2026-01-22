

# File ListControlArray\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListControlArray\_c\_api.h**](ListControlArray__c__api_8h.md)

[Go to the source code of this file](ListControlArray__c__api_8h_source.md)



* `#include "falcon_core/math/arrays/ControlArray_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListControlArrayHandle**](#typedef-listcontrolarrayhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ControlArrayHandle | [**ListControlArray\_at**](#function-listcontrolarray_at) (ListControlArrayHandle handle, size\_t idx) <br> |
|  void | [**ListControlArray\_clear**](#function-listcontrolarray_clear) (ListControlArrayHandle handle) <br> |
|  bool | [**ListControlArray\_contains**](#function-listcontrolarray_contains) (ListControlArrayHandle handle, ControlArrayHandle value) <br> |
|  ListControlArrayHandle | [**ListControlArray\_copy**](#function-listcontrolarray_copy) (ListControlArrayHandle handle) <br> |
|  ListControlArrayHandle | [**ListControlArray\_create**](#function-listcontrolarray_create) (ControlArrayHandle \* data, size\_t count) <br> |
|  ListControlArrayHandle | [**ListControlArray\_create\_empty**](#function-listcontrolarray_create_empty) () <br> |
|  void | [**ListControlArray\_destroy**](#function-listcontrolarray_destroy) (ListControlArrayHandle handle) <br> |
|  bool | [**ListControlArray\_empty**](#function-listcontrolarray_empty) (ListControlArrayHandle handle) <br> |
|  bool | [**ListControlArray\_equal**](#function-listcontrolarray_equal) (ListControlArrayHandle handle, ListControlArrayHandle other) <br> |
|  void | [**ListControlArray\_erase\_at**](#function-listcontrolarray_erase_at) (ListControlArrayHandle handle, size\_t idx) <br> |
|  ListControlArrayHandle | [**ListControlArray\_fill\_value**](#function-listcontrolarray_fill_value) (size\_t count, ControlArrayHandle value) <br> |
|  ListControlArrayHandle | [**ListControlArray\_from\_json\_string**](#function-listcontrolarray_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ListControlArray\_index**](#function-listcontrolarray_index) (ListControlArrayHandle handle, ControlArrayHandle value) <br> |
|  ListControlArrayHandle | [**ListControlArray\_intersection**](#function-listcontrolarray_intersection) (ListControlArrayHandle handle, ListControlArrayHandle other) <br> |
|  size\_t | [**ListControlArray\_items**](#function-listcontrolarray_items) (ListControlArrayHandle handle, ControlArrayHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListControlArray\_not\_equal**](#function-listcontrolarray_not_equal) (ListControlArrayHandle handle, ListControlArrayHandle other) <br> |
|  void | [**ListControlArray\_push\_back**](#function-listcontrolarray_push_back) (ListControlArrayHandle handle, ControlArrayHandle value) <br> |
|  size\_t | [**ListControlArray\_size**](#function-listcontrolarray_size) (ListControlArrayHandle handle) <br> |
|  StringHandle | [**ListControlArray\_to\_json\_string**](#function-listcontrolarray_to_json_string) (ListControlArrayHandle handle) <br> |




























## Public Types Documentation




### typedef ListControlArrayHandle 

```C++
typedef void* ListControlArrayHandle;
```




<hr>
## Public Functions Documentation




### function ListControlArray\_at 

```C++
ControlArrayHandle ListControlArray_at (
    ListControlArrayHandle handle,
    size_t idx
) 
```




<hr>



### function ListControlArray\_clear 

```C++
void ListControlArray_clear (
    ListControlArrayHandle handle
) 
```




<hr>



### function ListControlArray\_contains 

```C++
bool ListControlArray_contains (
    ListControlArrayHandle handle,
    ControlArrayHandle value
) 
```




<hr>



### function ListControlArray\_copy 

```C++
ListControlArrayHandle ListControlArray_copy (
    ListControlArrayHandle handle
) 
```




<hr>



### function ListControlArray\_create 

```C++
ListControlArrayHandle ListControlArray_create (
    ControlArrayHandle * data,
    size_t count
) 
```




<hr>



### function ListControlArray\_create\_empty 

```C++
ListControlArrayHandle ListControlArray_create_empty () 
```




<hr>



### function ListControlArray\_destroy 

```C++
void ListControlArray_destroy (
    ListControlArrayHandle handle
) 
```




<hr>



### function ListControlArray\_empty 

```C++
bool ListControlArray_empty (
    ListControlArrayHandle handle
) 
```




<hr>



### function ListControlArray\_equal 

```C++
bool ListControlArray_equal (
    ListControlArrayHandle handle,
    ListControlArrayHandle other
) 
```




<hr>



### function ListControlArray\_erase\_at 

```C++
void ListControlArray_erase_at (
    ListControlArrayHandle handle,
    size_t idx
) 
```




<hr>



### function ListControlArray\_fill\_value 

```C++
ListControlArrayHandle ListControlArray_fill_value (
    size_t count,
    ControlArrayHandle value
) 
```




<hr>



### function ListControlArray\_from\_json\_string 

```C++
ListControlArrayHandle ListControlArray_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListControlArray\_index 

```C++
size_t ListControlArray_index (
    ListControlArrayHandle handle,
    ControlArrayHandle value
) 
```




<hr>



### function ListControlArray\_intersection 

```C++
ListControlArrayHandle ListControlArray_intersection (
    ListControlArrayHandle handle,
    ListControlArrayHandle other
) 
```




<hr>



### function ListControlArray\_items 

```C++
size_t ListControlArray_items (
    ListControlArrayHandle handle,
    ControlArrayHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListControlArray\_not\_equal 

```C++
bool ListControlArray_not_equal (
    ListControlArrayHandle handle,
    ListControlArrayHandle other
) 
```




<hr>



### function ListControlArray\_push\_back 

```C++
void ListControlArray_push_back (
    ListControlArrayHandle handle,
    ControlArrayHandle value
) 
```




<hr>



### function ListControlArray\_size 

```C++
size_t ListControlArray_size (
    ListControlArrayHandle handle
) 
```




<hr>



### function ListControlArray\_to\_json\_string 

```C++
StringHandle ListControlArray_to_json_string (
    ListControlArrayHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListControlArray_c_api.h`

