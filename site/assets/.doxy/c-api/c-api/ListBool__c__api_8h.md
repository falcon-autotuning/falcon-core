

# File ListBool\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListBool\_c\_api.h**](ListBool__c__api_8h.md)

[Go to the source code of this file](ListBool__c__api_8h_source.md)



* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListBoolHandle**](#typedef-listboolhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ListBoolHandle | [**ListBool\_allocate**](#function-listbool_allocate) (size\_t count) <br> |
|  bool | [**ListBool\_at**](#function-listbool_at) (ListBoolHandle handle, size\_t idx) <br> |
|  void | [**ListBool\_clear**](#function-listbool_clear) (ListBoolHandle handle) <br> |
|  bool | [**ListBool\_contains**](#function-listbool_contains) (ListBoolHandle handle, bool value) <br> |
|  ListBoolHandle | [**ListBool\_copy**](#function-listbool_copy) (ListBoolHandle handle) <br> |
|  ListBoolHandle | [**ListBool\_create**](#function-listbool_create) (bool \* data, size\_t count) <br> |
|  ListBoolHandle | [**ListBool\_create\_empty**](#function-listbool_create_empty) () <br> |
|  void | [**ListBool\_destroy**](#function-listbool_destroy) (ListBoolHandle handle) <br> |
|  bool | [**ListBool\_empty**](#function-listbool_empty) (ListBoolHandle handle) <br> |
|  bool | [**ListBool\_equal**](#function-listbool_equal) (ListBoolHandle handle, ListBoolHandle other) <br> |
|  void | [**ListBool\_erase\_at**](#function-listbool_erase_at) (ListBoolHandle handle, size\_t idx) <br> |
|  ListBoolHandle | [**ListBool\_fill\_value**](#function-listbool_fill_value) (size\_t count, bool value) <br> |
|  ListBoolHandle | [**ListBool\_from\_json\_string**](#function-listbool_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ListBool\_index**](#function-listbool_index) (ListBoolHandle handle, bool value) <br> |
|  ListBoolHandle | [**ListBool\_intersection**](#function-listbool_intersection) (ListBoolHandle handle, ListBoolHandle other) <br> |
|  size\_t | [**ListBool\_items**](#function-listbool_items) (ListBoolHandle handle, bool \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListBool\_not\_equal**](#function-listbool_not_equal) (ListBoolHandle handle, ListBoolHandle other) <br> |
|  void | [**ListBool\_push\_back**](#function-listbool_push_back) (ListBoolHandle handle, bool value) <br> |
|  size\_t | [**ListBool\_size**](#function-listbool_size) (ListBoolHandle handle) <br> |
|  StringHandle | [**ListBool\_to\_json\_string**](#function-listbool_to_json_string) (ListBoolHandle handle) <br> |




























## Public Types Documentation




### typedef ListBoolHandle 

```C++
typedef void* ListBoolHandle;
```




<hr>
## Public Functions Documentation




### function ListBool\_allocate 

```C++
ListBoolHandle ListBool_allocate (
    size_t count
) 
```




<hr>



### function ListBool\_at 

```C++
bool ListBool_at (
    ListBoolHandle handle,
    size_t idx
) 
```




<hr>



### function ListBool\_clear 

```C++
void ListBool_clear (
    ListBoolHandle handle
) 
```




<hr>



### function ListBool\_contains 

```C++
bool ListBool_contains (
    ListBoolHandle handle,
    bool value
) 
```




<hr>



### function ListBool\_copy 

```C++
ListBoolHandle ListBool_copy (
    ListBoolHandle handle
) 
```




<hr>



### function ListBool\_create 

```C++
ListBoolHandle ListBool_create (
    bool * data,
    size_t count
) 
```




<hr>



### function ListBool\_create\_empty 

```C++
ListBoolHandle ListBool_create_empty () 
```




<hr>



### function ListBool\_destroy 

```C++
void ListBool_destroy (
    ListBoolHandle handle
) 
```




<hr>



### function ListBool\_empty 

```C++
bool ListBool_empty (
    ListBoolHandle handle
) 
```




<hr>



### function ListBool\_equal 

```C++
bool ListBool_equal (
    ListBoolHandle handle,
    ListBoolHandle other
) 
```




<hr>



### function ListBool\_erase\_at 

```C++
void ListBool_erase_at (
    ListBoolHandle handle,
    size_t idx
) 
```




<hr>



### function ListBool\_fill\_value 

```C++
ListBoolHandle ListBool_fill_value (
    size_t count,
    bool value
) 
```




<hr>



### function ListBool\_from\_json\_string 

```C++
ListBoolHandle ListBool_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListBool\_index 

```C++
size_t ListBool_index (
    ListBoolHandle handle,
    bool value
) 
```




<hr>



### function ListBool\_intersection 

```C++
ListBoolHandle ListBool_intersection (
    ListBoolHandle handle,
    ListBoolHandle other
) 
```




<hr>



### function ListBool\_items 

```C++
size_t ListBool_items (
    ListBoolHandle handle,
    bool * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListBool\_not\_equal 

```C++
bool ListBool_not_equal (
    ListBoolHandle handle,
    ListBoolHandle other
) 
```




<hr>



### function ListBool\_push\_back 

```C++
void ListBool_push_back (
    ListBoolHandle handle,
    bool value
) 
```




<hr>



### function ListBool\_size 

```C++
size_t ListBool_size (
    ListBoolHandle handle
) 
```




<hr>



### function ListBool\_to\_json\_string 

```C++
StringHandle ListBool_to_json_string (
    ListBoolHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListBool_c_api.h`

