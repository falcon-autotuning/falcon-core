

# File ListFArrayDouble\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListFArrayDouble\_c\_api.h**](ListFArrayDouble__c__api_8h.md)

[Go to the source code of this file](ListFArrayDouble__c__api_8h_source.md)



* `#include "falcon_core/generic/FArrayDouble_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListFArrayDoubleHandle**](#typedef-listfarraydoublehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  FArrayDoubleHandle | [**ListFArrayDouble\_at**](#function-listfarraydouble_at) (ListFArrayDoubleHandle handle, size\_t idx) <br> |
|  void | [**ListFArrayDouble\_clear**](#function-listfarraydouble_clear) (ListFArrayDoubleHandle handle) <br> |
|  bool | [**ListFArrayDouble\_contains**](#function-listfarraydouble_contains) (ListFArrayDoubleHandle handle, FArrayDoubleHandle value) <br> |
|  ListFArrayDoubleHandle | [**ListFArrayDouble\_copy**](#function-listfarraydouble_copy) (ListFArrayDoubleHandle handle) <br> |
|  ListFArrayDoubleHandle | [**ListFArrayDouble\_create**](#function-listfarraydouble_create) (FArrayDoubleHandle \* data, size\_t count) <br> |
|  ListFArrayDoubleHandle | [**ListFArrayDouble\_create\_empty**](#function-listfarraydouble_create_empty) () <br> |
|  void | [**ListFArrayDouble\_destroy**](#function-listfarraydouble_destroy) (ListFArrayDoubleHandle handle) <br> |
|  bool | [**ListFArrayDouble\_empty**](#function-listfarraydouble_empty) (ListFArrayDoubleHandle handle) <br> |
|  bool | [**ListFArrayDouble\_equal**](#function-listfarraydouble_equal) (ListFArrayDoubleHandle handle, ListFArrayDoubleHandle other) <br> |
|  void | [**ListFArrayDouble\_erase\_at**](#function-listfarraydouble_erase_at) (ListFArrayDoubleHandle handle, size\_t idx) <br> |
|  ListFArrayDoubleHandle | [**ListFArrayDouble\_fill\_value**](#function-listfarraydouble_fill_value) (size\_t count, FArrayDoubleHandle value) <br> |
|  ListFArrayDoubleHandle | [**ListFArrayDouble\_from\_json\_string**](#function-listfarraydouble_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ListFArrayDouble\_index**](#function-listfarraydouble_index) (ListFArrayDoubleHandle handle, FArrayDoubleHandle value) <br> |
|  ListFArrayDoubleHandle | [**ListFArrayDouble\_intersection**](#function-listfarraydouble_intersection) (ListFArrayDoubleHandle handle, ListFArrayDoubleHandle other) <br> |
|  size\_t | [**ListFArrayDouble\_items**](#function-listfarraydouble_items) (ListFArrayDoubleHandle handle, FArrayDoubleHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListFArrayDouble\_not\_equal**](#function-listfarraydouble_not_equal) (ListFArrayDoubleHandle handle, ListFArrayDoubleHandle other) <br> |
|  void | [**ListFArrayDouble\_push\_back**](#function-listfarraydouble_push_back) (ListFArrayDoubleHandle handle, FArrayDoubleHandle value) <br> |
|  size\_t | [**ListFArrayDouble\_size**](#function-listfarraydouble_size) (ListFArrayDoubleHandle handle) <br> |
|  StringHandle | [**ListFArrayDouble\_to\_json\_string**](#function-listfarraydouble_to_json_string) (ListFArrayDoubleHandle handle) <br> |




























## Public Types Documentation




### typedef ListFArrayDoubleHandle 

```C++
typedef void* ListFArrayDoubleHandle;
```




<hr>
## Public Functions Documentation




### function ListFArrayDouble\_at 

```C++
FArrayDoubleHandle ListFArrayDouble_at (
    ListFArrayDoubleHandle handle,
    size_t idx
) 
```




<hr>



### function ListFArrayDouble\_clear 

```C++
void ListFArrayDouble_clear (
    ListFArrayDoubleHandle handle
) 
```




<hr>



### function ListFArrayDouble\_contains 

```C++
bool ListFArrayDouble_contains (
    ListFArrayDoubleHandle handle,
    FArrayDoubleHandle value
) 
```




<hr>



### function ListFArrayDouble\_copy 

```C++
ListFArrayDoubleHandle ListFArrayDouble_copy (
    ListFArrayDoubleHandle handle
) 
```




<hr>



### function ListFArrayDouble\_create 

```C++
ListFArrayDoubleHandle ListFArrayDouble_create (
    FArrayDoubleHandle * data,
    size_t count
) 
```




<hr>



### function ListFArrayDouble\_create\_empty 

```C++
ListFArrayDoubleHandle ListFArrayDouble_create_empty () 
```




<hr>



### function ListFArrayDouble\_destroy 

```C++
void ListFArrayDouble_destroy (
    ListFArrayDoubleHandle handle
) 
```




<hr>



### function ListFArrayDouble\_empty 

```C++
bool ListFArrayDouble_empty (
    ListFArrayDoubleHandle handle
) 
```




<hr>



### function ListFArrayDouble\_equal 

```C++
bool ListFArrayDouble_equal (
    ListFArrayDoubleHandle handle,
    ListFArrayDoubleHandle other
) 
```




<hr>



### function ListFArrayDouble\_erase\_at 

```C++
void ListFArrayDouble_erase_at (
    ListFArrayDoubleHandle handle,
    size_t idx
) 
```




<hr>



### function ListFArrayDouble\_fill\_value 

```C++
ListFArrayDoubleHandle ListFArrayDouble_fill_value (
    size_t count,
    FArrayDoubleHandle value
) 
```




<hr>



### function ListFArrayDouble\_from\_json\_string 

```C++
ListFArrayDoubleHandle ListFArrayDouble_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListFArrayDouble\_index 

```C++
size_t ListFArrayDouble_index (
    ListFArrayDoubleHandle handle,
    FArrayDoubleHandle value
) 
```




<hr>



### function ListFArrayDouble\_intersection 

```C++
ListFArrayDoubleHandle ListFArrayDouble_intersection (
    ListFArrayDoubleHandle handle,
    ListFArrayDoubleHandle other
) 
```




<hr>



### function ListFArrayDouble\_items 

```C++
size_t ListFArrayDouble_items (
    ListFArrayDoubleHandle handle,
    FArrayDoubleHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListFArrayDouble\_not\_equal 

```C++
bool ListFArrayDouble_not_equal (
    ListFArrayDoubleHandle handle,
    ListFArrayDoubleHandle other
) 
```




<hr>



### function ListFArrayDouble\_push\_back 

```C++
void ListFArrayDouble_push_back (
    ListFArrayDoubleHandle handle,
    FArrayDoubleHandle value
) 
```




<hr>



### function ListFArrayDouble\_size 

```C++
size_t ListFArrayDouble_size (
    ListFArrayDoubleHandle handle
) 
```




<hr>



### function ListFArrayDouble\_to\_json\_string 

```C++
StringHandle ListFArrayDouble_to_json_string (
    ListFArrayDoubleHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListFArrayDouble_c_api.h`

