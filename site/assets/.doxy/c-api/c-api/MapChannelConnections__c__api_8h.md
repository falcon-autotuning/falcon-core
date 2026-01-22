

# File MapChannelConnections\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**MapChannelConnections\_c\_api.h**](MapChannelConnections__c__api_8h.md)

[Go to the source code of this file](MapChannelConnections__c__api_8h_source.md)



* `#include "falcon_core/generic/PairChannelConnections_c_api.h"`
* `#include "falcon_core/generic/ListChannel_c_api.h"`
* `#include "falcon_core/generic/ListConnections_c_api.h"`
* `#include "falcon_core/generic/ListPairChannelConnections_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**MapChannelConnectionsHandle**](#typedef-mapchannelconnectionshandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ConnectionsHandle | [**MapChannelConnections\_at**](#function-mapchannelconnections_at) (MapChannelConnectionsHandle handle, ChannelHandle key) <br> |
|  void | [**MapChannelConnections\_clear**](#function-mapchannelconnections_clear) (MapChannelConnectionsHandle handle) <br> |
|  bool | [**MapChannelConnections\_contains**](#function-mapchannelconnections_contains) (MapChannelConnectionsHandle handle, ChannelHandle key) <br> |
|  MapChannelConnectionsHandle | [**MapChannelConnections\_copy**](#function-mapchannelconnections_copy) (MapChannelConnectionsHandle handle) <br> |
|  MapChannelConnectionsHandle | [**MapChannelConnections\_create**](#function-mapchannelconnections_create) (PairChannelConnectionsHandle \* data, size\_t count) <br> |
|  MapChannelConnectionsHandle | [**MapChannelConnections\_create\_empty**](#function-mapchannelconnections_create_empty) () <br> |
|  void | [**MapChannelConnections\_destroy**](#function-mapchannelconnections_destroy) (MapChannelConnectionsHandle handle) <br> |
|  bool | [**MapChannelConnections\_empty**](#function-mapchannelconnections_empty) (MapChannelConnectionsHandle handle) <br> |
|  bool | [**MapChannelConnections\_equal**](#function-mapchannelconnections_equal) (MapChannelConnectionsHandle handle, MapChannelConnectionsHandle other) <br> |
|  void | [**MapChannelConnections\_erase**](#function-mapchannelconnections_erase) (MapChannelConnectionsHandle handle, ChannelHandle key) <br> |
|  MapChannelConnectionsHandle | [**MapChannelConnections\_from\_json\_string**](#function-mapchannelconnections_from_json_string) (StringHandle json) <br> |
|  void | [**MapChannelConnections\_insert**](#function-mapchannelconnections_insert) (MapChannelConnectionsHandle handle, ChannelHandle key, ConnectionsHandle value) <br> |
|  void | [**MapChannelConnections\_insert\_or\_assign**](#function-mapchannelconnections_insert_or_assign) (MapChannelConnectionsHandle handle, ChannelHandle key, ConnectionsHandle value) <br> |
|  ListPairChannelConnectionsHandle | [**MapChannelConnections\_items**](#function-mapchannelconnections_items) (MapChannelConnectionsHandle handle) <br> |
|  ListChannelHandle | [**MapChannelConnections\_keys**](#function-mapchannelconnections_keys) (MapChannelConnectionsHandle handle) <br> |
|  bool | [**MapChannelConnections\_not\_equal**](#function-mapchannelconnections_not_equal) (MapChannelConnectionsHandle handle, MapChannelConnectionsHandle other) <br> |
|  size\_t | [**MapChannelConnections\_size**](#function-mapchannelconnections_size) (MapChannelConnectionsHandle handle) <br> |
|  StringHandle | [**MapChannelConnections\_to\_json\_string**](#function-mapchannelconnections_to_json_string) (MapChannelConnectionsHandle handle) <br> |
|  ListConnectionsHandle | [**MapChannelConnections\_values**](#function-mapchannelconnections_values) (MapChannelConnectionsHandle handle) <br> |




























## Public Types Documentation




### typedef MapChannelConnectionsHandle 

```C++
typedef void* MapChannelConnectionsHandle;
```




<hr>
## Public Functions Documentation




### function MapChannelConnections\_at 

```C++
ConnectionsHandle MapChannelConnections_at (
    MapChannelConnectionsHandle handle,
    ChannelHandle key
) 
```




<hr>



### function MapChannelConnections\_clear 

```C++
void MapChannelConnections_clear (
    MapChannelConnectionsHandle handle
) 
```




<hr>



### function MapChannelConnections\_contains 

```C++
bool MapChannelConnections_contains (
    MapChannelConnectionsHandle handle,
    ChannelHandle key
) 
```




<hr>



### function MapChannelConnections\_copy 

```C++
MapChannelConnectionsHandle MapChannelConnections_copy (
    MapChannelConnectionsHandle handle
) 
```




<hr>



### function MapChannelConnections\_create 

```C++
MapChannelConnectionsHandle MapChannelConnections_create (
    PairChannelConnectionsHandle * data,
    size_t count
) 
```




<hr>



### function MapChannelConnections\_create\_empty 

```C++
MapChannelConnectionsHandle MapChannelConnections_create_empty () 
```




<hr>



### function MapChannelConnections\_destroy 

```C++
void MapChannelConnections_destroy (
    MapChannelConnectionsHandle handle
) 
```




<hr>



### function MapChannelConnections\_empty 

```C++
bool MapChannelConnections_empty (
    MapChannelConnectionsHandle handle
) 
```




<hr>



### function MapChannelConnections\_equal 

```C++
bool MapChannelConnections_equal (
    MapChannelConnectionsHandle handle,
    MapChannelConnectionsHandle other
) 
```




<hr>



### function MapChannelConnections\_erase 

```C++
void MapChannelConnections_erase (
    MapChannelConnectionsHandle handle,
    ChannelHandle key
) 
```




<hr>



### function MapChannelConnections\_from\_json\_string 

```C++
MapChannelConnectionsHandle MapChannelConnections_from_json_string (
    StringHandle json
) 
```




<hr>



### function MapChannelConnections\_insert 

```C++
void MapChannelConnections_insert (
    MapChannelConnectionsHandle handle,
    ChannelHandle key,
    ConnectionsHandle value
) 
```




<hr>



### function MapChannelConnections\_insert\_or\_assign 

```C++
void MapChannelConnections_insert_or_assign (
    MapChannelConnectionsHandle handle,
    ChannelHandle key,
    ConnectionsHandle value
) 
```




<hr>



### function MapChannelConnections\_items 

```C++
ListPairChannelConnectionsHandle MapChannelConnections_items (
    MapChannelConnectionsHandle handle
) 
```




<hr>



### function MapChannelConnections\_keys 

```C++
ListChannelHandle MapChannelConnections_keys (
    MapChannelConnectionsHandle handle
) 
```




<hr>



### function MapChannelConnections\_not\_equal 

```C++
bool MapChannelConnections_not_equal (
    MapChannelConnectionsHandle handle,
    MapChannelConnectionsHandle other
) 
```




<hr>



### function MapChannelConnections\_size 

```C++
size_t MapChannelConnections_size (
    MapChannelConnectionsHandle handle
) 
```




<hr>



### function MapChannelConnections\_to\_json\_string 

```C++
StringHandle MapChannelConnections_to_json_string (
    MapChannelConnectionsHandle handle
) 
```




<hr>



### function MapChannelConnections\_values 

```C++
ListConnectionsHandle MapChannelConnections_values (
    MapChannelConnectionsHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/MapChannelConnections_c_api.h`

