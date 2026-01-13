

# File Group\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**config**](dir_581a120aab54b5f137a62afb53b974b4.md) **>** [**core**](dir_2d9342c5d4579911ee06a50b57a946ed.md) **>** [**Group\_c\_api.h**](Group__c__api_8h.md)

[Go to the source code of this file](Group__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/autotuner_interfaces/names/Channel_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/physics/config/geometries/GateGeometryArray1D_c_api.h"`
* `#include "falcon_core/physics/device_structures/Connections_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**GroupHandle**](#typedef-grouphandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ConnectionsHandle | [**Group\_barrier\_gates**](#function-group_barrier_gates) (GroupHandle handle) <br> |
|  GroupHandle | [**Group\_copy**](#function-group_copy) (GroupHandle handle) <br> |
|  GroupHandle | [**Group\_create**](#function-group_create) (ChannelHandle name, int num\_dots, ConnectionsHandle screening\_gates, ConnectionsHandle reservoir\_gates, ConnectionsHandle plunger\_gates, ConnectionsHandle barrier\_gates, ConnectionsHandle order) <br> |
|  void | [**Group\_destroy**](#function-group_destroy) (GroupHandle handle) <br> |
|  ConnectionsHandle | [**Group\_dot\_gates**](#function-group_dot_gates) (GroupHandle handle) <br> |
|  bool | [**Group\_equal**](#function-group_equal) (GroupHandle handle, GroupHandle other) <br> |
|  GroupHandle | [**Group\_from\_json\_string**](#function-group_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  ConnectionsHandle | [**Group\_get\_all\_channel\_gates**](#function-group_get_all_channel_gates) (GroupHandle handle) <br>_Gets all of the gates assocciated with this channel from the config._  |
|  ConnectionsHandle | [**Group\_get\_all\_connections**](#function-group_get_all_connections) (GroupHandle handle) <br> |
|  ConnectionsHandle | [**Group\_get\_all\_gates**](#function-group_get_all_gates) (GroupHandle handle) <br> |
|  ConnectionHandle | [**Group\_get\_barrier\_gate**](#function-group_get_barrier_gate) (GroupHandle handle) <br> |
|  ConnectionHandle | [**Group\_get\_dot\_gate**](#function-group_get_dot_gate) (GroupHandle handle) <br> |
|  ConnectionHandle | [**Group\_get\_gate**](#function-group_get_gate) (GroupHandle handle) <br> |
|  ConnectionHandle | [**Group\_get\_ohmic**](#function-group_get_ohmic) (GroupHandle handle) <br> |
|  ConnectionHandle | [**Group\_get\_plunger\_gate**](#function-group_get_plunger_gate) (GroupHandle handle) <br> |
|  ConnectionHandle | [**Group\_get\_reservoir\_gate**](#function-group_get_reservoir_gate) (GroupHandle handle) <br> |
|  ConnectionHandle | [**Group\_get\_screening\_gate**](#function-group_get_screening_gate) (GroupHandle handle) <br> |
|  bool | [**Group\_has\_barrier\_gate**](#function-group_has_barrier_gate) (GroupHandle handle, ConnectionHandle barrier\_gate) <br> |
|  bool | [**Group\_has\_channel**](#function-group_has_channel) (GroupHandle handle, ChannelHandle channel) <br>_Validates if this channel is present._  |
|  bool | [**Group\_has\_gate**](#function-group_has_gate) (GroupHandle handle, ConnectionHandle gate) <br> |
|  bool | [**Group\_has\_ohmic**](#function-group_has_ohmic) (GroupHandle handle, ConnectionHandle ohmic) <br> |
|  bool | [**Group\_has\_plunger\_gate**](#function-group_has_plunger_gate) (GroupHandle handle, ConnectionHandle plunger\_gate) <br> |
|  bool | [**Group\_has\_reservoir\_gate**](#function-group_has_reservoir_gate) (GroupHandle handle, ConnectionHandle reservoir\_gate) <br> |
|  bool | [**Group\_has\_screening\_gate**](#function-group_has_screening_gate) (GroupHandle handle, ConnectionHandle screening\_gate) <br> |
|  bool | [**Group\_is\_charge\_sensor**](#function-group_is_charge_sensor) (GroupHandle handle) <br>_Checks if this channel could be a charge sensor._  |
|  ChannelHandle | [**Group\_name**](#function-group_name) (GroupHandle handle) <br>_collect the name of this group._  |
|  bool | [**Group\_not\_equal**](#function-group_not_equal) (GroupHandle handle, GroupHandle other) <br> |
|  int | [**Group\_num\_dots**](#function-group_num_dots) (GroupHandle handle) <br>_collect the number of dots in this group._  |
|  ConnectionsHandle | [**Group\_ohmics**](#function-group_ohmics) (GroupHandle handle) <br>_collect the ohmics pertaining to this group._  |
|  GateGeometryArray1DHandle | [**Group\_order**](#function-group_order) (GroupHandle handle) <br>_collect the order of the gates in this group._  |
|  ConnectionsHandle | [**Group\_plunger\_gates**](#function-group_plunger_gates) (GroupHandle handle) <br> |
|  ConnectionsHandle | [**Group\_reservoir\_gates**](#function-group_reservoir_gates) (GroupHandle handle) <br> |
|  ConnectionsHandle | [**Group\_screening\_gates**](#function-group_screening_gates) (GroupHandle handle) <br> |
|  [**StringHandle**](structstring.md) | [**Group\_to\_json\_string**](#function-group_to_json_string) (GroupHandle handle) <br> |




























## Public Types Documentation




### typedef GroupHandle 

```C++
typedef void* GroupHandle;
```




<hr>
## Public Functions Documentation




### function Group\_barrier\_gates 

```C++
ConnectionsHandle Group_barrier_gates (
    GroupHandle handle
) 
```




<hr>



### function Group\_copy 

```C++
GroupHandle Group_copy (
    GroupHandle handle
) 
```




<hr>



### function Group\_create 

```C++
GroupHandle Group_create (
    ChannelHandle name,
    int num_dots,
    ConnectionsHandle screening_gates,
    ConnectionsHandle reservoir_gates,
    ConnectionsHandle plunger_gates,
    ConnectionsHandle barrier_gates,
    ConnectionsHandle order
) 
```




<hr>



### function Group\_destroy 

```C++
void Group_destroy (
    GroupHandle handle
) 
```




<hr>



### function Group\_dot\_gates 

```C++
ConnectionsHandle Group_dot_gates (
    GroupHandle handle
) 
```




<hr>



### function Group\_equal 

```C++
bool Group_equal (
    GroupHandle handle,
    GroupHandle other
) 
```




<hr>



### function Group\_from\_json\_string 

```C++
GroupHandle Group_from_json_string (
    StringHandle json
) 
```




<hr>



### function Group\_get\_all\_channel\_gates 

_Gets all of the gates assocciated with this channel from the config._ 
```C++
ConnectionsHandle Group_get_all_channel_gates (
    GroupHandle handle
) 
```





**Parameters:**


* `channel` The channel to collect the gates for. 



**Returns:**

The gates associated with this channel. If the channel is not correct then empty gates are returned. 





        

<hr>



### function Group\_get\_all\_connections 

```C++
ConnectionsHandle Group_get_all_connections (
    GroupHandle handle
) 
```




<hr>



### function Group\_get\_all\_gates 

```C++
ConnectionsHandle Group_get_all_gates (
    GroupHandle handle
) 
```




<hr>



### function Group\_get\_barrier\_gate 

```C++
ConnectionHandle Group_get_barrier_gate (
    GroupHandle handle
) 
```




<hr>



### function Group\_get\_dot\_gate 

```C++
ConnectionHandle Group_get_dot_gate (
    GroupHandle handle
) 
```




<hr>



### function Group\_get\_gate 

```C++
ConnectionHandle Group_get_gate (
    GroupHandle handle
) 
```




<hr>



### function Group\_get\_ohmic 

```C++
ConnectionHandle Group_get_ohmic (
    GroupHandle handle
) 
```




<hr>



### function Group\_get\_plunger\_gate 

```C++
ConnectionHandle Group_get_plunger_gate (
    GroupHandle handle
) 
```




<hr>



### function Group\_get\_reservoir\_gate 

```C++
ConnectionHandle Group_get_reservoir_gate (
    GroupHandle handle
) 
```




<hr>



### function Group\_get\_screening\_gate 

```C++
ConnectionHandle Group_get_screening_gate (
    GroupHandle handle
) 
```




<hr>



### function Group\_has\_barrier\_gate 

```C++
bool Group_has_barrier_gate (
    GroupHandle handle,
    ConnectionHandle barrier_gate
) 
```




<hr>



### function Group\_has\_channel 

_Validates if this channel is present._ 
```C++
bool Group_has_channel (
    GroupHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel to validate. 



**Returns:**

true if the channel is present. 





        

<hr>



### function Group\_has\_gate 

```C++
bool Group_has_gate (
    GroupHandle handle,
    ConnectionHandle gate
) 
```




<hr>



### function Group\_has\_ohmic 

```C++
bool Group_has_ohmic (
    GroupHandle handle,
    ConnectionHandle ohmic
) 
```




<hr>



### function Group\_has\_plunger\_gate 

```C++
bool Group_has_plunger_gate (
    GroupHandle handle,
    ConnectionHandle plunger_gate
) 
```




<hr>



### function Group\_has\_reservoir\_gate 

```C++
bool Group_has_reservoir_gate (
    GroupHandle handle,
    ConnectionHandle reservoir_gate
) 
```




<hr>



### function Group\_has\_screening\_gate 

```C++
bool Group_has_screening_gate (
    GroupHandle handle,
    ConnectionHandle screening_gate
) 
```




<hr>



### function Group\_is\_charge\_sensor 

_Checks if this channel could be a charge sensor._ 
```C++
bool Group_is_charge_sensor (
    GroupHandle handle
) 
```





**Returns:**

true if the channel has a single dot. 





        

<hr>



### function Group\_name 

_collect the name of this group._ 
```C++
ChannelHandle Group_name (
    GroupHandle handle
) 
```




<hr>



### function Group\_not\_equal 

```C++
bool Group_not_equal (
    GroupHandle handle,
    GroupHandle other
) 
```




<hr>



### function Group\_num\_dots 

_collect the number of dots in this group._ 
```C++
int Group_num_dots (
    GroupHandle handle
) 
```




<hr>



### function Group\_ohmics 

_collect the ohmics pertaining to this group._ 
```C++
ConnectionsHandle Group_ohmics (
    GroupHandle handle
) 
```




<hr>



### function Group\_order 

_collect the order of the gates in this group._ 
```C++
GateGeometryArray1DHandle Group_order (
    GroupHandle handle
) 
```




<hr>



### function Group\_plunger\_gates 

```C++
ConnectionsHandle Group_plunger_gates (
    GroupHandle handle
) 
```




<hr>



### function Group\_reservoir\_gates 

```C++
ConnectionsHandle Group_reservoir_gates (
    GroupHandle handle
) 
```




<hr>



### function Group\_screening\_gates 

```C++
ConnectionsHandle Group_screening_gates (
    GroupHandle handle
) 
```




<hr>



### function Group\_to\_json\_string 

```C++
StringHandle Group_to_json_string (
    GroupHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/physics/config/core/Group_c_api.h`

