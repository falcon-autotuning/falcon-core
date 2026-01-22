

# Class falcon\_core::physics::config::geometries::LeftReservoirWithImplantedOhmic



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**physics**](namespacefalcon__core_1_1physics.md) **>** [**config**](namespacefalcon__core_1_1physics_1_1config.md) **>** [**geometries**](namespacefalcon__core_1_1physics_1_1config_1_1geometries.md) **>** [**LeftReservoirWithImplantedOhmic**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1LeftReservoirWithImplantedOhmic.md)



_A special reservoir geometry that has an implanted ohmic contact and the rest of the channel extending to the right._ 

* `#include <LeftReservoirWithImplantedOhmic.hpp>`



Inherits the following classes: [falcon\_core::physics::device\_structures::Connection](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md),  [falcon\_core::physics::config::geometries::HasImplantedOhmic](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasImplantedOhmic.md),  [falcon\_core::physics::config::geometries::HasRightNeighbor](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasRightNeighbor.md)


























































































































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**LeftReservoirWithImplantedOhmic**](#function-leftreservoirwithimplantedohmic-12) (std::string name, device\_structures::ConnectionSP right\_neighbor, device\_structures::ConnectionSP ohmic) <br> |


## Public Functions inherited from falcon_core::physics::device_structures::Connection

See [falcon\_core::physics::device\_structures::Connection](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md)

| Type | Name |
| ---: | :--- |
|   | [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-connection-13) (const Connection & other) <br>_Copy constructor._  |
|   | [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-connection-23) (const std::string & name, const DeviceFeature & type) <br>_Construct a_ [_**Connection**_](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md) _with a name and type._ |
|  bool | [**is\_barrier\_gate**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-is_barrier_gate) () const<br>_Check if the connection is a barriergate._  |
|  bool | [**is\_dot\_gate**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-is_dot_gate) () const<br>_Check if the connection is a plungergate or barriergate._  |
|  bool | [**is\_gate**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-is_gate) () const<br>_Check if the connection is any type of gate (barrier, plunger, reservoir, screening)._  |
|  bool | [**is\_ohmic**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-is_ohmic) () const<br>_Check if the connection is an ohmic contact._  |
|  bool | [**is\_plunger\_gate**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-is_plunger_gate) () const<br>_Check if the connection is a plunger gate._  |
|  bool | [**is\_reservoir\_gate**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-is_reservoir_gate) () const<br>_Check if the connection is a reservoir gate._  |
|  bool | [**is\_screening\_gate**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-is_screening_gate) () const<br>_Check if the connection is a screening gate._  |
|  const std::string | [**name**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-name) () const<br>_The name of the connection._  |
|  bool | [**operator!=**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-operator) (const [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-connection-13) & other) const<br> |
|  bool | [**operator&lt;**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-operator_1) (const [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-connection-13) & other) const<br> |
|  [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-connection-13) & | [**operator=**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-operator_2) (const [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-connection-13) & other) <br>_Assignment operator._  |
|  bool | [**operator==**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-operator_3) (const [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-connection-13) & other) const<br> |
|  const std::string | [**type**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-type) () const<br>_The type of the connection._  |


## Public Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  void | [**serialize**](classfalcon__core_1_1generic_1_1Song.md#function-serialize) (Archive &) <br>_cereal serialization interface. Override in derived classes._  |
|  std::string | [**to\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-to_json_string) () const<br>_Serialize this object to a JSON string._  |
| virtual  | [**~Song**](classfalcon__core_1_1generic_1_1Song.md#function-song) () = default<br> |


## Public Functions inherited from falcon_core::physics::config::geometries::HasImplantedOhmic

See [falcon\_core::physics::config::geometries::HasImplantedOhmic](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasImplantedOhmic.md)

| Type | Name |
| ---: | :--- |
|   | [**HasImplantedOhmic**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasImplantedOhmic.md#function-hasimplantedohmic-13) (const HasImplantedOhmic & other) <br> |
|   | [**HasImplantedOhmic**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasImplantedOhmic.md#function-hasimplantedohmic-23) (device\_structures::ConnectionSP ohmic) <br> |
|  device\_structures::ConnectionSP | [**ohmic**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasImplantedOhmic.md#function-ohmic) () const<br>_Returns the ohmic below the gate._  |
|  HasImplantedOhmic & | [**operator=**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasImplantedOhmic.md#function-operator) (const HasImplantedOhmic & other) <br> |


## Public Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  void | [**serialize**](classfalcon__core_1_1generic_1_1Song.md#function-serialize) (Archive &) <br>_cereal serialization interface. Override in derived classes._  |
|  std::string | [**to\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-to_json_string) () const<br>_Serialize this object to a JSON string._  |
| virtual  | [**~Song**](classfalcon__core_1_1generic_1_1Song.md#function-song) () = default<br> |


## Public Functions inherited from falcon_core::physics::config::geometries::HasRightNeighbor

See [falcon\_core::physics::config::geometries::HasRightNeighbor](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasRightNeighbor.md)

| Type | Name |
| ---: | :--- |
|   | [**HasRightNeighbor**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasRightNeighbor.md#function-hasrightneighbor-13) (const HasRightNeighbor & other) <br> |
|   | [**HasRightNeighbor**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasRightNeighbor.md#function-hasrightneighbor-23) (device\_structures::ConnectionSP right\_neighbor) <br> |
|  HasRightNeighbor & | [**operator=**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasRightNeighbor.md#function-operator) (const HasRightNeighbor & other) <br> |
|  device\_structures::ConnectionSP | [**right\_neighbor**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasRightNeighbor.md#function-right_neighbor) () const<br>_Returns the right neighbor of the gate._  |


## Public Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  void | [**serialize**](classfalcon__core_1_1generic_1_1Song.md#function-serialize) (Archive &) <br>_cereal serialization interface. Override in derived classes._  |
|  std::string | [**to\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-to_json_string) () const<br>_Serialize this object to a JSON string._  |
| virtual  | [**~Song**](classfalcon__core_1_1generic_1_1Song.md#function-song) () = default<br> |




## Public Static Functions inherited from falcon_core::physics::device_structures::Connection

See [falcon\_core::physics::device\_structures::Connection](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-connection-13) &gt; | [**BarrierGate**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-barriergate) (const std::string & name) <br>_Construct a BarrierGate with a name._  |
|  std::shared\_ptr&lt; [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-connection-13) &gt; | [**Ohmic**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-ohmic) (const std::string & name) <br>_Construct a Ohmic with a name._  |
|  std::shared\_ptr&lt; [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-connection-13) &gt; | [**PlungerGate**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-plungergate) (const std::string & name) <br>_Construct a PlungerGate with a name._  |
|  std::shared\_ptr&lt; [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-connection-13) &gt; | [**ReservoirGate**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-reservoirgate) (const std::string & name) <br>_Construct a ReservoirGate with a name._  |
|  std::shared\_ptr&lt; [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-connection-13) &gt; | [**ScreeningGate**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-screeninggate) (const std::string & name) <br>_Construct a ScreeningGate with a name._  |


## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |




## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |




## Public Static Functions inherited from falcon_core::generic::Song

See [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; T &gt; | [**from\_json\_string**](classfalcon__core_1_1generic_1_1Song.md#function-from_json_string) (const std::string & json) <br>_Deserialize an object from a JSON string._  |














































































































































## Protected Functions

| Type | Name |
| ---: | :--- |
|   | [**LeftReservoirWithImplantedOhmic**](#function-leftreservoirwithimplantedohmic-22) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |


## Protected Functions inherited from falcon_core::physics::device_structures::Connection

See [falcon\_core::physics::device\_structures::Connection](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md)

| Type | Name |
| ---: | :--- |
|   | [**Connection**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-connection-33) () <br> |
|  void | [**serialize**](classfalcon__core_1_1physics_1_1device__structures_1_1Connection.md#function-serialize) (Archive & ar) <br> |




## Protected Functions inherited from falcon_core::physics::config::geometries::HasImplantedOhmic

See [falcon\_core::physics::config::geometries::HasImplantedOhmic](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasImplantedOhmic.md)

| Type | Name |
| ---: | :--- |
|   | [**HasImplantedOhmic**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasImplantedOhmic.md#function-hasimplantedohmic-33) () <br> |
|  void | [**serialize**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasImplantedOhmic.md#function-serialize) (Archive & ar) <br> |




## Protected Functions inherited from falcon_core::physics::config::geometries::HasRightNeighbor

See [falcon\_core::physics::config::geometries::HasRightNeighbor](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasRightNeighbor.md)

| Type | Name |
| ---: | :--- |
|   | [**HasRightNeighbor**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasRightNeighbor.md#function-hasrightneighbor-33) () <br> |
|  void | [**serialize**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasRightNeighbor.md#function-serialize) (Archive & ar) <br> |


















## Public Functions Documentation




### function LeftReservoirWithImplantedOhmic [1/2]

```C++
falcon_core::physics::config::geometries::LeftReservoirWithImplantedOhmic::LeftReservoirWithImplantedOhmic (
    std::string name,
    device_structures::ConnectionSP right_neighbor,
    device_structures::ConnectionSP ohmic
) 
```




<hr>
## Protected Functions Documentation




### function LeftReservoirWithImplantedOhmic [2/2]

```C++
falcon_core::physics::config::geometries::LeftReservoirWithImplantedOhmic::LeftReservoirWithImplantedOhmic () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::physics::config::geometries::LeftReservoirWithImplantedOhmic::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::physics::config::geometries::LeftReservoirWithImplantedOhmic::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/physics/config/geometries/LeftReservoirWithImplantedOhmic.hpp`

