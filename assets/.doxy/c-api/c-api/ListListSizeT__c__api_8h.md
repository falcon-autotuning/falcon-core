

# File ListListSizeT\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListListSizeT\_c\_api.h**](ListListSizeT__c__api_8h.md)

[Go to the source code of this file](ListListSizeT__c__api_8h_source.md)



* `#include "falcon_core/generic/ListSizeT_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListListSizeTHandle**](#typedef-listlistsizethandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ListSizeTHandle | [**ListListSizeT\_at**](#function-listlistsizet_at) (ListListSizeTHandle handle, size\_t idx) <br> |
|  void | [**ListListSizeT\_clear**](#function-listlistsizet_clear) (ListListSizeTHandle handle) <br> |
|  bool | [**ListListSizeT\_contains**](#function-listlistsizet_contains) (ListListSizeTHandle handle, ListSizeTHandle value) <br> |
|  ListListSizeTHandle | [**ListListSizeT\_copy**](#function-listlistsizet_copy) (ListListSizeTHandle handle) <br> |
|  ListListSizeTHandle | [**ListListSizeT\_create**](#function-listlistsizet_create) (ListSizeTHandle \* data, size\_t count) <br> |
|  ListListSizeTHandle | [**ListListSizeT\_create\_empty**](#function-listlistsizet_create_empty) () <br> |
|  void | [**ListListSizeT\_destroy**](#function-listlistsizet_destroy) (ListListSizeTHandle handle) <br> |
|  bool | [**ListListSizeT\_empty**](#function-listlistsizet_empty) (ListListSizeTHandle handle) <br> |
|  bool | [**ListListSizeT\_equal**](#function-listlistsizet_equal) (ListListSizeTHandle handle, ListListSizeTHandle other) <br> |
|  void | [**ListListSizeT\_erase\_at**](#function-listlistsizet_erase_at) (ListListSizeTHandle handle, size\_t idx) <br> |
|  ListListSizeTHandle | [**ListListSizeT\_fill\_value**](#function-listlistsizet_fill_value) (size\_t count, ListSizeTHandle value) <br> |
|  ListListSizeTHandle | [**ListListSizeT\_from\_json\_string**](#function-listlistsizet_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListListSizeT\_index**](#function-listlistsizet_index) (ListListSizeTHandle handle, ListSizeTHandle value) <br> |
|  ListListSizeTHandle | [**ListListSizeT\_intersection**](#function-listlistsizet_intersection) (ListListSizeTHandle handle, ListListSizeTHandle other) <br> |
|  size\_t | [**ListListSizeT\_items**](#function-listlistsizet_items) (ListListSizeTHandle handle, ListSizeTHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListListSizeT\_not\_equal**](#function-listlistsizet_not_equal) (ListListSizeTHandle handle, ListListSizeTHandle other) <br> |
|  void | [**ListListSizeT\_push\_back**](#function-listlistsizet_push_back) (ListListSizeTHandle handle, ListSizeTHandle value) <br> |
|  size\_t | [**ListListSizeT\_size**](#function-listlistsizet_size) (ListListSizeTHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListListSizeT\_to\_json\_string**](#function-listlistsizet_to_json_string) (ListListSizeTHandle handle) <br> |




























## Public Types Documentation




### typedef ListListSizeTHandle 

```C++
typedef void* ListListSizeTHandle;
```




<hr>
## Public Functions Documentation




### function ListListSizeT\_at 

```C++
ListSizeTHandle ListListSizeT_at (
    ListListSizeTHandle handle,
    size_t idx
) 
```




<hr>



### function ListListSizeT\_clear 

```C++
void ListListSizeT_clear (
    ListListSizeTHandle handle
) 
```




<hr>



### function ListListSizeT\_contains 

```C++
bool ListListSizeT_contains (
    ListListSizeTHandle handle,
    ListSizeTHandle value
) 
```




<hr>



### function ListListSizeT\_copy 

```C++
ListListSizeTHandle ListListSizeT_copy (
    ListListSizeTHandle handle
) 
```




<hr>



### function ListListSizeT\_create 

```C++
ListListSizeTHandle ListListSizeT_create (
    ListSizeTHandle * data,
    size_t count
) 
```




<hr>



### function ListListSizeT\_create\_empty 

```C++
ListListSizeTHandle ListListSizeT_create_empty () 
```




<hr>



### function ListListSizeT\_destroy 

```C++
void ListListSizeT_destroy (
    ListListSizeTHandle handle
) 
```




<hr>



### function ListListSizeT\_empty 

```C++
bool ListListSizeT_empty (
    ListListSizeTHandle handle
) 
```




<hr>



### function ListListSizeT\_equal 

```C++
bool ListListSizeT_equal (
    ListListSizeTHandle handle,
    ListListSizeTHandle other
) 
```




<hr>



### function ListListSizeT\_erase\_at 

```C++
void ListListSizeT_erase_at (
    ListListSizeTHandle handle,
    size_t idx
) 
```




<hr>



### function ListListSizeT\_fill\_value 

```C++
ListListSizeTHandle ListListSizeT_fill_value (
    size_t count,
    ListSizeTHandle value
) 
```




<hr>



### function ListListSizeT\_from\_json\_string 

```C++
ListListSizeTHandle ListListSizeT_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListListSizeT\_index 

```C++
size_t ListListSizeT_index (
    ListListSizeTHandle handle,
    ListSizeTHandle value
) 
```




<hr>



### function ListListSizeT\_intersection 

```C++
ListListSizeTHandle ListListSizeT_intersection (
    ListListSizeTHandle handle,
    ListListSizeTHandle other
) 
```




<hr>



### function ListListSizeT\_items 

```C++
size_t ListListSizeT_items (
    ListListSizeTHandle handle,
    ListSizeTHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListListSizeT\_not\_equal 

```C++
bool ListListSizeT_not_equal (
    ListListSizeTHandle handle,
    ListListSizeTHandle other
) 
```




<hr>



### function ListListSizeT\_push\_back 

```C++
void ListListSizeT_push_back (
    ListListSizeTHandle handle,
    ListSizeTHandle value
) 
```




<hr>



### function ListListSizeT\_size 

```C++
size_t ListListSizeT_size (
    ListListSizeTHandle handle
) 
```




<hr>



### function ListListSizeT\_to\_json\_string 

```C++
StringHandle ListListSizeT_to_json_string (
    ListListSizeTHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListListSizeT_c_api.h`

