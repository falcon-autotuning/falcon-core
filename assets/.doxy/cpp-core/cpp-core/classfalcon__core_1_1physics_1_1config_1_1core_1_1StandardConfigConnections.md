

# Class falcon\_core::physics::config::core::StandardConfigConnections



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**physics**](namespacefalcon__core_1_1physics.md) **>** [**config**](namespacefalcon__core_1_1physics_1_1config.md) **>** [**core**](namespacefalcon__core_1_1physics_1_1config_1_1core.md) **>** [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md)



_Base config functionality for core config classes._ 

* `#include <StandardConfigConnections.hpp>`



Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)


Inherited by the following classes: [falcon\_core::physics::config::core::Config](classfalcon__core_1_1physics_1_1config_1_1core_1_1Config.md),  [falcon\_core::physics::config::core::Group](classfalcon__core_1_1physics_1_1config_1_1core_1_1Group.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**StandardConfigConnections**](#function-standardconfigconnections-13) (const [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md) & other) <br> |
|   | [**StandardConfigConnections**](#function-standardconfigconnections-23) (const device\_structures::ConnectionsSP & screening\_gates, const device\_structures::ConnectionsSP & reservoir\_gates, const device\_structures::ConnectionsSP & plunger\_gates, const device\_structures::ConnectionsSP & barrier\_gates, const device\_structures::ConnectionsSP & ohmics) <br>_Constructs the differet gate types holders._  |
|  const device\_structures::ConnectionsSP & | [**barrier\_gates**](#function-barrier_gates) () const<br>_The barrier gates from the config._  |
|  const device\_structures::ConnectionsSP | [**dot\_gates**](#function-dot_gates) () const<br>_Gets the connections of type as supplied._  |
|  const device\_structures::ConnectionsSP | [**get\_all\_connections**](#function-get_all_connections) () const<br>_Gets all of the connections for this collection from the config._  |
|  const device\_structures::ConnectionsSP | [**get\_all\_gates**](#function-get_all_gates) () const<br>_Gets all of the gates for this collection from the config._  |
|  const device\_structures::ConnectionSP | [**get\_barrier\_gate**](#function-get_barrier_gate) () const<br>_Gets the first barrier gate connection._  |
|  const device\_structures::ConnectionSP | [**get\_dot\_gate**](#function-get_dot_gate) () const<br>_Gets the first dot gate connection._  |
|  const device\_structures::ConnectionSP | [**get\_gate**](#function-get_gate) () const<br>_Gets the first gate connection._  |
|  const device\_structures::ConnectionSP | [**get\_ohmic**](#function-get_ohmic) () const<br>_Gets the first ohmic connection._  |
|  const device\_structures::ConnectionSP | [**get\_plunger\_gate**](#function-get_plunger_gate) () const<br>_Gets the first plunger gate connection._  |
|  const device\_structures::ConnectionSP | [**get\_reservoir\_gate**](#function-get_reservoir_gate) () const<br>_Gets the first reservoir gate connection.._  |
|  const device\_structures::ConnectionSP | [**get\_screening\_gate**](#function-get_screening_gate) () const<br>_Gets the first screening gate connection._  |
|  bool | [**has\_barrier\_gate**](#function-has_barrier_gate) (const device\_structures::ConnectionSP & gate) const<br>_If this gate is a barriergate of this group or not._  |
|  bool | [**has\_gate**](#function-has_gate) (const device\_structures::ConnectionSP & gate) const<br>_If this gate is a member of this group or not._  |
|  bool | [**has\_ohmic**](#function-has_ohmic) (const device\_structures::ConnectionSP & ohmic) const<br>_If this ohmic is a member of this group or not._  |
|  bool | [**has\_plunger\_gate**](#function-has_plunger_gate) (const device\_structures::ConnectionSP & gate) const<br>_If this gate is a plungergate of this group or not._  |
|  bool | [**has\_reservoir\_gate**](#function-has_reservoir_gate) (const device\_structures::ConnectionSP & gate) const<br>_If this gate is a reservoirgate of this group or not._  |
|  bool | [**has\_screening\_gate**](#function-has_screening_gate) (const device\_structures::ConnectionSP & gate) const<br>_If this gate is a screeninggate of this group or not._  |
|  const device\_structures::ConnectionsSP & | [**ohmics**](#function-ohmics) () const<br>_The ohmics from the config._  |
|  bool | [**operator!=**](#function-operator) (const [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md) & other) const<br> |
|  [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md) & | [**operator=**](#function-operator_1) (const [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md) & other) <br> |
|  bool | [**operator==**](#function-operator_2) (const [**StandardConfigConnections**](classfalcon__core_1_1physics_1_1config_1_1core_1_1StandardConfigConnections.md) & other) const<br> |
|  const device\_structures::ConnectionsSP & | [**plunger\_gates**](#function-plunger_gates) () const<br>_The plunger gates from the config._  |
|  const device\_structures::ConnectionsSP & | [**reservoir\_gates**](#function-reservoir_gates) () const<br>_The reservoir gates from the config._  |
|  const device\_structures::ConnectionsSP & | [**screening\_gates**](#function-screening_gates) () const<br>_The screening gates from the config._  |


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
|   | [**StandardConfigConnections**](#function-standardconfigconnections-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Public Functions Documentation




### function StandardConfigConnections [1/3]

```C++
falcon_core::physics::config::core::StandardConfigConnections::StandardConfigConnections (
    const StandardConfigConnections & other
) 
```




<hr>



### function StandardConfigConnections [2/3]

_Constructs the differet gate types holders._ 
```C++
falcon_core::physics::config::core::StandardConfigConnections::StandardConfigConnections (
    const device_structures::ConnectionsSP & screening_gates,
    const device_structures::ConnectionsSP & reservoir_gates,
    const device_structures::ConnectionsSP & plunger_gates,
    const device_structures::ConnectionsSP & barrier_gates,
    const device_structures::ConnectionsSP & ohmics
) 
```





**Parameters:**


* `screening_gates` The screening gates. 
* `reservoir_gates` The reservoir gates. 
* `plunger_gates` The plunger gates. 
* `barrier_gates` The barrier gates. 
* `ohmics` The ohmic contacts. 




        

<hr>



### function barrier\_gates 

_The barrier gates from the config._ 
```C++
const device_structures::ConnectionsSP & falcon_core::physics::config::core::StandardConfigConnections::barrier_gates () const
```





**Returns:**

The barrier gates. 





        

<hr>



### function dot\_gates 

_Gets the connections of type as supplied._ 
```C++
const device_structures::ConnectionsSP falcon_core::physics::config::core::StandardConfigConnections::dot_gates () const
```





**Parameters:**


* `conn_type` The type of connection to get. The types of supported connections are: Connection, Connection, Connection, Connection, Connection, DotGate, Gate. and Connection 



**Returns:**

the plural form of the connection type. This corresponds to the conn\_type 





        

<hr>



### function get\_all\_connections 

_Gets all of the connections for this collection from the config._ 
```C++
const device_structures::ConnectionsSP falcon_core::physics::config::core::StandardConfigConnections::get_all_connections () const
```




<hr>



### function get\_all\_gates 

_Gets all of the gates for this collection from the config._ 
```C++
const device_structures::ConnectionsSP falcon_core::physics::config::core::StandardConfigConnections::get_all_gates () const
```




<hr>



### function get\_barrier\_gate 

_Gets the first barrier gate connection._ 
```C++
const device_structures::ConnectionSP falcon_core::physics::config::core::StandardConfigConnections::get_barrier_gate () const
```




<hr>



### function get\_dot\_gate 

_Gets the first dot gate connection._ 
```C++
const device_structures::ConnectionSP falcon_core::physics::config::core::StandardConfigConnections::get_dot_gate () const
```




<hr>



### function get\_gate 

_Gets the first gate connection._ 
```C++
const device_structures::ConnectionSP falcon_core::physics::config::core::StandardConfigConnections::get_gate () const
```




<hr>



### function get\_ohmic 

_Gets the first ohmic connection._ 
```C++
const device_structures::ConnectionSP falcon_core::physics::config::core::StandardConfigConnections::get_ohmic () const
```




<hr>



### function get\_plunger\_gate 

_Gets the first plunger gate connection._ 
```C++
const device_structures::ConnectionSP falcon_core::physics::config::core::StandardConfigConnections::get_plunger_gate () const
```




<hr>



### function get\_reservoir\_gate 

_Gets the first reservoir gate connection.._ 
```C++
const device_structures::ConnectionSP falcon_core::physics::config::core::StandardConfigConnections::get_reservoir_gate () const
```




<hr>



### function get\_screening\_gate 

_Gets the first screening gate connection._ 
```C++
const device_structures::ConnectionSP falcon_core::physics::config::core::StandardConfigConnections::get_screening_gate () const
```




<hr>



### function has\_barrier\_gate 

_If this gate is a barriergate of this group or not._ 
```C++
bool falcon_core::physics::config::core::StandardConfigConnections::has_barrier_gate (
    const device_structures::ConnectionSP & gate
) const
```




<hr>



### function has\_gate 

_If this gate is a member of this group or not._ 
```C++
bool falcon_core::physics::config::core::StandardConfigConnections::has_gate (
    const device_structures::ConnectionSP & gate
) const
```




<hr>



### function has\_ohmic 

_If this ohmic is a member of this group or not._ 
```C++
bool falcon_core::physics::config::core::StandardConfigConnections::has_ohmic (
    const device_structures::ConnectionSP & ohmic
) const
```




<hr>



### function has\_plunger\_gate 

_If this gate is a plungergate of this group or not._ 
```C++
bool falcon_core::physics::config::core::StandardConfigConnections::has_plunger_gate (
    const device_structures::ConnectionSP & gate
) const
```




<hr>



### function has\_reservoir\_gate 

_If this gate is a reservoirgate of this group or not._ 
```C++
bool falcon_core::physics::config::core::StandardConfigConnections::has_reservoir_gate (
    const device_structures::ConnectionSP & gate
) const
```




<hr>



### function has\_screening\_gate 

_If this gate is a screeninggate of this group or not._ 
```C++
bool falcon_core::physics::config::core::StandardConfigConnections::has_screening_gate (
    const device_structures::ConnectionSP & gate
) const
```




<hr>



### function ohmics 

_The ohmics from the config._ 
```C++
const device_structures::ConnectionsSP & falcon_core::physics::config::core::StandardConfigConnections::ohmics () const
```





**Returns:**

The ohmics gates. 





        

<hr>



### function operator!= 

```C++
bool falcon_core::physics::config::core::StandardConfigConnections::operator!= (
    const StandardConfigConnections & other
) const
```




<hr>



### function operator= 

```C++
StandardConfigConnections & falcon_core::physics::config::core::StandardConfigConnections::operator= (
    const StandardConfigConnections & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::physics::config::core::StandardConfigConnections::operator== (
    const StandardConfigConnections & other
) const
```




<hr>



### function plunger\_gates 

_The plunger gates from the config._ 
```C++
const device_structures::ConnectionsSP & falcon_core::physics::config::core::StandardConfigConnections::plunger_gates () const
```





**Returns:**

The plunger gates. 





        

<hr>



### function reservoir\_gates 

_The reservoir gates from the config._ 
```C++
const device_structures::ConnectionsSP & falcon_core::physics::config::core::StandardConfigConnections::reservoir_gates () const
```





**Returns:**

The reservoir gates. 





        

<hr>



### function screening\_gates 

_The screening gates from the config._ 
```C++
const device_structures::ConnectionsSP & falcon_core::physics::config::core::StandardConfigConnections::screening_gates () const
```





**Returns:**

The screening gates. 





        

<hr>
## Protected Functions Documentation




### function StandardConfigConnections [3/3]

```C++
falcon_core::physics::config::core::StandardConfigConnections::StandardConfigConnections () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::physics::config::core::StandardConfigConnections::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::physics::config::core::StandardConfigConnections::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/physics/config/core/StandardConfigConnections.hpp`

