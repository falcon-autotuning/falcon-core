

# File ListString\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListString\_c\_api.h**](ListString__c__api_8h.md)

[Go to the source code of this file](ListString__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListStringHandle**](#typedef-liststringhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ListStringHandle | [**ListString\_allocate**](#function-liststring_allocate) (size\_t count) <br> |
|  [**StringHandle**](structstring.md) | [**ListString\_at**](#function-liststring_at) (ListStringHandle handle, size\_t idx) <br> |
|  void | [**ListString\_clear**](#function-liststring_clear) (ListStringHandle handle) <br> |
|  bool | [**ListString\_contains**](#function-liststring_contains) (ListStringHandle handle, [**StringHandle**](structstring.md) value) <br> |
|  ListStringHandle | [**ListString\_copy**](#function-liststring_copy) (ListStringHandle handle) <br> |
|  ListStringHandle | [**ListString\_create**](#function-liststring_create) ([**StringHandle**](structstring.md) \* data, size\_t count) <br> |
|  ListStringHandle | [**ListString\_create\_empty**](#function-liststring_create_empty) () <br> |
|  void | [**ListString\_destroy**](#function-liststring_destroy) (ListStringHandle handle) <br> |
|  bool | [**ListString\_empty**](#function-liststring_empty) (ListStringHandle handle) <br> |
|  bool | [**ListString\_equal**](#function-liststring_equal) (ListStringHandle handle, ListStringHandle other) <br> |
|  void | [**ListString\_erase\_at**](#function-liststring_erase_at) (ListStringHandle handle, size\_t idx) <br> |
|  ListStringHandle | [**ListString\_fill\_value**](#function-liststring_fill_value) (size\_t count, [**StringHandle**](structstring.md) value) <br> |
|  ListStringHandle | [**ListString\_from\_json\_string**](#function-liststring_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListString\_index**](#function-liststring_index) (ListStringHandle handle, [**StringHandle**](structstring.md) value) <br> |
|  ListStringHandle | [**ListString\_intersection**](#function-liststring_intersection) (ListStringHandle handle, ListStringHandle other) <br> |
|  size\_t | [**ListString\_items**](#function-liststring_items) (ListStringHandle handle, [**StringHandle**](structstring.md) \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListString\_not\_equal**](#function-liststring_not_equal) (ListStringHandle handle, ListStringHandle other) <br> |
|  void | [**ListString\_push\_back**](#function-liststring_push_back) (ListStringHandle handle, [**StringHandle**](structstring.md) value) <br> |
|  size\_t | [**ListString\_size**](#function-liststring_size) (ListStringHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListString\_to\_json\_string**](#function-liststring_to_json_string) (ListStringHandle handle) <br> |




























## Public Types Documentation




### typedef ListStringHandle 

```C++
typedef void* ListStringHandle;
```




<hr>
## Public Functions Documentation




### function ListString\_allocate 

```C++
ListStringHandle ListString_allocate (
    size_t count
) 
```




<hr>



### function ListString\_at 

```C++
StringHandle ListString_at (
    ListStringHandle handle,
    size_t idx
) 
```




<hr>



### function ListString\_clear 

```C++
void ListString_clear (
    ListStringHandle handle
) 
```




<hr>



### function ListString\_contains 

```C++
bool ListString_contains (
    ListStringHandle handle,
    StringHandle value
) 
```




<hr>



### function ListString\_copy 

```C++
ListStringHandle ListString_copy (
    ListStringHandle handle
) 
```




<hr>



### function ListString\_create 

```C++
ListStringHandle ListString_create (
    StringHandle * data,
    size_t count
) 
```




<hr>



### function ListString\_create\_empty 

```C++
ListStringHandle ListString_create_empty () 
```




<hr>



### function ListString\_destroy 

```C++
void ListString_destroy (
    ListStringHandle handle
) 
```




<hr>



### function ListString\_empty 

```C++
bool ListString_empty (
    ListStringHandle handle
) 
```




<hr>



### function ListString\_equal 

```C++
bool ListString_equal (
    ListStringHandle handle,
    ListStringHandle other
) 
```




<hr>



### function ListString\_erase\_at 

```C++
void ListString_erase_at (
    ListStringHandle handle,
    size_t idx
) 
```




<hr>



### function ListString\_fill\_value 

```C++
ListStringHandle ListString_fill_value (
    size_t count,
    StringHandle value
) 
```




<hr>



### function ListString\_from\_json\_string 

```C++
ListStringHandle ListString_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListString\_index 

```C++
size_t ListString_index (
    ListStringHandle handle,
    StringHandle value
) 
```




<hr>



### function ListString\_intersection 

```C++
ListStringHandle ListString_intersection (
    ListStringHandle handle,
    ListStringHandle other
) 
```




<hr>



### function ListString\_items 

```C++
size_t ListString_items (
    ListStringHandle handle,
    StringHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListString\_not\_equal 

```C++
bool ListString_not_equal (
    ListStringHandle handle,
    ListStringHandle other
) 
```




<hr>



### function ListString\_push\_back 

```C++
void ListString_push_back (
    ListStringHandle handle,
    StringHandle value
) 
```




<hr>



### function ListString\_size 

```C++
size_t ListString_size (
    ListStringHandle handle
) 
```




<hr>



### function ListString\_to\_json\_string 

```C++
StringHandle ListString_to_json_string (
    ListStringHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListString_c_api.h`

