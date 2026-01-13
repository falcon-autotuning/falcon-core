

# File ListGname\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListGname\_c\_api.h**](ListGname__c__api_8h.md)

[Go to the source code of this file](ListGname__c__api_8h_source.md)



* `#include "falcon_core/autotuner_interfaces/names/Gname_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListGnameHandle**](#typedef-listgnamehandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  GnameHandle | [**ListGname\_at**](#function-listgname_at) (ListGnameHandle handle, size\_t idx) <br> |
|  void | [**ListGname\_clear**](#function-listgname_clear) (ListGnameHandle handle) <br> |
|  bool | [**ListGname\_contains**](#function-listgname_contains) (ListGnameHandle handle, GnameHandle value) <br> |
|  ListGnameHandle | [**ListGname\_copy**](#function-listgname_copy) (ListGnameHandle handle) <br> |
|  ListGnameHandle | [**ListGname\_create**](#function-listgname_create) (GnameHandle \* data, size\_t count) <br> |
|  ListGnameHandle | [**ListGname\_create\_empty**](#function-listgname_create_empty) () <br> |
|  void | [**ListGname\_destroy**](#function-listgname_destroy) (ListGnameHandle handle) <br> |
|  bool | [**ListGname\_empty**](#function-listgname_empty) (ListGnameHandle handle) <br> |
|  bool | [**ListGname\_equal**](#function-listgname_equal) (ListGnameHandle handle, ListGnameHandle other) <br> |
|  void | [**ListGname\_erase\_at**](#function-listgname_erase_at) (ListGnameHandle handle, size\_t idx) <br> |
|  ListGnameHandle | [**ListGname\_fill\_value**](#function-listgname_fill_value) (size\_t count, GnameHandle value) <br> |
|  ListGnameHandle | [**ListGname\_from\_json\_string**](#function-listgname_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListGname\_index**](#function-listgname_index) (ListGnameHandle handle, GnameHandle value) <br> |
|  ListGnameHandle | [**ListGname\_intersection**](#function-listgname_intersection) (ListGnameHandle handle, ListGnameHandle other) <br> |
|  size\_t | [**ListGname\_items**](#function-listgname_items) (ListGnameHandle handle, GnameHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListGname\_not\_equal**](#function-listgname_not_equal) (ListGnameHandle handle, ListGnameHandle other) <br> |
|  void | [**ListGname\_push\_back**](#function-listgname_push_back) (ListGnameHandle handle, GnameHandle value) <br> |
|  size\_t | [**ListGname\_size**](#function-listgname_size) (ListGnameHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListGname\_to\_json\_string**](#function-listgname_to_json_string) (ListGnameHandle handle) <br> |




























## Public Types Documentation




### typedef ListGnameHandle 

```C++
typedef void* ListGnameHandle;
```




<hr>
## Public Functions Documentation




### function ListGname\_at 

```C++
GnameHandle ListGname_at (
    ListGnameHandle handle,
    size_t idx
) 
```




<hr>



### function ListGname\_clear 

```C++
void ListGname_clear (
    ListGnameHandle handle
) 
```




<hr>



### function ListGname\_contains 

```C++
bool ListGname_contains (
    ListGnameHandle handle,
    GnameHandle value
) 
```




<hr>



### function ListGname\_copy 

```C++
ListGnameHandle ListGname_copy (
    ListGnameHandle handle
) 
```




<hr>



### function ListGname\_create 

```C++
ListGnameHandle ListGname_create (
    GnameHandle * data,
    size_t count
) 
```




<hr>



### function ListGname\_create\_empty 

```C++
ListGnameHandle ListGname_create_empty () 
```




<hr>



### function ListGname\_destroy 

```C++
void ListGname_destroy (
    ListGnameHandle handle
) 
```




<hr>



### function ListGname\_empty 

```C++
bool ListGname_empty (
    ListGnameHandle handle
) 
```




<hr>



### function ListGname\_equal 

```C++
bool ListGname_equal (
    ListGnameHandle handle,
    ListGnameHandle other
) 
```




<hr>



### function ListGname\_erase\_at 

```C++
void ListGname_erase_at (
    ListGnameHandle handle,
    size_t idx
) 
```




<hr>



### function ListGname\_fill\_value 

```C++
ListGnameHandle ListGname_fill_value (
    size_t count,
    GnameHandle value
) 
```




<hr>



### function ListGname\_from\_json\_string 

```C++
ListGnameHandle ListGname_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListGname\_index 

```C++
size_t ListGname_index (
    ListGnameHandle handle,
    GnameHandle value
) 
```




<hr>



### function ListGname\_intersection 

```C++
ListGnameHandle ListGname_intersection (
    ListGnameHandle handle,
    ListGnameHandle other
) 
```




<hr>



### function ListGname\_items 

```C++
size_t ListGname_items (
    ListGnameHandle handle,
    GnameHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListGname\_not\_equal 

```C++
bool ListGname_not_equal (
    ListGnameHandle handle,
    ListGnameHandle other
) 
```




<hr>



### function ListGname\_push\_back 

```C++
void ListGname_push_back (
    ListGnameHandle handle,
    GnameHandle value
) 
```




<hr>



### function ListGname\_size 

```C++
size_t ListGname_size (
    ListGnameHandle handle
) 
```




<hr>



### function ListGname\_to\_json\_string 

```C++
StringHandle ListGname_to_json_string (
    ListGnameHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListGname_c_api.h`

