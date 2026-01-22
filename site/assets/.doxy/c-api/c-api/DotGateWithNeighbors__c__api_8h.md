

# File DotGateWithNeighbors\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**config**](dir_581a120aab54b5f137a62afb53b974b4.md) **>** [**geometries**](dir_1d88f50ca6512fed7187c162c771cfa6.md) **>** [**DotGateWithNeighbors\_c\_api.h**](DotGateWithNeighbors__c__api_8h.md)

[Go to the source code of this file](DotGateWithNeighbors__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/physics/device_structures/Connection_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**DotGateWithNeighborsHandle**](#typedef-dotgatewithneighborshandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  DotGateWithNeighborsHandle | [**DotGateWithNeighbors\_copy**](#function-dotgatewithneighbors_copy) (DotGateWithNeighborsHandle handle) <br> |
|  DotGateWithNeighborsHandle | [**DotGateWithNeighbors\_create\_barrier\_gate\_with\_neighbors**](#function-dotgatewithneighbors_create_barrier_gate_with_neighbors) (StringHandle name, ConnectionHandle left\_neighbor, ConnectionHandle right\_neighbor) <br> |
|  DotGateWithNeighborsHandle | [**DotGateWithNeighbors\_create\_plunger\_gate\_with\_neighbors**](#function-dotgatewithneighbors_create_plunger_gate_with_neighbors) (StringHandle name, ConnectionHandle left\_neighbor, ConnectionHandle right\_neighbor) <br> |
|  void | [**DotGateWithNeighbors\_destroy**](#function-dotgatewithneighbors_destroy) (DotGateWithNeighborsHandle handle) <br> |
|  bool | [**DotGateWithNeighbors\_equal**](#function-dotgatewithneighbors_equal) (DotGateWithNeighborsHandle handle, DotGateWithNeighborsHandle other) <br> |
|  DotGateWithNeighborsHandle | [**DotGateWithNeighbors\_from\_json\_string**](#function-dotgatewithneighbors_from_json_string) (StringHandle json) <br> |
|  bool | [**DotGateWithNeighbors\_is\_barrier\_gate**](#function-dotgatewithneighbors_is_barrier_gate) (DotGateWithNeighborsHandle handle) <br> |
|  bool | [**DotGateWithNeighbors\_is\_plunger\_gate**](#function-dotgatewithneighbors_is_plunger_gate) (DotGateWithNeighborsHandle handle) <br> |
|  ConnectionHandle | [**DotGateWithNeighbors\_left\_neighbor**](#function-dotgatewithneighbors_left_neighbor) (DotGateWithNeighborsHandle handle) <br> |
|  StringHandle | [**DotGateWithNeighbors\_name**](#function-dotgatewithneighbors_name) (DotGateWithNeighborsHandle handle) <br> |
|  bool | [**DotGateWithNeighbors\_not\_equal**](#function-dotgatewithneighbors_not_equal) (DotGateWithNeighborsHandle handle, DotGateWithNeighborsHandle other) <br> |
|  ConnectionHandle | [**DotGateWithNeighbors\_right\_neighbor**](#function-dotgatewithneighbors_right_neighbor) (DotGateWithNeighborsHandle handle) <br> |
|  StringHandle | [**DotGateWithNeighbors\_to\_json\_string**](#function-dotgatewithneighbors_to_json_string) (DotGateWithNeighborsHandle handle) <br> |
|  StringHandle | [**DotGateWithNeighbors\_type**](#function-dotgatewithneighbors_type) (DotGateWithNeighborsHandle handle) <br> |




























## Public Types Documentation




### typedef DotGateWithNeighborsHandle 

```C++
typedef void* DotGateWithNeighborsHandle;
```




<hr>
## Public Functions Documentation




### function DotGateWithNeighbors\_copy 

```C++
DotGateWithNeighborsHandle DotGateWithNeighbors_copy (
    DotGateWithNeighborsHandle handle
) 
```




<hr>



### function DotGateWithNeighbors\_create\_barrier\_gate\_with\_neighbors 

```C++
DotGateWithNeighborsHandle DotGateWithNeighbors_create_barrier_gate_with_neighbors (
    StringHandle name,
    ConnectionHandle left_neighbor,
    ConnectionHandle right_neighbor
) 
```




<hr>



### function DotGateWithNeighbors\_create\_plunger\_gate\_with\_neighbors 

```C++
DotGateWithNeighborsHandle DotGateWithNeighbors_create_plunger_gate_with_neighbors (
    StringHandle name,
    ConnectionHandle left_neighbor,
    ConnectionHandle right_neighbor
) 
```




<hr>



### function DotGateWithNeighbors\_destroy 

```C++
void DotGateWithNeighbors_destroy (
    DotGateWithNeighborsHandle handle
) 
```




<hr>



### function DotGateWithNeighbors\_equal 

```C++
bool DotGateWithNeighbors_equal (
    DotGateWithNeighborsHandle handle,
    DotGateWithNeighborsHandle other
) 
```




<hr>



### function DotGateWithNeighbors\_from\_json\_string 

```C++
DotGateWithNeighborsHandle DotGateWithNeighbors_from_json_string (
    StringHandle json
) 
```




<hr>



### function DotGateWithNeighbors\_is\_barrier\_gate 

```C++
bool DotGateWithNeighbors_is_barrier_gate (
    DotGateWithNeighborsHandle handle
) 
```




<hr>



### function DotGateWithNeighbors\_is\_plunger\_gate 

```C++
bool DotGateWithNeighbors_is_plunger_gate (
    DotGateWithNeighborsHandle handle
) 
```




<hr>



### function DotGateWithNeighbors\_left\_neighbor 

```C++
ConnectionHandle DotGateWithNeighbors_left_neighbor (
    DotGateWithNeighborsHandle handle
) 
```




<hr>



### function DotGateWithNeighbors\_name 

```C++
StringHandle DotGateWithNeighbors_name (
    DotGateWithNeighborsHandle handle
) 
```




<hr>



### function DotGateWithNeighbors\_not\_equal 

```C++
bool DotGateWithNeighbors_not_equal (
    DotGateWithNeighborsHandle handle,
    DotGateWithNeighborsHandle other
) 
```




<hr>



### function DotGateWithNeighbors\_right\_neighbor 

```C++
ConnectionHandle DotGateWithNeighbors_right_neighbor (
    DotGateWithNeighborsHandle handle
) 
```




<hr>



### function DotGateWithNeighbors\_to\_json\_string 

```C++
StringHandle DotGateWithNeighbors_to_json_string (
    DotGateWithNeighborsHandle handle
) 
```




<hr>



### function DotGateWithNeighbors\_type 

```C++
StringHandle DotGateWithNeighbors_type (
    DotGateWithNeighborsHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/physics/config/geometries/DotGateWithNeighbors_c_api.h`

