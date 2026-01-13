

# File ListPairConnectionConnections\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairConnectionConnections\_c\_api.h**](ListPairConnectionConnections__c__api_8h.md)

[Go to the source code of this file](ListPairConnectionConnections__c__api_8h_source.md)



* `#include "falcon_core/generic/PairConnectionConnections_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListPairConnectionConnectionsHandle**](#typedef-listpairconnectionconnectionshandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairConnectionConnectionsHandle | [**ListPairConnectionConnections\_at**](#function-listpairconnectionconnections_at) (ListPairConnectionConnectionsHandle handle, size\_t idx) <br> |
|  void | [**ListPairConnectionConnections\_clear**](#function-listpairconnectionconnections_clear) (ListPairConnectionConnectionsHandle handle) <br> |
|  bool | [**ListPairConnectionConnections\_contains**](#function-listpairconnectionconnections_contains) (ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle value) <br> |
|  ListPairConnectionConnectionsHandle | [**ListPairConnectionConnections\_copy**](#function-listpairconnectionconnections_copy) (ListPairConnectionConnectionsHandle handle) <br> |
|  ListPairConnectionConnectionsHandle | [**ListPairConnectionConnections\_create**](#function-listpairconnectionconnections_create) (PairConnectionConnectionsHandle \* data, size\_t count) <br> |
|  ListPairConnectionConnectionsHandle | [**ListPairConnectionConnections\_create\_empty**](#function-listpairconnectionconnections_create_empty) () <br> |
|  void | [**ListPairConnectionConnections\_destroy**](#function-listpairconnectionconnections_destroy) (ListPairConnectionConnectionsHandle handle) <br> |
|  bool | [**ListPairConnectionConnections\_empty**](#function-listpairconnectionconnections_empty) (ListPairConnectionConnectionsHandle handle) <br> |
|  bool | [**ListPairConnectionConnections\_equal**](#function-listpairconnectionconnections_equal) (ListPairConnectionConnectionsHandle handle, ListPairConnectionConnectionsHandle other) <br> |
|  void | [**ListPairConnectionConnections\_erase\_at**](#function-listpairconnectionconnections_erase_at) (ListPairConnectionConnectionsHandle handle, size\_t idx) <br> |
|  ListPairConnectionConnectionsHandle | [**ListPairConnectionConnections\_fill\_value**](#function-listpairconnectionconnections_fill_value) (size\_t count, PairConnectionConnectionsHandle value) <br> |
|  ListPairConnectionConnectionsHandle | [**ListPairConnectionConnections\_from\_json\_string**](#function-listpairconnectionconnections_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListPairConnectionConnections\_index**](#function-listpairconnectionconnections_index) (ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle value) <br> |
|  ListPairConnectionConnectionsHandle | [**ListPairConnectionConnections\_intersection**](#function-listpairconnectionconnections_intersection) (ListPairConnectionConnectionsHandle handle, ListPairConnectionConnectionsHandle other) <br> |
|  size\_t | [**ListPairConnectionConnections\_items**](#function-listpairconnectionconnections_items) (ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListPairConnectionConnections\_not\_equal**](#function-listpairconnectionconnections_not_equal) (ListPairConnectionConnectionsHandle handle, ListPairConnectionConnectionsHandle other) <br> |
|  void | [**ListPairConnectionConnections\_push\_back**](#function-listpairconnectionconnections_push_back) (ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle value) <br> |
|  size\_t | [**ListPairConnectionConnections\_size**](#function-listpairconnectionconnections_size) (ListPairConnectionConnectionsHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListPairConnectionConnections\_to\_json\_string**](#function-listpairconnectionconnections_to_json_string) (ListPairConnectionConnectionsHandle handle) <br> |




























## Public Types Documentation




### typedef ListPairConnectionConnectionsHandle 

```C++
typedef void* ListPairConnectionConnectionsHandle;
```




<hr>
## Public Functions Documentation




### function ListPairConnectionConnections\_at 

```C++
PairConnectionConnectionsHandle ListPairConnectionConnections_at (
    ListPairConnectionConnectionsHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairConnectionConnections\_clear 

```C++
void ListPairConnectionConnections_clear (
    ListPairConnectionConnectionsHandle handle
) 
```




<hr>



### function ListPairConnectionConnections\_contains 

```C++
bool ListPairConnectionConnections_contains (
    ListPairConnectionConnectionsHandle handle,
    PairConnectionConnectionsHandle value
) 
```




<hr>



### function ListPairConnectionConnections\_copy 

```C++
ListPairConnectionConnectionsHandle ListPairConnectionConnections_copy (
    ListPairConnectionConnectionsHandle handle
) 
```




<hr>



### function ListPairConnectionConnections\_create 

```C++
ListPairConnectionConnectionsHandle ListPairConnectionConnections_create (
    PairConnectionConnectionsHandle * data,
    size_t count
) 
```




<hr>



### function ListPairConnectionConnections\_create\_empty 

```C++
ListPairConnectionConnectionsHandle ListPairConnectionConnections_create_empty () 
```




<hr>



### function ListPairConnectionConnections\_destroy 

```C++
void ListPairConnectionConnections_destroy (
    ListPairConnectionConnectionsHandle handle
) 
```




<hr>



### function ListPairConnectionConnections\_empty 

```C++
bool ListPairConnectionConnections_empty (
    ListPairConnectionConnectionsHandle handle
) 
```




<hr>



### function ListPairConnectionConnections\_equal 

```C++
bool ListPairConnectionConnections_equal (
    ListPairConnectionConnectionsHandle handle,
    ListPairConnectionConnectionsHandle other
) 
```




<hr>



### function ListPairConnectionConnections\_erase\_at 

```C++
void ListPairConnectionConnections_erase_at (
    ListPairConnectionConnectionsHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairConnectionConnections\_fill\_value 

```C++
ListPairConnectionConnectionsHandle ListPairConnectionConnections_fill_value (
    size_t count,
    PairConnectionConnectionsHandle value
) 
```




<hr>



### function ListPairConnectionConnections\_from\_json\_string 

```C++
ListPairConnectionConnectionsHandle ListPairConnectionConnections_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListPairConnectionConnections\_index 

```C++
size_t ListPairConnectionConnections_index (
    ListPairConnectionConnectionsHandle handle,
    PairConnectionConnectionsHandle value
) 
```




<hr>



### function ListPairConnectionConnections\_intersection 

```C++
ListPairConnectionConnectionsHandle ListPairConnectionConnections_intersection (
    ListPairConnectionConnectionsHandle handle,
    ListPairConnectionConnectionsHandle other
) 
```




<hr>



### function ListPairConnectionConnections\_items 

```C++
size_t ListPairConnectionConnections_items (
    ListPairConnectionConnectionsHandle handle,
    PairConnectionConnectionsHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListPairConnectionConnections\_not\_equal 

```C++
bool ListPairConnectionConnections_not_equal (
    ListPairConnectionConnectionsHandle handle,
    ListPairConnectionConnectionsHandle other
) 
```




<hr>



### function ListPairConnectionConnections\_push\_back 

```C++
void ListPairConnectionConnections_push_back (
    ListPairConnectionConnectionsHandle handle,
    PairConnectionConnectionsHandle value
) 
```




<hr>



### function ListPairConnectionConnections\_size 

```C++
size_t ListPairConnectionConnections_size (
    ListPairConnectionConnectionsHandle handle
) 
```




<hr>



### function ListPairConnectionConnections\_to\_json\_string 

```C++
StringHandle ListPairConnectionConnections_to_json_string (
    ListPairConnectionConnectionsHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListPairConnectionConnections_c_api.h`

