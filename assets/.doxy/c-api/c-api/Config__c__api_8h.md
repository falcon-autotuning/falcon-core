

# File Config\_c\_api.h



[**FileList**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**config**](dir_581a120aab54b5f137a62afb53b974b4.md) **>** [**core**](dir_2d9342c5d4579911ee06a50b57a946ed.md) **>** [**Config\_c\_api.h**](Config__c__api_8h.md)

[Go to the source code of this file](Config__c__api_8h_source.md)



* `#include <stdbool.h>`
* `#include "falcon_core/autotuner_interfaces/names/Channel_c_api.h"`
* `#include "falcon_core/autotuner_interfaces/names/Channels_c_api.h"`
* `#include "falcon_core/autotuner_interfaces/names/Gname_c_api.h"`
* `#include "falcon_core/generic/ListGname_c_api.h"`
* `#include "falcon_core/generic/ListGroup_c_api.h"`
* `#include "falcon_core/generic/MapChannelConnections_c_api.h"`
* `#include "falcon_core/generic/MapGnameGroup_c_api.h"`
* `#include "falcon_core/generic/PairConnectionConnection_c_api.h"`
* `#include "falcon_core/generic/String_c_api.h"`
* `#include "falcon_core/physics/config/core/Group_c_api.h"`
* `#include "falcon_core/physics/config/core/VoltageConstraints_c_api.h"`
* `#include "falcon_core/physics/device_structures/Connections_c_api.h"`
* `#include "falcon_core/physics/device_structures/GateRelations_c_api.h"`
* `#include "falcon_core/physics/device_structures/Impedances_c_api.h"`

















## Public Types

| Type | Name |
| ---: | :--- |
| typedef void \* | [**ConfigHandle**](#typedef-confighandle)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  ConnectionsHandle | [**Config\_barrier\_gates**](#function-config_barrier_gates) (ConfigHandle handle) <br> |
|  ChannelsHandle | [**Config\_channels**](#function-config_channels) (ConfigHandle handle) <br>_Returns the channels of the config._  |
|  ConfigHandle | [**Config\_copy**](#function-config_copy) (ConfigHandle handle) <br> |
|  ConfigHandle | [**Config\_create**](#function-config_create) (ConnectionsHandle screening\_gates, ConnectionsHandle plunger\_gates, ConnectionsHandle ohmics, ConnectionsHandle barrier\_gates, ConnectionsHandle reservoir\_gates, MapGnameGroupHandle groups, ImpedancesHandle wiring\_DC, VoltageConstraintsHandle constraints) <br> |
|  void | [**Config\_destroy**](#function-config_destroy) (ConfigHandle handle) <br> |
|  ConnectionsHandle | [**Config\_dot\_gates**](#function-config_dot_gates) (ConfigHandle handle) <br> |
|  bool | [**Config\_equal**](#function-config_equal) (ConfigHandle handle, ConfigHandle other) <br> |
|  ConfigHandle | [**Config\_from\_json\_string**](#function-config_from_json_string) ([**StringHandle**](structstring.md) json) <br> |
|  GateRelationsHandle | [**Config\_generate\_gate\_relations**](#function-config_generate_gate_relations) (ConfigHandle handle) <br>_Returns the gate relations in the config._  |
|  ConnectionsHandle | [**Config\_get\_all\_connections**](#function-config_get_all_connections) (ConfigHandle handle) <br> |
|  ConnectionsHandle | [**Config\_get\_all\_gates**](#function-config_get_all_gates) (ConfigHandle handle) <br> |
|  ListGnameHandle | [**Config\_get\_all\_gnames**](#function-config_get_all_gnames) (ConfigHandle handle) <br>_Returns all of the group names._  |
|  ListGroupHandle | [**Config\_get\_all\_groups**](#function-config_get_all_groups) (ConfigHandle handle) <br>_Returns all of the groups._  |
|  ConnectionHandle | [**Config\_get\_associated\_ohmic**](#function-config_get_associated_ohmic) (ConfigHandle handle, ConnectionHandle reservoir\_gate) <br>_Every reservoir gate has an associated ohmic. This pulls the associated ohmic from the config._  |
|  ConnectionHandle | [**Config\_get\_barrier\_gate**](#function-config_get_barrier_gate) (ConfigHandle handle) <br> |
|  MapChannelConnectionsHandle | [**Config\_get\_barrier\_gate\_dict**](#function-config_get_barrier_gate_dict) (ConfigHandle handle) <br>_Returns barrier gates indexed by channel._  |
|  ConnectionsHandle | [**Config\_get\_channel\_barrier\_gates**](#function-config_get_channel_barrier_gates) (ConfigHandle handle, ChannelHandle channel) <br>_Gets all of the barrier gates assocated with the selected current channel from the config._  |
|  ConnectionsHandle | [**Config\_get\_channel\_dot\_gates**](#function-config_get_channel_dot_gates) (ConfigHandle handle, ChannelHandle channel) <br>_Gets all of the dot gates assocated with the selected current channel from the config._  |
|  ConnectionsHandle | [**Config\_get\_channel\_gates**](#function-config_get_channel_gates) (ConfigHandle handle, ChannelHandle channel) <br>_Gets all of the gates assocated with the selected current channel from the config._  |
|  ConnectionsHandle | [**Config\_get\_channel\_ohmics**](#function-config_get_channel_ohmics) (ConfigHandle handle, ChannelHandle channel) <br>_Gets all of the ohmics assocated with the selected current channel._  |
|  ConnectionsHandle | [**Config\_get\_channel\_order\_no\_ohmics**](#function-config_get_channel_order_no_ohmics) (ConfigHandle handle, ChannelHandle channel) <br>_Gets all of the gates in the order at the selected channel from the config with no ohmics._  |
|  ConnectionsHandle | [**Config\_get\_channel\_plunger\_gates**](#function-config_get_channel_plunger_gates) (ConfigHandle handle, ChannelHandle channel) <br>_Gets all of the plunger gates assocated with the selected current channel from the config._  |
|  ConnectionsHandle | [**Config\_get\_channel\_reservoir\_gates**](#function-config_get_channel_reservoir_gates) (ConfigHandle handle, ChannelHandle channel) <br>_Gets all of the reservoir gates assocated with the selected current channel from the config._  |
|  ConnectionsHandle | [**Config\_get\_channel\_screening\_gates**](#function-config_get_channel_screening_gates) (ConfigHandle handle, ChannelHandle channel) <br>_Gets all of the screening gates assocated with the selected current channel from the config._  |
|  ListGnameHandle | [**Config\_get\_charge\_sense\_groups**](#function-config_get_charge_sense_groups) (ConfigHandle handle) <br>_Finds all of the arrays of dots that are charge sensors, i.e. only one quantum dot per channel._  |
|  ChannelsHandle | [**Config\_get\_current\_channels**](#function-config_get_current_channels) (ConfigHandle handle) <br>_Gets all of the current channels from the config._  |
|  PairConnectionConnectionHandle | [**Config\_get\_dot\_channel\_neighbors**](#function-config_get_dot_channel_neighbors) (ConfigHandle handle, ConnectionHandle dot\_gate) <br>_Gets the nearby neighbors of the selected gate in the dot channel._  |
|  ConnectionHandle | [**Config\_get\_dot\_gate**](#function-config_get_dot_gate) (ConfigHandle handle) <br> |
|  MapChannelConnectionsHandle | [**Config\_get\_dot\_gate\_dict**](#function-config_get_dot_gate_dict) (ConfigHandle handle) <br>_Returns dot gates indexed by channel._  |
|  int | [**Config\_get\_dot\_number**](#function-config_get_dot_number) (ConfigHandle handle, ChannelHandle channel) <br>_Finds the number of dots associated with a current channel from the config._  |
|  ConnectionHandle | [**Config\_get\_gate**](#function-config_get_gate) (ConfigHandle handle) <br> |
|  MapChannelConnectionsHandle | [**Config\_get\_gate\_dict**](#function-config_get_gate_dict) (ConfigHandle handle) <br>_Returns gates indexed by channel._  |
|  GnameHandle | [**Config\_get\_gname**](#function-config_get_gname) (ConfigHandle handle, ChannelHandle channel) <br>_Gets the associated Gname with a Channel if it exists._  |
|  ConnectionsHandle | [**Config\_get\_group\_barrier\_gates**](#function-config_get_group_barrier_gates) (ConfigHandle handle, GnameHandle gname) <br>_Gets all of the barrier gates assocated with the selected group from the config._  |
|  ConnectionsHandle | [**Config\_get\_group\_dot\_gates**](#function-config_get_group_dot_gates) (ConfigHandle handle, GnameHandle gname) <br>_Gets all of the dot gates assocated with the selected group from the config._  |
|  ConnectionsHandle | [**Config\_get\_group\_gates**](#function-config_get_group_gates) (ConfigHandle handle, GnameHandle gname) <br>_Gets all of the gates assocated with the selected group from the config._  |
|  ConnectionsHandle | [**Config\_get\_group\_plunger\_gates**](#function-config_get_group_plunger_gates) (ConfigHandle handle, GnameHandle gname) <br>_Gets all of the plunger gates assocated with the selected group from the config._  |
|  ConnectionsHandle | [**Config\_get\_group\_reservoir\_gates**](#function-config_get_group_reservoir_gates) (ConfigHandle handle, GnameHandle gname) <br>_Gets all of the reservoir gates assocated with the selected group from the config._  |
|  ConnectionsHandle | [**Config\_get\_group\_screening\_gates**](#function-config_get_group_screening_gates) (ConfigHandle handle, GnameHandle gname) <br>_Gets all of the screening gates assocated with the selected group from the config._  |
|  ImpedanceHandle | [**Config\_get\_impedance**](#function-config_get_impedance) (ConfigHandle handle, ConnectionHandle connection) <br>_Returns the impedance matching the connection in teh dcwiring._  |
|  ConnectionsHandle | [**Config\_get\_isolated\_barrier\_gates**](#function-config_get_isolated_barrier_gates) (ConfigHandle handle) <br>_Task to find isolated barrier gates stored in the config._  |
|  MapChannelConnectionsHandle | [**Config\_get\_isolated\_barrier\_gates\_by\_channel**](#function-config_get_isolated_barrier_gates_by_channel) (ConfigHandle handle) <br>_Returns barrier gates indexed by channel which are unshared._  |
|  ConnectionsHandle | [**Config\_get\_isolated\_channel\_barrier\_gates**](#function-config_get_isolated_channel_barrier_gates) (ConfigHandle handle, ChannelHandle channel) <br>_Finds the isolated barrier gates in the selected channel._  |
|  ConnectionsHandle | [**Config\_get\_isolated\_channel\_dot\_gates**](#function-config_get_isolated_channel_dot_gates) (ConfigHandle handle, ChannelHandle channel) <br>_Finds the isolated dot gates in the selected channel._  |
|  ConnectionsHandle | [**Config\_get\_isolated\_channel\_gates**](#function-config_get_isolated_channel_gates) (ConfigHandle handle, ChannelHandle channel) <br>_Finds the isolated gates in the selected channel._  |
|  ConnectionsHandle | [**Config\_get\_isolated\_channel\_plunger\_gates**](#function-config_get_isolated_channel_plunger_gates) (ConfigHandle handle, ChannelHandle channel) <br>_Finds the isolated plunger gates in the selected channel._  |
|  ConnectionsHandle | [**Config\_get\_isolated\_channel\_reservoir\_gates**](#function-config_get_isolated_channel_reservoir_gates) (ConfigHandle handle, ChannelHandle channel) <br>_Finds the isolated reservoir gates in the selected channel._  |
|  ConnectionsHandle | [**Config\_get\_isolated\_channel\_screening\_gates**](#function-config_get_isolated_channel_screening_gates) (ConfigHandle handle, ChannelHandle channel) <br>_Finds the isolated screening gates in the selected channel._  |
|  ConnectionsHandle | [**Config\_get\_isolated\_dot\_gates**](#function-config_get_isolated_dot_gates) (ConfigHandle handle) <br>_Task to find isolated dot gates stored in the config._  |
|  MapChannelConnectionsHandle | [**Config\_get\_isolated\_dot\_gates\_by\_channel**](#function-config_get_isolated_dot_gates_by_channel) (ConfigHandle handle) <br>_Returns dot gates indexed by channel which are unshared._  |
|  ConnectionsHandle | [**Config\_get\_isolated\_gates**](#function-config_get_isolated_gates) (ConfigHandle handle) <br>_Task to find isolated gates stored in the config._  |
|  MapChannelConnectionsHandle | [**Config\_get\_isolated\_gates\_by\_channel**](#function-config_get_isolated_gates_by_channel) (ConfigHandle handle) <br>_Returns gates indexed by channel which are unshared._  |
|  ConnectionsHandle | [**Config\_get\_isolated\_plunger\_gates**](#function-config_get_isolated_plunger_gates) (ConfigHandle handle) <br>_Task to find isolated plunger gates stored in the config._  |
|  MapChannelConnectionsHandle | [**Config\_get\_isolated\_plunger\_gates\_by\_channel**](#function-config_get_isolated_plunger_gates_by_channel) (ConfigHandle handle) <br>_Returns plunger gates indexed by channel which are unshared._  |
|  ConnectionsHandle | [**Config\_get\_isolated\_reservoir\_gates**](#function-config_get_isolated_reservoir_gates) (ConfigHandle handle) <br>_Task to find isolated reservoir gates stored in the config._  |
|  MapChannelConnectionsHandle | [**Config\_get\_isolated\_reservoir\_gates\_by\_channel**](#function-config_get_isolated_reservoir_gates_by_channel) (ConfigHandle handle) <br>_Returns reservoir gates indexed by channel which are unshared._  |
|  ConnectionsHandle | [**Config\_get\_isolated\_screening\_gates**](#function-config_get_isolated_screening_gates) (ConfigHandle handle) <br>_Task to find isolated screening gates stored in the config._  |
|  MapChannelConnectionsHandle | [**Config\_get\_isolated\_screening\_gates\_by\_channel**](#function-config_get_isolated_screening_gates_by_channel) (ConfigHandle handle) <br>_Returns screening gates indexed by channel which are unshared._  |
|  int | [**Config\_get\_num\_unique\_channels**](#function-config_get_num_unique_channels) (ConfigHandle handle) <br>_Returns the number of unique channels associated with the current sample._  |
|  ConnectionHandle | [**Config\_get\_ohmic**](#function-config_get_ohmic) (ConfigHandle handle) <br> |
|  ConnectionHandle | [**Config\_get\_plunger\_gate**](#function-config_get_plunger_gate) (ConfigHandle handle) <br> |
|  MapChannelConnectionsHandle | [**Config\_get\_plunger\_gate\_dict**](#function-config_get_plunger_gate_dict) (ConfigHandle handle) <br>_Returns plunger gates indexed by channel._  |
|  ConnectionHandle | [**Config\_get\_reservoir\_gate**](#function-config_get_reservoir_gate) (ConfigHandle handle) <br> |
|  MapChannelConnectionsHandle | [**Config\_get\_reservoir\_gate\_dict**](#function-config_get_reservoir_gate_dict) (ConfigHandle handle) <br>_Returns reservoir gates indexed by channel._  |
|  ConnectionHandle | [**Config\_get\_screening\_gate**](#function-config_get_screening_gate) (ConfigHandle handle) <br> |
|  MapChannelConnectionsHandle | [**Config\_get\_screening\_gate\_dict**](#function-config_get_screening_gate_dict) (ConfigHandle handle) <br>_Returns screening gates indexed by channel._  |
|  ConnectionsHandle | [**Config\_get\_shared\_barrier\_gates**](#function-config_get_shared_barrier_gates) (ConfigHandle handle) <br>_Task to find shared barrier gates stored in the config._  |
|  ConnectionsHandle | [**Config\_get\_shared\_channel\_barrier\_gates**](#function-config_get_shared_channel_barrier_gates) (ConfigHandle handle, ChannelHandle channel) <br>_Finds the shared barrier gates in the selected channel._  |
|  ConnectionsHandle | [**Config\_get\_shared\_channel\_dot\_gates**](#function-config_get_shared_channel_dot_gates) (ConfigHandle handle, ChannelHandle channel) <br>_Finds the shared dot gates of the gatetype in the selected channel._  |
|  ConnectionsHandle | [**Config\_get\_shared\_channel\_gates**](#function-config_get_shared_channel_gates) (ConfigHandle handle, ChannelHandle channel) <br>_Finds the shared gates in the selected channel._  |
|  ConnectionsHandle | [**Config\_get\_shared\_channel\_plunger\_gates**](#function-config_get_shared_channel_plunger_gates) (ConfigHandle handle, ChannelHandle channel) <br>_Finds the shared plunger gates in the selected channel._  |
|  ConnectionsHandle | [**Config\_get\_shared\_channel\_reservoir\_gates**](#function-config_get_shared_channel_reservoir_gates) (ConfigHandle handle, ChannelHandle channel) <br>_Finds the shared reservoir gates in the selected channel._  |
|  ConnectionsHandle | [**Config\_get\_shared\_channel\_screening\_gates**](#function-config_get_shared_channel_screening_gates) (ConfigHandle handle, ChannelHandle channel) <br>_Finds the shared screening gates in the selected channel._  |
|  ConnectionsHandle | [**Config\_get\_shared\_dot\_gates**](#function-config_get_shared_dot_gates) (ConfigHandle handle) <br>_Task to find shared dot gates stored in the config._  |
|  ConnectionsHandle | [**Config\_get\_shared\_gates**](#function-config_get_shared_gates) (ConfigHandle handle) <br>_Task to find shared gates stored in the config._  |
|  ConnectionsHandle | [**Config\_get\_shared\_plunger\_gates**](#function-config_get_shared_plunger_gates) (ConfigHandle handle) <br>_Task to find shared plunger gates stored in the config._  |
|  ConnectionsHandle | [**Config\_get\_shared\_reservoir\_gates**](#function-config_get_shared_reservoir_gates) (ConfigHandle handle) <br>_Task to find shared reservoir gates stored in the config._  |
|  ConnectionsHandle | [**Config\_get\_shared\_screening\_gates**](#function-config_get_shared_screening_gates) (ConfigHandle handle) <br>_Task to find shared screening gates stored in the config._  |
|  MapGnameGroupHandle | [**Config\_groups**](#function-config_groups) (ConfigHandle handle) <br>_Return the DC wiring impedances for the physical layout._  |
|  bool | [**Config\_has\_barrier\_gate**](#function-config_has_barrier_gate) (ConfigHandle handle, ConnectionHandle barrier\_gate) <br> |
|  bool | [**Config\_has\_channel**](#function-config_has_channel) (ConfigHandle handle, ChannelHandle channel) <br>_Validates if this is a proper Channel name in the set of all device Channels._  |
|  bool | [**Config\_has\_gate**](#function-config_has_gate) (ConfigHandle handle, ConnectionHandle gate) <br> |
|  bool | [**Config\_has\_gname**](#function-config_has_gname) (ConfigHandle handle, GnameHandle gname) <br>_Validates if this is a proper gatename._  |
|  bool | [**Config\_has\_ohmic**](#function-config_has_ohmic) (ConfigHandle handle, ConnectionHandle ohmic) <br> |
|  bool | [**Config\_has\_plunger\_gate**](#function-config_has_plunger_gate) (ConfigHandle handle, ConnectionHandle plunger\_gate) <br> |
|  bool | [**Config\_has\_reservoir\_gate**](#function-config_has_reservoir_gate) (ConfigHandle handle, ConnectionHandle reservoir\_gate) <br> |
|  bool | [**Config\_has\_screening\_gate**](#function-config_has_screening_gate) (ConfigHandle handle, ConnectionHandle screening\_gate) <br> |
|  bool | [**Config\_not\_equal**](#function-config_not_equal) (ConfigHandle handle, ConfigHandle other) <br> |
|  int | [**Config\_num\_unique\_channels**](#function-config_num_unique_channels) (ConfigHandle handle) <br>_Returns the number of unique channels associated with the current sample._  |
|  bool | [**Config\_ohmic\_in\_channel**](#function-config_ohmic_in_channel) (ConfigHandle handle, ConnectionHandle ohmic, ChannelHandle channel) <br>_Checks if the ohmic is connected to a channel._  |
|  bool | [**Config\_ohmic\_in\_charge\_sensor**](#function-config_ohmic_in_charge_sensor) (ConfigHandle handle, ConnectionHandle ohmic) <br>_If the ohmic is inside of a charge sensor channel._  |
|  ConnectionsHandle | [**Config\_ohmics**](#function-config_ohmics) (ConfigHandle handle) <br> |
|  ConnectionsHandle | [**Config\_plunger\_gates**](#function-config_plunger_gates) (ConfigHandle handle) <br> |
|  ConnectionsHandle | [**Config\_reservoir\_gates**](#function-config_reservoir_gates) (ConfigHandle handle) <br> |
|  ChannelHandle | [**Config\_return\_channel\_from\_gate**](#function-config_return_channel_from_gate) (ConfigHandle handle, ConnectionHandle gate) <br>_Returns the channel a given gate belongs to. If the gate is in multiple channels, if will return the first channel if finds._  |
|  ChannelsHandle | [**Config\_return\_channels\_from\_gate**](#function-config_return_channels_from_gate) (ConfigHandle handle, ConnectionHandle gate) <br>_Returns all of the channels associated with a gate._  |
|  ConnectionsHandle | [**Config\_screening\_gates**](#function-config_screening_gates) (ConfigHandle handle) <br> |
|  GroupHandle | [**Config\_select\_group**](#function-config_select_group) (ConfigHandle handle, GnameHandle gname) <br>_Finds a group from the name and returns it._  |
|  [**StringHandle**](structstring.md) | [**Config\_to\_json\_string**](#function-config_to_json_string) (ConfigHandle handle) <br> |
|  VoltageConstraintsHandle | [**Config\_voltage\_constraints**](#function-config_voltage_constraints) (ConfigHandle handle) <br>_Return the voltage constraints for the physical layout._  |
|  ImpedancesHandle | [**Config\_wiring\_DC**](#function-config_wiring_dc) (ConfigHandle handle) <br> |




























## Public Types Documentation




### typedef ConfigHandle 

```C++
typedef void* ConfigHandle;
```




<hr>
## Public Functions Documentation




### function Config\_barrier\_gates 

```C++
ConnectionsHandle Config_barrier_gates (
    ConfigHandle handle
) 
```




<hr>



### function Config\_channels 

_Returns the channels of the config._ 
```C++
ChannelsHandle Config_channels (
    ConfigHandle handle
) 
```




<hr>



### function Config\_copy 

```C++
ConfigHandle Config_copy (
    ConfigHandle handle
) 
```




<hr>



### function Config\_create 

```C++
ConfigHandle Config_create (
    ConnectionsHandle screening_gates,
    ConnectionsHandle plunger_gates,
    ConnectionsHandle ohmics,
    ConnectionsHandle barrier_gates,
    ConnectionsHandle reservoir_gates,
    MapGnameGroupHandle groups,
    ImpedancesHandle wiring_DC,
    VoltageConstraintsHandle constraints
) 
```




<hr>



### function Config\_destroy 

```C++
void Config_destroy (
    ConfigHandle handle
) 
```




<hr>



### function Config\_dot\_gates 

```C++
ConnectionsHandle Config_dot_gates (
    ConfigHandle handle
) 
```




<hr>



### function Config\_equal 

```C++
bool Config_equal (
    ConfigHandle handle,
    ConfigHandle other
) 
```




<hr>



### function Config\_from\_json\_string 

```C++
ConfigHandle Config_from_json_string (
    StringHandle json
) 
```




<hr>



### function Config\_generate\_gate\_relations 

_Returns the gate relations in the config._ 
```C++
GateRelationsHandle Config_generate_gate_relations (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_all\_connections 

```C++
ConnectionsHandle Config_get_all_connections (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_all\_gates 

```C++
ConnectionsHandle Config_get_all_gates (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_all\_gnames 

_Returns all of the group names._ 
```C++
ListGnameHandle Config_get_all_gnames (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_all\_groups 

_Returns all of the groups._ 
```C++
ListGroupHandle Config_get_all_groups (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_associated\_ohmic 

_Every reservoir gate has an associated ohmic. This pulls the associated ohmic from the config._ 
```C++
ConnectionHandle Config_get_associated_ohmic (
    ConfigHandle handle,
    ConnectionHandle reservoir_gate
) 
```





**Parameters:**


* `reservoir_gate` The reservoir gate to find the associated ohmic for. 



**Returns:**

The ohmic associated with the reservoir gate. A nullptr if no match 





        

<hr>



### function Config\_get\_barrier\_gate 

```C++
ConnectionHandle Config_get_barrier_gate (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_barrier\_gate\_dict 

_Returns barrier gates indexed by channel._ 
```C++
MapChannelConnectionsHandle Config_get_barrier_gate_dict (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_channel\_barrier\_gates 

_Gets all of the barrier gates assocated with the selected current channel from the config._ 
```C++
ConnectionsHandle Config_get_channel_barrier_gates (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel to find the gates for. 



**Returns:**

All of the gates of a gatetype assocated with the selected channel. Otherwise a nullptr if no match is found. 





        

<hr>



### function Config\_get\_channel\_dot\_gates 

_Gets all of the dot gates assocated with the selected current channel from the config._ 
```C++
ConnectionsHandle Config_get_channel_dot_gates (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel to find the gates for. 



**Returns:**

All of the gates of a gatetype assocated with the selected channel. Otherwise a nullptr if no match is found. 





        

<hr>



### function Config\_get\_channel\_gates 

_Gets all of the gates assocated with the selected current channel from the config._ 
```C++
ConnectionsHandle Config_get_channel_gates (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel to find the gates for. 
* `type` The gate type to find the gates for. 



**Returns:**

All of the gates of a gatetype assocated with the selected channel. Otherwise a nullptr if no match is found. 





        

<hr>



### function Config\_get\_channel\_ohmics 

_Gets all of the ohmics assocated with the selected current channel._ 
```C++
ConnectionsHandle Config_get_channel_ohmics (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel to find the ohmics for. 



**Returns:**

All of the ohmics assocated with the selected channel. Otherwise a nullptr if no match is found. 





        

<hr>



### function Config\_get\_channel\_order\_no\_ohmics 

_Gets all of the gates in the order at the selected channel from the config with no ohmics._ 
```C++
ConnectionsHandle Config_get_channel_order_no_ohmics (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel to find the gates for. 



**Returns:**

All of the gates in the order at the selected channel. Otherwise a nullptr 





        

<hr>



### function Config\_get\_channel\_plunger\_gates 

_Gets all of the plunger gates assocated with the selected current channel from the config._ 
```C++
ConnectionsHandle Config_get_channel_plunger_gates (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel to find the gates for. 



**Returns:**

All of the gates of a gatetype assocated with the selected channel. Otherwise a nullptr if no match is found. 





        

<hr>



### function Config\_get\_channel\_reservoir\_gates 

_Gets all of the reservoir gates assocated with the selected current channel from the config._ 
```C++
ConnectionsHandle Config_get_channel_reservoir_gates (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel to find the gates for. channel. Otherwise a nullptr if no match is found. 




        

<hr>



### function Config\_get\_channel\_screening\_gates 

_Gets all of the screening gates assocated with the selected current channel from the config._ 
```C++
ConnectionsHandle Config_get_channel_screening_gates (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel to find the gates for. 



**Returns:**

All of the gates of a gatetype assocated with the selected channel. Otherwise a nullptr if no match is found. 





        

<hr>



### function Config\_get\_charge\_sense\_groups 

_Finds all of the arrays of dots that are charge sensors, i.e. only one quantum dot per channel._ 
```C++
ListGnameHandle Config_get_charge_sense_groups (
    ConfigHandle handle
) 
```





**Returns:**

A vector of gnames that are charge sensors. 





        

<hr>



### function Config\_get\_current\_channels 

_Gets all of the current channels from the config._ 
```C++
ChannelsHandle Config_get_current_channels (
    ConfigHandle handle
) 
```





**Returns:**

All of the current channels from the config. 





        

<hr>



### function Config\_get\_dot\_channel\_neighbors 

_Gets the nearby neighbors of the selected gate in the dot channel._ 
```C++
PairConnectionConnectionHandle Config_get_dot_channel_neighbors (
    ConfigHandle handle,
    ConnectionHandle dot_gate
) 
```





**Parameters:**


* `dotgate` The gate of interest (must be in dot channel) 



**Returns:**

A pair of GateSP (left, right) if found, nullptr otherwise. 





        

<hr>



### function Config\_get\_dot\_gate 

```C++
ConnectionHandle Config_get_dot_gate (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_dot\_gate\_dict 

_Returns dot gates indexed by channel._ 
```C++
MapChannelConnectionsHandle Config_get_dot_gate_dict (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_dot\_number 

_Finds the number of dots associated with a current channel from the config._ 
```C++
int Config_get_dot_number (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel to find the number of dots for. 



**Returns:**

The number of dots associated with the channel. A 0 if there is no match. 





        

<hr>



### function Config\_get\_gate 

```C++
ConnectionHandle Config_get_gate (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_gate\_dict 

_Returns gates indexed by channel._ 
```C++
MapChannelConnectionsHandle Config_get_gate_dict (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_gname 

_Gets the associated Gname with a Channel if it exists._ 
```C++
GnameHandle Config_get_gname (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel to find the associated Gname for. 



**Returns:**

The Gname associated with the Channel. A nullptr if no match is found. 





        

<hr>



### function Config\_get\_group\_barrier\_gates 

_Gets all of the barrier gates assocated with the selected group from the config._ 
```C++
ConnectionsHandle Config_get_group_barrier_gates (
    ConfigHandle handle,
    GnameHandle gname
) 
```





**Parameters:**


* `gname` The group name to find the gates for. 



**Returns:**

All of the gates of a gatetype assocated with the selected group. Otherwise a nullptr if no match is found. 





        

<hr>



### function Config\_get\_group\_dot\_gates 

_Gets all of the dot gates assocated with the selected group from the config._ 
```C++
ConnectionsHandle Config_get_group_dot_gates (
    ConfigHandle handle,
    GnameHandle gname
) 
```





**Parameters:**


* `gname` The group name to find the gates for. 



**Returns:**

All of the gates of a gatetype assocated with the selected group. Otherwise a nullptr if no match is found. 





        

<hr>



### function Config\_get\_group\_gates 

_Gets all of the gates assocated with the selected group from the config._ 
```C++
ConnectionsHandle Config_get_group_gates (
    ConfigHandle handle,
    GnameHandle gname
) 
```





**Parameters:**


* `gname` The group name to find the gates for. 



**Returns:**

All of the gates of a gatetype assocated with the selected group. Otherwise a nullptr if no match is found. 





        

<hr>



### function Config\_get\_group\_plunger\_gates 

_Gets all of the plunger gates assocated with the selected group from the config._ 
```C++
ConnectionsHandle Config_get_group_plunger_gates (
    ConfigHandle handle,
    GnameHandle gname
) 
```





**Parameters:**


* `gname` The group name to find the gates for. 



**Returns:**

All of the gates of a gatetype assocated with the selected group. Otherwise a nullptr if no match is found. 





        

<hr>



### function Config\_get\_group\_reservoir\_gates 

_Gets all of the reservoir gates assocated with the selected group from the config._ 
```C++
ConnectionsHandle Config_get_group_reservoir_gates (
    ConfigHandle handle,
    GnameHandle gname
) 
```





**Parameters:**


* `gname` The group name to find the gates for. 



**Returns:**

All of the gates of a gatetype assocated with the selected group. Otherwise a nullptr if no match is found. 





        

<hr>



### function Config\_get\_group\_screening\_gates 

_Gets all of the screening gates assocated with the selected group from the config._ 
```C++
ConnectionsHandle Config_get_group_screening_gates (
    ConfigHandle handle,
    GnameHandle gname
) 
```





**Parameters:**


* `gname` The group name to find the gates for. 



**Returns:**

All of the gates of a gatetype assocated with the selected group. Otherwise a nullptr if no match is found. 





        

<hr>



### function Config\_get\_impedance 

_Returns the impedance matching the connection in teh dcwiring._ 
```C++
ImpedanceHandle Config_get_impedance (
    ConfigHandle handle,
    ConnectionHandle connection
) 
```





**Returns:**

The impedance matching the connection in teh dcwiring. A nullptr if no match is found. 





        

<hr>



### function Config\_get\_isolated\_barrier\_gates 

_Task to find isolated barrier gates stored in the config._ 
```C++
ConnectionsHandle Config_get_isolated_barrier_gates (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_isolated\_barrier\_gates\_by\_channel 

_Returns barrier gates indexed by channel which are unshared._ 
```C++
MapChannelConnectionsHandle Config_get_isolated_barrier_gates_by_channel (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_isolated\_channel\_barrier\_gates 

_Finds the isolated barrier gates in the selected channel._ 
```C++
ConnectionsHandle Config_get_isolated_channel_barrier_gates (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

ConnectionsSP list of all gates of the gatetype that are isolated in the selected channel. 





        

<hr>



### function Config\_get\_isolated\_channel\_dot\_gates 

_Finds the isolated dot gates in the selected channel._ 
```C++
ConnectionsHandle Config_get_isolated_channel_dot_gates (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

DotGatesSP list of all gates of the gatetype that are isolated in the selected channel. 





        

<hr>



### function Config\_get\_isolated\_channel\_gates 

_Finds the isolated gates in the selected channel._ 
```C++
ConnectionsHandle Config_get_isolated_channel_gates (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

GatesSP&lt;Gate&gt; list of all gates of the gatetype that are isolated in the selected channel. 





        

<hr>



### function Config\_get\_isolated\_channel\_plunger\_gates 

_Finds the isolated plunger gates in the selected channel._ 
```C++
ConnectionsHandle Config_get_isolated_channel_plunger_gates (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

ConnectionsSP list of all gates of the gatetype that are isolated in the selected channel. 





        

<hr>



### function Config\_get\_isolated\_channel\_reservoir\_gates 

_Finds the isolated reservoir gates in the selected channel._ 
```C++
ConnectionsHandle Config_get_isolated_channel_reservoir_gates (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

ConnectionsSP list of all gates of the gatetype that are isolated in the selected channel. 





        

<hr>



### function Config\_get\_isolated\_channel\_screening\_gates 

_Finds the isolated screening gates in the selected channel._ 
```C++
ConnectionsHandle Config_get_isolated_channel_screening_gates (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

ConnectionsSP list of all gates of the gatetype that are isolated in the selected channel. 





        

<hr>



### function Config\_get\_isolated\_dot\_gates 

_Task to find isolated dot gates stored in the config._ 
```C++
ConnectionsHandle Config_get_isolated_dot_gates (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_isolated\_dot\_gates\_by\_channel 

_Returns dot gates indexed by channel which are unshared._ 
```C++
MapChannelConnectionsHandle Config_get_isolated_dot_gates_by_channel (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_isolated\_gates 

_Task to find isolated gates stored in the config._ 
```C++
ConnectionsHandle Config_get_isolated_gates (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_isolated\_gates\_by\_channel 

_Returns gates indexed by channel which are unshared._ 
```C++
MapChannelConnectionsHandle Config_get_isolated_gates_by_channel (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_isolated\_plunger\_gates 

_Task to find isolated plunger gates stored in the config._ 
```C++
ConnectionsHandle Config_get_isolated_plunger_gates (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_isolated\_plunger\_gates\_by\_channel 

_Returns plunger gates indexed by channel which are unshared._ 
```C++
MapChannelConnectionsHandle Config_get_isolated_plunger_gates_by_channel (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_isolated\_reservoir\_gates 

_Task to find isolated reservoir gates stored in the config._ 
```C++
ConnectionsHandle Config_get_isolated_reservoir_gates (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_isolated\_reservoir\_gates\_by\_channel 

_Returns reservoir gates indexed by channel which are unshared._ 
```C++
MapChannelConnectionsHandle Config_get_isolated_reservoir_gates_by_channel (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_isolated\_screening\_gates 

_Task to find isolated screening gates stored in the config._ 
```C++
ConnectionsHandle Config_get_isolated_screening_gates (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_isolated\_screening\_gates\_by\_channel 

_Returns screening gates indexed by channel which are unshared._ 
```C++
MapChannelConnectionsHandle Config_get_isolated_screening_gates_by_channel (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_num\_unique\_channels 

_Returns the number of unique channels associated with the current sample._ 
```C++
int Config_get_num_unique_channels (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_ohmic 

```C++
ConnectionHandle Config_get_ohmic (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_plunger\_gate 

```C++
ConnectionHandle Config_get_plunger_gate (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_plunger\_gate\_dict 

_Returns plunger gates indexed by channel._ 
```C++
MapChannelConnectionsHandle Config_get_plunger_gate_dict (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_reservoir\_gate 

```C++
ConnectionHandle Config_get_reservoir_gate (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_reservoir\_gate\_dict 

_Returns reservoir gates indexed by channel._ 
```C++
MapChannelConnectionsHandle Config_get_reservoir_gate_dict (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_screening\_gate 

```C++
ConnectionHandle Config_get_screening_gate (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_screening\_gate\_dict 

_Returns screening gates indexed by channel._ 
```C++
MapChannelConnectionsHandle Config_get_screening_gate_dict (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_shared\_barrier\_gates 

_Task to find shared barrier gates stored in the config._ 
```C++
ConnectionsHandle Config_get_shared_barrier_gates (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_shared\_channel\_barrier\_gates 

_Finds the shared barrier gates in the selected channel._ 
```C++
ConnectionsHandle Config_get_shared_channel_barrier_gates (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

ConnectionsSP list of all gates of the gateytpe that are shared in the selected channel. 





        

<hr>



### function Config\_get\_shared\_channel\_dot\_gates 

_Finds the shared dot gates of the gatetype in the selected channel._ 
```C++
ConnectionsHandle Config_get_shared_channel_dot_gates (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

DotGatesSP list of all gates of the gateytpe that are shared in the selected channel. 





        

<hr>



### function Config\_get\_shared\_channel\_gates 

_Finds the shared gates in the selected channel._ 
```C++
ConnectionsHandle Config_get_shared_channel_gates (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

GatesSP&lt;Gate&gt; list of all gates of the gateytpe that are shared in the selected channel. 





        

<hr>



### function Config\_get\_shared\_channel\_plunger\_gates 

_Finds the shared plunger gates in the selected channel._ 
```C++
ConnectionsHandle Config_get_shared_channel_plunger_gates (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

ConnectionsSP list of all gates of the gateytpe that are shared in the selected channel. 





        

<hr>



### function Config\_get\_shared\_channel\_reservoir\_gates 

_Finds the shared reservoir gates in the selected channel._ 
```C++
ConnectionsHandle Config_get_shared_channel_reservoir_gates (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

ConnectionsSP list of all gates of the gateytpe that are shared in the selected channel. 





        

<hr>



### function Config\_get\_shared\_channel\_screening\_gates 

_Finds the shared screening gates in the selected channel._ 
```C++
ConnectionsHandle Config_get_shared_channel_screening_gates (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel of the device of interest. 



**Returns:**

ConnectionsSP list of all gates of the gateytpe that are shared in the selected channel. 





        

<hr>



### function Config\_get\_shared\_dot\_gates 

_Task to find shared dot gates stored in the config._ 
```C++
ConnectionsHandle Config_get_shared_dot_gates (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_shared\_gates 

_Task to find shared gates stored in the config._ 
```C++
ConnectionsHandle Config_get_shared_gates (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_shared\_plunger\_gates 

_Task to find shared plunger gates stored in the config._ 
```C++
ConnectionsHandle Config_get_shared_plunger_gates (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_shared\_reservoir\_gates 

_Task to find shared reservoir gates stored in the config._ 
```C++
ConnectionsHandle Config_get_shared_reservoir_gates (
    ConfigHandle handle
) 
```




<hr>



### function Config\_get\_shared\_screening\_gates 

_Task to find shared screening gates stored in the config._ 
```C++
ConnectionsHandle Config_get_shared_screening_gates (
    ConfigHandle handle
) 
```




<hr>



### function Config\_groups 

_Return the DC wiring impedances for the physical layout._ 
```C++
MapGnameGroupHandle Config_groups (
    ConfigHandle handle
) 
```




<hr>



### function Config\_has\_barrier\_gate 

```C++
bool Config_has_barrier_gate (
    ConfigHandle handle,
    ConnectionHandle barrier_gate
) 
```




<hr>



### function Config\_has\_channel 

_Validates if this is a proper Channel name in the set of all device Channels._ 
```C++
bool Config_has_channel (
    ConfigHandle handle,
    ChannelHandle channel
) 
```





**Parameters:**


* `channel` The channel to validate. 



**Returns:**

true if the channel exists, false otherwise. 





        

<hr>



### function Config\_has\_gate 

```C++
bool Config_has_gate (
    ConfigHandle handle,
    ConnectionHandle gate
) 
```




<hr>



### function Config\_has\_gname 

_Validates if this is a proper gatename._ 
```C++
bool Config_has_gname (
    ConfigHandle handle,
    GnameHandle gname
) 
```





**Parameters:**


* `gname` The gname to validate. 



**Returns:**

true if the gname exists, false otherwise. 





        

<hr>



### function Config\_has\_ohmic 

```C++
bool Config_has_ohmic (
    ConfigHandle handle,
    ConnectionHandle ohmic
) 
```




<hr>



### function Config\_has\_plunger\_gate 

```C++
bool Config_has_plunger_gate (
    ConfigHandle handle,
    ConnectionHandle plunger_gate
) 
```




<hr>



### function Config\_has\_reservoir\_gate 

```C++
bool Config_has_reservoir_gate (
    ConfigHandle handle,
    ConnectionHandle reservoir_gate
) 
```




<hr>



### function Config\_has\_screening\_gate 

```C++
bool Config_has_screening_gate (
    ConfigHandle handle,
    ConnectionHandle screening_gate
) 
```




<hr>



### function Config\_not\_equal 

```C++
bool Config_not_equal (
    ConfigHandle handle,
    ConfigHandle other
) 
```




<hr>



### function Config\_num\_unique\_channels 

_Returns the number of unique channels associated with the current sample._ 
```C++
int Config_num_unique_channels (
    ConfigHandle handle
) 
```




<hr>



### function Config\_ohmic\_in\_channel 

_Checks if the ohmic is connected to a channel._ 
```C++
bool Config_ohmic_in_channel (
    ConfigHandle handle,
    ConnectionHandle ohmic,
    ChannelHandle channel
) 
```





**Parameters:**


* `ohmic` The ohmic to diagnose. 
* `channel` The channel to check the ohmic against. 



**Returns:**

true if the ohmic is connected to the channel, false otherwise. 





        

<hr>



### function Config\_ohmic\_in\_charge\_sensor 

_If the ohmic is inside of a charge sensor channel._ 
```C++
bool Config_ohmic_in_charge_sensor (
    ConfigHandle handle,
    ConnectionHandle ohmic
) 
```





**Parameters:**


* `ohmic` The ohmic to check 



**Returns:**

true if the ohmic is inside a charge sensor channel 





        

<hr>



### function Config\_ohmics 

```C++
ConnectionsHandle Config_ohmics (
    ConfigHandle handle
) 
```




<hr>



### function Config\_plunger\_gates 

```C++
ConnectionsHandle Config_plunger_gates (
    ConfigHandle handle
) 
```




<hr>



### function Config\_reservoir\_gates 

```C++
ConnectionsHandle Config_reservoir_gates (
    ConfigHandle handle
) 
```




<hr>



### function Config\_return\_channel\_from\_gate 

_Returns the channel a given gate belongs to. If the gate is in multiple channels, if will return the first channel if finds._ 
```C++
ChannelHandle Config_return_channel_from_gate (
    ConfigHandle handle,
    ConnectionHandle gate
) 
```





**Parameters:**


* `gate` The gate to find the channel for. 



**Returns:**

The channel the gate belongs to. A nullptr if no match is found. 





        

<hr>



### function Config\_return\_channels\_from\_gate 

_Returns all of the channels associated with a gate._ 
```C++
ChannelsHandle Config_return_channels_from_gate (
    ConfigHandle handle,
    ConnectionHandle gate
) 
```





**Parameters:**


* `gate` The gate to find the channels for. 



**Returns:**

All of the channels associated with a gate. Otherwise a nullptr if no match is found. 





        

<hr>



### function Config\_screening\_gates 

```C++
ConnectionsHandle Config_screening_gates (
    ConfigHandle handle
) 
```




<hr>



### function Config\_select\_group 

_Finds a group from the name and returns it._ 
```C++
GroupHandle Config_select_group (
    ConfigHandle handle,
    GnameHandle gname
) 
```





**Parameters:**


* `gname` The name of the group to find. 



**Returns:**

The group matching the name. A nullptr if no match is found. 





        

<hr>



### function Config\_to\_json\_string 

```C++
StringHandle Config_to_json_string (
    ConfigHandle handle
) 
```




<hr>



### function Config\_voltage\_constraints 

_Return the voltage constraints for the physical layout._ 
```C++
VoltageConstraintsHandle Config_voltage_constraints (
    ConfigHandle handle
) 
```




<hr>



### function Config\_wiring\_DC 

```C++
ImpedancesHandle Config_wiring_DC (
    ConfigHandle handle
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `c-api/include/falcon_core/physics/config/core/Config_c_api.h`

