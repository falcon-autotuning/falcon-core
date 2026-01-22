

# File ListConnections\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListConnections\_c\_api.h**](ListConnections__c__api_8h.md)

[Go to the source code of this file](ListConnections__c__api_8h_source.md)



* `#include "falcon_core/physics/device_structures/Connections_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListConnectionsHandle**](#typedef-listconnectionshandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ConnectionsHandle | [**ListConnections\_at**](#function-listconnections_at) (ListConnectionsHandle handle, size\_t idx) <br> |
|  void | [**ListConnections\_clear**](#function-listconnections_clear) (ListConnectionsHandle handle) <br> |
|  bool | [**ListConnections\_contains**](#function-listconnections_contains) (ListConnectionsHandle handle, ConnectionsHandle value) <br> |
|  ListConnectionsHandle | [**ListConnections\_copy**](#function-listconnections_copy) (ListConnectionsHandle handle) <br> |
|  ListConnectionsHandle | [**ListConnections\_create**](#function-listconnections_create) (ConnectionsHandle \* data, size\_t count) <br> |
|  ListConnectionsHandle | [**ListConnections\_create\_empty**](#function-listconnections_create_empty) () <br> |
|  void | [**ListConnections\_destroy**](#function-listconnections_destroy) (ListConnectionsHandle handle) <br> |
|  bool | [**ListConnections\_empty**](#function-listconnections_empty) (ListConnectionsHandle handle) <br> |
|  bool | [**ListConnections\_equal**](#function-listconnections_equal) (ListConnectionsHandle handle, ListConnectionsHandle other) <br> |
|  void | [**ListConnections\_erase\_at**](#function-listconnections_erase_at) (ListConnectionsHandle handle, size\_t idx) <br> |
|  ListConnectionsHandle | [**ListConnections\_fill\_value**](#function-listconnections_fill_value) (size\_t count, ConnectionsHandle value) <br> |
|  ListConnectionsHandle | [**ListConnections\_from\_json\_string**](#function-listconnections_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ListConnections\_index**](#function-listconnections_index) (ListConnectionsHandle handle, ConnectionsHandle value) <br> |
|  ListConnectionsHandle | [**ListConnections\_intersection**](#function-listconnections_intersection) (ListConnectionsHandle handle, ListConnectionsHandle other) <br> |
|  size\_t | [**ListConnections\_items**](#function-listconnections_items) (ListConnectionsHandle handle, ConnectionsHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListConnections\_not\_equal**](#function-listconnections_not_equal) (ListConnectionsHandle handle, ListConnectionsHandle other) <br> |
|  void | [**ListConnections\_push\_back**](#function-listconnections_push_back) (ListConnectionsHandle handle, ConnectionsHandle value) <br> |
|  size\_t | [**ListConnections\_size**](#function-listconnections_size) (ListConnectionsHandle handle) <br> |
|  StringHandle | [**ListConnections\_to\_json\_string**](#function-listconnections_to_json_string) (ListConnectionsHandle handle) <br> |




























## Public Types Documentation




### typedef ListConnectionsHandle 

```C++
typedef void* ListConnectionsHandle;
```




<hr>
## Public Functions Documentation




### function ListConnections\_at 

```C++
ConnectionsHandle ListConnections_at (
    ListConnectionsHandle handle,
    size_t idx
) 
```




<hr>



### function ListConnections\_clear 

```C++
void ListConnections_clear (
    ListConnectionsHandle handle
) 
```




<hr>



### function ListConnections\_contains 

```C++
bool ListConnections_contains (
    ListConnectionsHandle handle,
    ConnectionsHandle value
) 
```




<hr>



### function ListConnections\_copy 

```C++
ListConnectionsHandle ListConnections_copy (
    ListConnectionsHandle handle
) 
```




<hr>



### function ListConnections\_create 

```C++
ListConnectionsHandle ListConnections_create (
    ConnectionsHandle * data,
    size_t count
) 
```




<hr>



### function ListConnections\_create\_empty 

```C++
ListConnectionsHandle ListConnections_create_empty () 
```




<hr>



### function ListConnections\_destroy 

```C++
void ListConnections_destroy (
    ListConnectionsHandle handle
) 
```




<hr>



### function ListConnections\_empty 

```C++
bool ListConnections_empty (
    ListConnectionsHandle handle
) 
```




<hr>



### function ListConnections\_equal 

```C++
bool ListConnections_equal (
    ListConnectionsHandle handle,
    ListConnectionsHandle other
) 
```




<hr>



### function ListConnections\_erase\_at 

```C++
void ListConnections_erase_at (
    ListConnectionsHandle handle,
    size_t idx
) 
```




<hr>



### function ListConnections\_fill\_value 

```C++
ListConnectionsHandle ListConnections_fill_value (
    size_t count,
    ConnectionsHandle value
) 
```




<hr>



### function ListConnections\_from\_json\_string 

```C++
ListConnectionsHandle ListConnections_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListConnections\_index 

```C++
size_t ListConnections_index (
    ListConnectionsHandle handle,
    ConnectionsHandle value
) 
```




<hr>



### function ListConnections\_intersection 

```C++
ListConnectionsHandle ListConnections_intersection (
    ListConnectionsHandle handle,
    ListConnectionsHandle other
) 
```




<hr>



### function ListConnections\_items 

```C++
size_t ListConnections_items (
    ListConnectionsHandle handle,
    ConnectionsHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListConnections\_not\_equal 

```C++
bool ListConnections_not_equal (
    ListConnectionsHandle handle,
    ListConnectionsHandle other
) 
```




<hr>



### function ListConnections\_push\_back 

```C++
void ListConnections_push_back (
    ListConnectionsHandle handle,
    ConnectionsHandle value
) 
```




<hr>



### function ListConnections\_size 

```C++
size_t ListConnections_size (
    ListConnectionsHandle handle
) 
```




<hr>



### function ListConnections\_to\_json\_string 

```C++
StringHandle ListConnections_to_json_string (
    ListConnectionsHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListConnections_c_api.h`

