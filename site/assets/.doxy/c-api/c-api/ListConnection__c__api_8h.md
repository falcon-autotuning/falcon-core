

# File ListConnection\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListConnection\_c\_api.h**](ListConnection__c__api_8h.md)

[Go to the source code of this file](ListConnection__c__api_8h_source.md)



* `#include "falcon_core/physics/device_structures/Connection_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListConnectionHandle**](#typedef-listconnectionhandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ConnectionHandle | [**ListConnection\_at**](#function-listconnection_at) (ListConnectionHandle handle, size\_t idx) <br> |
|  void | [**ListConnection\_clear**](#function-listconnection_clear) (ListConnectionHandle handle) <br> |
|  bool | [**ListConnection\_contains**](#function-listconnection_contains) (ListConnectionHandle handle, ConnectionHandle value) <br> |
|  ListConnectionHandle | [**ListConnection\_copy**](#function-listconnection_copy) (ListConnectionHandle handle) <br> |
|  ListConnectionHandle | [**ListConnection\_create**](#function-listconnection_create) (ConnectionHandle \* data, size\_t count) <br> |
|  ListConnectionHandle | [**ListConnection\_create\_empty**](#function-listconnection_create_empty) () <br> |
|  void | [**ListConnection\_destroy**](#function-listconnection_destroy) (ListConnectionHandle handle) <br> |
|  bool | [**ListConnection\_empty**](#function-listconnection_empty) (ListConnectionHandle handle) <br> |
|  bool | [**ListConnection\_equal**](#function-listconnection_equal) (ListConnectionHandle handle, ListConnectionHandle other) <br> |
|  void | [**ListConnection\_erase\_at**](#function-listconnection_erase_at) (ListConnectionHandle handle, size\_t idx) <br> |
|  ListConnectionHandle | [**ListConnection\_fill\_value**](#function-listconnection_fill_value) (size\_t count, ConnectionHandle value) <br> |
|  ListConnectionHandle | [**ListConnection\_from\_json\_string**](#function-listconnection_from_json_string) (StringHandle json) <br> |
|  size\_t | [**ListConnection\_index**](#function-listconnection_index) (ListConnectionHandle handle, ConnectionHandle value) <br> |
|  ListConnectionHandle | [**ListConnection\_intersection**](#function-listconnection_intersection) (ListConnectionHandle handle, ListConnectionHandle other) <br> |
|  size\_t | [**ListConnection\_items**](#function-listconnection_items) (ListConnectionHandle handle, ConnectionHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListConnection\_not\_equal**](#function-listconnection_not_equal) (ListConnectionHandle handle, ListConnectionHandle other) <br> |
|  void | [**ListConnection\_push\_back**](#function-listconnection_push_back) (ListConnectionHandle handle, ConnectionHandle value) <br> |
|  size\_t | [**ListConnection\_size**](#function-listconnection_size) (ListConnectionHandle handle) <br> |
|  StringHandle | [**ListConnection\_to\_json\_string**](#function-listconnection_to_json_string) (ListConnectionHandle handle) <br> |




























## Public Types Documentation




### typedef ListConnectionHandle 

```C++
typedef void* ListConnectionHandle;
```




<hr>
## Public Functions Documentation




### function ListConnection\_at 

```C++
ConnectionHandle ListConnection_at (
    ListConnectionHandle handle,
    size_t idx
) 
```




<hr>



### function ListConnection\_clear 

```C++
void ListConnection_clear (
    ListConnectionHandle handle
) 
```




<hr>



### function ListConnection\_contains 

```C++
bool ListConnection_contains (
    ListConnectionHandle handle,
    ConnectionHandle value
) 
```




<hr>



### function ListConnection\_copy 

```C++
ListConnectionHandle ListConnection_copy (
    ListConnectionHandle handle
) 
```




<hr>



### function ListConnection\_create 

```C++
ListConnectionHandle ListConnection_create (
    ConnectionHandle * data,
    size_t count
) 
```




<hr>



### function ListConnection\_create\_empty 

```C++
ListConnectionHandle ListConnection_create_empty () 
```




<hr>



### function ListConnection\_destroy 

```C++
void ListConnection_destroy (
    ListConnectionHandle handle
) 
```




<hr>



### function ListConnection\_empty 

```C++
bool ListConnection_empty (
    ListConnectionHandle handle
) 
```




<hr>



### function ListConnection\_equal 

```C++
bool ListConnection_equal (
    ListConnectionHandle handle,
    ListConnectionHandle other
) 
```




<hr>



### function ListConnection\_erase\_at 

```C++
void ListConnection_erase_at (
    ListConnectionHandle handle,
    size_t idx
) 
```




<hr>



### function ListConnection\_fill\_value 

```C++
ListConnectionHandle ListConnection_fill_value (
    size_t count,
    ConnectionHandle value
) 
```




<hr>



### function ListConnection\_from\_json\_string 

```C++
ListConnectionHandle ListConnection_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListConnection\_index 

```C++
size_t ListConnection_index (
    ListConnectionHandle handle,
    ConnectionHandle value
) 
```




<hr>



### function ListConnection\_intersection 

```C++
ListConnectionHandle ListConnection_intersection (
    ListConnectionHandle handle,
    ListConnectionHandle other
) 
```




<hr>



### function ListConnection\_items 

```C++
size_t ListConnection_items (
    ListConnectionHandle handle,
    ConnectionHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListConnection\_not\_equal 

```C++
bool ListConnection_not_equal (
    ListConnectionHandle handle,
    ListConnectionHandle other
) 
```




<hr>



### function ListConnection\_push\_back 

```C++
void ListConnection_push_back (
    ListConnectionHandle handle,
    ConnectionHandle value
) 
```




<hr>



### function ListConnection\_size 

```C++
size_t ListConnection_size (
    ListConnectionHandle handle
) 
```




<hr>



### function ListConnection\_to\_json\_string 

```C++
StringHandle ListConnection_to_json_string (
    ListConnectionHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListConnection_c_api.h`

