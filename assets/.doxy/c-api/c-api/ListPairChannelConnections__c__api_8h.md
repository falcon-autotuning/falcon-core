

# File ListPairChannelConnections\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairChannelConnections\_c\_api.h**](ListPairChannelConnections__c__api_8h.md)

[Go to the source code of this file](ListPairChannelConnections__c__api_8h_source.md)



* `#include "falcon_core/generic/PairChannelConnections_c_api.h"`
* `#include <stddef.h>`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ListPairChannelConnectionsHandle**](#typedef-listpairchannelconnectionshandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairChannelConnectionsHandle | [**ListPairChannelConnections\_at**](#function-listpairchannelconnections_at) (ListPairChannelConnectionsHandle handle, size\_t idx) <br> |
|  void | [**ListPairChannelConnections\_clear**](#function-listpairchannelconnections_clear) (ListPairChannelConnectionsHandle handle) <br> |
|  bool | [**ListPairChannelConnections\_contains**](#function-listpairchannelconnections_contains) (ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle value) <br> |
|  ListPairChannelConnectionsHandle | [**ListPairChannelConnections\_copy**](#function-listpairchannelconnections_copy) (ListPairChannelConnectionsHandle handle) <br> |
|  ListPairChannelConnectionsHandle | [**ListPairChannelConnections\_create**](#function-listpairchannelconnections_create) (PairChannelConnectionsHandle \* data, size\_t count) <br> |
|  ListPairChannelConnectionsHandle | [**ListPairChannelConnections\_create\_empty**](#function-listpairchannelconnections_create_empty) () <br> |
|  void | [**ListPairChannelConnections\_destroy**](#function-listpairchannelconnections_destroy) (ListPairChannelConnectionsHandle handle) <br> |
|  bool | [**ListPairChannelConnections\_empty**](#function-listpairchannelconnections_empty) (ListPairChannelConnectionsHandle handle) <br> |
|  bool | [**ListPairChannelConnections\_equal**](#function-listpairchannelconnections_equal) (ListPairChannelConnectionsHandle handle, ListPairChannelConnectionsHandle other) <br> |
|  void | [**ListPairChannelConnections\_erase\_at**](#function-listpairchannelconnections_erase_at) (ListPairChannelConnectionsHandle handle, size\_t idx) <br> |
|  ListPairChannelConnectionsHandle | [**ListPairChannelConnections\_fill\_value**](#function-listpairchannelconnections_fill_value) (size\_t count, PairChannelConnectionsHandle value) <br> |
|  ListPairChannelConnectionsHandle | [**ListPairChannelConnections\_from\_json\_string**](#function-listpairchannelconnections_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  size\_t | [**ListPairChannelConnections\_index**](#function-listpairchannelconnections_index) (ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle value) <br> |
|  ListPairChannelConnectionsHandle | [**ListPairChannelConnections\_intersection**](#function-listpairchannelconnections_intersection) (ListPairChannelConnectionsHandle handle, ListPairChannelConnectionsHandle other) <br> |
|  size\_t | [**ListPairChannelConnections\_items**](#function-listpairchannelconnections_items) (ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle \* out\_buffer, size\_t buffer\_size) <br> |
|  bool | [**ListPairChannelConnections\_not\_equal**](#function-listpairchannelconnections_not_equal) (ListPairChannelConnectionsHandle handle, ListPairChannelConnectionsHandle other) <br> |
|  void | [**ListPairChannelConnections\_push\_back**](#function-listpairchannelconnections_push_back) (ListPairChannelConnectionsHandle handle, PairChannelConnectionsHandle value) <br> |
|  size\_t | [**ListPairChannelConnections\_size**](#function-listpairchannelconnections_size) (ListPairChannelConnectionsHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**ListPairChannelConnections\_to\_json\_string**](#function-listpairchannelconnections_to_json_string) (ListPairChannelConnectionsHandle handle) <br> |




























## Public Types Documentation




### typedef ListPairChannelConnectionsHandle 

```C++
typedef void* ListPairChannelConnectionsHandle;
```




<hr>
## Public Functions Documentation




### function ListPairChannelConnections\_at 

```C++
PairChannelConnectionsHandle ListPairChannelConnections_at (
    ListPairChannelConnectionsHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairChannelConnections\_clear 

```C++
void ListPairChannelConnections_clear (
    ListPairChannelConnectionsHandle handle
) 
```




<hr>



### function ListPairChannelConnections\_contains 

```C++
bool ListPairChannelConnections_contains (
    ListPairChannelConnectionsHandle handle,
    PairChannelConnectionsHandle value
) 
```




<hr>



### function ListPairChannelConnections\_copy 

```C++
ListPairChannelConnectionsHandle ListPairChannelConnections_copy (
    ListPairChannelConnectionsHandle handle
) 
```




<hr>



### function ListPairChannelConnections\_create 

```C++
ListPairChannelConnectionsHandle ListPairChannelConnections_create (
    PairChannelConnectionsHandle * data,
    size_t count
) 
```




<hr>



### function ListPairChannelConnections\_create\_empty 

```C++
ListPairChannelConnectionsHandle ListPairChannelConnections_create_empty () 
```




<hr>



### function ListPairChannelConnections\_destroy 

```C++
void ListPairChannelConnections_destroy (
    ListPairChannelConnectionsHandle handle
) 
```




<hr>



### function ListPairChannelConnections\_empty 

```C++
bool ListPairChannelConnections_empty (
    ListPairChannelConnectionsHandle handle
) 
```




<hr>



### function ListPairChannelConnections\_equal 

```C++
bool ListPairChannelConnections_equal (
    ListPairChannelConnectionsHandle handle,
    ListPairChannelConnectionsHandle other
) 
```




<hr>



### function ListPairChannelConnections\_erase\_at 

```C++
void ListPairChannelConnections_erase_at (
    ListPairChannelConnectionsHandle handle,
    size_t idx
) 
```




<hr>



### function ListPairChannelConnections\_fill\_value 

```C++
ListPairChannelConnectionsHandle ListPairChannelConnections_fill_value (
    size_t count,
    PairChannelConnectionsHandle value
) 
```




<hr>



### function ListPairChannelConnections\_from\_json\_string 

```C++
ListPairChannelConnectionsHandle ListPairChannelConnections_from_json_string (
    StringHandle json
) 
```




<hr>



### function ListPairChannelConnections\_index 

```C++
size_t ListPairChannelConnections_index (
    ListPairChannelConnectionsHandle handle,
    PairChannelConnectionsHandle value
) 
```




<hr>



### function ListPairChannelConnections\_intersection 

```C++
ListPairChannelConnectionsHandle ListPairChannelConnections_intersection (
    ListPairChannelConnectionsHandle handle,
    ListPairChannelConnectionsHandle other
) 
```




<hr>



### function ListPairChannelConnections\_items 

```C++
size_t ListPairChannelConnections_items (
    ListPairChannelConnectionsHandle handle,
    PairChannelConnectionsHandle * out_buffer,
    size_t buffer_size
) 
```




<hr>



### function ListPairChannelConnections\_not\_equal 

```C++
bool ListPairChannelConnections_not_equal (
    ListPairChannelConnectionsHandle handle,
    ListPairChannelConnectionsHandle other
) 
```




<hr>



### function ListPairChannelConnections\_push\_back 

```C++
void ListPairChannelConnections_push_back (
    ListPairChannelConnectionsHandle handle,
    PairChannelConnectionsHandle value
) 
```




<hr>



### function ListPairChannelConnections\_size 

```C++
size_t ListPairChannelConnections_size (
    ListPairChannelConnectionsHandle handle
) 
```




<hr>



### function ListPairChannelConnections\_to\_json\_string 

```C++
StringHandle ListPairChannelConnections_to_json_string (
    ListPairChannelConnectionsHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/ListPairChannelConnections_c_api.h`

