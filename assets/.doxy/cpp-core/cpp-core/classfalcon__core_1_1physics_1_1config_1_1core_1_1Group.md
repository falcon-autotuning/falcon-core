

# Class falcon\_core::physics::config::core::Group



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**physics**](namespacefalcon__core_1_1physics.md) **>** [**config**](namespacefalcon__core_1_1physics_1_1config.md) **>** [**core**](namespacefalcon__core_1_1physics_1_1config_1_1core.md) **>** [**Group**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Group.md)



_Elements of the config that pertain to an individual group of gates._ 

* `#include <Group.hpp>`



Inherits the following classes: [falcon\_core::physics::config::core::StandardConfigConnections](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Group**](#function-group-13) (const [**Group**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Group.md) & other) <br> |
|   | [**Group**](#function-group-23) (const autotuner\_interfaces::names::ChannelSP & name, const int & num\_dots, const device\_structures::ConnectionsSP & screening\_gates, const device\_structures::ConnectionsSP & reservoir\_gates, const device\_structures::ConnectionsSP & plunger\_gates, const device\_structures::ConnectionsSP & barrier\_gates, const device\_structures::ConnectionsSP & order) <br>_Holds information about a group of gates._  |
|  device\_structures::ConnectionsSP | [**get\_all\_channel\_gates**](#function-get_all_channel_gates) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Gets all of the gates assocciated with this channel from the config._  |
|  bool | [**has\_channel**](#function-has_channel) (const autotuner\_interfaces::names::ChannelSP & channel) const<br>_Validates if this channel is present._  |
|  bool | [**is\_charge\_sensor**](#function-is_charge_sensor) () const<br>_Checks if this channel could be a charge sensor._  |
|  const autotuner\_interfaces::names::ChannelSP & | [**name**](#function-name) () const<br>_collect the name of this group._  |
|  const int & | [**num\_dots**](#function-num_dots) () const<br>_collect the number of dots in this group._  |
|  const device\_structures::ConnectionsSP | [**ohmics**](#function-ohmics) () const<br>_collect the ohmics pertaining to this group._  |
|  bool | [**operator!=**](#function-operator) (const [**Group**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Group.md) & other) const<br> |
|  [**Group**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Group.md) & | [**operator=**](#function-operator_1) (const [**Group**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Group.md) & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const [**Group**](classfalcon__core_1_1physics_1_1config_1_1core_1_1Group.md) & other) const<br> |
|  const geometries::GateGeometryArray1DSP & | [**order**](#function-order) () const<br>_collect the order of the gates in this group._  |


## Public Functions inherited from falcon_core::physics::config::core::StandardConfigConnections

See [falcon\_core::physics::config::core::StandardConfigConnections](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md)

| Type | Name |
| ---: | :--- |
|   | [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-standardconfigconnections-13) (const [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md) & other) <br> |
|   | [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-standardconfigconnections-23) (const device\_structures::ConnectionsSP & screening\_gates, const device\_structures::ConnectionsSP & reservoir\_gates, const device\_structures::ConnectionsSP & plunger\_gates, const device\_structures::ConnectionsSP & barrier\_gates, const device\_structures::ConnectionsSP & ohmics) <br>_Constructs the differet gate types holders._  |
|  const device\_structures::ConnectionsSP & | [**barrier\_gates**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-barrier_gates) () const<br>_The barrier gates from the config._  |
|  const device\_structures::ConnectionsSP | [**dot\_gates**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-dot_gates) () const<br>_Gets the connections of type as supplied._  |
|  const device\_structures::ConnectionsSP | [**get\_all\_connections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-get_all_connections) () const<br>_Gets all of the connections for this collection from the config._  |
|  const device\_structures::ConnectionsSP | [**get\_all\_gates**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-get_all_gates) () const<br>_Gets all of the gates for this collection from the config._  |
|  const device\_structures::ConnectionSP | [**get\_barrier\_gate**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-get_barrier_gate) () const<br>_Gets the first barrier gate connection._  |
|  const device\_structures::ConnectionSP | [**get\_dot\_gate**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-get_dot_gate) () const<br>_Gets the first dot gate connection._  |
|  const device\_structures::ConnectionSP | [**get\_gate**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-get_gate) () const<br>_Gets the first gate connection._  |
|  const device\_structures::ConnectionSP | [**get\_ohmic**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-get_ohmic) () const<br>_Gets the first ohmic connection._  |
|  const device\_structures::ConnectionSP | [**get\_plunger\_gate**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-get_plunger_gate) () const<br>_Gets the first plunger gate connection._  |
|  const device\_structures::ConnectionSP | [**get\_reservoir\_gate**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-get_reservoir_gate) () const<br>_Gets the first reservoir gate connection.._  |
|  const device\_structures::ConnectionSP | [**get\_screening\_gate**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-get_screening_gate) () const<br>_Gets the first screening gate connection._  |
|  bool | [**has\_barrier\_gate**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-has_barrier_gate) (const device\_structures::ConnectionSP & gate) const<br>_If this gate is a barriergate of this group or not._  |
|  bool | [**has\_gate**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-has_gate) (const device\_structures::ConnectionSP & gate) const<br>_If this gate is a member of this group or not._  |
|  bool | [**has\_ohmic**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-has_ohmic) (const device\_structures::ConnectionSP & ohmic) const<br>_If this ohmic is a member of this group or not._  |
|  bool | [**has\_plunger\_gate**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-has_plunger_gate) (const device\_structures::ConnectionSP & gate) const<br>_If this gate is a plungergate of this group or not._  |
|  bool | [**has\_reservoir\_gate**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-has_reservoir_gate) (const device\_structures::ConnectionSP & gate) const<br>_If this gate is a reservoirgate of this group or not._  |
|  bool | [**has\_screening\_gate**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-has_screening_gate) (const device\_structures::ConnectionSP & gate) const<br>_If this gate is a screeninggate of this group or not._  |
|  const device\_structures::ConnectionsSP & | [**ohmics**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-ohmics) () const<br>_The ohmics from the config._  |
|  bool | [**operator!=**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-operator) (const [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md) & other) const<br> |
|  [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md) & | [**operator=**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-operator_1) (const [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md) & other) <br> |
|  bool | [**operator==**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-operator_2) (const [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md) & other) const<br> |
|  const device\_structures::ConnectionsSP & | [**plunger\_gates**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-plunger_gates) () const<br>_The plunger gates from the config._  |
|  const device\_structures::ConnectionsSP & | [**reservoir\_gates**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-reservoir_gates) () const<br>_The reservoir gates from the config._  |
|  const device\_structures::ConnectionsSP & | [**screening\_gates**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-screening_gates) () const<br>_The screening gates from the config._  |


## Public Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  void | [**serialize**](classfalcon__core_1_1generic_1_1Song.md#function-serialize) (Archive &) <br>_cereal serialization interface. Override in derived classes._  |
|  std::string | [**to\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-to_json_string) () const<br>_Serialize this object to a JSON string._  |
| virtual  | [**~Song**](classfalcon__core_1_1generic_1_1Song.md#function-song) () = default<br> |






## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |






























































## Protected Functions

| Type | Name |
| ---: | :--- |
|   | [**Group**](#function-group-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |


## Protected Functions inherited from falcon_core::physics::config::core::StandardConfigConnections

See [falcon\_core::physics::config::core::StandardConfigConnections](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md)

| Type | Name |
| ---: | :--- |
|   | [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-standardconfigconnections-33) () <br> |
|  void | [**serialize**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md#function-serialize) (Archive & ar) <br> |










## Public Functions Documentation




### function Group [1/3]

```C++
falcon_core::physics::config::core::Group::Group (
    const Group & other
) 
```




<hr>



### function Group [2/3]

_Holds information about a group of gates._ 
```C++
falcon_core::physics::config::core::Group::Group (
    const autotuner_interfaces::names::ChannelSP & name,
    const int & num_dots,
    const device_structures::ConnectionsSP & screening_gates,
    const device_structures::ConnectionsSP & reservoir_gates,
    const device_structures::ConnectionsSP & plunger_gates,
    const device_structures::ConnectionsSP & barrier_gates,
    const device_structures::ConnectionsSP & order
) 
```





**Parameters:**


* `name` The name of the group. 
* `num_dots` The number of dots in the group. 
* `screening_gates` The screening gates in the group. 
* `reservoir_gates` The reservoir gates in the group. 
* `plunger_gates` The plunger gates in the group. 
* `barrier_gates` The barrier gates in the group. 
* `order` The order of the gates in the group. 




        

<hr>



### function get\_all\_channel\_gates 

_Gets all of the gates assocciated with this channel from the config._ 
```C++
device_structures::ConnectionsSP falcon_core::physics::config::core::Group::get_all_channel_gates (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel to collect the gates for. 



**Returns:**

The gates associated with this channel. If the channel is not correct then empty gates are returned. 





        

<hr>



### function has\_channel 

_Validates if this channel is present._ 
```C++
bool falcon_core::physics::config::core::Group::has_channel (
    const autotuner_interfaces::names::ChannelSP & channel
) const
```





**Parameters:**


* `channel` The channel to validate. 



**Returns:**

true if the channel is present. 





        

<hr>



### function is\_charge\_sensor 

_Checks if this channel could be a charge sensor._ 
```C++
bool falcon_core::physics::config::core::Group::is_charge_sensor () const
```





**Returns:**

true if the channel has a single dot. 





        

<hr>



### function name 

_collect the name of this group._ 
```C++
const autotuner_interfaces::names::ChannelSP & falcon_core::physics::config::core::Group::name () const
```




<hr>



### function num\_dots 

_collect the number of dots in this group._ 
```C++
const int & falcon_core::physics::config::core::Group::num_dots () const
```




<hr>



### function ohmics 

_collect the ohmics pertaining to this group._ 
```C++
const device_structures::ConnectionsSP falcon_core::physics::config::core::Group::ohmics () const
```




<hr>



### function operator!= 

```C++
bool falcon_core::physics::config::core::Group::operator!= (
    const Group & other
) const
```




<hr>



### function operator= 

```C++
Group & falcon_core::physics::config::core::Group::operator= (
    const Group & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::physics::config::core::Group::operator== (
    const Group & other
) const
```




<hr>



### function order 

_collect the order of the gates in this group._ 
```C++
const geometries::GateGeometryArray1DSP & falcon_core::physics::config::core::Group::order () const
```




<hr>
## Protected Functions Documentation




### function Group [3/3]

```C++
falcon_core::physics::config::core::Group::Group () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::physics::config::core::Group::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::physics::config::core::Group::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/physics/config/core/Group.hpp`

