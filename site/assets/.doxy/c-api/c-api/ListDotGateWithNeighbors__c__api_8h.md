

# File ListDotGateWithNeighbors\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListDotGateWithNeighbors\_c\_api.h**](ListDotGateWithNeighbors__c__api_8h.md)

[Go to the source code of this file](ListDotGateWithNeighbors__c__api_8h_source.md)



* `#include "falcon_core/physics/config/geometries/DotGateWithNeighbors_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListDotGateWithNeighborsHandle**](#typedef-listdotgatewithneighborshandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  DotGateWithNeighborsHandle | [**ListDotGateWithNeighbors\_at**](#function-listdotgatewithneighbors_at) (ListDotGateWithNeighborsHandle handle, size\_t idx) <br> |
|  void | [**ListDotGateWithNeighbors\_clear**](#function-listdotgatewithneighbors_clear) (ListDotGateWithNeighborsHandle handle) <br> |
|  bool | [**ListDotGateWithNeighbors\_contains**](#function-listdotgatewithneighbors_contains) (ListDotGateWithNeighborsHandle handle, DotGateWithNeighborsHandle value) <br> |
|  ListDotGateWithNeighborsHandle | [**ListDotGateWithNeighbors\_copy**](#function-listdotgatewithneighbors_copy) (ListDotGateWithNeighborsHandle handle) <br> |
|  ListDotGateWithNeighborsHandle | [**ListDotGateWithNeighbors\_create**](#function-listdotgatewithneighbors_create) (DotGateWithNeighborsHandle \* data, size\_t count) <br> |
|  ListDotGateWithNeighborsHandle | [**ListDotGateWithNeighbors\_create\_empty**](#function-listdotgatewithneighbors_create_empty) () <br> |
|  void | [**ListDotGateWithNeighbors\_destroy**](#function-listdotgatewithneighbors_destroy) (ListDotGateWithNeighborsHandle handle) <br> |
|  bool | [**ListDotGateWithNeighbors\_empty**](#function-listdotgatewithneighbors_empty) (ListDotGateWithNeighborsHandle handle) <br> |
|  bool | [**ListDotGateWithNeighbors\_equal**](#function-listdotgatewithneighbors_equal) (ListDotGateWithNeighborsHandle handle, ListDotGateWithNeighborsHandle other) <br> |
|  void | [**ListDotGateWithNeighbors\_erase\_at**](#function-listdotgatewithneighbors_erase_at) (ListDotGateWithNeighborsHandle handle, size\_t idx) <br> |
|  ListDotGateWithNeighborsHandle | [**ListDotGateWithNeighbors\_fill\_value**](#function-listdotgatewithneighbors_fill_value) (size\_t count, DotGateWithNeighborsHandle value) <br> |
|  ListDotGateWithNeighborsHandle | [**ListDotGateWithNeighbors\_from\_json\_string**](#function-listdotgatewithneighbors_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ListDotGateWithNeighbors\_index**](#function-listdotgatewithneighbors_index) (ListDotGateWithNeighborsHandle handle, DotGateWithNeighborsHandle value) <br> |
|  ListDotGateWithNeighborsHandle | [**ListDotGateWithNeighbors\_intersection**](#function-listdotgatewithneighbors_intersection) (ListDotGateWithNeighborsHandle handle, ListDotGateWithNeighborsHandle other) <br> |
|  size\_t | [**ListDotGateWithNeighbors\_items**](#function-listdotgatewithneighbors_items) (ListDotGateWithNeighborsHandle handle, DotGateWithNeighborsHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListDotGateWithNeighbors\_not\_equal**](#function-listdotgatewithneighbors_not_equal) (ListDotGateWithNeighborsHandle handle, ListDotGateWithNeighborsHandle other) <br> |
|  void | [**ListDotGateWithNeighbors\_push\_back**](#function-listdotgatewithneighbors_push_back) (ListDotGateWithNeighborsHandle handle, DotGateWithNeighborsHandle value) <br> |
|  size\_t | [**ListDotGateWithNeighbors\_size**](#function-listdotgatewithneighbors_size) (ListDotGateWithNeighborsHandle handle) <br> |
|  StringHandle | [**ListDotGateWithNeighbors\_to\_json\_string**](#function-listdotgatewithneighbors_to_json_string) (ListDotGateWithNeighborsHandle handle) <br> |




























## Public Types Documentation




### typedef ListDotGateWithNeighborsHandle 

```C++
typedef void* ListDotGateWithNeighborsHandle;
```




<hr>
## Public Functions Documentation




### function ListDotGateWithNeighbors\_at 

```C++
DotGateWithNeighborsHandle ListDotGateWithNeighbors_at (
    ListDotGateWithNeighborsHandle handle,
    size_t idx
) 
```




<hr>



### function ListDotGateWithNeighbors\_clear 

```C++
void ListDotGateWithNeighbors_clear (
    ListDotGateWithNeighborsHandle handle
) 
```




<hr>



### function ListDotGateWithNeighbors\_contains 

```C++
bool ListDotGateWithNeighbors_contains (
    ListDotGateWithNeighborsHandle handle,
    DotGateWithNeighborsHandle value
) 
```




<hr>



### function ListDotGateWithNeighbors\_copy 

```C++
ListDotGateWithNeighborsHandle ListDotGateWithNeighbors_copy (
    ListDotGateWithNeighborsHandle handle
) 
```




<hr>



### function ListDotGateWithNeighbors\_create 

```C++
ListDotGateWithNeighborsHandle ListDotGateWithNeighbors_create (
    DotGateWithNeighborsHandle * data,
    size_t count
) 
```




<hr>



### function ListDotGateWithNeighbors\_create\_empty 

```C++
ListDotGateWithNeighborsHandle ListDotGateWithNeighbors_create_empty () 
```




<hr>



### function ListDotGateWithNeighbors\_destroy 

```C++
void ListDotGateWithNeighbors_destroy (
    ListDotGateWithNeighborsHandle handle
) 
```




<hr>



### function ListDotGateWithNeighbors\_empty 

```C++
bool ListDotGateWithNeighbors_empty (
    ListDotGateWithNeighborsHandle handle
) 
```




<hr>



### function ListDotGateWithNeighbors\_equal 

```C++
bool ListDotGateWithNeighbors_equal (
    ListDotGateWithNeighborsHandle handle,
    ListDotGateWithNeighborsHandle other
) 
```




<hr>



### function ListDotGateWithNeighbors\_erase\_at 

```C++
void ListDotGateWithNeighbors_erase_at (
    ListDotGateWithNeighborsHandle handle,
    size_t idx
) 
```




<hr>



### function ListDotGateWithNeighbors\_fill\_value 

```C++
ListDotGateWithNeighborsHandle ListDotGateWithNeighbors_fill_value (
    size_t count,
    DotGateWithNeighborsHandle value
) 
```




<hr>



### function ListDotGateWithNeighbors\_from\_json\_string 

```C++
ListDotGateWithNeighborsHandle ListDotGateWithNeighbors_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListDotGateWithNeighbors\_index 

```C++
size_t ListDotGateWithNeighbors_index (
    ListDotGateWithNeighborsHandle handle,
    DotGateWithNeighborsHandle value
) 
```




<hr>



### function ListDotGateWithNeighbors\_intersection 

```C++
ListDotGateWithNeighborsHandle ListDotGateWithNeighbors_intersection (
    ListDotGateWithNeighborsHandle handle,
    ListDotGateWithNeighborsHandle other
) 
```




<hr>



### function ListDotGateWithNeighbors\_items 

```C++
size_t ListDotGateWithNeighbors_items (
    ListDotGateWithNeighborsHandle handle,
    DotGateWithNeighborsHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListDotGateWithNeighbors\_not\_equal 

```C++
bool ListDotGateWithNeighbors_not_equal (
    ListDotGateWithNeighborsHandle handle,
    ListDotGateWithNeighborsHandle other
) 
```




<hr>



### function ListDotGateWithNeighbors\_push\_back 

```C++
void ListDotGateWithNeighbors_push_back (
    ListDotGateWithNeighborsHandle handle,
    DotGateWithNeighborsHandle value
) 
```




<hr>



### function ListDotGateWithNeighbors\_size 

```C++
size_t ListDotGateWithNeighbors_size (
    ListDotGateWithNeighborsHandle handle
) 
```




<hr>



### function ListDotGateWithNeighbors\_to\_json\_string 

```C++
StringHandle ListDotGateWithNeighbors_to_json_string (
    ListDotGateWithNeighborsHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListDotGateWithNeighbors_c_api.h`

