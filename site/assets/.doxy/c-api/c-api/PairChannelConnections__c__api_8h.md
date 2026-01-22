

# File PairChannelConnections\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairChannelConnections\_c\_api.h**](PairChannelConnections__c__api_8h.md)

[Go to the source code of this file](PairChannelConnections__c__api_8h_source.md)



* `#include "falcon_core/autotuner_interfaces/names/Channel_c_api.h"`
* `#include "falcon_core/physics/device_structures/Connections_c_api.h"`
* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**PairChannelConnectionsHandle**](#typedef-pairchannelconnectionshandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  PairChannelConnectionsHandle | [**PairChannelConnections\_copy**](#function-pairchannelconnections_copy) (PairChannelConnectionsHandle handle) <br> |
|  PairChannelConnectionsHandle | [**PairChannelConnections\_create**](#function-pairchannelconnections_create) (ChannelHandle first, ConnectionsHandle second) <br> |
|  void | [**PairChannelConnections\_destroy**](#function-pairchannelconnections_destroy) (PairChannelConnectionsHandle handle) <br> |
|  bool | [**PairChannelConnections\_equal**](#function-pairchannelconnections_equal) (PairChannelConnectionsHandle handle, PairChannelConnectionsHandle other) <br> |
|  ChannelHandle | [**PairChannelConnections\_first**](#function-pairchannelconnections_first) (PairChannelConnectionsHandle handle) <br> |
|  PairChannelConnectionsHandle | [**PairChannelConnections\_from\_json\_string**](#function-pairchannelconnections_from_json_string) (StringHandle json) <br> |
|  bool | [**PairChannelConnections\_not\_equal**](#function-pairchannelconnections_not_equal) (PairChannelConnectionsHandle handle, PairChannelConnectionsHandle other) <br> |
|  ConnectionsHandle | [**PairChannelConnections\_second**](#function-pairchannelconnections_second) (PairChannelConnectionsHandle handle) <br> |
|  StringHandle | [**PairChannelConnections\_to\_json\_string**](#function-pairchannelconnections_to_json_string) (PairChannelConnectionsHandle handle) <br> |




























## Public Types Documentation




### typedef PairChannelConnectionsHandle 

```C++
typedef void* PairChannelConnectionsHandle;
```




<hr>
## Public Functions Documentation




### function PairChannelConnections\_copy 

```C++
PairChannelConnectionsHandle PairChannelConnections_copy (
    PairChannelConnectionsHandle handle
) 
```




<hr>



### function PairChannelConnections\_create 

```C++
PairChannelConnectionsHandle PairChannelConnections_create (
    ChannelHandle first,
    ConnectionsHandle second
) 
```




<hr>



### function PairChannelConnections\_destroy 

```C++
void PairChannelConnections_destroy (
    PairChannelConnectionsHandle handle
) 
```




<hr>



### function PairChannelConnections\_equal 

```C++
bool PairChannelConnections_equal (
    PairChannelConnectionsHandle handle,
    PairChannelConnectionsHandle other
) 
```




<hr>



### function PairChannelConnections\_first 

```C++
ChannelHandle PairChannelConnections_first (
    PairChannelConnectionsHandle handle
) 
```




<hr>



### function PairChannelConnections\_from\_json\_string 

```C++
PairChannelConnectionsHandle PairChannelConnections_from_json_string (
    StringHandle json
) 
```




<hr>



### function PairChannelConnections\_not\_equal 

```C++
bool PairChannelConnections_not_equal (
    PairChannelConnectionsHandle handle,
    PairChannelConnectionsHandle other
) 
```




<hr>



### function PairChannelConnections\_second 

```C++
ConnectionsHandle PairChannelConnections_second (
    PairChannelConnectionsHandle handle
) 
```




<hr>



### function PairChannelConnections\_to\_json\_string 

```C++
StringHandle PairChannelConnections_to_json_string (
    PairChannelConnectionsHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/generic/PairChannelConnections_c_api.h`

