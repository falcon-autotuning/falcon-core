

# File PairConnectionConnections\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairConnectionConnections\_c\_api.h**](PairConnectionConnections__c__api_8h.md)

[Go to the source code of this file](PairConnectionConnections__c__api_8h_source.md)



* `#include "falcon_core/physics/device_structures/Connections_c_api.h"`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PairConnectionConnectionsHandle**](#typedef-pairconnectionconnectionshandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairConnectionConnectionsHandle | [**PairConnectionConnections\_copy**](#function-pairconnectionconnections_copy) (PairConnectionConnectionsHandle handle) <br> |
|  PairConnectionConnectionsHandle | [**PairConnectionConnections\_create**](#function-pairconnectionconnections_create) (ConnectionHandle first, ConnectionsHandle second) <br> |
|  void | [**PairConnectionConnections\_destroy**](#function-pairconnectionconnections_destroy) (PairConnectionConnectionsHandle handle) <br> |
|  bool | [**PairConnectionConnections\_equal**](#function-pairconnectionconnections_equal) (PairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle other) <br> |
|  ConnectionHandle | [**PairConnectionConnections\_first**](#function-pairconnectionconnections_first) (PairConnectionConnectionsHandle handle) <br> |
|  PairConnectionConnectionsHandle | [**PairConnectionConnections\_from\_json\_string**](#function-pairconnectionconnections_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  bool | [**PairConnectionConnections\_not\_equal**](#function-pairconnectionconnections_not_equal) (PairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle other) <br> |
|  ConnectionsHandle | [**PairConnectionConnections\_second**](#function-pairconnectionconnections_second) (PairConnectionConnectionsHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**PairConnectionConnections\_to\_json\_string**](#function-pairconnectionconnections_to_json_string) (PairConnectionConnectionsHandle handle) <br> |




























## Public Types Documentation




### typedef PairConnectionConnectionsHandle 

```C++
typedef void* PairConnectionConnectionsHandle;
```




<hr>
## Public Functions Documentation




### function PairConnectionConnections\_copy 

```C++
PairConnectionConnectionsHandle PairConnectionConnections_copy (
    PairConnectionConnectionsHandle handle
) 
```




<hr>



### function PairConnectionConnections\_create 

```C++
PairConnectionConnectionsHandle PairConnectionConnections_create (
    ConnectionHandle first,
    ConnectionsHandle second
) 
```




<hr>



### function PairConnectionConnections\_destroy 

```C++
void PairConnectionConnections_destroy (
    PairConnectionConnectionsHandle handle
) 
```




<hr>



### function PairConnectionConnections\_equal 

```C++
bool PairConnectionConnections_equal (
    PairConnectionConnectionsHandle handle,
    PairConnectionConnectionsHandle other
) 
```




<hr>



### function PairConnectionConnections\_first 

```C++
ConnectionHandle PairConnectionConnections_first (
    PairConnectionConnectionsHandle handle
) 
```




<hr>



### function PairConnectionConnections\_from\_json\_string 

```C++
PairConnectionConnectionsHandle PairConnectionConnections_from_json_string (
    StringHandle json
) 
```




<hr>



### function PairConnectionConnections\_not\_equal 

```C++
bool PairConnectionConnections_not_equal (
    PairConnectionConnectionsHandle handle,
    PairConnectionConnectionsHandle other
) 
```




<hr>



### function PairConnectionConnections\_second 

```C++
ConnectionsHandle PairConnectionConnections_second (
    PairConnectionConnectionsHandle handle
) 
```




<hr>



### function PairConnectionConnections\_to\_json\_string 

```C++
StringHandle PairConnectionConnections_to_json_string (
    PairConnectionConnectionsHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/PairConnectionConnections_c_api.h`

