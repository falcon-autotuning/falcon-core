

# Class falcon\_core::physics::config::geometries::HasRightNeighbor



[**ClassList**](annotated.md) **>** [**falcon\_core**](namespacefalcon__core.md) **>** [**physics**](namespacefalcon__core_1_1physics.md) **>** [**config**](namespacefalcon__core_1_1physics_1_1config.md) **>** [**geometries**](namespacefalcon__core_1_1physics_1_1config_1_1geometries.md) **>** [**HasRightNeighbor**](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1HasRightNeighbor.md)



_A gate with a right neighbor._ 

* `#include <HasRightNeighbor.hpp>`



Inherits the following classes: [falcon\_core::generic::Song](classfalcon__core_1_1generic_1_1Song.md)


Inherited by the following classes: [falcon\_core::physics::config::geometries::DotGateWithNeighbors](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1DotGateWithNeighbors.md),  [falcon\_core::physics::config::geometries::LeftReservoirWithImplantedOhmic](classfalcon__core_1_1physics_1_1config_1_1geometries_1_1LeftReservoirWithImplantedOhmic.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**HasRightNeighbor**](#function-hasrightneighbor-13) (const HasRightNeighbor & other) <br> |
|   | [**HasRightNeighbor**](#function-hasrightneighbor-23) (device\_structures::ConnectionSP right\_neighbor) <br> |
|  HasRightNeighbor & | [**operator=**](#function-operator) (const HasRightNeighbor & other) <br> |
|  device\_structures::ConnectionSP | [**right\_neighbor**](#function-right_neighbor) () const<br>_Returns the right neighbor of the gate._  |


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
|   | [**HasRightNeighbor**](#function-hasrightneighbor-33) () <br> |
|  void | [**serialize**](#function-serialize) (Archive & ar) <br> |








## Public Functions Documentation




### function HasRightNeighbor [1/3]

```C++
falcon_core::physics::config::geometries::HasRightNeighbor::HasRightNeighbor (
    const HasRightNeighbor & other
) 
```




<hr>



### function HasRightNeighbor [2/3]

```C++
falcon_core::physics::config::geometries::HasRightNeighbor::HasRightNeighbor (
    device_structures::ConnectionSP right_neighbor
) 
```




<hr>



### function operator= 

```C++
HasRightNeighbor & falcon_core::physics::config::geometries::HasRightNeighbor::operator= (
    const HasRightNeighbor & other
) 
```




<hr>



### function right\_neighbor 

_Returns the right neighbor of the gate._ 
```C++
device_structures::ConnectionSP falcon_core::physics::config::geometries::HasRightNeighbor::right_neighbor () const
```




<hr>
## Protected Functions Documentation




### function HasRightNeighbor [3/3]

```C++
falcon_core::physics::config::geometries::HasRightNeighbor::HasRightNeighbor () 
```




<hr>



### function serialize 

```C++
template<class Archive>
inline void falcon_core::physics::config::geometries::HasRightNeighbor::serialize (
    Archive & ar
) 
```




<hr>## Friends Documentation





### friend access 

```C++
class falcon_core::physics::config::geometries::HasRightNeighbor::access (
    cereal::access
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `cpp/include/falcon_core/physics/config/geometries/HasRightNeighbor.hpp`

