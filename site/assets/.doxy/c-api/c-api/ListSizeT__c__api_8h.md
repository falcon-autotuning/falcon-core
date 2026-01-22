

# File ListSizeT\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListSizeT\_c\_api.h**](ListSizeT__c__api_8h.md)

[Go to the source code of this file](ListSizeT__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListSizeTHandle**](#typedef-listsizethandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ListSizeTHandle | [**ListSizeT\_allocate**](#function-listsizet_allocate) (size\_t count) <br> |
|  size\_t | [**ListSizeT\_at**](#function-listsizet_at) (ListSizeTHandle handle, size\_t idx) <br> |
|  void | [**ListSizeT\_clear**](#function-listsizet_clear) (ListSizeTHandle handle) <br> |
|  bool | [**ListSizeT\_contains**](#function-listsizet_contains) (ListSizeTHandle handle, size\_t value) <br> |
|  ListSizeTHandle | [**ListSizeT\_copy**](#function-listsizet_copy) (ListSizeTHandle handle) <br> |
|  ListSizeTHandle | [**ListSizeT\_create**](#function-listsizet_create) (size\_t \* data, size\_t count) <br> |
|  ListSizeTHandle | [**ListSizeT\_create\_empty**](#function-listsizet_create_empty) () <br> |
|  void | [**ListSizeT\_destroy**](#function-listsizet_destroy) (ListSizeTHandle handle) <br> |
|  bool | [**ListSizeT\_empty**](#function-listsizet_empty) (ListSizeTHandle handle) <br> |
|  bool | [**ListSizeT\_equal**](#function-listsizet_equal) (ListSizeTHandle handle, ListSizeTHandle other) <br> |
|  void | [**ListSizeT\_erase\_at**](#function-listsizet_erase_at) (ListSizeTHandle handle, size\_t idx) <br> |
|  ListSizeTHandle | [**ListSizeT\_fill\_value**](#function-listsizet_fill_value) (size\_t count, size\_t value) <br> |
|  ListSizeTHandle | [**ListSizeT\_from\_json\_string**](#function-listsizet_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ListSizeT\_index**](#function-listsizet_index) (ListSizeTHandle handle, size\_t value) <br> |
|  ListSizeTHandle | [**ListSizeT\_intersection**](#function-listsizet_intersection) (ListSizeTHandle handle, ListSizeTHandle other) <br> |
|  size\_t | [**ListSizeT\_items**](#function-listsizet_items) (ListSizeTHandle handle, size\_t \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListSizeT\_not\_equal**](#function-listsizet_not_equal) (ListSizeTHandle handle, ListSizeTHandle other) <br> |
|  void | [**ListSizeT\_push\_back**](#function-listsizet_push_back) (ListSizeTHandle handle, size\_t value) <br> |
|  size\_t | [**ListSizeT\_size**](#function-listsizet_size) (ListSizeTHandle handle) <br> |
|  StringHandle | [**ListSizeT\_to\_json\_string**](#function-listsizet_to_json_string) (ListSizeTHandle handle) <br> |




























## Public Types Documentation




### typedef ListSizeTHandle 

```C++
typedef void* ListSizeTHandle;
```




<hr>
## Public Functions Documentation




### function ListSizeT\_allocate 

```C++
ListSizeTHandle ListSizeT_allocate (
    size_t count
) 
```




<hr>



### function ListSizeT\_at 

```C++
size_t ListSizeT_at (
    ListSizeTHandle handle,
    size_t idx
) 
```




<hr>



### function ListSizeT\_clear 

```C++
void ListSizeT_clear (
    ListSizeTHandle handle
) 
```




<hr>



### function ListSizeT\_contains 

```C++
bool ListSizeT_contains (
    ListSizeTHandle handle,
    size_t value
) 
```




<hr>



### function ListSizeT\_copy 

```C++
ListSizeTHandle ListSizeT_copy (
    ListSizeTHandle handle
) 
```




<hr>



### function ListSizeT\_create 

```C++
ListSizeTHandle ListSizeT_create (
    size_t * data,
    size_t count
) 
```




<hr>



### function ListSizeT\_create\_empty 

```C++
ListSizeTHandle ListSizeT_create_empty () 
```




<hr>



### function ListSizeT\_destroy 

```C++
void ListSizeT_destroy (
    ListSizeTHandle handle
) 
```




<hr>



### function ListSizeT\_empty 

```C++
bool ListSizeT_empty (
    ListSizeTHandle handle
) 
```




<hr>



### function ListSizeT\_equal 

```C++
bool ListSizeT_equal (
    ListSizeTHandle handle,
    ListSizeTHandle other
) 
```




<hr>



### function ListSizeT\_erase\_at 

```C++
void ListSizeT_erase_at (
    ListSizeTHandle handle,
    size_t idx
) 
```




<hr>



### function ListSizeT\_fill\_value 

```C++
ListSizeTHandle ListSizeT_fill_value (
    size_t count,
    size_t value
) 
```




<hr>



### function ListSizeT\_from\_json\_string 

```C++
ListSizeTHandle ListSizeT_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListSizeT\_index 

```C++
size_t ListSizeT_index (
    ListSizeTHandle handle,
    size_t value
) 
```




<hr>



### function ListSizeT\_intersection 

```C++
ListSizeTHandle ListSizeT_intersection (
    ListSizeTHandle handle,
    ListSizeTHandle other
) 
```




<hr>



### function ListSizeT\_items 

```C++
size_t ListSizeT_items (
    ListSizeTHandle handle,
    size_t * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListSizeT\_not\_equal 

```C++
bool ListSizeT_not_equal (
    ListSizeTHandle handle,
    ListSizeTHandle other
) 
```




<hr>



### function ListSizeT\_push\_back 

```C++
void ListSizeT_push_back (
    ListSizeTHandle handle,
    size_t value
) 
```




<hr>



### function ListSizeT\_size 

```C++
size_t ListSizeT_size (
    ListSizeTHandle handle
) 
```




<hr>



### function ListSizeT\_to\_json\_string 

```C++
StringHandle ListSizeT_to_json_string (
    ListSizeTHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListSizeT_c_api.h`

