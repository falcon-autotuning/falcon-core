

# Class falcon\_core::physics::device\_structures::Connection



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**physics**](namespacefalcon__core_1_1physics.md) **>** [**device\_structures**](namespacefalcon__core_1_1physics_1_1device__structures.md) **>** [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md)








Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)


Inherited by the following classes: [falcon\_core::physics::config::geometries::DotGateWithNeighbors](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1DotGateWithNeighbors.md),  [falcon\_core::physics::config::geometries::LeftReservoirWithImplantedOhmic](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1LeftReservoirWithImplantedOhmic.md),  [falcon\_core::physics::config::geometries::RightReservoirWithImplantedOhmic](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1RightReservoirWithImplantedOhmic.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Connection**](#function-connection-13) (const [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) & other) <br>_Copy constructor._  |
|   | [**Connection**](#function-connection-23) (const std::string & name, const DeviceFeature & type) <br>_Construct a_ [_**Connection**_](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) _with a name and type._ |
|  bool | [**is\_barrier\_gate**](#function-is_barrier_gate) () const<br>_Check if the connection is a barriergate._  |
|  bool | [**is\_dot\_gate**](#function-is_dot_gate) () const<br>_Check if the connection is a plungergate or barriergate._  |
|  bool | [**is\_gate**](#function-is_gate) () const<br>_Check if the connection is any type of gate (barrier, plunger, reservoir, screening)._  |
|  bool | [**is\_ohmic**](#function-is_ohmic) () const<br>_Check if the connection is an ohmic contact._  |
|  bool | [**is\_plunger\_gate**](#function-is_plunger_gate) () const<br>_Check if the connection is a plunger gate._  |
|  bool | [**is\_reservoir\_gate**](#function-is_reservoir_gate) () const<br>_Check if the connection is a reservoir gate._  |
|  bool | [**is\_screening\_gate**](#function-is_screening_gate) () const<br>_Check if the connection is a screening gate._  |
|  const std::string | [**name**](#function-name) () const<br>_The name of the connection._  |
|  bool | [**operator!=**](#function-operator) (const [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) & other) const<br> |
|  bool | [**operator&lt;**](#function-operator_1) (const [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) & other) const<br> |
|  [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) & | [**operator=**](#function-operator_2) (const [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) & other) <br>_Assignment operator._  |
|  bool | [**operator==**](#function-operator_3) (const [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) & other) const<br> |
|  const std::string | [**type**](#function-type) () const<br>_The type of the connection._  |


## Public Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  void | [**serialize**](classfalcon__core_1_1generic_1_1Song.md#function-serialize) (Archive &) <br>_cereal serialization interface. Override in derived classes._  |
|  std::string | [**to\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-to_json_string) () const<br>_Serialize this object to a JSON string._  |
| virtual  | [**~Song**](classfalcon__core_1_1generic_1_1Song.md#function-song) () = default<br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) &gt; | [**BarrierGate**](#function-barriergate) (const std::string & name) <br>_Construct a BarrierGate with a name._  |
|  std::shared\_ptr&lt; [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) &gt; | [**Ohmic**](#function-ohmic) (const std::string & name) <br>_Construct a Ohmic with a name._  |
|  std::shared\_ptr&lt; [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) &gt; | [**PlungerGate**](#function-plungergate) (const std::string & name) <br>_Construct a PlungerGate with a name._  |
|  std::shared\_ptr&lt; [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) &gt; | [**ReservoirGate**](#function-reservoirgate) (const std::string & name) <br>_Construct a ReservoirGate with a name._  |
|  std::shared\_ptr&lt; [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) &gt; | [**ScreeningGate**](#function-screeninggate) (const std::string & name) <br>_Construct a ScreeningGate with a name._  |


## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |










































## Protected Functions

| Type | Name |
| ---: | :--- |
|   | [**Connection**](#function-connection-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Public Functions Documentation




### function Connection [1/3]

_Copy constructor._ 
```C++
falcon_core::physics::device_structures::Connection::Connection (
    const Connection & other
) 
```




<hr>



### function Connection [2/3]

_Construct a_ [_**Connection**_](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) _with a name and type._
```C++
falcon_core::physics::device_structures::Connection::Connection (
    const std::string & name,
    const DeviceFeature & type
) 
```





**Parameters:**


* `name` The name of the connection. 
* `type` The type of the connection (DeviceFeature). 




        

<hr>



### function is\_barrier\_gate 

_Check if the connection is a barriergate._ 
```C++
bool falcon_core::physics::device_structures::Connection::is_barrier_gate () const
```




<hr>



### function is\_dot\_gate 

_Check if the connection is a plungergate or barriergate._ 
```C++
bool falcon_core::physics::device_structures::Connection::is_dot_gate () const
```




<hr>



### function is\_gate 

_Check if the connection is any type of gate (barrier, plunger, reservoir, screening)._ 
```C++
bool falcon_core::physics::device_structures::Connection::is_gate () const
```




<hr>



### function is\_ohmic 

_Check if the connection is an ohmic contact._ 
```C++
bool falcon_core::physics::device_structures::Connection::is_ohmic () const
```




<hr>



### function is\_plunger\_gate 

_Check if the connection is a plunger gate._ 
```C++
bool falcon_core::physics::device_structures::Connection::is_plunger_gate () const
```




<hr>



### function is\_reservoir\_gate 

_Check if the connection is a reservoir gate._ 
```C++
bool falcon_core::physics::device_structures::Connection::is_reservoir_gate () const
```




<hr>



### function is\_screening\_gate 

_Check if the connection is a screening gate._ 
```C++
bool falcon_core::physics::device_structures::Connection::is_screening_gate () const
```




<hr>



### function name 

_The name of the connection._ 
```C++
const std::string falcon_core::physics::device_structures::Connection::name () const
```





**Returns:**

The name as a string. 





        

<hr>



### function operator!= 

```C++
bool falcon_core::physics::device_structures::Connection::operator!= (
    const Connection & other
) const
```




<hr>



### function operator&lt; 

```C++
bool falcon_core::physics::device_structures::Connection::operator< (
    const Connection & other
) const
```




<hr>



### function operator= 

_Assignment operator._ 
```C++
Connection & falcon_core::physics::device_structures::Connection::operator= (
    const Connection & other
) 
```




<hr>



### function operator== 

```C++
bool falcon_core::physics::device_structures::Connection::operator== (
    const Connection & other
) const
```




<hr>



### function type 

_The type of the connection._ 
```C++
const std::string falcon_core::physics::device_structures::Connection::type () const
```





**Returns:**

The type as a string. 





        

<hr>
## Public Static Functions Documentation




### function BarrierGate 

_Construct a BarrierGate with a name._ 
```C++
static std::shared_ptr< Connection > falcon_core::physics::device_structures::Connection::BarrierGate (
    const std::string & name
) 
```





**Parameters:**


* `name` The name of the connection. 




        

<hr>



### function Ohmic 

_Construct a Ohmic with a name._ 
```C++
static std::shared_ptr< Connection > falcon_core::physics::device_structures::Connection::Ohmic (
    const std::string & name
) 
```





**Parameters:**


* `name` The name of the connection. 




        

<hr>



### function PlungerGate 

_Construct a PlungerGate with a name._ 
```C++
static std::shared_ptr< Connection > falcon_core::physics::device_structures::Connection::PlungerGate (
    const std::string & name
) 
```





**Parameters:**


* `name` The name of the connection. 




        

<hr>



### function ReservoirGate 

_Construct a ReservoirGate with a name._ 
```C++
static std::shared_ptr< Connection > falcon_core::physics::device_structures::Connection::ReservoirGate (
    const std::string & name
) 
```





**Parameters:**


* `name` The name of the connection. 




        

<hr>



### function ScreeningGate 

_Construct a ScreeningGate with a name._ 
```C++
static std::shared_ptr< Connection > falcon_core::physics::device_structures::Connection::ScreeningGate (
    const std::string & name
) 
```





**Parameters:**


* `name` The name of the connection. 




        

<hr>
## Protected Functions Documentation




### function Connection [3/3]

```C++
falcon_core::physics::device_structures::Connection::Connection () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::physics::device_structures::Connection::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::physics::device_structures::Connection::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/physics/device_structures/Connection.hpp`

