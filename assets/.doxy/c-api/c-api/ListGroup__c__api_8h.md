

# File ListGroup\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListGroup\_c\_api.h**](ListGroup__c__api_8h.md)

[Go to the source code of this file](ListGroup__c__api_8h_source.md)



* `#include "falcon_core/physics/config/core/Group_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListGroupHandle**](#typedef-listgrouphandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  GroupHandle | [**ListGroup\_at**](#function-listgroup_at) (ListGroupHandle handle, size\_t idx) <br> |
|  void | [**ListGroup\_clear**](#function-listgroup_clear) (ListGroupHandle handle) <br> |
|  bool | [**ListGroup\_contains**](#function-listgroup_contains) (ListGroupHandle handle, GroupHandle value) <br> |
|  ListGroupHandle | [**ListGroup\_copy**](#function-listgroup_copy) (ListGroupHandle handle) <br> |
|  ListGroupHandle | [**ListGroup\_create**](#function-listgroup_create) (GroupHandle \* data, size\_t count) <br> |
|  ListGroupHandle | [**ListGroup\_create\_empty**](#function-listgroup_create_empty) () <br> |
|  void | [**ListGroup\_destroy**](#function-listgroup_destroy) (ListGroupHandle handle) <br> |
|  bool | [**ListGroup\_empty**](#function-listgroup_empty) (ListGroupHandle handle) <br> |
|  bool | [**ListGroup\_equal**](#function-listgroup_equal) (ListGroupHandle handle, ListGroupHandle other) <br> |
|  void | [**ListGroup\_erase\_at**](#function-listgroup_erase_at) (ListGroupHandle handle, size\_t idx) <br> |
|  ListGroupHandle | [**ListGroup\_fill\_value**](#function-listgroup_fill_value) (size\_t count, GroupHandle value) <br> |
|  ListGroupHandle | [**ListGroup\_from\_json\_string**](#function-listgroup_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListGroup\_index**](#function-listgroup_index) (ListGroupHandle handle, GroupHandle value) <br> |
|  ListGroupHandle | [**ListGroup\_intersection**](#function-listgroup_intersection) (ListGroupHandle handle, ListGroupHandle other) <br> |
|  size\_t | [**ListGroup\_items**](#function-listgroup_items) (ListGroupHandle handle, GroupHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListGroup\_not\_equal**](#function-listgroup_not_equal) (ListGroupHandle handle, ListGroupHandle other) <br> |
|  void | [**ListGroup\_push\_back**](#function-listgroup_push_back) (ListGroupHandle handle, GroupHandle value) <br> |
|  size\_t | [**ListGroup\_size**](#function-listgroup_size) (ListGroupHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListGroup\_to\_json\_string**](#function-listgroup_to_json_string) (ListGroupHandle handle) <br> |




























## Public Types Documentation




### typedef ListGroupHandle 

```C++
typedef void* ListGroupHandle;
```




<hr>
## Public Functions Documentation




### function ListGroup\_at 

```C++
GroupHandle ListGroup_at (
    ListGroupHandle handle,
    size_t idx
) 
```




<hr>



### function ListGroup\_clear 

```C++
void ListGroup_clear (
    ListGroupHandle handle
) 
```




<hr>



### function ListGroup\_contains 

```C++
bool ListGroup_contains (
    ListGroupHandle handle,
    GroupHandle value
) 
```




<hr>



### function ListGroup\_copy 

```C++
ListGroupHandle ListGroup_copy (
    ListGroupHandle handle
) 
```




<hr>



### function ListGroup\_create 

```C++
ListGroupHandle ListGroup_create (
    GroupHandle * data,
    size_t count
) 
```




<hr>



### function ListGroup\_create\_empty 

```C++
ListGroupHandle ListGroup_create_empty () 
```




<hr>



### function ListGroup\_destroy 

```C++
void ListGroup_destroy (
    ListGroupHandle handle
) 
```




<hr>



### function ListGroup\_empty 

```C++
bool ListGroup_empty (
    ListGroupHandle handle
) 
```




<hr>



### function ListGroup\_equal 

```C++
bool ListGroup_equal (
    ListGroupHandle handle,
    ListGroupHandle other
) 
```




<hr>



### function ListGroup\_erase\_at 

```C++
void ListGroup_erase_at (
    ListGroupHandle handle,
    size_t idx
) 
```




<hr>



### function ListGroup\_fill\_value 

```C++
ListGroupHandle ListGroup_fill_value (
    size_t count,
    GroupHandle value
) 
```




<hr>



### function ListGroup\_from\_json\_string 

```C++
ListGroupHandle ListGroup_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListGroup\_index 

```C++
size_t ListGroup_index (
    ListGroupHandle handle,
    GroupHandle value
) 
```




<hr>



### function ListGroup\_intersection 

```C++
ListGroupHandle ListGroup_intersection (
    ListGroupHandle handle,
    ListGroupHandle other
) 
```




<hr>



### function ListGroup\_items 

```C++
size_t ListGroup_items (
    ListGroupHandle handle,
    GroupHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListGroup\_not\_equal 

```C++
bool ListGroup_not_equal (
    ListGroupHandle handle,
    ListGroupHandle other
) 
```




<hr>



### function ListGroup\_push\_back 

```C++
void ListGroup_push_back (
    ListGroupHandle handle,
    GroupHandle value
) 
```




<hr>



### function ListGroup\_size 

```C++
size_t ListGroup_size (
    ListGroupHandle handle
) 
```




<hr>



### function ListGroup\_to\_json\_string 

```C++
StringHandle ListGroup_to_json_string (
    ListGroupHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListGroup_c_api.h`

