

# File ListMapStringBool\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListMapStringBool\_c\_api.h**](ListMapStringBool__c__api_8h.md)

[Go to the source code of this file](ListMapStringBool__c__api_8h_source.md)



* `#include "falcon_core/generic/MapStringBool_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListMapStringBoolHandle**](#typedef-listmapstringboolhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  MapStringBoolHandle | [**ListMapStringBool\_at**](#function-listmapstringbool_at) (ListMapStringBoolHandle handle, size\_t idx) <br> |
|  void | [**ListMapStringBool\_clear**](#function-listmapstringbool_clear) (ListMapStringBoolHandle handle) <br> |
|  bool | [**ListMapStringBool\_contains**](#function-listmapstringbool_contains) (ListMapStringBoolHandle handle, MapStringBoolHandle value) <br> |
|  ListMapStringBoolHandle | [**ListMapStringBool\_copy**](#function-listmapstringbool_copy) (ListMapStringBoolHandle handle) <br> |
|  ListMapStringBoolHandle | [**ListMapStringBool\_create**](#function-listmapstringbool_create) (MapStringBoolHandle \* data, size\_t count) <br> |
|  ListMapStringBoolHandle | [**ListMapStringBool\_create\_empty**](#function-listmapstringbool_create_empty) () <br> |
|  void | [**ListMapStringBool\_destroy**](#function-listmapstringbool_destroy) (ListMapStringBoolHandle handle) <br> |
|  bool | [**ListMapStringBool\_empty**](#function-listmapstringbool_empty) (ListMapStringBoolHandle handle) <br> |
|  bool | [**ListMapStringBool\_equal**](#function-listmapstringbool_equal) (ListMapStringBoolHandle handle, ListMapStringBoolHandle other) <br> |
|  void | [**ListMapStringBool\_erase\_at**](#function-listmapstringbool_erase_at) (ListMapStringBoolHandle handle, size\_t idx) <br> |
|  ListMapStringBoolHandle | [**ListMapStringBool\_fill\_value**](#function-listmapstringbool_fill_value) (size\_t count, MapStringBoolHandle value) <br> |
|  ListMapStringBoolHandle | [**ListMapStringBool\_from\_json\_string**](#function-listmapstringbool_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ListMapStringBool\_index**](#function-listmapstringbool_index) (ListMapStringBoolHandle handle, MapStringBoolHandle value) <br> |
|  ListMapStringBoolHandle | [**ListMapStringBool\_intersection**](#function-listmapstringbool_intersection) (ListMapStringBoolHandle handle, ListMapStringBoolHandle other) <br> |
|  size\_t | [**ListMapStringBool\_items**](#function-listmapstringbool_items) (ListMapStringBoolHandle handle, MapStringBoolHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListMapStringBool\_not\_equal**](#function-listmapstringbool_not_equal) (ListMapStringBoolHandle handle, ListMapStringBoolHandle other) <br> |
|  void | [**ListMapStringBool\_push\_back**](#function-listmapstringbool_push_back) (ListMapStringBoolHandle handle, MapStringBoolHandle value) <br> |
|  size\_t | [**ListMapStringBool\_size**](#function-listmapstringbool_size) (ListMapStringBoolHandle handle) <br> |
|  StringHandle | [**ListMapStringBool\_to\_json\_string**](#function-listmapstringbool_to_json_string) (ListMapStringBoolHandle handle) <br> |




























## Public Types Documentation




### typedef ListMapStringBoolHandle 

```C++
typedef void* ListMapStringBoolHandle;
```




<hr>
## Public Functions Documentation




### function ListMapStringBool\_at 

```C++
MapStringBoolHandle ListMapStringBool_at (
    ListMapStringBoolHandle handle,
    size_t idx
) 
```




<hr>



### function ListMapStringBool\_clear 

```C++
void ListMapStringBool_clear (
    ListMapStringBoolHandle handle
) 
```




<hr>



### function ListMapStringBool\_contains 

```C++
bool ListMapStringBool_contains (
    ListMapStringBoolHandle handle,
    MapStringBoolHandle value
) 
```




<hr>



### function ListMapStringBool\_copy 

```C++
ListMapStringBoolHandle ListMapStringBool_copy (
    ListMapStringBoolHandle handle
) 
```




<hr>



### function ListMapStringBool\_create 

```C++
ListMapStringBoolHandle ListMapStringBool_create (
    MapStringBoolHandle * data,
    size_t count
) 
```




<hr>



### function ListMapStringBool\_create\_empty 

```C++
ListMapStringBoolHandle ListMapStringBool_create_empty () 
```




<hr>



### function ListMapStringBool\_destroy 

```C++
void ListMapStringBool_destroy (
    ListMapStringBoolHandle handle
) 
```




<hr>



### function ListMapStringBool\_empty 

```C++
bool ListMapStringBool_empty (
    ListMapStringBoolHandle handle
) 
```




<hr>



### function ListMapStringBool\_equal 

```C++
bool ListMapStringBool_equal (
    ListMapStringBoolHandle handle,
    ListMapStringBoolHandle other
) 
```




<hr>



### function ListMapStringBool\_erase\_at 

```C++
void ListMapStringBool_erase_at (
    ListMapStringBoolHandle handle,
    size_t idx
) 
```




<hr>



### function ListMapStringBool\_fill\_value 

```C++
ListMapStringBoolHandle ListMapStringBool_fill_value (
    size_t count,
    MapStringBoolHandle value
) 
```




<hr>



### function ListMapStringBool\_from\_json\_string 

```C++
ListMapStringBoolHandle ListMapStringBool_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListMapStringBool\_index 

```C++
size_t ListMapStringBool_index (
    ListMapStringBoolHandle handle,
    MapStringBoolHandle value
) 
```




<hr>



### function ListMapStringBool\_intersection 

```C++
ListMapStringBoolHandle ListMapStringBool_intersection (
    ListMapStringBoolHandle handle,
    ListMapStringBoolHandle other
) 
```




<hr>



### function ListMapStringBool\_items 

```C++
size_t ListMapStringBool_items (
    ListMapStringBoolHandle handle,
    MapStringBoolHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListMapStringBool\_not\_equal 

```C++
bool ListMapStringBool_not_equal (
    ListMapStringBoolHandle handle,
    ListMapStringBoolHandle other
) 
```




<hr>



### function ListMapStringBool\_push\_back 

```C++
void ListMapStringBool_push_back (
    ListMapStringBoolHandle handle,
    MapStringBoolHandle value
) 
```




<hr>



### function ListMapStringBool\_size 

```C++
size_t ListMapStringBool_size (
    ListMapStringBoolHandle handle
) 
```




<hr>



### function ListMapStringBool\_to\_json\_string 

```C++
StringHandle ListMapStringBool_to_json_string (
    ListMapStringBoolHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListMapStringBool_c_api.h`

